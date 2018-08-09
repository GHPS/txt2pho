
#include "lisatalk.h"

#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif

extern short bt2(short) ;
extern long bt4(long) ;

void syndata_error(char* origin, char* message, int level) {
	if (level > 100) return ;
	fprintf(errfile,"Error during syndata handling (%s) : %s\n",origin,message) ;
	switch (level) {
		case 0:
		case 1: exit(1) ; } }

Periodlist::Periodlist(FILE* pmfile, long start, int number) {

	errorvalue.start = -1 ;
	errorvalue.voiced = error ;
	errorvalue.amp = 0.0 ;
	errorvalue.length = 0 ;

   	char dummy[8] ;

	Periodinfo inf ;
	long laststart=-1 ;
	fseek(pmfile,start,SEEK_SET) ;
	int nr = 0 ;
	while (nr++ < number) {
		if (feof(pmfile)) {
			syndata_error("Periodlist_constructor","end of file",2) ;
			break ; }
		fread(dummy,1,8,pmfile) ;
#ifdef SUN
		inf.start = bt4(*(long*)(&dummy[0])) ;
		inf.voiced = (excitation)(bt2(*(short*)(&dummy[4]))) ;
		inf.amp = bt2(*(short*)(&dummy[6])) ;
//		fprintf(errfile,"SUN defined in syndata.cc\n") ;
#else
		inf.start = *(long*)(&dummy[0]) ;
		inf.voiced = (excitation)(*(short*)(&dummy[4])) ;
		inf.amp = *(short*)(&dummy[6]) ;
#endif
		inf.dur = 1.0 ;
		inf.deletable = 0 ;
		inf.interpolate = 0 ;
      if (laststart != inf.start)
			append(inf) ;
      laststart = inf.start ; }
	reset() ;
	laststart = act->i.start ;
	while (act->after != NULL) {
		act=act->after ;
		act->before->i.length = (int)(act->i.start-laststart) ;
      if (act->before->i.length < 40) {
         act->i.start -= act->before->i.length ;
         act->before->i.length = 0 ; }
		act->before->i.f0 = act->before->i.length ;
		laststart = act->i.start ; }
	act->i.length = 0 ;
	reset() ;

   for (int j = 1 ; j < length() ; j++) {
   	inf = get(j) ;
      if (inf.length == 0) {
      	exclude(j) ;
         j-- ; } }



   reset() ; }

Periodlist::~Periodlist() { ; }

Periodlist::Periodlist() {
	errorvalue.start = -1 ;
	errorvalue.voiced = error ;
	errorvalue.amp = 0.0 ;
	errorvalue.length = 0 ; }

int Periodlist::conc(Periodinfo i) { return(append(i)) ; }

int Periodlist::write(FILE* pmfile) {
 	reset() ;
	char dummy[8] ;
	Periodinfo i ;
	int counter = 0 ;
	short d ;
	while ((i = get_and_advance()).voiced != errorvalue.voiced) {
	  counter++ ;
	  memcpy(dummy,&i.start,4) ;
	   d = (short) i.voiced ;
	   memcpy(&dummy[4],&d,2) ;
	   d = (short)i.amp ;
	   memcpy(&dummy[6],&d,2) ; }
	return(counter) ; }
 

void Periodlist::print(FILE* ascoutfil) {
	reset() ;
	Periodinfo i ;
	while ((i = get_and_advance()).voiced != errorvalue.voiced) {
		fprintf(ascoutfil,"%8ld %4d %4d %8.4f %8.4f %1d %1d %3d\n",i.start,i.length,i.f0,i.amp,i.dur,(int)i.voiced,(int)i.deletable,(int)i.interpolate) ; } }

long Periodlist::input(FILE* ascinfil, long pos) {
	Periodinfo i ;
	char buffer[80] ;
	int firstone = 1 ;
	fseek(ascinfil,pos,SEEK_SET) ;
	while (fgets(buffer,79,ascinfil) != NULL) {
		i.start = atol(buffer) ;
		if (firstone == 0 && i.start == 0L)
			break ;
		firstone = 0 ;
		pos = ftell(ascinfil) ;
		i.length = atol(&buffer[8]) ;
		i.f0 = (short)atof(&buffer[14]) ;
		i.amp = atof(&buffer[23]) ;
		i.dur = atof(&buffer[32]) ;
		i.voiced = (excitation)atoi(&buffer[41]) ;
		i.deletable = atoi(&buffer[43]) ;
		i.interpolate = atoi(&buffer[45]) ;
		append(i) ; }
	 return(pos) ; }


Periodinfo Periodlist::get_period_next_to(long sample) {
	if (sample < 0L)
		return(errorvalue) ;
	Periodinfo inf2,inf1 = errorvalue ;
	inf1 = get() ;
	if (inf1.voiced == errorvalue.voiced) {
		reset() ;
		inf1 = get() ; }
	inf2 = inf1 ;
	do {
		if (inf1.start < sample) {
			if (advance() == -1)
				break ;
			inf2 = inf1 ;
			inf1 = get() ; }
		if (inf2.start > sample) {
			if (decrease() == -1)
				break ;
			inf1 = inf2 ;
			inf2 = get() ; } }
	while (inf1.start < sample || inf2.start > sample) ;
	if ((sample-inf2.start > inf1.start-sample) || (inf2.voiced == errorvalue.voiced))  {
		return(inf1) ; }
	else {
		return(inf2) ; } }

