/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#include "lisatalk.h"
#ifdef Windows
    #include "promguess.h"
#else
    #include "promguess.h"
#endif

#if !defined(__SYLLABLE_H__)
    #include "syllable.h"
#endif

#include <string.h>

//#ifdef UNIX
extern char* strdup(char*) ;
//#endif

extern int get_wc(char* wcs) ;
extern int find_diphon_in_liste(char*, char*) ;

//#define DEBUG2

const int SOUNDNR = 87 ;
int dBval[SOUNDNR] =
{
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1,
    75, 75, 75,
    75, 1, 75, 1, 75,
    1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    75, 75, 75, 75, 75, 75, 75,
    75, 75, 75, 75, 75, 75, 75, 75,
    75, 75, 75, 75, 75, 75,
    75, 75, 75, 75, 75, 75,
    75, 75, 75, 75,
    75, 75, 75, 75, 75, 75, 75,
    1, 1, 1,
    75, 75, 75, 75
} ;
char sounds[SOUNDNR][4] =
{
    "p", "b", "b0", "t", "d", "d0", "k", "g", "g0",				//Plosive
    "_p", "_b", "_b0", "_t", "_d", "_d0", "_k", "_g", "_g0", //Plosivpausen
    "m", "n", "N",													//Nasale
    "R", "R0", "l", "l0", "6",										//Liquide
    "?", "h", "h0",													//Glottallaute
    "f", "v", "v0", "z", "z0", "s", "Z", "Z0", "S", "C", "j", "j0", "x", //Frikative
    "a", "I", "E", "9", "U", "Y", "O",								//Kurzvokale
    "a:", "e:", "i:", "o:", "u:", "E:", "y:", "2:", "O:", "9:",				//Langvokale
    "e", "i", "o", "u", "y", "2",									//gespannte Kurzvokale
    "aI", "aU", "OY", "EI",											//Diphthonge
    "a+", "E+", "O+", "9+",											//Nasalvokale
    "@", "@:", "=6", "=l", "=n", "=m", "=N",						//Schwa+Elision
    "<i", "<u", "<o",												//nichtsilbische Vokale
    "a~", "E~", "O~", "9~"
} ;

int seof(char* b, int j)
{
    return (b[j] == '\0') ;
}


char* sgets(char* a, int max, char* b, int &j)
{
    if (b[j]=='\0')
        return (NULL) ;
    int i = 0 ;
    do
    {
        a[i] = b[j] ;
        if (b[j] == '\0' && i > max)
            break ;
        i++;
        j++;
    } while (a[i-1] != '\n') ;
    a[i] = '\0' ;
    return (a) ;
}

char* Syllablelist::next_token(FILE* in)
{
    if (in == NULL)
        return (NULL) ;
    unsigned int i = tokenpos ;
    char akt ;
    int comment = 0 ;
    while (!feof(in))
    {
        akt = fgetc(in) ;
        if (feof(in)) //akt == 0xFF)
            break ;
        if (isspace(akt))
            continue ;
        if (akt == '{')
            comment = 1 ;
        if (akt == '}')
        {
            buffer[i] = '\0' ;
            i = 0 ;
            return (&buffer[0]) ;
        }
        if (akt == '|' && comment == 0)
        {
            buffer[i++] = akt ;
            buffer[i] = '\0' ;
            i = 0 ;
            return (&buffer[0]) ;
        }
        buffer[i++] = akt ;
    }
    i = 0 ;
    return (NULL) ;
}


extern int find_sound(char* &) ;

Syllablelist::Syllablelist()
{
    tokenpos = 0 ;
    errorvalue.soundnr = 0 ;
    errorvalue.firstsound = 0 ;
    errorvalue.name = (char*)"ERROR" ;
    errorvalue.prosinfo = (char*)"" ;
    errorvalue.type = (char*)"ERROR" ;
    errorvalue.accent = -1 ;
}

