/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#include "tools.h"
#include "xscript.h"
#include "hposttra.h"

#if !defined(__STDIO_H)
#include <stdio.h>
#endif
#include <string.h>

//static int MIN_BORDER=2 ;
//#define NOT_SO_MANY_BOUNDARIES

#define sign(i) ((i)<0?-1:((i)>0?1:0))

const char* Konstnames[14] = {
	"PP","VP","NP","VI","TNP","TPP","TVP","TVI", "satzende", "teilsatzende", "emphase", "invalid" ,"Unknowne", "Errore"  } ;

const char* Satznames[5] = {
	"aussage", "befehl", "wfrage", "efrage", "garnix" } ;
bool fragewort (const string &word) ;

TWordClass get_wortart(char* s) {
	TWordClass result= Unknown ;
	if (strncmp(s,"VRB",3) == 0)
		result = VRB ;
	if (strncmp(s,"VEM",3) == 0)
		result = VEM ;
	if (strncmp(s,"VES",3) == 0)
		result = VES ;
	if (strncmp(s,"VEW",3) == 0)
		result = VEW ;
	if (strncmp(s,"VEH",3) == 0)
		result = VEH ;
	if (strncmp(s,"TME",3) == 0)
		result = TME ;
	if (strncmp(s,"QAV",3) == 0)
		result = QAV ;
	if (strncmp(s,"QPV",3) == 0)
		result = QPV ;
	if (strncmp(s,"QAN",3) == 0)
		result = QAN ;
	if (strncmp(s,"QPN",3) == 0)
		result = QPN ;
	if (strncmp(s,"NUM",3) == 0)
		result = NUM ;
	if (strncmp(s,"NOM",3) == 0)
		result = NOM ;
	if (strncmp(s,"NAM",3) == 0)
		result = NAM ;
	if (strncmp(s,"ART",3) == 0)
		result = ART ;
	if (strncmp(s,"PPR",3) == 0)
		result = PPR ;
	if (strncmp(s,"PRO",3) == 0)
		result = PRO ;
	if (strncmp(s,"ADD",3) == 0)
		result = ADD ;
	if (strncmp(s,"VKN",3) == 0)
		result = VKN ;
	if (strncmp(s,"KKN",3) == 0)
		result = KKN ;
	if (strncmp(s,"KNJ",3) == 0)
		result = KNJ ;
	if (strncmp(s,"SBJ",3) == 0)
		result = SBJ ;
	if (strncmp(s,"NEG",3) == 0)
		result = NEG ;
	if (strncmp(s,"INJ",3) == 0)
		result = INJ ;
	if (strncmp(s,"MOD",3) == 0)
		result = MOD ;
	return(result) ; }



int putsylpros (char *in, int len, int val, char bs)
{
	if (len < 1)
		return 0;

   float langkurz = 2.0 ;
   if (strchr(in,'@') != NULL)
   	langkurz = 4.0 ;
   if (strstr(in,"aU") != NULL || strstr(in,"EI") != NULL ||
   	 strstr(in,"aI") != NULL || strstr(in,"OY") != NULL)
   	langkurz = 1.0 ;

   float sonr = (float)strlen(in) ;
   if (langkurz == 1.0 || strchr(in,':') != NULL)
   	sonr -= 1 ;

	int pval = (int)(val*(0.4 + 0.03*sonr - 0.08*langkurz)) ;
	char buffer[10] ;

	if (bs == '\'')
		pval = val;
	if (bs ==  ',')
		pval += 2 ;

	sprintf(buffer,"[%d]",pval) ;
	strcat(in, buffer);
	return (strlen(buffer));
}

int find_sylls(char* in) {
	unsigned int i ;
	int count = 0 ;
	for (i = 0 ; i < strlen(in) ; i++)
		if (in[i] == '|')
			count++ ;
	return(count) ; }


Wordlist::Wordlist() {
        MIN_BORDER = 2 ;
	errorvalue.konstit = Errore ;
	errorvalue.flag = 127 ; }

