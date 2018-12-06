/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/



#include "tools.h"
#include "lisatalk.h"
#include "debug.h"
#include "vv.h"

#ifndef _Windows
extern int strcomp(char*,char*) ;
#else
#define strcomp strcmp
#endif

#include <stdio.h>

extern int piping ;

int is_whitespace(char c) {
	if (c == 13 || c == 10)
   	return(1) ; 
	if (strchr(" \n\t\0",c) == NULL)
		return(0) ;
	return(1) ; }


char *VV::isabkz (const char *in)
{

	if (in == NULL || abklst == NULL)
		return NULL;

	int i, j, k;
	char *result = NULL;

	fprintf(errfile,"%s\n",in) ;
	int e = strlen(in) ;
	if (strncmp(&in[e-4],"str.",4) == 0)
	  {
	    result = new char[strlen(in)+10] ;
	    memcpy(result,in,e-4) ;
	    result[e-4] = '\0' ;
	    strcat(result,"straﬂe") ;
	    return result ;
	  }

	for (i = j = 0; i < abklstlen; i++)
	{
		if (abklst[i] == ' ' && in[j] == '\0')
		{
			k = i;
			while (abklst[k] != '.' && abklst[k] != '\n' && abklst[k] != '\r')
				k++;
			if (abklst[k] != '.')
			{
				ALLOCATE(char, result, 500);
				while (abklst[i] == ' ')
					i++;
				j = 0;
				while (abklst[i] != '\n' && abklst[i] != '\r')
					result[j++] = abklst[i++];
				result[j] = '\0';
				return(result);
			}
		}
		if (abklst[i] != in[j])
		{
			while (abklst[i] != '\n' && i < abklstlen)
				i++ ;
			j = 0 ;
			continue ; }
		j++ ; }
	return(NULL) ; }

char *VV::iseinh (const char* in)
{
	if (in == NULL || einlst == NULL)
		return NULL;

	int i, j;
	char *result = NULL;

	for (i=j=0 ; i < einlstlen ; i++) {
		if (einlst[i] == ' ' && in[j] == '\0') {
			ALLOCATE(char, result, 500);
			while (einlst[i] == ' ')
				i++ ;
			j = 0 ;
			while (einlst[i] != '\n' && einlst[i] != '\r' && einlst[i] != '<')
				result[j++] = einlst[i++] ;
			result[j] = '\0' ;
			return(result) ; }
		if (einlst[i] != in[j]) {
			while (einlst[i] != '\n' && i < einlstlen)
				i++ ;
			j = 0 ;
			continue ; }
		j++ ; }
	return(NULL) ; }

char *VV::get_number (const char *in, int level = 0)
{
	long number ;
	int digits = strlen(in) ;
	char* zwres ;
	char* result = NULL;
	ALLOCATE(char, result, digits * 20);
	result[0] = '\0' ;
	const char *start = in;
	char inter[20] ;
	int i,j=0,k = 0 ;
	number = abs(atol(start)) ;
	if ((number > 10000L && level == 0 && strcomp((char*)&in[digits-3],(char*)"00") != 0) || (digits > 2 && level == 2) || (in[0] == '0' && level != 2)) {
		for (i=0 ; i < digits ; i++) {
			inter[0] = in[i] ;
			inter[1] = '\0' ;
			level = 2 ;
			zwres = get_number(inter,level) ;
			strcat(result,zwres) ;
			if (in[i] == '1')
				strcat(result,"s") ;
			strcat(result," ") ;
			CLEAR(zwres); }
		return(result) ; }
	if ((number == 1 || (number > 99 && number%10 == 1)) && level == 0)
		k = 1 ;
	if (number > 999) {
		strcpy(inter,in) ;
		inter[digits-3] = '\0' ;
		zwres = get_number(inter,1) ;
		start = &in[digits-3] ;
		strcpy (result,zwres) ;
		strcat (result,"tausend") ;
		j += strlen(zwres)+7 ;
		digits = strlen(start) ;
		number = atol(start) ;
		CLEAR(zwres);
	}
	if (number > 99) {
		strcpy(inter,start) ;
		inter[digits-2] = '\0' ;
		zwres = get_number(inter,1) ;
		start = &start[digits-2] ;
		strcat (result,zwres) ;
		strcat (result,"hundert") ;
		j += strlen(zwres)+7 ;
		number = atol(start) ;
		CLEAR(zwres);
	}
	if (number > 20 && number % 10 != 0) {
		sprintf(inter, "%d", (int) (number % 10));
		zwres = get_number(inter,1) ;
		strcat (result,zwres) ;
		strcat (result,"und") ;
		j += strlen(zwres)+3 ;
		number = (number / 10) * 10 ;
		CLEAR(zwres);
	}
	if (number > 0) {
	 for (i=0 ; i < numlstlen ; i++) {
		if (atol(&numlst[i]) == number) {
			while (numlst[i] != ' ')
				i++ ;
			i++ ;
			while (numlst[i] != '\n' && numlst[i] != '\r')
				result[j++] = numlst[i++] ;
			result[j] = '\0' ;
			break ; }
		while (numlst[i] != '\n')
			i++ ;
		continue ; } }
	else if (level != 1 && digits == 1)
		strcat(result,"null") ;
	if (k) {
		result[j] = 's' ;
	result[j+1] = '\0' ; }

	return(result) ; }