Syllablelist::Syllablelist(FILE* in)
{
    errorvalue.soundnr = 0 ;
    errorvalue.firstsound = 0 ;
    errorvalue.name = (char*)"ERROR" ;
    errorvalue.prosinfo = (char*)"" ;
    errorvalue.type = (char*)"ERROR" ;
    errorvalue.accent = -1 ;
    char* result ;
    Syllableinfo sy, lastsy ;
    int i, j ;
    if (in == NULL)
    {
        return;
    }
    sy.type = strdup("PGR") ;
    sy.name = strdup("SATZ") ;
    sy.prosinfo = strdup("02") ;
    sy.firstsound = 0 ;
    sy.wordstart = 0 ;
    sy.soundnr = 0 ;
    #ifdef BORDERPROS
    sy.accent = 1 ;
    #else
    sy.accent = 20 ;
    #endif
    conc(sy) ;
    while ((result = next_token(in)) != NULL)
    {
        lastsy = sy ;
        if (result[0] == '{')
        {
            sy.type = strdup("COM") ;
            sy.name = strdup(result) ;
            sy.prosinfo = strdup("") ;
            sy.firstsound = 0 ;
            sy.soundnr = 0 ;
            sy.wordstart = 0 ;
            sy.accent = 0 ;
            conc(sy) ;
            continue ;
        }
        if (result[0] == '*')
        {
            sy.type = strdup("PGR") ;
            switch (result[1])
            {
                case 'W' :
                    sy.prosinfo = strdup("10") ;
                    sy.name = strdup("GRUPPE") ;
                    sy.soundnr = 0 ;
                    break ;
                case 'R' :
                    sy.prosinfo = strdup("12") ;
                    sy.name = strdup("SATZ") ;
                    sy.soundnr = 2 ;
                    break ;
                default :
                    sy.prosinfo = strdup("02") ;
                    sy.soundnr = 2 ;
                    sy.name = strdup("SATZ") ;
            }
            sy.accent = atoi(&result[3]) ;
            #ifndef BORDERPROS
            sy.accent = 150 ;
            #endif
            conc(sy) ;
            continue ;
        }
        sy.type = strdup("SIL") ;
        sy.firstsound = 0 ;
        sy.wordstart = 0 ;
        sy.soundnr = 0 ;
        sy.name = new char[strlen(result)+1] ;
        sy.prosinfo = new char[8] ;
        for (i = j = 0 ; i < (int)strlen(result) ; i++)
        {
            if (result[i] == '[')
            {
                i++ ;
                break ;
            }
            sy.name[j++] = result[i] ;
        }
        sy.accent = atoi(&result[i]) ;
        if (sy.accent > 17)
            strcpy(sy.prosinfo, "H") ;
        else
            strcpy(sy.prosinfo, "-") ;
        sy.name[j] = '\0' ;
        conc(sy) ;
    }
}

int Syllablelist::reduce(int level)
{
    reset() ;
    int i ;
    int end = 0 ;
    char* pos ;
    int start ;
    Syllableinfo* sy, *sydavor, *sydanach = NULL ;
    sydavor = get_syll_pointer() ;
    do
    {
        advance() ;
        sy = get_syll_pointer() ;
        if (strncmp(sy->name, "{SetReductionLevel:", 19) == 0)
            level = atoi(&sy->name[19]) ;
    } while (strcmp(sy->type, "COM")==0) ;
    while (end == 0)
    {
        do
        {
            if (advance() == -1)
            {
                end = 1 ;
                break ;
            }
            sydanach = get_syll_pointer() ;
            if (strncmp(sydanach->name, "{SetReductionLevel:", 19) == 0)
                level = atoi(&sydanach->name[19]) ;
        } while (strcmp(sydanach->type, "COM")==0) ;
        if (level > 0)
        {
            pos = sy->name ;
            start = 0 ;
            while ((pos = strchr(pos+start, 'R')) != NULL)
            {
                start = 1 ;
                if (pos != sy->name)
                {
                    if (pos[-1] == ':')
                        pos[0] = '6' ;
                    if (pos[-1] == '@')
                    {
                        pos[-1] = '=' ;
                        pos[0] = '6' ;
                    }
                }
            }
        }
        if (level > 1)
        {
            if ((strchr("bdghvzZj", sy->name[0]) != NULL) ||
                    (strchr("bdghvzZj", sy->name[1]) != NULL && sy->name[0] == '#'))
                if ((strcmp(sydavor->type, "PGR") == 0) ||
                        (strchr("ptkfsSCx", sydavor->name[strlen(sydavor->name)-1]) != NULL))
                {
                    if (sy->name[0] != '#')
                        i = 0 ;
                    else
                        i = 1 ;
                    if (sy->name[i] == 'z')
                        sy->name[i] = 'z' ;
                    else
                    {
                        memmove(&sy->name[i+2], &sy->name[i+1], strlen(sy->name)-(i)) ;
                        sy->name[i+1] = '0' ;
                    }
                }
        }
        if (level > 2)
        {
            if ((((pos = strstr(sy->name, "@n")) != NULL) ||
                    ((pos = strstr(sy->name, "@l")) != NULL)) && pos != sy->name && strchr("mnlRN", pos[-1]) == NULL)
                pos[0] = '=' ;
        }
        if (level > 3)
        {
            if ((pos = strstr(sy->name, "=n")) != NULL && pos != sy->name)
            {
                if (strchr("pb", pos[-1]) != NULL)
                    pos[1] = 'm' ;
                if (strchr("kg", pos[-1]) != NULL)
                    pos[1] = 'N' ;
            }
        }
        if (level > 4)
        {
            if ((pos = strrchr(sy->name, 'R')) != NULL && pos != sy->name)
            {
                pos-- ;
                if (strchr("aeiouAEIOUY29:", pos[0]) != NULL)
                    pos[1] = '6';
            }
        }
        sydavor = sy ;
        sy = sydanach ;
    }
    return (level) ;
}



