#if !defined(__SYNTHESE_H__)
#define __SYNTHESE_H__

#include "lisatalk.h"

#ifndef _MAX_PATH
#define _MAX_PATH 256
#endif

#if !defined(__ENVIRON_H__)
#include "environ.h"
#endif

#if !defined(__HPOSTTRA_H__)
#include "hposttra.h"
#endif


#if !defined(__LEXICON_H__)
#include "lexicon.h"
#endif

#if !defined(__PROSODY_H__)
#include "prosody.h"
#endif

#if !defined(__PROSTREE_H__)
#include "prostree.h"
#endif

#if !defined(__VV_H__)
#include "vv.h"
#endif

#if !defined(__NN_H__)
#include "nn.h"
#endif
#if !defined(__PHDURNN_H__)
#include "phdurnn.h"
#endif


typedef int (*fprt) () ;
typedef int (*nefu) (float*,float*,int) ;

class Synthese {


   char ppfilnam[_MAX_PATH] ;
   int ppindex ;
	char lexemfilnam[_MAX_PATH] ;
	char szProgramPath[_MAX_PATH];
	TLexicon *lexicon;
	char* infi ;
	Duration_Model* d ;
	Intonation_Model* i ;
	Intensity_Control* a ;
	NNProsody* n ;
	Baum* b ;
	FILE* f0fil;
	Netz* durnet ;
	Netz* intnet ;
	PhonNetz* phondurnet ;
	Environment* env ;
	Environment* rcenv ;
	int def_use_net ;
	int use_wagonprom ;
	VV* vvv ;
	int reduction_level ;
	char* inventname ;
	char* inventpath ;
	float defaultspeechrate ;
	int interpunction ;
	int dares ;
	int mulaw ;
	char treename[128] ;
   char tbuffer[256] ;
   int bwl ;

	char pid[80] ;
   char temppath[256] ;
       int language ;
       int piping ;
       int nopreproc ;
       int search_exactly ;
       int skip_it ;
       int alles_gelesen ;
       int talknow ;



public:



	Synthese(char* __hWnd, char* path, char* temppath, int dl = -1, int pip=0) ;
	~Synthese() ;

	int stop ;
	int finish ;

	int  change_voice(char* path, const char* name) ;
	int  talk(const char* filename, int modus, const char* resultfilename) ; } ;


#endif