char *VV::get_ordinumber (const char *in)
{
	if (in == NULL || ordlst == NULL)
		return(NULL) ;
	long number ;
	int digits = strlen(in)-1 ;
	char* zwres ;
	char* result = NULL;
	ALLOCATE(char, result, 1000);
	result[0] = '\0' ;
	const char* start = in ;
	char inter[20] ;
	int i,j=0 ;
	number = atol(start) ;
	if (number > 1999) {
		strcpy(inter,in) ;
		inter[digits-3] = '\0' ;
		zwres = get_number(inter,1) ;
		start = &in[digits-3] ;
		strcpy (result,zwres) ;
		strcat (result,"tausend") ;
		j += strlen(zwres)+7 ;
		digits = strlen(start) ;
		number = atol(start) ;
		CLEAR(zwres);
	}
	if (number > 99) {
		strcpy(inter,start) ;
		inter[digits-2] = '\0' ;
		zwres = get_number(inter,1) ;
		start = &start[digits-2] ;
		strcat (result,zwres) ;
		strcat (result,"hundert") ;
		j += strlen(zwres)+7 ;
		number = atol(start) ;
		CLEAR(zwres);
	}
	if (number > 20 && number % 10 != 0) {
		sprintf(inter,"%ld",number%10) ;
		zwres = get_number(inter,1) ;
		if (number % 10 == 1)
			zwres[strlen(zwres)-1] = '\0' ;
		strcat (result,zwres) ;
		strcat (result,"und") ;
		j += strlen(zwres)+3 ;
		number = (number / 10) * 10 ;
		CLEAR(zwres);
	}
	if (number > 0) {
	 for (i=0 ; i < numlstlen ; i++) {
		if (atol(&ordlst[i]) == number) {
			while (ordlst[i] != ' ')
				i++ ;
			i++ ;
			while (ordlst[i] != '\n' && ordlst[i] != '\r')
				result[j++] = ordlst[i++] ;
			result[j] = '\0' ;
			break ; }
		while (ordlst[i] != '\n')
			i++ ;
		continue ; } }
	else
		strcpy(&result[j],"ste") ;
	return(result) ; }