/*

    Alte Version:

    Syllablelist::Syllablelist(FILE* in) {
	errorvalue.soundnr = 0 ;
	errorvalue.firstsound = 0 ;
	errorvalue.name = "ERROR" ;
	errorvalue.prosinfo = "" ;
	errorvalue.type = "ERROR" ;
	errorvalue.accent = -1 ;
	const char* pause = "_Pk_[Dk]|[E<]" ;
	const char* satzanfang = "[SA]" ;
	const char* satzende = "_Pl_[Dl][SE]|" ;
	const char* frageende = "_Pl_[Dl][FE]|" ;
	const char* satzende2 = "_Pk_[Dk]|_Pl_[Dl][SE]|" ;
	char* result ;
	Syllableinfo sy, lastsy ;
	int i,j,k ;

	if (in == NULL) {
		return; }

	while ((result = next_token(in)) != NULL) {
		lastsy = sy ;
		if (result[0] == '{') {
			sy.type = strdup("COM") ;
			sy.name = strdup(result) ;
			sy.prosinfo = strdup("") ;
			sy.firstsound = 0 ;
			sy.soundnr = 0 ;
			sy.wordstart = 0 ;
			sy.accent = 0 ;
			conc(sy) ;
			continue ; }
		if (strcmp(result,pause) == 0) {
			sy.type = strdup("PGR") ;
			sy.name = strdup("GRUPPE") ;
			switch (result[strlen(result)-3]) {
				case 'W' :
					sy.prosinfo = strdup("1") ;
					break ;
				case 'F' :
					sy.prosinfo = strdup("2") ;
					break ;
				default :
					sy.prosinfo = strdup("3") ; }
			sy.firstsound = 0 ;
			sy.wordstart = 0 ;
    #ifdef BORDERPROS
			sy.accent = 4 ;
    #else
			sy.accent = 150 ;
    #endif
			sy.soundnr = 0 ;
			conc(sy) ;
			continue ; }
		if (strcmp(result,satzanfang) == 0) {
			sy.type = strdup("PGR") ;
			sy.name = strdup("SATZ") ;
			sy.prosinfo = strdup("1") ;
			sy.firstsound = 0 ;
			sy.wordstart = 0 ;
			sy.soundnr = 2 ;
    #ifdef BORDERPROS
			sy.accent = 1 ;
    #else
			sy.accent = 20 ;
    #endif
			conc(sy) ;
			continue ; }
		if (strcmp(result,satzende) == 0 || strcmp(result,satzende2) == 0) {
			sy.type = strdup("PGR") ;
			sy.name = strdup("SATZ") ;
			sy.prosinfo = strdup("-1") ;
			sy.firstsound = 0 ;
			sy.wordstart = 0 ;
			sy.soundnr = -2 ;
    #ifdef BORDERPROS
			sy.accent = 8 ;
    #else
			sy.accent = 400 ;
    #endif
			conc(sy) ;
			break ; }
		if (strcmp(result,frageende) == 0) {
			sy.type = strdup("PGR") ;
			sy.name = strdup("SATZ") ;
			sy.prosinfo = strdup("-3") ;
			sy.firstsound = 0 ;
			sy.wordstart = 0 ;
			sy.soundnr = -4 ;
    #ifdef BORDERPROS
			sy.accent = 8 ;
    #else
			sy.accent = 400 ;
    #endif
			conc(sy) ;
			break ; }
		if (result[0] == '[')
			continue ;
		sy.type = strdup("SIL") ;
		sy.firstsound = 0 ;
		sy.wordstart = 0 ;
		sy.soundnr = 0 ;
		sy.name = new char[strlen(result)+1] ;
		sy.prosinfo = new char[8] ;
		for (i = j = 0 ; i < strlen(result) ; i++) {
			if (result[i] == '[') {
				i++ ;
				break ; }
			sy.name[j++] = result[i] ; }
		sy.accent = atoi(&result[i]) ;
		while(result[i] != ',')
			i++ ;
		k = 0 ;
		i++ ;
		while (result[i] != ']')
			sy.prosinfo[k++] = result[i++] ;
		sy.prosinfo[k] = '\0' ;
		i++ ;
		while (result[i] != '|')
			sy.name[j++] = result[i++] ;
		sy.name[j] = '\0' ;
		conc(sy) ; } }


*/

Syllablelist::~Syllablelist()
{
    reset() ;
    while (act != NULL)
    {
        if (act->i.type != NULL)
            delete[](act->i.type) ;
        if (act->i.name != NULL)
            delete[](act->i.name) ;
        if (act->i.prosinfo != NULL)
            delete[](act->i.prosinfo) ;
        act = act->after ;
    }
}


