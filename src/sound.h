/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined(__SOUND_H__)
#define __SOUND_H__

#if !defined(__LIST_H__)
#include "list.h"
#endif

typedef struct {
	char name[8] ;
	int duration ;
	int intensity ;
	int accent ;
	int f0nr ;
	float f0pos[30] ;
	float f0[30] ; } Soundinfo ;

class Soundlist: public List<Soundinfo> {

  long actdur ;

	public:
		Soundlist() ;
		~Soundlist() ;

		Soundinfo get_last_sound() ;
		Soundinfo* get_sound_pointer(int indexnr) ;
		int conc(Soundinfo i) ;

		void clear_doubles() ;
		void clear_zero_dur() ;
		void print(FILE* ascoutfil) ;
		void printf0(FILE* ascoutfil) ;
		void printmbrola(FILE* ascoutfil, char* impbuffer = NULL) ;
		void input_prosody(FILE* ascinfil) ;
		void input(FILE* ascinfil) ; } ;

#endif

