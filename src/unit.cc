
#include "lisatalk.h"
#if !defined(__UNIT_H__)
#include "unit.h"
#endif

//#define DEBUG2


const int PREFIXNR = 47 ;
const char prefix[PREFIXNR][6] = {
	"pfi:","pfu:","skla:","skle:","tli:","tlu:",
	"SplI","SplO","pfli:","pflu:",
	"spli:","splo:","pfRi:","pfrO","SpRi:","SpRU","skRi:","skRU",
	"stRI","stRu:","StRi:","StRU","pnI","pnO","tnU","pmi:",
	"pmu:","tmi:","tmu:","pvI","pvU","tvi:","tvU","pjE:","pju:",
	"kjE:","kjU","kSi:","kSu:","gnU","gnI","g0nU","g0nI",
	"SlY", "vRI", "vRU" } ;

static const char* plosives = "bdgptk" ;
static const char* listsounds = "bdgptkvzZjfsSCxmnNlRh6X" ;
const char* exceptionlist [22][23] =
{{"bv.k","bd.k","bg.k","bv.k","bd.k","bg.k","bv.k","bz.k","bZ.k","bj.k","bv.k","bd.k","bd.k","bg.k","bg.k","b=m.l","b=n.l","bN.k","blE:.a","bRE:.a","bg.k","-","bd.k"},
{"db.k","dz.k","dg.k","db.k","dz.k","dg.k","dv.k","dz.k","dZE:.a","dj.k","db.k","dz.k","dz.k","dg.k","dg.k","dm.k","d=n.l","dN.k","d=l.l","dRE:.a","dg.k","-","db.k"},
{"gb.k","gd.k","gj.k","gb.k","gd.k","gj.k","gv.k","gz.k","gZ.k","gj.k","gb.k","gd.k","gd.k","gj.k","gj.k","gmE:.a","gnE:.a","g=N.l","glE:.a","gRE:.a","gj.k","-","gd.k"},
{"Epf.s","Ept.s","Epk.s","Epf.s","Ept.s","Epk.s","pvU.a","psa:.a","pZ.k","pjE:.a","pfi:.a","psa:.a","EpS.s","Epk.s","Epk.s","pmi:.a","pnI.a","pN.k","plE:.a","pRE:.a","ph0.k","-","Ep.e"},
{"Etp.s","Ets.s","Etk.s","Etp.s","Ets.s","Etk.s","tvi:.a","tsE:.a","EtS.s","tjE:.a","Etp.s","Ets.s","EtS.s","Etk.s","Etk.s","tmi:.a","tnU.a","tN.k","tli:.a","tRE:.a","th0.k","-","Et.e"},
{"Ekp.s","Ekt.s","EkS.s","Ekp.s","Ekt.s","EkS.s","kvE:.a","ksE:.a","kZ.k","kjE:.a","Ekp.s","ksE:.a","EkS.s","EkS.s","EkS.s","kmi:.a","knE:.a","k=N.l","klE:.a","kRE:.a","kh0.k","-","Ek.e"},
{"vb.k","vd.k","vg.k","vp.k","vt.k","vk.k","vp.k","vz.k","vZ.k","vj.k","vp.k","vt.k","vt.k","vk.k","vk.k","vm.k","v=n.l","vN.k","v=l.l","vRa:.a","vh.k","-","vb.k"},
{"zb.k","zd.k","zg.k","zp.k","zt.k","zk.k","zv.k","zd.k","zd.k","zj.k","zp.k","zt.k","zt.k","zk.k","zk.k","zm.k","z=n.l","zN.k","z=l.l","zR.k","zh.k","-","zd.k"},
{"Zb.k","Zd.k","Zg.k","Zp.k","Zt.k","Zk.k","Zv.k","Zz.k","Zz.k","Zj.k","Zp.k","Zt.k","Zt.k","Zk.k","Zk.k","Zm.k","Zn.k","ZN.k","Zl.k","ZR.k","Zh.k","-","Zd.k"},
{"jb.k","jd.k","jg.k","jp.k","jt.k","jk.k","jv.k","jz.k","jZ.k","jk.k","jp.k","jt.k","jt.k","jk.k","jk.k","jm.k","jn.k","jN.k","jl.k","jR.k","jh.k","-","jk.k"},
{"Efp.s","Eft.s","Efk.s","Efp.s","Eft.s","Efk.s","fv0.k","Eft.s","fZ.k","fj0.k","Efp.s","Eft.s","Eft.s","Efk.s","Efk.s","f=m.l","f=n.l","fN.k","flE:.a","fRE:.a","fh0.k","-","Ef.s"},
{"Esp.s","Est.s","Esk.s","Esp.s","Est.s","Esk.s","svE:.a","Est.s","sZ.k","sj0.k","Esp.s","Est.s","Est.s","Esk.s","Esk.s","smO.a","snI.a","sN.k","slE:.a","sR0.k","sh0.k","-","Es.s"},
{"ESp.s","ESt.s","ESk.s","ESp.s","ESt.s","ESk.s","SvE:.a","ESt.s","SZ.k","Sj0.k","ESp.s","ESt.s","ESt.s","ESk.s","ESk.s","SmE:.a","SnE:.a","SN.k","SlE:.a","SRE:.a","Sh0.k","-","ES.s"},
{"ECp.s","ECt.s","ECk.s","ECp.s","ECt.s","ECk.s","Cv0.k","ECt.s","CZ.k","Cj0.k","ECp.s","ECt.s","ECt.s","ECk.s","ECk.s","Cm.k","C=n.l","CN.k","C=l.l","CR0.k","Ch0.k","-","EC.e"},
{"axp.s","axt.s","axk.s","axp.s","axt.s","axk.s","xv0.k","axt.s","xZ.k","xj0.k","axp.s","axt.s","axt.s","axk.s","axk.s","xm.k","x=n.l","xN.k","x=l.l","xR0.k","xh0.k","-","Ux.e"},
{"mb.k","md.k","mg.k","Emp.e","Emt.e","mk.k","mv.k","mz.k","mZ.k","mj.k","Emp.e","Emt.e","Emt.e","mk.k","mk.k","Emp.e","mn.k","mN.k","ml.k","mR.k","mh.k","-","Em.e"},
{"nb.k","nd.k","ng.k","Enp.e","Ent.e","Enk.e","nv.k","nz.k","nZ.k","nj.k","Enp.e","Ent.e","Ent.e","Enk.e","Enk.e","nm.k","Ent.e","ng.k","nl.k","nR.k","nh.k","-","En.e"},
{"Nb.k","Nd.k","Ng.k","Np.k","ENt.e","ENk.e","Nv.k","Nz.k","NZ.k","Nj.k","Np.k","ENt.e","ENt.e","ENk.e","ENk.e","Nm.k","Nn.k","ENk.e","Nl.k","NR.k","Nh.k","-","EN.e"},
{"lb.k","ld.k","lg.k","Elp.e","Elt.e","Elk.e","lv.k","lz.k","lZ.k","lj.k","Elp.e","Elt.e","Elt.e","Elk.e","Elk.e","Elm.e","@ln.e","lN.k","Elt.e","lR.k","lh.k","-","El.e"},
{"Rb.k","Rd.k","Rg.k","ERp.e","ERt.e","ERk.e","Rv.k","Rz.k","RZ.k","Rj.k","ERp.e","ERt.e","ERt.e","ERC.e","ERk.e","ERm.e","ERn.e","RN.k","ERl.e","ERk.e","Rh.k","-","ER.e"},
{"hU.a","hI.a","ha:.a","hU.a","hI.a","ha:.a","hU.a","hI.a","hE:.a","ha:.a","hU.a","hI.a","hE:.a","hE:.a","ha:.a","hU.a","hI.a","ha:.a","hI.a","ha:.a","ha:.a","ha:.a","h@.a"},
{"E:6p.e","E:6t.e","E:6k.e","E:6p.e","E:6t.e","E:6k.e","E:6p.e","E:6t.e","E:6t.e","E:6k.e","E:6p.e","E:6t.e","E:6t.e","E:6k.e","E:6k.e","=6m.e","=6n.e","=6.e","=6l.e","=6R.e","=6.e","=6.e" } } ;

