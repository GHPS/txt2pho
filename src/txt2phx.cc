#include <stdio.h>
#include <windows.h>
#include "tx2phdll.h"
#include "ppdll.h"


FILE* errfile ;

int FCLOSE(FILE* f) {
	return(fclose(f)) ; }

long bt4(long l) {
	return(l) ; }

int isonlyspace(char* s) {
	for (int i = 0 ; i < strlen(s) ; i++) {
   	if (strchr(" \n\t\r",s[i]) == NULL)
      	return(0) ; }
   return(1) ; }

int main(int argc, char** argv) {

  char invbuffer[512] ;
  char buffer[512] ;
  char voice[512] ;
  char outbuffer[512] ;
  char type[512] ;
  char path[512] ;
  strcpy(voice,"male") ;
  strcpy(invbuffer,"") ;
  strcpy(type,"") ;
  strcpy(outbuffer,"") ;
  strcpy(path,"data\\") ;
  FILE* inifile = fopen("txt2pho.ini","r") ;
  if (inifile == NULL) {
  	printf("File txt2pho.ini not found\n") ;
   return(2) ; }
  while (fgets(buffer,511,inifile) != NULL) {
  	buffer[strlen(buffer)-1] = '\0' ;
  	if (strncmp(buffer,"Voice=",6) == 0)
   	strcpy(voice,&buffer[6]) ;
  	if (strncmp(buffer,"Voicefile=",10) == 0)
   	strcpy(invbuffer,&buffer[10]) ;
  	if (strncmp(buffer,"Path=",5) == 0)
   	strcpy(path,&buffer[5]) ; }
  fclose(inifile) ;

	if (argc < 3) {
   	printf("Usage: txt2pho /G=male|female /O=<output file> /T=wav|play /D=<database> <text file> <pho file>\n") ;
      return(-1) ; }

   for (unsigned i=1 ; i < argc -2 ; i++) {
   	if (strncmp(argv[i],"/G",2) == 0) {
         strcpy(voice,&argv[i][3]) ; }
   	if (strncmp(argv[i],"/D",2) == 0) {
         strcpy(invbuffer,&argv[i][3]) ; }
   	if (strncmp(argv[i],"/O",2) == 0) {
         strcpy(outbuffer,&argv[i][3]) ; }
   	if (strncmp(argv[i],"/T",2) == 0) {
         strcpy(type,&argv[i][3]) ; } }

   Txt2phoInit(path,voice,0) ;
	Txt2phoRun(argv[argc-1],argv[argc-2]) ;
   Txt2phoClose() ;
   if (strlen(invbuffer) > 0 && strlen(type) > 0) {
	   strcpy(buffer,"phoplayer ") ;
      if (strcpy(type,"wav") == 0 && strlen(outbuffer) > 0) {
      	strcat(buffer,"/O=") ;
         strcat(buffer,outbuffer) ;
         strcat(buffer," /T=wav ") ; }
      strcat(buffer,"database=") ;
      strcat(buffer,invbuffer) ;
      strcat(buffer," ") ;
      strcat(buffer,argv[argc-1]) ;
//      printf("%s\n",buffer) ;
	   system(buffer) ; }
	return(0) ; }

