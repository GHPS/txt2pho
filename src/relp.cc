#include "lisatalk.h"
#if !defined(__RELP_H__)
#include "relp.h"
#endif

#include <string.h>

//=============================================================================


extern int ola(short* a,short* b, int blen) ;

// static functions for lpc analysis

// multiply a hamming window to buffer with length

static void hamming_window(float* buffer,int length) {

	double dt,t ;

	dt = 6.28504/(double)(length-1) ;
	t = -3.14257-dt ;
	for (int i = 0 ; i < length ; i++ ) {
		t += dt ;
		buffer[i] *= (float)(0.54 + 0.46*cos(t)) ; } }

//=======================

/* this routine performs an autocorrelation after Markel & Gray with
	window the signal window , a the autocorr. values , rc the
	reflexion coefficients, and length windowlength */

static void autocorrelation(float* window,float* a,float* rc,int length, int lpc_grade) {

	float* r = new float[lpc_grade+1] ;	         // autocorrelation coeffs.
	float* b = new float[lpc_grade+1] ;          	// backward prediction coeffs
	nulltest(r) ;
	nulltest(b) ;
	int i,j ;
	float alpha ;		               // prediction error
	float	sum ;

	// compute autocorrelation values
	for (i = 0 ; i < lpc_grade+1 ; i++ ) {
		r[i] = a[i] = rc[i] = (float)0.0 ;
		for (j = -1 ; ++j < (length - i) ;
			r[i] += window[j]*window[j+i] ) ; }

	// initial conditions
	if ((alpha=r[0]) <= (float)0.0)
		goto ende ;
	a[1] = rc[0] = -r[1] / r[0] ;
	a[0] = (float)1.0 ;
	alpha += r[1]*rc[0] ;
	if (alpha <= (float) 0.0)
		goto ende ;

	// main loop
	for (i = 1 ; i < lpc_grade ; i++) {

		// backward prediction
		sum = (float)0.0 ;
		for (j = -1 ; ++j <= i ; sum += r[i-j+1] * a[j])
			b[j] = a[i-j] ;

		// forward prediction
		a[i+1] = rc[i] = -sum / alpha ;
		for (j = 0 ; ++j <= i ; a[j] += rc[i]*b[j-1]) ;

		alpha -= rc[i] * rc[i] * alpha ;
		if (alpha <= (float)0.0)
			goto ende ; }
ende:
	delete(b) ;
	delete(r) ;
	return ; }







Relplist::Relplist(int lp_grade, float m) {
	errorvalue.rc = NULL ;
	errorvalue.residual = NULL ;
	errorvalue.length = -1 ;
	lpc_grade = lp_grade ;
	pastbuf= new float[lpc_grade+1] ;  	// past buffer
	emvzg = new float[lpc_grade+2] ;
	for (int ii=0 ; ii < lpc_grade+2 ; emvzg[ii++]=(float)0.0) ;
//	printf("f %d\n",lpc_grade) ;
	mu = m ; }

Relplist::~Relplist() {
	reset() ;
   delete(pastbuf) ;
   delete(emvzg) ;
	while (act != NULL) {
		if (act->i.rc != NULL)
			delete(act->i.rc) ;
		if (act->i.residual != NULL)
			delete(act->i.residual) ;
		act = act->after ; } }

