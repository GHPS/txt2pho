



#include "lisatalk.h"
#if !defined(__PROSODY_H__)
#include "prosody.h"
#endif

#ifdef UNIX
extern char* strdup(char*) ;
#endif

#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

#include <string.h>


//#define DEBUG1

#ifndef NGIMMICKS
int tempo = 112 ;
float octave = 0.5 ;

void syndata_error(const char* origin, const char* message, int level) {
	if (level > 100) return ;
	fprintf(errfile,"Error during syndata handling (%s) : %s\n",origin,message) ;
	switch (level) {
		case 0:
		case 1: exit(1) ; } }



int get_notedur(int tempo, int note) {
	float noteval = 4.0/(float)note ;
	float bps = 60.0/float(tempo) ;
	return(int(noteval*bps*1000.0)) ; }

float get_noteval(char* note) {
	float result = 350 ;
	switch (note[0]) {
		case 'c':
			if (note[1] == 'i')
				result = 277.18 ;
			else
				result = 261.63 ;
			break ;
		case 'd':
			result = 293.67 ;
			break ;
		case 'e':
			if (note[1] == 's')
				result = 311.13 ;
			else
				result = 329,63 ;
			break ;
		case 'f':
			if (note[1] == 'i')
				result = 349.23 ;
			else
				result = 369.99 ;
			break ;
		case 'g':
			result = 392.00 ;
			break ;
		case 'a':
			if (note[1] == 's')
				result = 415.31 ;
			else
				result = 440.0 ;
			break ;
		case 'b':
			result = 466.16 ;
			break ;
		case 'h' :
			result = 493.88 ;
			break ; }
	if (note[1] == '\'' || note[2] == '\'' || note[3] == '\'')
   	result *= 2 ;
	return(result) ; }

#endif

float get_predur(Syllableinfo& syll, Soundlist* soli) {
	Soundinfo s ;
	float bisher = 0 ;
	int i ;
	for (i=0 ; i < syll.soundnr; i++) {
	s = soli->get(syll.firstsound + i) ;
		if (strchr("aeiouy29EIOUY=@",s.name[0]) != NULL)
			return(bisher) ;
		bisher += s.duration ; }
	return(bisher) ; }

float get_postdur(Syllableinfo& syll, Soundlist* soli) {
	Soundinfo s ;
	float bisher = 0 ;
	int noch_onset = 1 ;
	int i ;
	for (i=0 ; i < syll.soundnr; i++) {
		s = soli->get(syll.firstsound + i) ;
	  if (strchr("aeiouy29EIOUY=@",s.name[0]) != NULL)
			noch_onset = 0 ;
		if (noch_onset == 0)
		  bisher += s.duration ; }
	return(bisher) ; }

float get_tl(Syllableinfo& syll, Soundlist* soli,float tlval) {
	Soundinfo s ;
	int i ;
	for (i=0 ; i < syll.soundnr; i++) {
		s = soli->get(syll.firstsound + i) ;
		if (strchr("aeiouy29EIOUY=@",s.name[0]) != NULL)
			return((float)s.duration) ; }
	return(tlval) ; }

float get_tr(Syllableinfo& syll, Soundlist* soli, float trval) {
	Soundinfo s ;
	float zeit = 0.0 ;
	int i ;
	for (i=0 ; i < syll.soundnr; i++) {
		s = soli->get(syll.firstsound + i) ;
		if (strchr("aeiouy29EIOUY=@",s.name[0]) != NULL)
			break ; }
	while (strcmp((s=soli->get(syll.firstsound+(++i))).name,"pau") != 0)
		zeit += s.duration ;


	return(zeit*trval) ; }

Intensity_Control::Intensity_Control(const char* intname, const char* intpath) {
	char fnam[512] ;
	int i,j ;


	strcat(strcat(strcpy(fnam,intpath),intname),".amp") ;
	FILE* drmfil = FOPEN(fnam,"r") ;
	intensity_values = NULL ;
	soundnr = 0 ;
	sounds = NULL ;
	if (drmfil == NULL) {
		syndata_error("Intensity_Control","modelfile not found",2) ;
		return ; }
	char buffer[81] ;

	// initialize class variables
	fgets(buffer,80,drmfil) ;
	soundnr = atoi(buffer) ;
	intensity_values = new int[soundnr] ;
	sounds = new char*[soundnr] ;
	fgets(buffer,80,drmfil) ;
	db_decrease = atof(buffer) ;
//    fprintf(errfile,"%f\n",db_decrease) ;
	for (j = 0 ; j < soundnr ; j++) {
		fgets(buffer,80,drmfil) ;
		sounds[j] = new char[4] ;
		if (strlen(buffer) < 5)
			break ;
		for (i=0 ; i < 4 ; i++)
			if (isspace(buffer[i])) {
				sounds[j][i] = '\0' ;
				break ; }
			else
				sounds[j][i] = buffer[i] ;
		intensity_values [j] = (int)atof(&buffer[8]) ; }

	// close parameter file
	FCLOSE(drmfil) ; }

Intensity_Control::~Intensity_Control() {
	if (intensity_values != NULL)
		delete[](intensity_values) ;
	if (sounds != NULL) {
   	for (int i = 0 ; i < soundnr ; i++)
      	delete[] (sounds[i]) ;
		delete[](sounds) ; } }

int Intensity_Control::compute_intensities( Soundlist* s) {
	Soundinfo* x ;
	s->reset() ;
	int i = 1,j=0 ;
	int accent ;
	int soundcount = 0, actsoundnr = 0 ;

	float posfac = 4.0 ;
   float db_decrease = 4.0 ;
	s->reset() ;
	do {
		x = s->get_sound_pointer(i++) ;
		if (s->advance() < 1 )
			break ;
		soundcount++ ; }
	while (1) ;

	i = 1 ;
	do {
		x = s->get_sound_pointer(i++) ;
		if (s->advance() < 1)
			break ;
		if (strcmp(x->name,"pau") == 0)
			continue ;
		accent = x->intensity ;
		x->intensity = -2 ;
		x->intensity -= int((float(31-accent) / 31.0)*db_decrease) ;
		x->intensity -= int(posfac * ((float)actsoundnr++ / float(soundcount))) ;
		if (j == soundnr)
			x->intensity = 1 ; }
	while (1) ;

	return(1) ; }



Duration_Model::D_Soundlist::D_Soundlist() {
	errorvalue.name[0] = '-' ;
	errorvalue.logmean = -1 ;
	errorvalue.logsd = -1 ; }

Duration_Model::D_Soundlist::~D_Soundlist() { ; }

int Duration_Model::D_Soundlist::conc(D_Sound i) {
	return(append(i)) ; }

D_Sound Duration_Model::D_Soundlist::find_sound(char* s) {
	reset() ;
	D_Sound i ;
	while ((i = get_and_advance()).logmean != errorvalue.logmean)
		if (strcmp(i.name,s) == 0)
			return(i) ;
	fprintf(errfile,"%s -- ",s) ;
	syndata_error("D_Soundlist::find_sound","Sound not found",5) ;
	return(errorvalue) ; }