Wordlist::Wordlist(TFile& infile) {
	char buffer[256] ;
	char* erg ;
	Word w ;
	int wopro = -1 ;
	int betchg = 0 ;

	while (infile.GetS(buffer, sizeof(buffer)) != NULL)
	{
		w.text = NULL;
		w.flag = 0;
		if (strchr(".;!?", buffer[0]) != NULL)
		{
				if (buffer[0] == ';')
					add_constituent_info(teilsatzende) ;
				else {
						add_constituent_info(satzende) ;
						switch (buffer[0]) {
							case '.' : add_sentence_type(aussage) ; break ;
							case '!' : add_sentence_type(befehl) ; break ;
							case '?' : add_sentence_type(efrage) ; break ; } }
		}
		if(buffer[0] == '{') {
			w.text = strdup(buffer) ;
			strncpy(w.wordclass,"COM",3) ;
			w.wk = Unknown ;
			w.konstit = invalid ;
			w.satztyp = garnix ;
			if (strncmp(w.text,"{WordProminence:",16) == 0)
				wopro = atoi(&(w.text)[16]) ;
			if (strncmp(w.text,"{ChangeWordProminence:",22) == 0)
				betchg = atoi(&(w.text)[22]) ;
			if (strncmp(w.text,"{BoundaryStrength:",18) == 0)
				MIN_BORDER = atoi(&(w.text)[18]) ;
			conc(w) ; }
		if (strstr((char*)buffer,"##") != NULL)
			w.flag = 1;
		erg = strchr((char*)buffer, ' ');
		if (erg == NULL)
		{
			continue;
		}
		erg[0] = '\0';
		erg++;
		w.betstuf = wopro ;
		if (wopro > -1)
			wopro = -1 ;
		w.betchg = betchg ;
		if (betchg != 0)
			betchg = 0 ;
		w.text = strdup(buffer);
		w.satztyp = garnix ;
		w.konstit = Unknowne ;
		w.pg_betonung = 0 ;


// Hier sind noch nicht mehrere Wortklassen zulaessig

		strncpy(w.wordclass, erg, 3);
      erg = strstr(erg,"LEX") ;
/*		if (erg != NULL) {
	      if ((isupper(erg[3]) || erg[3] == 'Ä' || erg[3] == 'Ö' || erg[3] == 'Ü') && start != 1) {
   	   	strncpy(w.wordclass,"NOM",3) ;
	         start = 0 ; } }
*/		w.wk = get_wortart(w.wordclass) ;
		conc(w) ; }
	}

Wordlist::Wordlist(char** lexlist, int lexemnr) {
	char buffer[256] ;
	char* erg ;
	Word w ;
	int frage ;
	MIN_BORDER = 2 ;
	Word w1 ;
	int wopro = -1 ;
	int j ;
	int emph = 0 ;
	int betchg = 0 ;
   int start = 1 ;
	
	frage = 0 ;
	for (j = 0 ; j < lexemnr ; j++)
	{
		if (fragewort(lexlist[j]))
			frage = 1 ;	
		strcpy(buffer,lexlist[j]) ;
		w.text = NULL;
		w.flag = 0;
		if (strchr(".;!?", buffer[0]) != NULL && strlen(buffer)<4)
		{
				if (buffer[0] == ';')
					add_constituent_info(teilsatzende) ;
				else {
						add_constituent_info(satzende) ;
						switch (buffer[0]) {
							case '.' : add_sentence_type(aussage) ; break ;
							case '!' : add_sentence_type(befehl) ; break ;
							case '?' : 	add_sentence_type(frage==1?wfrage:efrage) ; break ; } }
		}
		if(buffer[0] == '{') {
			w.text = strdup(buffer) ;
			strncpy(w.wordclass,"COM",3) ;
			w.wk = Unknown ;
			w.konstit = invalid ;
			w.pg_betonung = 0 ;
			w.satztyp = garnix ;
			if (strncmp(w.text,"{Emphasis:on}",13) == 0)
			       emph = 1 ;
			if (strncmp(w.text,"{Emphasis:off}",14) == 0)
			       emph = 0 ;
			if (strncmp(w.text,"{WordProminence:",16) == 0)
				wopro = atoi(&(w.text)[16]) ;
			if (strncmp(w.text,"{ChangeWordProminence:",22) == 0)
				betchg = atoi(&(w.text)[22]) ;
			if (strncmp(w.text,"{BoundaryStrength:",18) == 0)
				MIN_BORDER = atoi(&(w.text)[18]) ;
			conc(w) ; }
		if (strstr((char*)buffer,"##") != NULL)
			w.flag = 1;
		erg = strchr((char*)buffer, ' ');
		if (erg == NULL)
		{
			continue;
		}

		erg[0] = '\0';
		erg++;
		w.betstuf = wopro ;
		if (wopro > -1)
			wopro = -1 ;
		w.betchg = betchg ;
		if (betchg != 0)
			betchg = 0 ;
		if (emph == 1)
		  w.betchg = 20 ;
		w.text = strdup(buffer);
		w.satztyp = garnix ;
		w.konstit = Unknowne ;
		w.pg_betonung = 0 ;

// Hier sind noch nicht mehrere Wortklassen zulaessig

		strncpy(w.wordclass, erg, 3);
			
//		Hier kommen WortklassenEI
		char wklstring[256] ;
		sprintf(wklstring,"{WordClass:%c%c%c}",w.wordclass[0],w.wordclass[1],w.wordclass[2]) ;
		if (w.flag == 0) {
			w1.text = strdup(wklstring) ;
			strncpy(w1.wordclass,"COM",3) ;
			w1.wk = Unknown ;
			w1.konstit = invalid ;
			w1.satztyp = garnix ;
			w1.pg_betonung = 0 ;
			conc(w1) ; }



      erg = strstr(erg,"LEX") ;
/*    if (erg != NULL) {
   	   if ((isupper(erg[3]) || erg[3] == 'Ä' || erg[3] == 'Ö' || erg[3] == 'Ü') && start != 1) {
      		strncpy(w.wordclass,"NOM",3) ; } }
*/     	start = 0 ;
		w.wk = get_wortart(w.wordclass) ;
		conc(w) ; }

	}