const int SOUNDNR = 87 ;
extern char sounds[SOUNDNR][4] ;

char assoc(char in) {
	if (in == '\0')
		return('\0') ;
	if (strchr("pbvfm",in) != NULL)
		return('p') ;
	if (strchr("tdzZSnls",in) != NULL)
		return('t') ;
	if (strchr("kgjCxNR",in) != NULL)
		return('k') ;
	return(in) ; }

char voicedassoc(char in) {
	if (in == '\0')
		return('\0') ;
	if (strchr("pbvfm",in) != NULL)
		return('b') ;
	if (strchr("tdzZSnls",in) != NULL)
		return('d') ;
	if (strchr("kgjCxNR",in) != NULL)
		return('g') ;
	return(in) ; }

int getlistsoundsnr(char c) {
	for (unsigned int i = 0 ; i < strlen(listsounds) ; i++)
		if (listsounds[i] == c)
			return(i) ;
	return(-1) ; }

int find_sound(char*& d) {
	int i = -1 ;
	int pos = -1 ;
	int len = -1 ;
	int aktlen ;
	while (++i < SOUNDNR) {
		if ((aktlen = strlen(sounds[i])) <= len)
			continue ;
      if (strncmp(d,sounds[i],aktlen) == 0) {
			pos = i ;
			len = aktlen ; } }
	if (len != -1)
		d += len ;
	return(pos) ; }

int soundcount(char* s) {
	int i = 0 ;
	while (find_sound(s) != -1)
		i++ ;
	return(i) ; }

char* get_first_sound(char* s, int offset = 0, int sim = 0) {
	int a=0,i ;
	char* ret = new char[4] ;


	nulltest(ret) ;
	for (i=0 ; i <= offset; i++)
		a = find_sound(s) ;
	i = 0 ;
	if (sim) {
		ret[i] = '&' ;
		i++ ; }
	if (strchr("bdgptk",sounds[a][0]) != NULL) {
		ret[i] = '_' ;
		i++ ; }
	strcpy(&ret[i],sounds[a]) ;

if(debuglevel>2)
  fprintf(errfile,"First Sound is %s\n",ret) ;

	return(ret) ; }

char* get_last_sound(char* s, int offset = 0, int sim = 0) {
	char* ret = new char[4] ;
	if (offset == 0) {
		strcpy(ret,"-") ;
		return(ret) ; }
	int a=0 ;


	nulltest(ret) ;
	int i,j = soundcount(s) - offset ;
	for (i=0 ; i <= j; i++)
		a = find_sound(s) ;
	i = 0 ;
	if (sim) {
		ret[i++] = '&' ; }
	if (strchr("bdgptk",sounds[a][0]) != NULL) {
		ret[i++] = '_' ; }
	strcpy(&ret[i],sounds[a]) ;

if(debuglevel>2)
  fprintf(errfile,"Last Sound is %s\n",ret) ;

	return(ret) ; }

int get_first_sound_index(char* s, char* t) {
	int i = 0,  k = 0 ;
	char* r ;
	if (t[0] == '&')
		t++ ;
	while( t[0] != s[i]) {
		if (t[0] == '_') {
			t++ ;
			continue ; }
		r = &s[i] ;
		i += strlen(sounds[find_sound(r)]) ;
				k++ ; }
	return(k) ; }

char* find_prefix(char*ahs,char*b) {
	char* h = new char[strlen(ahs)+2] ;
	nulltest(h) ;
	int i,slen,vokstart,fallback = -1 ;

	for (slen=i=0 ; i < (int)strlen(ahs) ; i++)
		if (ahs[i] != '0')
			h[slen++] = ahs[i] ;
	h[slen] = '\0' ;
	char* start = strrchr(h,b[0]) ;
	int len = strlen(h) ;
	int rounded = 0, srounded = 0 ;
	if (start == NULL) {
		delete(h) ;
		return(NULL) ; }
	start-- ;
	if (strchr(":~",h[len-1]) != NULL) {
		vokstart = len-2 ;
		rounded = (strchr("uoy2",h[len-2]) != NULL) ; }
	else {
		vokstart = len-1 ;
		rounded = (strchr("OYU9",h[len-1]) != NULL) ; }
	h[vokstart] = '\0' ;
	for (i = 0 ; i < PREFIXNR ; i++)
		if (strstr(prefix[i],start) != 0) {
			if (strchr("aeiouEIOUYy29",prefix[i][strlen(start)]) == NULL)
				continue ;
			slen = strlen(prefix[i]) ;
			if (strchr(":~",prefix[i][slen-1]) != NULL) {
				srounded = (strchr("uoy2",prefix[i][slen-2]) != NULL) ; }
			else {
			srounded = (strchr("OYU9",prefix[i][slen-1]) != NULL) ; }
			if (srounded == rounded)
				break ;
			else
				fallback = i ; }
	delete[](h) ;
	if (i == PREFIXNR && fallback == -1)
		return(NULL) ;
	else
		if (i == PREFIXNR)
			return((char*)prefix[fallback]) ;
		else
			return((char*)prefix[i]) ; }

float soundcount(Unitinfo u) {
	float result = 0.0 ;
	int ssim = 0, esim = 0 ;
	int splosiv = 0, eplosiv = 0 ;
	int i,j ;
	if (u.startmark[0] == '&')
		ssim = 1 ;
	if (u.startmark[0] == '_')
		splosiv = 1 ;
	for (i = 0 ; i < 10 ; i++)
		if (u.name[i] == u.startmark[splosiv||ssim])
			break ;

	char* h = new char[10] ;
		nulltest(h) ;
	h = strcpy(h,&u.name[i]) ;
	if (u.endmark[0] == '-')
		j = strlen(h) ;
	else {
		if (u.endmark[0] == '&')
			esim = 1 ;
		if (u.endmark[0] == '_')
			eplosiv = 1 ;
		for (j = strlen(h) ; j > -1 ; j--)
			if (h[j] == u.endmark[eplosiv||esim])
				break ; }
	h[j] = '\0' ;
	eplosiv = 0 ;
	for (i=0 ; i < (int)strlen(h) ; i++)
		if (strchr("ptkbdg",h[i]) != NULL)
			eplosiv ++ ;
	result = soundcount(h) + (esim*0.5) - (ssim*0.5) + eplosiv ;
	delete[](h) ;
	return (result) ; }


Unitlist::Unitlist() {
	errorvalue.soundnr = 0 ;
	errorvalue.firstsound = -1 ; }

Unitlist::~Unitlist() { ; }

Unitinfo* Unitlist::get_unit_pointer() {
	return(&(act->i)) ; }