int Relplist::analyze_window(short* window, int length, int shift, int DELAY) {

	Relpframe frame ;
	static FILE* rsfil = FOPEN("rs.sig","ab") ;
	float* buf = NULL ;		         // float buffer
	float* copbuf = NULL ;		      // float buffer for res. computation
	float* a ;				               // autocorr. values
	float* rc ;			            	// reflexion coeffs
	static int k = 0 ;				               // indicates, if a past exists
	int i,j,mm ;
	float sum = 0.0 ;

	// convert int to float buffer and compute average
	buf = new float[length] ;
	nulltest(buf) ;
	copbuf = new float[shift+lpc_grade] ;
	nulltest(copbuf) ;
	for (i = 0 ; i < length ; sum += buf[i++] )
		buf[i] = (float) window[i] ;

	// copy error signal buffer
	if (k == lpc_grade)
		memcpy(copbuf,pastbuf,k*sizeof(float)) ;
	memcpy(&copbuf[k],buf,shift*sizeof(float)) ;

	// averaging of the buffer
	sum /= (float)length ;
	for (i = -1 ; ++i < length ; buf[i] -= sum) ;

	// preemphasis according to mu
	for (i = length ; --i > 0 ; buf[i] -= (float)mu * buf[i-1]) ;
	buf[0] = buf[0] - (float)mu * buf[0] ;

	// hamming window on preemphasized buffer
	hamming_window(buf,length) ;

	// compute lp coefficients
	rc = new float[lpc_grade+1] ;
	nulltest(rc) ;
	a = new float[lpc_grade+1] ;
	nulltest(a) ;
	if (length <= DELAY)
		DELAY = length -lpc_grade ;
	if (DELAY < 0)
   	DELAY = 0 ;
	autocorrelation(&buf[DELAY/2],a,rc,length-DELAY,lpc_grade) ;

	// copy coefficients into frame
	frame.length = shift ;
	frame.rc = rc ;
	frame.residual = new short[shift] ;

	// compute error signal and write it to file
	for (i = k ; i < shift + k ; i++) {
		mm = min(i+k,lpc_grade+1) ;
		sum = 0.0 ;
		for (j = -1 ; ++j < mm ; sum += a[j] * copbuf[i-j]) ;
		frame.residual[i-k] = (int)sum ; }
	delete(a) ;

	// move error signal buffer
	memcpy(pastbuf,&copbuf[shift-lpc_grade+k],lpc_grade*sizeof(float)) ;

	// k must change after first window - now a past exists
	k = lpc_grade ;


	delete(buf) ;
	delete(copbuf) ;
	append(frame) ;

	return(1) ; }

//=============================================================================

// synthesizes a time signal out of a relplist into file outfil

short* Relplist::synthesize(int first, int last, long& length) {
	int ii, jframe ;
	float excitation ;            // excitation of filter
	Relpframe frame ;	      	// contains actframe
	short* result = NULL ;	      	// buffer for residual and result
	float* emvzg = new float[lpc_grade+1] ;  	// coeffs describing the past
	nulltest(emvzg) ;

	// initialize past coefficients
	for (ii=0 ; ii <= lpc_grade ; emvzg[ii++]=(float)0.0) ;
	frame = get(first-1) ;
	length = -frame.length ;

	// loop thru all frames
	while ((frame = get_and_advance()).length != errorvalue.length) {
		if (get_number() > last+1)
			break ;

		// loop thru all residual samples
		length += frame.length ;
		for (jframe = 0 ; jframe < frame.length; jframe++) {
			excitation = (float)frame.residual[jframe] ;
			for (ii = lpc_grade - 1 ; ii > -1 ; --ii ) {
				excitation -= frame.rc[ii] * emvzg[ii] ;
				emvzg[ii+1] = emvzg[ii] + frame.rc[ii]*excitation ; }
			emvzg[0] = excitation ;
			frame.residual[jframe] = max((int)-32766,(int)min((short)excitation,(short)32766)) ; } }

	delete(emvzg) ;
	result = new short[length] ;
	nulltest(result) ;
	get(first) ;
	length = 0L ;
	while ((frame = get_and_advance()).length != errorvalue.length) {
		if (get_number() > last+1)
			break ;
		memcpy(&result[length],frame.residual,frame.length*sizeof(short)) ;
		length += frame.length ; }

	return(result) ;
}
//==============================================================================



//=============================================================================

// synchronizes frame, gives new residual length (must be smaller than before)

int Relplist::synchronize(Relpframe& frame, int length) {

	short* buffer = new short[length] ;
	nulltest(buffer) ;
	memcpy(buffer,&(frame.residual[frame.length-length]),length*sizeof(short)) ;

	// synchronizing by overlap add
	frame.length = ola(frame.residual,buffer,length) ;
	delete(frame.residual) ;
	frame.residual = buffer ;

	return(frame.length) ; }

//=============================================================================
#define hann(wk,k,K) (short)((double)wk*(0.5*(1.0+cos(3.14257*(double)k/(double)K))))

/* interpolates between frames; inserts frames frames after entry with index
	number-1, number and number+1 will be excluded; the interpolation is
	performed between number-1 and number+2 linearly with a cosine slope;
	returns number of new frames minus 2 */

