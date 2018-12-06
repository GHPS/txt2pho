/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*  Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPCCONTE_H_
#define _PPCCONTE_H_

#include "PPCStrin.h"

class PPCContext
{

        PPCString* cstr ;
        char** tliste ;
        int tokennr ;
        int direction ;
        int scope ;

    public:

        PPCContext(char* in, int d) ;
        ~PPCContext() ;
        int is_valid(char* in, int tokenstart, PPRulecharlist &rcl) ;
        void list(FILE* lf) ;
} ;

#endif

