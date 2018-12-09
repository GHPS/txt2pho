/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#ifndef _PPRULLST_H_
#define _PPRULLST_H_

#include <stdio.h>
#include "PPRule.h"
#include "PPRlchls.h"

class PPRulelist
{

        PPRule** rulelist ;
        int rulenr ;
        PPRulecharlist rcl ;

    public:

        PPRulelist(FILE* rf) ;
        ~PPRulelist() ;
        void list(FILE* lf) ;
        char* apply(char* in, int tokenstart) ;
} ;

#endif


