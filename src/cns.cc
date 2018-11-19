
//#define DEBUG2

#include "lisatalk.h"
#if !defined(__DAC_H__)
#include "dac.h"
#endif
#if !defined(__UNIT_H__)
#include "unit.h"
#endif
#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif
#if !defined(__RELP_H__)
#include "relp.h"
#endif
#include <string.h>
#include "sigman.h"



#ifdef UNIX
#include <unistd.h>
#endif

#define ZEROTRAP    /* turn on the trap as per the MIL-STD */
#define BIAS 0x84   /* define the add-in bias for 16 bit samples */
#define CLIP 32635

unsigned char
linear_to_ulaw (short sample)
{
  unsigned exp_lut[256] = {
    0,0,1,1,2,2,2,2,3,3,3,3,3,3,3,3,
    4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,
    5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
    5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,5,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,
    7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7
    };
  
  unsigned sign, exponent, mantissa;
  unsigned ulawbyte;

//  sample <<= mulaw_shift;
  
  /* Get the sample into sign-magnitude. */
  
  sign = ((unsigned)sample >> 8) & 0x80;    /* set aside the sign */
  if (sign != 0)
    sample = -sample;       /* get magnitude */
  if (sample > CLIP)
    sample = CLIP;      /* clip the magnitude */

  /* Convert from 16 bit linear to ulaw. */
  
  sample = sample + BIAS;
  exponent = exp_lut[((unsigned)sample >> 7) & 0xFF];
  mantissa = ((unsigned)sample >> (exponent + 3)) & 0x0F;
  ulawbyte = ~ (sign | (exponent << 4) | mantissa);
#ifdef ZEROTRAP
  if (ulawbyte == 0)
    ulawbyte = 0x02;        /* optional CCITT trap */
#endif

  return (unsigned char) ulawbyte;
}


void concat_error(const char* message, int level) {
	fprintf(errfile,"Error during concat : %s\n",message) ;
	switch (level) {
		case 0:
		case 1: exit(1) ; } }

float korrkoeff(float* a, float* b, int n) {
	if (a== NULL || b == NULL) {
   	fprintf(errfile," IN CNS:KK:input NULL\n") ;
      return(0.5) ; }
	float sumxy, sumx, sumy, sumx2, sumy2 ;
	sumxy = sumx = sumy = sumx2 = sumy2 = 0.0 ;
	int i ;	
	for (i=0 ; i < n ; i++) {
		sumx += a[i] ;
		sumy += b[i] ;
		sumxy += a[i]*b[i] ;
		sumx2 += a[i]*a[i] ;
		sumy2 += b[i]*b[i] ; }
	return(((float)n*sumxy-sumx*sumy)/sqrt(((float)n*sumx2-(sumx*sumx))*((float(n)*sumy2-(sumy*sumy))))) ; }


float sumfac(float* a, int n, float k){
	int i ;
	float result = 0.0 ;
	for (i=0 ; i< n ; i++) {
		result += pow(a[i],k) ; }
	result /= (float)n ;
	return(result) ; }	

int compute_durfacs(float* dif, int n, float fact) {
	fprintf(errfile,"IN CD %d %f\n",n,fact) ;
   fflush(errfile) ;
	int i ;
   if (n == 0)
      return(-1) ;
	for (i=0 ; i < n ; i++) {
		dif[i] = 1.0/(dif[i]*3.0+1.0) ;
		if (fact > 1.0)
			dif[i] = 1.0/dif[i] ; }

	float k[3] = {0.0,0.0,0.0} ;
	float erg[3] ;
	float deltak = 1.0 ;
	float minf ;
	int mini ;
	do{
		k[1] = k[0]-deltak ;
		k[2] = k[0]+deltak ;
		minf = 1.0E10 ;
		mini = 0 ;
		for (i=0 ; i < 3 ; i++) {
			erg[i] = pow(sumfac(dif,n,k[i]) - fact,2) ;
			if (minf > erg[i]) {
				minf = erg[i] ;
				mini = i ; } }
		if (mini == 0)
			deltak /= 4.0 ;
		k[0] = k[mini] ; }
	while (deltak > 0.0001) ;
	for (i = 1 ; i < n ; i++)
		dif[i-1] = pow(dif[i],k[0]) ;
	dif[n-1] = 1.0 ;
	if (k[0] < 0.0001)
		return(0) ;
	return(1) ; }



extern short bt2(short) ;
extern unsigned short* get_win(int length, int slope) ;

extern float* compute_mel_cepstrum(short* window, int winlen, int coeffnr, int sf) ;

#ifndef NGIMMICKS
extern float euklid(float* a, float* b, int len) ;
extern float* compute_phaseless_signal(short*,int,int) ;
#endif


#define win(a,b) (short)(((unsigned long)(b)*(unsigned long)(a)) >> 16)

/* ola performs overlap addition for arrays a and b with length alen and blen,
	the resulting array is b, its length is the return value */