Periodinfo Periodlist::get_period_next_to_with_offset(long sample, int offset) {
	if (sample < 0L)
		return(errorvalue) ;
	get_period_next_to(sample) ;
	return(get(get_number()+offset)) ; }

double Periodlist::get_dB(long position) {
	double rms = get_period_next_to(position).amp ;
	if (rms == 0.0)
		return(rms) ;
	return(20.0 * log10(rms)) ; }

double Periodlist::get_max_dB() {
	reset() ;
	double rms = 0.0 ;
	Periodinfo inf ;
	do {
		inf = get_and_advance() ;
		if (inf.amp > rms)
			rms = inf.amp ; }
	while (inf.voiced != errorvalue.voiced) ;
	if (rms == 0.0)
		return(rms) ;
	return(20.0 * log10(rms)) ; }

Periodinfo* Periodlist::get_period_pointer() {
	return(&(act->i)) ; }



Marklist::Marklist(FILE* markerfile, long start, int number) {

	errorvalue.adress = -1 ;
	char dummy[14] ;
	char dummy4[4] ;

	Markerinfo inf ;
	fseek(markerfile,start,SEEK_SET) ;
	int nr = 0 ;
	while (nr++ < number) {
		if (feof(markerfile)) {
			syndata_error("Markerlist_constructor","end of file",2) ;
			break ; }
		fread(dummy,1,14,markerfile) ;
		memcpy(inf.key,&dummy[4],10) ;
		memcpy(dummy4,dummy,4) ;
#ifdef SUN
		inf.adress = bt4(*(long*)(dummy4)) ;

#else
		inf.adress = *(long*)(dummy4) ;	
#endif

//		inf.key = new char[strlen(inrec.text)+1] ;
//		nulltest(inf.key) ;
		append(inf) ; }
	reset() ; }

Marklist::~Marklist() {
	reset() ;
/*	while (act != NULL) {
		if (act->i.key != NULL)
			delete(act->i.key) ;
		 act = act->after ; }
 */  }

int Marklist::write(FILE* markerfile) {
 	reset() ;
	char dummy[14] ;
	Markerinfo i ;
	int counter = 0 ;
	while ((i = get_and_advance()).adress != errorvalue.adress) {
	  counter++ ;
	  memcpy(dummy,i.key,10) ;
	  memcpy(&dummy[10],&i.adress,4) ; }
	return(counter) ; }
 

Marklist::Marklist() {
	errorvalue.adress = -1 ; }

long Marklist::get_marker_adress(char* key) {
	Markerinfo inf ;
	reset() ;
	do {
		inf = get_and_advance() ;
		if (inf.adress == errorvalue.adress) {
			if (key[0] != '&' && key[0] != '\0') {
				fprintf(errfile,"%s ",key) ;
				syndata_error("Marklist_get_marker_adress","key not found",5) ; }
			return(inf.adress) ; } }
	while (strcmp(inf.key,key) != 0) ;
	return(inf.adress) ; }

long Marklist::get_marker_adress_after(char* key) {
	Markerinfo inf ;
	reset() ;
	do {
		inf = get_and_advance() ;
		if (inf.adress == errorvalue.adress) {
			if (key[0] != '&' && key[0] != '\0') {
				fprintf(errfile,"%s ",key) ;
				syndata_error("Marklist_get_marker_adress","key not found",5) ; }
			return(inf.adress) ; } }
	while (strcmp(inf.key,key) != 0) ;
	inf = get() ;
	return(inf.adress) ; }

int Marklist::conc(Markerinfo i) { return(append(i)) ; }

void Marklist::print(FILE* ascoutfil) {
	reset() ;
	Markerinfo i ;
	while ((i = get_and_advance()).adress != errorvalue.adress) {
		fprintf(ascoutfil,"%8ld %s\n",i.adress,i.key) ; } }

long Marklist::input(FILE* ascinfil,long pos) {
	Markerinfo i ;
	char buffer[80] ;
	int firstone = 1 ;
	int keylen ;
	fseek(ascinfil,pos,SEEK_SET) ;
	while (fgets(buffer,79,ascinfil) != NULL) {
		i.adress = atol(buffer) ;
		if (firstone == 0 && i.adress == 0L)
			break ;
		if (i.adress > 0)
			firstone = 0 ;
		pos = ftell(ascinfil) ;
		keylen = strlen(&buffer[9]) ;
//		i.key = new char[keylen] ;
//		nulltest(i.key) ;
		strncpy(i.key,&buffer[9],keylen-1) ;
		i.key[keylen-1] = '\0' ;
		append(i) ; }
	return(pos) ; }

Markerinfo* Marklist::get_marker_pointer() {
	return(&(act->i)) ; }



