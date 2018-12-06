/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPABBLST_H_
#define _PPABBLST_H_
#include <stdio.h>

class PPAbbreviationlist {

	char* abbreviations ;

public:

	PPAbbreviationlist(FILE* abbfile) ;
   ~PPAbbreviationlist() ;
   char* apply(char* in) ; } ;

#endif
