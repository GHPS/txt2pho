/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined(__SYLLABLE_H__)
#define __SYLLABLE_H__

#if !defined(__SOUND_H__)
#include "sound.h"
#endif


typedef struct {
	char* name ;
	char* prosinfo ;
	char* type ;
	int firstsound ;
	int soundnr ;
   int wordstart ;
	int accent ; } Syllableinfo ;

class Syllablelist: public List<Syllableinfo> {

	char buffer[256] ;
	Syllableinfo* get_syll_pointer() ;
	char* next_token(FILE*) ;
	int tokenpos ;
		void ex(int i) ;

	public:
		Syllablelist() ;
      Syllablelist(FILE* in) ;
		~Syllablelist() ;

		int conc(Syllableinfo i) ;
		int make_soundlist(Soundlist* s) ;
		int compute_intonation_features() ;
		int distance_to_pgr() ;
      int no_interpunction() ;
		char* new_voice() ;
		void pauses() ;
      int reduce(int level) ;
      char* find_command(const char*) ;
	void wagonprom() ;
	int printmbrola(Soundlist* soli, FILE* outfile, char* impbuffer) ;
	int printkalle(Soundlist* soli, FILE* outfile) ;
	int printretivox(Soundlist* soli, FILE* outfile) ;

		void print(FILE* ascoutfil) ;
		int input(char* ascinfil) ; } ;

#endif

