/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#ifdef PHONDURNET
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "phdurnn.h"
#include "lisatalk.h"

#include "vokale.h"
#ifdef Windows
    #include "konsonanten.h"
#else
    #include "konsonanten.h"
#endif

#include "sdb.h"

#ifdef IPHONDURNET

    #include "a.h"
    #include "oo.h"
    #include "aa.h"
    #include "schwa.h"
    #include "i.h"
    #include "oe.h"
    #include "oeh.h"
    #include "oy.h"
    #include "y.h"
    #include "f.h"
    #include "h.h"
    #include "j.h"
    #include "n.h"
    #include "r.h"
    #include "vokr.h"
    #include "z.h"

#endif

//#define DEBUG1

#define FINLEN 1.0

const int INPARS = 33 ;
const int OUTPARS = 1 ;
const char* indatanames[INPARS] = {"TYP", "ACAT", "ACC_PH_P", "FACCE", "STRESS", "B_ONC", "B_WORTAR",
                                   "FL_ARTAR", "PDISS", "FL_GERUN", "FL_OF_GE", "PL_VO_HI", "SONR", "BEATP", "BEATC",
                                   "FL_SH_SL", "FL_VO_HI", "FOSO", "GERUNDET", "HOCHTIEF", "LANGKURZ", "OF_GE",
                                   "VOR_HIN", "SH_SL", "KONS_ART", "PHR_POS", "PLDISVH", "PLIDS",
                                   "PL_ARTAR", "PL_GERUN", "PL_OF_GE", "PL_SH_SL", "BODI"
                                  } ;
const char* outdatanames[OUTPARS] = {"LAUTDUR"} ;




int get_value(DBSyll* d, int i)
{
    switch (i)
    {
        case 0 :
            return (d->typ) ;
            break ;
        case 5 :
            return (1) ;
            break ;
        case 1 :
            return (d->acat) ;
            break ;
        case 6 :
            return (1) ;
            break ;
        case 3 :
            return (d->facce) ;
            break ;
        case 4 :
            return (d->stress) ;
            break ;
        case 7 :
            return (1) ;
            break ;
        case 9 :
            return (1) ;
            break ;
        case 10 :
            return (1) ;
            break ;
        case 8 :
            return (d->pdiss) ;
            break ;
        case 11 :
            return (1) ;
            break ;
        case 12 :
            return (d->sonr) ;
            break ;
        case 13 :
            return (d->beatp) ;
            break ;
        case 14 :
            return (d->beatc) ;
            break ;
        case 15 :
            return (1) ;
            break ;
        case 16 :
            return (1) ;
            break ;
        case 17 :
            return (d->coso) ;
            break ;
        case 18 :
            return (1) ;
            break ;
        case 19 :
            return (1) ;
            break ;
        case 20 :
            return (1) ;
            break ;
        case 21 :
            return (1) ;
            break ;
        case 22 :
            return (1) ;
            break ;
        case 23 :
            return (1) ;
            break ;
        case 24 :
            return (1) ;
            break ;
        case 25 :
            return (d->phraspos) ;
            break ;
        case 26 :
            return (1) ;
            break ;
        case 27 :
            return (1) ;
            break ;
        case 2 :
            return (d->pacatbo) ;
            break ;
        case 29 :
            return (1) ;
            break ;
        case 30 :
            return (1) ;
            break ;
        case 31 :
            return (1) ;
            break ;
        case 32 :
            return (d->bodi) ;
            break ;
        default:
            return (1) ;
    }
    return (0) ;
}



int findname(const char** liste, int listlen, char* key)
{
    int i ;
    for (i = 0 ; i < listlen ; i++)
    {
        if (strcmp(liste[i], key) == 0)
            return (i) ;
    }
    return (-1) ;
}

float adjust(int v, float minval, float maxval)
{
    float value = (float)v ;
    if (maxval == minval)
        return (0.0) ;
    if (value > maxval)
        value = maxval ;
    if (value < minval)
        value = minval ;
    return ((value-minval)/(maxval-minval)) ;
}

