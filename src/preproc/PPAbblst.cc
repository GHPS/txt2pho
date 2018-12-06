/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/* Copyright (C) 1998  Thomas Portele


*/
#include "PPAbblst.h"
#include "PPdebug.h"
#include <string.h>

PPAbbreviationlist::PPAbbreviationlist(FILE* abbfile) {

	abbreviations = NULL ;

   char buffer[512] ;
	fseek(abbfile,0L,SEEK_END) ;
   long length = ftell(abbfile) ;
   if (length > 65526) {
   	fprintf(errfile,"LENGTH OF ABBREVIATIONLIST EXCEEDS 65526\n") ;
   	return; }

   rewind(abbfile) ;
   abbreviations = new char[length+10] ;
   strcpy(abbreviations,"") ;
   while (fgets(buffer,511,abbfile) != NULL) {
   	if (buffer[0] == '#' || strlen(buffer) < 3)
      	continue ;
      strcat(abbreviations,buffer) ; }
   return ; }

PPAbbreviationlist::~PPAbbreviationlist() {
	if (abbreviations != NULL)
   	delete(abbreviations) ; }


char* PPAbbreviationlist::apply(char* in) {
   char* r;
   unsigned int i,j ;
   char v ;
   char* result ;

   char* tmp = new char[strlen(in)+2] ;
   strcpy(tmp,in) ;

   if (strncmp(in,"street(",7) == 0)
     {
       strcpy(tmp,&in[7]) ;
       tmp[strlen(tmp)-1] = '\0' ;
     }

	if ((r = strstr(abbreviations,tmp)) == NULL) 
	  { delete[] tmp ;
	  return(in) ; }
	while (r != NULL) {
	  if (r == abbreviations || r[-1] == '\n')
	    break ;
	  r = strstr(r+1,tmp) ; }
	if (r == NULL) {
	  delete[] tmp ;
	  return(in) ; }
	for (i = 0 ; i < strlen(r) ; i++)
	  if (r[i] == 0x09)
	    break ;
	if (i != strlen(tmp)) {
	  delete[] tmp ;
	  return(in) ; }
	i++ ;
	for (j=0 ; j < strlen(&r[i]) ; j++)
	  if (r[j] == '\n')
	    break ;
	v = r[j] ;
	r[j] = '\0' ;
	result = new char[j-i+2] ;
	strcpy(result,&r[i]) ;
	r[j] = v ;
	delete(in) ;
	delete[] tmp ;
	return(result) ; }




