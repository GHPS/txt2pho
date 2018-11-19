#include "synthese.h"
#include <unistd.h>


int main (int argc, char** argv) {
	int modus = 0 ;

	unlink("/tmp/syninfil") ;
	char* path = (char*)"/apps/hadifix/" ; 
	char pid[64] ;
	char temp[90] ;

	sprintf(pid,"%d",getpid()) ;
	


	FILE* infile ;
	FILE* scratch ;
	FILE* out ;	
      	Synthese s(pid,path,(char*)"/tmp/",3) ;
	char buffer[4096] ;
	scratch = fopen("/tmp/syswatch","w") ;
	fprintf(scratch,"Synthese gestartet.") ;
	fclose(scratch) ;
	s.talk("/tmp/syswatchout",modus,"/tmp/syswatch") ;
	system("splay -q -b 16 -s 32000 /tmp/syswatchout") ;

	do {
		sleep(1) ;
		infile = fopen("/tmp/syninfil","r") ; }
	while (infile == NULL) ;
	do {
		sleep(1) ;
		if (fgets(buffer,sizeof(buffer),infile) == NULL)
			continue ;	
		scratch = fopen("/tmp/syswatch","w") ;
		fprintf(scratch,"%s",buffer) ;
		fclose(scratch) ;
		s.talk("/tmp/syswatchout",modus,"/tmp/syswatch") ;
		system("splay -q -b 16 -s 32000 /tmp/syswatchout") ;
		if (strcmp(buffer,"Game Over") == 0)
			break ; }
	while(1) ;
	sprintf(temp,"rm /tmp/%s*\n",pid) ;
	unlink("/tmp/syninfil") ;
	system(temp) ;
//	fprintf(stderr,"Game Over\n") ;
 }
	

