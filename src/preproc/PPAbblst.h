/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#ifndef _PPABBLST_H_
#define _PPABBLST_H_
#include <stdio.h>

class PPAbbreviationlist
{

        char* abbreviations ;

    public:

        PPAbbreviationlist(FILE* abbfile) ;
        ~PPAbbreviationlist() ;
        char* apply(char* in) ;
} ;

#endif
