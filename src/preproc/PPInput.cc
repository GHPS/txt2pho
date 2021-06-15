/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "PPInput.h"
#include "PPdebug.h"
#include <string.h>

int space(char a)
{
    if (a=='\n' || a == '\t' || a == ' ')
        return (1) ;
    return (0) ;
}

int move_string(char* in, int length, int &pos, int &z)
{
    int i ;
    for (i=0 ; i < length; i++)
        if (space(in[i]) == 1)
            break ;
    if (i == length)
    {
        fprintf(errfile, "TOKEN TOO LONG %s\n", in) ;
        in[0] = '\0' ;
        return (0) ;
    }
    int j ;
    for (j=i+1 ; j < length ; j++)
        in[j-(i+1)] = in[j] ;
    pos -= (i+1) ;
    z -= (i+1) ;
    return (length - (i+1)) ;
}

char PPInput::get_next_char(FILE* infile, char* spacer)
{
    if (infile == NULL)
        return ('\0') ;
    if (lastz == '\0' && !feof(infile))
    {
        lastz = (int)fgetc(infile) ;
        return (lastz) ;
    }
    if (z == '\0' && !feof(infile))
        z = (int)fgetc(infile) ;
    if (noget == 1)
    {
        noget = 0 ;
        lastz = z ;
        if (space(nextz) == 0)
        {
            noget = 2 ;
            z = ' ';
        }
        else
            z = nextz ;
        return (lastz) ;
    }
    if (noget == 2)
    {
        noget = 0 ;
        lastz = z ;
        z = nextz ;
        return (' ') ;
    }
    if (feof(infile))
        nextz = '\0' ;
    else
        nextz = (int)fgetc(infile) ;
    while (space(z) && space(nextz) && !feof(infile))
    {
        nextz = (int)fgetc(infile) ;
    }
//	if (strchr(",.:?!;",z) != NULL && strchr(",.:?!;",nextz) != NULL) {
//   	noget = 2 ; }
    if (spacer != NULL && strchr(spacer, z) != NULL)
    {
        if (space(lastz) == 0)
        {
            noget = 1 ;
            return (' ') ;
        }
        if (space(nextz) == 0)
            noget = 2 ;
    }
    lastz = z ;
    z = nextz ;
    return (lastz) ;
}

PPInput::PPInput(const char* i, const char* sp)
{
    spacer = strdup(sp);
    if (strcmp(i, "-") == 0)
        in = stdin ;
    else
        in = fopen(i, "r") ;
    if (in == NULL)
    {
        fprintf(errfile, "Cannot open %s\n", i) ;
    }
    noget = 0 ;
    stop = 0 ;
    z = '\0' ;
    nextz = '\0' ;
    lastz = '\0' ;
    size = 1024 ;
    actpos = 0 ;
    lastactpos = 0 ;
    actstart = 0 ;
    current = new char[size] ;
}


PPInput::~PPInput()
{
    if (in != NULL && in != stdin)
        fclose(in) ;
    delete (current) ;
}


char* PPInput::get_next_token(int &pos)
{
    char z ;
    if (feof(in))
        return (NULL) ;
    actstart = actpos ;
    while (z = get_next_char(in, spacer), space(z) == 0)
    {
        while (actpos >= size-64)
        {
            actpos = move_string(current, actpos, actstart, lastactpos) ;
        }
        if (z == '\0')
        {
            break ;
        }
        current[actpos++] = z ;
    }
    current[actpos] = ' ' ;
    current[actpos+1] = '\0' ;
    pos = actstart ;
    return (current) ;
}

char* PPInput::get_next_token_with_lookahead(int &pos)
{
    char z ;
    if (stop && actstart == -1)
        return (NULL) ;
    if (stop)
    {
        while ((z = get_next_char(in, spacer)) != '\0' && z!= -1)
            current[actpos++] = z ;
        current[actpos] = '\0' ;
        pos = lastactpos ;
        char* result = new char[strlen(current)+1] ;
        strcpy(result, current) ;
        actstart = -1 ;
        return (result) ;
    }
    actstart = lastactpos ;
    if (actpos == 0)
    {
        while (z = get_next_char(in, spacer), space(z) != 0) ;
        current[actpos++] = z ;
        while (z = get_next_char(in, spacer), space(z) == 0)
        {
            while (actpos >= size-5)
            {
                actpos = move_string(current, actpos, actstart, lastactpos) ;
            }
            if (z == '\0' || z == -1)
            {
                break ;
            }
            current[actpos++] = z ;
        }
        current[actpos++] = ' ' ;
    }
    lastactpos = actpos ;
    while (z = get_next_char(in, spacer), space(z) == 0)
    {
        if (actpos >= size-5)
            actpos = move_string(current, actpos, actstart, lastactpos) ;
        if (z == '\0' || z == -1)
        {
            break ;
        }
        current[actpos++] = z ;
    }
    current[actpos++] = ' ' ;
    current[actpos] = '\0' ;
    pos = actstart ;
    char* result = new char[strlen(current)+1] ;
    strcpy(result, current) ;
    if (z == '\0' || z == -1)
        stop = 1 ;
    return (result) ;
}

