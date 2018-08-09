
#include "lisatalk.h"
#if !defined(__SOUND_H__)
#include "sound.h"
#endif

char* consonants = "ptkbdgfvszSZcjxhRlmnN" ;

char* vowels = "aeiou29EIOUyY6@" ;
char* voiced = "aeiou29EIOYyY6@mnRlN" ;

int find_diphon_in_liste(char* liste, char* key) {

  //	fprintf(errfile,"LOOKING FOR %s\n",key) ;

	if (liste == NULL)
   	return(0) ;
	if (strstr(liste,key) != NULL) {
   	fprintf(errfile,"FOUND\n") ;
   	return(1) ; }
   return(0) ; }



Soundlist::Soundlist() {
  actdur = 0L ;
	errorvalue.duration = -1 ;
	errorvalue.intensity = -1 ;
	errorvalue.f0nr = 0 ; }

Soundlist::~Soundlist() { ; }
//	printf("now deleting soundlist\n") ; }

Soundinfo* Soundlist::get_sound_pointer(int i) {
	get(i) ;
	return(&(act->i)) ; }

Soundinfo Soundlist::get_last_sound() {
	return(act->before->i) ; }


void Soundlist::print(FILE* ascoutfil) {
	reset() ;
	Soundinfo i ;
	while ((i = get_and_advance()).duration != errorvalue.duration) {
		fprintf(ascoutfil,"%3d %4s - %6d - %6d - ",get_number()-1,i.name,i.duration,i.intensity) ;
		for (int j = 0 ; j < i.f0nr; j++)
			fprintf(ascoutfil,"%3.0f %3.0f ",i.f0[j],i.f0pos[j]) ;
		fprintf(ascoutfil,"\n") ; } }

/*
void Soundlist::printmbrola(FILE* ascoutfil, char* impbuffer) {
	reset() ;
	Soundinfo i,lasti ;
	int lastdur = 0;

	while ((i = get_and_advance()).duration != errorvalue.duration) {
		if (i.name[0] == '_') {
			lastdur = i.duration ;
			continue ; }
		i.duration+=lastdur ;
		lastdur = 0 ;

		fprintf(stderr,"%s\n",i.name) ;

		if (strcmp(i.name,"EI") == 0) {
			strcpy(i.name,"e:") ;
			fprintf(ascoutfil,"%s %d ","e:",i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }
		if (strcmp(i.name,"O~") == 0) {
			fprintf(ascoutfil,"%s %d ","o^",i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }

		if (strchr(i.name,'0') != NULL) {
			fprintf(ascoutfil,"%c %d ",i.name[0],i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }
		        
		if (i.name[1] == '~') {
			fprintf(ascoutfil,"%c^ %d ",i.name[0],i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }

		if (strchr("=",i.name[0]) != NULL) {
			fprintf(ascoutfil,"%s %d ",&i.name[1],i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }
		if (strchr("<",i.name[0]) != NULL) {
			fprintf(ascoutfil,"%s: %d ",&i.name[1],i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }

		if (strchr("2oiuey",i.name[0]) != NULL && i.name[1] != ':') {
			fprintf(ascoutfil,"%s: %d ",i.name,i.duration) ;
			for (int j = 0 ; j < min(20,i.f0nr); j++)
				fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
			fprintf(ascoutfil,"\n") ;
			lasti = i ;
			continue ; }

		if (strcmp(i.name,lasti.name) == 0) {
			lasti = i ;
			continue ; }


		if (i.name[0] == '?')
			i.name[0] = '_' ;
		if (strcmp(i.name,"pau") == 0) {
			if (i.duration > 10) {
				fprintf(ascoutfil,"_ %d\n#\n",i.duration) ;
				lasti = i ; }
			continue ; }



		lasti = i ;
		fprintf(ascoutfil,"%s %d ",i.name,i.duration) ;
		for (int j = 0 ; j < min(20,i.f0nr); j++)
			fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
		fprintf(ascoutfil,"\n") ; } }
*/
void Soundlist::printf0(FILE* ascoutfil) {
	reset() ;
	Soundinfo i ;
	while ((i = get_and_advance()).duration != errorvalue.duration) {
		if (strchr(voiced,i.name[0]) == NULL) {
			actdur += i.duration ;
			continue ; }		
		for (int j = 0 ; j < i.f0nr; j++)
			fprintf(ascoutfil,"%ld %3.0f\n",(long)i.f0pos[j]+actdur,i.f0[j]) ;
		actdur += i.duration ; } }

