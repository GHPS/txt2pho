
#include "lisatalk.h"


int OpenFiles = 0 ;

long fsize (FILE * xstream)
{
	long curpos, length;

	if ((curpos = ftell(xstream)) == -1L)
		return (-1L);
	if (fseek(xstream, 0L, SEEK_END) != 0)
		return (-1L);
	if ((length = ftell(xstream)) == -1L)
		return (-1L);
	if (fseek(xstream, curpos, SEEK_SET) != 0)
		return (-1L);
	return (length);
}

FILE* FOPEN(char* name, char* modus) {
	FILE* result = fopen(name,modus) ;
	if (result == NULL)
		fprintf(errfile,"Cannot Open %s with %s - %d Open Files\n",name,modus,OpenFiles) ;
	else {
		OpenFiles++ ;
if (debuglevel > 7 ) {
		fprintf(errfile,"File %s opened with %s (%p) - %d Open Files\n",name,modus,result,OpenFiles) ;
}
		}
	fflush(errfile) ;
	return(result) ; }

int FCLOSE(FILE* file) {
if (debuglevel > 7 ) {
	fprintf(errfile,"Closing File %p\n",file) ;
}
	int result = fclose(file) ;
	if (result != 0)
		fprintf(errfile,"Cannot close file - %d Open Files\n",OpenFiles) ;
	else
		OpenFiles-- ;
	return(result) ; }