Wordlist::~Wordlist() {
	reset() ;
	while (act != NULL) {
		if (act->i.text != NULL)
			delete[](act->i.text) ;
		act = act->after ; } }

int Wordlist::conc(Word i) {
	return(append(i)) ; }

Word* Wordlist::get_word_pointer() {
	return(&(act->i)) ; }


void Wordlist::print(FILE* ascoutfil) {
	reset() ;
	Word i ;
	while ((i = get_and_advance()).flag != errorvalue.flag) {
		fprintf(ascoutfil,"%8s %c%c%c  %d  %s %s %3d  %d  %d\n",i.text,i.wordclass[0],i.wordclass[1],i.wordclass[2],i.flag,Konstnames[(int)i.konstit],Satznames[(int)i.satztyp],i.pg_betonung, i.betstuf, i.wk) ; } }

TPhrKons Wordlist::get_following_constituents(int i, int offset) {
	Word w ;
	int j = 1 ;
	int k = 1 ;
	while ((w = get(j)).flag != errorvalue.flag) {
		if (w.konstit != Unknowne) {
			k++ ;
			if (k == offset)
				break ; } }
	return(w.konstit) ; }

int Wordlist::add_constituent_info(TPhrKons k) {
	end->i.konstit = k ;
	return(end->index) ; }

int Wordlist::add_sentence_type(TSentenceType t) {
	int count = 0 ;
	int i = end->index ;
	while (i > 0) {
		get(i--) ;
		if (act->i.satztyp != garnix)
			break ;
		act->i.satztyp = t ;
		count++ ; }
	return(count) ; }

int Wordlist::get_syllable_number_in_constituent(int i) {
	int sc = 0 ;
	get(i--) ;
//	fprintf(errfile,"For %s ",act->i.text) ;
	sc += find_sylls(act->i.text) ;
	while (i > 0) {
		get(i--) ;
		if (act->i.konstit != Unknowne)
			break ;
		sc += find_sylls(act->i.text) ; }
//	fprintf(errfile,"%d Syllables found in constit\n",sc) ;
	return(sc) ; }

int Wordlist::get_syllable_number_in_phrase(int i) {
	int sc = 0 ;
	get(i--) ;
//	fprintf(errfile,"For %s ",act->i.text) ;
	sc += find_sylls(act->i.text) ;
	while (i > 0) {
		get(i--) ;
		if (act->i.konstit == teilsatzende || act->i.konstit == satzende || act->i.konstit == emphase)
			break ;
		sc+= find_sylls(act->i.text) ; }
//	fprintf(errfile,"%d Syllables found in constit\n",sc) ;
	return(sc) ; }

