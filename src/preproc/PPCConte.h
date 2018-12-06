/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPCCONTE_H_
#define _PPCCONTE_H_

#include "PPCStrin.h"

class PPCContext {

	PPCString* cstr ;
   char** tliste ;
   int tokennr ;
   int direction ;
   int scope ;

public:

	PPCContext(char* in, int d) ;
   ~PPCContext() ;
   int is_valid(char*in, int tokenstart,PPRulecharlist& rcl) ;
   void list(FILE* lf) ; } ;

#endif

