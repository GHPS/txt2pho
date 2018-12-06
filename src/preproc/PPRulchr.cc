/* Copyright (C) 1998  Thomas Portele


*/
#include "PPRulchr.h"
#include <stdlib.h>
#include <string.h>
#include "PPdebug.h"

PPRulechars::PPRulechars(char* in) {
   unsigned int i,j ;
   key = '\0' ;
   member = NULL ;
   for (i = 0 ; i < strlen(in) ; i++)
   	if (in[i] != ' ' && key == '\0') {
      	key = in[i] ; break ; }
	i++ ;
	while (i < strlen(in)) {
   	if (in[i] == ':')
      	break ;
      i++ ; }
   i++ ;
   while (i < strlen(in)) {
   	if (in[i] != ' ' && in[i] != 0x09)
      	break ;
      i++ ;}
   j = i ;
   while (i < strlen(in)) {
   	if (in[i] == ' ' || in[i] == 0x09 || in[i] == '\0' || in[i] == 0x0a || in[i] == 0x0d)
      	break ;
      i++ ;}
	member = new char[i+2-j] ;
   in[i] = '\0' ;
   strcpy(member,&in[j]) ; }

PPRulechars::~PPRulechars() {
	if (member != NULL)
   	delete(member) ; }

int PPRulechars::is_member(char c) {

	if (strchr(member,c) != NULL)
   	return(1) ;
   return(0) ; }

void PPRulechars::list(FILE* lf) {
	fprintf(lf,"KEY: %c  MEMBERS: %s\n",key,member) ; }