Duration_Model::Duration_Model(char* drmfilnam, char* drmfilpath, int build_word_list) {

	char fnam[512] ;
	int i ;
	D_Sound s ;
	wordlist = NULL ;
	wordnr = 0 ;
	lastwordnr = 0 ;
	lastwordlist = NULL ;
	actdur = 0.0 ;
	actword = 0 ;
	bwl = build_word_list ;

	strcat(strcat(strcpy(fnam,drmfilpath),drmfilnam),".dur") ;
	fprintf(errfile,"%s %s %s\n",drmfilpath,drmfilnam,fnam) ;
	FILE* drmfil = FOPEN(fnam,"r") ;
	if (drmfil == NULL) {
		syndata_error("Duration_Model","modelfile not found",2) ;
		return ; }
	char buffer[81] ;
	varia = 1.0 ;

	// initialize class variables
	fgets(buffer,80,drmfil) ;
	speechrate = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	plosfac = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	sonrfac = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	finalfac = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	acatfac = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	acatplus = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	divisor = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	summand = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	diphthongfac = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	kvfac = atof(buffer) ;
	while (fgets(buffer,80,drmfil) != NULL) {
		if (strlen(buffer) < 10)
			break ;
		for (i=0 ; i < 4 ; i++)
			if (isspace(buffer[i])) {
				s.name[i] = '\0' ;
				break ; }
			else
				s.name[i] = buffer[i] ;
		sscanf(&buffer[i],"%f %f",&(s.logmean),&(s.logsd)) ;
//		s.logmean = atof(&buffer[8]) ;
//		s.logsd = atof(&buffer[17]) ;
		dsl.conc(s) ; }

	// close parameter file
	FCLOSE(drmfil) ; }

Duration_Model::~Duration_Model() {
	if (wordlist != NULL)
		free(wordlist) ; }

void Duration_Model::change_speech_rate(float offset) {
	speechrate += offset ;
	if (speechrate < 0.5 || speechrate > 5.0)
		speechrate -= offset ; }

long Duration_Model::get_total_length() {
	return(total_length) ; }

void Duration_Model::set_speech_rate(float rate) {
	speechrate = rate ;
	if (speechrate < 0.5 || speechrate > 5.0)
		speechrate = 1.0 ; }

float Duration_Model::get_speech_rate() {
	return(speechrate) ; }

void Duration_Model::set_accentlength(float rate) {
	acatfac = rate ;
	if (acatfac < 0.0 || acatfac > 25.0)
		acatfac = 1.0 ; }

float Duration_Model::get_accentlength() {
	return(acatfac) ; }

void Duration_Model::set_final_lengthening(float rate) {
	finalfac = rate ;
	if (finalfac < 0.0 || finalfac > 2.5)
		finalfac = 1.0 ; }

float Duration_Model::get_final_lengthening() {
	return(finalfac) ; }

void Duration_Model::set_speech_rate_range(float rate) {
	varia = rate ;
	if (varia < 0.0 || varia > 2.0)
		varia = 1.0 ; }

float Duration_Model::get_speech_rate_range() {
	return(varia) ; }

int Duration_Model::get_word_index(long ms) {
	int result ;
	for (result = 0; result < lastwordnr ; result++)
		if (lastwordlist[result] > ms)
			break ;
	return(result-1) ; }

long* Duration_Model::get_word_list(long* wpl) {
	long* result = NULL ;
	if (wpl != NULL) {
		wpl[0] = long(wordnr) ;
		for (int i=0 ; i < wordnr ; i++) {
			wpl[i+1] = wordlist[i] ; }
	   prepare_for_last_sentence () ;
   	return(NULL) ; }
	result = new long[wordnr+1] ;
	if (result == NULL)
		return(result) ;
	result[0] = long(wordnr) ;
	for (int i=0 ; i < wordnr ; i++) {
		result[i+1] = wordlist[i] ; }
   prepare_for_last_sentence () ;
	return(result) ; }

float Duration_Model::sildur(float k,D_Soundlist* syll, int lautzahl) {
	float sd = 0.0 ;
	syll->reset() ;
	D_Sound s ;
	while ((s = syll->get_and_advance()).logmean != -1) {
		if (s.logmean <= 0.0001)
			continue ;
		sd += exp(s.logmean + k*s.logsd) ; }
	return(sd) ; }


float Duration_Model::fit(D_Soundlist* syll,int lautzahl,float sd,int phraspos){
	if (lautzahl == 0)
		return(0) ;
	float k[3] = {0.0,0.0,0.0} ;
	float erg[3] ;
	float deltak = 1.0 ;
	int i ;
	float minf ;
	int mini ;
	do{
		k[1] = k[0]-deltak ;
		k[2] = k[0]+deltak ;
		minf = 1.0E10 ;
		mini = 0 ;
		for (i=0 ; i < 3 ; i++) {
			erg[i] = pow(sildur(k[i],syll,lautzahl) - sd,2) ;
			if (minf > erg[i]) {
				minf = erg[i] ;
				mini = i ; } }
		if (mini == 0)
			deltak /= 4.0 ;
		k[0] = k[mini] ; }
	while (deltak > 0.01) ;
	return(k[0]) ; }


void Duration_Model::compute_syllable_duration(Syllableinfo syll, int phraspos, int accent, Soundlist* soli, float& actdur, int plosivdur, int solldur = 0) {
	Soundinfo* s ;
	D_Soundlist* this_dsl = new D_Soundlist;
	nulltest(this_dsl) ;
//   fprintf(errfile,"DUCOMP FOR %s\n",syll.name) ;
//   fflush(errfile) ;
	D_Sound ds,dsn ;
	int i,j;
	int plosiv = 0 ;
	float sd,k ;
	for (i=0 ; i < syll.soundnr ; i++) {
		s = soli->get_sound_pointer(syll.firstsound+i) ;
//      fprintf(errfile,"LOOKING FOR SOUND %s\n",s->name) ;
//      fflush(errfile) ;
		ds = dsl.find_sound(s->name) ;
		if (ds.logmean > 0) {
			for (j=-1 ; ++j < 4 ; dsn.name[j] = ds.name[j]) ;
			if (plosivdur == 0) {
				if (strchr("ptkbdg_",dsn.name[0]) != NULL ) {
					plosiv += 2 ;
					i++ ;
					continue ; }
				if (dsn.name[0] == '?') {
					plosiv++ ;
					continue ; } }
			dsn.logmean = ds.logmean ;
			dsn.logsd = ds.logsd ;
			this_dsl->conc(dsn) ; } }

	sd = ((syll.soundnr-plosiv)/sonrfac) ;
	sd = sd * (finalfac*phraspos+1) ;
	if (accent < 0)
		accent = 0 ;
	sd = sd *(acatfac * accent + acatplus) ;
	sd = sd /divisor+summand ;
   sd = sd * 1.2 ;
	sd = sd * speechrate ;
	if (solldur > 0)
		sd = solldur*speechrate*1.2 ;  // - (plosiv*35) ???
	k = fit(this_dsl,syll.soundnr-plosiv,sd,phraspos) ;

	this_dsl->reset() ;
	for (i=0 ; i < syll.soundnr ; i++) {
		s = soli->get_sound_pointer(syll.firstsound+i) ;
		ds = dsl.find_sound(s->name) ;
		if (ds.logmean < 0) {
			s->duration = 50 ; }
		else
		if (plosivdur == 0 && strchr("ptkb_dg?",s->name[0]) != NULL) {
			ds = dsl.find_sound(s->name) ;
			s->duration = (int)exp(ds.logmean) ;
			if (soli->get_last_sound().name[0] == 'n' && strchr("td",s->name[1]) != 0)
				s->duration = 5 ;
			if (soli->get_last_sound().name[0] == 'm' && strchr("pb",s->name[1]) != 0)
				s->duration = 10 ;
			if (soli->get_last_sound().name[0] == 'N' && strchr("kg",s->name[1]) != 0)
				s->duration = 10 ; }
		else {
			ds = this_dsl->get_and_advance() ;
			s->duration = (int)exp(ds.logmean + k * ds.logsd) ; }
		actdur += s->duration ; }
	delete(this_dsl) ; }



