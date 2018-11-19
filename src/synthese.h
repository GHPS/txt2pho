#if !defined(__SYNTHESE_H__)
#define __SYNTHESE_H__

#ifdef __DLL__
#define EXX_EXX_EXX _export
#else
#define EXX_EXX_EXX
#endif

#include "lisatalk.h"

#ifndef _MAX_PATH
#define _MAX_PATH 256
#endif



#if !defined(__DAC_H__)
#include "dac.h"
#endif

#if !defined(__DI_H__)
#include "di.h"
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

#if !defined(__UNIT_H__)
#include "unit.h"
#endif

typedef int (*fprt) () ;
typedef int (*nefu) (float*,float*,int) ;

#ifdef NN

#include "nnetz1.h"

#endif

class EXX_EXX_EXX Synthese {

#ifdef NN
	NeuronalesNetz*  NNetz;
	InputFile*       IFile;
	DataFile*        DFile;
	RecallFile*      RFile;
	char             In_File[255]     ;
	char             Dat_File[255]    ;
	char             Rec_File[255]    ;
#endif

#ifdef _Windows
	HINSTANCE hWnd;
#endif

   char ppfilnam[_MAX_PATH] ;
   int ppindex ;
	char lexemfilnam[_MAX_PATH] ;
	char szProgramPath[_MAX_PATH];
	TLexicon *lexicon;
#ifndef NO_FILES
	Infilehandler* infi ;
#else
	char* infi ;
#endif
	DAC* dac ;
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
#ifdef UNIX
	Environment* rcenv ;
#endif
	Inventory* invent ;
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
	int tx2ph ;
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



#ifdef _Windows
EXX_EXX_EXX	Synthese(HINSTANCE __hWnd, char* path, int db=0, int bw = 0, int txt2pho=0) ;
#else
	Synthese(char* __hWnd, char* path, char* temppath, int dl = -1, int pip=0, int npp=0, int txt2pho = 0) ;
#endif
EXX_EXX_EXX	~Synthese() ;

	int stop ;
	int finish ;

	void EXX_EXX_EXX change_dares(int value) ;
	void EXX_EXX_EXX set_mulaw(int value) ;
	char* EXX_EXX_EXX get_voice() ;
	char* EXX_EXX_EXX get_invent() ;
	float EXX_EXX_EXX get_speechrate() ;
	float EXX_EXX_EXX get_pitch() ;
	int EXX_EXX_EXX change_voice(char* path, const char* name) ;
	float EXX_EXX_EXX get_declination() ;
	int EXX_EXX_EXX change_declination(float value) ;
	int EXX_EXX_EXX change_speechrate(float value) ;
	int EXX_EXX_EXX change_pitch(float value) ;
	int EXX_EXX_EXX change_accentlength(float value) ;
	int EXX_EXX_EXX change_finallengthening(float value) ;
	float EXX_EXX_EXX get_speechraterange() ;
	float EXX_EXX_EXX get_pitchrange() ;
	float EXX_EXX_EXX get_accentlength() ;
	float EXX_EXX_EXX get_finallengthening() ;
	int EXX_EXX_EXX change_speechraterange(float value) ;
	int EXX_EXX_EXX change_pitchrange(float value) ;
	int EXX_EXX_EXX preprocess(char* infilename, char* outfilename) ;
	int EXX_EXX_EXX talk(char* filename, int modus) ;
	int EXX_EXX_EXX set_reduction_level(int value) ;
	int EXX_EXX_EXX add_abbreviation(char* abb, char* text) ;
	int EXX_EXX_EXX change_abbreviation_list(char* filename) ;
	int EXX_EXX_EXX change_SI_abbreviation_list(char* filename) ;
	int EXX_EXX_EXX set_interpunction(int) ;
	long* EXX_EXX_EXX get_word_position_list(long* wpl = NULL) ;
	int EXX_EXX_EXX talk(const char* filename, int modus, const char* resultfilename,  int preproc = 0,int (*Call)() = NULL, int* wordnr = NULL , char*** worlist = NULL, char* rvfilename = NULL) ; } ;


#endif

