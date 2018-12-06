/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#include "lisatalk.h"
#if !defined(__UNIT_H__)
    #include "unit.h"
#endif
#include <string.h>

//#define DEBUG2


const int PREFIXNR = 47 ;
const char prefix[PREFIXNR][6] =
{
    "pfi:", "pfu:", "skla:", "skle:", "tli:", "tlu:",
    "SplI", "SplO", "pfli:", "pflu:",
    "spli:", "splo:", "pfRi:", "pfrO", "SpRi:", "SpRU", "skRi:", "skRU",
    "stRI", "stRu:", "StRi:", "StRU", "pnI", "pnO", "tnU", "pmi:",
    "pmu:", "tmi:", "tmu:", "pvI", "pvU", "tvi:", "tvU", "pjE:", "pju:",
    "kjE:", "kjU", "kSi:", "kSu:", "gnU", "gnI", "g0nU", "g0nI",
    "SlY", "vRI", "vRU"
} ;

static const char* listsounds = "bdgptkvzZjfsSCxmnNlRh6X" ;
const char* exceptionlist [22][23] =
{
    {"bv.k", "bd.k", "bg.k", "bv.k", "bd.k", "bg.k", "bv.k", "bz.k", "bZ.k", "bj.k", "bv.k", "bd.k", "bd.k", "bg.k", "bg.k", "b=m.l", "b=n.l", "bN.k", "blE:.a", "bRE:.a", "bg.k", "-", "bd.k"},
    {"db.k", "dz.k", "dg.k", "db.k", "dz.k", "dg.k", "dv.k", "dz.k", "dZE:.a", "dj.k", "db.k", "dz.k", "dz.k", "dg.k", "dg.k", "dm.k", "d=n.l", "dN.k", "d=l.l", "dRE:.a", "dg.k", "-", "db.k"},
    {"gb.k", "gd.k", "gj.k", "gb.k", "gd.k", "gj.k", "gv.k", "gz.k", "gZ.k", "gj.k", "gb.k", "gd.k", "gd.k", "gj.k", "gj.k", "gmE:.a", "gnE:.a", "g=N.l", "glE:.a", "gRE:.a", "gj.k", "-", "gd.k"},
    {"Epf.s", "Ept.s", "Epk.s", "Epf.s", "Ept.s", "Epk.s", "pvU.a", "psa:.a", "pZ.k", "pjE:.a", "pfi:.a", "psa:.a", "EpS.s", "Epk.s", "Epk.s", "pmi:.a", "pnI.a", "pN.k", "plE:.a", "pRE:.a", "ph0.k", "-", "Ep.e"},
    {"Etp.s", "Ets.s", "Etk.s", "Etp.s", "Ets.s", "Etk.s", "tvi:.a", "tsE:.a", "EtS.s", "tjE:.a", "Etp.s", "Ets.s", "EtS.s", "Etk.s", "Etk.s", "tmi:.a", "tnU.a", "tN.k", "tli:.a", "tRE:.a", "th0.k", "-", "Et.e"},
    {"Ekp.s", "Ekt.s", "EkS.s", "Ekp.s", "Ekt.s", "EkS.s", "kvE:.a", "ksE:.a", "kZ.k", "kjE:.a", "Ekp.s", "ksE:.a", "EkS.s", "EkS.s", "EkS.s", "kmi:.a", "knE:.a", "k=N.l", "klE:.a", "kRE:.a", "kh0.k", "-", "Ek.e"},
    {"vb.k", "vd.k", "vg.k", "vp.k", "vt.k", "vk.k", "vp.k", "vz.k", "vZ.k", "vj.k", "vp.k", "vt.k", "vt.k", "vk.k", "vk.k", "vm.k", "v=n.l", "vN.k", "v=l.l", "vRa:.a", "vh.k", "-", "vb.k"},
    {"zb.k", "zd.k", "zg.k", "zp.k", "zt.k", "zk.k", "zv.k", "zd.k", "zd.k", "zj.k", "zp.k", "zt.k", "zt.k", "zk.k", "zk.k", "zm.k", "z=n.l", "zN.k", "z=l.l", "zR.k", "zh.k", "-", "zd.k"},
    {"Zb.k", "Zd.k", "Zg.k", "Zp.k", "Zt.k", "Zk.k", "Zv.k", "Zz.k", "Zz.k", "Zj.k", "Zp.k", "Zt.k", "Zt.k", "Zk.k", "Zk.k", "Zm.k", "Zn.k", "ZN.k", "Zl.k", "ZR.k", "Zh.k", "-", "Zd.k"},
    {"jb.k", "jd.k", "jg.k", "jp.k", "jt.k", "jk.k", "jv.k", "jz.k", "jZ.k", "jk.k", "jp.k", "jt.k", "jt.k", "jk.k", "jk.k", "jm.k", "jn.k", "jN.k", "jl.k", "jR.k", "jh.k", "-", "jk.k"},
    {"Efp.s", "Eft.s", "Efk.s", "Efp.s", "Eft.s", "Efk.s", "fv0.k", "Eft.s", "fZ.k", "fj0.k", "Efp.s", "Eft.s", "Eft.s", "Efk.s", "Efk.s", "f=m.l", "f=n.l", "fN.k", "flE:.a", "fRE:.a", "fh0.k", "-", "Ef.s"},
    {"Esp.s", "Est.s", "Esk.s", "Esp.s", "Est.s", "Esk.s", "svE:.a", "Est.s", "sZ.k", "sj0.k", "Esp.s", "Est.s", "Est.s", "Esk.s", "Esk.s", "smO.a", "snI.a", "sN.k", "slE:.a", "sR0.k", "sh0.k", "-", "Es.s"},
    {"ESp.s", "ESt.s", "ESk.s", "ESp.s", "ESt.s", "ESk.s", "SvE:.a", "ESt.s", "SZ.k", "Sj0.k", "ESp.s", "ESt.s", "ESt.s", "ESk.s", "ESk.s", "SmE:.a", "SnE:.a", "SN.k", "SlE:.a", "SRE:.a", "Sh0.k", "-", "ES.s"},
    {"ECp.s", "ECt.s", "ECk.s", "ECp.s", "ECt.s", "ECk.s", "Cv0.k", "ECt.s", "CZ.k", "Cj0.k", "ECp.s", "ECt.s", "ECt.s", "ECk.s", "ECk.s", "Cm.k", "C=n.l", "CN.k", "C=l.l", "CR0.k", "Ch0.k", "-", "EC.e"},
    {"axp.s", "axt.s", "axk.s", "axp.s", "axt.s", "axk.s", "xv0.k", "axt.s", "xZ.k", "xj0.k", "axp.s", "axt.s", "axt.s", "axk.s", "axk.s", "xm.k", "x=n.l", "xN.k", "x=l.l", "xR0.k", "xh0.k", "-", "Ux.e"},
    {"mb.k", "md.k", "mg.k", "Emp.e", "Emt.e", "mk.k", "mv.k", "mz.k", "mZ.k", "mj.k", "Emp.e", "Emt.e", "Emt.e", "mk.k", "mk.k", "Emp.e", "mn.k", "mN.k", "ml.k", "mR.k", "mh.k", "-", "Em.e"},
    {"nb.k", "nd.k", "ng.k", "Enp.e", "Ent.e", "Enk.e", "nv.k", "nz.k", "nZ.k", "nj.k", "Enp.e", "Ent.e", "Ent.e", "Enk.e", "Enk.e", "nm.k", "Ent.e", "ng.k", "nl.k", "nR.k", "nh.k", "-", "En.e"},
    {"Nb.k", "Nd.k", "Ng.k", "Np.k", "ENt.e", "ENk.e", "Nv.k", "Nz.k", "NZ.k", "Nj.k", "Np.k", "ENt.e", "ENt.e", "ENk.e", "ENk.e", "Nm.k", "Nn.k", "ENk.e", "Nl.k", "NR.k", "Nh.k", "-", "EN.e"},
    {"lb.k", "ld.k", "lg.k", "Elp.e", "Elt.e", "Elk.e", "lv.k", "lz.k", "lZ.k", "lj.k", "Elp.e", "Elt.e", "Elt.e", "Elk.e", "Elk.e", "Elm.e", "@ln.e", "lN.k", "Elt.e", "lR.k", "lh.k", "-", "El.e"},
    {"Rb.k", "Rd.k", "Rg.k", "ERp.e", "ERt.e", "ERk.e", "Rv.k", "Rz.k", "RZ.k", "Rj.k", "ERp.e", "ERt.e", "ERt.e", "ERC.e", "ERk.e", "ERm.e", "ERn.e", "RN.k", "ERl.e", "ERk.e", "Rh.k", "-", "ER.e"},
    {"hU.a", "hI.a", "ha:.a", "hU.a", "hI.a", "ha:.a", "hU.a", "hI.a", "hE:.a", "ha:.a", "hU.a", "hI.a", "hE:.a", "hE:.a", "ha:.a", "hU.a", "hI.a", "ha:.a", "hI.a", "ha:.a", "ha:.a", "ha:.a", "h@.a"},
    {"E:6p.e", "E:6t.e", "E:6k.e", "E:6p.e", "E:6t.e", "E:6k.e", "E:6p.e", "E:6t.e", "E:6t.e", "E:6k.e", "E:6p.e", "E:6t.e", "E:6t.e", "E:6k.e", "E:6k.e", "=6m.e", "=6n.e", "=6.e", "=6l.e", "=6R.e", "=6.e", "=6.e" }
} ;

