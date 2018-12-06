/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/




#include <string.h>
#include "ascii.h"
#include "debug.h"
#include "ipa.h"
#include "ptra.h"
#include "code.h"

extern int language ;

extern FILE* errfile ;

int strcomp(char* s1, char* s2)
{
    int i = 0 ;
    if (s1 == NULL)
        return (-1) ;
    if (s2 == NULL)
        return (1) ;
    while (s1[i] != '\0')
    {
        if (s1[i] < s2[i])
            return (-1) ;
        if (s1[i] > s2[i])
            return (1) ;
        i++ ;
    }
    return (0) ;
}


////////////////////////////////////////////////////////////////////////////////////////

bool setborder (char* in, int len, int pos)
{
    if (pos > len)
        return false;
    for (int i = len; i > pos; i--)
        in[i] = in[i - 1];
    in[pos] = '|';
    in[len + 1] = '\0';
//  printf("%s", in);
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////

bool setborder (string &in, int len, int pos)
{
    if (pos > len)
        return false;
    #if defined(__GNUC__)
    in.insert(pos, 1, '|');
    #else
    in.insert(pos, '|');
    #endif
    return true;
}



char* changesounds(char* in, char* result)
{
    int len = strlen(in) ;
    int i, j=0 ;
    for (i=0 ; i < len ; i++)
    {
        if (in[i]=='<' && (i > len-3 || strchr(ipa_sylcor, in[i+2]) == NULL))
        {
            result[j++] = in[i+1] ;
            result[j++] = ':' ;
            i++ ;
            continue ;
        }
        if (strchr(ipa_sylcor, in[i]) == NULL)
        {
            if (strchr(ipa_voicedplos, in[i]) == NULL)
                result[j++] = in[i];
            else
                switch (in[i])
                {
                    case '6' :
                        result[j++] = 'r';
                        break;
                    case 'd' :
                        result[j++] = 'd';
                        break;
                    case 'g' :
                        result[j++] = 'g';
                        break;
                    case 'b' :
                        result[j++] = 'b';
                        break;
                    case 'z' :
                        result[j++] = 'z';
                        break;
                    case 'v' :
                        result[j++] = 'v';
                        break;
                }
        }
        else if (in[i] == '=')
        {
            result[j++] = '@';
            switch (in[++i])
            {
                case 'l' :
                    result[j++] = 'l';
                    break ;
                case 'm' :
                    result[j++] = 'm';
                    break ;
                case 'n' :
                    result[j++] = 'n';
                    break ;
                case 'N' :
                    result[j++] = 'N';
                    break ;
                case '6' :
                    result[j++] = 'r';
                    break ;
            }
        }
        else
            result[j++] = in[i] ;
    }
    result[j] = '\0' ;
    return (result) ;
}



////////////////////////////////////////////////////////////////////////////////////////

char* putborder (char* in, int len, int kv)
{
    statistics("Syllable Border " << in << " " << kv) ;
    int i;
    int nsv = 0;
    if (len == 0)
    {
        setborder(in, len, 0);
        statistics("Rule 0 " << in) ;
        return in;
    }
    if (strchr("<", in[len - 1]) != NULL)
    {
        if (!is_ipa_consonant(in[len - 2]))
        {
            setborder(in, len, len - 1);
            statistics("Rule 1 " << in) ;
            return in;
        }
        else
        {
            nsv = 1;
            if (len < 3)
            {
                setborder(in, len, 0);
                statistics("Rule 2 " << in) ;
                return in;
            }
        }
    }
    if (len < 2)
    {
        setborder(in, len, 0);
        statistics("Rule 3 " << in) ;
        return in;
    }
    for (i = 1-kv ; i < len; i++)
    {
        statistics(in[i]) ;
        if (strchr(ipa_beforeborder, in[i]) != NULL || (i > 0 && in[i - 1] == in[i]))
        {
            setborder(in, len, i);
            statistics("Rule 4 " << in) ;
            return in;
        }
        if (strchr(ipa_sonorants, in[i]) != NULL && (i < len-1 && in[i + 1] == 'r'))
        {
            setborder(in, len, i + 1);
            statistics("Rule 5 " << in) ;
            return in;
        }
        if (strchr(&ipa_sonorants[2], in[i]) != NULL && (i < len-1 && in[i + 1] == 'l'))
        {
            setborder(in, len, i + 1);
            statistics("Rule 6 " << in) ;
            return in;
        }
        if (strchr(&ipa_sonorants[3], in[i]) != NULL && (i < len-1 && strchr(ipa_sonorants, in[i + 1]) != NULL && in[i + 1] != '\0'))
        {
            setborder(in, len, i + 1);
            statistics("Rule 7 " << in) ;
            return in;
        }
    }
    switch (in[len - 1 - nsv])
    {
        case 'r' :
            if (strchr("ktpfvS", in[len - 2 - nsv]) == NULL)
            {
                setborder(in, len, len - 1 - nsv);
                statistics("Rule 8 " << in) ;
                return in;
            }
            if (len-3-nsv >= 0 && ((strncmp(&in[len - 3 - nsv], "Str", 3) == 0 ||
                                    strncmp(&in[len - 3 - nsv], "Spr", 3) == 0 ||
                                    strncmp(&in[len - 3 - nsv], "pfr", 3) == 0) && !(kv == 0 && len-3-nsv == 0)))
                setborder(in, len, len - 3 - nsv);
            else if (kv == 0 && len-2-nsv == 0)
                setborder(in, len, len-1-nsv) ;
            else
                setborder(in, len, len - 2 - nsv);
            statistics("Rule 9 " << in) ;
            return in;
        case 'l' :
            if (strchr("kpfvS", in[len - 2 - nsv]) == NULL)
            {
                setborder(in, len, len - 1 - nsv);
                statistics("Rule 10 " << in) ;
                return in;
            }
            if (len-3-nsv >= 0 && ((strncmp(&in[len - 3 - nsv], "Stl", 3) == 0 ||
                                    strncmp(&in[len - 3 - nsv], "pfl", 3) == 0) && !(kv == 0 && len-3-nsv == 0)))
                setborder(in, len, len - 3 - nsv);
            else if (kv == 0 && len-2-nsv == 0)
                setborder(in, len, len-1-nsv) ;
            else
                setborder(in, len, len - 2 - nsv);
            statistics("Rule 11 " << in) ;
            return in;
        case 't' :
        case 'p' :
        case 'm' :
            if (strchr("S", in[len - 2 - nsv]) == NULL || kv == 0)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            statistics("Rule 12 " << in) ;
            return in;
        case 'n' :
        case 'v' :
            if (strchr("kS", in[len - 2 - nsv]) == NULL || kv == 0)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            statistics("Rule 13 " << in) ;
            return in;
        case 'x' :
        case 'C' :
        case 'k' :
            setborder(in, len, len - 1 - nsv);
            statistics("Rule 14 " << in) ;
            return in;
        case 'f' :
            if (strchr("p", in[len - 2 - nsv]) == NULL || kv == 0)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            statistics("Rule 15 " << in) ;
            return in;
        case 'S' :
        case 's' :
            if (strchr("t", in[len - 2 - nsv]) == NULL || kv == 0)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            statistics("Rule 16 " << in) ;
            return in;
    }
    setborder(in, len, 1);
    statistics("Rule 17 " << in) ;
    return in;
}


////////////////////////////////////////////////////////////////////////////////////////

string &putborder (string &in, int len)
{
    int i;
    int nsv = 0;
    if (len == 0)
    {
        setborder(in, len, 0);
        return in;
    }
    if (is_ipa_non_syllabic_vowel(in[len - 1]))
    {
        if (!is_ipa_consonant(in[len - 2]))
        {
            setborder(in, len, len - 1);
            return in;
        }
        else
        {
            nsv = 1;
            if (len < 3)
            {
                setborder(in, len, 0);
                return in;
            }
        }
    }
    if (len < 2)
    {
        setborder(in, len, 0);
        return in;
    }
    for (i = 0; i < len; i++)
    {
        if (i > 0 && (strchr(ipa_beforeborder, in[i]) != NULL || in[i - 1] == in[i]))
        {
            setborder(in, len, i);
            return in;
        }
        if (strchr(ipa_sonorants, in[i]) != NULL && in[i + 1] == 'r')
        {
            setborder(in, len, i + 1);
            return in;
        }
        if (strchr(&ipa_sonorants[2], in[i]) != NULL && in[i + 1] == 'l')
        {
            setborder(in, len, i + 1);
            return in;
        }
        if (strchr(&ipa_sonorants[3], in[i]) != NULL && strchr(ipa_sonorants, in[i + 1]) != NULL && in[i + 1] != '\0')
        {
            setborder(in, len, i + 1);
            return in;
        }
    }
    switch (in[len - 1 - nsv])
    {
        case 'r' :
            if (strchr("ktpfvS", in[len - 2 - nsv]) == NULL)
            {
                setborder(in, len, len - 1 - nsv);
                return in;
            }
            if (strncmp(&in[len - 3 - nsv], "Str", 3) == 0 ||
                    strncmp(&in[len - 3 - nsv], "Spr", 3) == 0 ||
                    strncmp(&in[len - 3 - nsv], "pfr", 3) == 0)
                setborder(in, len, len - 3 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            return in;
        case 'l' :
            if (strchr("kpfvS", in[len - 2 - nsv]) == NULL)
            {
                setborder(in, len, len - 1 - nsv);
                return in;
            }
            if (strncmp(&in[len - 3 - nsv], "Stl", 3) == 0 ||
                    strncmp(&in[len - 3 - nsv], "pfl", 3) == 0)
                setborder(in, len, len - 3 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            return in;
        case 't' :
        case 'p' :
        case 'm' :
            if (strchr("S", in[len - 2 - nsv]) == NULL)
                setborder(in, len, len - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            return in;
        case 'n' :
        case 'v' :
            if (strchr("kS", in[len - 2 - nsv]) == NULL)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            return in;
        case 'x' :
        case 'C' :
        case 'k' :
            setborder(in, len, len - 1 - nsv);
            return in;
        case 'f' :
            if (strchr("p", in[len - 2 - nsv]) == NULL)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            return in;
        case 'S' :
        case 's' :
            if (strchr("t", in[len - 2 - nsv]) == NULL)
                setborder(in, len, len - 1 - nsv);
            else
                setborder(in, len, len - 2 - nsv);
            return in;
    }
    setborder(in, len, 1);
    return in;
}


////////////////////////////////////////////////////////////////////////////////////////

/*
    Regel::~Regel ()
    {   destructor(this);

	if (precontext != NULL)
		CLEAR(precontext);
	if (suchtext != NULL)
		CLEAR(suchtext);
	if (postcontext)
		CLEAR(postcontext);
	if (result != NULL)
		CLEAR(result);
    }
*/


////////////////////////////////////////////////////////////////////////////////////////

char* PTRA::sylborders (char* in, bool gs_include)
{
    char* result = NULL;
    char* intermed = NULL ;
    ALLOCATE(char, result, strlen(in) * 3 + 2);
    ALLOCATE(char, intermed, strlen(in) * 3 + 2);
    char syl[256];
    int len = strlen(in);
    int i, j = 0, k, l;
    bool putgs = false;
    int kv = 0 ;
    int schwav = 0 ;
    int slkns = 0 ;
    statistics("Syllable Borders for " << in) ;
    changesounds(in, intermed) ;
    statistics("Syllable Borders after changesounds " << in) ;
    len = strlen(intermed) ;
    if (strchr(ipa_sylcor, intermed[0]) != NULL && language != 1)
        result[j++] = '?';
    if (strchr(ipa_sylcor, intermed[1]) != NULL && (intermed[0] == ',' || intermed[0] == '\'') && language != 1)
        putgs = true;
    for (i=0; i < len; i++)
    {
        if (putgs && i == 1)
        {
            putgs = false;
            result[j++] = '?';
        }
        if (strchr(ipa_sylcor, intermed[i]) == NULL)
        {
            if (intermed[i] == '<')
            {
                result[j++] = intermed[i++] ;
                result[j++] = intermed[i] ;
                continue ;
            }
            if (strchr(ipa_voicedplos, intermed[i]) == NULL)
                result[j++] = intermed[i];
            else
                switch (intermed[i])
                {
                    case '6' :
                        result[j++] = 'r';
                        break;
                    case 'd' :
                        result[j++] = 'd';
                        break;
                    case 'g' :
                        result[j++] = 'g';
                        break;
                    case 'b' :
                        result[j++] = 'b';
                        break;
                    case 'z' :
                        result[j++] = 'z';
                        break;
                    case 'v' :
                        result[j++] = 'v';
                        break;
                }
        }
        else
        {
            kv = -1 ;
            slkns = 0 ;
            while (strchr(ipa_sylcor, intermed[i]) != NULL)
            {
                if (intermed[i] == '=')
                {
                    result[j++] = intermed[i++] ;
                    result[j++] = intermed[i++] ;
                    slkns = 1 ;
                    continue ;
                }
                if (i == len)
                    break;
                if ((intermed[i] == 'a' && (intermed[i+1] == 'I' || intermed[i+1] == 'U')) ||
                        (intermed[i] == 'E' && intermed[i+1] == 'I') ||
                        (intermed[i] == 'O' && intermed[i+1] == 'Y'))
                {
                    result[j++] = intermed[i++] ;
                    result[j++] = intermed[i++] ;
                    slkns=1 ;
                    continue ;
                }
                if (strchr(ipa_schwa, intermed[i]) != NULL)
                    schwav = 1 ;
                kv++ ;
                if (j > 1 && result[j-2] != '<' && (slkns == 1 || strchr(ipa_sylcorend, result[j-1]) != NULL) && strchr(ipa_sylcorstart, intermed[i]) != NULL)
                {
                    result[j++] = '|';
                    schwav = 0 ;
                    kv = 0 ;
                    slkns = 0 ;
                    if (intermed[i] != '=' && intermed[i] != '@' && gs_include)
                        result[j++] = '?';
                }
                result[j++] = intermed[i];
                i++;
            }
            break;
        }
    }
    i--;
    k = 0;
    statistics("LEN " << len) ;
    while (++i < len)
    {
        result[j] = '\0' ;
        syl[k] = '\0' ;
        statistics("NOW " << intermed[i]<< " i " << i << " BISHER " << result << " j " << j << " SYL " << syl << " k " << k) ;
        if (strchr(ipa_sylcor, intermed[i]) == NULL)
        {
            if (intermed[i] == '<')
                syl[k++] = intermed[i++] ;
            syl[k++] = intermed[i];
        }
        else
        {
            putborder((char*)syl, k, schwav = 0 ? kv : 1);
            for (l = 0; l < k+1; l++)
                result[j++] = syl[l];
            k = 0;
            schwav = 0 ;
            kv = -1 ;
            slkns = 0 ;
            while (strchr(ipa_sylcor, intermed[i]) != NULL)
            {
                if (i == len)
                    break;
                if (intermed[i] == '=')
                {
                    result[j++] = intermed[i++] ;
                    result[j++] = intermed[i++] ;
                    slkns = 1 ;
                    continue ;
                }
                if ((intermed[i] == 'a' && (intermed[i+1] == 'I' || intermed[i+1] == 'U')) ||
                        (intermed[i] == 'E' && intermed[i+1] == 'I') ||
                        (intermed[i] == 'O' && intermed[i+1] == 'Y'))
                {
                    result[j++] = intermed[i++] ;
                    result[j++] = intermed[i++] ;
                    slkns=1 ;
                    continue ;
                }
                kv++ ;
                if (strchr(ipa_schwa, intermed[i]) != NULL)
                    schwav = 1 ;
                if (j > 0 && result[j-2] != '<' && (slkns == 1 || strchr(ipa_sylcorend, result[j-1]) != NULL) && strchr(ipa_sylcorstart, intermed[i]) != NULL)
                {
                    result[j++] = '|';
                    kv = 0 ;
                    schwav = 0 ;
                    slkns = 0 ;
                    statistics("INSERTED BOUNDARY BETWEEN NUCLEI") ;
                    if (intermed[i] != '=' && intermed[i] != '@' && gs_include)
                        result[j++] = '?';
                }
                result[j++] = intermed[i];
                i++;
            }
            i--;
            continue;
        }
    }
    for (l = 0; l < k; l++)
        result[j++] = syl[l];
    result[j++] = '|';
    result[j] = '\0';
    CLEAR(in);
    CLEAR(intermed) ;
    statistics("Syllable Borders Result " << result) ;
    return result;
}


////////////////////////////////////////////////////////////////////////////////////////

char* PTRA::accents (char* in)
{
    char* result = NULL;
    int sylnr = 1;
    int i, j;
    int len = strlen(in);
    for (i = j = 0; i < len; i++)
        if (in[i] == '\'')
            j++;
    if (j != 0)
    {
        return in;
    }
    // Silbenzahl
    for (i = 0; i < len; i++)
        if (in[i] == '|')
            sylnr++;
    ALLOCATE(char, result, len + 5 + sylnr);
    statistics("In Accents " << sylnr << " Syllables in " << len << " Characters found") ;
    // Hauptakzent auf erste betonbare Silbe
    for (i = 0; i < len; i++)
        if (strchr(ipa_sylcor, in[i]) != NULL && in[i] != '@')
            break;
    if (i == len)
        for (i = 0; i < len; i++)
            if (strchr(ipa_sylcor, in[i]) != NULL)
                break;
    if (i < len)
    {
        for (j = i; j > -1; j--)
            if (in[j] == '|')
                break;
        strncpy(result, in, j+1);
        result[++j] = '\'';
        strcpy(&result[j+1], &in[j]);
    }
    // Mehr als 3 Silben: Nebenakzent auf erste betonbare Silbe nach der n/2-ten Silbe
    if (sylnr > 3)
    {
        for (i = j = 0; j < len; j++)
        {
            if (in[j] == '|')
                i++;
            if (i == sylnr/2)
                break;
        }
        for (i = j; i < len; i++)
            if (strchr(ipa_sylcor, in[i]) != NULL && in[i] != '@')
                break;
        if (i < len)
        {
            for (j = i; j > 0; j--)
                if (in[j] == '|')
                    break;
            result[j+2] = ',';
            strcpy(&result[j+3], &in[j+1]);
        }
    }
    CLEAR(in);
    statistics("Accents result " << result) ;
    return result;
}



////////////////////////////////////////////////////////////////////////////////////////

static bool ispace (char c)
{
    if (c == '\n' || c == '\t' || c == ' ')
        return true;
    return false;
}


////////////////////////////////////////////////////////////////////////////////////////

static bool turn (char* in, int len)
{
    if (len < 1)
        return false;
    statistics("turn (char *in = \"" << in << "\", int len = " << len << ");");
    char* inter = NULL;
    DUPLICATE(inter, in);
    int i, k = 0, l, m, n, ipos = 0;
    for (i = 0; i < len; i++)
    {
        if (in[i] == ')')
            k--;
        if (in[i] == '(')
            k++;
        if (in[i] == ',' && k == 0)
            break;
    }
    // Frage: Muß jede öffnende Klammer auch wieder geschlossen werden?
    assert(k == 0);
    for (int j = i - 1; j > -1; j--)
    {
        assert(j >= 0 && j < len);
        switch (in[j])
        {
            case '>':
            {
                int k = 0;
                for (l = j; l > -1; l--)
                {
                    assert(l >= 0 && l < len);
                    if (in[l] == '>')
                        k++;
                    if (in[l] == '<')
                        k--;
                    if (k == 0)
                        break;
                }
                assert(l - 1 >= 0 && l - 1 < len);
                if (in[l - 1] == '-')
                {
                    l--;
                }
                for (k = l; k <= j; k++)
                {
                    assert(ipos >= 0 && ipos < len);
                    assert(k    >= 0 && k    < len);
                    inter[ipos++] = in[k];
                }
                j = l;
                break;
            }
            case ')' :
            {
                int k = 0;
                for (l = j; l > -1; l--)
                {
                    assert(l >= 0 && l < len);
                    if (in[l] == ')')
                        k++;
                    if (in[l] == '(')
                        k--;
                    if (k == 0)
                        break;
                }
                m = ipos + 1;
                n = 0;
                assert(l - 1 >= 0 && l - 1 < len);
                if (in[l - 1] == '-')
                {
                    m++;
                    n = 1;
                    l--;
                }
                for (k = l; k <= j; k++)
                {
                    assert(ipos >= 0 && ipos < len);
                    assert(k    >= 0 && k    < len);
                    inter[ipos++] = in[k];
                }
                assert(m               >= 0 && m               < len);
                assert(j - (l + 1 + n) >= 0 && j - (l + 1 + n) < len);
                turn(&inter[m], j - (l + 1 + n));
                j = l;
                break;
            }
            default:
            {
                int k = -1;
                for (l = j; l > -1; l--)
                {
                    assert(l >= 0 && l < len);
                    if (in[l] == ')' || in[l] == '>')
                        break;
                    if (in[l] == '-')
                    {
                        k = l;
                        break;
                    }
                }
                if (k > -1)
                {
                    for (k = l; k <= j; k++)
                    {
                        assert(ipos >= 0 && ipos < len);
                        assert(k    >= 0 && k    < len);
                        inter[ipos++] = in[k];
                    }
                    assert(     l + 1  >= 0 &&      l + 1  < len);
                    assert(j - (l + 1) >= 0 && j - (l + 1) < len);
                    turn(&inter[l + 1], j - (l + 1));
                    j = l;
                    break;
                }
                assert(j - 1 >= 0 && j - 1 < len);
                if (j > 0 && in[j - 1] == '@')
                {
                    assert(ipos >= 0 && ipos < len);
                    inter[ipos++] = '@';
                    assert(ipos >= 0 && ipos < len);
                    assert(j    >= 0 && j    < len);
                    inter[ipos++] = in[j];
                    j--;
                    break;
                }
                assert(ipos >= 0 && ipos < len);
                assert(j    >= 0 && j    < len);
                inter[ipos++] = in[j];
            }
        }
    }
    assert(ipos >= 0 && ipos < len);
    assert(i    >= 0 && i    < len);
    assert(ipos + (int)strlen(&in[i]) < len);
    strcpy(&inter[ipos], &in[i]);
    assert(ipos + 1 >= 0 && ipos + 1 < len);
    assert(len - (i + 1) >= 0 && len - (i + 1) < len);
    turn(&inter[ipos + 1], len - (i + 1));
    if (strlen(inter) > strlen(in))
        ERRMSG("String 'inter' ist l?nger als String 'in'");
    strncpy(in, inter, len);
    CLEAR(inter);
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////

int find (char* rule, char* in, int &rulpos, int &inpos, int modus, Klassenliste* kl)
{
    int i, j, k, l;
    int len = strlen(rule);
    int oldinpos = inpos;
    int found, finished;
    char* rul = NULL;
    char name[10];
    k = 0;
    for (i = rulpos; i < len; i++)
    {
        if (rule[i] == ')')
            k--;
        if (rule[i] == '(')
            k++;
        if (rule[i] == ',' && k == 0)
            break;
    }
    if (i == rulpos)
        return 1;
    found = 1;
    finished = 0;
    for (j = rulpos; j < i; j++)
    {
        switch (rule[j])
        {
            case '<' :
                k = j;
                if (rule[j+1] == '<')
                    k++;
                for (l = k+1; rule[l] != '>' && rule[l] != ';'; l++)
                    name[l-(k+1)] = rule[l];
                name[l-(k+1)] = '\0';
//              printf("%s\n",name);
                if (!kl->ismember(in[inpos], name, modus))
                {
                    found = 0;
                    break;
                }
                if (rule[l] == ';')
                    while (rule[++l] != '>')
                    {
                        if (rule[l] == ';')
                            continue;
                        if (in[inpos]==rule[l])
                            found = 0;
                    }
                if (k > j)
                {
                    inpos ++;
                    if (in[inpos] != in[inpos-1])
                        found = 0;
                    l++;
                }
                inpos++;
                j = l;
                break;
            case '(' :
            {
                k = 0;
                for (l=j; rule[l] != ')' || k != 1; l++)
                {
                    if (rule[l] == '(')
                        k++;
                    if (rule[l] == ')')
                        k--;
                }
                char* rul = NULL;
                ALLOCATE(char, rul, len + 1);
                strcpy(rul, rule);
                rul[l] = '\0';
                found = find(rul, in, ++j, inpos, modus, kl);
                CLEAR(rul);
                j = l;
                break;
            }
            case '\0' :
            case ',' :
            case ')' :
                finished = 1;
                break;
            case '$' :
                inpos++;
                break;
            case '-' :
                k = 0;
                for (l=j; l < len; l++)
                {
                    if (rule[l] == '(')
                        k++;
                    if (rule[l] == ')')
                        k--;
                    if ((rule[l] == ','&&k==0)||rule[l]=='\0')
                        break;
                }
                ALLOCATE(char, rul, len + 1);
                strcpy(rul, rule);
                rul[l] = '\0';
                found = 1 - find(rul, in, ++j, inpos, modus, kl);
                CLEAR(rul);
                j = l;
                break;
            case '@' :
                j++;
                if (in[inpos++] == rule[j])
                    found = 0;
                break;
            default:
                if (in[inpos++] != rule[j])
                    found = 0;
        }
        if (finished|| found==0 )
            break;
    }
    if (i == len || found)
        return found;
    rulpos = i+1;
    inpos = oldinpos;
    found |= find(rule, in, rulpos, inpos, modus, kl);
    return found;
}


////////////////////////////////////////////////////////////////////////////////////////

Klassenliste::Klassenliste (const TFile &rulefile)
{
    Klasse k;
    char* begin;
    errorvalue.name[0] = '\0';
    int i = 0;
    unsigned int l ;
    rulefile.Rewind();
    char buffer[200];
    while (rulefile.GetS(buffer, sizeof(buffer)) != NULL)
    {
        for (l=0 ; l < strlen(buffer) ; l++)
            buffer[l] = (char)decode((unsigned char)buffer[l]) ;
        if ((begin = strchr((char*)buffer, '!')) != NULL)
        {
            i = 0;
            begin++;
            while (!ispace(begin[0]))
            {
                k.name[i++] = begin[0];
                begin++;
            }
            k.name[i] = '\0';
            i = 0;
            while (begin[0] != '\n' && begin[0] != '*')
            {
                if (!ispace(begin[0]) && begin[0] != ',')
                    k.members[i++] = begin[0];
                begin++;
            }
            k.members[i] = '\0';
            append(k);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////

int Klassenliste::ismember (char input, char* name, int modus)
{
    Klasse k;
    reset();
    while ((k = get_and_advance()).name[0] != '\0')
    {
        if (strcomp(k.name, name) == 0)
        {
            if (strchr((char*)k.members, (modus == 1 ? ucase(input) : input)) == NULL)
                return 0;
            else
                return 1;
        }
    }
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////

Regelliste::Regelliste (char letter, const TFile &rulefile)
{
    Regel r;
    int j, nopostcontext, k;
    char buffer[200];
    char* begin = NULL, *end = NULL, *ci = NULL;
    trace = 0 ;
    errorvalue.suchtext = NULL;
    // Suche Start
    rulefile.Rewind();
    while (rulefile.GetS(buffer, sizeof(buffer)) != NULL)
    {
        for (k=0 ; k < (int)strlen(buffer) ; k++)
            buffer[k] = (char)decode((unsigned char)buffer[k]) ;
        begin = strchr((char*)buffer, '*');
        if (begin != NULL)
            begin[0] = '\0';
        if ((begin = strchr((char*)buffer, '.')) == NULL)
            continue;
        if (begin[1] != letter)
            continue;
        break;
    }
    // bis Fileende
    while (rulefile.GetS(buffer, sizeof(buffer)) != NULL)
    {
        for (k=0 ; k < (int)strlen(buffer) ; k++)
            buffer[k] = (char)decode((unsigned char)buffer[k]) ;
        begin = strchr((char*)buffer, '*');
        if (begin != NULL)
            begin[0] = '\0';
        if (strchr((char*)buffer, '.') != NULL)
            break;
        if (strlen(buffer) < 6)
            continue;
        if (strchr((char*)buffer, '.') != NULL)
            break;
        r.precontext = NULL;
        end = NULL;
        begin = strchr((char*)buffer, '\"');
        if (begin != NULL)
        {
            r.precontextmodus = 1;
            end = strchr(&begin[1], '\"');
            if (end == NULL)
            {
//#pragma message Incorrect format-string for printf
//              printf("prec %s fucked up\n");
                exit(EXIT_FAILURE);
            }
            ALLOCATE(char, r.precontext, end - begin);
            j = 0;
            for (ci = begin + 1; ci < end; ci++)
                if (!ispace(*ci) && j < (end - (begin + 1)))
                    r.precontext[j++] = *ci;
            r.precontext[j] = '\0';
        }
        begin = strchr((char*)buffer, '/');
        if (begin != NULL)
        {
            r.precontextmodus = 0;
            end = strchr(&begin[1], '/');
            if (end == NULL)
            {
//#pragma message Incorrect format-string for printf
//              printf("prec2 %s fucked up\n");
                exit(EXIT_FAILURE);
            }
            ALLOCATE(char, r.precontext, end - begin);
            j = 0;
            for (ci = begin + 1; ci < end; ci++)
                if (!ispace(*ci) && j < (end - (begin + 1)))
                    r.precontext[j++] = *ci;
            r.precontext[j] = '\0';
        }
        begin = strchr((char*)buffer, '[');
        if (begin != NULL)
        {
            r.precontextmodus = 0;
            end = strchr(&begin[1], ']');
            if (end == NULL)
            {
//#pragma message Incorrect format-string for printf
//              printf("prec3 %s fucked up\n");
                exit(EXIT_FAILURE);
            }
            ALLOCATE(char, r.precontext, end - begin);
            j = 0;
            for (ci = begin + 1; ci < end; ci++)
                if (!ispace(*ci) && j < (end - (begin + 1)))
                    r.precontext[j++] = *ci;
            r.precontext[j] = '\0';
        }
        /*
        		if (r.precontext != NULL)
        			turn(r.precontext, strlen(r.precontext));
        */
        begin = (end != NULL) ? end : (char*)buffer;
        r.suchtext = NULL;
        end = strchr(begin, '&');
        nopostcontext = 0;
        if (end == NULL)
        {
            nopostcontext = 1;
            end = strchr(begin, '=');
            if (end == NULL)
            {
//#pragma message Incorrect format-string for printf
//              printf("npc %s fucked up\n");
                exit(EXIT_FAILURE);
            }
        }
        ALLOCATE(char, r.suchtext, end - begin);
        j = 0;
        r.ucasesuchtext = 1;
        for (ci = begin + 1; ci < end; ci++)
            if (!ispace(*ci) && j < (end - (begin + 1)))
            {
                r.suchtext[j++] = *ci;
//              if (*ci == ',')
//                  printf("%s\n", buffer);
                if (ucase(*ci) != *ci)
                    r.ucasesuchtext = 0;
            }
        r.suchtext[j] = '\0';
        r.postcontext = NULL;
        begin = end;
        if (nopostcontext == 0)
        {
            end = strchr(begin, '=');
            if (end == NULL)
            {
//#pragma message Incorrect format-string for printf
                fprintf(errfile, "%s fucked up\n", buffer);
                fflush(errfile) ;
                exit(EXIT_FAILURE);
            }
            ALLOCATE(char, r.postcontext, end - begin);
            j = 0;
            for (ci = begin+1; ci < end; ci++)
                if (!ispace(*ci) && j < (end - (begin + 1)))
                    r.postcontext[j++] = *ci;
            r.postcontext[j] = '\0';
            begin = end;
        }
        r.result = NULL;
        end = strchr(begin, '\n');
        if (end == NULL)
        {
            end = strchr(begin, '\0');
            if (end == NULL)
            {
//#pragma message Incorrect format-string for printf
//              printf("result %s fucked up\n");
                fprintf(errfile, "%s fucked up\n", buffer);
                fflush(errfile) ;
                exit(EXIT_FAILURE);
            }
        }
        ALLOCATE(char, r.result, end - begin);
        j = 0;
        for (ci = begin + 1; ci < end; ci++)
            if (!ispace(*ci) && j < (end - (begin + 1)))
                r.result[j++] = *ci;
        r.result[j] = '\0';
        append(r);
    }
}


////////////////////////////////////////////////////////////////////////////////////////

Regelliste::~Regelliste()
{
    Regel r;
    reset();
    while ((r = get_and_advance()).suchtext != NULL)
    {
        if (r.suchtext != NULL)
            CLEAR(r.suchtext);
        if (r.result != NULL)
            CLEAR(r.result);
        if (r.precontext != NULL)
            CLEAR(r.precontext);
        if (r.postcontext != NULL)
            CLEAR(r.postcontext);
    }
}


////////////////////////////////////////////////////////////////////////////////////////

int Regelliste::matcher (char* grapheme, int &graphempos, char* phoneme, int &phonempos, Klassenliste* kl)
{
    Regel r;
    int i, j;
    reset();
    char* revbuf = NULL;
    int a, b;
    while ((r = get_and_advance()).suchtext != NULL)
    {
        j = strlen(r.suchtext);
        for (i = 0; i < j; i++)
            if ((r.ucasesuchtext ? ucase(grapheme[i + graphempos]) : grapheme[i + graphempos]) != r.suchtext[i])
                break;
        if (i < j)
            continue;
        if (r.postcontext != NULL)
        {
            ALLOCATE(char, revbuf, strlen(r.postcontext) + 1);
            strncpy(revbuf, &grapheme[j + graphempos], strlen(r.postcontext));
            revbuf[strlen(r.postcontext)] = '\0';
            for (i = 0; i < (int)strlen(revbuf); i++)
                revbuf[i] = ucase(revbuf[i]);
            a = b = 0;
            if (find(r.postcontext, revbuf, a, b, 1, kl) == 0)
            {
                if (trace > 2)
                    fprintf(errfile, "        postct %s not found in %s\n", r.postcontext, revbuf);
                CLEAR(revbuf);
                continue;
            }
            CLEAR(revbuf);
        }
        if (r.precontext != NULL)
        {    
            if (r.precontextmodus == 0)
            {
                ALLOCATE(char, revbuf, phonempos + 1);
                strncpy(revbuf, phoneme, phonempos);
                revbuf[phonempos] = '\0';
                strrev(revbuf);
                a = b = 0;
                if (find(r.precontext, revbuf, a, b, 0, kl) == 0)
                {
                    if (trace > 2)
                        fprintf(errfile, "        prect %s not found in %s\n", r.precontext, revbuf);
                    CLEAR(revbuf);
                    continue;
                }
                CLEAR(revbuf);
            }
            else
            {
                ALLOCATE(char, revbuf, graphempos + 1);
                strncpy(revbuf, grapheme, graphempos);
                revbuf[graphempos] = '\0';
                strrev(revbuf);
                a = b = 0;
                if (find(r.precontext, revbuf, a, b, 1, kl) == 0)
                {
                    if (trace > 2)
                        fprintf(errfile, "        prect %s not found in %s\n", r.precontext, revbuf);
                    CLEAR(revbuf);
                    continue;
                }
                CLEAR(revbuf);
            }
        }    
        strcpy(&phoneme[phonempos], r.result);
        phonempos += strlen(r.result) /*-1*/ ;
        // OBEN KOMISCH
        graphempos += j;
        if (trace > 1)
            fprintf(errfile, "  %d:%s  /  %s  / %s  -> %s\n", r.precontextmodus, r.precontext, r.suchtext, r.postcontext, r.result);
        return 1;
    }
    return 0;
}


////////////////////////////////////////////////////////////////////////////////////////

PTRA::PTRA (const string &datapath, const string &basename) :
    kli(NULL),
    rl(NULL),
    letters("ABCDEFGHIJKLMNOPQRSTUVWXYZßÄÜÖ")
{
    unsigned int i;
    const TFile rulefile(datapath + basename + ".scr");
    if (!rulefile.Open('b'))
        ERRMSG("Konnte " << rulefile.Filename() << " nicht öffnen");
    #ifdef _Windows
    try
    #endif
    {
        kli = new Klassenliste(rulefile);
    }
    #ifdef _Windows
    catch (xalloc)
    #else
    if (kli == NULL)
    #endif
    {
        rulefile.Close();
        ERRMSG("Speicheranforderung fNr Zeiger 'kli' fehlgeschlagen");
    }
    #ifdef _Windows
    try
    #endif
    {
        rl = new Regelliste *[strlen(letters)];
        for (i = 0; i < strlen(letters); i++)
            rl[i] = NULL;
    }
    #ifdef _Windows
    catch (xalloc)
    #else
    if (rl == NULL)
    #endif
    {
        delete kli;
        rulefile.Close();
        ERRMSG("Speicheranforderung fNr Zeiger 'rl' fehlgeschlagen");
    }
    #ifdef _Windows
    try
    #endif
    {
        for (i = 0; i < strlen(letters); i++)
            rl[i] = new Regelliste(letters[i], rulefile);
    }
    #ifdef _Windows
    catch (xalloc)
    {
        for (j = 0; j < i; i++)
            delete rl[i];
        delete[] rl;
        delete kli;
        rulefile.Close();
        ERRMSG("Speicheranforderung fNr Zeiger rl[" << i << "] fehlgeschlagen");
    }
    #endif
    rulefile.Close();
}


////////////////////////////////////////////////////////////////////////////////////////

PTRA::~PTRA ()
{
    statistics("PTRA::~PTRA ()");
    delete kli;
    for (unsigned int i = 0; i < strlen(letters); i++)
        delete rl[i];
    delete[] rl;
}


////////////////////////////////////////////////////////////////////////////////////////

char* PTRA::transcribe (const char* word)
{
    int i = 0, j = 0;
    char* isword = NULL;
    statistics("IN PTRA " << word) ;
    //	kl = kli;
    ALLOCATE(char, isword, strlen(word) * 2 + 5);
    isword[j++] = '#';
    while (word[i] != '\0')
    {
        switch (word[i])
        {
            case 'é':
            case 'É':
                isword[j++] = 'e';
                isword[j++] = 'e';
                break;
            case 'è':
            case 'È':
                isword[j++] = 'ä';
                isword[j++] = 'h';
                break;
            case 'ê':
            case 'Ê':
                isword[j++] = 'ä';
                break;
            case 'à':
            case 'á':
            case 'â':
            case 'Á':
            case 'À':
            case 'Â':
                isword[j++] = 'a';
                break;
            case 'ú':
            case 'ù':
            case 'û':
            case 'Ù':
            case 'Ú':
            case 'Û':
                isword[j++] = 'u';
                break;
            case 'ó':
            case 'ò':
            case 'ô':
            case 'Ò':
            case 'Ó':
            case 'Ô':
                isword[j++] = 'o';
                break;
            case 'í':
            case 'ì':
            case 'î':
            case 'Ì':
            case 'Í':
            case 'Î':
                isword[j++] = 'i';
                break;
            case 'ñ':
            case 'Ñ':
                isword[j++] = 'n';
                isword[j++] = 'j';
                break;
            default:
                if (strchr("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZßÄÜÖäüö", word[i]) != NULL)
                    isword[j++] = word[i];
        }
        i++;
    }
    isword[j++] = '#';
    isword[j++] = '\0';
    if (strlen(isword) < 3)
    {
        CLEAR(isword) ;
        return NULL ;
    }
    statistics("IN PTRA FIRST PREPROC " << isword) ;
    char* result = NULL;
    ALLOCATE(char, result, strlen(word) * 8 + 4);
    int gp = 1;
    int pp = 1;
    result[0] = '#';
    result[1] = '\0';
    while (isword[gp] != '#')
    {
        for (i = 0; i < 30; i++)
            if (letters[i] == ucase(isword[gp]))
            {
                rl[i]->matcher(isword, gp, result, pp, kli);
                break;
            }
        if (i == 30)
            break;
    }
    CLEAR(isword);
    statistics("IN PTRA STUFE 1 " << result) ;
    char* res = NULL;
    int sylcor = 0 ;
    ALLOCATE(char, res, strlen(result)+5);
    for (i = j = 0; i < (int)strlen(result); i++)
    {
        if (strchr(ipa_sylcor, result[i]) != NULL)
            sylcor = 1 ;
        if (strchr("'#,", result[i]) == NULL && result[i] != 0x0d)
            res[j++] = result[i];
    }
    if (sylcor == 0)
        res[j++] = '@' ;
    res[j] = '\0';
    CLEAR(result);
    DUPLICATE(result, res);
    CLEAR(res);
    statistics("LEAVING PTRA " << result) ;
    return result;
}

