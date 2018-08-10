#define _POSIX_SOURCE
#include "synthese.h"
#include "tags.h"
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <fcntl.h> 
#include <stdio.h>
#ifndef SUN
#include <getopt.h>
#endif


extern int optind,opterr,optopt ;

extern char* optarg ;



char* synopsis = 
"This is twhadi Version 0.92\n"
"Usage is \"twadi -pdvlih\"\n"
"Valid options are:\n"
"  -p path      - This option specifies the path to the hadifix files. Default\n"
"                 value is /usr/local/hadifix/data/. The path must end with a '/'.\n"
"  -f path      - This option specifies the path to the festival files. Default\n"
"                 value is /usr/local/src/festival.\n"
"  -d level     - Level specifies the amount of debug information (default 0).\n"
"                 The higher the number, the more information is given. The\n" 
"                 debug info is written into files located in /tmp.\n"
"  -v           - Gives the version number and exits.\n"
"  -i name      - Specifies an input file name or text, depending on the mode.\n"
"  -l name      - Specifies the path to the temporary files (default is \"/tmp/\").\n"
"  -h           - Prints this information.\n" ;

int basname(char* out, char* in) {
   strcpy(out,in) ;
  *strrchr(out,'.') = 0 ;
  return(0) ; }


int main (int argc, char** argv) {
	int modus = 0 ;
	int i = 0 ;

	struct timespec ts ;
	ts.tv_sec = 0 ;
	ts.tv_nsec = 10000 ;
	
	char path[2048] ;
	char inname[2048] ;
	char outname[2048] ;
	char outbname[2048] ;
	char isname[2048] ;
	char voicename[2048] ;
	char festname [2048] ;
	char buffer[2048] ;
	char rvname[256] ;
	strcpy(path,"/usr/local/hadifix/data/") ;
	strcpy(festname,"/TalkingWeb/festival/festival") ;
	strcpy(inname,"-") ;
	strcpy(outname,"-") ;
	strcpy(voicename,"") ;
	char pid[64] ;
	char lp[256] ;
	int debuglevel = -1 ;
	char temp[90] ;
	int piping = 0 ;
	FILE* stpfile ;

	char* RetiPcomDir = getenv("RetiPcomDir") ;
	char* RetiRoot = getenv("TalkingWebRoot") ;

	if (RetiRoot == NULL)
	  {
	    RetiRoot = "/TalkingWeb" ;
	  }
	if (RetiPcomDir == NULL)
	  {
	    RetiPcomDir = "/TalkingWeb/data/pcom_files" ;
	  }
	  
	char lockname[2048] ;
	char linkname[2048] ;
	char synstopname[2048] ;
	char synstopokname[2048] ;
	struct stat filestat;

	sprintf(pid,"%d",getpid()) ;
	
        setvbuf(stdin, NULL, _IOLBF, BUFSIZ);
        setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	char optc ;

	strcpy(lp,"") ;

	while((optc = getopt(argc,argv,"p:d:f:vi:hl:")) != EOF) {

	  switch(optc) {
	  case 'v': printf("This is twhadi Version 0.92\n") ; return(0) ;
	  case 'p': if (optarg != NULL)strcpy(path,optarg) ; break; 
	  case 'f': if (optarg != NULL)strcpy(festname,optarg) ; break; 
	  case 'd': if (optarg != NULL)debuglevel = atoi(optarg) ; break ;
	  case 'i': if (optarg != NULL)strcpy(inname,optarg) ; break ;
	  case 'l': if (optarg != NULL)strcpy(lp,optarg) ; break ;
	  case 'h': printf("%s",synopsis) ; return(0) ; }}

	unlink(inname) ;

	if (piping != 0)
	  piping = 1 ;

	Synthese* s ;
	int language = 0 ;
	Taglist t(path) ;
	s = new Synthese(pid,path,lp,debuglevel,piping) ;
	FILE* infile ;
	int infd ;
	fd_set inset ;
	fd_set stopset ;
	if (inname[0] == '-')
	  infd = 0 ;
	else {
	  do {
	    sleep(1) ; 
	    infd = open(inname,O_RDONLY) ; }
	  while(infd == -1) ; }
	infile = fdopen(infd,"r") ;
	FD_ZERO(&inset) ;
	FD_SET(infd,&inset) ;
	do {
	    select(infd+1,&inset,NULL,NULL,NULL) ;  
	    fgets(buffer,2047,infile) ;
	  sscanf(buffer,"%s %s %s",isname,outname,rvname) ;
	  if ((i = open(outname,O_CREAT | O_EXCL | O_RDONLY,6*64+6*8+6)) == -1 )
	    continue ;
	    
	  close(i) ;
	  language = t.change(isname) ;
	  basname(outbname,outname) ;
	  sprintf(lockname, "%s.lock", outbname);
	  sprintf(linkname, "%s_%dl.lock", outbname, getpid());

	  if ((i = open(lockname,O_CREAT | O_EXCL | O_RDONLY,6*64+6*8+6)) == -1 )
	    continue ;
	  close(i);

	  // Locking wird ueber Anzahl der Links ueberprueft vgl. 
	  // man 2 open
	  //
	  if ((i = link(lockname,linkname)) == -1 )
	    continue ;
	    
	  close(i);

	  stat( lockname, &filestat );
	  if( filestat.st_nlink > 2 ){
	    unlink(linkname);
	    continue;
	  }

	  // Looking for synth_stop
	  strcat(strcpy(synstopname,RetiPcomDir),"/synth_stop") ;
	  strcat(strcat(strcpy(synstopokname,RetiPcomDir),"/synth_stop_"),pid) ;
	  stpfile = fopen(synstopname,"r") ;
	  if (stpfile != NULL)
	    {
	      fclose(stpfile) ;
	      stpfile = fopen(synstopokname,"w") ;
	      fprintf(stpfile,"%s\n",pid) ;
	      do {
		fclose(stpfile) ;
		sleep(1) ;
		stpfile = fopen(synstopname,"r") ;
	      }
	      while (stpfile != NULL) ;
	    }

	  //	  if (language == 0)
	    s->talk(outname,0,isname,0,NULL,NULL,NULL,rvname) ;
	    //	  else {
	    //	    sprintf(buffer,"%s/examples/text2wavewithlog -mode text -l %s.tmp -o %s %s; cat %s.tmp | awk ' BEGIN {n=0}  { print $1 \" \" n ; n += $3 } ' > %s",festname,rvname,outname,isname,rvname,rvname) ;
	    //	    system(buffer) ;
	    // }

	  unlink(linkname);
	  unlink(lockname);

	  sprintf(buffer, "%s/hirn/perl_code/convsound.perl %s", RetiRoot, outbname) ;
	  system(buffer) ;
	}
	while(strcmp(outname,"TWHADISTOP") != 0) ;
	delete(s) ;
	return(0) ;
 }
	