char *VV::isnumber (const char *in)
{
	if (in == NULL || numlst == NULL)
		return(NULL) ;
	char* a = NULL;
	ALLOCATE(char, a, strlen(in) + 1);
	char* b ;
	char* vkresult ;
	char* nkresult = NULL ;
	const char* komma = " Komma " ;
	const char* punkt = " Punkt " ;
	const char* uhr = " Doppelpunkt " ;
	int ku = 'k' ;
	strcpy(a,in) ;
	vkresult = get_number(a) ;
	if ((b = strchr(a,',')) != NULL) {
		*b = '\0' ;
		b++ ;
		nkresult = isnumber(b) ; }
	if ((b = strchr(a,'.')) != NULL) {
		*b = '\0' ;
		b++ ;
		ku = 'p' ;
		nkresult = isnumber(b) ; }
	if ((b = strchr(a,':')) != NULL) {
		*b = '\0' ;
		b++ ;
		ku = 'u' ;
		nkresult = isnumber(b) ; }
//	vkresult = get_number(a) ;
	char* result = NULL;
	if (nkresult != NULL)
	  ALLOCATE(char, result, strlen(nkresult) + strlen(vkresult) + strlen(uhr) + 2);
	else
	  ALLOCATE(char, result, strlen(vkresult) + strlen(uhr) + 2);
	strcpy(result,vkresult) ;
	CLEAR(vkresult);
	if (nkresult != NULL) {
		switch (ku) {
			case 'u': strcat(result,uhr) ; break ;
			case 'k': strcat(result,komma) ; break ;
			case 'p': strcat(result,punkt) ; break ; }
		strcat(result,nkresult) ;
		CLEAR(nkresult); }
	CLEAR(a) ;
	return(result) ; }

char *VV::issymb (char in)
{
	if (in == 0 || symlst == NULL)
		return(NULL) ;
	int i,j ;
	char* result = NULL ;
	for (i=0 ; i < symlstlen ; i++) {
		if (symlst[i] != in) {
			while (symlst[i] != '\n')
				i++ ;
			continue ; }
		ALLOCATE(char, result, 50);
		if (result == NULL)
			exit(0) ;
		while (symlst[i++] == ' ')
			i++ ;
		j = 0 ;
		while (symlst[i] != '\n' && symlst[i] != '\r')
			result[j++] = symlst[i++] ;
		result[j] = '\0' ;
		return(result) ; }
	return(NULL) ; }


VV::VV (const string &datapath) :
	abklst(NULL),  abklstlen(0),
	einlst(NULL),  einlstlen(0),
	symlst(NULL),  symlstlen(0),
	numlst(NULL),  numlstlen(0),
	ordlst(NULL),  ordlstlen(0),
	abklstname(datapath+"hadifix.abk"),
	einlstname(datapath+"hadifix.ehe")

{
        in = stdin ;
        stop = 0 ; 
	TFile abkfile(abklstname);
	if (abkfile.Open('b'))
	{
		abklstlen = abkfile.Size();
		ALLOCATE(char, abklst, abklstlen + 2);
		abkfile.Read(abklst, sizeof(*abklst), abklstlen);
		abklst[abklstlen] = '\0';
		abkfile.Close();
	}

	TFile einfile(einlstname);

	if (einfile.Open('b'))
	{
		einlstlen = einfile.Size();
		ALLOCATE(char, einlst, einlstlen + 2);
		einfile.Read(einlst, sizeof(*einlst), einlstlen);
		einlst[einlstlen] = '\0';
		einfile.Close();
	}

	TFile numfile(datapath + "hadifix.zhl");

	if (numfile.Open('b'))
	{
		numlstlen = numfile.Size();
		ALLOCATE(char, numlst, numlstlen + 2);
		numfile.Read(numlst, sizeof(*numlst), numlstlen);
		numlst[numlstlen] = '\0';
		numfile.Close();
	}

	TFile ordfile(datapath + "hadifix.dtm");

	if (ordfile.Open('b'))
	{
		ordlstlen = ordfile.Size();
		ALLOCATE(char, ordlst, ordlstlen + 2);
		ordfile.Read(ordlst, sizeof(*ordlst), ordlstlen);
		ordlst[ordlstlen] = '\0';
		ordfile.Close();
	}

	TFile symfile(datapath + "hadifix.smb");

	if (symfile.Open('b'))
	{
		symlstlen = symfile.Size();
		ALLOCATE(char, symlst, symlstlen + 2);
		symfile.Read(symlst, sizeof(*symlst), symlstlen);
		symlst[symlstlen] = '\0';
		symfile.Close();
	}
}


VV::~VV ()
{
	CLEAR(symlst);
	CLEAR(numlst);
	CLEAR(ordlst);
	CLEAR(einlst);
	CLEAR(abklst);
}


