#ifndef NGIMMICKS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#ifdef VECTOR
#include "vector.h"
#endif

#include "lpc.h"

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))


extern FILE* errfile ;
	int length;
	struct ceparray {
	       float *cep;
	       struct ceparray *kette;
	       };
	struct dist {
	       float entfernung;
			 struct dist *naechsta;
			 };
//=============================================================================

#undef log2

int log2(int x) {
	 unsigned int mask,i,k=x-1;
	 for(mask = 1 , i = 0 ; ; mask *= 2 , i++) {
		  if(k == 0) return(i);
		  k = k & (~mask); } }


//int widow_length() { return(length) ; }

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

static float autocorrelation(float* window,lpc_coeffs a,
									 lpc_coeffs rc,int length) {

	static lpc_coeffs r ;	         // autocorrelation coeffs.
	static lpc_coeffs b ;          	// backward prediction coeffs
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
		return(1.0e-10) ;
	a[1] = rc[0] = -r[1] / r[0] ;
	a[0] = (float)1.0 ;
	alpha += r[1]*rc[0] ;
	if (alpha <= (float) 0.0)
		return(1.0e-10) ;

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
			return(1.0e-10) ; }
	return(alpha) ; }

//====================

/* lpc analysis of a window length samples long; if method = 1
	autocorrelation is performed, else covariance analysis */

static float analyze_window(short* window, lpc_coeffs a) {

	float* buf = (float *) calloc(length, sizeof(float));     // float buffer
	lpc_coeffs rc ;			            	// reflexion coeffs
	int i ;
	float help, sum = 0.0 ;

	// convert int to float buffer and compute average
	for (i = 0 ; i < length ; sum += buf[i++] )
		buf[i] = (float) window[i] ;

	// averaging of the buffer
	sum /= (float)length ;
	for (i = -1 ; ++i < length ; buf[i] -= sum) ;

	// hamming window on preemphasized buffer
	hamming_window(buf,length) ;

	// compute lp coefficients
	help = autocorrelation(buf,a,rc,length);
	 free(buf);
	return(help) ; }


//=============================================================================

Ref_frame get_ref_frame(short* window) {

	lpc_coeffs a ;
	Ref_frame retval ;
	int i ;

	analyze_window(window,a) ;

	for (i=0 ; i <= lpc_grade ; i++)
		retval.b[i] = a[i] ;

	return(retval) ; }

//=======================

float get_distance(short* window, Ref_frame frame) {

	lpc_coeffs a ;
	int i,j ;
	float sum,sum1 ;
	float down,up ;

	analyze_window(window,a) ;

	up = down = 0.0 ;

	for (i=lpc_grade ; i < length ; i++) {
		sum = sum1 = 0.0 ;
		for (j=1 ; j <= lpc_grade ; j++) {
			sum += window[i-j]*a[j] ;
			sum1 += window[i-j]*frame.b[j] ; }
		down += (window[i]+sum)*(window[i]+sum) ;
		up += (window[i]+sum1)*(window[i]+sum1) ; }

	if (up == 0.0 || down == 0.0)
		return(-1.0) ;

	return(log(up/down)) ;  }

//===============================

float* get_lpc_spectrum(short* window,int speclen, int kHz) {

	lpc_coeffs a,p ;
	float g ;
	float sum ;
	float* spectrum = (float*)malloc(sizeof(float)*speclen)  ;
	float angle = ((float)kHz*3.14257/8.0)/(float)speclen ;
	int i,j ;

	if (spectrum == NULL) {
		exit(1) ; }

	g = analyze_window(window,a) ;

	for (i=0; i <= lpc_grade ; i++) {
		p[i] = 0 ;
		for (j=0 ; j <= lpc_grade-i ; j++)
			p[i] += a[j]*a[j+i] ; }

	for (i=0; i < speclen ; i++) {
		sum = 0.0 ;
		for (j=1 ; j <= lpc_grade ; j++)
			sum += p[j]*cos((float)j*((float)i*angle)) ;
		if (sum == 0.0 ) {
			spectrum[i] = 0.0 ; continue ; }
		spectrum[i] = 10.0 * log10(g / (p[0]+2.0*sum)) ; }

	return(spectrum) ; }

//============================