void Soundlist::printmbrola(FILE* ascoutfil, char* impbuffer) {
	reset() ;
	Soundinfo i,lasti ;
   char db[24] ;
	int lastdur = 0;

   lasti = get_and_advance() ;
	while ((i = get_and_advance()).duration != errorvalue.duration) {
		if (i.name[0] == '_') {
			lastdur = i.duration ;
			continue ; }
		i.duration+=lastdur ;
		lastdur = 0 ;



		if (strcmp(i.name,"EI") == 0)
			strcpy(i.name,"e:") ;
		if (strcmp(i.name,"O~") == 0)
			strcpy(i.name,"o^") ;
		if (strcmp(i.name,"9~") == 0)
			strcpy(i.name,"E^") ;
		if (i.name[1] == '~') {
			sprintf(db,"%c^",i.name[0]) ;
         strcpy(i.name,db) ; }
		if (i.name[1] == '0') {
			sprintf(db,"%c",i.name[0]) ;
         strcpy(i.name,db) ; }	
		if (strchr("=",i.name[0]) != NULL) {
			sprintf(db,"%s",&i.name[1]) ;
         strcpy(i.name,db) ; }
		if (strchr("<",i.name[0]) != NULL) {
			sprintf(db,"%s",&i.name[1]) ;
         strcpy(i.name,db) ; }
		if (strchr("2oiuey",i.name[0]) != NULL && i.name[1] == '\0') {
			sprintf(db,"%s:",i.name) ;
         strcpy(i.name,db) ; }
		if (strchr("9OIUY@6",i.name[0]) != NULL && i.name[1] == ':')
			i.name[1] = '\0'  ;
		if (i.name[0] == '?')
			i.name[0] = '_' ;
		if (strcmp(i.name,"pau") == 0)
			sprintf(i.name,"_") ;

		if (strcmp(i.name,lasti.name) == 0) {
			lasti = i ;
			continue ; }

      sprintf(db,"-%s-%s-",lasti.name,i.name) ;
      if (find_diphon_in_liste(impbuffer,db) == 1) {
      	if (strchr("dgvzhj",lasti.name[0]) != NULL) {
         	fprintf(ascoutfil,"a 10\n") ; }
         if (strchr("9O",lasti.name[0]) != NULL) {
         	fprintf(ascoutfil,"t 10\n") ; }
         if (lasti.name[0] != '_' && i.name[0] != '_')
	         fprintf(ascoutfil,"_ 5\n") ;
         if (i.name[0] == 'N')
         	fprintf(ascoutfil,"a 10\n") ;
         if (i.name[0] == '6')
         	fprintf(ascoutfil,"t 10\n") ;
         if (strchr("^~",i.name[1]) != NULL && strchr("E9o",i.name[0]) != NULL && strlen(i.name) > 1)
         	fprintf(ascoutfil,"t 10\n") ; }

		lasti = i ;
		fprintf(ascoutfil,"%s %d ",i.name,max(10,i.duration)) ;
		for (int j = 0 ; j < min(10,i.f0nr); j++)
			fprintf(ascoutfil,"%3.0f %3.0f ",100.0*(float)i.f0pos[j]/(float)i.duration,i.f0[j]) ;
		fprintf(ascoutfil,"\n") ; } }

void Soundlist::input_prosody(FILE* ascoutfil) {
	reset() ;
	Soundinfo* i ;
	int j ;
	char buffer[256] ;
	while ((i = get_sound_pointer(get_number()))->duration != errorvalue.duration) {
		if (advance() < 0)
			break ;
		if (fgets(buffer,255,ascoutfil) == NULL)
			break ;
		i->duration = atoi(&buffer[10]) ;
		i->intensity = atoi(&buffer[19]) ;
		i->f0nr = 0 ;
      i->accent = 0 ;
		j = 28 ;
		while (buffer[j] != '\n') {
			while (buffer[j] != ' ' && buffer[j] != '\n')
				j++ ;
			if (buffer[j] == '\n')
				break ;
			i->f0[i->f0nr] = atof(&buffer[j]) ;
			if (i->f0[i->f0nr] == 0)
				break ;
			j += 4 ;
			while (buffer[j] != ' ' && buffer[j] != '\n')
				j++ ;
			if (buffer[j] == '\n')
				break ;
			i->f0pos[i->f0nr] = atof(&buffer[j]) ;
			if (i->f0pos[i->f0nr] == 0)
					break ;
			j += 4 ;
			i->f0nr++ ; } } }
void Soundlist::input(FILE* ascoutfil) {
	Soundinfo i ;
	int j,k ;
	char buffer[2048] ;
	while (fgets(buffer,2047,ascoutfil) != NULL) {

		if (buffer[0] == '{')
			continue ;
		j = 4 ;
		k = 0 ;
		while (buffer[j] == ' ')
			j++ ;
		while (buffer[j] != ' ')
			i.name[k++] = buffer[j++] ;
		i.name[k] = '\0' ;
		i.duration = atoi(&buffer[10]) ;
		i.intensity = atoi(&buffer[19]) ;
		i.f0nr = 0 ;
		i.accent = 0 ;
		j = 28 ;
		while (buffer[j] != '\n' && i.f0nr < 30) {
			while (buffer[j] != ' ' && buffer[j] != '\n')
				j++ ;
			if (buffer[j] == '\n')
				break ;
			i.f0[i.f0nr] = atof(&buffer[j]) ;
			if (i.f0[i.f0nr] == 0)
				break ;
			j += 4 ;
			while (buffer[j] != ' ' && buffer[j] != '\n')
				j++ ;
			if (buffer[j] == '\n')
				break ;
			i.f0pos[i.f0nr] = atof(&buffer[j]) ;
//			if (i.f0pos[i.f0nr] == 0)
//     			       	break ;
			j += 4 ;
			i.f0nr++ ; } 
		conc(i) ; } }

int Soundlist::conc(Soundinfo i) {
	return(append(i)) ; }

void Soundlist::clear_zero_dur() {
	reset() ;
	Soundinfo i ;
	int j ;
	while ((i = get()).duration != errorvalue.duration) {
		j = get_number() ;
		if (i.duration <= 0)  {
			exclude(j) ;
			continue ; }
		if (advance()==-1)
			break ; }
	return ; }

void Soundlist::clear_doubles() {
	reset() ;
	Soundinfo i1,i2 ;
	int j ;
	i1 = get_and_advance() ;
	while ((i2 = get()).duration != errorvalue.duration) {
		j = get_number() ;
		if (strcmp(i1.name,i2.name) == 0 && (strcmp(i1.name,"pau") != 0))  {
			exclude(j) ;
			continue ; }
		if (i1.name[0] == i2.name[0] && i1.name[1] == '0' && i2.name[1] == '\0') {
			exclude(j) ;
			continue ; }
		i1 = i2 ;
		if (advance()==-1)
			break ; }
	return ; }
