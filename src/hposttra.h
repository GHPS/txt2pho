/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined(HPOSTTRA_HEADER)
#define HPOSTTRA_HEADER


#include "file.h"
#include "wrdclass.h"
#include "syllable.h"

////////////////////////////////////////////////////////////////////////////////////////

struct Word
{
	char *text;
	char wordclass[3];
	char flag;
	TPhrKons konstit ;
	TSentenceType satztyp ;
	TWordClass wk ;
	int pg_betonung ;
	int betstuf;
	char bettyp;
	int betchg;
};


class Wordlist: public List<Word> {

  int MIN_BORDER ;

	public:
		Wordlist() ;
      Wordlist(char**,int) ;
		Wordlist(TFile& infile) ;
		~Wordlist() ;

		int conc(Word i) ;
		int add_constituent_info(TPhrKons k) ;
		int add_sentence_type(TSentenceType t) ;

		int output(TFile& outfile) ;
		int output(FILE* outfile) ;
		int convert(Syllablelist* s) ;
		Word* get_word_pointer() ;
		int putpros() ;
		int ipa2sampa() ;
		TWordClass get_wordclass(int i, int offset) ;
		TPhrKons get_following_constituents(int i, int offset) ;
		int get_syllable_number_in_constituent(int i) ;
		int get_syllable_number_in_phrase(int i) ;


		void print(FILE* ascoutfil) ; } ;


void prosogen (const TFile &in, TFile &out, int cnt_lexem);
void prosogenx (char** lexlist, Syllablelist* s, int cnt_lexem, FILE* debugfile = NULL) ;
void ipa2sampa (const TFile &in, TFile &out);


#endif