void Syllablelist::ex(int i)
{
    get(i) ;
    if (act->i.type != NULL)
        delete[](act->i.type) ;
    if (act->i.name != NULL)
        delete[](act->i.name) ;
    if (act->i.prosinfo != NULL)
        delete[](act->i.prosinfo) ;
    exclude(i) ;
}


int Syllablelist::conc(Syllableinfo i)
{
    return (append(i)) ;
}

Syllableinfo* Syllablelist::get_syll_pointer()
{
    return (&(act->i)) ;
}

int Syllablelist::input(char* ascinfil)
{
    Syllableinfo i ;
    char buffer[80] ;
    int apos = 0 ;
    char* ts ;
    while (sgets(buffer, 79, ascinfil, apos) != NULL)
        if (buffer[0] == '-')
            break ;
    buffer[strlen(buffer)-1] = '\0' ;
    while (!seof(ascinfil, apos))
    {
        do
        {
            i.firstsound = -1 ;
            if (buffer[0]=='-')
            {
                i.type = new char[strlen(buffer)] ;
                nulltest(i.type) ;
                i.type = strcpy(i.type, &buffer[1]) ;
            }
            if (sgets(buffer, 79, ascinfil, apos) == NULL)
                break ;
            buffer[strlen(buffer)-1] = '\0' ;
            if ((ts = strstr((char*)buffer, "val")) != NULL)
            {
                for (ts += 3; (isspace(ts[0]) || ts[0] == ':') ; ts++) ;
                i.name = new char[strlen(ts)+1] ;
                nulltest(i.name) ;
                i.name = strcpy(i.name, ts) ;
            }
            if ((ts = strstr((char*)buffer, "pros")) != NULL)
            {
                for (ts += 4; (isspace(ts[0]) || ts[0] == ':') ; ts++) ;
                i.prosinfo = new char[strlen(ts)+1] ;
                nulltest(i.prosinfo) ;
                i.prosinfo = strcpy(i.prosinfo, ts) ;
            }
            if ((ts = strstr((char*)buffer, "bet")) != NULL)
            {
                for (ts += 3; (isspace(ts[0]) || ts[0] == ':') ; ts++) ;
                i.accent = atoi(ts) ;
            }
            if ((ts = strstr((char*)buffer, "pos")) != NULL)
            {
                for (ts += 3; (isspace(ts[0]) || ts[0] == ':') ; ts++) ;
                i.soundnr = atoi(ts) ;
            }
        } while (buffer[0] != '-') ;
        append(i) ;
    }
    return (1) ;
}


int Syllablelist::no_interpunction()
{
    Syllableinfo syll, syll1 ;
    reset() ;
    int i = 1 ;
    while (advance() > 0)
    {
        syll = get() ;
        if (syll.name[0] == '#' && syll.name[1] == '#')
        {
            i = get_number() ;
            ex(i-1) ;
            while (strcmp("SIL", (syll = get(i-1)).type) == 0)
            {
                ex(i-1) ;
            }
        }
    }
    reset() ;
    syll = get() ;
    if (advance() == -1)
        return (0) ;
    decrease() ;
    while (advance() > 0)
    {
        syll1 = get() ;
        if (strcmp(syll.name, "SATZ") == 0 && strcmp(syll1.name, "SATZ") == 0)
            return (0) ;
        syll = syll1 ;
    }
    return (1) ;
}