int Duration_Model::prepare_for_last_sentence() {
	actdur = 0.0 ;
   actword = 0 ;
	if (lastwordlist != NULL)
		delete(lastwordlist) ;
	lastwordlist = NULL ;
	lastwordnr = wordnr ;
	if (wordlist != NULL) {
		lastwordlist = wordlist ;
		wordlist = NULL ; }
	wordnr = 0 ;
	return(1) ; }

int Duration_Model::compute_duration(Syllablelist& syll, Soundlist* soli, FILE* nnfile, long start, Proslist* p, int use_net, PhonNetz* phondurnet, DBSyllist* dbs) {


if (debuglevel > 0) {
  fprintf(errfile,"SPEECHRATE: %f\n",speechrate) ;
  fflush(errfile) ;
}



	int treesyldur=0 ;
	int phraspos = 0 ;
	float solldur ;
	int i ;
	char* help ;
	int singingdur[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
	int singingdurcnt = 0 ;
	int focus = 0 ;
	char buffer[300] ;
   float lastactdur = actdur ;


	Syllableinfo s,svor,snach,snach2 ;
	Soundinfo* sn ;

/*	if (lastwordlist != NULL)
		delete(lastwordlist) ;
	lastwordlist = NULL ;
	lastwordnr = wordnr ;
	if (wordlist != NULL) {
		lastwordlist = wordlist ;
		wordlist = NULL ; }
	wordnr = 0 ;
*/
	if (nnfile != NULL)
		fseek(nnfile,start,SEEK_SET) ;

	if (p != NULL)
        	p->reset() ;


if (debuglevel > 0) {
	fprintf(errfile,"USE_NET: %d\n",use_net) ;
	fflush(errfile) ;
}
	if (use_net > 0 && strcmp(syll.get().type,"PGR") == 0) {
		phondurnet->compute(&syll,soli,dbs, speechrate,use_net) ;
if (debuglevel > 0) {
		fprintf(errfile,"PhonNet durations computed\n") ;
      fflush(errfile) ;
}
 }




	syll.reset() ;
	if (bwl) {
	while ((s = syll.get_and_advance()).accent != -1) {
		if (s.wordstart == 1)
			wordnr++ ;
			}
	wordlist = (long*)realloc(wordlist,wordnr*sizeof(long)) ;
	if (wordlist == NULL)
	  syndata_error("Wordlist","out of heap",0) ; }
	syll.reset() ;
	svor = syll.get_and_advance() ;
#ifdef BORDERPROS
	if (strcmp(svor.type,"PGR") == 0 && svor.accent < 21) {
		sn = soli->get_sound_pointer(s.firstsound) ;
		if (p != NULL) {
			sn->duration = (int)(p->get_and_advance()).syldur ;
			if (sn->duration < 5)
				sn->duration = 5 ; }
		else
		if (nnfile != NULL) {
			fgets(buffer,299,nnfile) ;
			sn->duration = (int)atof(buffer) ;
			if (sn->duration < 5)
				sn->duration = 5 ; }
		else
			sn->duration = svor.accent * 40 ; }
#endif
	if (strcmp(svor.type,"SIL") != 0) {
		actdur += svor.accent ;
		s = syll.get_and_advance() ; }
	else {
   	s = svor ; }
	snach = syll.get_and_advance() ;
//	actword = 0 ;
   int plosivdur = 1 ;
	while ((snach2 = syll.get_and_advance()).accent != -1) {
		if (bwl && s.wordstart == 1)
			wordlist[actword++] = (long)actdur ;
		if (strcmp(s.type,"COM") == 0 && strncmp(s.name,"{Duration:",10) == 0) {
			speechrate += atof(&(s.name)[10]) ; }
		if (strcmp(s.type,"COM") == 0 && strncmp(s.name,"{Plosivdur:",11) == 0) {
			plosivdur = atoi(&(s.name)[11]) ; }

//	fprintf(errfile,"%s Computing\n",s.name) ;
   fflush(errfile) ;

#ifndef NGIMMICKS
		if (strcmp(s.type,"COM") == 0 && strncmp(s.name,"{SetSingingTempo:",17) == 0) {
			if (strncmp(&(s.name)[17],"Largo",5) == 0)
				tempo = 42 ;
			if (strncmp(&(s.name)[17],"Larghetto",9) == 0)
				tempo = 60 ;
			if (strncmp(&(s.name)[17],"Adagio",6) == 0)
				tempo = 72 ;
			if (strncmp(&(s.name)[17],"Andante",7) == 0)
				tempo = 92 ;
			if (strncmp(&(s.name)[17],"Allegretto",10) == 0)
				tempo = 112 ;
			if (strncmp(&(s.name)[17],"Allegro",7) == 0)
				tempo = 140 ;
			if (strncmp(&(s.name)[17],"Presto",6) == 0)
				tempo = 180 ;
			if (atoi(&(s.name)[17]) != 0)
				tempo = atoi(&(s.name)[17]) ; }
		if (strcmp(s.type,"COM") == 0 && strncmp(s.name,"{Singing:",9) == 0) {
			help = &(s.name)[9] ;
			singingdurcnt = 0 ;
			i = -1 ;
			while (help[i] != '\0') {
				singingdur[singingdurcnt++] = get_notedur(tempo,atoi(&help[++i])) ; ;
				if (singingdurcnt > 19)
					break ;
				while (help[i] != ';' && help[i] != '\0')
					i++ ; }
			singingdurcnt = 0 ; }

#endif

		phraspos = 0 ;
		if (strcmp(s.type,"SIL") == 0) {
 
//		fprintf(errfile,"%s Syllable\n",s.type) ;
   	fflush(errfile) ;
			if (((strcmp(snach.type,"PGR") == 0) && (snach.accent > 0)) ||
				 (((strcmp(snach2.type,"PGR") == 0) && (snach2.accent > 0)) &&
				  ((strchr(snach.name,'@') != 0) || (strchr(snach.name,'=') != 0)))) {
				phraspos = 1;
				if (snach.accent > 300)
					phraspos = 2 ; }
			if (p != NULL)
			  treesyldur = (int)(p->get_and_advance()).syldur ;
			if (use_net == 0) {
			if (p != NULL)
				compute_syllable_duration(s,phraspos,s.accent-(focus),soli,actdur,plosivdur,treesyldur) ;
			else {
				if (nnfile != NULL) {
					fgets(buffer,299,nnfile) ;
					solldur = atof(buffer) ;
					compute_syllable_duration(s,phraspos,s.accent-(focus),soli,actdur,plosivdur,(int)solldur) ; }
				else
				  compute_syllable_duration(s,phraspos,s.accent-(s.accent<28?focus:0),soli,actdur,plosivdur,0) ; }}
			else {
			  for (i=s.firstsound ; i < s.firstsound+s.soundnr ; i++)
			    actdur += soli->get(i).duration ; }
			if  (singingdur[singingdurcnt] != 0)
				compute_syllable_duration(s,phraspos,s.accent,soli,actdur,plosivdur,singingdur[singingdurcnt++]) ; }
		else
#ifdef BORDERPROS
			// Berechnung der Pausendauer in Abhaengigkeit von der Prominenz

//	fprintf(errfile,"Border Computing\n",s.type) ;
   fflush(errfile) ;
			if (strcmp(s.type,"PGR") == 0 && s.accent < 21) {
				sn = soli->get_sound_pointer(s.firstsound) ;
				if (p != NULL) {
					sn->duration = (int)(p->get_and_advance()).syldur ;
					if (sn->duration < 5)
						sn->duration = 5 ; }
				else
				if (nnfile != NULL) {
					fgets(buffer,299,nnfile) ;
					sn->duration = (int)atof(buffer) ;
					if (sn->duration < 5)
						sn->duration = 5 ; }
				else
					sn->duration = s.accent * 40 ; }
#endif
			actdur += s.accent ;
		svor = s ;
		s = snach ;
		snach = snach2 ; }
	if (bwl && s.wordstart == 1)
		wordlist[actword++] = (long)actdur ;

//	fprintf(errfile,"Ende %s Computing\n",s.name) ;
   fflush(errfile) ;

	if (strcmp(s.type,"SIL") == 0) {
			if (((strcmp(snach.type,"PGR") == 0) && (snach.accent > 0)) ||
				 (((strcmp(snach2.type,"PGR") == 0) && (snach2.accent > 0)) &&
				  ((strchr(snach.name,'@') != 0) || (strchr(snach.name,'=') != 0)))) {
				phraspos = 1;
				if (snach.accent > 300)
					phraspos = 2 ; }
			if (p != NULL)
			  treesyldur = (int)(p->get_and_advance()).syldur ;
			if (use_net ==0) {
			if (p != NULL)
				compute_syllable_duration(s,phraspos,s.accent-(focus),soli,actdur,plosivdur,treesyldur) ;
			else {
				if (nnfile != NULL) {
					fgets(buffer,299,nnfile) ;
					solldur = atof(buffer) ;
					compute_syllable_duration(s,phraspos,s.accent-(focus),soli,actdur,plosivdur,(int)solldur) ; }
				else
				  compute_syllable_duration(s,phraspos,s.accent-focus,soli,actdur,plosivdur,0) ; }}
			else {
			  for (i=s.firstsound ; i < s.firstsound+s.soundnr ; i++)
			    actdur += soli->get(i).duration ; }
		if  (singingdur[singingdurcnt] != 0) {
			compute_syllable_duration(s,phraspos,s.accent,soli,actdur,plosivdur,singingdur[singingdurcnt]) ;
			singingdur[singingdurcnt++] = 0 ; } }
#ifdef BORDERPROS
	if (strcmp(snach.type,"PGR") == 0 && snach.accent < 21) {
		sn = soli->get_sound_pointer((int)snach.firstsound) ;
		if (p != NULL) {
			sn->duration = (int)(p->get_and_advance()).syldur ;
			if (sn->duration < 5)
				sn->duration = 5 ; }
		else
		if (nnfile != NULL) {
			fgets(buffer,299,nnfile) ;
			sn->duration = (int)atof(buffer) ;
			if (sn->duration < 5)
				sn->duration = 5 ; }
		else
			sn->duration = snach.accent * 40 ; }
#endif

//	fprintf(errfile,"Returning\n",s.name) ;
   fflush(errfile) ;

	actdur += snach.accent ;
	total_length = (long)(actdur-lastactdur) ;
	return(1) ; }

int Proslist::conc(Prosinfo i) {
	return(append(i)) ; }

Proslist::Proslist() {
	errorvalue.syldur = -1.0 ; }

int Proslist::print(FILE* listfile) {
	reset() ;
	Prosinfo pr ;
	while ((pr = get_and_advance()).syldur != errorvalue.syldur) {
		fprintf(listfile,"%8f %8f %8f %8f %8f\n",pr.syldur,pr.delay,pr.ampli,pr.betali,pr.betare) ; }
	return(0) ; }

int Intonation_Model::I_Commandlist::conc(I_Command i) {
	return(append(i)) ; }

Intonation_Model::I_Commandlist::I_Commandlist() {
	errorvalue.t0 = -1 ; }

I_Command* Intonation_Model::I_Commandlist::get_i_command_pointer(int index) {
	get(index) ;
	return(&(act->i)) ; }


Intonation_Model::Intonation_Model(char* infilnam, char* infilpath) {
	char fnam[512] ;
	char buffer[81] ;
	strcat(strcat(strcpy(fnam,infilpath),infilnam),".int") ;


	FILE* drmfil = FOPEN(fnam,"r") ;
	if (drmfil == NULL) {
				syndata_error("Intonation_Model","modelfile not found",2) ;
            return ; }

	// initialize class variables
	fgets(buffer,80,drmfil) ;
	toplinestart = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	toplineend = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	baselinestart = atof(buffer) ;
	fgets(buffer,80,drmfil) ;
	baselineend = atof(buffer) ;
	FCLOSE(drmfil) ; }

Intonation_Model::~Intonation_Model() { ; }

float Intonation_Model::get_pitch() {
	return(baselinestart) ; }

int Intonation_Model::set_pitch(float value)  {
	float diff = baselinestart - value ;
	baselinestart -= diff ;
	baselinestart = max(baselinestart,50) ;
	baselinestart = min(baselinestart,400) ;
	baselineend -= diff ;
	baselineend = max(baselineend,50) ;
	baselineend = min(baselineend,400) ;
	toplinestart -= diff ;
	toplinestart = max(toplinestart,50) ;
	toplinestart = min(toplinestart,500) ;
	toplineend -= diff ;
	toplineend = max(toplineend,50) ;
	toplineend = min(toplineend,500) ;
	return(1) ; }

float Intonation_Model::get_pitchrange() {
	return(toplinestart - baselinestart) ; }

int Intonation_Model::set_pitchrange(float value)  {
	toplinestart = baselinestart + value ;
	toplinestart = max(toplinestart,50) ;
	toplinestart = min(toplinestart,500) ;
	toplineend = baselineend + value ;
	toplineend = max(toplineend,50) ;
	toplineend = min(toplineend,500) ;
	return(1) ; }

float Intonation_Model::get_declination() {
	return(baselinestart - baselineend) ; }

int Intonation_Model::set_declination(float value)  {
	toplineend = toplinestart - value ;
	toplineend = max(toplineend,50) ;
	toplineend = min(toplineend,500) ;
	baselineend = baselinestart - value ;
	baselineend = max(baselineend,50) ;
	baselineend = min(baselineend,400) ;
	return(1) ; }

void Intonation_Model::clear() {
	dsl.clear() ; }

#define bottom(s) (baselineend+float(baselinestart-baselineend)*(float(totalms-(s))/float(totalms)))
#define top(s) (toplineend+float(toplinestart-toplineend)*(float(totalms-(s))/float(totalms)))

float Intonation_Model::compute_f0_value(long sample, long totalms) {

	float bval = bottom(sample) ;
	float lval,rval,pos,negrval=0.0 ;
	I_Command a ;
	int negval=-1 ;


	// look through all accents, add value of accent command
	dsl.reset() ;
	while ((a=dsl.get()).t0 != -1) {
		if (a.t0 == -999 && (long)a.delay < sample) {
			f0changeval += (int)a.amplitude ;
			dsl.get_i_command_pointer(dsl.get_number())->amplitude = 0.0 ; }
		if (a.t0 == -1000 && (long)a.delay < sample) {
			sollf0 = (int)a.amplitude ; }
		if (a.t0 > -999 && sample < a.t0+a.delay) break ;
		if (dsl.advance() == -1) {
			a.t0 = -1 ;
			break ; } }
	if (sollf0 > 0)
		return(sollf0) ;
	if (a.t0 == -1) {
		a = dsl.get() ;
//		fprintf(errfile,"computing lval by %ld %f %ld\n",a.t0,a.amplitude,a.delay) ;
		lval = bval ;
		pos = float(sample-(a.t0+a.delay))*a.betare ;
		if (pos < 3.14/2.0 && pos > -3.14/2.0)
			lval += 0.5*pow(cos(pos),2) * (top(a.t0+a.delay)-bottom(a.t0+a.delay))*a.amplitude ;
		rval = 0 ; }
	else {
		rval = bval ;
		pos = float(sample-(a.t0+a.delay))*a.betali ;
//		fprintf(errfile,"computing rval by %ld %f %ld\n",a.t0,a.amplitude,a.delay) ;
		if (pos < 3.14/2.0 && pos > -3.14/2.0) {
			negrval = 0.5*pow(cos(pos),2) * (top(a.t0+a.delay)-bottom(a.t0+a.delay))*a.amplitude ;
			if (a.amplitude < 0.0)
				negval = 1;
			else
				negval = -1 ;
			rval += negrval*(float)(-negval) ; } ;
			
		if (dsl.decrease() > -1) {
			a = dsl.get() ;
//			fprintf(errfile,"computing lval by %ld %f %ld\n",a.t0,a.amplitude,a.delay) ;
			lval = bval ;
			pos = float(sample-(a.t0+a.delay))*a.betare ;
			if (pos < 3.14/2.0 && pos > -3.14/2.0)
				lval += 0.5*pow(cos(pos),2) * (top(a.t0+a.delay)-bottom(a.t0+a.delay))*a.amplitude ; }
		else
			lval = 0.0 ; }
//     fprintf(errfile,"lval %f rval %f bval %f\n",lval,rval,bval) ;
	if (negval == 1) {	
		rval = 0.0 ;
		lval += negrval ;
		bval += negrval ; }		
	if (lval > rval && lval > bval)
		return(lval+f0changeval) ;
	if (rval > bval) {
		return(rval+f0changeval) ; }
	return (bval+f0changeval) ; }

int Intonation_Model::compute_f0(Syllablelist& sy, Soundlist* soli, int modus, FILE* nnfile, long start, const char* pid, int onlystress, Proslist* p) {
	Syllableinfo syll ;
	Soundinfo* s ;
	I_Command i ;
	long actms = 0L ;
	long totalms ;
	long phrasedur = 0L ;
#ifndef NO_FILES
#ifdef UNIX
	char temp[90] ;
	char* intofilename = strcat(strcpy(temp,pid),"hadi.int") ;
#else
	char* intofilename = "hadi.int" ;
#endif
	FILE* intofile ;
#endif
	sy.reset() ;
	Prosinfo pr ;
	int accentnr_in_satz = 0 ; ;
	int accentnr_in_phrase = 0;
	int silbe = 0 ;
	int n ;
	char* help ;
	int singingdur[20] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0} ;
	int singingdurcnt = 0 ;
	int focus = 0 ;
	char buffer[300] ;

	if (p != NULL) {
if (debuglevel > 0) {
		fprintf(errfile,"\n\nReading prosody values from memory\n") ;
		fprintf(errfile,"Output Prosody Generation Module:\n\n") ;
		p->print(errfile) ;
		fflush(errfile) ;
}
		p->reset() ;
	}
	else
	if (nnfile != NULL) {
		fseek(nnfile, start, SEEK_SET) ;
if (debuglevel > 0) {
		fprintf(errfile,"reading prosody values from file\n") ;
		fflush(errfile) ;
}
		 }
	else
if (debuglevel > 0) {
		fprintf(errfile,"using default rules for prosody generation\n") ;
}
	f0changeval = 0 ;
	sollf0 = 0 ;
	sy.reset() ;
//	while ((syll = sy.get_and_advance()).accent != -1)
//		if (strcmp(syll.type,"SIL") == 0 && syll.accent > 28)
//			focus = 1 ;
	sy.reset() ;
	if (modus != 1) {


	  while ((syll = sy.get_and_advance()).accent != -1) {
		if (strcmp(syll.type,"PGR") == 0) {
			if (strcmp(syll.name,"SATZ") == 0) {
//				if (strcmp(syll.prosinfo,"1") == 0)
					accentnr_in_phrase = 0 ; }
			if (strcmp(syll.name,"PHRASE") == 0) {
//				if (strcmp(syll.prosinfo,"1") == 0)
					accentnr_in_phrase = 0 ; }
			if (syll.firstsound != -1) {
				phrasedur = (soli->get(syll.firstsound)).duration ;
				actms += (soli->get(syll.firstsound)).duration ; } }
		if (strcmp(syll.type,"COM") == 0 && strncmp(syll.name,"{Pitch:",7) == 0) {
			i.delay = (float) actms ;
			i.t0 = -999 ;
			i.amplitude = atof(&syll.name[7]) ;
			dsl.conc(i) ; }

#ifndef NGIMMICKS

		if (strcmp(syll.type,"COM") == 0 && strncmp(syll.name,"{SetOctave:",11) == 0) {
			if (strncmp(&(syll.name)[11],"C",1) == 0)
				octave = 0.25 ;
			if (strncmp(&(syll.name)[11],"c",1) == 0)
				octave = 0.5 ;
			if (strncmp(&(syll.name)[11],"c'",2) == 0)
				octave = 1.0 ;
			if (strncmp(&(syll.name)[11],"c''",3) == 0)
				octave = 2.0 ;
			if (strncmp(&(syll.name)[11],"c'''",4) == 0)
				octave = 4.0 ; }
		if (strcmp(syll.type,"COM") == 0 && strncmp(syll.name,"{Singing:",9) == 0) {
			help = &(syll.name)[9] ;
			singingdurcnt = 0 ;
			n = 0 ;
			while (help[n] != '\0') {
				if (help[n] == ',')
					singingdur[singingdurcnt++] = int(get_noteval(&help[++n])*octave) ;
				if (singingdurcnt > 19)
					break ;
				n++ ; }
			singingdurcnt = 0 ; }

#endif

		if (strcmp(syll.type,"SIL") == 0) {
			silbe++ ;
			actms += (long)get_predur(syll,soli) ;
			if (singingdur[singingdurcnt] != 0) {
				if (p != NULL)
					 pr = p->get_and_advance() ;
         	i.delay = (float) actms-get_predur(syll,soli) ;
				i.t0 = -1000 ;
				i.amplitude = singingdur[singingdurcnt] ;
            i.betali = 0.001 ;
            i.betare = 0.001 ;
				singingdur[singingdurcnt++] = 0 ;
				dsl.conc(i) ; }
			else
			if (singingdurcnt > 0) {
				if (p != NULL)
					 pr = p->get_and_advance() ;
				i.delay = (float) actms-get_predur(syll,soli) ;
				i.t0 = -1000 ;
				i.amplitude = 0 ;
            i.betali = 0.001 ;
            i.betare = 0.001 ;
				singingdurcnt = 0 ;
				dsl.conc(i) ; }
			else
			if (p != NULL) {
			 pr = p->get_and_advance() ;
//			 fprintf(errfile,"%8f %8f %s\n",pr.delay,pr.ampli,syll.prosinfo) ;
                         fflush(errfile) ;
			 if (strchr(".-",syll.prosinfo[0]) == NULL) {
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ;
				n = 0 ;
				i.t0 = actms ;
				i.delay = pr.delay ;
				i.amplitude = pr.ampli ;
				i.betali = pr.betali ;
				i.betare = pr.betare ;
				if (i.betali == 0.0)
					i.betali = 0.01 ;
				if (i.betare == 0.0)
					i.betare = 0.01 ;

//				fprintf(errfile,"%f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
				fflush(errfile) ;
#ifdef NEWTREE
				if (i.amplitude != 0) {
					i.betare = (i.betare * (3.14257/4.0) / i.amplitude) * 0.5 ;
					i.betali = (i.betali * (3.14257/4.0) / i.amplitude) * 0.5 ;
					i.amplitude = i.amplitude / 100.0 ; }
#endif
//				fprintf(errfile,"made to %f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
				fflush(errfile) ;
				dsl.conc(i) ; } }
			else
			if (nnfile != NULL) {
			 if (onlystress == 0)
				 fgets(buffer,299,nnfile) ;
			 if (strchr(".-",syll.prosinfo[0]) == NULL) {
				if (onlystress == 1)
					fgets(buffer,299,nnfile) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ;
				n = 0 ;
				if (onlystress == 0)
					while (!isspace(buffer[n]))
						n++ ;
				i.t0 = actms ;
				i.delay = atof(&buffer[n]) ;
				n += 2 ;
				while (!isspace(buffer[n]))
					n++ ;
				i.amplitude = atof(&buffer[n]) ;
				n += 2 ;
				while (!isspace(buffer[n]))
					n++ ;
				i.betali = atof(&buffer[n]) ;
				n += 2 ;
				while (!isspace(buffer[n]))
					n++ ;
				i.betare = atof(&buffer[n]) ;
				if (i.betali == 0.0)
					i.betali = 0.01 ;
				if (i.betare == 0.0)
					i.betare = 0.01 ;

//				fprintf(errfile,"%f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
				fflush(errfile) ;
#ifdef NEWTREE
				if (i.amplitude != 0) {
					i.betare = (i.betare * (3.14257/4.0) / i.amplitude) * 0.5 ;
					i.betali = (i.betali * (3.14257/4.0) / i.amplitude) * 0.5 ;
					i.amplitude = i.amplitude / 100.0 ; }
#endif
//				fprintf(errfile,"made to %f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
				fflush(errfile) ;
				dsl.conc(i) ; } }
			else
			if (strcmp(syll.prosinfo,"H") == 0) {
				i.t0 = actms ;
				if (focus == 1 && syll.accent < 28)
					syll.accent -=15 ;
				i.amplitude = 0.02*syll.accent ; // - (0.03 * accentnr_in_phrase) ;
				i.delay = 100+syll.accent ;
				if (silbe == 1)
					i.delay = 160+syll.accent ;
				if (silbe == 2)
					i.delay = 110+syll.accent ;
				i.betali = 0.0003*syll.accent ;
				if (accentnr_in_phrase == 0)
					i.betali = 0.006-0.001*(max(4-silbe,4)) ;
				i.betare = 0.0002*syll.accent ;
				dsl.conc(i) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ; }
			else
			if (strcmp(syll.prosinfo,"N") == 0) {
				i.t0 = actms ;
				i.amplitude = 0.38 ; //- (0.03 * accentnr_in_phrase) ;
				i.delay = 60 ;
				if (silbe == 1)
					i.delay = 160 ;
				if (silbe == 2)
					i.delay = 110 ;
				i.betali = 0.0015 ;
				if (accentnr_in_phrase == 0)
					i.betali = 0.006-0.001*max(4-silbe,4) ;
				i.betare = 0.001 ;
				dsl.conc(i) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ; }
			else
			if (strcmp(syll.prosinfo,"FHe") == 0) {
				i.t0 = actms ;
				i.amplitude = 0.8 ;
				i.delay = 100 * (sy.distance_to_pgr()+1) ;
				i.betali = 0.003 ;
				i.betare = 0.0000001 ;
				dsl.conc(i) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ; }
			else
			if (strcmp(syll.prosinfo,"EHe") == 0) {
				if (focus == 1 && syll.accent < 28)
					syll.accent -=15 ;
				i.t0 = actms ;
				i.amplitude = 0.02*syll.accent ;
				n = sy.distance_to_pgr();
				i.delay = 0 - 60*(4-n) ;
				i.betali = 0.0002 * syll.accent ;
				i.betare = 0.001 + 0.001*max(2-n,0) ;
				dsl.conc(i) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ; }
			else
			if (strcmp(syll.prosinfo,"EHw") == 0) {
				i.t0 = actms ;
				i.amplitude = 0.5 ;
				i.delay = 80 * (sy.distance_to_pgr() + 1) ;
				i.betali = 0.002 ;
				i.betare = 0.001 ;
				dsl.conc(i) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ; }
			actms += (long)get_postdur(syll,soli) ; }
#ifndef BORDERPROS
			}
#else
		if (strcmp(syll.type,"PGR") == 0 && p != NULL) {
		 pr = p->get_and_advance() ;
//		 fprintf(errfile,"HEY JUST HERE %8f %8f\n",pr.delay,pr.ampli) ;
		 fflush(errfile) ;
#ifndef LOWBORDERTONE
		 if (syll.prosinfo[0] == '1') {
#endif
			accentnr_in_phrase++ ;
			accentnr_in_satz++ ;
			n = 0 ;
			i.t0 = actms - phrasedur ;
			i.delay = pr.delay ;
			i.amplitude = pr.ampli ;
			i.betali = pr.betali ;
			i.betare = pr.betare ;
			if (i.betali == 0.0)
				i.betali = 0.01 ;
			if (i.betare == 0.0)
				i.betare = 0.01 ;

//			fprintf(errfile,"%f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
			fflush(errfile) ;
#ifdef NEWTREE
			if (i.amplitude != 0) {
				i.betare = (i.betare * (3.14257/4.0) / i.amplitude) * 0.5 ;
				i.betali = (i.betali * (3.14257/4.0) / i.amplitude) * 0.5 ;
				i.amplitude = i.amplitude / 100.0 ; }
#endif
//			fprintf(errfile,"made to %f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
			fflush(errfile) ;
			dsl.conc(i) ; } 
#ifndef LOWBORDERTONE
 }
#endif
		else
		if (strcmp(syll.type,"PGR") == 0 && nnfile != NULL) {
			if (onlystress == 0)
				fgets(buffer,299,nnfile) ;
#ifndef LOWBORDERTONE
			if (syll.prosinfo[0] == '1') {
#endif
				if (onlystress == 1)
		fgets(buffer,299,nnfile) ;
				accentnr_in_phrase++ ;
				accentnr_in_satz++ ;
				n = 0 ;
				if (onlystress == 0)
					while (!isspace(buffer[n]))
						n++ ;
				i.t0 = actms-phrasedur ;
				i.delay = atof(&buffer[n]) ;
				n += 2 ;
				while (!isspace(buffer[n]))
					n++ ;
				i.amplitude = atof(&buffer[n]) ;
				n += 2 ;
				while (!isspace(buffer[n]))
					n++ ;
				i.betali = atof(&buffer[n]) ;
				n += 2 ;
				while (!isspace(buffer[n]))
					n++ ;
				i.betare = atof(&buffer[n]) ;
//				fprintf(errfile,"%f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
				fflush(errfile) ;
#ifdef NEWTREE
				if (i.amplitude != 0) {
					i.betare = (i.betare * (3.14257/4.0) / i.amplitude) * 0.5 ;
					i.betali = (i.betali * (3.14257/4.0) / i.amplitude) * 0.5 ;
					i.amplitude = i.amplitude / 100.0 ; }
#endif
//				fprintf(errfile,"made to %f %f %f %f\n",i.delay,i.amplitude,i.betali,i.betare) ;
				fflush(errfile) ;
				dsl.conc(i) ; } } 
#ifndef LOWBORDERTONE
 }
#endif
#endif
	  if (accentnr_in_satz == 0) {
		i.t0 = 0 ;
		i.amplitude = 0.5 ;
		i.delay = 80 ;
		i.betali = 0.002 ;
		i.betare = 0.001 ;
		fprintf(errfile,"NO INTONATION PEAKS FOUND FOR UTTERANCE - DEFAULT ADDED\n") ;
      fflush(errfile) ;
		dsl.conc(i) ; }

if (debuglevel > 0) {
     fprintf(errfile,"\n\nIntonation Parameters:\n\n") ;
     print(errfile,actms) ;
}

#ifndef NO_FILES
	  intofile = FOPEN(intofilename,"w") ;
	  if (intofile != NULL) {
		print(intofile,actms) ;
		FCLOSE(intofile) ; } }

	else {
		intofile = FOPEN(intofilename,"r") ;
		if (intofile != NULL) {
			actms = input(intofile) ;
			FCLOSE(intofile) ; }

#endif
	}
	dsl.reset() ;
	totalms = actms ;
	actms = 0 ;
	soli->reset() ;
	int nextt = 0 ;
	n = 20 ;
	float pp ;

	while ((s = soli->get_sound_pointer(soli->get_number()))->duration != -1) {
		while (nextt <= s->duration) {
			pp = compute_f0_value(actms+nextt,totalms) ;
			if (s->f0nr < 30) {
				s->f0nr++ ;
				s->f0[s->f0nr-1] = pp ;
				s->f0pos[s->f0nr-1] = nextt ; }
			nextt += n ; }
		actms += s->duration ;
		nextt -= s->duration ;
		if (soli->advance() == -1)
			break ; }
	return(1) ; }

