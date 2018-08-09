#include <assert.h>

#include "newtable.h"
#include "ascii.h"
#include "code.h"
#include "debug.h"
#include "string.h"

static string convert_string (const string &source, bool remap_case, bool remap_chars)
{
	size_t i = 0;
	string result;

	if (remap_case)
	{
		if (remap_chars)
		{
			for (i = 0; i < source.length(); i++)
			{
				result += upper_char(remap_char(source[i]));
				switch (source[i])
				{
					case asc_a_umlaut: case asc_A_umlaut:
					case asc_o_umlaut: case asc_O_umlaut:
					case asc_u_umlaut: case asc_U_umlaut:
						result += 'E';
						break;
					case asc_sz_lig:
						result += 'S';
						break;
				}
			}
		}
		else
		{
			for (i = 0; i < source.length(); i++)
			{
				result += upper_char(source[i]);
//				if (source[i] == asc_sz_lig)
//					result += 'S';
			}
		}
	}
	else
	{
		if (remap_chars)
		{
			for (i = 0; i < source.length(); i++)
			{
				result += remap_char(source[i]);
				switch (source[i])
				{
					case asc_a_umlaut: case asc_A_umlaut:
					case asc_o_umlaut: case asc_O_umlaut:
					case asc_u_umlaut: case asc_U_umlaut:
						result += 'e';
						break;
					case asc_sz_lig:
						result += 's';
						break;
				}
			}
		}
		else
		{
			result = source;
		}
	}
	return result;
}



int convert_chars (char* source, char* result, bool remap_case, bool remap_chars)
{
	size_t i = 0;
	int j = 0 ;
	if (remap_case)
	{
		if (remap_chars)
		{
			for (i = 0; i < strlen(source); i++)
			{
				result[j++] = upper_char(remap_char(source[i]));
				switch (source[i])
				{
					case asc_a_umlaut: case asc_A_umlaut:
					case asc_o_umlaut: case asc_O_umlaut:
					case asc_u_umlaut: case asc_U_umlaut:
						result[j++] = 'E';
						break;
					case asc_sz_lig:
						result[j++] = 'S';
						break;
				}
			}
			result[j] = '\0' ;
		}
		else
		{
			for (i = 0; i < strlen(source); i++)
			{
				result[j++] = upper_char(source[i]);
//				if (source[i] == asc_sz_lig)
//					result[j++] = 'S';
			}
			result[j] = '\0' ;
		}
	}
	else
	{
		if (remap_chars)
		{
			for (i = 0; i < strlen(source); i++)
			{
				result[j++] = remap_char(source[i]);
				switch (source[i])
				{
					case asc_a_umlaut: case asc_A_umlaut:
					case asc_o_umlaut: case asc_O_umlaut:
					case asc_u_umlaut: case asc_U_umlaut:
						result[j++] = 'e';
						break;
					case asc_sz_lig:
						result[j++] = 's';
						break;
				}
			}
                        result[j] = '\0' ;
		}
		else
		{
			strcpy(result,source) ;
		}
	}
	return 1 ;
}

Newtable::TRecord::TRecord () :
	wordClasses(NULL),
	cntWordClasses(0)
{
}


////////////////////////////////////////////////////////////////////////////////////////

// !!! ACHTUNG !!!  Ver?ndert ªmema!

Newtable::TRecord::TRecord (char *&mem) :
	wordClasses(NULL),
	cntWordClasses(0)
{
	while (is_whitespace(*mem))
		*mem++ = '\0';
	char *ptr_lemma = mem;
	while (!is_whitespace(*mem))
		mem++;

	while (is_whitespace(*mem))
		*mem++ = '\0';
	char *ptr_wcl_string = mem;
	while (!is_whitespace(*mem))
		mem++;

	while (is_whitespace(*mem))
		*mem++ = '\0';
	char *ptr_transcription = mem;
	while (!is_whitespace(*mem))
		mem++;
	*mem++ = '\0';


	lemma = ptr_lemma;
	LEMMA = convert_string(lemma, true, true);
	transcription = ptr_transcription;

	char *ptr = ptr_wcl_string;

	cntWordClasses = 1;
	while ((ptr = strchr(ptr + 1, ':')) != NULL)
		cntWordClasses++;
	wordClasses = new TWordClass[cntWordClasses];

	ptr = strtok(ptr_wcl_string, ":");
	for (short i = 0; i < cntWordClasses; i++)
	{
		wordClasses[i] = str2wcl(ptr);
		ptr = strtok(NULL, ":");
	}
}


////////////////////////////////////////////////////////////////////////////////////////

