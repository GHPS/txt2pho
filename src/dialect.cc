/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "lisatalk.h"

#include "lexem.h"

#include <string.h>

extern const int SOUNDNR ;
extern int find_sound(char* &d) ;

const char* sylborder = "|" ;
static char ipasounds[87][4] =
{
    "p", "b", "b", "t", "d", "d", "k", "g", "g",				//Plosive
    "p", "b", "b", "t", "d", "d", "k", "g", "g", //Plosivpausen
    "m", "n", "N",													//Nasale
    "r", "r", "l", "l", "6",										//Liquide
    "?", "h", "h",													//Glottallaute
    "f", "v", "v", "z", "z", "s", "Z", "Z", "S", "C", "j", "j", "x", //Frikative
    "a", "I", "E", "9", "U", "Y", "O",								//Kurzvokale
    "a:", "e:", "i:", "o:", "u:", "E:", "y:", "2:", "O:", "9:",				//Langvokale
    "e", "i", "o", "u", "y", "2",
    "aI", "aU", "OY", "EI",											//Diphthonge
    "a~", "E~", "O~", "9~",											//Nasalvokale
    "@", "@", "@r", "@l", "@n", "@m", "@N",						//Schwa+Elision
    "<i", "<u", "<o",												//nichtsilbische Vokale
    "a~", "E~", "O~", "9~"
} ;								//Nasalvokale

int sampa2ipa(string &out, char* in)
{
    int i ;
    out = "";
    while (strlen(in) > 0)
    {
        if (in[0] == '|')
        {
            in++ ;
            out += sylborder;
            continue ;
        }
        if (in[0] == ',')
        {
            in++ ;
            out += ",";
            continue ;
        }
        if (in[0] == '\'')
        {
            in++ ;
            out += "\'";
            continue ;
        }
        if ((i = find_sound(in)) != -1)
            out += ipasounds[i];
        else
            in++ ;
    }
    return (1) ;
}


char* delchar(char* in, int pos)
{
    return ((char*)memmove(&in[pos], &in[pos+1], strlen(in)-pos)) ;
}
char* inschar(char* in, int pos, char c)
{
    memmove(&in[pos+1], &in[pos], strlen(in)-pos+1) ;
    in[pos] = c ;
    return (in) ;
}

int change_rhythm(string &out, char* r)
{
    int i= 0, j = 0 ;
    while (r[j] != '\0')
    {
        if (r[j] == out[i])
        {
            j++ ;
            while (out[i++] != '|') ;
            continue ;
        }
        if (r[j] == '-')
        {
            if (strchr(",\'", out[i]) != NULL)
            {
                out.erase(i, 1) ;
            }
            j++ ;
            while (out[i++] != '|') ;
            continue ;
        }
        if (strchr(",\'", out[i]) == 0)
        {
            out.insert(i, "\'");
        }
        else
        {
            out[i] = '\'' ;
        }
        j++ ;
        while (out[i++] != '|') ;
    }
    return (1) ;
}


#ifndef NGIMMICKS