long Intonation_Model::input(FILE* infil) {
	char buffer[81] ;
	I_Command i ;
	long totalms = 0L ;
	dsl.reset() ;

	while (fgets(buffer,79,infil) != NULL) {
	 if(buffer[0] == 'P') {
		totalms = strtol(&buffer[18],NULL,10) ;
		toplinestart = strtod(&buffer[27],NULL) ;
		toplineend = strtod(&buffer[36],NULL) ;
		baselinestart = strtod(&buffer[45],NULL) ;
		baselineend = strtod(&buffer[54],NULL) ; }
	 else {
		i.t0 = strtol(&buffer[9],NULL,10) ;
		i.delay = strtod(&buffer[18],NULL) ;
		i.betali = strtod(&buffer[27],NULL) ;
		i.betare = strtod(&buffer[36],NULL) ;
		i.amplitude = strtod(&buffer[45],NULL) ;
#ifdef NEWTREE
		i.betare = (i.betare * (3.14257/4.0) / i.amplitude) ;
		i.betali = (i.betali * (3.14257/4.0) / i.amplitude) ;
		i.amplitude = i.amplitude / 100.0 ;
#endif
		dsl.conc(i) ; } }
	return(totalms) ; }


void Intonation_Model::print(FILE* outfil, long totalms) {
	dsl.reset() ;
	I_Command i ;
	fprintf(outfil,"P       :%8d %8ld %8.2f %8.2f %8.2f %8.2f\n",0,totalms,toplinestart,toplineend,baselinestart,baselineend) ;
	while ((i = dsl.get_and_advance()).t0 != -1)
#ifdef NEWTREE
		fprintf(outfil,"A       :%8ld %8.3f %8.3f %8.3f %8.3f\n",
			i.t0,i.delay,i.betali*100.0*i.amplitude/(3.14257/4.0),i.betare*100.0*i.amplitude/(3.14257/4.0),i.amplitude*100.0) ; }