int Relplist::interpolate(int first, int last, int frames) {
	int i,j ;
	float* arc, *brc ;
	short* a1, *b1 ;		            // residual signals
	Relpframe a,b,c ;         	// frames
	int samples = 0 ;             // interpolated samples
	int shiftvalue ;              // length of all interpolated frames
	double factor,actfact ;     	// interpolation factors

	// read the two reference frames and synchronize them
	a = get(first) ;
	b = get(last) ;

	get(first) ;
	for (i=first ; i <= last ; i++)
		exclude(first) ;

	shiftvalue = min(b.length-a.length,0) ;
	if (a.length > b.length)
		samples = synchronize(a,b.length) ;
	else
		samples = synchronize(b,a.length) ;

	insert(a,first-1) ;

	// reserve space for residuals and read the reference res. signals
	a1 = new short[samples*frames] ;
	nulltest(a1) ;
	b1 = new short[samples*frames] ;
	nulltest(b1) ;
	memcpy(a1,a.residual,samples*sizeof(short)) ;
	memcpy(b1,b.residual,samples*sizeof(short)) ;

	// generate merged residual
	for (i=1; i < frames ; i++) {
		memcpy(&a1[i*samples],&a1[(i-1)*samples],samples*sizeof(short)) ;
		memcpy(&b1[i*samples],&b1[(i-1)*samples],samples*sizeof(short)) ; }
	for (i=0 ; i < samples*frames ; i++)
		a1[i] = hann(a1[i],i,(samples*frames-1)) +
				 hann(b1[i],(i-(samples*frames-1)),(samples*frames-1)) ;
	delete(b1) ;

	// convert refl. coeffs to log area ratios
	arc = new float[lpc_grade+1] ;
	nulltest(arc) ;
	brc = new float[lpc_grade+1] ;
	nulltest(brc) ;
	for (i = 0 ; i <= lpc_grade ; i++) {
		arc[i] = (float)log10(((1.0+(a.rc)[i])/ (1.0-(a.rc)[i]))) ;
		brc[i] = (float)log10(((1.0+(b.rc)[i])/ (1.0-(b.rc)[i]))) ; }

	// compute interpolation stepwidth
	factor = 1.0/(double)(frames-1) ;

	// interpolation loop
	for (j = 0 ; j < frames ; j++ ) {

		c.rc = new float[lpc_grade+1] ;
		nulltest(c.rc) ;
		c.residual = new short[samples] ;
		nulltest(c.residual) ;

		// compute actual factor (cosine slope)
		actfact = factor * (double)(j) ;

		// interpolate log area ratios, convert them to rc's
		for (i = 0 ; i <= lpc_grade ; i++) {
			(c.rc)[i] = (float) ((brc[i] - arc[i])
					 * actfact + arc[i]) ;
			(c.rc)[i] = (float) ((pow((float)10.0,(float)(c.rc)[i])-1)/
					 (pow((float)10.0,(float)(c.rc)[i])+1)) ; }

		// write result into relpfile and relplist
		c.length = samples ;
		memcpy(c.residual,&a1[j*samples],sizeof(short)*c.length) ;
		insert(c,first+j) ; }
	insert(b,first+j) ;
	// free heap memory
	delete(a1) ;
	delete(arc) ;
	delete(brc) ;

	return(shiftvalue) ; }

void Relplist::list() {
	FILE* rsfil = FOPEN("rs.sig","ab") ;
	FILE* pmfil = FOPEN("par.lst","a") ;
	Relpframe frame ;
	int count = 1 ;
	reset() ;
	while ((frame = get_and_advance()).length != errorvalue.length) {
		fwrite(frame.residual,sizeof(short),frame.length,rsfil) ;
		fprintf(pmfil,"\n%3d %6d ",count++,frame.length) ;
		for (int i = 0 ; i <= lpc_grade ; i++)
			fprintf(pmfil,"%6.3f ",frame.rc[i]) ; }
	FCLOSE(pmfil) ;
	FCLOSE(rsfil) ; }

void Relplist::write_last_frame() {
	FILE* rsfil = FOPEN("rs.sig","ab") ;
	FILE* pmfil = FOPEN("par.lst","a") ;
	Relpframe frame ;
	int count = 1 ;
	reset() ;
	frame = get(1) ;
	fwrite(frame.residual,sizeof(short),frame.length,rsfil) ;
	fprintf(pmfil,"\n%3d ",count++) ;
	for (int i = 0 ; i <= lpc_grade ; i++)
		fprintf(pmfil,"%6.3f ",frame.rc[i]) ;
	exclude(1) ;
	FCLOSE(pmfil) ;
	FCLOSE(rsfil) ; }

