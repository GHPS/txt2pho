#include "synthese.h"
#include <unistd.h>
#ifndef SUN
#include <getopt.h>
#endif

extern int optind,opterr,optopt ;

extern char* optarg ;

char const* synopsis = 
"This is hadifix Version 0.92\n"
"Usage is \"hadifix -pmdnvioh\"\n"
"Hadifix reads text from stdin (if no filename is given with the -i option)\n"
"and writes audio samples to stdout (if no filename is given with the -o option)\n"
"Hadifix reads its global settings from a file \"hadifix.cfg\" located in\n"
"a directory specified by the -p option. If a file \"~/.hadifixrc\" is found,\n"
"its values overwrite those settings, and command line options overwrite the rest.\n"
"Valid options are:\n"
"  -p path      - This option specifies the path to the hadifix files. Default\n"
"                 value is /usr/local/hadifix/data/. The path must end with a '/'.\n"
"  -m mode      - This variable specifies the operating mode (default is 0):\n"
"                 0:  if -i is given, the value is interpreted as a filename,\n"
"                 +10: if -i is given, the value is interpreted as a text,\n"
"                 2:  reserved,\n"
"                 3:  output is the transcription with prominences,\n"
"                 4:  output is the transcription,\n"
"                 5:  input is a sol file (obscure proprietory file format),\n"
"                 7:  output is a sol file (obscure proprietory file format),\n"
"                 8:  output is a file for the MBROLA synthesizer.\n"
"  -d level     - Level specifies the amount of debug information (default 0).\n"
"                 The higher the number, the more information is given. The\n" 
"                 debug info is written into files located in /tmp.\n"
"  -r mode      - Direct input mode after new line (mode can be 0 or 1).\n"
"                 Note this disables internal preprocessing.\n"
"  -v           - Gives the version number and exits.\n"
"  -s name      - Specifies the inventory name.\n"
"  -i name      - Specifies an input file name or text, depending on the mode.\n"
"  -o name      - Specifies an output file.\n"
"  -l name      - Specifies the path to the temporary files (default is \"/tmp/\").\n"
"  -h           - Prints this information.\n" ;


int main (int argc, char** argv) {
	int modus = 0 ;


	
	char path[2048] ;
	char inname[2048] ;
	char outname[2048] ;
	char voicename[2048] ;
	strcpy(path,"") ; 
	strcpy(inname,"-") ;
	strcpy(outname,"-") ;
	strcpy(voicename,"") ;
	char pid[64] ;
	char lp[256] ;
	int debuglevel = -1 ;
	char temp[90] ;
	int piping = 0 ;

	sprintf(pid,"%d",getpid()) ;
	
        setvbuf(stdin, NULL, _IOLBF, BUFSIZ);
        setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	char optc ;

	strcpy(lp,"") ;

	while((optc = getopt(argc,argv,"s:p:m:d:vi:o:hl:r:n:")) != EOF) {

	  switch(optc) {
	  case 'v': printf("This is hadifix Version 0.92\n") ; return(0) ;
	  case 'p': if (optarg != NULL)strcpy(path,optarg) ; break; 
	  case 'm': if (optarg != NULL)modus = atoi(optarg) ; break ;
	  case 'r': if (optarg != NULL)piping = atoi(optarg) ; break ;
	  case 'd': if (optarg != NULL)debuglevel = atoi(optarg) ; break ;
	  case 'n': if (optarg != NULL)strcpy(voicename,optarg) ; break ;
	  case 'i': if (optarg != NULL)strcpy(inname,optarg) ; break ;
	  case 's': if (optarg != NULL)strcpy(voicename,optarg) ; break ;
	  case 'o': if (optarg != NULL)strcpy(outname,optarg) ; break ;
	  case 'l': if (optarg != NULL)strcpy(lp,optarg) ; break ;
	  case 'h': printf("%s",synopsis) ; return(0) ; }}

	if (piping != 0)
	  piping = 1 ;

	Synthese* s ;
	s = new Synthese(pid,path,lp,debuglevel,piping) ;
	if (strlen(voicename) > 0)
	  s->change_voice(NULL,voicename) ;
	s->talk(outname,modus,inname) ;
	delete(s) ;
	return(0) ;
 }
	
