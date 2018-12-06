/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*  Copyright (C) 1998  Thomas Portele


*/
#include "PPCtgstr.h"
#include <string.h>
#include <stdlib.h>

PPCategorystring::PPCategorystring(char* in)
{
    str = NULL ;
    con = NULL ;
    contextnr = 0 ;
    char* c ;
    int r ;
    char* v ;
    if ((c = strstr(in, " BEFORE ")) == NULL)
    {
        c = strstr(in, " AFTER ") ;
    }
    if (c != NULL)
    {
        con = (PPCContext**)malloc(sizeof(PPCContext*)) ;
        do
        {
            c[0] = '\0' ;
            if (c[1] == 'B')
            {
                r = 1 ;
                c += 8 ;
            }
            else
            {
                r = -1 ;
                c += 7 ;
            }
            if ((v = strstr(c, " BEFORE ")) == NULL)
            {
                v = strstr(c, " AFTER ") ;
            }
            if (v != NULL)
                v[0] = '\0' ;
            con[contextnr++] = new PPCContext(c, r) ;
            con = (PPCContext**)realloc(con, sizeof(PPCContext*)*(contextnr+1)) ;
            c = v ;
        } while (c != NULL) ;
    }
    str = new PPCString(in) ;
}

PPCategorystring::~PPCategorystring()
{
    int i ;
    if (con != NULL)
    {
        for (i=0 ; i < contextnr ; i++)
            delete (con[i]) ;
        free(con) ;
    }
    delete (str) ;
}

void PPCategorystring::list(FILE* lf)
{
    str->list(lf) ;
    fprintf(lf, " ") ;
    int i ;
    for (i=0 ; i < contextnr ; i++)
    {
        con[i]->list(lf) ;
        fprintf(lf, " ") ;
    }
}

int PPCategorystring::find(char* in, int tokenstart, int &left, PPRulecharlist &rcl)
{
    if (str->find(in, tokenstart, 0, left, rcl) == 0)
        return (0) ;
    if (con == NULL)
        return (1) ;
    int i ;
    for (i=0 ; i < contextnr ; i++)
        if (con[i]->is_valid(in, tokenstart, rcl) == 0)
            return (0) ;
    return (1) ;
}