float readjust(float value, float minval, float maxval)
{
    return (value*(maxval-minval)+minval) ;
}

int get_wc(char* wcs)
{
    if (strcmp(wcs, "NOM") == 0)
        return (7) ;
    if (strcmp(wcs, "NAM") == 0)
        return (5) ;
    if (strcmp(wcs, "QPN") == 0)
        return (10) ;
    if (strcmp(wcs, "QAN") == 0)
        return (11) ;
    if (strcmp(wcs, "QPV") == 0)
        return (12) ;
    if (strcmp(wcs, "QAV") == 0)
        return (13) ;
    if (strcmp(wcs, "VRB") == 0)
        return (20) ;
    if (strcmp(wcs, "VEM") == 0)
        return (17) ;
    if (strcmp(wcs, "VEH") == 0)
        return (16) ;
    if (strcmp(wcs, "VES") == 0)
        return (18) ;
    if (strcmp(wcs, "VEW") == 0)
        return (19) ;
    if (strcmp(wcs, "ART") == 0)
        return (1) ;
    if (strcmp(wcs, "PRO") == 0)
        return (9) ;
    if (strcmp(wcs, "PPR") == 0)
        return (21) ;
    if (strcmp(wcs, "VKN") == 0)
        return (22) ;
    if (strcmp(wcs, "KKN") == 0)
        return (23) ;
    if (strcmp(wcs, "ADD") == 0)
        return (0) ;
    if (strcmp(wcs, "SBJ") == 0)
        return (14) ;
    if (strcmp(wcs, "KNJ") == 0)
        return (3) ;
    if (strcmp(wcs, "TME") == 0)
        return (15) ;
    if (strcmp(wcs, "NEG") == 0)
        return (6) ;
    if (strcmp(wcs, "NUM") == 0)
        return (8) ;
    if (strcmp(wcs, "RFW") == 0)
        return (20) ;
    if (strcmp(wcs, "MOD") == 0)
        return (4) ;
    if (strcmp(wcs, "INJ") == 0)
        return (2) ;
    return (5) ;
}

typedef struct
{
    int vokkns ;
    int gerundet ;
    int of_ge ;
    int sh_sl ;
    int vor_hin ;
    int hochtief ;
    int langkurz ;
    int kons_art ;
} Phonfeatures ;


int compute_features(Soundinfo* s, Phonfeatures &f)
{
    f.vokkns = 0 ;
    f.hochtief = 0 ;
    f.langkurz = 0 ;
    f.vor_hin = 0 ;
    f. gerundet = 0 ;
    f.of_ge = 0 ;
    f.sh_sl = 0 ;
    f.kons_art = 0 ;
    if (strchr("aeiouEIOUyY29=@", s->name[0]) != NULL)
        f.vokkns = 1 ;
    if (strchr("iIuUyY", s->name[0]) != NULL)
        f.hochtief = 1 ;
    else
        f.hochtief = 2 ;
    if (s->name[0] == '@' || s->name[0] == '=')
        f.langkurz = 4 ;
    else if (strlen(s->name) < 2)
        f.langkurz = 3 ;
    else if (s->name[1] == ':')
        f.langkurz = 2 ;
    else
        f.langkurz = 1 ;
    if (strchr("iIeE29yY", s->name[0]) != NULL)
        f.vor_hin = 1 ;
    else if (strchr("oOuU", s->name[0]) != NULL)
        f.vor_hin = 3 ;
    else
        f.vor_hin = 2 ;
    switch (s->name[0])
    {
        case '?' :
        case '_' :
            f.kons_art = 4 ;
            break ;
        case 'v' :
        case 'z' :
        case 'Z' :
        case 'j' :
        case 'f' :
        case 's' :
        case 'S' :
        case 'C' :
        case 'x' :
            f.kons_art = 1 ;
            break ;
        case 'm' :
        case 'n' :
        case 'N' :
        case 'l' :
        case 'R' :
        case 'h' :
            f.kons_art = 2 ;
            break ;
        case 'b' :
        case 'd' :
        case 'g' :
        case 'p' :
        case 't' :
        case 'k' :
            f.kons_art = 3 ;
            break ;
        default :
            f.kons_art = 0 ;
    }
    if (strchr("iyu", s->name[0]) != NULL)
        f.of_ge = 4 ;
    else if (strchr("e2oIYU", s->name[0]) != NULL)
        f.of_ge = 3 ;
    else if (strchr("E9O@=6", s->name[0]) != NULL)
        f.of_ge = 2 ;
    else
        f.of_ge = 1 ;
    if (strchr("29yYoOuU", s->name[0]) != NULL)
        f.gerundet = 1 ;
    else
        f.gerundet = 0 ;
    if (strchr("bdgvzZjnmNlR", s->name[0]) != NULL)
        f.sh_sl = 1 ;
    else
        f.sh_sl = 0 ;
    if (f.vokkns == 0)
    {
        f.hochtief = 0 ;
        f.langkurz = 0 ;
        f.gerundet = 0 ;
        f.of_ge = 0 ;
        f.vor_hin = 0 ;
    }
    else
    {
        f.sh_sl = 0 ;
        f.kons_art = 0 ;
    }
//	fprintf(errfile,"SOUND %s VOKKNS %d GERUNDET %d HOCHTIEF %d LANGKURZ %d OF_GE %d VOR_HIN %d SH_SL %d KONS_ART %d\n",s->name,f.vokkns,f.gerundet,f.hochtief,f.langkurz,f.of_ge,f.vor_hin,f.sh_sl,f.kons_art) ;
    return (f.vokkns) ;
}