int Syllablelist::compute_intonation_features()
{
    Syllableinfo* s, *t;
    int maxprom = -1 ;
    reset() ;
    t = NULL ;
    while ((s = get_syll_pointer())->accent != errorvalue.accent)
    {
        if (strcmp(s->type, "PGR") == 0)
        {
            if (t!= NULL)
                strcpy(t->prosinfo, "HM") ;
            maxprom = -1 ;
        }
        if (strcmp(s->type, "SIL") == 0)
        {
            if (s->accent >= maxprom)
            {
                maxprom = s->accent ;
                t = s ;
            }
        }
        if (advance() == -1)
            break ;
    }
    int brdpos = get_number() ;
    int j ;
    int rifa =0;
    int lastacc = 1 ;
    int lastbrdpos = brdpos ;
    int comcount = 0 ;
    for (j = brdpos ; j > 0 ; j--)
    {
        get(j) ;
        s = get_syll_pointer() ;
        if (strcmp(s->type, "COM") == 0)
            comcount++ ;
        if (strcmp(s->type, "PGR") == 0)
        {
            lastbrdpos = get_number() ;
            lastacc = 1 ;
            comcount = 0 ;
            if (strchr(s->prosinfo, '1') == NULL)
                rifa = 0 ;
            else
                rifa = 1 ;
        }
        if (strcmp(s->type, "SIL") == 0)
        {
            if (strchr(s->prosinfo, 'H') != NULL)
            {
                if (lastacc == 1)
                {
                    lastacc = 0 ;
                    if (rifa == 0)
                    {
                        if (lastbrdpos-(comcount+j) < 4)
                            strcat(s->prosinfo, "E") ;
                    }
                    else
                    {
                        strcat(s->prosinfo, "L") ;
                    }
                }
            }
        }
    }
    comcount = 0 ;
    int lastbrdtyp=0 ;
    int firstacc = 1 ;
    for (j = 1 ; j < brdpos ; j++)
    {
        get(j) ;
        s=get_syll_pointer() ;
        if (strcmp(s->type, "COM") == 0)
            comcount++ ;
        if (strcmp(s->type, "PGR") == 0)
        {
            if (strcmp(s->prosinfo, "10") == 0)
                lastbrdtyp=1 ;
            else
                lastbrdtyp=0 ;
            lastbrdpos = get_number() ;
            comcount = 0 ;
            firstacc = 1 ;
        }
        if (strcmp(s->type, "SIL") == 0)
        {
            if (strchr(s->prosinfo, 'H') != NULL)
            {
                if (firstacc == 1)
                {
                    firstacc = 0 ;
                    if (lastbrdtyp==1)
                    {
                        if (j-(comcount+lastbrdpos) < 3)
                            strcat(s->prosinfo, "E") ;
                    }
                    else
                    {
                        if (j-(comcount+lastbrdpos) < 3)
                            strcat(s->prosinfo, "L") ;
                    }
                }
            }
        }
    }
    comcount = 0 ;
    lastacc = 0 ;
    for (j = 1 ; j < brdpos ; j++)
    {
        get(j) ;
        s=get_syll_pointer() ;
        if (strcmp(s->type, "COM") == 0)
            comcount++ ;
        if (strcmp(s->type, "PGR") == 0)
        {
            lastacc = 0 ;
            comcount = 0 ;
        }
        if (strcmp(s->type, "SIL") == 0)
        {
            if (strchr(s->prosinfo, 'H') != NULL)
            {
                if (lastacc != 0)
                {
                    if (j-(comcount+lastacc) < 3)
                    {
                        if (strchr(s->prosinfo, 'E') != NULL)
                            strcat(s->prosinfo, "S") ;
                        else
                            strcat(s->prosinfo, "L") ;
                    }
                }
                lastacc = j ;
            }
        }
    }
    char pf[20] ;
    lastacc=0 ;
    for (j = 1 ; j < brdpos ; j++)
    {
        get(j) ;
        s=get_syll_pointer() ;
        if (strcmp(s->type, "COM") == 0 && strncmp(s->name, "{PeakFeatures:", 14) == 0)
        {
            lastacc = 1 ;
            strcpy(pf, &s->name[14]) ;
        }
        if (strcmp(s->type, "SIL") == 0)
        {
            if (strchr(s->prosinfo, 'H') != NULL)
            {
                if (lastacc != 0)
                {
                    lastacc = 0 ;
                    strcpy(s->prosinfo, pf) ;
                }
            }
        }
    }
    return (0) ;
}






int Syllablelist::make_soundlist(Soundlist* soli)
{
    Syllableinfo* syll ;
    Soundinfo soun ;
    int soundnr, a ;
    char* as ;
    reset() ;
    while ((syll = get_syll_pointer())->accent != errorvalue.accent)
    {
        if (strcmp(syll->type, "SIL") == 0)
        {
            if ((as = strstr(syll->name, "?@")) != NULL)
                as[1]='E' ;
            if ((as = strstr(syll->name, "?=")) != NULL)
                as[1]='E' ;
            syll->firstsound = -1 ;
            syll->soundnr = 0 ;
            as = syll->name ;
            syll->wordstart = 0 ;
            if (syll->name[0] == '#')
            {
                syll->wordstart = 1 ;
                as++ ;
            }
            if (syll->name[1] == '#')
                as++ ;
            while ((soundnr = find_sound(as)) > -1)
            {
                if (soundnr < 9)
                {
                    strcpy(soun.name, sounds[soundnr+9]) ;
                    soun.duration = syll->accent ;
                    soun.intensity = (int)1.0 ;
                    soun.accent = syll->accent ;
                    soun.f0nr = 0 ;
                    a = soli->conc(soun) ;
                    syll->soundnr ++ ;
                    if (syll->firstsound == -1)
                        syll->firstsound = a ;
                }
                strcpy(soun.name, sounds[soundnr]) ;
                soun.duration = syll->accent ;
                soun.intensity = syll->accent ;
                soun.accent = syll->accent ;
                soun.f0nr = 0 ;
                syll->soundnr ++ ;
                a = soli->conc(soun) ;
                if (syll->firstsound == -1)
                    syll->firstsound = a ;
            }
        }
        else
        {
            if (strcmp(syll->type, "PGR") == 0)
            {
                strcpy(soun.name, "pau") ;
                soun.duration = (((syll->accent>0) || (strcmp(syll->name, "GRUPPE") == 0))?syll->accent:20) ;
                soun.accent = 0 ;
                soun.intensity = syll->soundnr ;
                soun.f0nr = 0 ;
                syll->soundnr = 1 ;
                syll->firstsound = soli->conc(soun) ;
            }
        }// }
        if (advance() == -1)
            break ;
    }
    return (1) ;
}

