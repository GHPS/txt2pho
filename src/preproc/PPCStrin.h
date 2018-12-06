/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPCSTRIN_H_
#define _PPCSTRIN_H_

#include "PPRlchls.h"
#include <stdio.h>

class PPCString {

	char* target ;

public:

	PPCString(char* in) ;
   ~PPCString() ;
   int find(char* in, int tokenstart, int direction, int& left, PPRulecharlist& rcl) ;
   void list(FILE* lf) ; } ;

#endif