#else
		fprintf(outfil,"A       :%8ld %8.3f %8.5f %8.5f %8.5f\n",
			i.t0,i.delay,i.betali,i.betare,i.amplitude) ; }
#endif

int NNProsody::NNSyllist::conc(NNSyll i) {
	return(append(i)) ; }

NNProsody::NNSyllist::NNSyllist() {
	errorvalue.syldur = -1 ; }

DBSyllist::~DBSyllist() {
	reset() ;
	while (act != NULL) {
		if (act->i.name != NULL)
			delete(act->i.name) ;
		act = act->after ; } }

NNProsody::NNSyllist::~NNSyllist() {
	reset() ;
	while (act != NULL) {
		if (act->i.name != NULL)
			delete(act->i.name) ;
		act = act->after ; } }

int DBSyllist::conc(DBSyll i) {
	return(append(i)) ; }

DBSyllist::DBSyllist() {
	errorvalue.sonr = -1 ; }

void DBSyllist::clearx() {
	reset() ;
	while (act != NULL) {
		if (act->i.name != NULL)
			delete[](act->i.name) ; 
		act = act->after ; }
	clear() ; }


DBSyll* DBSyllist::get_db_pointer(int index) {
	get(index) ;
	return(&(act->i)) ; }

DBSyll* DBSyllist::get_db_pointer() {
	return(&(act->i)) ; }