Relpframe Relplist::get_frame(long startpoint, int length) {
//	list() ;
	reset() ;
	Relpframe frame ;
	Relpframe result ;
	long actpos = 0 ;
	frame = get() ;
	while (actpos <= startpoint) {
//		fprintf(errfile,"in get_frame %ld %ld\n",actpos,startpoint) ;
		frame = get_and_advance() ;
		if (frame.length == -1) {
			result.length = -1 ;
			fprintf(errfile,"NULL FRAME DESIRED\n") ;
			result.residual = NULL ;
			return(result) ; }
		actpos += frame.length ; }
	result.length = length ;
	result.rc = new float[lpc_grade+1] ;
	nulltest(result.rc) ;
	memcpy(result.rc,frame.rc,(lpc_grade+1)*sizeof(float)) ;
//		result.residual = new short[frame.length] ;
//		memcpy(result.residual,frame.residual,(frame.length)*sizeof(short)) ;

	result.residual = get_residual(startpoint,length) ;
/*		if (result.rc == NULL || result.residual == NULL) {
			printf("out of heap") ;
			exit(0) ; }
		memcpy(result.rc,frame.rc,(lpc_grade+1)*sizeof(float)) ;
		if (result.length <= frame.length)
			memcpy(result.residual,frame.residual,result.length*sizeof(short)) ;
		else {
			lastx += frame.length ;
			while (lastx < result.length) {
				memcpy(result.residual,frame.residual,frame.length*sizeof(short)) ;
				frame = get() ; }
			memcpy(&result.residual[lastx],frame.residual,(length-lastx)*sizeof(short)) ; } */
	return(result) ; }

short* Relplist::get_residual(long startpoint, int length) {
	reset() ;
	Relpframe frame ;
	short* result ;
	int lastx = 0 ;
	int i = 0 ;
	long actpos = 0 ;
	frame = get() ;
	while (actpos < startpoint) {
		if (frame.length == -1) {
			result = NULL ;
			return(result) ; }
		frame = get_and_advance() ;
		actpos += frame.length ; }
	if (frame.length == -1)
		return(NULL) ;
	result = new short[length] ;
	nulltest(result) ;
	if (actpos > startpoint) {
		lastx = actpos-startpoint ;
		i = min(length,lastx) ;
		memcpy(result,&frame.residual[frame.length-lastx],i*sizeof(short)) ;
		lastx = i ; }
	frame = get() ;
	while (lastx < length) {
		if (frame.length >= (length-lastx)) {
			memcpy(&result[lastx],frame.residual,sizeof(short)*(length-lastx)) ;
			break ; }
		memcpy(&result[lastx],frame.residual,sizeof(short)*frame.length) ;
		lastx += frame.length ;
		frame = get() ;}
	return(result) ; }

short* Relplist::synthesize_frame(Relpframe frame) {
	int ii, jframe ;
	float excitation ;            // excitation of filter

   float dummy ;


	for (jframe = 0 ; jframe < frame.length; jframe++) {
		excitation = (float)frame.residual[jframe] ;
		for (ii = lpc_grade - 1 ; ii > -1 ; --ii ) {
			excitation -= frame.rc[ii] * emvzg[ii] ;
			dummy/*emvzg[ii+1]*/ = emvzg[ii] + frame.rc[ii]*excitation ;
         if (ii+1 <  0 || ii >= lpc_grade-1) {
//         	fprintf(errfile,"ii out of range\n") ;
            fflush(errfile) ; }
         else {
//         	fprintf(errfile,"%p %d %f\n",emvzg,ii,dummy) ;
//            fflush(errfile) ;
	         emvzg[ii+1] = dummy ; }
         }
		emvzg[0] = excitation ;
      if (abs(emvzg[1])>32767) {
      	fprintf(errfile,"FILTER UNSTABLE\n") ;
         delete(frame.rc) ;
         delete(frame.residual) ;
         for (ii = 0 ; ii < lpc_grade+2 ; ii++)
         	emvzg[ii] = 0.0 ;
         return(NULL) ; }
		frame.residual[jframe] = max((int)-32766,(int)min((short)excitation,(short)32766)) ; }

	delete(frame.rc) ;
	return(frame.residual) ;
}