int VV::add_abbreviation (const char *abb, const char *text)
{
	char *inter = NULL;

	abklstlen += strlen(abb) + strlen(text) + 3;
	ALLOCATE(char, inter, abklstlen + 2);

	if (inter != NULL)
	{
		if (abklst != NULL)
			strcpy(inter, abklst);
		strcat(inter, abb);
		strcat(inter, " ");
		strcat(inter, text);
		strcat(inter, "\x0d\x0a");
		if (abklst != NULL)
			delete[] abklst;
		abklst = inter;

		TFile file(abklstname);

		if (file.Create('b'))
		{
			file.Write(abklst, sizeof(*abklst), abklstlen);
			file.Close();
		}
		else
			fprintf(errfile, "CANNOT OPEN %s\n", abklstname.c_str());
		return 1;
	}
	return -1;
}

int VV::change_SI_abbreviation_list (const string &filename)
{
	einlstname = filename;

	if (einlst != NULL)
	{
		delete[] einlst;
		einlst = NULL;
		einlstlen = 0;
	}

	TFile einfile(einlstname);

	if (einfile.Open('b'))
	{
		einlstlen = einfile.Size();
		ALLOCATE(char, einlst, einlstlen + 2);
		einfile.Read(einlst, sizeof(*einlst), einlstlen);
		einlst[einlstlen] = '\0';
		einfile.Close();
		return 1;
	}
	else
		return -1;
}

int VV::change_abbreviation_list (const string &filename)
{
	abklstname = filename;

	if (abklst != NULL)
	{
		delete[] abklst;
		abklst = NULL;
		abklstlen = 0;
	}

	TFile abkfile(abklstname);
	if (abkfile.Open('b'))
	{
		abklstlen = abkfile.Size();
		ALLOCATE(char, abklst, abklstlen + 2);
		abkfile.Read(abklst, sizeof(*abklst), abklstlen);
		abklst[abklstlen] = '\0';
		abkfile.Close();
		return 1;
	}
	else
		return -1;
}


#define COMPLETE_VV



