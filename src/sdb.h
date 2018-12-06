/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#ifndef __sdb2_HEADER__
#define __sdb2_HEADER__


typedef struct
{
    float LAUTDUR;
    float ACAT;
    char* FACCE;
    char* LANGKURZ;
    char* VOKAL;
    char* KONS_ART;
    char* VOR_HIN;
    char* OF_GE;
    char* GERUNDET;
    char* SH_SL;
    char* FOSO;
    char* PHR_POS;
    float PLDISVH;
    float PLIDS;
    float SONR;
    char* STRESS;
} sdb2_struct ;

extern float sdb2_wagon_comp(sdb2_struct &st) ;

#endif
