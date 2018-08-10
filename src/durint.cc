
#include "lisatalk.h"
#if !defined(__DI_H__)
#include "di.h"
#endif
#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif

#include <string.h>

extern int isspace(char c);

Duration::Durationlist::Durationlist() {
	errorvalue.type = 'x' ; }

Duration::Durationlist::~Durationlist() { ; }
int Duration::Durationlist::conc(Duration_unit a) { return(append(a)) ; }

Duration_unit* Duration::Durationlist::get_durinf_pointer(int indexnr) {
	get(indexnr) ;
	return(&(act->i)) ; }


void Duration::Durationlist::multiply_value(int indexnr, float factor) {
	Duration_unit* du = get_durinf_pointer(indexnr) ;
	du->value *= (int)factor ;
	if (du->value > maxdur)
		du->value = maxdur ; }

char* Duration::Durationlist::get_name(int indexnr) {
	return(get(indexnr).name) ; }


/* constructor reads model parameters from file named fujifilnam
		parameters must appear at the beginning of a line */

Duration::Duration(int samplingf) {

        lastampfac = 0.0 ;
	sf = samplingf ;
}

//===================

// destructor deletes accent and phrase list

Duration::~Duration() { reset() ; }


//=============================================================================

int Duration::input_duration(Soundlist* soli) {

	Duration_unit du ;
	int k ;
	soli->reset() ;
	Soundinfo s ;
   int c = 0 ;

	while ((s = soli->get_and_advance()).duration != -1) {
		if (s.duration == 0)
			continue ;
		du.value = s.duration ;
		du.f0nr = s.f0nr ;
		du.amp = s.intensity ;
		if (du.f0nr > 29)
        	du.f0nr = 29 ;
		strcpy(du.name,s.name) ;
		if (strcmp(du.name,"pau") == 0)
			du.f0nr = 0 ;
		else
			for (k = 0 ; k < s.f0nr; k++) {
				du.f0pos[k] = (int)s.f0pos[k] ;
				du.f0[k] = s.f0[k] ; }
      c++ ;
		durl.conc(du) ; }
   if (debuglevel > 4) {
   	fprintf(errfile,"%d Duration units\n",c) ; }
	durl.reset() ;
	return(1) ; }