TWordClass Wordlist::get_wordclass(int i, int offset) {
	Word w = get(i) ;
	int count = 0, j ;

//	fprintf(errfile,"in GWK: i %d offset %d  sign %d\n",i,offset,sign(offset)) ;

	for (j = i ; count < abs(offset) ;) {
		do {
			j+= sign(offset) ;
//			fprintf(errfile,"in GWK: j %d count %d\n",j,count) ;
			if (j < 1)
				return(Unknown) ;
			w = get(j) ;
			if (w.flag == errorvalue.flag)
				return(Unknown) ;
//			fprintf(errfile,"text %s\n",w.text) ;
			}
		while (w.konstit == invalid) ;
		count++ ; }
//	fprintf(errfile,"in GWK:text %s j %d count %d wk %d\n",w.text,j,count,w.wk) ;
	return(w.wk) ; }

int Wordlist::putpros() {
	Word* w ;
	char buffer[256] ;
	int i,k,l ;
	char val ;

	reset() ;
	while ((w = get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (advance() == -1)
				break ;
			continue ; }
		i = 0 ;
		l = -1 ;
		val = ' ' ;
		for (k=0 ; k < (int)strlen(w->text) ; k++) {
			if (w->text[k] == '\'' || w->text[k] == ',')
				val = w->text[k] ;
			else
				buffer[++l] = w->text[k] ;
			if (w->text[k] == '|') {
					buffer[l] = '\0' ;
					l = l + putsylpros(&buffer[i],l-i,w->betstuf,val) ;
					buffer[l] = '|' ;
					buffer[++l] = '\n' ;
					val = ' ' ;
					i = l+1 ; } }
		buffer[++l] = '\0' ;
		delete[](w->text) ;
		w->text = strdup(buffer) ;
		if (advance() == -1)
			break ; }
	return(1) ; }

int Wordlist::ipa2sampa() {
	Word* w ;
	char resultbuffer[256] ;
	int i,j ;

	reset() ;
	while ((w = get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (advance() == -1)
				break ;
			continue ; }
		j = 0 ;
		for (i=0 ; i < (int)strlen(w->text) ; i++)
			switch (w->text[i])
			{
				case '6':
				case 'r':
					resultbuffer[j++] = 'R';
					break;
				case ' ':
					break;
				default:
					resultbuffer[j++] = w->text[i];
					break;
			}
		delete[](w->text) ;
		resultbuffer[j] = '\0' ;
		w->text = strdup(resultbuffer) ;
		if (advance() == -1)
			break ; }
	return(1) ; }