void Unitlist::build_sce(char* s, int n, int sk, int firstsound, Inventory& invent) {
	char ahs[256] ;
	char ehs[256] ;
	char leftover[256] ;
	char* sf ;
	char* nl2char ;
	char* dummy ;
	int i,j,k,extract = 0,pref = 0,gsinsert = 0 ;
	int sc = soundcount(s) ;
	float aktsound = 0.0 ;
	char truechar = 0 ;
	int notloesung = 0 ;
	int notloesung2 = 0 ;
	int notloesung3 = 0 ;
   int notloesung4 = 0 ;
   int notloesung5 = 0 ;
	Unitindex ue,up ;
	Unitinfo ui ;

if (debuglevel > 1) {
	fprintf(errfile,"sce: %s with sk %d\n",s,sk) ;
}


	if (strlen(s) < 1)
		return ;
	for (i=0 ; i < n ; i++)
		if (strchr("ptkbdg",s[i]) != NULL)
			sc++ ;

	// VORSILBE

	i = 0 ;
	if (s[sk] == '@' && s[sk+1] != '\0') {
		if (sk > 1 && (strncmp(&s[sk-2],"b0",2) == 0 || strncmp(&s[sk-2],"g0",2) == 0))
			i = 2 ;
		if (sk > 0 && strchr("bdg",s[sk-1]) != NULL)
			i = 1 ; }
	if (sk == 0)
		i = 0 ;
	if (i > 0) {
		strcpy(ahs,&s[sk-i]) ;
		ue = invent.find_unit(ahs,'p') ;
		extract = 0 ;
		truechar = ahs[i+1] ;
		if (ue.type == 'x') {
			ahs[i+1] = assoc(ahs[i+1]) ;
			extract = 1 ;
			ue = invent.find_unit(ahs,'p') ;
			ahs[i+1] = truechar ; }
		if (ue.type == 'x') {
			syndata_error("build_sce","unit 'p' not found",6) ;
			fprintf(errfile,"%s %s\n",s,ahs) ; }
		else {
			strcpy(leftover,s) ;
			leftover[sk-i] = '\0' ;
			aktsound += soundcount((char*)leftover) ;
			for (j=0 ; j < (int)strlen(leftover) ; j++)
				if (strchr("ptkbdg",leftover[j]) != NULL)
					aktsound++ ;
			strcpy(ui.name,ue.name) ;
			ui.type = 'p' ;
			dummy = get_first_sound(ue.name,0,0) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;
			dummy = get_last_sound(ue.name,extract,0) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;
			ui.soundnr = soundcount(ui) ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
			append(ui) ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as vs\n",ui.name,ui.type) ;
}

			goto suffix ;
			 } }

	// SILBISCHE KONSONANTEN

	if (s[sk] == '=' && s[sk+1] != '6') {
		pref = 0 ;
		if (s[sk-1]=='S' && s[sk-2] != 't') {
			pref = 1 ;
			strcpy(ahs,s) ;
			strcpy(&ahs[sk],&s[sk-1]) ;
			ahs[sk-1] = 't' ; }
		else
			strcpy(ahs,s) ;
		for (j = sk ; j < n ; j++)
			if (strchr("sSZzbvfdgjCx",ahs[j]) != NULL)
				break ;
		truechar = ahs[j] ;
		i = -1 ;
		do {
			i++ ;
			ahs[j] = truechar ;
			ue = invent.find_unit(&ahs[i],'l') ;
			extract = 0 ;
			if (ahs[i+1] == '0' && ue.type == 'x') {
				strcpy(ehs,&ahs[i+1]) ;
				ehs[0] = ahs[i] ;
				ue = invent.find_unit(ehs,'l') ; }
			if (j < n) {
				ahs[j] = assoc(ahs[j]) ;
				up = invent.find_unit(&ahs[i],'l') ;
				if (strlen(up.name) > strlen(ue.name)) {
					ue = up ;
					extract = 1 ; } } }
		while (ue.type == 'x' && i < n) ;
		if (ue.type == 'x' || ue.name[0] == '=') {
			fprintf(errfile,"Warning in Build_sce: unit 'l' not found ") ;
			fprintf(errfile,"%s %s\n",s,ahs) ;
			notloesung = 1 ;
			s[sk] = '@' ; }
		else {
			strcpy(leftover,ahs) ;
			leftover[i] = '\0' ;
			aktsound += soundcount((char*)leftover) ;
			for (j=0 ; j < (int)strlen(leftover) ; j++)
				if (strchr("ptkbdg",leftover[j]) != NULL)
					aktsound++ ;
			strcpy(ui.name,ue.name) ;
			ui.type = 'l' ;
			dummy = get_first_sound(ue.name,pref,0) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;
			dummy = get_last_sound(ue.name,extract,0) ;
			strcpy(ui.endmark,dummy) ;
			 delete[](dummy) ;
			ui.soundnr = soundcount(ui) ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as slk\n",ui.name,ui.type) ;
}

			append(ui) ;
			pref = 0 ;
			goto suffix ;
		 } }
	// ANFANGS-UND ENDHALBSILBEN

		gsinsert = 0 ;
		if (strchr("aeiouy29IUOEY=@",s[0]) != NULL) {
			gsinsert = 1 ;
			ahs[0]='?' ;
			strcpy(&ahs[1],s) ; }
		else if (s[0] == '6' && sk == 1) {
			gsinsert = 1 ;
			notloesung3 = 1 ;
			ahs[0]='?' ;

			strcpy(&ahs[1],&s[1]) ; }
		else
			strcpy(ahs,s) ;