Newtable::TRecord::~TRecord ()
{
	delete[] wordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////

bool Newtable::TRecord::has_word_class (TWordClass wcl) const
{
	if ((wcl == Unknown) || (cntWordClasses == 1 && wordClasses[0] == Unknown))
		return true;

	for (short i = 0; i < cntWordClasses; i++)
		if (wordClasses[i] == wcl)
			return true;

	return false;
}


////////////////////////////////////////////////////////////////////////////////////////


void Newtable::TRecord::init (const Newtable::TRecord &rec)
{
	if (this == &rec)
		return;

	delete[] wordClasses;

	lemma = rec.lemma;
	LEMMA = rec.LEMMA;
	transcription = rec.transcription;
	wordClasses = new TWordClass[cntWordClasses = rec.cntWordClasses];
	for (short i = 0; i < cntWordClasses; i++)
		wordClasses[i] = rec.wordClasses[i];
}


Newtable::Newtable(string path, string name) {
	char dummy[1024] ;

	strcat(strcat(strcpy(dummy,path.c_str()),name.c_str()),".sce") ;

	FILE* lexfile = fopen(dummy,"rb") ;

	if (lexfile == NULL) {
	  if (name != "hadibrit") 
		fprintf(errfile,"ERROR: Cannot open lexikon %s\n",dummy) ;
		fflush(errfile) ;
		lexikon = NULL ;
		wordstart = NULL ;
		lexlen = -1 ;
		wordcount = -1 ;
		return ; }

	fseek(lexfile,0L,SEEK_END) ;
	lexlen = ftell(lexfile) ;
	rewind(lexfile) ;

#ifdef Windows
	lexikon = new HugeArray<unsigned char>(lexlen+1L) ;
#else
	lexikon = new unsigned char[lexlen+1] ;
#endif
	if (lexikon == NULL) {
		fprintf(errfile,"ERROR: Cannot read lexikon %s - out of memory\n",dummy) ;
		lexikon = NULL ;
		wordstart = NULL ;
		lexlen = -1 ;
		wordcount = -1 ;
		return ; }

#ifdef Windows
	long i, j ;
#else
	int i,j ;
#endif
	int k = 0 ;
	unsigned char lexbuf[8192] ;

	while ((i = fread(lexbuf,1,8192,lexfile)) == 8192) {
		for (j = 0 ; j < i ; j++) {
			lexbuf[j] = decode(lexbuf[j]) ;
#ifdef Windows
		 } lexikon->Append(lexbuf,8192) ; }
#else
			lexikon[k++] = lexbuf[j] ; } }
#endif
	for (j = 0 ; j < i ; j++) {
		lexbuf[j] = decode(lexbuf[j]) ;
#ifdef Windows
		 } lexikon->Append(lexbuf,i) ;
#else
			lexikon[k++] = lexbuf[j] ; }
#endif
	fclose(lexfile) ;

//   for (i=0 ; i < lexlen ; i++)
//	fprintf(errfile,"%c",(lexikon)[i]) ;

	wordcount = 1 ;
	for (i=0 ; i < lexlen ; i++)
#ifdef Windows
		if ((*lexikon)[i] == (unsigned char)10)
#else
		if (lexikon[i] == (unsigned char) 10)
#endif
		       wordcount++ ;




#ifdef Windows
	wordstart = new HugeArray<long>(wordcount) ;
#else
	wordstart = new long[wordcount] ;
#endif
	if (wordstart == NULL) {
		fprintf(errfile,"ERROR: Cannot read lexikon %s - out of memory\n",dummy) ;
		fflush(errfile) ;
		lexikon = NULL ;
		wordstart = NULL ;
		lexlen = -1 ;
		wordcount = -1 ;
		return ; }

	j = 1 ;
	long zero = 0L ;
	k = 0 ;
#ifdef Windows
	wordstart->Append(&zero,1) ;
#else
	wordstart[k++] = zero ;
#endif
	for (i=0 ; i < lexlen ; i++)
#ifdef Windows
		if ((*lexikon)[i] == (unsigned char)10) {
#else
		if (lexikon[i] == (unsigned char)10) {
#endif
		       zero = i+1 ;
#ifdef Windows
		       wordstart->Append(&zero,1) ; }
#else
			wordstart[k++] = zero ; }
#endif

//   for (i=0 ; i < wordcount ; i++)
//	fprintf(errfile,"%ld ",(wordstart)[i]) ;

	fprintf(errfile,"LEXICON loaded, %ld bytes, %ld words\n",lexlen,wordcount) ;
	fflush(errfile) ;

	return ; }