void fft(COMPLEX* x, int m) {
	 static COMPLEX *w;           /* used to store the w complex array */
	 static int mstore = 0;       /* stores m for future reference */
	 static int n = 1;            /* length of fft stored for future */

	 COMPLEX u,temp,tm;
    COMPLEX *xi,*xip,*xj,*wptr;

    int i,j,k,l,le,windex;

	 double arg,w_real,w_imag,wrecur_real,wrecur_imag,wtemp_real;

    if(m != mstore) {

		  /* free previously allocated storage and set new m */
		  if(mstore != 0) free(w);
		  mstore = m;
		  if(m == 0) return;       /* if m=0 then done */

		  /* n = 2**m = fft length */
		  n = 1 << m;
		  le = n/2;

		  /* allocate the storage for w */
		  w = (COMPLEX *) calloc(le-1,sizeof(COMPLEX));
		  if(!w) {
				exit(1); }

		  /* calculate the w values recursively */
		  arg = 4.0*atan(1.0)/le;         /* PI/le calculation */
		  wrecur_real = w_real = cos(arg);
		  wrecur_imag = w_imag = -sin(arg);
		  xj = w;
		  for (j = 1 ; j < le ; j++) {
				xj->real = (float)wrecur_real;
				xj->imag = (float)wrecur_imag;
				xj++;
				wtemp_real = wrecur_real*w_real - wrecur_imag*w_imag;
				wrecur_imag = wrecur_real*w_imag + wrecur_imag*w_real;
				wrecur_real = wtemp_real; } }

	 /* start fft */
	 le = n;
	 windex = 1;
	 for (l = 0 ; l < m ; l++) {
		  le = le/2;

		  /* first iteration with no multiplies */
		  for(i = 0 ; i < n ; i = i + 2*le) {
				xi = x + i;
				xip = xi + le;
				temp.real = xi->real + xip->real;
				temp.imag = xi->imag + xip->imag;
				xip->real = xi->real - xip->real;
				xip->imag = xi->imag - xip->imag;
				*xi = temp; }

		  /* remaining iterations use stored w */
		  wptr = w + windex - 1;
		  for (j = 1 ; j < le ; j++) {
				u = *wptr;
				for (i = j ; i < n ; i = i + 2*le) {
                xi = x + i;
					 xip = xi + le;
					 temp.real = xi->real + xip->real;
                temp.imag = xi->imag + xip->imag;
                tm.real = xi->real - xip->real;
					 tm.imag = xi->imag - xip->imag;
                xip->real = tm.real*u.real - tm.imag*u.imag;
                xip->imag = tm.real*u.imag + tm.imag*u.real;
					 *xi = temp; }
				wptr = wptr + windex; }
		  windex = 2*windex; }

	 /* rearrange data by bit reversing */
	 j = 0;
    for (i = 1 ; i < (n-1) ; i++) {
		  k = n/2;
		  while(k <= j) {
				j = j - k;
				k = k/2; }
		  j = j + k;
		  if (i < j) {
				xi = x + i;
				xj = x + j;
				temp = *xj;
				*xj = *xi;
				*xi = temp; } } }

//============================

void rfft(float* x, COMPLEX* y, int m) {
	 static	  COMPLEX  *cf;
	 static	  int      mstore = 0;
	 int       p,num,k;
	 float     Realsum, Realdif, Imagsum, Imagdif;
	 double    factor, arg;
	 COMPLEX   *ck, *xk, *xnk, *cx;

	 /* First call the fft routine using the x array but with
		half the size of the real fft */
	 p = m - 1;
	 cx = (COMPLEX *) x;
	 fft(cx,p);

	 /* Next create the coefficients for recombination, if required */
	 num = 1 << p;    /* num is half the real sequence length.  */

    if (m!=mstore){
		if (mstore != 0) free(cf);
		cf = (COMPLEX *) calloc(num - 1,sizeof(COMPLEX));
		if(!cf){
		  exit(1); }
		mstore = m ;
		factor = 4.0*atan(1.0)/num;
      for (k = 1; k < num; k++){
		  arg = factor*k;
		  cf[k-1].real = (float)cos(arg);
		  cf[k-1].imag = (float)sin(arg); } }

	 /* DC component, no multiplies */
	 y[0].real = cx[0].real + cx[0].imag;
	 y[0].imag = 0.0;

	 /* other frequencies by trig recombination */
	 ck = cf;
	 xk = cx + 1;
	 xnk = cx + num - 1;
	 for (k = 1; k < num; k++){
		Realsum = ( xk->real + xnk->real ) / 2;
		Imagsum = ( xk->imag + xnk->imag ) / 2;
		Realdif = ( xk->real - xnk->real ) / 2;
		Imagdif = ( xk->imag - xnk->imag ) / 2;

		y[k].real = Realsum + ck->real * Imagsum
								  - ck->imag * Realdif ;

      y[k].imag = Imagdif - ck->imag * Imagsum
                          - ck->real * Realdif ;
      ck++;
      xk++;
		xnk--; } }