if (debuglevel > 1) {
	fprintf(errfile,"ahs: %s\n",ahs) ;
}


		switch (ahs[sk+gsinsert-notloesung3]) {
			case 'a':
			case 'E':
				if (ahs[sk+1+gsinsert-notloesung3] != '~') {
					ahs[sk+1+gsinsert-notloesung3] = ':' ;
					ahs[sk+2+gsinsert-notloesung3] = '\0' ; }
				break ;
			case 'i':
         case '2':
         case 'u':
         case 'o':
         case 'y':
         case 'e':
				if (ahs[sk+1+gsinsert-notloesung3] != ':') {
					ahs[sk+1+gsinsert-notloesung3] = ':' ;
					ahs[sk+2+gsinsert-notloesung3] = '\0' ; }
            break ;
			case '9':
				if (ahs[sk+1+gsinsert-notloesung3] == ':')
					ahs[sk+1+gsinsert-notloesung3] = '\0' ;
				break ;
			case 'O':
				if (ahs[sk+1+gsinsert-notloesung3] == 'Y' || ahs[sk+1+gsinsert-notloesung3] == ':')
					ahs[sk+1+gsinsert-notloesung3] = '\0' ;
				break ; }
		if (strchr(":~6",ahs[sk+1+gsinsert-notloesung3]) != NULL)
			ahs[sk+2+gsinsert-notloesung3] = '\0' ;
		else
			ahs[sk+1+gsinsert-notloesung3] = '\0' ;
		if (ahs[sk+1+gsinsert-notloesung3] == '6' && ahs[sk+gsinsert-notloesung3] != '=')
			ahs[sk+1+gsinsert-notloesung3] = '\0' ;

		i = -1 ;
		do {
			ue = invent.find_unit(&ahs[++i],'a') ;
			k = 0 ;
			extract = 0 ;
			if (ue.type == 'x') {
				for (j = i ; j < (int)strlen(ahs) ; j++) {
					if (ahs[j] == '0' && k > 1) {
						extract = 1 ;
						continue ; }
					ehs[k++] = ahs[j] ; }
            ehs[k] = '\0' ;
				if (extract > 0)
					ue = invent.find_unit(ehs,'a') ; }
			extract = 0 ;
			if ((ue.type == 'x') && (ahs[i] == 's' ||
					 strncmp(&ahs[i],"z0",2) == 0 ||
					 strncmp(&ahs[i],"v0",2) == 0 ||
					 strncmp(&ahs[i],"j0",2) == 0 ||
					 strncmp(&ahs[i],"l0",2) == 0 ||
					 strncmp(&ahs[i],"R0",2) == 0)) {
				if (ahs[i] == 's') {
					ehs[0] = 't' ;
					strcpy(&ehs[1],&ahs[i]) ; }
				else {
					strcpy(ehs,&ahs[i]) ;
					switch (ehs[0]) {
						case 'v' : ehs[1] = 'v' ; ehs[0] = 'S' ; break ;
						case 'z' : ehs[1] = 's' ; ehs[0] = 't' ; break ;
						case 'j' : ehs[1] = 'j' ; ehs[0] = 't' ; break ;
						case 'l' : ehs[1] = 'l' ; ehs[0] = 'k' ; break ;
						case 'R' : ehs[1] = 'R' ; ehs[0] = 't' ; break ; } }
				extract = 1 ;
				ue = invent.find_unit(ehs,'a') ; }
			notloesung5 = 0 ;
			if (ue.type == 'x' && (dummy = strchr((char*)ahs,'~')) != NULL && strlen(&ahs[i])< 4) {
				strcpy(ehs,&ahs[i]) ;
				sf = strchr((char*)ehs,'~') ;
				if (*(sf-1)=='a' || *(sf-1)=='E')
				  *sf=':' ;
				else
				  *sf='\0' ;
				notloesung5 = 1 ;
				ue = invent.find_unit(ehs,'a') ; } 			
			notloesung2 = 0 ;
			nl2char = NULL ;
			if (ue.type == 'x' && (dummy = strchr((char*)ahs,'<')) != NULL) {
				strcpy(ehs,&ahs[i]) ;
				sf = strchr((char*)ehs,'<') ;
				if (sf == NULL) {
					strcpy(ehs,&ahs[i-2]) ;
					ehs[0] = '?' ;
					gsinsert = 1 ;
					sf = &ehs[1] ; }
				notloesung2 = 1 ;
				truechar = *(dummy+1) ;
				nl2char = dummy+2 ;
				switch (*(dummy+1)) {
					case 'i': *sf = 'i' ; *(sf+1) = ':' ; break ;
					case 'u': *sf = 'u' ; *(sf+1) = ':' ; break ;
					case 'o': *sf = 'o' ; *(sf+1) = ':' ; break ; }
				ue = invent.find_unit(ehs,'a') ; } }
		while (ue.type == 'x' && i <= sk+1) ;
 
		if (ue.type == 'x') {
//			fprintf(errfile,"Looking for Unit %s\n",ehs) ;
			syndata_error("Build_sce","unit 'a' not found",5) ;
			return ; }
		pref = 0 ;
		strcpy(leftover,ahs) ;
		leftover[i] = '\0' ;
		aktsound += soundcount((char*)leftover) ;
		for (j=0 ; j < (int)strlen(leftover) ; j++)
			if (strchr("ptkbdg",leftover[j]) != NULL)
				aktsound++ ;
		if (j > 0 && find_prefix(ahs,&ue.name[extract]) != NULL) {
			strcpy(ehs,find_prefix(ahs,&ue.name[extract])) ;
			up = invent.find_unit(ehs,'a') ;
			if (up.type != 'x') {
				pref = 1 ;
				strcpy(ui.name,up.name) ;
				dummy = get_first_sound(ui.name,0,0) ;
				strcpy(ui.startmark,dummy) ;
				delete[](dummy) ;
				dummy = get_last_sound(ui.name,2,1) ;
				strcpy(ui.endmark,dummy) ;
				delete[](dummy) ;
				ui.soundnr = soundcount(ui) ;
				aktsound -= 1 + (ui.startmark[0] == '_') ;
				ui.firstsound = int(firstsound-sc+ aktsound) ;
				aktsound += ui.soundnr ;
				ui.type = 'a' ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as prefix\n",ui.name,ui.type) ;
}

				append(ui) ;
				 } }
		strcpy(ui.name,ue.name) ;
		dummy = get_first_sound(ui.name,extract+gsinsert,0) ;
		strcpy(ui.startmark,dummy) ;
		delete[](dummy) ;
		if (pref)
			strcpy(ui.startmark,ui.endmark) ;
		dummy = get_last_sound(ui.name,1,1) ;
		strcpy(ui.endmark,dummy) ;
		delete[](dummy) ;
		ui.soundnr = soundcount(ui) ;
		ui.firstsound = int(firstsound-sc+aktsound+notloesung3) ;
		aktsound += ui.soundnr+notloesung3 ;
		ui.type = 'a' ;
		append(ui) ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c %d as ahs\n",ui.name,ui.type,ui.firstsound) ;
}


		if (notloesung2) {
			notloesung2 = 0 ;
			ui.name[0] = truechar ;
			ui.name[1] = ':' ;
			ui.name[2] = '\0' ;
			ui.type = 'e' ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += 0.5 ;
			ui.soundnr = 0.5 ;
			ui.startmark[0] = '&' ;
			strcpy(&ui.startmark[1],ui.name) ;
			strcpy(ui.endmark,"-") ;
			append(ui) ;
			ui.name[0] = '?' ;
			ui.name[1] = s[sk] ;
			if (strchr("aEeiou2y",s[sk]) != NULL) {
				ui.name[2] = ':' ;
				ui.name[3] = '\0' ; }
			else {
			  if (s[sk] == '=') {
			    ui.name[2] = s[sk+1] ;
			    ui.name[3] = '\0' ; }
			  else
			    ui.name[2] = '\0' ; }
			ui.type = 'a' ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
         aktsound += 0.5 ;
			ui.soundnr = 0.5 ;
			strcpy(ui.startmark,&ui.name[1]) ;
			strcpy(ui.endmark,ui.name) ;
			ui.endmark[0] = '&' ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as notloesung2\n",ui.name,ui.type) ;
}

			append(ui) ;  }


		// ENDHALBSILBEN
		if (strchr("ouiey2",s[sk]) != NULL && s[sk+1]!=':') {
			ehs[0] = s[sk] ;
         ehs[1] = ':' ;
         notloesung4 = 1 ;
			strcpy(&ehs[2],&s[sk+1]) ; }
		else {
		if (strchr("O9",s[sk]) != NULL && s[sk+1]==':') {
			ehs[0] = s[sk] ;
         notloesung4 = -1 ;
			strcpy(&ehs[1],&s[sk+2]) ; }
		else
			strcpy(ehs,&s[sk]) ; }
		for (j = 0 ; j < (int)strlen(ehs) ; j++) {
			if (strchr("sSZzdgbvfj",ehs[j]) != NULL)
				break ;
			if (strchr("Cx",ehs[j]) != NULL && strchr("lnmN6",ehs[j-1]) != NULL)
				break ; }
		truechar = ehs[j] ;
		extract = 0 ;

                if (notloesung5 == 1) {
		  if (ehs[0] == 'a' || ehs[0] == 'E')
		    ehs[1] = ':' ;
		  else
		    memmove(&ehs[1],&ehs[2],strlen(&ehs[1])) ; }
		ue = invent.find_unit(ehs,'e') ;
		if (j < (int)strlen(ehs)) {
			ehs[j] = assoc(ehs[j]) ;
			up = invent.find_unit(ehs,'e') ;
			if (strlen(up.name) > strlen(ue.name)) {
				ue = up ;
				extract = 1 ; } }
		if (ue.type == 'x') {
			syndata_error("Build_sce","unit 'e' not found",5) ;
			return ; }
		else {
			ehs[j] = truechar ;
			strcpy(ui.name,ue.name) ;
			pref = 0 ;
			if ((extract == 0) &&
				 (strchr("ptk",ue.name[strlen(ue.name)-1]) != NULL)) {
				for (i = 0 ; i < ((int)strlen(ehs)-1) ; i++)
					if (strchr("ptk",ehs[i]) != NULL)
						break ;
				if (i <= (int)strlen(ue.name) -1 && strchr("sSftkp",ehs[i+1]) != NULL
					&& ehs[i+1] != '\0' && ehs[i] != ehs[i+1] )
					pref = 1 ; }
			dummy = get_first_sound(ui.name,0,1) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;  ;
			dummy = get_last_sound(ui.name,extract+pref,0) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;  ;
			ui.soundnr = soundcount(ui)-notloesung ;
			ui.type = 'e' ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c %d as ehs\n",ui.name,ui.type,ui.firstsound) ;
}

			append(ui) ;
			 }

	// SUFFIXE