const int SOUNDNR = 87 ;
extern char sounds[SOUNDNR][4] ;

char assoc(char in)
{
    if (in == '\0')
        return ('\0') ;
    if (strchr("pbvfm", in) != NULL)
        return ('p') ;
    if (strchr("tdzZSnls", in) != NULL)
        return ('t') ;
    if (strchr("kgjCxNR", in) != NULL)
        return ('k') ;
    return (in) ;
}

char voicedassoc(char in)
{
    if (in == '\0')
        return ('\0') ;
    if (strchr("pbvfm", in) != NULL)
        return ('b') ;
    if (strchr("tdzZSnls", in) != NULL)
        return ('d') ;
    if (strchr("kgjCxNR", in) != NULL)
        return ('g') ;
    return (in) ;
}

int getlistsoundsnr(char c)
{
    for (unsigned int i = 0 ; i < strlen(listsounds) ; i++)
        if (listsounds[i] == c)
            return (i) ;
    return (-1) ;
}

int find_sound(char* &d)
{
    int i = -1 ;
    int pos = -1 ;
    int len = -1 ;
    int aktlen ;
    while (++i < SOUNDNR)
    {
        if ((aktlen = strlen(sounds[i])) <= len)
            continue ;
        if (strncmp(d, sounds[i], aktlen) == 0)
        {
            pos = i ;
            len = aktlen ;
        }
    }
    if (len != -1)
        d += len ;
    return (pos) ;
}