NNProsody::NNProsody(char* filename, char* filepath) {
	prifa = 0 ;
	ptobo = 2 ;
	pacatbo = 0 ;
	facatbo = 0 ;
return ; }

NNProsody::~NNProsody() {
	return ; }

DBSyllist* NNProsody::get_DBS() {
	return(&dbs) ; }


int NNProsody::generate_DBS(Syllablelist* syll, Soundlist* soli) {
	DBSyll i ;
	DBSyll* j ;
	Syllableinfo s ;
	Soundinfo ss ;
	int fpdiss = 0 ;
	int fpacce = 0 ;
	int nr = 1 ;
	int inr ;
	int maxacc = 0 ;
	int dnr ;
	int typ = 0 ;
	int rifa = 0 ;
	int tobo = 0 ;
	int beat = 0 ;
	int ii ;
	char* result ;


	result = syll->find_command("SetBorderType") ;
	if (result != NULL) {
		tobo = atoi(result) ; }
	syll->reset() ;
	while ((s = syll->get_and_advance()).accent != -1) {
		if (strcmp(s.type,"SIL") != 0) {
			if (strcmp(s.type,"PGR") == 0) {
				i.pdiss = fpdiss ;
				fpdiss = 0 ;
				fpacce = 1 ;
				beat = 1 ;
				nr = 1 ;
				i.name = strdup(s.name) ;
				strcpy(i.nucl,"") ;
				i.firstsound = s.firstsound ;
				i.silgrz = 0 ;
				i.bodi = 0 ;
				i.acat = s.accent ;
				i.pacatbo = pacatbo ;
				pacatbo = i.acat ;
				i.ptobo = ptobo ;
				i.prifa = prifa ;
				i.sonr = 1 ;
				i.nuctyp = 4 ;
				i.onsec = 0 ;
				i.cosec = 0 ;
				i.onso = 0 ;
				i.coso = 0 ;
				i.onfr = 0 ;
				i.cofr = 0 ;
				i.acce = 1 ;
				i.onpl = 0 ;
				i.copl = 0 ;
				i.nuchilo = 0 ;
				i.stress = 0 ;
				i.pacce = 0 ;
				i.facce = 0 ;
				i.fdiss = 0 ;
				i.beatc = 0 ;
				i.phraspos = 0 ;
				i.beatp = 0 ;
				i.sylnr = 0 ;
				if (result == NULL)
					i.tobo = atoi(&s.prosinfo[1]) ;
				else
					i.tobo = atoi(result) ;
				if (s.prosinfo[0] == '1')
					i.rifa = 1 ;
				else
					i.rifa = 0 ;
				i.typ = i.rifa ;

				if (i.rifa == 1)
					i.stress = 1 ;
#ifdef LOWBORDERTONE
				i.stress=1 ;
#endif 
				dbs.conc(i) ;
				if (i.tobo != 0) {
					prifa = i.rifa ;
					ptobo = i.tobo ; } }
			continue ; }
		i.name = strdup(s.name) ;
		if (maxacc < s.accent)
			maxacc = s.accent ;
		i.silgrz = 1 ;
		i.firstsound = s.firstsound ;
		i.acat = s.accent ;
		i.sonr = s.soundnr ;
		ss = soli->get(s.firstsound) ;
		for (ii = 0 ; ii < s.soundnr; ii++) {
			ss = soli->get_and_advance() ;
			if (ss.name[0] == '_')
				i.sonr-- ; }
		i.pacatbo = pacatbo ;
		i.facatbo = facatbo ;
		i.onsec = 0 ;
		i.cosec = 0 ;
		i.onso = 0 ;
		i.coso = 0 ;
		i.onfr = 0 ;
		i.cofr = 0 ;
		i.onpl = 0 ;
		i.copl = 0 ;
		i.nuchilo = 0 ;
		i.ptobo = ptobo ;
		i.prifa = prifa ;
		for (ii=0 ; ii < s.soundnr; ii++) {
			ss = soli->get(s.firstsound + ii) ;
			if (strchr("aeiouy29EIOUY=@",ss.name[0]) != NULL)
				break ;
			if (ss.name[0] != '_')
				i.onsec++ ;
			if (strchr("ptkbdg?",ss.name[0]) != NULL)
				i.onpl++ ;
			if (strchr("fvszSZCjxh",ss.name[0]) != NULL)
				i.onfr++ ;
			if (strchr("mnNRl",ss.name[0]) != NULL)
				i.onso++ ; }
		strcpy(i.nucl,ss.name) ;
		while (++ii < s.soundnr) {
			ss = soli->get(s.firstsound + ii) ;
			if (ss.name[0] != '_')
				i.cosec++ ;
			if (strchr("ptkbdg?",ss.name[0]) != NULL)
				i.copl++ ;
			if (strchr("fvszSZCjxh",ss.name[0]) != NULL)
				i.cofr++ ;
			if (strchr("6mnNRl",ss.name[0]) != NULL)
				i.coso++ ; }
		i.nuctyp = 1 ;
		if (strchr("@=",i.nucl[0]) != NULL)
			i.nuctyp = 0 ;
		if (i.nucl[1] == ':')
			i.nuctyp = 2 ;
		if (strlen(i.nucl) > 1 && strchr("UIY",i.nucl[1]) != NULL)
			i.nuctyp = 3 ;
		if (strchr("iIuUyY",i.nucl[0]) != NULL)
			i.nuchilo = 1 ;
		if (strchr(".-",s.prosinfo[0]) == NULL)
			i.stress = 1 ;
		else
			i.stress = 0 ;
		if (strchr(s.prosinfo,'M') == NULL)
			i.stressmax = 0 ;
		else
			i.stressmax = 1 ;
		if (strchr(s.prosinfo,'L') == NULL)
			i.stresslate = 0 ;
		else
			i.stresslate = 1 ;
		if (strchr(s.prosinfo,'E') == NULL)
			i.stressearly = 0 ;
		else
			i.stressearly = 1 ;
		if (strchr(s.prosinfo,'S') == NULL)
			i.stressslope = 0 ;
		else
			i.stressslope = 1 ;
		i.pacce = fpacce ;
		i.sylnr = nr++ ;
		i.phraspos = 0 ;
		if (i.sylnr == 0)
			i.phraspos = 2 ;
		if (i.sylnr == 1)
			i.phraspos = 1 ;
		i.pdiss = fpdiss ;
		if (strchr(i.name,'@') == NULL && strchr(i.name,'=') == NULL) {
			i.acce = 1 ;
			fpacce = 1 ; }
		else {
			i.acce = 0 ;
			fpacce = 0 ; }
		if (fpdiss > 0)
			fpdiss++ ;
		if (i.stress == 1) {
			beat = 1 ;
			fpdiss = 1 ; }
		i.beatp = beat++ ;
		dbs.conc(i) ; }
	inr = syll->length() ;
	dnr = dbs.length() ;
	fpdiss = 0 ;
	while (inr > 0) {
		s = syll->get(inr--) ;
		j = dbs.get_db_pointer(dnr--) ;
		if (j->silgrz == 1) {
			j->typ = typ ;
			j->rifa = rifa ;
			j->facatbo = facatbo ;
			j->bodi = (nr++)-1 ;
			j->sylpos = int(8*j->sylnr/(j->bodi+j->sylnr)) ;
			if (j->bodi == 0)
				j->phraspos = -2 ;
			if (j->bodi == 1)
				j->phraspos = -1 ;
			j->tobo = tobo ; }
		else {
			tobo = j->tobo ;
			rifa = j->rifa ;
			typ = j->typ ;
			fpdiss = 0 ;
			fpacce = 1 ;
			beat = 0 ;
			nr = 1 ;
			j->facatbo = facatbo ;
			facatbo = j->acat ; }
		if (beat == 0)
			beat = j->beatp ;
		j->beatc = beat ;
		j->facce = fpacce ;
		j->fdiss = fpdiss ;
		j->maxacc = maxacc ;
		if (strchr(j->name,'@') == NULL && strchr(j->name,'=') == NULL)
			fpacce = 1 ;
		else
			fpacce = 0 ;
		if (fpdiss > 0)
			fpdiss++ ;
		if (j->stress == 1 && j->silgrz == 1) {
			beat = 0 ;
			fpdiss = 1 ; } }
	return(1) ;}