int Wordlist::output(TFile& outfile) {
	Word* w ;

	reset() ;
	while ((w = get_word_pointer()) != NULL) {
		if (w-> konstit != invalid) {
			outfile.PrintF("#") ;
			if (w->flag == 1)
				outfile.PrintF("#") ; }
		outfile.PrintF("%s",w->text) ;
		if (w->konstit == invalid)
			outfile.PrintF("\n") ;
#ifdef NOT_SO_MANY_BOUNDARIES
      if (w->pg_betonung >= MIN_BORDER && (w->konstit == satzende || w->konstit == teilsatzende)) {
#else
		if (w->pg_betonung >= MIN_BORDER) {
#endif
			if (w->konstit != satzende)
				outfile.PrintF("*W[%d]|\n",w->pg_betonung) ;
			else {
				if (w->satztyp == aussage || w->satztyp == befehl)
					outfile.PrintF("*F[%d]|\n",w->pg_betonung) ;
				else
					outfile.PrintF("*R[%d]|\n",w->pg_betonung) ; } }
		if (advance() == -1)
			break ; }
	return(1) ; }

int Wordlist::output(FILE* outfile) {
	Word* w ;

//   fprintf(errfile,"MIN_BORDER %d\n",MIN_BORDER) ;

	reset() ;
	while ((w = get_word_pointer()) != NULL) {
		if (w-> konstit != invalid) {
			fprintf(outfile,"#") ;
			if (w->flag == 1)
				fprintf(outfile,"#") ; }
		fprintf(outfile,"%s",w->text) ;
		if (w->konstit == invalid)
			fprintf(outfile,"\n") ;
#ifdef NOT_SO_MANY_BOUNDARIES
      if (w->pg_betonung >= MIN_BORDER && (w->konstit == satzende || w->konstit == teilsatzende)) {
#else
		if (w->pg_betonung >= MIN_BORDER) {
#endif
			if (w->konstit != satzende)
				fprintf(outfile,"*W[%d]|\n",w->pg_betonung) ;
			else {
				if ((w->satztyp == aussage || w->satztyp == befehl))
					fprintf(outfile,"*F[%d]|\n",w->pg_betonung) ;
				else
					fprintf(outfile,"*R[%d]|\n",w->pg_betonung) ; }}
		else
		  fprintf(outfile,"\n") ;
		if (advance() == -1)
			break ; }
	return(1) ; }

int Wordlist::convert(Syllablelist* s) {
	Word* w ;
	Syllableinfo sy ;
	char nbuf[256] ;

	int i,j,k,l ;

	reset() ;
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
	s->conc(sy) ;
	while ((w = get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			sy.type = strdup("COM") ;
			sy.name = strdup(w->text) ;
			sy.name[strlen(sy.name)-1] = '\0' ;
			sy.prosinfo = strdup("") ;
			sy.firstsound = 0 ;
			sy.soundnr = 0 ;
			sy.wordstart = 0 ;
			sy.accent = 0 ;
			s->conc(sy) ;
			if (advance() == -1)
				break ;
			continue ; }
		nbuf[0] = '\0' ;
		k = 0 ;
		if (w-> konstit != invalid) {
			strcat(nbuf,"#") ;
			k++ ;
			if (w->flag == 1) {
				k++ ;
				strcat(nbuf,"#") ; } }
		for (i=0 ; i < (int)strlen(w->text) ; i++) {
			if (w->text[i] != '|' && w->text[i] != '\n')
				nbuf[k++] = w->text[i] ;
			else if (w->text[i] == '|') {
				nbuf[k] ='\0' ;
				k = 0 ;
				sy.type = strdup("SIL") ;
				sy.firstsound = 0 ;
				sy.wordstart = 0 ;
				sy.soundnr = 0 ;
				sy.name = new char[strlen(nbuf)+1] ;
				sy.prosinfo = new char[8] ;
				for (l = j = 0 ; l < (int)strlen(nbuf) ; l++) {
					if (nbuf[l] == '[') {
						l++ ;
						break ; }
					sy.name[j++] = nbuf[l] ; }
				sy.accent = atoi(&nbuf[l]) ;
				if (sy.accent > 17)
					strcpy(sy.prosinfo,"H") ;
				else
					strcpy(sy.prosinfo,"-") ;
				sy.name[j] = '\0' ;
				s->conc(sy) ; } }
#ifdef NOT_SO_MANY_BOUNDARIES
      if (w->pg_betonung >= MIN_BORDER && (w->konstit == satzende || w->konstit == teilsatzende)) {
#else
	        if (debuglevel > 1)
		  fprintf(errfile,"MIN_BORDER %d\n",MIN_BORDER) ; 
		if (w->pg_betonung >= MIN_BORDER) {
#endif

//			fprintf(errfile,"Putting border after %s\n",w->text) ;

			sy.type = strdup("PGR") ;
			if (w->konstit != satzende) {
					sy.prosinfo = strdup("10") ;
					sy.name = strdup("GRUPPE") ;
					sy.soundnr = 0 ; }
			else {
				if ((w->satztyp == aussage || w->satztyp == befehl || w->satztyp==wfrage)) {
					sy.prosinfo = strdup("02") ;
					sy.soundnr = 2 ;
					sy.name = strdup("SATZ") ; }
				else {
					sy.prosinfo = strdup("12") ;
					sy.name = strdup("SATZ") ;
					sy.soundnr = 2 ; } }
			sy.accent = w->pg_betonung  ;
#ifndef BORDERPROS
			sy.accent = 150 ;
#endif
			s->conc(sy) ; }
		if (advance() == -1)
			break ; }
	return(1) ; }



//#define max(a,b)((a)>(b)?(a):(b))



bool fragewort (const string &word)
{
	if ((word[0] == '\'' && word[1] == 'v') || (word[0] == 'v'))
		if (word == "'vEl|C=6'|"   ||
			word == "'vEl|C@s|"   ||
			word == "'vEl|C@|"    ||
			word == "'vi:|fi:l|"  ||
			word == "'vi:|"       ||
			word == "'vo:|"       ||
			word == "'ve:6|"      ||
			word == "'van|"       ||
			word == "'vas|"       ||
			word == "'ve:m|"      ||
			word == "'ve:n|"      ||
			word == "'vE|s=n|"     ||
			word == "va|'rUm|"    ||
			word == "vEs|'halp|"  ||
			word == "vi|'zo:|"    ||
			word == "vo|'dUrC|"   ||
			word == "vo|'mIt|"    ||
			word == "vo|'fy:6|"   ||
			word == "vo|'ge:|g=N|" ||
			word == "vo|'he:6|"   ||
			word == "vo|'hIn|"    ||
			word == "vo|'ran|"    ||
			word == "vo|'raUf|"   ||
			word == "vo|'raUs|"   ||
			word == "vo|'raIn|"   ||
			word == "vo|'rIn|"    ||
			word == "vo|'ry:|b=6|" ||
			word == "vo|'rUm|"    ||
			word == "vo|'fOn|"    ||
			word == "vo|'fo:=6|"   ||
			word == "vo|'tsu:|")
			return true;
		else
			return false;
	else
		return false;
}


void prosogenx (char** lexlist, Syllablelist* s, int cnt_lexem, FILE*debugfile)
{
	Wordlist wl(lexlist,cnt_lexem) ;

	int number ;

	Word* w ;

	int l = 3;

	TWordClass wortart, wa_1p, wa_1f, wa_3p, wa_2p ;
	int betonung, wortimsatz = 0 , satzposi  ;

	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }
		wortimsatz++ ;
		if (wortimsatz > 3)
			satzposi = 0 ;
		else
			satzposi = wortimsatz ;
		if (w->konstit != Unknowne)
			satzposi = 4 ;
		wortart = w->wk ;
		number = wl.get_number() ;
		wa_1p = wl.get_wordclass(number, -1) ;
		wa_2p = wl.get_wordclass(number, -2) ;
		wa_3p = wl.get_wordclass(number, -3) ;
		wa_1f = wl.get_wordclass(number, 1) ;


		betonung = 20 ;


#include "cwirules.cpp"



// PG-Regeln von Christina Stufe 1
//#Die Konstituenten NP, PP, VP, VI im ganzen Satz bzw. Teilsatz #
		if (w->konstit == Unknowne) {
			if  (wortart == PPR || wortart == NAM)
				{w->konstit = NP;}
			if  (wortart == PRO && (wa_1f != NOM || wa_1f != QAN))
				{w->konstit  = NP;}
			if  (wortart == NOM && wa_1f != NAM && wa_1f != NUM)
				{w->konstit = NP;}
			if  (wortart == NUM && wa_1p == NOM)	// #Datum#
				{w->konstit = NP;}
			if  (wortart == NAM && wa_1p == NOM)	// #Ortsangaben#
				{w->konstit = NP;}
			if  (w->konstit == NP && (wa_3p == ADD || wa_2p == ADD || wa_1p == ADD))
				{w->konstit  = PP;}
			if ((wortart == VRB || wortart == VES || wortart == VEH|| wortart == VEM || wortart == VEW) && wa_1p != ADD)
				{w->konstit   = VP;}
			if ((wortart == VRB || wortart == VES || wortart == VEH|| wortart == VEM || wortart == VEW) && wa_1p == ADD)
				{w->konstit   = VI;} }

		if (w->betstuf < 0)
			w->betstuf = betonung ;
		w->betstuf += w->betchg ;
		if (w->betstuf < 0)
			w->betstuf = 0 ;
		if (w->betstuf > 31)
			w->betstuf = 31 ;
		w->bettyp = '-' ;
		if (w->betstuf > 18)
			w->bettyp = 'H' ;

		wl.get(number) ;
		if (wl.advance() == -1)
			break ;
		}


	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }



// Chistinas Regeln 2. Stufe
 // #Konstituenten innerhalb der Verbalphrase#

		if (w->konstit == VP) {
			while (w->konstit != satzende && w->konstit != teilsatzende) {
				if (wl.advance() == -1)
					break ;
				if (w->konstit ==NP)
					{w->konstit = TNP;}
				if (w->konstit ==PP)
					{w->konstit = TPP;}
				if (w->konstit ==VP)
					{w->konstit = TVP;}
				if (w->konstit ==VI)
					{w->konstit = TVI;}} }
		if (wl.advance() == -1)
			break ; }

	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }



// Christinas Regeln 3. Stufe
// #Finden von verbundenen Teils?tzen#

		number = wl.get_number() ;

		wa_1f = wl.get_wordclass(number,1) ;
		if ((w->konstit == TPP || w->konstit == TNP) && wa_1f == VKN && wl.get_following_constituents(number,1) == TVP)
			{ w->konstit = teilsatzende;}
		if ((w->konstit == TPP || w->konstit == TNP) && wa_1f == VKN && (wl.get_following_constituents(number,1) == TPP || wl.get_following_constituents(number,1) == TNP) && wl.get_following_constituents(number,2) == TVP)
			{ w->konstit = teilsatzende;}
		wl.get(number) ;
		if (wl.advance() == -1)
			break ; }

	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }




// Christinas Regeln 4. Stufe
// #Zuordnen der Betonungswerte an Konstituentenenden#

		number = wl.get_number() ;

		if (w->konstit == NP || w->konstit == PP) {
			w->pg_betonung = 1;
			if (wl.get_syllable_number_in_constituent(number) > 7)
				{w->pg_betonung = 2;} }
		if (w->konstit == TNP || w->konstit == TPP) {
			w->pg_betonung = 1;
			if (wl.get_following_constituents(number,1) != TVP || wl.get_following_constituents(number,1) != TVI) {
				w->pg_betonung = 2;
				if (wl.get_syllable_number_in_constituent(number) > 7) {
					w->pg_betonung = 3;}} }
		wl.get(number) ;
		if (wl.advance() == -1)
			break ; }


	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }

		number = wl.get_number() ;