int ola(short* a,short* b, int blen)
{
	unsigned short* window ;
	int i ;

	window = get_win(blen,1) ;
	if (window == 0) {
		fprintf(errfile,"WINDOW ZERO\n") ;
		return(blen) ; }
	for (i=0 ; i < blen ; i++)
		b[i] = win(a[i],window[i]) + win(b[i],window[(blen-1)-i]) ;
	delete[](window) ;
	return(blen) ;
}
int lengthola(short* a,int alen, int blen)
{
	unsigned short* window ;
	int i ;

	short* b = new short[alen] ;
	memcpy(b,a,alen*sizeof(short)) ;
	window = get_win(blen,1) ;
	if (window == 0) {
		fprintf(errfile,"WINDOW ZERO\n") ;
		return(blen) ; }
	for (i=0 ; i < blen ; i++)
		a[i] = win(b[i],window[i]) + win(b[i],window[(alen-1)-i]) ;
	delete(window) ;
	delete(b) ;
	return(blen) ;
}

int findmin(short* s, int slen, int targetlen) {
	int pmin  ;
	pmin = slen-targetlen ;
	return(pmin) ; }


short* Sigman::get_next_signal_part(Inventory& invent, Periodlist& pl, Marklist& ml, int* sl, int& reset) {

	char* name ;
	char typ = ' ' ;
	int sf = invent.get_sf() ;
	Unit unit ;
	int i,index ;
	unsigned short* window ;
	int sigshift ;
	int winlen ;
	long rbadress ;
	long leftborder,rightborder ;
	short* sigpart = NULL ;
	int pegeldownleft,pegeldownright ;
	Markerinfo mi ;
	Periodinfo pi[4] ;
	int newsmoothper = 0 ;
	long newsmoothadr = 0 ;
	int newsmoothlength ;
	short rightval ;
	float leftfact,rightfact ;



	if (reset) {
		if (rl != NULL)
			delete(rl) ;
		rl = NULL ;
		if (smoothwindow != NULL)
			delete(smoothwindow) ;
		smoothwindow = NULL ;
		smoothlength = 0 ;
		smoothper = 0 ;
		smoothadr = 0 ;

		leftval = 0 ; }
	else {
		while ((mi = ml.get_and_advance()).adress >= 0) {
			if (strcmp(mi.key,"---") == 0)
		 		break ; } }
	reset= 0 ;


   s2length = 0 ;

	while ((mi = ml.get_and_advance()).adress >= 0) {
		if (strcmp(mi.key,"ENDE") == 0) {
			return(NULL) ; }
		if (strcmp(mi.key,"---") == 0)
			return(sigpart) ;
		if (strncmp(mi.key,"PAU",3) == 0) {
			s2length = atoi(&mi.key[4]) ;
			sigpart = new short[s2length] ;
			nulltest(sigpart) ;
			if (rl != NULL)
				delete(rl) ;
			rl = NULL ;
			if (smoothwindow != NULL)
				delete(smoothwindow) ;
			smoothwindow = NULL ;
			smoothlength = 0 ;
			smoothper = 0 ;
			smoothadr = 0 ;
			leftval = 0 ;
			for (i=0 ; i < s2length ; sigpart[i++] = 0) ;
			*sl = s2length ;
				reset = 1 ;
			continue ; }
		if (!(strncmp(mi.key,"DIV",3) && strncmp(mi.key,"SFX",3) &&
				strncmp(mi.key,"KKD",3) && strncmp(mi.key,"VVD",3) &&
				strncmp(mi.key,"SLK",3) && strncmp(mi.key,"VS ",3) &&
				strncmp(mi.key,"EHR",3) && strncmp(mi.key,"EHS",3) &&
				strncmp(mi.key,"AHS",3) && strncmp(mi.key,"NSL",3))) break ; }

	if (mi.adress < 0)
		return(sigpart) ;

	switch (mi.key[0]) {
		case 'N' : typ = 'n' ; break ;
		case 'K' : typ = 'k' ; break ;
		case 'V' :
			if (mi.key[1] == 'S')
				typ = 'p' ;
			else
				typ = 'v' ;
			break ;
		case 'A' : typ = 'a' ; break ;
		case 'S' :
			if (mi.key[1] == 'L')
				typ = 'l' ;
			else
				typ = 's' ;
			break ;
		case 'D' : typ = 'd' ; break ;
		case 'E' : typ = 'e' ; break ; }

	name = &mi.key[4] ;
if (debuglevel > 1) {
	fprintf(errfile,"Unit %s %c fetching...\n",name,typ) ;
}


	unit = invent.get_unit_signal(name,typ) ;

	if (unit.type == 'x') {
		concat_error("unit not found",3) ;
		return(NULL) ; }

	do
		mi = ml.get_and_advance() ;
	while (strncmp(mi.key,"LB",2) != 0) ;

	leftborder = atol(&mi.key[3]) ;
	pegeldownleft = (leftborder < 0) ;
	leftborder = abs(leftborder) ;
	if (leftborder == 1)
		leftborder = 0 ;

	do
		mi = ml.get_and_advance() ;
	while (strncmp(mi.key,"RB",2) != 0) ;

	rightborder = atol(&mi.key[3]) ;
	rbadress = mi.adress ;
	pegeldownright = (rightborder < 0) ;
	rightborder = abs(rightborder) ;
	newsmoothlength = 0 ;

	do {
		mi = ml.get_and_advance() ;
		if (strncmp(mi.key,"SMO ",4) == 0) {
			newsmoothper = atoi(&mi.key[4]) ;
			newsmoothadr = mi.adress ; }
		if (strncmp(mi.key,"SML ",4) == 0)
			newsmoothlength = atoi(&mi.key[4]) ; }
	while (strncmp(mi.key,"---",3) != 0) ;

	sigpart = unit.sig->get_signal(leftborder,rightborder+newsmoothlength-1) ;
	*sl = rightborder - leftborder ;



	if (rl != NULL) {
		pl.get_period_next_to(rbadress-rightborder+leftborder) ;
		for (i=0 ; i < 4 ; i++)
			pi[i] = pl.get_and_advance() ;
		sigshift = pi[0].length ;
		*sl -= sigshift ;
		rightval = sigpart[sigshift-1] ;
		smoothadr = 0 ;
		for (i=0 ; i < 3 ; i++) {
			winlen = pi[i].length+pi[i+1].length ;
			smoothwindow=new short[winlen] ;
			nulltest(smoothwindow) ;
			memcpy(smoothwindow,&sigpart[smoothadr],sizeof(short)*winlen) ;
			smoothadr += pi[i].length ;
			rl->analyze_window(smoothwindow,winlen,pi[i].length) ;
			delete(smoothwindow) ; }
		rl->interpolate(3,5,smoothper) ;
		smoothwindow = rl->synthesize(4,3+smoothper,smoothlength) ;
		leftfact = (float)leftval / (float)smoothwindow[0] ;
		rightfact = (float)rightval / (float)smoothwindow[smoothlength-1] ;
		for (i=0 ; i < smoothlength ; i++)
			smoothwindow[i] = (int)((float)smoothwindow[i]*
				((rightfact-leftfact)*((float)i/(float)smoothlength)+leftfact)) ;
		smoothwindow = (short*)realloc(smoothwindow,sizeof(short)*(smoothlength+(*sl)+newsmoothlength)) ;
		if (smoothwindow == NULL)
			concat_error("out of heap",0) ;
		memcpy(&smoothwindow[smoothlength],&sigpart[sigshift],(*sl+newsmoothlength)*sizeof(short)) ;
		delete(sigpart) ;
		sigpart = smoothwindow ;
		smoothwindow = NULL ;
		*sl += smoothlength ;
		rightborder = leftborder + *sl + 1 ;
		smoothlength = 0 ;
		delete(rl) ;
		rl = NULL ; }

	if (smoothlength > 0) {
		s2length = pl.get_period_next_to(smoothadr).length ;
		s2length = ola(smoothwindow,sigpart,s2length) ;
		delete[](smoothwindow) ;
		smoothwindow = NULL ;
		smoothlength = 0 ; }

	if (newsmoothper > 1) {
		smoothper = newsmoothper ;
		rl = new Relplist(5+sf,0.9) ;
		nulltest(rl) ;
		pl.get_period_next_to(rbadress-3*(newsmoothlength)) ;
		for (i=0 ; i < 4 ; i++)
			pi[i] = pl.get_and_advance() ;
		pi[3].length = newsmoothlength ;
		leftval = sigpart[rightborder-leftborder] ;
		newsmoothadr = rightborder-leftborder-pi[0].length-pi[1].length-pi[2].length ;
		for (i=0 ; i < 3 ; i++) {
			winlen = pi[i].length+pi[i+1].length ;
			smoothwindow=new short[winlen] ;
			nulltest(smoothwindow) ;
			memcpy(smoothwindow,&sigpart[newsmoothadr],sizeof(short)*(winlen)) ;
			newsmoothadr += pi[i].length ;
			rl->analyze_window(smoothwindow,winlen,pi[i].length) ;
			delete(smoothwindow) ;
			smoothwindow = NULL ; } }


	if (newsmoothper == 1) {
		smoothper = newsmoothper ;
		smoothlength = newsmoothlength ;
		smoothadr = newsmoothadr ;
		smoothwindow = new short[smoothlength] ;
		nulltest(smoothwindow) ;
		memcpy(smoothwindow,&sigpart[rightborder-leftborder],smoothlength*sizeof(short)) ; }


//==========================
// signal depression at borders

	// get length for depression window
	if (pegeldownleft + pegeldownright > 0) {
		winlen = min(rightborder-leftborder,80L) ;
		window = get_win(winlen,1) ;

		// depress left side (rising hann window)
		if (pegeldownleft > 0)
			for (i = 0 ; i < winlen ; i++)
				sigpart[i] = win(sigpart[i],window[winlen-1-i]) ;

		// depress right side (falling hann window)
		if (pegeldownright > 0)
			for (i = 0 ; i < winlen ; i++) {
				index = (rightborder + i) - (leftborder+winlen) ;
				sigpart[index] = win(sigpart[index],window[i]) ; }

		delete[](window) ; }

	delete(unit.sig) ;
	return(sigpart) ; }

