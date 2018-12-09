/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#ifndef _PPCTGSTR_H_
#define _PPCTGSTR_H_

#include "PPCStrin.h"
#include "PPCConte.h"

class PPCategorystring
{

        PPCString* str ;
        PPCContext** con ;
        int contextnr ;

    public:

        PPCategorystring(char* in) ;
        ~PPCategorystring() ;
        void list(FILE* lf) ;
        int find(char* in, int tokenstart, int &left, PPRulecharlist &rcl) ;
} ;

#endif
