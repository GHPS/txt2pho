/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*  Copyright (C) 1998  Thomas Portele


*/
#include "PPRule.h"
#include <string.h>
#include "PPdebug.h"

PPRule::PPRule(char* in)
{
    char* c ;
    cs = NULL ;
    cl = NULL ;
    c = strstr(in, " AS ") ;
    if (c== NULL)
    {
        fprintf(errfile, "Keyword AS missing in %s\n", in) ;
        return ;
    }
    c[0] = '\0' ;
    c = c+4 ;
    cs = new PPCategorystring(in) ;
    cl = new PPCategorylist(c) ;
}

PPRule::~PPRule()
{
    if (cs != NULL)
        delete (cs) ;
    if (cl != NULL)
        delete (cl) ;
}

void PPRule::list(FILE* lf)
{
    if (cs != NULL)
        cs->list(lf) ;
    fprintf(lf, " AS ") ;
    if (cl != NULL)
        cl->list(lf) ;
    fprintf(lf, "\n") ;
}

char* PPRule::apply(char* in, int tokenstart, int &success, PPRulecharlist &rcl)
{
    int left ;
    if (cs == NULL || cl == NULL)
    {
        success = 0 ;
        return (in) ;
    }
    if (cs->find(in, tokenstart, left, rcl) == 0)
    {
        success = 0 ;
        return (in) ;
    }
    success = 1 ;
    char* out = new char[strlen(in)+ cl->length()+6] ;
    int i ;
    char ll ;
    ll = in[left+tokenstart] ;
    in[left+tokenstart] = '\0' ;
    if (ll != ' ')
    {
        for (i = left+tokenstart+1 ; i < (int)strlen(&in[left+tokenstart+1])+left+tokenstart+1 ; i++)
            if (in[i] == ' ')
            {
                in[i] = '\0' ;
                break ;
            }
        sprintf(out, "%s(%s) %c%s", cl->get_value(), &in[tokenstart], ll, &in[left+tokenstart+1]) ;
    }
    else
    {
        sprintf(out, "%s(%s)", cl->get_value(), &in[tokenstart]) ;
    }
    delete (in) ;
    return (out) ;
}