int Syllablelist::distance_to_pgr()
{
    Listentry* l = act ;
    int i = 0 ;
    while (strcmp(l->i.type, "PGR") != 0)
    {
        i++ ;
        l = l->after ;
    }
    return (i) ;
}

char* Syllablelist::new_voice()
{
    reset() ;
    Syllableinfo i ;
    while ((i = get_and_advance()).accent != errorvalue.accent)
        if (strcmp(i.type, "COM") == 0 && strncmp(i.name, "{Voice:", 7) == 0)
            return (&i.name[7]) ;
    return (NULL) ;
}

char* Syllablelist::find_command(const char* c)
{
    reset() ;
    Syllableinfo i ;
    while ((i = get_and_advance()).accent != errorvalue.accent)
        if (strcmp(i.type, "COM") == 0 && strncmp(&i.name[1], c, strlen(c)) == 0)
            return (&i.name[strlen(c)+2]) ;
    return (NULL) ;
}


void Syllablelist::wagonprom()
{
    promguess_struct st ;
    st.WAKZENT = "0" ;
    st.LAUT = "@" ;
    st.WSYLC = "1" ;
    st.WSYLP = "1" ;
    st.SONR = 3 ;
    st.BODI = 1 ;
    st.ACCE = "0" ;
    st.FACCE = "0" ;
    st.PACCE = "0" ;
    st.CODAC = "0" ;
    st.ONSEC = "0" ;
    st.WORTART = "0" ;
    const char* nucstart = "aeiouEIOUyY29=@" ;
    char dummy[10][12] ;
    Syllableinfo* si ;
    Syllableinfo u;
    int i, j, k, l ;
    int wsylc;
    int maxacc ;
    char wcstring[12] ;
    int wcs ;
    int codac, onsec, sonr, soundnr, acce = 0, facce, bodi, wsylp ;
    char* as ;
    reset() ;
    while ((si = get_syll_pointer())->accent != errorvalue.accent)
    {
        j = get_number()+1 ;
        if (strncmp(si->name, "{WordClass:", 11) == 0)
        {
            if (debuglevel > 1)
            {
                fprintf(errfile, "Wordstart found %s\n", si->name) ;
                fflush(errfile) ;
            }
            strncpy(wcstring, &si->name[11], 3) ;
            wcstring[3] = '\0' ;
            wcs = get_wc(wcstring) ;
            i = get_number() ;
            wsylc = 0 ;
            maxacc = -1 ;
            k = i ;
            do
            {
                u=get(++k) ;
                if (strcmp(u.type, "SIL") == 0)
                {
                    wsylc++ ;
                    if (u.accent > maxacc)
                        maxacc = u.accent ;
                }
            } while (strcmp(u.type, "PGR")!=0 && (strncmp(u.name, "{WordClass:", 11) != 0)) ;
            j = k ;
            if (debuglevel > 1)
            {
                fprintf(errfile, "Wordend found %s\n", u.name) ;
                fflush(errfile) ;
            }
            bodi = 0 ;
            while (strcmp(u.type, "PGR")!=0)
            {
                u=get(++k) ;
                if (strcmp(u.type, "SIL") == 0)
                {
                    bodi++ ;
                }
            }
            sprintf(dummy[9], "%d", wcs) ;
            sprintf(dummy[2], "%d", wsylc) ;
            st.WORTART=dummy[9] ;
            st.WSYLC=dummy[2] ;
            wsylp = 0 ;
            for (k = i+1 ; k < j ; k++)
            {
                get(k) ;
                si = get_syll_pointer() ;
                if (strcmp(si->type, "SIL") == 0)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "In syllable %s\n", si->name) ;
                        fflush(errfile) ;
                    }
                    wsylp++ ;
                    sprintf(dummy[3], "%d", wsylp) ;
                    st.WSYLP = dummy[3] ;
                    st.BODI = bodi+wsylc-wsylp ;
                    if (si->accent >= maxacc)
                        sprintf(dummy[0], "1") ;
                    else
                        sprintf(dummy[0], "0") ;
                    st.WAKZENT = dummy[0] ;
                    sprintf(dummy[6], "%d", acce) ;
                    st.PACCE=dummy[6] ;
                    as = si->name ;
                    while (*as == '#')
                        as++ ;
                    codac = 0 ;
                    onsec = 0 ;
                    acce = 0 ;
                    sonr = 0 ;
                    st.LAUT = "0" ;
                    facce = 0 ;
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Starting to look for sounds in %s...\n", as) ;
                        fflush(errfile) ;
                    }
                    while ((soundnr = find_sound(as)) > -1)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Sound found %s now %s", sounds[soundnr], as) ;
                            fflush(errfile) ;
                        }
                        sonr++ ;
                        if (strchr(nucstart, sounds[soundnr][0]) != NULL)
                        {
                            st.LAUT = sounds[soundnr] ;
                        }
                        else
                        {
                            if (st.LAUT[0] == '0')
                                onsec++ ;
                            else
                                codac++ ;
                        }
                    }
                    if (strchr("@=", st.LAUT[0]) == NULL)
                        acce = 1 ;
                    sprintf(dummy[4], "%d", 1) ;
                    st.ACCE = dummy[4] ;
                    st.SONR = sonr ;
                    sprintf(dummy[7], "%d", codac) ;
                    st.CODAC = dummy[7] ;
                    sprintf(dummy[8], "%d", onsec) ;
                    st.ONSEC = dummy[8] ;
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Vor bodi-Loop %f\n", st.BODI) ;
                        fflush(errfile) ;
                    }
                    if (st.BODI > 0)
                    {
                        l = k+1 ;
                        do
                        {
                            u = get(l++) ;
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "In syllable %d %s\n", l, u.name) ;
                                fflush(errfile) ;
                            }
                        } while (strcmp(u.type, "SIL") != 0) ;
                        if (strchr(u.name, '@') == NULL && strchr(u.name, '=') == NULL)
                            facce = 1 ;
                        else
                            facce = 0 ;
                    }
                    sprintf(dummy[5], "%d", facce) ;
                    st.FACCE = dummy[5] ;
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Calling Wagonprom for %s with %s %s %s %s %f %f %s %s %s %s %s %s\n", si->name, st.WAKZENT, st.LAUT, st.WSYLC, st.WSYLP, st.SONR, st.BODI, st.ACCE, st.FACCE, st.PACCE, st.CODAC, st.ONSEC, st.WORTART) ;
                        fflush(errfile) ;
                    }
                    si->accent = (int)promguess_wagon_comp(st) ;
                }
            }
        }
        get(j-1) ;
        if (advance() == -1)
            break ;
    }
}