int rheinisch (TLexem &lexem)
{
    int ortholen = lexem.chars.length() - 1;
    int translen = lexem.transcription.length() - 1;
    int i ;
    if (lexem.chars == "das")
    {
        lexem.transcription = "\'dat|";
        return (1) ;
    }
    if (lexem.chars == "was")
    {
        lexem.transcription = "\'vat|";
        return (1) ;
    }
    if (lexem.chars == "es")
    {
        lexem.transcription = "\'Et|";
        return (1) ;
    }
    if (lexem.chars == "der")
    {
        lexem.transcription = "\'d@|";
        return (1) ;
    }
    if (lexem.chars == "und")
    {
        lexem.transcription = "\'Un|";
        return (1) ;
    }
    if (lexem.chars == "da")
    {
        lexem.transcription = "\'dO:|";
        return (1) ;
    }
    if (lexem.chars == "nicht")
    {
        lexem.transcription = "\'nEt|";
        return (1) ;
    }
    if (lexem.chars == "ist")
    {
        lexem.transcription = "\'Is|";
        return (1) ;
    }
    if (lexem.chars[ortholen] == 'g')
    {
        if (strchr("auo", lexem.chars[ortholen-1]) == NULL)
        {
            for (i= translen; i < 0; i-- )
                if (lexem.transcription[i] == 'k')
                {
                    lexem.transcription[i] = 'S' ;
                }
        }
        else
            for (i= translen; i < 0; i-- )
                if (lexem.transcription[i] == 'k')
                {
                    lexem.transcription[i] = 'x' ;
                    if (lexem.transcription[i-1] == ':')
                    {
                        lexem.transcription.erase((size_t)(i - 1), size_t(1)) ;
                        translen = lexem.transcription.length() - 1 ;
                        if (lexem.transcription[i-2] == 'u')
                            lexem.transcription[i-2] = 'U' ;
                    }
                }
    }
    if (lexem.transcription[translen-1] == '@')
    {
        lexem.transcription.erase(size_t(translen - 1), size_t(1));
        translen = lexem.transcription.length() - 1 ;
    }
    #ifdef Windows
    while (lexem.transcription.find("pf|") != NPOS)
    {
    #else
    while (lexem.transcription.find("pf|") != string::npos)
    {
    #endif
        lexem.transcription.erase(size_t(lexem.transcription.find("pf|")), size_t( 1));
        translen = lexem.transcription.length() - 1 ;
    }
//	while (lexem.transcription.find("@n|") != string::npos)
//		lexem.transcription.erase(lexem.transcription.find("@n|"), 1);
//	while (lexem.transcription.find("@r|") != string::npos)
//		lexem.transcription.erase(lexem.transcription.find("@r|"), 1);
    for (i = 0 ; i <= translen ; i++)
    {
        if (lexem.transcription[i] == 'C')
            lexem.transcription[i] = 'S' ;
        if (lexem.transcription[i] == 'g')
            lexem.transcription[i] = 'j' ;
    }
    return (1) ;
}

int kanzler(TLexem &lexem)
{
    int ortholen = lexem.chars.length() - 1;
    int translen = lexem.transcription.length() - 1;
    int i ;
    if (lexem.chars[ortholen] == 'g')
    {
        if (strchr("auo", lexem.chars[ortholen-1]) == NULL)
        {
            for (i= translen; i < 0; i-- )
                if (lexem.transcription[i] == 'k')
                {
                    lexem.transcription[i] = 'S' ;
                }
        }
        else
            for (i= translen; i < 0; i-- )
                if (lexem.transcription[i] == 'k')
                {
                    lexem.transcription[i] = 'x' ;
                    if (lexem.transcription[i-1] == ':')
                    {
                        lexem.transcription.erase(i - 1, 1);
                        if (lexem.transcription[i-2] == 'u')
                            lexem.transcription[i-2] = 'U' ;
                    }
                }
    }
//	if (lexem.transcription[translen-1] == '@')
//		lexem.transcription.erase(translen - 1, 1);
//	while (lexem.transcription.find("pf|") != string::npos)
//		lexem.transcription.erase(lexem.transcription.find("pf|"), 1) ;
//	while (lexem.transcription.find("@n|") != string::npos)
//		lexem.transcription.erase(lexem.transcription.find("@n|"), 1);
    #ifdef Windows
    while (lexem.transcription.find("@r|") != NPOS)
    #else
    while (lexem.transcription.find("@r|") != string::npos)
    #endif
        lexem.transcription.replace(lexem.transcription.find("@r|"), 2, "O:");
    for (i = 0 ; i <= translen ; i++)
    {
        if (lexem.transcription[i] == 'C')
            lexem.transcription[i] = 'S' ;
        if (lexem.transcription[i] == 'b')
            lexem.transcription[i] = 'p' ;
        if (lexem.transcription[i] == 'd')
            lexem.transcription[i] = 't' ;
        if (lexem.transcription[i] == 'v')
            lexem.transcription[i] = 'f' ;
        if (lexem.transcription[i] == 'z')
            lexem.transcription[i] = 's' ;
        if (lexem.transcription[i] == 'g')
            lexem.transcription[i] = 'k' ;
    }
    return (1) ;
}

int make_dialect(TLexem &lexem, char* dialect)
{
    if (strcmp(dialect, "Rheinisch") == 0)
        return (rheinisch(lexem)) ;
    if (strcmp(dialect, "Kanzler") == 0)
        return (kanzler(lexem)) ;
    return (0) ;
}

#endif