int soundcount(char* s)
{
    int i = 0 ;
    while (find_sound(s) != -1)
        i++ ;
    return (i) ;
}

char* get_first_sound(char* s, int offset = 0, int sim = 0)
{
    int a=0, i ;
    char* ret = new char[4] ;
    nulltest(ret) ;
    for (i=0 ; i <= offset; i++)
        a = find_sound(s) ;
    i = 0 ;
    if (sim)
    {
        ret[i] = '&' ;
        i++ ;
    }
    if (strchr("bdgptk", sounds[a][0]) != NULL)
    {
        ret[i] = '_' ;
        i++ ;
    }
    strcpy(&ret[i], sounds[a]) ;
    if (debuglevel>2)
        fprintf(errfile, "First Sound is %s\n", ret) ;
    return (ret) ;
}

char* get_last_sound(char* s, int offset = 0, int sim = 0)
{
    char* ret = new char[4] ;
    if (offset == 0)
    {
        strcpy(ret, "-") ;
        return (ret) ;
    }
    int a=0 ;
    nulltest(ret) ;
    int i, j = soundcount(s) - offset ;
    for (i=0 ; i <= j; i++)
        a = find_sound(s) ;
    i = 0 ;
    if (sim)
    {
        ret[i++] = '&' ;
    }
    if (strchr("bdgptk", sounds[a][0]) != NULL)
    {
        ret[i++] = '_' ;
    }
    strcpy(&ret[i], sounds[a]) ;
    if (debuglevel>2)
        fprintf(errfile, "Last Sound is %s\n", ret) ;
    return (ret) ;
}

int get_first_sound_index(char* s, char* t)
{
    int i = 0,  k = 0 ;
    char* r ;
    if (t[0] == '&')
        t++ ;
    while ( t[0] != s[i])
    {
        if (t[0] == '_')
        {
            t++ ;
            continue ;
        }
        r = &s[i] ;
        i += strlen(sounds[find_sound(r)]) ;
        k++ ;
    }
    return (k) ;
}

char* find_prefix(char* ahs, char* b)
{
    char* h = new char[strlen(ahs)+2] ;
    nulltest(h) ;
    int i, slen, vokstart, fallback = -1 ;
    for (slen=i=0 ; i < (int)strlen(ahs) ; i++)
        if (ahs[i] != '0')
            h[slen++] = ahs[i] ;
    h[slen] = '\0' ;
    char* start = strrchr(h, b[0]) ;
    int len = strlen(h) ;
    int rounded = 0, srounded = 0 ;
    if (start == NULL)
    {
        delete (h) ;
        return (NULL) ;
    }
    start-- ;
    if (strchr(":~", h[len-1]) != NULL)
    {
        vokstart = len-2 ;
        rounded = (strchr("uoy2", h[len-2]) != NULL) ;
    }
    else
    {
        vokstart = len-1 ;
        rounded = (strchr("OYU9", h[len-1]) != NULL) ;
    }
    h[vokstart] = '\0' ;
    for (i = 0 ; i < PREFIXNR ; i++)
        if (strstr(prefix[i], start) != 0)
        {
            if (strchr("aeiouEIOUYy29", prefix[i][strlen(start)]) == NULL)
                continue ;
            slen = strlen(prefix[i]) ;
            if (strchr(":~", prefix[i][slen-1]) != NULL)
            {
                srounded = (strchr("uoy2", prefix[i][slen-2]) != NULL) ;
            }
            else
            {
                srounded = (strchr("OYU9", prefix[i][slen-1]) != NULL) ;
            }
            if (srounded == rounded)
                break ;
            else
                fallback = i ;
        }
    delete[](h) ;
    if (i == PREFIXNR && fallback == -1)
        return (NULL) ;
    else if (i == PREFIXNR)
        return ((char*)prefix[fallback]) ;
    else
        return ((char*)prefix[i]) ;
}