// Christinas Regeln 5. Stufe
// #Zuweisen der Betonungswerte am Teilsatz bzw. Satzende und vor bzw. nach emphatischen AusdrNcken#

		if (w->konstit == teilsatzende)
			{ w->pg_betonung = 3;}
		if (w->konstit == teilsatzende && w->flag == 1)
			{ w->pg_betonung = l;}
		if (w->konstit == teilsatzende && wl.get_syllable_number_in_phrase(number) > 3)
			{ w->pg_betonung = 5;}
		if (w->konstit == satzende)
			{ w->pg_betonung = 8;}
		if (w->konstit == emphase)
			{ w->pg_betonung = 5;}
		l = w->pg_betonung ;
		wl.get(number) ;
		if (wl.advance() == -1)
			break ; }

//	wl.output(errfile) ;

	wl.ipa2sampa() ;

	wl.putpros() ;

	wl.convert(s) ;

       	if (debugfile != NULL)
		wl.output(debugfile) ;


if (debuglevel > 0) {
	fprintf(errfile,"\n\nOutput Word Module:\n\n") ;
	wl.output(errfile) ;
}
}


void prosogen (const TFile &infile, TFile &outfile, int cnt_lexem)
{
	if (!infile.Open('t'))
		ERRMSG("Konnte Eingabedatei fNr prosogen nicht öffnen");
	if (!outfile.Append('t'))
		ERRMSG("Konnte Ausgabedatei fNr prosogen nicht öffnen");

	Wordlist wl((TFile&)infile) ;

	int number ;

	Word* w ;

	int l = 3 ;

	TWordClass wortart, wa_1p, wa_1f, wa_3p, wa_2p ;
	int betonung, wortimsatz = 0 , satzposi  ;

	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }
		wortimsatz++ ;
		if (wortimsatz > 3)
			satzposi = 0 ;
		else
			satzposi = wortimsatz ;
		if (w->konstit != Unknowne)
			satzposi = 4 ;
		wortart = w->wk ;
		number = wl.get_number() ;
		wa_1p = wl.get_wordclass(number, -1) ;
		wa_2p = wl.get_wordclass(number, -2) ;
		wa_3p = wl.get_wordclass(number, -3) ;
		wa_1f = wl.get_wordclass(number, 1) ;


		betonung = 20 ;

#include "cwirules.cpp"