Newtable::~Newtable() {
	if (lexikon != NULL)
		delete(lexikon) ;
	if (wordstart != NULL)
		delete(wordstart) ; }

int Newtable::lexcomp(char* a, long i, int modus) {
	char lexentry[256] ;
	char LEXENTRY[256] ;
   char Lexentry[256] ;
	int j ;

#ifdef Windows
	long pos = (*wordstart)[i] ;
		for (j = 0 ; (*lexikon)[pos] != '\t' ; pos++)
		lexentry[j++] = (*lexikon)[pos] ;
#else
	long pos = wordstart[i] ;
		for (j = 0 ; lexikon[pos] != '\t' ; pos++)
		lexentry[j++] = lexikon[pos] ;
#endif
	lexentry[j] = '\0' ;
	if (modus == 2) {
//		fprintf(errfile,"Comparing %s with %s from %ld\n",a,lexentry,pos) ;
		fflush(errfile) ;
		return(strcmp(a,lexentry)) ; }
   convert_chars(lexentry,Lexentry,true,false) ;
	convert_chars(lexentry,LEXENTRY,true,true) ;
   if (modus == 0) {
//		fprintf(errfile,"Comparing %s with %s from %ld %ld\n",a,LEXENTRY,pos,i) ;
		return(strcmp(a,LEXENTRY)) ; }
//	fprintf(errfile,"Comparing %s with %s from %ld %ld\n",a,Lexentry,pos,i) ;
	return(strcmp(a,Lexentry)) ; }

long Newtable::binary_Search(char* a, long start, long end) {
	long i = start + (end-start)/2L ;
	int result = lexcomp(a,i,false) ;

//	fprintf(errfile,"Comparison started by BS using %ld between %ld and %ld\n",i,start,end) ;
	fflush(errfile) ;

	if (result == 0)
		return(i) ;
	if (start >= end)
		return(-1L) ;
	if (result < 0)
		return(binary_Search(a,start,i-1)) ;
	else
		return(binary_Search(a,i+1,end)) ; }

long Newtable::Search(string str, int locase) {
//	fprintf(errfile,"Looking for String %s\n",str.c_str()) ;
	if (lexikon == NULL)
		return(-1) ;
	char* s = strdup(str.c_str()) ;
	char* S = new char[strlen(s) * 2 + 4] ;
	char* Ss = new char[strlen(s) * 2 + 4] ;
	convert_chars(s,S,true,true) ;
	convert_chars(s,Ss,true,false) ;
   long firstindex ;

   statistics("LOOKING for " << S << " converted from " << s) ;

	long index = binary_Search(S,0,wordcount-1) ;

	if (index > -1L) {
		// erstes passendes Lemma suchen (Groﬂ-/Kleinschreibung ignorieren)
		while (index > 0L && lexcomp(S,index-1L,0) == 0)
			index--;
      firstindex = index ;
		// wenn Groﬂ-/Kleinschreibung beachtet werden soll und das erste Lemma noch
		// nicht paﬂt
		if (locase && lexcomp(s,index,2) != 0 && index < wordcount-1) {
			do {
			   index++; }
			while (index < wordcount-1 && lexcomp(s,index,2) != 0 && lexcomp(S,index,0) == 0) ;
			if (lexcomp(s,index,2) != 0) {
         	index = firstindex-1 ;
				do {
				   index++; }
				while (index < wordcount-1 && lexcomp(Ss,index,1) != 0 && lexcomp(S,index,0) == 0) ;
				if (lexcomp(Ss,index,1) != 0)
					index = -1 ; } } }

	delete[](s) ;
   delete[](Ss) ;
	delete[](S) ;

        statistics("Result in Lexsearch " << index)  ;
	return(index) ; }

const long Newtable::Entries() const {
return((const long)wordcount-1) ; }

const Newtable::TRecord& Newtable::operator[] (long i)
{
assert(i >= 0 && i < wordcount-1);
char* dummy = new char[1024]  ;

#ifdef Windows
	strncpy(dummy,(char*)&((*lexikon)[(*wordstart)[i]]),1023) ;
#else
	strncpy(dummy,(char*)&(lexikon[wordstart[i]]),1023) ;
#endif
//	fprintf(errfile,"dummy %100s\n",dummy) ;
fflush(errfile) ;
#ifdef _Windows
	TRecord temp((char*)dummy) ;
#else
	TRecord temp((char *&)dummy) ;
#endif

result = temp ;

//delete dummy ;
fprintf(errfile,"NOW HERE\n") ;
	fflush(errfile) ;
	return result;
}















