/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*  Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPRLCHLS_H_
#define _PPRLCHLS_H_
#include <stdio.h>
#include "PPRulchr.h"

class PPRulecharlist
{

        PPRulechars** lst ;
        int listnumber ;

    public:

        PPRulecharlist() ;
        ~PPRulecharlist() ;
        void list(FILE* lf) ;
        int add(char* in) ;
        int check(char key, char c) ;
} ;

#endif