suffix:
	sf = strchr((char*)ui.name,s[sk]) ;
	i = 0 ;
	while (sf[i] == s[sk+i]) {
		if (s[sk+i] == '\0')
			break ;
		i++ ; }
	i -= pref ; // || extract ;
	if (notloesung4 < 0)
	  i -= notloesung4 ;

if (debuglevel > 1) {
   fprintf(errfile,"Suffixsearch sf %s s[sk] %s i %d pref %d nl4 %d\n",sf,&s[sk],i,pref,notloesung4) ;
}

	do {
		ehs[0] = 'U' ;
		if(strchr("aEeiI@=",s[sk]) != NULL && s[sk+1] != 'U')
			ehs[0] = 'E' ;
		strcpy(&ehs[1],&s[sk+i]) ;
		if (ehs[0] == 'U' && ehs[1] == 'C')
			ehs[0] = '9' ;
		if (ehs[0] == 'E' && ehs[1] == 'x')
			ehs[0] = 'a' ;
		extract = 0 ;
		ue = invent.find_unit(ehs,'s') ;
		if (ue.type == 'x' && strchr("Cx",ehs[1]) != NULL && ehs[2] =='\0') {
			ehs[2] = 't' ;
			ehs[3] = '\0' ;
			ue = invent.find_unit(ehs,'s') ;
			extract = 1 ;
			if (ue.type == 'x')
				break ;
			strcpy(ui.name,ue.name) ;
			dummy = get_first_sound(ui.name,1,0) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;  ;
			dummy = get_last_sound(ui.name,1,0) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;  ;
			ui.soundnr = soundcount(ui) ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
			ui.type = 's' ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as sfx1\n",ui.name,ui.type) ;
}

			append(ui) ;
			i += strlen(ui.name)-extract-1 ;
			continue ; }
		if (ue.type == 'x' && strchr("sfptkS",ehs[2]) != NULL) {
			ehs[2] = assoc(ehs[2]) ;
			ue = invent.find_unit(ehs,'s') ;
			extract = 1 ;
			if (ue.type == 'x')
				break ;
			strcpy(ui.name,ue.name) ;
			dummy = get_first_sound(ui.name,1,0) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;  ;
			dummy = get_last_sound(ui.name,1,0) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;  ;
			ui.soundnr = soundcount(ui) ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
			ui.type = 's' ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as sfx2\n",ui.name,ui.type) ;
}

			append(ui) ;
			i += strlen(ui.name)-extract-1 ;
			continue ; }
		truechar=ehs[strlen(ue.name)] ;
		ehs[strlen(ue.name)] = assoc(ehs[strlen(ue.name)]) ;
		up = invent.find_unit(ehs,'s') ;
      if (strlen(ue.name) > 0)
			ehs[strlen(ue.name)-1] = truechar ;
		if (ue.type == 'x'&& up.type == 'x')
			break ;
		if (strlen(up.name) > strlen(ue.name)) {
			extract = 1 ;
			strcpy(ui.name,up.name) ;
			dummy = get_first_sound(ui.name,1,0) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;  ;
			dummy = get_last_sound(ui.name,1,0) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;  ;
			ui.soundnr = soundcount(ui) ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
			ui.type = 's' ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as sfx3\n",ui.name,ui.type) ;
}

			append(ui) ;
			 }
		else {
			strcpy(ui.name,ue.name) ;
			dummy = get_first_sound(ui.name,1,0) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;  ;
			dummy = get_last_sound(ui.name,0,0) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;  ;
			ui.soundnr = soundcount(ui) ;
			ui.firstsound = int(firstsound-sc+aktsound) ;
			aktsound += ui.soundnr ;
			ui.type = 's' ;
if (debuglevel > 1) {
	fprintf(errfile,"ui: %s %c as sfx4\n",ui.name,ui.type) ;
}


			append(ui) ;
			 }
		i += strlen(ui.name)-extract-1 ; }
	while (i < n) ;

	return ; }





