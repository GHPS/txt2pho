/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPRULLST_H_
#define _PPRULLST_H_

#include <stdio.h>
#include "PPRule.h"
#include "PPRlchls.h"

class PPRulelist {

		PPRule** rulelist ;
      int rulenr ;
      PPRulecharlist rcl ;

	public:

   	PPRulelist(FILE* rf) ;
      ~PPRulelist() ;
      void list(FILE* lf) ;
      char* apply(char* in,int tokenstart) ; } ;

#endif


