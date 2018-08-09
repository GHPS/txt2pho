#include "lisatalk.h"
#include "impwords.h"

char mklower(char in) {
	in = tolower(in) ;
	if (in == 'Ä')
		in = 'ä' ;
	if (in == 'Ö')
		in = 'ö' ;
	if (in == 'Ü')
		in = 'ü' ;
	return(in) ; }

ImpossibleWords::ImpossibleWords(char* path) {

	startpairs = NULL ;
	endpairs = NULL ;
	FILE* startpairfile = fopen("hadifix.iws","r") ;
	if (startpairfile == NULL)
		return ;
	FILE* endpairfile = fopen("hadifix.iwe","r") ;
	if (endpairfile == NULL) {
		fclose(startpairfile) ;
		return ; }
	startpairs = (char*)malloc(1) ;
	endpairs = (char*)malloc(1) ;

	char buffer[30] ;

		startpairnr = 0 ;
	while (fgets(buffer,29,startpairfile) != NULL) {
		if (strlen(buffer) < 2)
			continue ;
		startpairs = (char*)realloc(startpairs,(++startpairnr)*2) ;
		memcpy(&startpairs[(startpairnr-1)*2],buffer,2) ; }
	fclose(startpairfile) ;

	endpairnr = 0 ;
	while (fgets(buffer,29,endpairfile) != NULL) {
		if (strlen(buffer) < 2)
			continue ;
		endpairs = (char*)realloc(endpairs,(++endpairnr)*2) ;
		memcpy(&endpairs[(endpairnr-1)*2],buffer,2) ; }
	fclose(endpairfile) ; }

ImpossibleWords::~ImpossibleWords() {
	if (startpairs != NULL)
		free(startpairs) ;
	if (endpairs != NULL)
		free(endpairs) ; }

int ImpossibleWords::is_impossible(char* word) {
	if (startpairs == NULL)
		return(0) ;
	int i ;
	char buffer[128] ;
	strncpy(buffer,word,127) ;
	for (i = 0 ; i < (int)strlen(buffer) ; i++)
		buffer[i] = mklower(buffer[i]) ;
//	fprintf(errfile,"In IW: %s   ",buffer) ;
	for (i=0 ; i < startpairnr ; i++)
		if (strncmp(&startpairs[i*2],buffer,2) == 0) {
//			fprintf(errfile," IMPSTART %c%c\n",startpairs[i*2],startpairs[i*2+1]) ;
			return(1) ; }
	for (i=0 ; i < endpairnr ; i++)
		if (strncmp(&endpairs[i*2],&buffer[strlen(buffer)-2],2) == 0) {
//			fprintf(errfile," IMPEND %c%c\n",endpairs[i*2],endpairs[i*2+1]) ;
			return(1) ; }
//	fprintf(errfile,"\n") ;
	return(0) ; }





