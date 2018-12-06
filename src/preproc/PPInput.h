/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPINPUT_H_
#define _PPINPUT_H_
#include <stdio.h>

class PPInput {

   char* spacer ;
   int size ;
   int actpos ;
   int lastactpos ;
   int actstart ;
   FILE* in ;
   char* current ;
   int noget ;
   char lastz, z, nextz ;
   int stop ;
   char get_next_char(FILE*, char*) ;

 public:

   PPInput(const char* i, const char* sp) ;
   ~PPInput() ;
   char* get_next_token(int& pos) ;
   char* get_next_token_with_lookahead(int& pos) ; } ;

#endif   