FILE* VV::next_input (const string &datapath, const string &filename, int piping, const string &pid, const char* lfn)
{
  
	int read = 0;
	if (stop)
		return NULL;

		
	if (piping == 0) {
	  in = NULL;
	  if (datapath != "STRING") {
#ifdef UNIX
		if (filename[0] == '-')
			in = stdin ;
		else 
#endif
		in = fopen(filename.c_str(), "r") ;
		if (in == NULL)
			return (NULL);
#ifdef UNIX
		if (in != stdin)
			rewind(in);
#endif
	  } }


#ifndef UNIX
	FILE* result;
	if (datapath.length() > 3 && datapath != "STRING")
		result = fopen(datapath.c_str(), "w+") ;
	else
		result = fopen(lfn, "w+");
#else
	FILE* result = fopen(lfn, "w+");
#endif
	if (result == NULL)
		return(NULL) ;

	char* buffer;
	int onestring = 0 ;
	if (in == NULL) {
		onestring = 1 ;
      buffer = new char[strlen(filename.c_str())+1] ;
		strcpy(buffer, filename.c_str()) ; }
   else
   	buffer = new char[4096] ;
	char* satzzeichen = NULL ;
	char resultbuffer[4096];
	char lastword[128];
	const char *symbole="%&$=*+<>()/-";
	const char *digits="0123456789";
	const char *alphas="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz¸ˆ‰ƒ÷‹ﬂ‡·ÏÌÚÛËÈÍ‚ÙÓ˚˘˙Ò—" ;
	const char *punctation=".,;:?!" ;
	int j, k;
	char* a = NULL;
	char* point ;
	int lastpoint = 1;
	int lastspace = 0;
	int lastcomma = 0;
	int digicount = 0;
	int lastdigit = 0;
	int lastsymb = 0;
	int dativ = 0;
	int incomment ;
	j = 0;

startpoint:


	
	while ((in == NULL?onestring==1:(fgets(buffer,4095,in) != NULL))) {
	  
	  if (debuglevel > 1) {
	    fprintf(errfile,"IN VV: %s",buffer) ;
	    fflush(errfile) ;
	  }
	  incomment = 0 ;
	  for (size_t i=0 ; i < strlen(buffer) ; i++) {
	    if (buffer[i] == '{') {
	      incomment = 1 ;
	      continue ; }
	    if (buffer[i] == '}') {
	      incomment = 0 ;
	      continue ; }
	    if (incomment == 1)
	      continue ;
	    if (strchr(symbole,buffer[i]) == 0 &&
		strchr(digits,buffer[i]) == 0 &&
		strchr(alphas,buffer[i]) == 0 &&
		strchr(punctation,buffer[i]) == 0 &&
		strchr(" \n\t\0",buffer[i]) == 0) {
	      if (debuglevel > 1) {
		fprintf(errfile,"Eliminating %c\n",buffer[i]) ;
		fflush(errfile) ;
	      }
	      memmove(&buffer[i],&buffer[i+1],strlen(&buffer[i])) ;
	      i-- ; } }
	    

		if (in == NULL)
			onestring = 0 ;

		// Um nicht immer wieder die Stringlaenge berechnen zu muessen, habe ich
		// eine Hilfsvariable eingefuehrt. Die Laenge von ``buffer'' darf sich
		// in der Schleife aber nicht aendern. Deshalb habe ich an kritischen
		// Stellen ``assert()''-Aufrufe eingefuegt. (jkr)
		for (size_t i = 0, len = strlen(buffer); i < len ; i++)
		{	assert(len == strlen(buffer));
		        fflush(result) ;


			if (buffer[i] == '{') {
				read++ ;
				if (j > 0)
					fprintf(result,"%s ",resultbuffer) ;
				j = 0 ;
				resultbuffer[j++] = '{' ;
				while (buffer[i++] != '}'){
					if (j > 2047)
						break ;
					resultbuffer[j++] = buffer[i] ; }
				resultbuffer[j] = '\0' ;
				j = 0 ;
				fprintf(result,"%s ",resultbuffer) ; }
			if (buffer[i] == '"') {
				read++ ;
				if (buffer[i+1] == 'a') {
					resultbuffer[j++] = '‰' ;
					i++ ;
					continue ; }
				if (buffer[i+1] == 'A') {
					resultbuffer[j++] = 'ƒ' ;
					i++ ;
					continue ; }
				if (buffer[i+1] == 'o') {
					resultbuffer[j++] = 'ˆ' ;
					i++ ;
					continue ; }
				if (buffer[i+1] == 'O') {
					resultbuffer[j++] = '÷' ;
					i++ ;
					continue ; }
				if (buffer[i+1] == 'u') {
					resultbuffer[j++] = '¸' ;
					i++ ;
					continue ; }
				if (buffer[i+1] == 'U') {
					resultbuffer[j++] = '‹' ;
					i++ ;
					continue ; }
				if (buffer[i+1] == 's') {
					resultbuffer[j++] = 'ﬂ' ;
					i++ ;
					continue ; }
				read-- ; }
			/*
			signed char 		 x ;
         x = buffer[i];
			switch (x) {
				 case 'ﬂ': x = 225-256; break;
				 case '?': x = 132-256; break;
				 case 'N': x = 129-256; break;
				 case 'ˆ': x = 148-256; break;
				 case 'ƒ': x = 142-256; break;
				 case '÷': x = 153-256; break;
				 case '‹': x = 154-256; break; }
				 
         buffer[i] = x ;
	 */
			if (strchr(symbole,buffer[i]) == 0 &&
				strchr(digits,buffer[i]) == 0 &&
				strchr(alphas,buffer[i]) == 0 &&
				strchr(punctation,buffer[i]) == 0 &&
			    strchr(" \n\t\0",buffer[i]) == 0) {
if (debuglevel > 1) {
			  fprintf(errfile,"Eliminating %c\n",buffer[i]) ;
			  fflush(errfile) ;
}

			  continue ; }
			if (debuglevel > 7) {
			  fprintf(errfile,"Working on %c\n",buffer[i]) ;
			  fflush(errfile) ; }
			if (j > 120) {
				fprintf(result,"%s ",resultbuffer) ;
				j = 0 ; }
			if (strchr(digits,buffer[i]) != NULL) {
				read++ ;
				lastsymb=lastpoint=lastspace=lastcomma=lastsymb = 0 ;
				lastdigit = 1 ;
				if (digicount++ == 0 && j > 0) {
					resultbuffer[j] = '\0' ;
					fprintf(result,"%s ",resultbuffer) ;
					fflush(result) ;
					j = 0 ; }
				resultbuffer[j++] = buffer[i] ;
#if defined COMPLETE_VV
/*				if (buffer[i+1] == ')' && lastpoint && is_whitespace(buffer[i+2])) {
//					strcat(a,"ns . ") ;
					resultbuffer[j++] = '.' ; ++i ;
					resultbuffer[j] = '\0' ;
					digicount = 0 ;
					j = 0 ;
					a = get_ordinumber(resultbuffer) ;
					strcat(a,"ns . ") ; }
*//*				if (buffer[i+1] == '.' && dativ < 2) {
					resultbuffer[j++] = buffer[++i] ;
					resultbuffer[j] = '\0' ;
					digicount = 0 ;
					j = 0 ;
					a = get_ordinumber(resultbuffer) ;
					if (strcomp(lastword,"den") == 0 ||
						 strcomp(lastword,"am") == 0 ||
						 strcomp(lastword,"vom") == 0 ||
						 strcomp(lastword,"zum") == 0 ||
						 strcomp(lastword,"dem") == 0 ||
						 strcomp(lastword,"Den") == 0 ||
						 strcomp(lastword,"Am") == 0 ||
						 strcomp(lastword,"Vom") == 0 ||
						 strcomp(lastword,"Zum") == 0 ||
						 strcomp(lastword,"Dem") == 0 || dativ) {
						dativ++ ;
						strcat(a,"n") ;
						lastpoint = lastcomma = 0 ; }
					if (lastpoint == 1) {
						lastpoint = lastcomma = 0 ;
						if (is_whitespace(buffer[i+1]))
							strcat(a,"ns . ") ;
						else
							fprintf(result,"der ") ; }
					else
						if (lastcomma == 1) {
							fprintf(result,"den ") ;
							dativ++ ;
							strcat(a,"n") ; }
					if (a != NULL) {
						fprintf(result,"%s ",a) ;
						CLEAR(a); }
					continue ; }
*/
				if (buffer[i+1] == '.' && strchr(" \n\t\0",buffer[i+2]) != NULL) {
					resultbuffer[j++] = buffer[++i] ;
					resultbuffer[j] = '\0' ;
					digicount = 0 ;
					j = 0 ;
					a = get_ordinumber(resultbuffer) ;
					if (a != NULL) {
						fprintf(result,"%s ",a) ;
						CLEAR(a); }
					continue ; }
#endif
				if (strchr(",:.",buffer[i+1]) != NULL) {
					if (strchr(digits,buffer[i+2]) == NULL)
						continue ;
/*					if (is_whitespace(buffer[i+2])) {
						resultbuffer[j] = '\0' ;
						digicount = 0 ;
						j = 0 ;
						a = isnumber(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s ",a) ;
							CLEAR(a); }
						continue ; }
					if (buffer[i+2] == '-') {
						resultbuffer[j] = '\0' ;
						digicount = 0 ;
						j = 0 ;
						a = isnumber(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s ",a) ;
							CLEAR(a); }
						i += 2 ;
						continue ; }
*/					resultbuffer[j++] = buffer[++i] ;
					continue ; }
				if (isalpha(buffer[i+1]) || strchr("ﬂƒ‹÷‰¸ˆ",buffer[i+1]) != NULL) {
					resultbuffer[j] = '\0' ;
					digicount = 0 ;
					j = 0 ;
					a = isnumber(resultbuffer) ;

if (debuglevel > 1) {
					fprintf(errfile,"Number found\n") ;
					fflush(errfile) ;
}

					if (a != NULL) {
						fprintf(result,"%s ",a) ;
						fflush(result) ;
						CLEAR(a); }
					continue ; }
				if (is_whitespace(buffer[i+1])) {
					resultbuffer[j] = '\0' ;
					digicount = 0 ;
					j = 0 ;
					a = isnumber(resultbuffer) ;
					if (a != NULL) {
						fprintf(result,"%s ",a) ;
						CLEAR(a); }
					continue ; } }
			dativ = 0 ;
			if (strchr(symbole,buffer[i]) != NULL) {
				read++ ;
				lastpoint = 0 ;
				if (j > 0) {
					resultbuffer[j] = '\0' ;
					if (digicount > 0) {
						digicount = 0 ;
						a = isnumber(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s ",a) ;
							CLEAR(a); } }
					else {
						a = iseinh(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s ",a) ;
							CLEAR(a);
							j = 0 ;
							continue ; }
						if (resultbuffer[j-1]=='.') {
							a = isabkz(resultbuffer) ;
							if (a != NULL) {
								fprintf(result,"%s ",a) ;
								CLEAR(a);
								j = 0 ;
								continue ; } }
						fprintf(result,"%s ",resultbuffer) ; }

					j = 0 ; }
				a = issymb(buffer[i]) ;
				if (a != NULL) {
#ifdef COMPLETE_VV
					if (!(buffer[i] == '-' && strchr(digits,buffer[i+1]) == NULL && strchr(symbole,buffer[i+1]) == NULL))
						fprintf(result,"%s ",a) ;
#else
					if (buffer[i] != '-' || lastdigit > 0 || lastsymb > 0 || i == 0)
						fprintf(result,"%s ",a) ;
#endif
					CLEAR(a); }
				lastsymb=1 ;
				lastdigit = 0 ;
				digicount = 0 ;
				continue ; }
			if (strchr(alphas,buffer[i]) != NULL) {
				read++ ;
				resultbuffer[j++] = buffer[i] ;
				lastsymb=lastpoint = lastspace = lastcomma = lastdigit = 0 ; }
			if (is_whitespace(buffer[i]))
				if (lastspace == 0) {
					digicount = 0 ;
					lastsymb=lastpoint = lastspace = lastcomma = lastdigit = 0 ;
					lastspace = 1 ;
					resultbuffer[j++] = '\0' ;
					if (digicount > 0) {
						digicount = 0 ;
						a = isnumber(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s ",a) ;
							CLEAR(a); } }
					else {
						resultbuffer[j-1] = '\0' ;
						a = iseinh(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s ",a) ;
							CLEAR(a);
							j = 0 ;
							continue ; }
						fprintf(result,"%s ",resultbuffer) ; }
					strcpy(lastword,resultbuffer) ;
					j = 0 ; }
				else {
					lastspace++ ;
//					if (lastspace == 3 && lastcomma == 0)
//						fprintf(result," . ") ;
						}
			if (strchr(".,?!;:",buffer[i]) != NULL) {

			  if (debuglevel > 7) {
			    fprintf(errfile,"Point found\n") ;
			    fflush(errfile) ; }

			  if (lastpoint != 0 || lastcomma != 0)
			    continue ;

			  if (debuglevel > 7) {
			    fprintf(errfile,"Assigning point\n") ;
			    fflush(errfile) ; }

				switch (buffer[i]) {
					case '.' : satzzeichen = (char*)"; Punkt## " ; break ;
					case ',' : satzzeichen = (char*)"; Komma## " ; break ;
					case '?' : satzzeichen = (char*)"; Fragezeichen## " ; break ;
					case '!' : satzzeichen = (char*)"; Ausrufezeichen## " ; break ;
					case ';' : satzzeichen = (char*)"; Semikolon## " ; break ;
					case ':' : satzzeichen = (char*)"; Doppelpunkt## " ; break ; }
				switch (buffer[i]) {
					case ':':
						buffer[i] = ';' ;
						break ;
					case ',':
						buffer[i] = ';' ;
						break ;
					case ';':
						buffer[i] = '.' ;
						break ; }
				if (buffer[i] == '.' && (strchr(symbole,buffer[i+1]) != NULL || strchr(alphas,buffer[i+1]) != NULL || strchr(digits,buffer[i+1]) != NULL)) {
					resultbuffer[j++] = '.' ;
					resultbuffer[j] = '\0' ;
					a = isabkz(resultbuffer) ;
					if (a != NULL) {
						fprintf(result,"%s",a) ;
						CLEAR(a);
						j = 0 ;
						continue ; }
					resultbuffer[--j] = '\0' ; }
				if (buffer[i] == '.' && lastspace == 0 && is_whitespace(buffer[i+1])) {
					if (j > 2 && strncmp(&resultbuffer[j-3],"str",3) == 0) {
						resultbuffer[j++] = 'a' ;
						resultbuffer[j++] = 'ﬂ' ;
						resultbuffer[j++] = 'e' ;
						resultbuffer[j++] = ' ' ;
						resultbuffer[j] = '\0' ;
						fprintf(result,"%s ",resultbuffer) ;
						j = 0 ;
						continue ; }
					resultbuffer[j++] = '.' ;
					resultbuffer[j] = '\0' ;
					a = isabkz(resultbuffer) ;
					if (a != NULL) {
						fprintf(result,"%s",a) ;
						CLEAR(a);
						j = 0 ;
						continue ; }
					resultbuffer[j-1] = '\0' ;
					k = i+1 ;
					while (buffer[k] != '\0') {
						if (!is_whitespace(buffer[k]))
							break ;
						k++ ; }
					if (!is_whitespace(buffer[k]) && strchr("abcdefghijklmnopqrstuvwxyz‰¸ˆﬂ-;:$%&/=?+*<>1234567890",buffer[k]) != NULL) {
						satzzeichen = (char*)"" ;
						lastpoint = 0 ;
						point = (char*)"" ; }
					else {
						lastpoint = 1 ; }
						point = (char*)"." ;
					if (digicount > 0) {
						digicount = 0 ;
						a = isnumber(resultbuffer) ;
						if (a != NULL) {
							fprintf(result,"%s Punkt ",a) ;
							lastpoint = 0 ;
							CLEAR(a); } }
					else
						fprintf(result,"%s %s %s ",resultbuffer,satzzeichen,point) ;
					j = 0 ;
					continue ; }
/*				if (buffer[i] == '.' && lastspace == 0 && !(is_whitespace(buffer[i+1]) || buffer[i+1]=='.')) {
					resultbuffer[j++] = '.' ;
					resultbuffer[j++] = ' ' ;
					continue ; }

		Die obigen Zeilen muessen u.U. wieder rein.
		Rausgenommen fuer Gefec, 26.4.1996


*/				resultbuffer[j] = '\0' ;
				if (digicount > 0) {
					digicount = 0 ;
					a = isnumber(resultbuffer) ;
					if (a != NULL) {
						if (buffer[i] != '.') {
							fprintf(result,"%s %s %c ",a,satzzeichen,buffer[i]) ;
							lastpoint = 1 ; }
						else {
							lastpoint = 0 ;
							fprintf(result,"%s Punkt ",a) ; }
						CLEAR(a); } }
				else {
				fprintf(result,"%s %s %c ",resultbuffer,satzzeichen,buffer[i]) ;
					if (buffer[i] == '.')
						lastpoint = 1 ; }
				if (buffer[i] == ',')
					lastcomma = 1 ;
				j = 0 ; } }

// Kurze Zeilenerkerkennung
		if (strlen(buffer) < 0 && lastcomma == 0) {
			resultbuffer[j] = '\0' ;
			if (lastspace == 0) {
				lastspace = 1 ;
				fprintf(result," ") ; }
			if (lastpoint == 0 || digicount > 0) {
				lastpoint = 1 ;
				if (digicount > 0) {
					digicount = 0 ;
					a = isnumber(resultbuffer) ;
					if (a != NULL) {
						fprintf(result,"%s . ",a) ;
						CLEAR(a); } }
					else
						fprintf(result,"%s . ",resultbuffer) ; } }


	if (piping && read == 0)
		goto startpoint ;


	if (piping)
	  break ;


		}

	  if (piping && feof(in)){
	    stop = 1 ; } 





	resultbuffer[j] = '\0' ;

	if (lastspace == 0)
		fprintf(result," ") ;
	if (lastpoint == 0 || digicount > 0) {
		if (digicount > 0) {
			digicount = 0 ;
			a = isnumber(resultbuffer) ;
			if (a != NULL) {
				fprintf(result,"%s . ",a) ;
				CLEAR(a); } }
			else
				fprintf(result,"%s . ",resultbuffer) ; }

	if (in != NULL)
#ifdef UNIX
	  if(in != stdin)
#endif
		fclose(in) ;
	delete[](buffer) ;
	if (read == 0) {
		fclose(result) ;
		return(NULL) ; }
	return(result) ; }