void Syllablelist::print(FILE* ascoutfil)
{
    reset() ;
    Syllableinfo i ;
    while ((i = get_and_advance()).accent != errorvalue.accent)
    {
        fprintf(ascoutfil, "%8s %4s - %6s - %6d - %6d\n", i.name, i.type, i.prosinfo, i.accent, i.soundnr) ;
    }
}


int Syllablelist::printmbrola(Soundlist* soli, FILE* ascoutfil, char* impbuffer)
{
    reset() ;
    Soundinfo i, lasti ;
    Syllableinfo ss ;
    char db[24] ;
    int lastdur = 0;
    int rr ;
    lasti = soli->get_and_advance() ;
    while ((ss = get_and_advance()).accent != errorvalue.accent)
    {
        if (strcmp(ss.type, "COM") == 0 && strncmp(ss.name, "{Comment:", 9) == 0)
        {
            fprintf(ascoutfil, "; %s\n", &ss.name[9]) ;
            continue ;
        }
        if (strcmp(ss.type, "SIL") != 0 && strcmp(ss.type, "PGR") != 0)
            continue ;
        for (rr = ss.firstsound ; rr < ss.firstsound+ss.soundnr ; rr++)
        {
            i = soli->get(rr) ;
            if (i.name[0] == '_')
            {
                lastdur = i.duration ;
                continue ;
            }
            i.duration+=lastdur ;
            lastdur = 0 ;
            if (strcmp(i.name, "EI") == 0)
                strcpy(i.name, "e:") ;
            if (strcmp(i.name, "O~") == 0)
                strcpy(i.name, "o^") ;
            if (strcmp(i.name, "9~") == 0)
                strcpy(i.name, "E^") ;
            if (i.name[1] == '~')
            {
                sprintf(db, "%c^", i.name[0]) ;
                strcpy(i.name, db) ;
            }
            if (i.name[1] == '0')
            {
                sprintf(db, "%c", i.name[0]) ;
                strcpy(i.name, db) ;
            }
            if (strchr("=", i.name[0]) != NULL)
            {
                sprintf(db, "%s", &i.name[1]) ;
                strcpy(i.name, db) ;
            }
            if (strchr("<", i.name[0]) != NULL)
            {
                sprintf(db, "%s", &i.name[1]) ;
                strcpy(i.name, db) ;
            }
            if (strchr("2oiuey", i.name[0]) != NULL && i.name[1] == '\0')
            {
                sprintf(db, "%s:", i.name) ;
                strcpy(i.name, db) ;
            }
            if (strchr("9OIUY@6", i.name[0]) != NULL && i.name[1] == ':')
                i.name[1] = '\0'  ;
            if (i.name[0] == '?')
                i.name[0] = '_' ;
            if (strcmp(i.name, "pau") == 0)
                sprintf(i.name, "_") ;
            if (strcmp(i.name, lasti.name) == 0 && i.name[0] != '_')
            {
                lasti = i ;
                continue ;
            }
            sprintf(db, "-%s-%s-", lasti.name, i.name) ;
            if (find_diphon_in_liste(impbuffer, db) == 1)
            {
                if (strchr("dgvzhj", lasti.name[0]) != NULL)
                {
                    fprintf(ascoutfil, "a 10\n") ;
                }
                if (strchr("9O", lasti.name[0]) != NULL)
                {
                    fprintf(ascoutfil, "t 10\n") ;
                }
                if (lasti.name[0] != '_' && i.name[0] != '_')
                    fprintf(ascoutfil, "_ 5\n") ;
                if (i.name[0] == 'N')
                    fprintf(ascoutfil, "a 10\n") ;
                if (i.name[0] == '6')
                    fprintf(ascoutfil, "t 10\n") ;
                if (strchr("^~", i.name[1]) != NULL && strchr("E9o", i.name[0]) != NULL && strlen(i.name) > 1)
                    fprintf(ascoutfil, "t 10\n") ;
            }
            lasti = i ;
            fprintf(ascoutfil, "%s %d ", i.name, max(10, i.duration)) ;
            for (int j = 0 ; j < min(10, i.f0nr); j++)
                fprintf(ascoutfil, "%3.0f %3.0f ", 100.0*(float)i.f0pos[j]/(float)i.duration, i.f0[j]) ;
            fprintf(ascoutfil, "\n") ;
        }
    }
}