PhonNetz::PhonNetz(const char* vname, const char* kname, const char* path)
{
    char temp[2048] ;
    vinputvalues = NULL ;
    kinputvalues = NULL ;
    outputvalues = NULL ;
    strcat(strcpy(temp, path), vname) ;
    FILE* vparfile = FOPEN(temp, "r") ;
    if (vparfile == NULL)
    {
        fprintf(errfile, "Error while opening file %s\n", temp) ;
        fflush(errfile) ;
        return ;
    }
    strcat(strcpy(temp, path), kname) ;
    FILE* kparfile = FOPEN(temp, "r") ;
    if (kparfile == NULL)
    {
        fprintf(errfile, "Error while opening file %s\n", temp) ;
        fflush(errfile) ;
        return ;
    }
    int i, j ;
    char* pos, *actpos ;
    vinputvalues = new Condition[40] ;
    kinputvalues = new Condition[40] ;
    outputvalues = new Condition[5] ;
    vinputvaluenr = 0 ;
    kinputvaluenr = 0 ;
    outputvaluenr = 0;
    while (fgets(temp, 2047, vparfile) != NULL)
    {
        if (debuglevel > 4)
        {
            fprintf(errfile, "%s", temp) ;
            fflush(errfile) ;
        }
        if (strstr(temp, "Eingabeparameter:") != NULL)
        {
            pos = strstr(temp, "Eingabeparameter:")+ 18 ;
            while (*pos != '\n' && *pos != '\0')
            {
                while (*pos == ' ' || *pos == '\t')
                    pos++ ;
                actpos = pos ;
                while (*pos != '\n' && *pos != '\t' && *pos != ' ')
                    pos++ ;
                pos[0] = '\0' ;
                pos++ ;
                j = findname(indatanames, INPARS, actpos) ;
                if (j == -1)
                {
                    fprintf(errfile, "Variable %s nicht gefunden\n", actpos) ;
                    fflush(errfile) ;
                }
                else
                {
                    vinputvalues[vinputvaluenr].column = j ;
                }
                while (*pos != '(')
                    pos++ ;
                pos++ ;
                vinputvalues[vinputvaluenr].minval = atof(pos) ;
                while (*pos != ',')
                    pos ++ ;
                pos++ ;
                vinputvalues[vinputvaluenr++].maxval = atof(pos) ;
                while (*pos != ')')
                    pos ++ ;
                pos++ ;
            }
        }
        if (strstr(temp, "Ausgabeparameter:") != NULL)
        {
            pos = strstr(temp, "Ausgabeparameter:")+ 18 ;
            while (*pos != '\n' && *pos != '\0')
            {
                while (*pos == ' ' || *pos == '\t')
                    pos++ ;
                actpos = pos ;
                while (*pos != '\n' && *pos != '\t' && *pos != ' ')
                    pos++ ;
                pos[0] = '\0' ;
                pos++ ;
                j = findname(outdatanames, OUTPARS, actpos) ;
                if (j == -1)
                {
                    fprintf(errfile, "Variable %s nicht gefunden\n", actpos) ;
                    fflush(errfile) ;
                }
                else
                {
                    outputvalues[outputvaluenr].column = j ;
                }
                while (*pos != '(')
                    pos++ ;
                pos++ ;
                outputvalues[outputvaluenr].minval = atof(pos) ;
                while (*pos != ',')
                    pos ++ ;
                pos++ ;
                outputvalues[outputvaluenr++].maxval = atof(pos) ;
                while (*pos != ')')
                    pos ++ ;
                pos++ ;
            }
        }
    }
    while (fgets(temp, 2047, kparfile) != NULL)
    {
        if (strstr(temp, "Eingabeparameter:") != NULL)
        {
            pos = strstr(temp, "Eingabeparameter:")+ 18 ;
            while (*pos != '\n' && *pos != '\0')
            {
                while (*pos == ' ' || *pos == '\t')
                    pos++ ;
                actpos = pos ;
                while (*pos != '\n' && *pos != '\t' && *pos != ' ')
                    pos++ ;
                pos[0] = '\0' ;
                pos++ ;
                j = findname(indatanames, INPARS, actpos) ;
                if (j == -1)
                {
                    fprintf(errfile, "Variable %s nicht gefunden\n", actpos) ;
                    fflush(errfile) ;
                }
                else
                {
                    kinputvalues[kinputvaluenr].column = j ;
                }
                while (*pos != '(')
                    pos++ ;
                pos++ ;
                kinputvalues[kinputvaluenr].minval = atof(pos) ;
                while (*pos != ',')
                    pos ++ ;
                pos++ ;
                kinputvalues[kinputvaluenr++].maxval = atof(pos) ;
                while (*pos != ')')
                    pos ++ ;
                pos++ ;
            }
        }
    }
    if (debuglevel > 0)
    {
        fprintf(errfile, "Eingabeparameter Vokale: ") ;
        for (i=0 ; i < vinputvaluenr ; i++)
            fprintf(errfile, "%s(%f - %f) ", indatanames[vinputvalues[i].column], vinputvalues[i].minval, vinputvalues[i].maxval) ;
        fprintf(errfile, "\n") ;
        fprintf(errfile, "Eingabeparameter Konsonanten: ") ;
        for (i=0 ; i < kinputvaluenr ; i++)
            fprintf(errfile, "%s(%f - %f) ", indatanames[kinputvalues[i].column], kinputvalues[i].minval, kinputvalues[i].maxval) ;
        fprintf(errfile, "\n") ;
        fprintf(errfile, "Ausgabeparameter: ") ;
        for (i=0 ; i < outputvaluenr ; i++)
            fprintf(errfile, "%s(%f - %f) ", outdatanames[outputvalues[i].column], outputvalues[i].minval, outputvalues[i].maxval) ;
        fprintf(errfile, "\n") ;
        fflush(errfile) ;
    }
    voktsr = new TSR("vokale.tsr", path) ;
    kontsr = new TSR("kons.tsr", path) ;
    FCLOSE(vparfile) ;
    FCLOSE(kparfile) ;
}

