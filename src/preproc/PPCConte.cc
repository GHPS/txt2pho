/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "PPCConte.h"
#include <stdlib.h>
#include <string.h>
#include "PPdebug.h"

int is_other_sign(char c)
{
    if (strchr("?!.,;:-_+ ", c) != NULL)
        return (1) ;
    return (0) ;
}


char* find_other_sign(char* in)
{
    while (is_other_sign(*in) ==0)
    {
        if (*in == '\0')
            return (NULL) ;
        in++ ;
    }
    return (in) ;
}

extern char* get_tokenend(char* in) ;

char* get_next_token(char* in)
{
    while (is_other_sign(*in)==0)
    {
        if (*in == '\0')
            return (NULL) ;
        in++ ;
    }
    while (is_other_sign(*in)==1)
    {
        if (*in == '\0')
            return (NULL) ;
        in++ ;
    }
    return (in) ;
}

char* get_last_token(char* in, char* ori)
{
    while (is_other_sign(*in)==0)
    {
        if (*in == '\0' || in < ori)
            return (NULL) ;
        in-- ;
    }
    while (is_other_sign(*in)!=0)
    {
        if (*in == '\0' || in < ori)
            return (NULL) ;
        in-- ;
    }
    while (is_other_sign(*in)==0)
    {
        if (*in == '\0' || in < ori)
            return (NULL) ;
        in-- ;
    }
    return (++in) ;
}

PPCContext::PPCContext(char* in, int d)
{
    direction = d ;
    char* c ;
    unsigned int i, j ;
    tliste = NULL ;
    tokennr = 0 ;
    cstr = NULL ;
    c = strstr(in, " IN ") ;
    if (c == NULL)
        scope = 1 ;
    else
    {
        c[0] = '\0' ;
        c += 4 ;
        scope = atoi(c) ;
    }
    if (in[0] == '\'')
    {
        tliste = (char**)malloc(sizeof(char*)) ;
        j = 1 ;
        for (i=1 ; i < strlen(&in[j])+j ; i++)
        {
            if (in[i] == '\'' || in[i] == ',')
            {
                tliste[tokennr] = new char[i-j+2] ;
                in[i] = '\0' ;
                strcpy(tliste[tokennr], &in[j]) ;
                tokennr++ ;
                tliste = (char**)realloc(tliste, sizeof(char*)*(tokennr+1)) ;
                j = i+1 ;
                continue ;
            }
        }
        if (i == strlen(in))
        {
            fprintf(errfile, "TOKEN %s HAS NO END\n", &in[j]) ;
        }
    }
    else
    {
        cstr = new PPCString(in) ;
    }
}

PPCContext::~PPCContext()
{
    if (cstr != NULL)
        delete (cstr) ;
    int i ;
    if (tliste != NULL)
    {
        for (i = 0 ; i < tokennr ; i++)
            delete (tliste[i]) ;
        free(tliste) ;
    }
}

void PPCContext::list(FILE* lf)
{
    int i ;
    if (cstr != NULL)
    {
        cstr->list(lf) ;
        fprintf(lf, " ") ;
    }
    else
    {
        for (i = 0 ; i < tokennr ; i++)
            fprintf(lf, "%s ", tliste[i]) ;
    }
    fprintf(lf, "DIRECTION %d SCOPE %d", direction, scope) ;
}

int PPCContext::is_valid(char* in, int tokenstart, PPRulecharlist &rcl)
{
    int i, j;
    char* v ;
    char* c ;
    char l = ' ' ;
    if (cstr != NULL)
    {
        if (direction == -1)
            return (cstr->find(in, tokenstart-2, -1, j, rcl)) ;
        v = get_tokenend(&in[tokenstart]) ;
        if (v == NULL)
            return (0) ;
        v = get_next_token(v) ;
        if (v == NULL)
            return (0) ;
        if (scope > 1)
        {
            fprintf(errfile, "SCOPE > 1 NOT SUPPORTED FOR CATEGORYSTRING\n") ;
        }
        return (cstr->find(v, 0, 1, j, rcl)) ;
    }
    v = &in[tokenstart] ;
    if (direction != -1)
    {
        v = get_tokenend(v) ;
        v-- ;
    }
    for (i=0 ; i < scope ; i++)
    {
        if (direction == -1)
            v = get_last_token(v, in) ;
        else
            v = get_next_token(v) ;
        if (v == NULL)
            return (0) ;
        c = find_other_sign(v) ;
        if (c != NULL)
        {
            l = c[0] ;
            c[0] = '\0' ;
        }
        for (j = 0 ; j < tokennr ; j++)
        {
            if (strcmp(v, tliste[j]) == 0)
            {
                if (c != NULL)
                    c[0] = l ;
                return (1) ;
            }
        }
        if (c != NULL)
            c[0] = l ;
    }
    return (0) ;
}





