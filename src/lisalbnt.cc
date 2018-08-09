
#include "synthese.h"

//char szProgramPath[_MAX_PATH] ;
Synthese** ssynthi ;
static int number_of_processes = 0 ;
//FILE* logfile;

bool WINAPI DllEntryPoint(HINSTANCE* hinstDll, DWORD fdwReason, LPVOID lpvReserved) {
	ssynthi = (Synthese**)malloc(1) ;
   return(1) ; }

int _stdcall _export LisaInit(char* path) {
	number_of_processes++ ;
   ssynthi = (Synthese**)realloc(ssynthi,sizeof(Synthese*)*number_of_processes) ;
	ssynthi[number_of_processes-1] = new Synthese(NULL,path,0,1) ;
	if (ssynthi[number_of_processes-1] == NULL) {
		return(-1) ; }
  return(number_of_processes-1) ; }

void _stdcall _export Lisa_waehle_stimme(char *filename, char *path, int p=0) {
	if (ssynthi[p] != NULL)
	  ssynthi[p]->change_voice(path,filename) ;
}

void _stdcall _export Lisa_lies_schneller(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->change_speechrate(ssynthi[p]->get_speechrate()-0.2) ;
}

void _stdcall _export Lisa_lies_langsamer(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->change_speechrate(ssynthi[p]->get_speechrate()+0.2) ;
}

void _stdcall _export Lisa_lies_lebhafter(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->change_pitchrange(ssynthi[p]->get_pitchrange()+20) ;
}

void _stdcall _export Lisa_lies_monotoner(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->change_pitchrange(ssynthi[p]->get_pitchrange()-20) ;
}

void _stdcall _export Lisa_setze_startwerte(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->change_voice("",ssynthi[p]->get_invent()) ;
}

void _stdcall _export Lisa_satzzeichen_ein(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->set_interpunction(1) ;
}

void _stdcall _export Lisa_satzzeichen_aus(int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->set_interpunction(0) ;
}

int _stdcall _export Lisa_vorverarbeitung(char* inname, char* outname, int p=0) {
	if (ssynthi[p] != NULL)
	ssynthi[p]->preprocess(inname,outname) ;
}

int _stdcall _export Lisa_loesche_wortliste(int number, char** wordlist) {
	for (int i=0 ; i < number ; i++) {
   	delete(wordlist[i]) ; }
   delete(wordlist) ;
   return(0) ; }

int _stdcall _export Lisa_lies_satz(char* string, char* resultfilename, long* wpl = NULL, int preproc = 0,  int (*Call)() = NULL, int* wordnr = NULL ,char*** wordlist = NULL, int p=0) {
   int result = -1 ;
	if (ssynthi[p] != NULL) {
//   	printf("Hallo %d\n",p) ;
		if ((result = ssynthi[p]->talk(string,10,resultfilename, preproc, Call, wordnr,wordlist))== -1)
			return(result) ;
		ssynthi[p]->get_word_position_list(wpl) ;
	 }
	return(result) ; }

void _stdcall _export Lisa_nehme_in_abkuerzungsliste_auf(char* abkuerzung, char* text, int p=0) {
	if (ssynthi[p] != NULL)
		ssynthi[p]->add_abbreviation(abkuerzung,text) ;
}


void _stdcall _export Lisa_stop(int p=0) {
	if (ssynthi[p] != NULL)
		ssynthi[p]->finish = 1 ;
}


int _stdcall _export LisaClose(int p=0) {
//   number_of_processes-- ;
//   if (number_of_processes < 1) {
//   	number_of_processes = 0 ;
		if (ssynthi[p] != NULL) {
			delete(ssynthi[p]) ;
         ssynthi[p] = NULL ; }
	return(p) ; }