int Duration::write_sentence_duration(Periodlist& pl,Marklist& ml,long start, long end, FILE* nmkfile) {
	pl.reset() ;
//	long actsample ;
	Periodinfo* p, *q ;
	Markerinfo m1,m2 ;
	ml.reset() ;
//	durl.reset() ;
	int fallback ;
	long islen ;
	int firstone ;
	int lookahead, fallbackindex ;
	float durfac,ampfac, midpoint ;
	if (start == 0L) {
		if (debuglevel > 4) {
      	fprintf(errfile,"Durint reset\n") ; fflush(errfile) ; }
		newactsample = 0L ;
		actms = 0L ;
		du1 = durl.get() ;
		du2 = durl.exclude_and_advance_and_get() ;
		actf0 = 140 ;
		lastactf0pos = 0 ;
		lastactf0 = 140 ;
		actf0pos = 0.0 ;
		actf0nr = 0 ; }
	if (du2.type == 'x')
		return(1) ;
	if (debuglevel>4) {
	  fprintf(errfile,"looking for %s before %s\n",du1.name,du2.name) ;
     fflush(errfile) ; }
	while (m1 = ml.get_and_advance(),m1.adress != -1) {
	if (debuglevel > 4) {
	  fprintf(errfile,"%s read\n",m1.key) ;
     fflush(errfile) ; }
		if (m1.adress < start)
			continue ;
		if (strcmp(m1.key,du1.name) == 0)
			break ;
		if (strncmp(m1.key,"PAU",3) == 0 && strncmp(du1.name,"pau",3) == 0) {
//			actms += du1.value ;
			break ; }
		if (m1.key[0] == '=' && m1.key[1] == du1.name[0])
			break ;
		if (du1.name[0] == '=' && m1.key[0] == du1.name[1])
			break ;
		if (m1.key[0] == '@' && du1.name[0] == '=')
			break ;
		if (du1.name[1] == '~' && m1.key[1] == ':')
		  break ;
		if (du1.name[1] == '~' && m1.key[0] == du1.name[0])
		  break ;
		if (m1.key[0] == 'i' && du1.name[0] == '<' && du1.name[1] == 'i')
			break ;
		if (m1.key[0] == 'u' && du1.name[0] == '<' && du1.name[1] == 'u')
			break ;
		if (m1.key[0] == 'o' && du1.name[0] == '<' && du1.name[1] == 'o')
			break ;
		if (m1.key[0] == du1.name[0]) {
			if (m1.key[1] == '0' || du1.name[1] == '0')
				break ;
			if ((m1.key[0] == '_' || m1.key[0] == '&') && m1.key[1] == du1.name[1] && (m1.key[2] == '0' || du1.name[2] == '0'))
				break ;
			if ((m1.key[0] == 'a' && strchr("iu:",du1.name[1]) != NULL) ||
				 (m1.key[0] == 'd' && du1.name[1] == ':') ||
				 (m1.key[0] == 'o' && du1.name[1] == 'i') ||
				 (m1.key[0] == 'a' && strchr("IU:",du1.name[1]) != NULL) ||
				 (m1.key[0] == 'E' && du1.name[1] == ':') ||
				 (m1.key[0] == 'E' && du1.name[1] == ':') ||
				 (m1.key[0] == 'O' && du1.name[1] == ':') ||
				 (m1.key[0] == '9' && du1.name[1] == ':') ||
				 (m1.key[0] == '@' && du1.name[1] == ':') ||
			         (m1.key[1] == ':' && du1.name[0] == 'E') ||
				 (m1.key[1] == ':' && du1.name[0] == 'a') ||
				 (m1.key[1] == ':' && du1.name[0] == 'y') ||
				 (m1.key[1] == ':' && du1.name[0] == 'o') ||
				 (m1.key[1] == ':' && du1.name[0] == 'u') ||
				 (m1.key[1] == ':' && du1.name[0] == 'e') ||
				 (m1.key[1] == ':' && du1.name[0] == '2') ||
				 (m1.key[1] == ':' && du1.name[0] == 'i') ||
				 (m1.key[0] == 'O' && du1.name[1] == 'Y'))
				 break ; } }
	if (m1.adress == -1) {
		fprintf(errfile,"Error: sound %s not found in dd m1\n",du1.name) ;
		return(0) ; }
   if (debuglevel > 4) {
   	fprintf(errfile,"first mark found %s %ld\n",m1.key,m1.adress);
      fflush(errfile) ; }

	while (pl.get_period_pointer()->start < m1.adress)
		if (pl.advance() == -1)
			break ;
//		actf0nr = 0 ;
//		lastactf0 = 140 ;
//		lastactf0pos = 0 ;
//		actf0pos = (du1.f0nr > 0 ? du1.f0pos[actf0nr]: 0.0) ;
//		actf0 = 140.0 ;
	fallback = ml.get_number() ;
	fallbackindex = durl.get_number() ;
	lookahead = 0 ;
	while (lookahead < 2) {
		while (m2 = ml.get_and_advance(),m2.adress != -1) {
			if (strcmp(m2.key,du2.name) == 0)
				break ;
			if (strncmp(m2.key,"PAU",3) == 0 && strncmp(du2.name,"pau",3) == 0)
				break ;
			if (m2.key[0] == '=' && m2.key[1] == du2.name[0])
				break ;
			if (du2.name[0] == '=' && m2.key[0] == du2.name[1])
			  break ;
			if (m2.key[0] == '@' && du2.name[0] == '=')
					break ;
			if (m2.key[0] == 'i' && du2.name[0] == '<' && du2.name[1] == 'i')
				break ;
			if (m2.key[0] == 'u' && du2.name[0] == '<' && du2.name[1] == 'u')
				break ;
			if (du2.name[1] == '~' && m2.key[1] == ':')
			  break ;
			if (du2.name[1] == '~' && m2.key[0] == du2.name[0])
			  break ;
			if (m2.key[0] == 'o' && du2.name[0] == '<' && du2.name[1] == 'o')
				break ;
			if (m2.key[0] == du2.name[0]) {
				if (m2.key[1] == '0' || du2.name[1] == '0')
					break ;
				if ((m2.key[0] == '_' || m1.key[0] == '&') && m2.key[1] == du2.name[1] && (m2.key[2] == '0' || du2.name[2] == '0'))
					break ;
				if ((m2.key[0] == 'a' && strchr("iu:",du2.name[1]) != NULL) ||
					 (m2.key[0] == 'd' && du2.name[1] == ':') ||
					 (m2.key[0] == 'o' && du2.name[1] == 'i') ||
					 (m2.key[0] == 'a' && strchr("IU:",du2.name[1]) != NULL) ||
					 (m2.key[0] == 'E' && du2.name[1] == ':') ||
					 (m2.key[0] == 'O' && du2.name[1] == ':') ||
					 (m2.key[0] == '9' && du2.name[1] == ':') ||
					 (m2.key[0] == '@' && du2.name[1] == ':') ||
				         (m2.key[1] == ':' && du2.name[0] == 'E') ||
					 (m2.key[1] == ':' && du2.name[0] == 'a') ||
					 (m2.key[1] == ':' && du2.name[0] == 'y') ||
					 (m2.key[1] == ':' && du2.name[0] == 'o') ||
					 (m2.key[1] == ':' && du2.name[0] == 'i') ||
					 (m2.key[1] == ':' && du2.name[0] == 'u') ||
					 (m2.key[1] == ':' && du2.name[0] == 'e') ||
					 (m2.key[1] == ':' && du2.name[0] == '2') ||
                (m2.key[1] == ':' && du2.name[0] == 'i') ||
					 (m2.key[0] == 'O' && du2.name[1] == 'Y'))
					 break ; } }
/*		if (m2.adress == -1 && du2.type != 'x') {
			if (durl.advance() < 0) {
				lookahead = 2 ;
				break ; }
			fprintf(errfile,"Error: sound %s not found in dd m2\n",du2.name) ;
			du2 = durl.get() ;
			lookahead++ ;
			ml.get(fallback) ;
			if (lookahead == 2)
				break ;
			goto start ; } */
		if (m2.adress == -1)
			break ;
	  islen = m2.adress - m1.adress ;
     if (debuglevel > 4) {
   	fprintf(errfile,"second mark found %s %ld\n",m2.key,m2.adress);
      fflush(errfile) ; }

	  if (islen > 0 && du1.value > 2.0)
				durfac = (float)(du1.value)*(float)sf/(float)islen ;
		else
			durfac = 1.0 ;
//		if (strchr("_ptkbdg",m1.key[0]) !=  NULL)
//			durfac = 1.0 ;
		actf0nr = 0 ;
		if (strchr("ptkbdg_?",m1.key[0]) != NULL || (du1.amp < 10 && du1.amp > 0))
			ampfac = 1.0 ;
		else
      	if (du1.amp > 10.0)
				ampfac = pow(10.0,(du1.amp/20.0)) ;
         else
         	ampfac = 1.0 - (abs(du1.amp+2.0)/20.0) ;
		if (m1.key[0] == 'P')
			ampfac = 0.0 ;
		if (lastampfac < 10.0)
			lastampfac = ampfac ;

		q = pl.get_period_pointer() ;

		firstone = 1 ;
		do {
			p = pl.get_period_pointer() ;

			if (p->start >= m2.adress)
				break ;

         if (debuglevel > 4) {
         	fprintf(errfile,"%ld %d %f %f\n",p->start,p->f0,p->amp,p->dur) ;
            fflush(errfile) ; }

         if (firstone)
         	actf0pos = 0.0 ;
         if (debuglevel > 4) {
				fprintf(errfile,"actf0pos %f\n",actf0pos) ;
	         fprintf(errfile,"leftside %f rightside %f\n",float(p->start - m1.adress) * durfac,actf0pos*(float)sf) ;
            fflush(errfile) ; }
			if (float(p->start - m1.adress) * durfac > actf0pos*(float)sf) {
				if (debuglevel > 4) {
					fprintf(errfile,"CHANGE\n") ;
               fflush(errfile) ; }
				lastactf0 = actf0 ;
            if (firstone == 0)
					lastactf0pos = actf0pos ;
            else {
            	firstone = 0 ; }
				if (actf0nr < du1.f0nr) {
					actf0pos = du1.f0pos[actf0nr] ;
					actf0 = du1.f0[actf0nr++] ; }
				else {
					if (du2.f0nr > 0) {
						actf0pos = du2.f0pos[0]+du1.value ;
						actf0 = du2.f0[0] ; }
					else {
						actf0 = lastactf0 ;
						actf0pos = du1.value ; } } }
			if (actf0pos == lastactf0pos)
				p->f0 = (int)actf0 ;
			else
				p->f0 = int(lastactf0+(actf0-lastactf0)*((float(p->start - m1.adress) * (durfac/(float)sf) - lastactf0pos)/(actf0pos-lastactf0pos)));
			if (p->f0 < 30) {
         	p->f0 = (short)lastactf0 ;
   			if (debuglevel > 4) {
		         fprintf(errfile,"F0 too low in DURINT: f0 %d lastactf0 %f actf0 %f p->start %ld m1.adress %ld durfac %f sf %d lastactf0pos %f actf0pos %f\n",p->f0,lastactf0,actf0,p->start,m1.adress,durfac,sf,lastactf0pos,actf0pos) ;
					fprintf(errfile,"start-adress %f df/sf %f term1 %f af0p-laf0p %f\n", float(p->start - m1.adress),(durfac/(float)sf),(float(p->start - m1.adress) * (durfac/(float)sf) - lastactf0pos),(actf0pos-lastactf0pos)) ;
      	      fflush(errfile) ; } }
			p->dur = durfac ;
			midpoint = 4.0*(1.0-abs((float(islen/2+m1.adress)-p->start)/float(islen/2)))+1.0 ;
			if (ampfac < 10.0)
				p->amp = ampfac ;
			else
				p->amp = min(ampfac/ p->amp, midpoint) ;
			lastampfac = ampfac ;
			if (pl.advance() == -1)
				break ; }
		while (p->start < m2.adress) ;
		m1 = m2 ;
		lastactf0pos -= du1.value ;
		if (actf0nr < du1.f0nr)
			actf0 = du1.f0[du1.f0nr-1] ;

		if (nmkfile != NULL) {
			fprintf(nmkfile,"%8ld %s\n",actms * (long)sf, du1.name) ;
			actms += du1.value ; }

		du1 = du2 ;
		du2 = durl.exclude_and_advance_and_get() ;


		if (m1.adress > end)
			break ; }
	if (lookahead == 2) {
		durl.get(fallbackindex) ;
		ml.get(fallback) ; }
	return(1) ; }



void Duration::reset() {
	durl.reset() ;
	while (durl.exclude_and_advance_and_get().type != 'x') ; }



