/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPRULE_H_
#define _PPRULE_H_

#include "PPCtgstr.h"
#include "PPCtglst.h"

class PPRule {

	PPCategorystring* cs ;
   PPCategorylist* cl ;

public:

	PPRule(char* in) ;
   ~PPRule() ;
	void list(FILE* lf) ;
   char* apply(char* in, int tokenstart, int& success, PPRulecharlist& rcl) ; } ;

#endif