//=============================================================================

// psola performs pitch-synchronous overlap-add after Moulines & Charpentier

// macro computes the length of a synthesis window


#define synwinlen(a,b) (int)(method == -1? (a).length : ((a).voiced == voiced ? (float)(b) / (a).f0 : (a).length))

#ifdef _Windows
int Sigman::psola(HugeArray<DATYPE> *h, short* sigpart,int siglen, Periodlist& pl, int lastpl, Marklist& ml, FILE* synfile, FILE* perfile, FILE* mrkfile, int reset, int sf, int dares, int mulaw, int danow, int filetype, int method, float preemp, int lpc_grade, float mu, int relpdelay) {
#else
int Sigman::psola(void *h, short* sigpart,int siglen, Periodlist& pl, int lastpl, Marklist& ml, FILE* synfile, FILE* perfile, FILE* mrkfile, int reset, int sf, int dares, int mulaw, int danow, int filetype , int method, float preemp, int lpc_grade , float mu, int relpdelay ) {
#endif

   Markerinfo mm ;
	Periodinfo nextp,nextnextp ;
	short* leftbuffer = NULL ;


	short* signal2 ;
   long lastosm ;
	long lastx ;
   short vlastval ;
	int i,j ;
	int adva ;

	Periodinfo* pp ;
	float rr ;
	float lastfac ;
	int pnum ;
	int melcepcheck = -1 ;
	if (method > 9) {
		melcepcheck = method / 10 - 1 ;
		method %= 10 ; }
if (debuglevel > 1) {
	fprintf(errfile,"METHOD %d MELMETH %d\n",method,melcepcheck) ;
}
	float* melbuffer ;
	float* lastmelbuffer ;
	short* interbuffer ;
	short* shortbuffer ;
	float* dif ;

	int nextsynwin ;					// length of synthesis periods
	signed char* charbuffer ;


   // START RESET

	if (reset == 1) {
   	        strcpy(lastlab,"") ;
		m = ml.get_marker_pointer() ;
		p = pl.get(lastpl++) ;


		// START NON_STANDARD

		if (method > 0) {
			xpl = 1 ;
			iblen = 0 ;
			xp = pl.get(xpl++) ;
			if (psolarl != NULL)
				delete(psolarl) ;
			psolarl = new Relplist(lpc_grade,mu) ; }
		if (method == 0 && melcepcheck > -1) {
			xpl = 1 ;
			iblen = 0 ;
			xp = pl.get(xpl++) ; }
		if (method == 2)
			lastpl-- ;

		// END NON_STANDARD

		rightbuffer = NULL ;
		if (signal != NULL)
			delete(signal) ;
		signal = NULL ;
		oldsiglen = 0 ;
		last = 0 ;
		durshift = 0 ;						// duration shift
		sample = 0L ;						// number of synthesized samples
		osm = 0L ;
		lastmelbuffer = NULL ;
		actsample = p.length ;
		synwin = synwinlen(p,sf*1000.0) ;
		insp = p.length ; }


	// END RESET

/*	if (long(siglen)+long(oldsiglen) > 32767L) {
		fprintf(errfile,"signal too long\n") ;
		exit(1) ; }
*/
if (debuglevel > 1) {
		fprintf(errfile,"entering PSOLA osl %ld sl %d as %ld sw %d\n",oldsiglen,siglen,actsample,synwin) ;
		fflush(errfile) ;
}


	signal2 = new short[siglen+oldsiglen] ;
	nulltest(signal2) ;
	memcpy(signal2,signal,oldsiglen*sizeof(short)) ;
	if (signal != NULL)
		delete[](signal) ;
	signal = signal2 ;
	memcpy(&signal[oldsiglen],sigpart,siglen*sizeof(short)) ;
	if (sigpart != NULL)
		delete[](sigpart) ;



	// START NON_STANDARD

#ifndef NGIMMICKS
	if (melcepcheck > -1 && method == 0) {
		lastx = 0 ;
		lastfac = 0.0 ;
		pnum = 0 ;
		dif = (float*)malloc(sizeof(float)) ;
		if (siglen >= xp.length) {
		  do {
			nextp = pl.get(xpl++) ;
			if (nextp.voiced == error)
				break ;
			fprintf(errfile,"%8ld %4d %8d %8.4f %8.4f %1d %1d %3d\n",lastx,nextp.length,nextp.f0,nextp.amp,nextp.dur,(int)nextp.voiced,(int)nextp.deletable,(int)nextp.interpolate) ;
			fflush(errfile);
			if (nextp.length > 1024)
				break ;
			if (lastfac != nextp.dur && pnum > 0) {
				if (lastfac != 0.0 && pnum > 0) {

/*
//	nur test
					for (i=0 ; i < pnum ; i++) {
						if (i >= pnum / 4 && i < 3*pnum / 4)
							dif[i] = 0.99 ;
						else
							dif[i] = 0.01 ; }
*/


					compute_durfacs(dif,pnum,lastfac) ;
if (debuglevel > 0) {
					fprintf(errfile,"%6.4f %4d : ",lastfac,pnum) ;
					rr = 0.0 ;
					for (i = 0 ; i < pnum ; i++) {
						fprintf(errfile,"%6.4f ",dif[i]) ;
						rr += dif[i] ; }
					rr /= (float)pnum ;
					fprintf(errfile,"  =>   %6.4f\n",rr) ;
}
					for (i=xpl-pnum-2 ; i < xpl-2 ; i++) {
						pl.get(i) ;
						pp = pl.get_period_pointer() ;
						pp->dur = dif[i-xpl+pnum+2] ;
 } }
				pnum = 0 ;
				lastfac = nextp.dur ; }
 			fprintf(errfile,"HERE WE ARE\n") ;
         fflush(errfile) ;
			shortbuffer = new short[nextp.length] ;
			memcpy(shortbuffer,&signal[oldsiglen+lastx],nextp.length*sizeof(short)) ;
//			melbuffer = compute_phaseless_signal(&signal[oldsiglen+lastx],nextp.length) ;
			if (lastshortbuffer != NULL) {
				pnum++ ;
				dif = (float*)realloc(dif,sizeof(float)*pnum) ;
				if (lastshortlength >= nextp.length) {
					lengthola(lastshortbuffer,lastshortlength,nextp.length) ;
					melbuffer = compute_phaseless_signal(shortbuffer,nextp.length,melcepcheck) ;
					lastmelbuffer = compute_phaseless_signal(lastshortbuffer,nextp.length,melcepcheck) ;
					lastshortlength = nextp.length ; }
				else {
					interbuffer = new short[nextp.length] ;
					memcpy(interbuffer, shortbuffer, nextp.length*sizeof(short)) ;
					lengthola(interbuffer,nextp.length,lastshortlength) ;
					melbuffer = compute_phaseless_signal(interbuffer,lastshortlength,melcepcheck) ;
					delete(interbuffer) ;
					lastmelbuffer = compute_phaseless_signal(lastshortbuffer,lastshortlength,melcepcheck) ; }
				switch (melcepcheck) {
					case 1:	dif[pnum-1] = 1000.0/euklid(melbuffer,lastmelbuffer,lastshortlength) ; break ;
					case 2: dif[pnum-1] = 20000.0/euklid(melbuffer,lastmelbuffer,lastshortlength) ; break ;
					case 0: dif[pnum-1] = pow((1.0+korrkoeff(melbuffer,lastmelbuffer,lastshortlength))/2.0,16) ; break ;
					case 3: dif[pnum-1] = 4.0/euklid(melbuffer,lastmelbuffer,20) ; break ; }
/*				for (i=0 ; i < lastshortlength; i++) {
					short dummy ;
					dummy = (short)(melbuffer[i]/5.0) ;
					fwrite(&dummy,2,1,melbfile) ;
					dummy = (short)(lastmelbuffer[i]/5.0) ;
					fwrite(&dummy,2,1,lastmelbfile) ; }
*/				fprintf(errfile,"%f %d\n",dif[pnum-1], melcepcheck) ;
				delete(lastshortbuffer) ;
				delete(melbuffer) ;
				delete(lastmelbuffer) ; }

// ola lasttestbuffer und testbuffer (auf den kuerzeren hin)
// lengthola(laengerer_buffer,istlen,solllen) ;
// laengerer_buffer ist temporaer

// berechne den KK (was passiert bei stimmlosen Segmenten ?)



//			for (i=0 ; i < 20 ; i++)
//				fprintf(errfile,"%6.3f ",melbuffer[i]) ;
//			fprintf(errfile,"\n") ;
/*			if (lastmelbuffer != NULL) {
				pnum++ ;
				dif = (float*)realloc(dif,sizeof(float)*pnum) ;
				dif[pnum-1] = 1.0/euklid(melbuffer,lastmelbuffer,20) ;
				fprintf(errfile,"%f\n",1.0/euklid(melbuffer,lastmelbuffer,20)) ;
				delete(lastmelbuffer) ; }
*/			fflush(errfile) ;
			lastshortlength = nextp.length ;
			lastshortbuffer = shortbuffer;
			lastx += xp.length ;
			xp = nextp ; }
		while (lastx+xp.length <= siglen) ; }
		if (lastfac != 0.0) {
/*
//	nur test
					for (i=0 ; i < pnum ; i++) {
						if (i > pnum / 4 && i < 3*pnum / 4)
							dif[i] = 0.99 ;
						else
							dif[i] = 0.01 ; }
*/
			compute_durfacs(dif,pnum,lastfac) ;
if (debuglevel > 0) {
			fprintf(errfile,"%6.4f %4d : ",lastfac,pnum) ;
			rr = 0.0 ;
			for (i = 0 ; i < pnum ; i++) {
				fprintf(errfile,"%6.4f ",dif[i]) ;
				rr += dif[i] ; }
			rr /= (float)pnum ;
			fprintf(errfile,"  =>   %6.4f\n",rr) ;
}
			for (i=xpl-pnum-2 ; i < xpl-2 ; i++) {
				pl.get(i) ;
				pp = pl.get_period_pointer() ;
				pp->dur = dif[i-xpl+pnum+2] ;
			}

			delete(dif) ;}

 }
#endif

	if (method > 0) {
		lastx = 0 ;
		if (siglen >= xp.length) {
		  if (lastx == 0 && iblen > 0) {
			if (interbuf == NULL)
				interbuf = (short*)malloc(2) ;
			interbuf = (short*)realloc(interbuf,sizeof(short)*(int)(iblen+xp.length)) ;
			nulltest(interbuf) ;
			memcpy(&interbuf[iblen],&signal[oldsiglen],(int)xp.length*sizeof(short)) ;
			psolarl->analyze_window(interbuf,(int)xp.length+iblen,iblen,relpdelay) ;
			delete(interbuf) ;
			interbuf = NULL ; }
		  do {
			nextp = pl.get(xpl++) ;
			if (nextp.voiced == error)
				break ;
			if (lastx+xp.length+nextp.length > siglen) {
				iblen = (int)xp.length ;
				interbuf = new short[iblen] ;
				nulltest(interbuf) ;
				memcpy(interbuf,&signal[oldsiglen+lastx],sizeof(short)*iblen) ; }
			else
				psolarl->analyze_window(&signal[oldsiglen+lastx],nextp.length+xp.length,xp.length,relpdelay) ;
			lastx += xp.length ;
			xp = nextp ; }
		  while (lastx+xp.length <= siglen) ; }
if (debuglevel > 1) {
//		psolarl->list() ;
}

		}



	// END NON_STANDARD

	// main loop
	mm = ml.get_and_advance() ;
	lastosm = p.start ;




//   fprintf(errfile,"MM READ %ld %s\n",mm.adress,mm.key) ;
	while (nextp = pl.get(lastpl++), nextsynwin = synwinlen(nextp,sf*1000),
		actsample + max((int)nextp.length,nextsynwin) <= oldsiglen+siglen) {



		// compute length of analysis and synthesis windows


		if (method < 1) {
			leftbuffer = new short[synwin] ;
			nulltest(leftbuffer) ;
			if (actsample < synwin) {
				synwin = actsample ;
if (debuglevel > 1) {
				fprintf(errfile,"actsample (%ld) < synwin (%d) -- corrected\n",actsample,synwin) ;
}
				}
			memcpy(leftbuffer,&signal[actsample-synwin],synwin*sizeof(short)) ; }


//		fprintf(errfile,"leftbuffer computed\n") ;
//      fflush(errfile) ;


		// START NON_STANDARD

		if (method == 1) {
			if (rightbuffer != NULL)
				leftbuffer = psolarl->get_residual(actsample-synwin,synwin) ;
			else {
				frame = psolarl->get_frame(actsample-synwin,synwin) ;
				leftbuffer = frame.residual ; } }


		if (perfile != NULL)
			fprintf(perfile,"%8ld %4d %8d %8.4f %8.4f %1d %1d %3d\n",osm,synwin,p.f0,p.amp,p.dur,(int)p.voiced,(int)p.deletable,(int)p.interpolate) ;
if (debuglevel > 6) {
		fprintf(errfile,"%8ld %4d %8d %8.4f %8.4f %1d %1d %3d\n",osm,synwin,p.f0,p.amp,p.dur,(int)p.voiced,(int)p.deletable,(int)p.interpolate) ;
		fflush(errfile) ;
}
      if (mrkfile != NULL)
		while (mm.adress != -1 && p.start >= mm.adress) {
      	if (mm.key[0] != '&' && mm.key[0] != '-' && mm.adress >= lastosm &&
   	      	strncmp(mm.key,"AHS",3) != 0 &&
      	   	strncmp(mm.key,"EHS",3) != 0 &&
			strncmp(mm.key,"SFX",3) != 0 &&
	         	strncmp(mm.key,"KKD",3) != 0 &&
		strncmp(mm.key,"VVD",3) != 0 &&
      		  	strncmp(mm.key,"SLK",3) != 0 &&
         		strncmp(mm.key,"VS",2) != 0 &&
	         	strncmp(mm.key,"SMO",3) != 0 &&
   	      	strncmp(mm.key,"SML",3) != 0 &&
      	   	strncmp(mm.key,"RB",2) != 0 &&
         		strncmp(mm.key,"LB",2) != 0 &&
			strncmp(mm.key,"ACC",3) != 0 &&
	         	strncmp(mm.key,"---",3) != 0) {
		fprintf(errfile,"%8ld %8ld %8ld %s\n",mm.adress, lastosm,osm,mm.key) ;
         	if (strcmp(lastlab,mm.key) != 0) {
		      	fprintf(mrkfile,"%8ld %s\n",osm,mm.key) ; }
               strcpy(lastlab,mm.key) ; }

         mm = ml.get_and_advance() ; }


                // END NON_STANDARD

		if (method == 0 || method == 1 || method == -1) {
			if (p.amp != 0.0 && rightbuffer != NULL) {

				if (p.amp > 5.0)
					p.amp = 1.0 ;
				if (p.amp != 1.0)
					for (i=0 ; i < synwin ; i++)
						leftbuffer[i] = short((float)leftbuffer[i]*p.amp) ;

//		fprintf(errfile,"leftbuffer adapted\n") ;
//      fflush(errfile) ;


				//				sw = synwin ;
				ola(rightbuffer,leftbuffer,synwin) ;
				delete[](rightbuffer) ; }

// 		fprintf(errfile,"ola computed\n") ;
//      fflush(errfile) ;


			rightbuffer = leftbuffer ; }


		// START NON_STANDARD

		if ((method == 1 || method == 2) && rightbuffer != NULL && frame.length > -1) {
			frame.residual = rightbuffer ;
			frame.length = synwin ;
			rightbuffer = psolarl->synthesize_frame(frame) ; }

		if (dares==8) {
		charbuffer = new signed char[synwin] ;
		  nulltest(charbuffer) ;
		if (rightbuffer != NULL) {
			if (mulaw == 0)
				for (i=-1 ; ++i < synwin ; charbuffer[i] = (signed char)((rightbuffer[i] >> 8) + 128)) ;
			else
				for (i=-1 ; ++i < synwin ; charbuffer[i] = linear_to_ulaw(rightbuffer[i])) ; }




#ifndef _Windows
		if (synfile != NULL && rightbuffer != NULL)
			fwrite(charbuffer,sizeof(signed char),synwin,synfile) ;
#else
		if (h != NULL && rightbuffer != NULL)
			h->Append((DATYPE*)charbuffer,synwin) ;
#endif
		delete(charbuffer) ; }
		else {

		  // END NON_STANDARD

      if (preemp > 0.0 && rightbuffer != NULL)
			for (i = 0 ; i < synwin ; i++) {
         	vlastval = rightbuffer[i] ;
            rightbuffer[i] -= (int)((float)preemp * (float)lastval) ;
            lastval = vlastval ; }

//  		fprintf(errfile,"preemp computed\n") ;
//      fflush(errfile) ;



#ifndef _Windows
		if (danow == 0 && rightbuffer != NULL) {
#ifndef SUN
			if (filetype == 2)
				for (i=-1 ; ++i < synwin ; rightbuffer[i] = bt2(rightbuffer[i])) ;
#endif
#ifdef SUN
			if (filetype == 1)
				for (i=-1 ; ++i < synwin ; rightbuffer[i] = bt2(rightbuffer[i])) ;
#endif


			fwrite(rightbuffer,sizeof(short),synwin,synfile) ; }
#ifdef SOLARIS
		else if (piping && rightbuffer != NULL)
			write(danow,rightbuffer,synwin*sizeof(DATYPE)) ;
#endif
#else
		if (h != NULL && rightbuffer != NULL) {
			h->Append((DATYPE*)rightbuffer,synwin) ; }
#endif
		}

//		fprintf(errfile,"buffer written\n") ;
//      fflush(errfile) ;



		osm += synwin ;

		if (rightbuffer != NULL) {
			delete[](rightbuffer) ;
			rightbuffer = NULL ; }

		if (nextp.voiced == error)
			break ;

		if (nextp.amp != 0.0 && method < 1) {
			if (nextsynwin < 0) {
				fprintf(errfile,"nextsynwin negative %d start %ld length %d f0 %d voiced %d\n",nextsynwin,nextp.start,nextp.length,nextp.f0,(int)nextp.voiced) ;
				fflush(errfile) ;
				break ; }

			rightbuffer = new short[nextsynwin] ;
			nulltest(rightbuffer) ;
			memcpy(rightbuffer,&signal[actsample],nextsynwin*sizeof(short)) ;
			if (nextp.amp > 5.0)
				nextp.amp = 1.0 ;
			if (nextp.amp != 1.0)
				for (i=0 ; i < nextsynwin ; i++)
					rightbuffer[i] = short((float)rightbuffer[i]*nextp.amp) ; }

//		fprintf(errfile,"rightbuffer computed\n") ;
//      fflush(errfile) ;



		// START NON_STANDARD

		if (method == 1) {
			frame = psolarl->get_frame(actsample,nextsynwin) ;
			if (frame.length == -1 || frame.residual == NULL)
				break ;
			rightbuffer = frame.residual ;
			if (p.amp != 1.0)
				for (i=0 ; i < nextsynwin ; i++)
					rightbuffer[i] = int((float)rightbuffer[i]*p.amp) ; }

		if (method == 2) {
			frame = psolarl->get_frame(sample,nextp.length) ;
if (debuglevel > 1) {
			fprintf(errfile,"found %ld %d %d\n",sample,frame.length,nextp.length) ;
}
			if (frame.length == -1 || frame.residual == NULL) {
				fprintf(errfile,"but no success\n") ;
				break ; }
			sample += nextp.length ;
//			if (frame.length < 30)
//				nextsynwin = frame.length ;
			fprintf(errfile,"%d\n",nextsynwin) ;
         fflush(errfile) ;
			rightbuffer = new short[nextsynwin] ;
			nulltest(rightbuffer) ;

//	ATTENTION!!!
/*			frame.length = nextp.length ;
         frame.residual = new short[frame.length] ;
			memcpy(frame.residual,&signal[actsample],nextp.length*sizeof(short)) ;
*/
			i = (nextsynwin > nextp.length ? 10 : nextp.length-nextsynwin) ;


			if (i > 0) {
				i = findmin(frame.residual,frame.length,i) ;
				if (nextsynwin > nextp.length) {
					memcpy(rightbuffer,frame.residual,i*sizeof(short)) ;
					for (j=i ; j < i+ (nextsynwin-nextp.length); j++)
						rightbuffer[j] = 0 ;
					memcpy(&rightbuffer[j],&frame.residual[i],(nextp.length-i)*sizeof(short)) ; }
				else {
					memcpy(rightbuffer,frame.residual,i*sizeof(short)) ;
					memcpy(&rightbuffer[i],&frame.residual[i+nextsynwin-nextp.length],(nextsynwin-i)*sizeof(short)) ; } }
			else
				memcpy(rightbuffer,frame.residual,frame.length*sizeof(short)) ;
			delete(frame.residual) ;
			frame.length = nextsynwin ;

			if (p.amp > 5.0)
				p.amp = 1.0 ;
			if (p.amp > 0.0 && p.amp != 1.0)
				for (i=0 ; i < nextsynwin ; i++)
					rightbuffer[i] = int((float)rightbuffer[i]*p.amp) ; }


		// END NON_STANDARD

		// update sample
		actsample += nextp.length ;

		durshift -= synwin - (int)(p.dur * (float)p.length) ;
		durshift = min(durshift,3*nextsynwin) ;

		if (method == -1)
			durshift = 0 ;

		synwin = nextsynwin ;
		adva = 0 ;
		// check for repetitions or deletions
		if (durshift >= nextsynwin) {

			// insert a period (repeat last one)
			if (nextp.deletable && actsample > nextp.length+p.length) {
				durshift -= (int)(nextp.dur*(float)nextp.length) ;
				actsample -= nextp.length ;
				sample -= nextp.length ;
				lastpl -- ; } }

		else while (durshift <= -nextsynwin) {

			adva++ ;
			// delete periods until duration is correct
			if (nextp.deletable == 0) break ;
			nextnextp = pl.get(lastpl) ;
			if (nextnextp.deletable == 0) {
				break ; }
			if (nextnextp.voiced == error)
				break ;
			nextsynwin = synwinlen(nextnextp,sf*1000) ;
			if (actsample + max((int)nextnextp.length,nextsynwin) > oldsiglen+siglen) {
				nextsynwin = synwinlen(nextp,sf*1000) ;
				break ; }
			lastpl++ ;
			nextp = nextnextp ;
			actsample += nextp.length ;
				sample += nextp.length ;
			durshift += int(nextp.dur*(double)nextp.length) ; }

//		fprintf(errfile,"durshift computed\n") ;
//      fflush(errfile) ;


		// move prosody
		if (nextsynwin > actsample)
			nextsynwin = actsample ;
		p = nextp ; }


	if (nextp.voiced == error) {
	  if (debuglevel > 1) {
	    fprintf(errfile,"End of PSOLA - deleting variables\n") ; fflush(errfile) ; }
		// prepare rightbuffer for right part of actual window in smoothbuffer
		if (signal != NULL) {
			delete[](signal) ;
			signal = NULL ; }
		if (rightbuffer != NULL)
			delete[](rightbuffer) ;
		if (lastshortbuffer != NULL) {
			delete(lastshortbuffer) ;
			lastshortbuffer = NULL ; }
		if (psolarl != NULL) {
			delete(psolarl) ;
			psolarl = NULL ; }
//		fclose(lastmelbfile) ;
//		fclose(melbfile) ;
		lastpl = -1 ;


 }

	else {
		lastpl-- ;
		memmove(signal,&signal[actsample-synwin],(siglen+oldsiglen+synwin-actsample)*sizeof(short)) ;
		oldsiglen = oldsiglen+siglen+synwin-actsample ;
		actsample = synwin ;
if (debuglevel > 1) {
		fprintf(errfile,"leaving PSOLA osl %ld sl %d as %ld sw %d\n",oldsiglen,siglen,actsample,synwin) ; fflush(errfile) ;
}
		if (oldsiglen < actsample)
			exit(1) ; }

	return(lastpl) ; } ;








