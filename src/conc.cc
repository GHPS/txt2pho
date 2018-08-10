
#include "lisatalk.h"
#if !defined(__UNIT_H__)
#include "unit.h"
#endif
#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif
#include "sigman.h"
#include <string.h>

//#define DEBUG2

extern void concat_error(char* message, int level) ;



long get_border(int value, char* text, Unit& u, int sf, float position) {
	long retval ;
	if (text[0] == '!') {
if (debuglevel > 1) {
		fprintf(errfile,"%s %c %s retval: %ld\n",u.name,u.type,text,u.pitchmarks->get_period_next_to(atol(&text[1])*sf).start) ;
}
		return(u.pitchmarks->get_period_next_to(atol(&text[1])*sf).start) ; }
	retval = u.borders->get_marker_adress(text) ;
	if ((position != 0.0 || retval == -1) && (text[0] == '&')) {
		retval = u.borders->get_marker_adress(&text[1]) ;
		retval += int((float)(u.borders->get_marker_adress_after(&text[1]) - u.borders->get_marker_adress(&text[1]))*(position== 0.0 ? 0.4:position)); }
	if (retval < 0)
		return(-1L) ;
	long offset = value*sf ;
	return(u.pitchmarks->get_period_next_to(offset+retval).start) ; }


Markerinfo mm(char* a, long sigpos, long number = 0L) {
	Markerinfo m ;
	int pos ;
	m.adress=sigpos;

	strcpy(m.key,a) ;
	if (number != 0L) {
		pos = strlen(m.key) ;
		sprintf(&(m.key)[pos],"%ld",number) ; }
	return(m) ; }

//========================================================================