int Unitlist::build(Soundlist* soli, Inventory& invent) {
	Unitindex ue ;
	Unitinfo ui,*a,*b ;
	Soundinfo s ;
	int startsound,endsound ;
	int startindex, endindex, nodire, nodili ;
	int firstsound = 0 ;
	int sk = -1 ;
	char* dummy ;
	char xname[10] ;
	char xtype ;
	int i,j,jj,syct ;
	char sy1[100] ;
	float delta ;
	float add ;
	soli->reset() ;
	syct = 0 ;

	// SILBENKERNUMGEBUNGEN

	while ((s = soli->get_and_advance()).intensity != -1) {
		if (s.duration == 0)
			continue ;
		firstsound++ ;
		if (strcmp(s.name,"pau") == 0) {
			sy1[syct] = '\0' ;
			build_sce(sy1,syct,sk,firstsound, invent) ;
			syct = 0 ;
			sk = -1 ;
			strcpy(ui.name,"PAU") ;
			ui.firstsound = firstsound ;
			strcpy(ui.startmark,"|") ;
			strcpy(ui.endmark,"|") ;
			ui.soundnr = 1 ;
			ui.type = 'P' ;
			append(ui) ;
			continue ; }
		if (strchr("aeiou29yEUOIY@=",s.name[0]) != NULL) {
			if (sk != -1) {
				sy1[syct] = '\0' ;
				build_sce(sy1,syct,sk,firstsound, invent) ;
				j = 1 ;
				if (strchr(":IUY~6",sy1[sk+j]) != NULL && sy1[sk+j] != '\0')
					j++ ;
				for (i=sk+j ; i < syct ; i++)
					sy1[i-(sk+j)] = sy1[i] ;
				syct -= sk+j ; }
			sk = syct ; }
		if (s.name[0] != '_')
			for (i=0 ; i < (int)strlen(s.name) ; i++) {
				sy1[syct++] = s.name[i] ;
				if (syct > 29) {
					syndata_error("Build","Syllable nucleus string too long",5) ;
					return(0) ; } } }

	// LÖCHER UND ÜBERLAPPUNGEN

if(debuglevel > 2)
  print(errfile) ;


	reset() ;
	a = get_unit_pointer() ;
	delta = 0.0 ;
	add = 1.0 ;
	advance() ;
	do {
		b=get_unit_pointer() ;

		if (debuglevel>2) {
		  fprintf(errfile,"a->f %d add %f\n",a->firstsound,add) ; }
		if (debuglevel > 0) {
		  if (a->firstsound != (int)add)
		    fprintf(errfile,"ADDMISMATCH\n") ; }

		add += a->soundnr ;
		delta = (float)b->firstsound-((float)a->firstsound+a->soundnr-delta) ;
		s = soli->get(b->firstsound-1) ;
		if (strcmp(s.name,"pau") == 0 && (s.duration == 0))
			delta -= 1 ;
		if (abs(delta) > 0.5) {
			if (delta > 0) {

				// LAUTE HINZUFÜGEN

				sy1[0] = '\0' ;
				syct = int(a->firstsound+a->soundnr-0.5) ;
				s = soli->get(syct) ;

				if (strcmp(s.name,"pau") == 0)
					strcat(sy1,"X") ;
				else
					strcat(sy1,s.name) ;
				while (++syct <= b->firstsound) {
					s = soli->get(syct) ;
					if (strcmp(s.name,"pau") == 0 || strcmp(s.name,"?") == 0)
						strcat(sy1,"X") ;
					else
						strcat(sy1,s.name) ; }
				jj = get_number() -1 ;
				firstsound = 1 ;
				startsound = 0 ;
				nodire = 0 ;
				if (strchr("aeiouAEIOUY29@=y",sy1[startsound]) != NULL) {
					startsound++ ;
					if (sy1[startsound-1] == '=')
						startsound++ ;
					if (strchr("IYU:~",sy1[startsound]) != NULL)
						startsound++ ;
					nodire = 1 ; }
				while (startsound < (int)strlen(sy1)-1) {
					if (startsound == (int)strlen(sy1)-2 && sy1[startsound+1] == '0')
						break ;
					if (startsound == (int)strlen(sy1)-2 && sy1[startsound] == '_')
						break ;
					nodili = nodire ;
					if (sy1[startsound] == '0')
						startsound++ ;
					if (sy1[startsound] == '=')
						startsound++ ;
					if (sy1[startsound] == 'X') {
						nodili = 1 ;
						startsound++ ; }
					if (sy1[startsound] == '_') {
						nodili = 1 ;
						startsound+=2 ; }
					if (sy1[startsound] == 'h') {
						nodili = 1 ; }
					if (sy1[startsound] == '0')
						startsound++ ;
if (debuglevel > 1) {
					fprintf(errfile,"Syll %s Startsound %c\n",sy1, sy1[startsound]) ;
}
					startindex = getlistsoundsnr(sy1[startsound]) ;
					if (startindex == -1 || startindex > 21) {
						fprintf(errfile,"Fill_Unit: Sound not found %c\n",sy1[startsound]) ;
						break ; }
					endsound = startsound+1 ;
					nodire = 0 ;
					if (sy1[endsound] == '0')
						endsound++ ;
					if (sy1[endsound] == '=')
						endsound++ ;
					if (sy1[endsound+1] == 'X') {
						nodire = 1 ; }
					if (sy1[endsound] == 'X' || sy1[endsound] == 'h') {
						nodire = 1 ; }
					if (sy1[endsound] == '_') {
						nodire = 1 ;
						endsound+=2 ;
						if (endsound >= (int)strlen(sy1))
							endsound = (strlen(sy1))-1 ; }
					if (sy1[endsound] == '0') {
						endsound++ ;
						if (endsound >= (int)strlen(sy1))
							endsound = (strlen(sy1))-2 ; }

if (debuglevel > 1) {
					fprintf(errfile,"Syll %s Endsound %c\n",sy1, sy1[endsound]) ;
}


					endindex = getlistsoundsnr(sy1[endsound]) ;
					if (endindex == -1) {
						fprintf(errfile,"Sound not found in FU %c\n",sy1[endsound]) ;
						break ; }
					if (exceptionlist[startindex][endindex] == NULL) {
						syndata_error("Fill_unit","Result NULL",3) ;
						break ; }
					strcpy(xname,exceptionlist[startindex][endindex]) ;
					if (xname[0] == '_') {
						startsound = endsound+1 ;
						continue ; }
					xtype = xname[strlen(xname)-1] ;
					xname[strlen(xname)-2]='\0' ;
					ue = invent.find_unit(xname,xtype) ;
					if (ue.type == 'x') {
						syndata_error("Fill_Unit","Unit not found",3) ;
						break ; }
					strcpy(ui.name,ue.name) ;
					ui.type = xtype ;
					j = 0 ;
					ui.soundnr = 1.0 ;
					if (strchr(plosives,sy1[startsound]) != NULL) {
						nodili = 1 ;
						ui.startmark[j++] = '_' ;
						ui.soundnr += 1.0 ;
						if (startsound == 0) {
							i = 0 ;
							xname[i++] = '_' ;
							xname[i++] = sy1[startsound] ;
							xname[i] = '\0' ;
							a->soundnr -= 2 ;
							add -= 2 ;
							strcpy(a->endmark,xname) ; } }
					if (nodili == 0) {
						if (firstsound) {
							i = 0 ;
							xname[i++] = '&' ;
							if (strchr(a->name,'=') != NULL && strchr(a->name,'=')[1] == sy1[startsound])
								xname[i++] = '=' ;
							xname[i++] = sy1[startsound] ;
							xname[i] = '\0' ;
							strcpy(a->endmark,xname) ;
							a->soundnr -= 0.5 ;
							add -= 0.5 ; }
						ui.startmark[j++] = '&' ;
						ui.soundnr -= 0.5 ; }
					if (ui.name[0] == '=')
						ui.startmark[j++] = '=' ;
					ui.startmark[j++] = sy1[startsound] ;
					ui.startmark[j] = '\0' ;
					j = 0 ;
					if (strchr((char*)ui.name,sy1[endsound]) == NULL || sy1[startsound] == sy1[endsound]) {
						if (sy1[endsound] == 'X') {
if (debuglevel > 1) {
						  fprintf(errfile,"Endmark set before X\n") ;
						  fflush(errfile) ;
}
							dummy = strchr((char*)ui.name,sy1[startsound]) ;
							if (dummy[1] == '\0')
								ui.endmark[j++] = '-' ;
							else {
								if (strchr(plosives,dummy[1]) != NULL)
									ui.endmark[j++] = '_' ;
								ui.endmark[j++] = dummy[1] ; }
							ui.endmark[j] = '\0' ; }
						else
						if (strchr("bdg",sy1[startsound]) == NULL) {
							nodire = 1 ;
							if (strcmp(ui.name,"Epf") == 0) {
								ui.endmark[j++] = 'f' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"Ets") == 0) {
								ui.endmark[j++] = 's' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"EkS") == 0) {
								ui.endmark[j++] = 'S' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"psa:") == 0) {
								ui.endmark[j++] = 's' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"tsE:") == 0) {
								ui.endmark[j++] = 's' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"ksE:") == 0) {
								ui.endmark[j++] = 's' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"=6") == 0) {
								ui.endmark[j++] = '-' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"ng") == 0) {
								ui.endmark[j++] = '_' ;
								ui.endmark[j++] = 'g' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"hI") == 0) {
								ui.endmark[j++] = 'I' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"hU") == 0) {
								ui.endmark[j++] = 'U' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"hE:") == 0) {
								ui.endmark[j++] = 'E' ;
								ui.endmark[j++] = ':' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"ha:") == 0) {
								ui.endmark[j++] = 'a' ;
								ui.endmark[j++] = ':' ;
								ui.endmark[j] = '\0' ; }
							else {
								ui.endmark[j++] = '_' ;
								ui.endmark[j++] = assoc(sy1[endsound]) ;
								ui.endmark[j] = '\0' ; } }
						else {
							if (strcmp(ui.name,"bv") == 0) {
								ui.endmark[j++] = 'v' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"dz") == 0) {
								ui.endmark[j++] = 'z' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"dg") == 0) {
								ui.endmark[j++] = '_' ;
								ui.endmark[j++] = 'g' ;
								ui.endmark[j] = '\0' ; }
							else
							if (strcmp(ui.name,"gj") == 0) {
								ui.endmark[j++] = 'j' ;
								ui.endmark[j] = '\0' ; }
							else {
								ui.endmark[j++] = '_' ;
								ui.endmark[j++] = voicedassoc(sy1[endsound]) ;
								ui.endmark[j] = '\0' ; }