void NNProsody::list_DBS(FILE* out) {
	DBSyll i ;

	dbs.reset() ;
	fprintf(out,"Name     fiso nu t ac p f s bd r sn pd fd t so bp bc o f p s c f p s n r t s f p n m\n") ;
	while ((i = dbs.get_and_advance()).sonr != -1) {
#ifndef BORDERPROS
		if (i.silgrz == 0)
			continue ;
#endif

		fprintf(out,"%8s %4d %2s %1d %2d %1d %1d %1d %2d %1d %2d %2d %2d %1d %2d %2d %2d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %1d %2d %1d %3d %3d\n",
			i.name,i.firstsound,i.nucl,i.typ,i.acat,i.pacce,i.facce,i.stress,i.bodi,i.rifa,
			i.sylnr,i.pdiss,i.fdiss,i.tobo,i.sonr,i.beatp,i.beatc,i.onsec,i.onfr,i.onpl,i.onso,i.cosec,i.cofr,i.copl,i.coso,i.nuchilo,i.prifa,i.ptobo,i.silgrz, i.nuctyp, i.maxacc, i.acce,i.facatbo,i.pacatbo) ; } }

int NNProsody::compute_NNS() {
	return(-1) ; }

int NNProsody::build(Syllablelist* syll,Soundlist* soli) {
	if (generate_DBS(syll,soli) == 1)
		return(compute_NNS()) ;
	return(-1) ; }

NNSyll NNProsody::get_next_NSL() {
	return(nsl.get_and_advance()) ; }

void NNProsody::NSL_reset() {
	nsl.reset() ; }

void NNProsody::clear() {
	dbs.clearx() ;
   nsl.clear() ; }