int Sigman::get_next_mark_and_pm(Inventory& invent, Unitlist* u, Soundlist* soli, Periodlist& pl, Marklist& ml, long& sigpos, float position) {

	char typname[20] ;
	Parameterset par ;
	Unit unit ;
	int sf = invent.get_sf() ;
	int i ;
	long leftborder,rightborder ;
	int pegeldownleft,pegeldownright ;
	float lpegel, rpegel ;
	Markerinfo mi ;
	Periodinfo pi ;
	long s2length = 0L ;
	int vorperiods = 0 ;
	Periodinfo* pp ;
	int actlastindex = 0 ;
	long unitsamples = 0L ;
	long startpos ;

startagain:
	do
		if ((par = u->get_next_set(soli)).type == 'x') {
		  //      	fprintf(errfile,"Not found\n") ;
		  //         fflush(errfile) ;
			return(0) ; }
	while (strcmp(par.name,"DELETE") == 0)  ;

if (debuglevel > 1) {
	fprintf(errfile,"%s ",par.name) ;
   fflush(errfile) ;
}

	if (par.type == 'P') {
		pi.start = sigpos ;
		pi.length = (int)(par.dau*sf) ;
		ml.conc(mm("PAU ",sigpos,pi.length)) ;
		pi.f0 = (short)1.0 ;
		pi.dur = 1.0 ;
		pi.amp = 0.0 ;
		pi.voiced = (excitation) 1 ;
		pi.deletable = 0 ;
		pi.interpolate = 0 ;
		pl.conc(pi) ;
		sigpos += pi.length ;
		ml.conc(mm("---",sigpos)) ;
			return(1) ; }


	unit = invent.get_unit_info(par.name,par.type) ;


	if (unit.type == 'x') {
		fprintf(errfile,"Unit %s %c nicht gefunden\n",par.name,par.type) ;
      fflush(errfile) ;
		concat_error("unit not found",3) ;
		goto startagain ; }


if (debuglevel > 1) {
	fprintf(errfile,"Unit fetched\n") ;
   fflush(errfile) ;
}
if (debuglevel > 3) {
	fprintf(errfile,"CONC: Unit %s %c %s %s\n",par.name,par.type,par.lcs,par.rcs) ;
   fflush(errfile) ;
}


	leftborder = unit.pitchmarks->get_period_next_to(get_border(par.lct,par.lcs,unit,sf,position)).start ;
	rightborder = unit.pitchmarks->get_period_next_to(get_border(par.rct,par.rcs,unit,sf,position)).start ;
	if (leftborder < 0 || rightborder < 0) {
		fprintf(errfile,"Unit %s %c Grenzen %s oder %s nicht gefunden\n",par.name,par.type,par.lcs,par.rcs) ;
		concat_error("unit border not found",3) ;
		goto startagain ; }

if (debuglevel > 1) {
	fprintf(errfile,"lb %ld rb %ld\n",leftborder, rightborder) ;
   fflush(errfile) ;
}

	if (conc_smoothlength > 0) {
		pi = unit.pitchmarks->get_period_next_to(leftborder) ;
		s2length = pi.length ;
		if (conc_periods > 1) {
			unit.pitchmarks->advance() ;
			s2length = unit.pitchmarks->get().length ; }
		s2length = min((long)conc_smoothlength,s2length) ;
		conc_smoothlength = pi.length ;
		leftborder += pi.length - s2length ;
		for (i=0 ; i < conc_periods ; i++) {
			pi.dur = 1.0 ;
			pi.length = s2length ;
			pi.start = sigpos ;
			sigpos += s2length ;
			pi.voiced = voiced ;
			pi.f0 = short((sf * 1000.0) / s2length) ;
			pi.deletable = 1 ;
			pi.interpolate = 1 ;
			pl.conc(pi) ; }
		vorperiods = conc_periods ;
		conc_periods = 0 ;
		conc_smoothlength = 0 ; }


	if (par.inp) {
		conc_smoothlength = unit.pitchmarks->get_period_next_to_with_offset(rightborder,-1).length ;
		conc_periods = par.inp ;
		rightborder -= conc_smoothlength ;
		if (conc_periods > 1)
			conc_smoothlength = unit.pitchmarks->get_period_next_to_with_offset(rightborder+conc_smoothlength,-2).length ; }

if (debuglevel > 1) {
	fprintf(errfile,"smmothlength %d\n",conc_smoothlength) ;
   fflush(errfile) ;
}


	switch (par.type) {
		case 'a' : strcpy(typname,"AHS ") ; break ;
		case 'e' : strcpy(typname,"EHS ") ; break ;
		case 'r' : strcpy(typname,"EHR ") ; break ;
		case 's' : strcpy(typname,"SFX ") ; break ;
		case 'v' : strcpy(typname,"VVD ") ; break ;
		case 'l' : strcpy(typname,"SLK ") ; break ;
		case 'p' : strcpy(typname,"VS  ") ; break ;
		case 'k' : strcpy(typname,"KKD ") ; break ;
		case 'n' : strcpy(typname,"NSL ") ; break ; }
	strcat(typname,par.name) ;
	ml.conc(mm(typname,sigpos)) ;
	ml.conc(mm("ACC ",sigpos,par.acc)) ;



//=====================
// compute amplitude factor

	// initialize sigdep flags
	pegeldownleft = pegeldownright = 0 ;

	// get values from rc file
	lpegel = (double)par.apl ;
	rpegel = (double)par.apr ;

	// left border amplitude
	// value > 10 -> dB value with actual value gives mult. factor
	if (lpegel > 100.0)
		lpegel = pow(10.0,((lpegel-100)-unit.pitchmarks->get_max_dB())/20.0) ;

	if (lpegel < -100) {
		lpegel = pow(10.0,(-(lpegel+100)-unit.pitchmarks->get_max_dB())/20.0) ;
		pegeldownleft = 1 ; }

	if (lpegel > 10.0)
		lpegel = pow(10.0,(lpegel-unit.pitchmarks->get_dB(leftborder))/20.0) ;

	// value < -10 -> as above, but use depression
	if (lpegel < -10.0) {
		lpegel = pow(10.0,(-lpegel-unit.pitchmarks->get_dB(leftborder))/20.0) ;
		pegeldownleft = 1 ; }

	// value = -1, depression, factor same as right border factor
	if (lpegel == -1.0) {
		lpegel = 0.0 ;
		pegeldownleft = 1 ; }

	// right border amplitude
	// value > 10 -> dB value with actual value gives mult. factor
	if (rpegel > 10.0)
		rpegel = pow(10.0,(rpegel-unit.pitchmarks->get_dB(rightborder))/20.0) ;

	// value < -10 -> as above, but use depression
	if (rpegel < -10.0) {
		rpegel = pow(10.0,(-rpegel-unit.pitchmarks->get_dB(rightborder))/20.0) ;
		pegeldownright = 1 ; }

	// value = -1, depression, factor same as right border factor
	if (rpegel == -1.0) {
		rpegel = 0.0 ;
		pegeldownright = 1 ; }

	// value = 0, use factor from other side
	if (rpegel == 0.0 && lpegel == 0.0)
		rpegel = lpegel = 1.0 ;
	if (rpegel == 0.0) rpegel = lpegel ;
	if (lpegel == 0.0) lpegel = rpegel ;


if (debuglevel > 1) {
	fprintf(errfile,"rpegel %f lpegel %f\n",rpegel,lpegel) ;
   fflush(errfile) ;
}


	if (leftborder == 0)
		leftborder = 1 ;
	ml.conc(mm("LB ",sigpos,(pegeldownleft?-leftborder:leftborder))) ;
	if (leftborder == 1)
		leftborder = 0 ;
	if (vorperiods > 0)
		leftborder += s2length ;

	pi = unit.pitchmarks->get_period_next_to(leftborder) ;
	pi = unit.pitchmarks->get_and_advance() ;
	startpos = sigpos ;

	while (pi.start < rightborder && pi.voiced != error) {
   	if (pi.length < 40) {
 			pi = unit.pitchmarks->get_and_advance() ;
      	continue ; }
		pi.interpolate = 0 ;
		pi.dur = 1.0 ;
		pi.f0 = (short)(sf * 1000.0) / pi.f0 ;
		pi.deletable = 1 ; //!(pi.voiced == plosive) ;
		if (pi.start == leftborder && pegeldownleft)
			pi.deletable = 0 ;
		if (pi.start+pi.length == rightborder && pegeldownright)
			pi.deletable = 0 ;
		pi.start = sigpos ;
		sigpos += pi.length ;
		unitsamples += pi.length ;
		actlastindex = pl.conc(pi) ;
		pi = unit.pitchmarks->get_and_advance() ; }

	if (vorperiods > 0) {
		lpegel = pl.get(conc_lastindex).amp ;
		rpegel = pl.get(conc_lastindex+vorperiods+1).amp ;
		pl.get(conc_lastindex+1) ;
		for (i=0 ; i < vorperiods; i++) {
			pp = pl.get_period_pointer() ;
			pl.advance() ; } }
	conc_lastindex = actlastindex ;

	unit.borders->reset() ;
	while (mi = unit.borders->get_and_advance(),mi.adress <= rightborder && mi.adress >= 0) {
		if (strcmp(mi.key,"MARK1") == 0 || strcmp(mi.key,"MARK2") == 0 ||
			 strcmp(mi.key,"START") == 0 || strcmp(mi.key,"VOICED") == 0 ||
			 strcmp(mi.key,"UNVOICED") == 0 || strcmp(mi.key,"PLOSIVE") == 0 ||
			 strcmp(mi.key,"PAUSE") == 0)
			continue ;
		if (mi.key[0]=='_' && mi.key[2]=='2')
			mi.key[2] = '\0' ;
		if (mi.key[0]=='s' && mi.key[1]=='2')
			mi.key[1] = '\0' ;
		ml.conc(mm(mi.key,startpos+(mi.adress-leftborder>0?mi.adress-leftborder:0))) ; }

	rightborder = leftborder+unitsamples ;
	ml.conc(mm("RB ",sigpos,(pegeldownright?-rightborder:rightborder))) ;
	if (par.inp > 0) {
		ml.conc(mm("SMO ",sigpos,par.inp)) ;
		ml.conc(mm("SML ",sigpos,conc_smoothlength)) ; }
	ml.conc(mm("---",sigpos)) ;

if (debuglevel > 1) {
	if (unitsamples < 20*sf)
		fprintf(errfile,"%s %c: %ld samples\n",par.name,par.type,unitsamples) ;
}

	delete(unit.pitchmarks) ;
	delete(unit.borders) ;
if (debuglevel > 1) {
	fprintf(errfile,"%s %c with %ld samples processed\n",par.name,par.type,unitsamples) ;
   fflush(errfile) ;
}
	return(1) ; }