//======================
/*
	window ist das Zeitsignal
	length ist Lnge des Signals
*/


float* get_fft_spectrum(short*window, int length) {

	int i ;
	int twopow = log2(length) ;
	COMPLEX* out = (COMPLEX*)malloc(length/2*sizeof(COMPLEX)) ;
	float* spectrum = (float*)malloc(length*sizeof(float))  ;
	double x ;

	if ((out == NULL) || (spectrum == NULL))
		return(NULL) ;

	for (i=0 ; i < length ; i++)
		spectrum[i] = (float)window[i] ;

	rfft(spectrum,out,twopow) ;

	for (i=0 ; i < length/2 ; i++) {
		x = out[i].real*out[i].real+out[i].imag*out[i].imag;
		if (x > 1.0e-6)
			spectrum[i] = 10.0*log10(x) ;
		else
			spectrum[i] = 0.0 ; }

	free(out) ;
	return(spectrum) ; }

//==============================

float euklid(float* a, float* b, int len) {

	if (a == NULL || b == NULL) {
   	fprintf(errfile,"IN EUKLID:input NULL\n") ;
      fflush(errfile) ;
      return(1.0) ; }
	float sum = 0.0 ;

	for (int i=0 ; i < len ; i++)
		sum += pow(a[i]-b[i],2) ;

	return(sqrt(sum)) ; }

//==============================

float* get_lpc_cepstrum(Ref_frame a) {

	float* cepstrum = (float*)malloc((lpc_grade+1)*sizeof(float)) ;
	if (cepstrum == NULL)
		return(NULL) ;

	int i, j ;

	for (i=0 ; i<lpc_grade+1 ; i++) {
		cepstrum[i] = a.b[i] ;
		for (j=0; j < i ; j++)
			cepstrum[i] += ((float)((j+1)-i)/(float)(i))*cepstrum[i-j]*a.b[j] ; }

	return(cepstrum) ; }

//=============================

float get_filter_output(float* spectrum, int pfreq, int pbandw) {

	int ramplen = pbandw/2 ;
	float* ramp = (float*)malloc(ramplen*sizeof(float)) ;
	if (ramp == NULL)
		return(-1) ;

	int i ;
	float sum ;
	float dramp = 1.0 / (float)ramplen ;
	float norm = 1.0 ;

	ramp[0] = 0.0 ;
	for (i=1 ; i < ramplen ; i++) {
		ramp[i] = ramp[i-1] + dramp ;
		norm += 2* ramp[i] ; }

	sum = spectrum[pfreq] ;
	for (i=1; i < ramplen ; i++)
		sum += (spectrum[pfreq+i]*ramp[ramplen-i])+
				 (spectrum[pfreq-ramplen+i]*ramp[i]) ;

	free(ramp) ;
	if (sum/norm < 1.0e-7)
		return(0.0) ;
	return(log(sum/norm)) ; }

//=============================

float* get_filterbank(float* spectrum, int* pfreqs, int* pbandws, int number) {

	float* bank = (float*)malloc(number*sizeof(float)) ;

	for (int i = 0 ; i < number ; i++)
		bank[i] = get_filter_output(spectrum,pfreqs[i],pbandws[i]) ;

	return(bank) ; }

//============================

