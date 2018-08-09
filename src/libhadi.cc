#include "synthese.h"
#include <unistd.h>

Synthese* s ;
char pid[64] ;
char temp[90] ;

int Hadi_init(char* path, char* logpath="/tmp/",int debuglevel=0) {

	sprintf(pid,"%d",getpid()) ;
	
	s = new Synthese(pid,path,logpath,debuglevel) ;
	return(0) ; }

int Hadi_close() {
	sprintf(temp,"rm /tmp/%s*\n",pid) ;
	system(temp) ;
	delete(s) ;
        return(0) ; }

int Hadi_talk(char* infile, int modus, char* outfile){
	return(s->talk(outfile,modus,infile)) ; }
	