int Syllablelist::printkalle(Soundlist* soli, FILE* ascoutfil)
{
    reset() ;
    Soundinfo i ;
    Syllableinfo ss ;
    int rr ;
    while ((ss = get_and_advance()).accent != errorvalue.accent)
    {
        if (strcmp(ss.type, "COM") == 0 && strncmp(ss.name, "{WordClass:", 11) == 0)
        {
            fprintf(ascoutfil, "##") ;
            continue ;
        }
        if (strcmp(ss.type, "SIL") != 0)
            continue ;
        for (rr = ss.firstsound ; rr < ss.firstsound+ss.soundnr ; rr++)
        {
            i = soli->get(rr) ;
            fprintf(ascoutfil, "%s\n", i.name) ;
        }
    }
    return (0) ;
}


int Syllablelist::printretivox(Soundlist* soli, FILE* ascoutfil)
{
    reset() ;
    long ddurr ;
    Soundinfo i ;
    Syllableinfo ss ;
    int rr ;
    ddurr = 0L ;
    while ((ss = get_and_advance()).accent != errorvalue.accent)
    {
        if (strcmp(ss.type, "COM") == 0 && strncmp(ss.name, "{Comment:", 9) == 0)
        {
            fprintf(ascoutfil, "%s %ld\n", &ss.name[9], ddurr) ;
            continue ;
        }
        if (strcmp(ss.type, "SIL") != 0 && strcmp(ss.type, "PGR") != 0)
            continue ;
        for (rr = ss.firstsound ; rr < ss.firstsound+ss.soundnr ; rr++)
        {
            i = soli->get(rr) ;
            ddurr += i.duration ;
        }
    }
    return (0) ;
}


void Syllablelist::pauses()
{
    reset() ;
    int length ;
    Syllableinfo* i, *j ;
    while (advance() > -1)
    {
        i = get_syll_pointer() ;
        if (strcmp(i->type, "COM") == 0 && strncmp(i->name, "{Pause:", 7) == 0)
        {
            length = atoi(&(i->name)[7]) ;
            if (length < 20)
                length = 20 ;
            if (length > 999)
                length = 900 ;
            i->accent = length ;
            #ifdef BORDERPROS
            i->accent = min(8, length/50)+1;
            #endif
            delete (i->type) ;
            i->type = strdup("PGR") ;
            delete (i->name) ;
            i->name = strdup("GRUPPE") ;
            delete (i->prosinfo) ;
            i->prosinfo = strdup("0") ;
        }
    }
    #ifndef BORDERPROS
}
    #else
    reset() ;
    while (advance() > -1)
    {
        i = get_syll_pointer() ;
        if (strcmp(i->type, "COM") == 0 && strncmp(i->name, "{BorderProminence:", 18) == 0)
        {
            length = atoi(&(i->name)[18]) ;
            advance() ;
            j = get_syll_pointer() ;
            if (strcmp(j->type, "PGR") == 0)
            {
                j->accent = length ;
                continue ;
            }
            i->accent = length ;
            #ifndef BORDERPROS
            i->accent = max(8, length / 100) + 1 ;
            #endif
            delete (i->type) ;
            i->type = strdup("PGR") ;
            delete (i->name) ;
            i->name = strdup("GRUPPE") ;
            delete (i->prosinfo) ;
            i->prosinfo = strdup("0") ;
        }
    }
}
    #endif