float* get_mel_filterbank(float* spectrum, int speclen, float topfreq, int& number) {

	number = 0 ;
	static int* pfreqs ;
	static int* pbandws ;
	static float lasttopf = 0 ;
	int i ;
	float freqassamp = (float)speclen / (topfreq*1000.0) ;
	number = (int)((1000.0/log(2.0))*log(1+topfreq) / 100.0)  ;

	if (lasttopf != topfreq) {
		pfreqs = (int*)calloc(number,sizeof(int)) ;
		pbandws = (int*)calloc(number,sizeof(int)) ;
		if ((pfreqs == NULL) || (pbandws == NULL))
			return(NULL) ;
		pfreqs[0] = 0 ;
		pbandws[0] = 0 ;

		for (i=1 ; i < number ; i++) {
			pfreqs[i] = (int)(1000.0*(exp(log(2)*(float)i/10.0)-1)) ;
			pbandws[i] = (pfreqs[i]-pfreqs[i-1])*2+1 ; }

		for (i=0 ; i < number ; i++) {
			pfreqs[i] = (int)((float)pfreqs[i]*freqassamp) ;
			pbandws[i] = (int)((float)pbandws[i]*freqassamp); }

		lasttopf = topfreq ; }

	return(get_filterbank(spectrum,&pfreqs[1],&pbandws[1],--number)) ;

}

//==========================
/*
	spectrum wird mit get_fft_spectrum berechnet
	speclen lnge des spektrums (anzahl der float-werte)
	topfreq ist die halbe Abtastrate in kHz
	cepsnr ist die Groesse des resultieren Vektors (20 ?)
*/


float* get_mel_cepstrum(float* spectrum, int speclen, float topfreq, int cepsnr) {

	int number = 0 ;
	float* bank = get_mel_filterbank(spectrum,speclen,topfreq,number) ;
	float* cepstrum = (float*)calloc(cepsnr,sizeof(float)) ;
	int i,j ;
	float sum ;

	if(cepstrum == NULL)
		return(NULL) ;

	for (i=0; i < cepsnr ; i++) {
		sum = 0.0 ;
		for (j=0 ; j < number ; j++)
			sum += bank[j]*cos((float)i*((float)j-0.5)*(3.14257/(float)number)) ;
		cepstrum[i] = sum ; }

	free(bank) ;
	return(cepstrum) ; }

//===========================

float* get_fft_cepstrum(float* spectrum, int speclen, int cepsnr) {

	float* cepstrum = (float*)calloc(cepsnr,sizeof(float)) ;
	int i,j ;
	float sum ;

	for (i=0 ; i < cepsnr ; i++) {
		sum = 0.0 ;
		for (j=0 ; j < speclen-1; j++)
			sum += spectrum[j]*cos((float)i*(float)j*3.14257/(float)speclen) ;
		cepstrum[i] = sum ; }

	return(cepstrum) ; }

//==========================

float* get_pse(short* window, int length, int shift, int speclen, int number) {

	float* spectrum = (float*)calloc(speclen,sizeof(float)) ;
	float* actspec = (float*)calloc(speclen*2,sizeof(float)) ;
	int i,j ;
	COMPLEX* out = (COMPLEX*)malloc(speclen*sizeof(COMPLEX)) ;
	double x ;

	if ((out == NULL) || (spectrum == NULL))
		return(NULL) ;
	if (((shift*(number-1)+speclen*2) > length) || (spectrum == NULL))
		return(NULL) ;

	for (i=0 ; i < speclen ; i++)
		spectrum[i] = 0.0 ;

	for (i=0 ; i < number ; i++) {

		for (j=0 ; j < speclen*2 ; j++)
			actspec[j] = (float)window[j+(i*shift)] ;

		hamming_window(actspec,speclen*2) ;

		rfft(actspec,out,log2(speclen*2)) ;

		for (j=0 ; j < speclen ; j++) {
			x = out[j].real*out[j].real+out[j].imag*out[j].imag;
			spectrum[j] += x ; } }

	for (j=0 ; j < speclen ; j++) {
		spectrum[j] /= number ;
		spectrum[j] = (spectrum[j] < 1.0e-7 ? 0.0 : 10.0*log10(spectrum[j])) ; }

	free(out) ;
	free(actspec) ;
	return(spectrum) ; }

//===============================


void kill1(struct ceparray *r)
{
	if (r==NULL)
		return;
	if (r->kette != NULL)
		kill1(r->kette);
	free(r);
}


void kill2(struct dist *r)
{
	if (r==NULL)
		return;
	if (r->naechsta != NULL)
		kill2(r->naechsta);
	free(r);
}