if (debuglevel > 1) {
						  fprintf(errfile,"Endmark set special\n") ;
						  fflush(errfile) ;
}
							nodire = 1 ; } }
					else {
						ui.soundnr += 1.0 ;
						if (strchr(plosives,sy1[endsound]) != NULL) {
							ui.endmark[j++] = '_' ;
							nodire = 1 ;
							ui.soundnr -= 1.0 ; }
						if (nodire == 0) {
							ui.endmark[j++] = '&' ;
							if (strchr((char*)ui.name,'=') != NULL && ui.name[0] != '=')
								ui.endmark[j++] = '=' ;
							ui.soundnr -= 0.5 ; }
if (debuglevel > 1) {
						  fprintf(errfile,"Endmark set normally X\n") ;
						  fflush(errfile) ;
}

						ui.endmark[j++] = sy1[endsound] ;
						if (strchr((char*)ui.name,'0') != NULL)
							ui.endmark[j++] = '0' ;
						if (sy1[endsound+1] == 'X' || (sy1[endsound] == 'h')) {
							j = 1 ;
if (debuglevel > 1) {
						  fprintf(errfile,"Endmark set before X or h %c\n",sy1[endsound]) ;
						  fflush(errfile) ;
}
							endsound++ ;
							if (sy1[endsound] == '0')
							  endsound++ ;
							if (nodire == 0) {
if (debuglevel > 1) {
						  fprintf(errfile,"Sound counter increased by 0.5\n") ;
						  fflush(errfile) ;
}

							  ui.soundnr += 0.5 ; }
							else {
							  if (strchr("ptkbdg",sy1[endsound-1])!=NULL && sy1[endsound] != 'h' && sy1[endsound] != '0')
							    ui.soundnr += 1.0 ;
								if (ui.endmark[0] == '_')
									ui.soundnr += 1.0 ; }
							nodire = 1 ;
                     ui.endmark[max(0,j-1)] = '-' ; }
						if (((endsound > 0 && sy1[endsound-1] == 'h' && sy1[endsound] != 'h') || (endsound > 1 && sy1[endsound-2] == 'h' && sy1[endsound-1]=='0'))&& strchr(b->startmark,'h') != NULL && b->firstsound-add < (2+(strchr("ptkbdg",sy1[startsound])!= NULL))) {
    
if (debuglevel > 1) {
						  fprintf(errfile,"Endmark set h %c and %s\n",sy1[endsound],b->startmark) ;
						  fflush(errfile) ;
}					  j=1 ;
					  ui.soundnr-- ;
					  nodire = 1 ;
                                          ui.endmark[j-1] = 'h' ;
					  if (strstr(ui.name,"h0") != NULL) 
					    ui.endmark[j++]='0' ;
 }

						ui.endmark[j] = '\0' ; }

					  
						  

if (debuglevel > 1) {
						  fprintf(errfile,"Endmark %s\n",ui.endmark) ;
						  fflush(errfile) ;
}
				ui.firstsound = (int)add ;
					add += ui.soundnr ;
					firstsound = 0 ;
					insert(ui,jj++) ;
					startsound = endsound ; }
				if (nodire == 0) {
					strcpy(&xname[1],b->startmark) ;
					xname[0] = '&' ;
					b->soundnr -= 0.5 ;
					strcpy(b->startmark,xname) ; }
				get(++jj) ; }
			else {

				// LAUTE LÖSCHEN

				delta = -delta ;
				while (delta > 0) {
					if (strchr(a->name,'=') != NULL && strchr(a->name,'=')[1] == b->startmark[0]) {
						a->endmark[0] = '=' ;
						strcpy(&a->endmark[1],b->startmark) ; }
					else
						strcpy(a->endmark,b->startmark) ;
					if (a->soundnr > delta) {
						a->soundnr -= delta ;
						add -= delta ;
						if (a->type == 's' && a->soundnr == 2 && a->startmark[0] == '_') {
							decrease() ; decrease() ;
							a = get_unit_pointer() ;
							if (a->endmark[0] != '-') {
								a->soundnr += 2 ;
								strcpy(a->endmark,"-") ;
								advance() ;
								exclude(get_number()) ; }
							else {
								advance() ;
								advance() ;
								a = get_unit_pointer() ; } }
						break ; }
					else {
						delta -= a->soundnr ;
						add -= a->soundnr ;
						decrease() ; decrease() ;
						a = get_unit_pointer() ;
						advance() ;
						exclude(get_number()) ;
						if (a->type == 's' && a->soundnr == 2 && a->startmark[0] == '_' && delta < a->soundnr) {
							decrease() ; decrease() ;
							a = get_unit_pointer() ;
							if (a->endmark[0] != '-') {
								a->soundnr += 2 ;
								strcpy(a->endmark,"-") ;
								advance() ;
								exclude(get_number()) ; }
							else {
								advance() ;
								advance() ;
								a = get_unit_pointer() ; } } } } }
			delta = 0.0 ;
			if (b->startmark[0] == '&')
				delta = -0.5 ;}
		a = b ; }
	while (advance() != -1) ;

	// VOKAL-VOKAL-ÜBERGÄNGE

if(debuglevel > 2)
  print(errfile) ;


	reset() ;
	a = get_unit_pointer() ;
	advance() ;
	do {
		b=get_unit_pointer() ;
		if (b->name[0] == '?' && b->startmark[0] != '?') {
			strcat(strcpy(sy1,a->name),b->startmark) ;
			ue = invent.find_unit(sy1,'v') ;
			if (ue.type == 'x')
				break ;

// Interpolation

			strcpy(b->name,ue.name) ;
			b->type = 'v' ;
			strcpy(b->startmark,a->startmark) ;
			b->soundnr = 1.0 ;
			b->firstsound -= 1 ;
		 exclude(get_number()-1) ; }
		a = b ; }
	while (advance() != -1) ;


	// ?@ loeschen

	reset() ;
	a = get_unit_pointer() ;
	advance() ;
	do {
		b=get_unit_pointer() ;
		if (a->name[0] == '?' && a->name[1] == '@') {
			strcpy(b->startmark,"@") ;
			b->soundnr +=0.5 ;
		 exclude(get_number()-1) ; }
		a = b ; }
	while (advance() != -1) ;

	// KONSONANT-KONSONANT-ÜBERGÄNGE
