#include "tags.h"

Taglist::Taglist(char* path) {

  char dummy[256] ;
  char buffer[512] ;

  strcat(strcpy(dummy,path),"twhadi.aliases") ;

  FILE* in = fopen(dummy,"r") ;

  if (in == NULL) {
    fprintf(stderr,"Unable to open %s\n",dummy) ;
    voices = NULL ;
    voicealiases = 0 ; 
    return ; }

  voices = (char***)malloc(sizeof(char**)) ;

  while (fgets(buffer,255,in) != NULL) {
    if (buffer[0] == '#' || strlen(buffer) < 3)
      continue ;
    voices[voicealiases] = new char*[2] ;
    voices[voicealiases][0] = new char[strlen(buffer)] ;
    voices[voicealiases][1] = new char[strlen(buffer)] ;
    sscanf(buffer,"%s %s",voices[voicealiases][0],voices[voicealiases][1]) ;
    voicealiases++ ;
    voices = (char***) realloc(voices,sizeof(char**)*(voicealiases+1)) ; }

  return ; }

Taglist::~Taglist() {

  for (unsigned i = 0 ; i < voicealiases ; i++) {
    delete[] voices[i][0] ;
    delete[] voices[i][1] ;
    delete[] voices[i] ; }

  free(voices) ; }

int Taglist::change(char* in) {

  int language = 0 ;

  FILE* infile = fopen(in,"rb") ;

  if (infile == NULL) {
    fprintf(stderr,"Unable to open %s\n",in) ;
    return -1 ; }
 
  fseek(infile,0L,SEEK_END) ;

  long size = ftell(infile) ;

  rewind(infile) ;

  char* buffer = new char[size+3] ;
  char voicnam[256] ;

  fread(buffer,size,sizeof(char),infile) ;

  fclose(infile) ;

  if( strstr(buffer,"{Language:English}") != NULL)
    language = 1 ;

  strcat(in,".new") ;

  infile = fopen(in,"w") ;

  if (language != 1)
    fprintf(infile,"{UseCARTProminence:0} ") ;

  for (unsigned i =0 ; i < size ; i++) {
    
    /*
    if (strncmp(&buffer[i],"{Emphasis:on}",13) == 0) {
      fprintf(infile,"{WordProminence:25} ") ;
      i+=13 ;
      continue ; }
    if (strncmp(&buffer[i],"{Emphasis:off}",14) == 0) {
      fprintf(infile,"{ChangeWordProminence:0} ") ;
      i+=14 ;
      continue ; }
    */

    if (language == 1 && buffer[i] == '{') {
      do {
	i++ ; }
      while (buffer[i] != '}') ;
      continue ; }
	  

    if (strncmp(&buffer[i],"{Voice:",7) == 0) {
      fprintf(infile,"{Voice:") ;
      strncpy(voicnam,&buffer[i+7],255) ;
      for (unsigned j =0 ; j < 255 ; j++)
	if (voicnam[j] == '}') {
	  voicnam[j] = '\0' ;
	  break ; }
      for (unsigned j = 0 ; j < voicealiases ; j++) {
	if (strcmp(voices[j][0],voicnam) == 0) {
	  fprintf(infile,"%s} ",voices[j][1]) ;
	  break ; } }
      i+=8+strlen(voicnam) ;
      continue ; }
    
    fprintf(infile,"%c",buffer[i]) ; }

  delete[] buffer ;
  fclose(infile) ;
  return(language) ; }

  