void find_minimal_distance(short* a1, long &sam1, short* a2, long &sam2, int sf, int sollen, char* method) {   // 2 Samplewerte zurueck

	ceparray *cepa, *helpa, *cepb, *helpb;
	float *s=NULL, *p=NULL;
	Ref_frame q,r ;
	int number=16;
	int x=0,y=0;
	float klein = 1e20;
	float d;
	int i,j ;
	int uv1, uv2, schub1, schub2;
	int sampanf1, sampend1, sampanf2, sampend2;
	int rr1, rr2, khz1, khz2;
	int param = -1, spectrum = -1 ;
	if (strstr(method,"MEL-CEPSTRUM") != NULL) {
		param = 1 ; }
	if (strstr(method,"MEL-FILTERBANK") != NULL) {
		param = 3 ; }
	if (strstr(method,"FFT-CEPSTRUM") != NULL) {
		param = 2 ; }
//	if (strstr(method,"LPC-CEPSTRUM") != NULL) {
//		param = 4 ; }
	if (strstr(method,"FFT-SPECTRUM") != NULL) {
		spectrum = 0 ; }
//	if (strstr(method,"LPC-SPECTRUM") != NULL) {
//		spectrum = 1 ; }
//	if (strstr(method,"LPC-PARAMS") != NULL) {
//		spectrum = 2 ; }

	if (param == -1 && spectrum == -1) {
		fprintf(errfile,"UNSUPPORTED OPTIMIZATION METHOD %s\n",method) ;
		sam1 = int(sam1 * 0.3) ;
		sam2 = int(sam2 * 0.3) ;
		return ; }

	if (param == -1)
		param = 0 ;
	if (spectrum == -1)
		spectrum = 0 ;


	length = 16*sf ;

	sampanf1=length;
	sampend1=sam1-2*length;

	sampanf2=length;
	sampend2=sam2-2*length;

	if (sollen > 0) {
		sampend2 = min(sampend2,sam2) ; //-length-((float)sollen*(float)sf*0.25)) ;
		sampanf1 = max(length, 0) ; //(float)sollen*(float)sf*0.25) ;
		sampanf2 = (int)max(length,sam2-length-((float)sollen*(float)sf*0.75)) ;
		sampend1 = (int)min(sampend1,(float)sollen*(float)sf*0.75) ; }

	if (sampanf1 > sampend1) {
		fprintf(errfile,"SAMPANF1 > SAMPEND1\n") ;
		sampend1=sam1-length;
		sampanf1 = length ; }
	if (sampanf2 > sampend2) {
		fprintf(errfile,"SAMPANF2 > SAMPEND2\n") ;
		sampend2=sam2-length;
		sampanf2 = length ; }


	uv1 = uv2 = 5;

	khz1 = khz2 = sf;


	rr1 = (sampend1-sampanf1)/(khz1*uv1)+1;
	rr2 = (sampend2-sampanf2)/(khz2*uv2)+1;
	schub1 = sampanf1 ;
	schub2 = sampanf2 ;

	i=-1 ;
	helpa = cepa = (struct ceparray *) malloc(sizeof(struct ceparray));
	helpa->kette = NULL ;
	while (++i < rr1) {
		switch (spectrum) {
			case 0: s = get_fft_spectrum(&a1[(schub1+i*khz1*uv1)],length/2); break ;
			case 4: s = get_pse(&a1[(schub1+i*khz1*uv1)],length,5,length/2,4) ; break ;
			case 1: s = get_lpc_spectrum(&a1[(schub1+i*khz1*uv1)],length/2,sf) ; break ;
			case 2: q = get_ref_frame(&a1[(schub1+i*khz1*uv1)]) ; break ; }
		helpa->kette = (struct ceparray *) malloc(sizeof(struct ceparray));
		(helpa->kette)->kette = NULL;
		switch (param) {
			case 0: helpa->cep = s ; number = length/2 ; break ;
			case 3: helpa->cep = get_mel_filterbank(s,length/2,8,number) ; delete(s) ; break ;
			case 1: helpa->cep = get_mel_cepstrum(s,length/2,8,number) ; delete(s) ; break ;
			case 2: helpa->cep = get_fft_cepstrum(s,length/2,number) ; delete(s) ; break ; }
		helpa = helpa->kette;
		}
	 j=-1;
	 helpb = cepb = (struct ceparray *) malloc(sizeof(struct ceparray));
	 helpb->kette = NULL ;
	 while (++j < rr2) {
		switch (spectrum) {
			case 0: p = get_fft_spectrum(&a2[(schub2+j*khz2*uv2)],length/2); break ;
			case 4: p = get_pse(&a2[(schub2+i*khz2*uv2)],length,5,length/2,4) ; break ;
			case 1: p = get_lpc_spectrum(&a2[(schub2+j*khz2*uv2)],length/2,sf) ; break ;
			case 2: r = get_ref_frame( &a2[(schub2+j*khz2*uv2)]) ; break ; }
		helpb->kette = (struct ceparray *) malloc(sizeof(struct ceparray));
		(helpb->kette)->kette = NULL;
		switch (param) {
			case 0: helpb->cep = p ; number = length/2 ; break ;
			case 3: helpb->cep = get_mel_filterbank(p,length/2,8,number) ; delete(p) ; break ;
			case 1: helpb->cep = get_mel_cepstrum(p,length/2,8,number) ; delete(p) ; break ;
			case 2: helpb->cep = get_fft_cepstrum(p,length/2,number) ; delete(p) ; break ; }
		helpb = helpb->kette;
			}

	  helpa = cepa;
	  helpb = cepb;
//	  helpmat = matrix = (struct dist *) malloc(sizeof(struct dist));
		for (j=0 ; j < rr2 ; j++)
			fprintf(errfile,"%10d ",j) ;
		fprintf(errfile,"\n") ;
	  for (i = 0; i < rr1; i++) {
		  fprintf(errfile,"%6d",i) ;
			 for ( j = 0; j < rr2; j++) {
				d = euklid(helpa->cep,helpb->cep,number);
				fprintf(errfile,"%9.0f",d) ;
				if ( klein > d ) {
					y=i;x=j;
					klein = d; }
//				helpmat->entfernung = d;
//				helpmat->naechsta = (struct dist *) malloc(sizeof(struct dist));
//				helpmat = helpmat->naechsta;
//				helpmat->naechsta = NULL;
				helpb = helpb->kette;
				}
			fprintf(errfile,"\n") ;
			 helpa = helpa->kette;
			 helpb = cepb;
			 }


		sam1 =  sampanf1+y*khz1*uv1 ;
		sam2 =  sampanf2+x*khz2*uv2 ;

//		sam1 = sam1 /2 ;
//		sam2 = sam2 / 2 ;
		kill1(cepa);
		kill1(cepb);
//		kill2(matrix);
}


