/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(WRDCLASS_HEADER)
#define WRDCLASS_HEADER


#ifdef _Windows
    #include <cstring.h>
#else
    #include <string>
#endif



#include "file.h"


////////////////////////////////////////////////////////////////////////////////////////

typedef enum
{
    NOM, NAM, QPV, QAN, QPN, QAV, VRB, VEM, VEH, VES, VEW, ART, PRO, PPR, ADD, SBJ, KNJ,
    VKN, KKN, TME,
    NEG, NUM, RFW, MOD, INJ, KMP, NumberOfWordClasses, Unknown, Error, Last_TWordClass
} TWordClass ;


typedef enum
{
    PP, VP, NP, VI, TNP, TPP, TVP, TVI, satzende, teilsatzende, emphase, invalid, Unknowne, Errore
} TPhrKons ;

typedef enum
{
    aussage, befehl, wfrage, efrage, garnix
} TSentenceType ;

////////////////////////////////////////////////////////////////////////////////////////

string wcl2str (TWordClass wcl);
string wcl2str (short cnt_wcls, const TWordClass* wcls);
TWordClass str2wcl (const string &str);


#endif

