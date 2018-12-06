/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPCTGSTR_H_
#define _PPCTGSTR_H_

#include "PPCStrin.h"
#include "PPCConte.h"

class PPCategorystring {

	PPCString* str ;
   PPCContext** con ;
   int contextnr ;

public:

	PPCategorystring(char* in) ;
   ~PPCategorystring() ;
   void list(FILE* lf) ;
   int find(char* in, int tokenstart, int& left, PPRulecharlist& rcl) ; } ;

#endif