float* compute_mel_cepstrum(short* window, int winlen, int coeffnr, int sf) {


	length = (int)pow(2.0,log2(winlen)-1) ;
//	fprintf(errfile,"window %d length %d\n",winlen,length) ;
	float* s = get_fft_spectrum(window,length) ;
//	for (i=0 ; i < length/2 ; i++)
//		fprintf(errfile,"%4.0f ",s[i]) ;
//	fprintf(errfile,"\n") ;
	float* result = get_mel_cepstrum(s,length/2,sf/2,coeffnr) ;
	free(s) ;
	return(result) ; }

float* compute_phaseless_signal(short* window, int winlen, int method) {

#ifdef VECTOR

  int i;
  vector Signal((const short*)window,winlen);

  if(Signal.dim()%2)
    Signal.set(Signal.dim()-1);
  Signal.dft(mforward);

  vector h(Signal.dim());
  for(i=2; i<h.dim(); i+=2)
    h[i] = sqrt(Signal[i]*Signal[i]+Signal[i+1]*Signal[i+1]);
  h[0] = sqrt(Signal[0]*Signal[0]);
  h[1] = sqrt(Signal[1]*Signal[1]);


  if (method == 0 || method == 1)
	h.dft(minverse);


  float* result ;
  if (method != 3) {
	 result = new float[winlen] ;
	 for (i=0 ; i < h.dim() ; i++)
	result[i] = h[i] ;
	 if (h.dim() < winlen)
	result[i] = h[i-1] ; }
  else {
	 float* dings = new float[winlen/2] ;
	 for (i=0 ; i < winlen/2 ; i++)
	dings[i] = h[i*2] ;
	 result = get_mel_cepstrum(dings,winlen/2,16,20) ;
	 delete(dings) ; }
#else
	float* result = NULL ;
#endif

  return(result) ; }



#endif