PhonNetz::~PhonNetz()
{
    if (vinputvalues != NULL)
    {
        delete[](vinputvalues) ;
        delete[](kinputvalues) ;
        delete[](outputvalues) ;
    }
    delete (voktsr) ;
    delete (kontsr) ;
}

int PhonNetz::compute(Syllablelist* s, Soundlist* soli, DBSyllist* dbs, float sr, int use_net)
{
    if (vinputvalues == NULL)
        return (-1) ;
    int ix, jx ;
    int b_wordclass = 1 ;
    float* vinputvals = new float[vinputvaluenr] ;
    float* kinputvals = new float[kinputvaluenr] ;
    float* outputvals = new float[outputvaluenr] ;
    int b_onc = 2 ;
    float rate = sr ;
    char sdbbuf[16][16] ;
    sdb2_struct st ;
    soli->reset() ;
    dbs->reset() ;
    s->reset() ;
    DBSyll* d ;
    Soundinfo* sound = NULL ;
    Soundinfo* lastsound = NULL ;
    Soundinfo* nextsound = NULL ;
    Syllableinfo syll ;
    Phonfeatures lastsoundf, soundf, nextsoundf ;
    while ((syll = s->get_and_advance()).accent != -1)
    {
        if (strncmp(syll.type, "PGR", 3) == 0)
        {
            dbs->advance() ;
            sound = soli->get_sound_pointer(syll.firstsound) ;
            soli->advance() ;
            continue ;
        }
        if (strncmp(syll.type, "COM", 3) == 0)
        {
            if (strncmp("{WordClass:", syll.name, 11) == 0)
            {
                b_wordclass = get_wc(&syll.name[11]) ;
            }
            if (strncmp("{Duration:", syll.name, 10) == 0)
            {
                rate += atof(&syll.name[10]) ;
                if (rate < 0.3)
                    rate = 0.3 ;
                if (rate > 5.0)
                    rate = 5.0 ;
            }
            continue ;
        }
        if (strncmp(syll.type, "SIL", 3) != 0)
            continue ;
        d = dbs->get_db_pointer() ;
        dbs->advance() ;
        b_onc = 3 ;
        for (jx = 0 ; jx < syll.soundnr ; jx++)
        {
            if (b_onc == 2)
                b_onc = 1 ;
            lastsound = sound ;
            sound = soli->get_sound_pointer(syll.firstsound+jx) ;
            soli->advance() ;
            nextsound = soli->get_sound_pointer(syll.firstsound+jx+1) ;
            compute_features(lastsound, lastsoundf) ;
            compute_features(sound, soundf) ;
            compute_features(nextsound, nextsoundf) ;
            outputvals[0] = 0.0 ;
            if (soundf.vokkns == 1)
            {
                b_onc = 2 ;
                //				fprintf(errfile,"V %2s ",sound->name) ;
                for (ix = 0 ; ix < vinputvaluenr ; ix++)
                {
                    vinputvals[ix] = adjust(get_value(d, vinputvalues[ix].column), vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                    switch (vinputvalues[ix].column)
                    {
                        case 5:
                            vinputvals[ix] = adjust(b_onc, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 6:
                            vinputvals[ix] = adjust(b_wordclass, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 7:
                            vinputvals[ix] = adjust(nextsoundf.kons_art, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 9:
                            vinputvals[ix] = adjust(nextsoundf.gerundet, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 10:
                            vinputvals[ix] = adjust(nextsoundf.of_ge, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 11:
                            vinputvals[ix] = adjust(lastsoundf.vor_hin, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 15:
                            vinputvals[ix] = adjust(nextsoundf.sh_sl, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 16:
                            vinputvals[ix] = adjust(nextsoundf.vor_hin, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 18:
                            vinputvals[ix] = adjust(soundf.gerundet, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 19:
                            vinputvals[ix] = adjust(soundf.hochtief, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 20:
                            vinputvals[ix] = adjust(soundf.langkurz, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 21:
                            vinputvals[ix] = adjust(soundf.of_ge, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 22:
                            vinputvals[ix] = adjust(soundf.vor_hin, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 23:
                            vinputvals[ix] = adjust(soundf.sh_sl, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 24:
                            vinputvals[ix] = adjust(soundf.kons_art, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 26:
                            vinputvals[ix] = adjust(syll.soundnr-jx, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 27:
                            vinputvals[ix] = adjust(jx+1, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 28:
                            vinputvals[ix] = adjust(lastsoundf.kons_art, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 29:
                            vinputvals[ix] = adjust(lastsoundf.gerundet, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 30:
                            vinputvals[ix] = adjust(lastsoundf.of_ge, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                        case 31:
                            vinputvals[ix] = adjust(lastsoundf.sh_sl, vinputvalues[ix].minval, vinputvalues[ix].maxval) ;
                            break ;
                    }
                    //fprintf(errfile,"%5.3f ",vinputvals[ix]) ;
                } ;
                vokale(vinputvals, outputvals, 0) ;
                if (use_net == 3)
                {
                    outputvals[0] = voktsr->compute(vinputvals, 0) ;
                }
                #ifdef IPHONDURNET
                if (use_net == 2)
                {
                    if (strcmp(sound->name, "a") == 0)
                    {
                        //fprintf(errfile," im a-netz ") ;
                        a(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "9") == 0)
                    {
                        //fprintf(errfile," im 9-netz ") ;
                        oe(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "NULL") == 0)
                    {
                        //fprintf(errfile," im o:-netz ") ;
                        oo(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "a:") == 0)
                    {
                        //fprintf(errfile," im a:-netz ") ;
                        aa(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "@") == 0)
                    {
                        //fprintf(errfile," im @-netz ") ;
                        schwa(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "i") == 0)
                    {
                        //fprintf(errfile," im I-netz ") ;
                        i(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "2:") == 0)
                    {
                        //fprintf(errfile," im 2:-netz ") ;
                        oeh(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "OY") == 0)
                    {
                        //fprintf(errfile," im OY-netz ") ;
                        oy(vinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "Y") == 0)
                    {
                        //fprintf(errfile," im Y-netz ") ;
                        y(vinputvals, outputvals, 0) ;
                    }
                }
                #endif
            }
            //fprintf(errfile," -> %6.4f\n",outputvals[0]) ; }
            else
            {
                //fprintf(errfile,"K %2s ",sound->name) ;
                for (ix = 0 ; ix < kinputvaluenr ; ix++)
                {
                    kinputvals[ix] = adjust(get_value(d, kinputvalues[ix].column), kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                    switch (kinputvalues[ix].column)
                    {
                        case 5:
                            kinputvals[ix] = adjust(b_onc, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 6:
                            kinputvals[ix] = adjust(b_wordclass, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 7:
                            kinputvals[ix] = adjust(nextsoundf.kons_art, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 9:
                            kinputvals[ix] = adjust(nextsoundf.gerundet, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 10:
                            kinputvals[ix] = adjust(nextsoundf.of_ge, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 11:
                            kinputvals[ix] = adjust(lastsoundf.vor_hin, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 15:
                            kinputvals[ix] = adjust(nextsoundf.sh_sl, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 16:
                            kinputvals[ix] = adjust(nextsoundf.vor_hin, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 18:
                            kinputvals[ix] = adjust(soundf.gerundet, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 19:
                            kinputvals[ix] = adjust(soundf.hochtief, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 20:
                            kinputvals[ix] = adjust(soundf.langkurz, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 21:
                            kinputvals[ix] = adjust(soundf.of_ge, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 22:
                            kinputvals[ix] = adjust(soundf.vor_hin, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 23:
                            kinputvals[ix] = adjust(soundf.sh_sl, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 24:
                            kinputvals[ix] = adjust(soundf.kons_art, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 26:
                            kinputvals[ix] = adjust(syll.soundnr-jx, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 27:
                            kinputvals[ix] = adjust(jx+1, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 28:
                            kinputvals[ix] = adjust(lastsoundf.kons_art, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 29:
                            kinputvals[ix] = adjust(lastsoundf.gerundet, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 30:
                            kinputvals[ix] = adjust(lastsoundf.of_ge, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                        case 31:
                            kinputvals[ix] = adjust(lastsoundf.sh_sl, kinputvalues[ix].minval, kinputvalues[ix].maxval) ;
                            break ;
                    }
                    // 				fprintf(errfile,"%5.3f ",kinputvals[ix]) ;
                } ;
                konsonanten(kinputvals, outputvals, 0) ;
                if (use_net == 3)
                {
                    outputvals[0] = kontsr->compute(kinputvals, 0);
                }
                #ifdef IPHONDURNET
                if (use_net == 2)
                {
                    if (strcmp(sound->name, "f") == 0)
                    {
                        //	fprintf(errfile," im f-netz ") ;
                        f(kinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "h") == 0)
                    {
                        //fprintf(errfile," im h-netz ") ;
                        h(kinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "j") == 0)
                    {
                        //fprintf(errfile," im j-netz ") ;
                        j(kinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "n") == 0)
                    {
                        //fprintf(errfile," im n-netz ") ;
                        n(kinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "r") == 0)
                    {
                        //fprintf(errfile," im r-netz ") ;
                        r(kinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "6") == 0)
                    {
                        //fprintf(errfile," im 6-netz ") ;
                        vokr(kinputvals, outputvals, 0) ;
                    }
                    else if (strcmp(sound->name, "z") == 0)
                    {
                        //fprintf(errfile," im z-netz ") ;
                        z(kinputvals, outputvals, 0) ;
                    }
                }
                #endif
            }
            //fprintf(errfile," -> %6.4f\n",outputvals[0]) ; }
//			fprintf(errfile,"DURATION of %s changed from %d to %d (%f) \n",sound->name,sound->duration,(int)readjust(outputvals[0],outputvalues[0].minval,outputvalues[0].maxval),outputvals[0]) ;
            fflush(errfile) ;
            sound->duration = (int)(rate*readjust(outputvals[0], outputvalues[0].minval, outputvalues[0].maxval)) ;
            if (use_net == 4)
            {
                st.ACAT = float(d->acat) ;
                sprintf(sdbbuf[0], "%d", d->facce) ;
                st.FACCE = sdbbuf[0] ;
                sprintf(sdbbuf[1], "%d", soundf.langkurz) ;
                st.LANGKURZ = sdbbuf[1] ;
                sprintf(sdbbuf[2], "%d", soundf.vokkns) ;
                st.VOKAL = sdbbuf[2] ;
                sprintf(sdbbuf[3], "%d", soundf.kons_art) ;
                st.KONS_ART = sdbbuf[3] ;
                sprintf(sdbbuf[7], "%d", soundf.vor_hin) ;
                st.VOR_HIN = sdbbuf[7] ;
                sprintf(sdbbuf[8], "%d", soundf.of_ge) ;
                st.OF_GE = sdbbuf[8] ;
                sprintf(sdbbuf[9], "%d", soundf.gerundet) ;
                st.GERUNDET = sdbbuf[9] ;
                sprintf(sdbbuf[10], "%d", soundf.sh_sl) ;
                st.SH_SL = sdbbuf[10] ;
                sprintf(sdbbuf[4], "%d", d->coso) ;
                st.FOSO = sdbbuf[4] ;
                sprintf(sdbbuf[5], "%d", d->phraspos) ;
                st.PHR_POS = sdbbuf[5] ;
                st.PLDISVH = float(syll.soundnr -jx) ;
                st.PLIDS = float(jx+1) ;
                st.SONR = float(syll.soundnr) ;
                sprintf(sdbbuf[6], "%d", d->stress) ;
                st.STRESS = sdbbuf[6] ;
                sound->duration = (int)(rate*sdb2_wagon_comp(st)) ;
            }
            if (sound->duration < 15)
                sound->duration = 15 ;
            if (d->phraspos == -2 && soundf.vokkns == 1)
                sound->duration = int(float(sound->duration)*FINLEN) ;
        }
    }
    delete[](vinputvals) ;
    delete[](kinputvals) ;
    delete[](outputvals) ;
    return (1) ;
}

#endif