// PG-Regeln von Christina Stufe 1
//#Die Konstituenten NP, PP, VP, VI im ganzen Satz bzw. Teilsatz #
		if (w->konstit == Unknowne) {
			if  (wortart == PPR || wortart == NAM)
				{w->konstit = NP;}
			if  (wortart == PRO && (wa_1f != NOM || wa_1f != QAN))
				{w->konstit  = NP;}
			if  (wortart == NOM && wa_1f != NAM && wa_1f != NUM)
				{w->konstit = NP;}
			if  (wortart == NUM && wa_1p == NOM)	// #Datum#
				{w->konstit = NP;}
			if  (wortart == NAM && wa_1p == NOM)	// #Ortsangaben#
				{w->konstit = NP;}
			if  (w->konstit == NP && (wa_3p == ADD || wa_2p == ADD || wa_1p == ADD))
				{w->konstit  = PP;}
			if ((wortart == VRB || wortart == VES || wortart == VEH|| wortart == VEM || wortart == VEW) && wa_1p != ADD)
				{w->konstit   = VP;}
			if ((wortart == VRB || wortart == VES || wortart == VEH|| wortart == VEM || wortart == VEW) && wa_1p == ADD)
				{w->konstit   = VI;} }

		if (w->betstuf < 0)
			w->betstuf = betonung ;
		w->betstuf += w->betchg ;
		if (w->betstuf < 0)
			w->betstuf = 0 ;
		if (w->betstuf > 31)
			w->betstuf = 31 ;
		w->bettyp = '-' ;
		if (w->betstuf > 18)
			w->bettyp = 'H' ;

		wl.get(number) ;
		if (wl.advance() == -1)
			break ;
		}


	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }

// Chistinas Regeln 2. Stufe
 // #Konstituenten innerhalb der Verbalphrase#

		if (w->konstit == VP) {
			while (w->konstit != satzende && w->konstit != teilsatzende) {
				if (wl.advance() == -1)
					break ;
				if (w->konstit ==NP)
					{w->konstit = TNP;}
				if (w->konstit ==PP)
					{w->konstit = TPP;}
				if (w->konstit ==VP)
					{w->konstit = TVP;}
				if (w->konstit ==VI)
					{w->konstit = TVI;}} }
		if (wl.advance() == -1)
			break ; }

	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }

// Christinas Regeln 3. Stufe
// #Finden von verbundenen Teils?tzen#

		number = wl.get_number() ;

		wa_1f = wl.get_wordclass(number,1) ;
		if ((w->konstit == TPP || w->konstit == TNP) && wa_1f == VKN && wl.get_following_constituents(number,1) == TVP)
			{ w->konstit = teilsatzende;}
		if ((w->konstit == TPP || w->konstit == TNP) && wa_1f == VKN && (wl.get_following_constituents(number,1) == TPP || wl.get_following_constituents(number,1) == TNP) && wl.get_following_constituents(number,2) == TVP)
			{ w->konstit = teilsatzende;}
		wl.get(number) ;
		if (wl.advance() == -1)
			break ; }


	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }


// Christinas Regeln 4. Stufe
// #Zuordnen der Betonungswerte an Konstituentenenden#

		number = wl.get_number() ;

		if (w->konstit == NP || w->konstit == PP) {
			w->pg_betonung = 1;
			if (wl.get_syllable_number_in_constituent(number) > 7)
				{w->pg_betonung = 2;} }
		if (w->konstit == TNP || w->konstit == TPP) {
			w->pg_betonung = 1;
			if (wl.get_following_constituents(number,1) != TVP || wl.get_following_constituents(number,1) != TVI) {
				w->pg_betonung = 2;
				if (wl.get_syllable_number_in_constituent(number) > 7) {
					w->pg_betonung = 3;}} }
		wl.get(number) ;
		if (wl.advance() == -1)
			break ; }


	wl.reset() ;
	while ((w = wl.get_word_pointer()) != NULL) {
		if (strncmp(w->wordclass,"COM",3) == 0) {
			if (wl.advance() == -1)
				break ;
			continue ; }

		number = wl.get_number() ;

// Christinas Regeln 5. Stufe
// #Zuweisen der Betonungswerte am Teilsatz bzw. Satzende und vor bzw. nach emphatischen AusdrNcken#

		if (w->konstit == teilsatzende)
			{ w->pg_betonung = 3;}
		if (w->konstit == teilsatzende && w->flag == 1)
			{ w->pg_betonung = l;}
		if (w->konstit == teilsatzende && wl.get_syllable_number_in_phrase(number) > 3)
			{ w->pg_betonung = 5;}
		if (w->konstit == satzende)
			{ w->pg_betonung = 8;}
		if (w->konstit == emphase)
			{ w->pg_betonung = 5;}
		l = w->pg_betonung ;
		wl.get(number) ;
		if (wl.advance() == -1)
			break ; }


	wl.ipa2sampa() ;

	wl.putpros() ;

	wl.output(outfile) ;

	infile.Close();
        outfile.Close() ;
}