if(debuglevel > 2)
  print(errfile) ;

	reset() ;
	a = get_unit_pointer() ;
	advance() ;
	do {
		b=get_unit_pointer() ;
		if (a->soundnr == 0.5) {
		  a = b ;
		  continue ; }
		strcat(strcpy(sy1,(soli->get(int(a->firstsound+a->soundnr))).name),b->startmark) ;
		ue = invent.find_unit(sy1,'k') ;
		if (ue.type != 'x' && strchr("ptkbdg",ue.name[0]) == NULL) {
			strcpy(ui.name,ue.name) ;
			ui.type = 'k' ;
			dummy = get_first_sound(ui.name,0,1) ;
			strcpy(ui.startmark,dummy) ;
			delete[](dummy) ;  ;
			dummy = get_last_sound(ui.name,1,1) ;
			strcpy(ui.endmark,dummy) ;
			delete[](dummy) ;  ;
			ui.firstsound = b->firstsound - 1 ;
			ui.soundnr = 1.0 ;
			b->soundnr -= 0.5 ;
			a->soundnr -= 0.5 ;
			strcpy(b->startmark,ui.endmark) ;
			strcpy(a->endmark,ui.startmark) ;
		if (a->name[strlen(a->name)-2] == '=') {
		a->endmark[0] = '&' ;
		a->endmark[1] = '=' ;
		a->endmark[2] = ui.startmark[1] ;
		a->endmark[3] = '\0' ; }

		insert(ui,get_number()-1) ; }
		a = b ; }
	while (advance() != -1) ;
	return(1) ; }
#ifndef NGIMMICKS

extern void find_minimal_distance(short* a1, long &sam1, short* a2, long &sam2, int sf, int duration, char* method) ;

void Unitlist::optimize(Soundlist* soli, Inventory& invent, char* method) {
	reset() ;
	Unitinfo* i, *j ;
	Unit a, b;
	int sf = invent.get_sf() ;
	long astart,bstart,aend,bend ;
	long alen,blen ;
	short* asig, *bsig ;
	char g[6] ;
	int duration ;
	do {
		i = get_unit_pointer() ;
		if (i->endmark[0] == '&') {
			advance() ;
			j = get_unit_pointer() ;
			decrease() ;
			if (j->startmark[0] != '&') {
				syndata_error("Optimize","& does not meet &",3) ;
				continue ; }
			duration = (soli->get(j->firstsound)).duration ;
			a = invent.get_unit_info(i->name,i->type) ;
			b = invent.get_unit_info(j->name,j->type) ;
			if (a.type == 'x' || b.type == 'x') {
				syndata_error("Optimize","unit not found",3) ;
				continue ; }
			astart = a.borders->get_marker_adress(&(i->endmark[1])) ;
			bstart = b.borders->get_marker_adress(&(j->startmark[1])) ;
			aend = a.borders->get_marker_adress_after(i->endmark) ;
			if (aend == -1)
				aend = a.borders->get_marker_adress_after(&(i->endmark[1])) ;
			bend = b.borders->get_marker_adress_after(j->startmark) ;
			if (bend == -1)
				bend = b.borders->get_marker_adress_after(&(j->startmark[1])) ;
			a = invent.get_unit_signal(i->name,i->type) ;
			b = invent.get_unit_signal(j->name,j->type) ;
			asig = a.sig->get_signal(astart,aend) ;
			bsig = b.sig->get_signal(bstart,bend) ;
			if (asig != NULL && bsig != NULL) {
				alen = aend-astart ;
				blen = bend-bstart ;
				fprintf(errfile,"Between %6s %c and %6s %c: length1: %6ld length2: %6ld\n",i->name,i->type,j->name,j->type,alen,blen) ;
				find_minimal_distance(asig,alen,bsig,blen,sf,duration,method ) ;
				fprintf(errfile,"                                  pos1: %6ld    pos2 %6ld\n",alen,blen) ;
				g[0] = '!' ;
				sprintf(&g[1],"%ld",(alen+astart)/sf) ;
				strncpy(i->endmark,g,6) ;
				sprintf(&g[1],"%ld",(blen+bstart)/sf) ;
				strncpy(j->startmark,g,6) ;
			}
			else
            	fprintf(errfile,"asig or bssig NULL, a from %ld to %ld, b from %ld to %ld\n",astart,aend,bstart,bend) ;
			if (asig != NULL)
				delete(asig) ;
			if (bsig != NULL)
				delete(bsig) ; } }
	while (advance() != -1) ; }

#endif



void Unitlist::print(FILE* ascoutfil) {
	reset() ;
	Unitinfo i ;
	while ((i = get_and_advance()).firstsound != errorvalue.firstsound) {
		fprintf(ascoutfil,"%c %7s %5s %5s %5.1f %5d\n",
			i.type,i.name,i.startmark,i.endmark,i.soundnr,i.firstsound) ; } }


Parameterset Unitlist::get_next_set(Soundlist* soli) {
	Parameterset u ;
	Unitinfo i = get() ;
	if (i.firstsound == errorvalue.firstsound) {
		u.type = 'x' ;
		return(u) ; }
	int j,k ;
	Soundinfo s = soli->get(i.firstsound) ;
	if (s.duration == -1) {
		u.type = 'x' ;
		return(u) ; }
	u.type = i.type ;
	if (i.type != 'P') {
		strcpy(u.name,i.name) ;
		u.lct = u.rct = 0 ;
		strcpy(u.lcs,i.startmark) ;
		strcpy(u.rcs,i.endmark) ;
		if (strcmp(i.endmark,i.startmark) == 0 || i.name[0] == i.endmark[1] && i.name[1] != '0')
			strcat(u.rcs,"2") ;
		u.dau = 1 ;
		if (i.endmark[0] == '&')
			u.inp = 1 ;
		else
			u.inp = 0 ;
		if (i.startmark[0] == '&')
			u.apl = soli->get(i.firstsound).intensity ;
		else
			u.apl = -1 ;
		if (i.endmark[0] == '&')
			u.apr = soli->get(int(i.firstsound+i.soundnr)).intensity ;
		else
			u.apr = -1 ;
		if (u.apl == -1 && u.apr == -1) {
			if (strchr((char*)u.name,'@') != NULL) {
				j = i.firstsound ;
				do
					s = soli->get(j++) ;
				while (s.name[0] != '@' && j < i.firstsound+i.soundnr) ;
				if (s.intensity > 10)
					u.apl = -(100+s.intensity) ; }
			if (strchr((char*)u.name,'=') != NULL) {
				j = i.firstsound ;
				do
					s = soli->get(j++) ;
				while (s.name[0] != '=' && j < i.firstsound+i.soundnr) ;
				if (s.intensity > 10)
					u.apl = -(100+s.intensity) ; } }
		u.acc = soli->get(i.firstsound).accent/11 ; }
	else {
		k = (soli->get(i.firstsound)).intensity ;
		j = 0 ;
		if (abs(k) > 2) {
			j = 2 ;
			k /= 2 ; }
		u.apl = 0 ;
		u.lct = 0 ;
		u.rct = 0 ;
		u.rcs[0] = '\0' ;
		u.lcs[0] = '\0' ;
		u.apr = 0 ;
		u.dau = (soli->get(i.firstsound)).duration ;
		u.inp = j ;
		strcpy(u.name,i.name) ;
		u.acc = k ; }
	exclude_and_advance_and_get() ;

	return(u) ; }

