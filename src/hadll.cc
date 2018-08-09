
#include "synthese.h"

char szProgramPath[_MAX_PATH] ;
Synthese* synthi = NULL ;
static int number_of_processes = 0 ;
FILE* logfile;

bool WINAPI DllEntryPoint(HINSTANCE* hinstDll, DWORD fdwReason, LPVOID lpvReserved) {
   return(1) ; }

int _export HadiClose() {
   number_of_processes-- ;
   if (number_of_processes < 1) {
   	number_of_processes = 0 ;
		if (synthi != NULL) {
			delete(synthi) ;
         synthi = NULL ; } }
	return(1) ; }

int _export HadiInit() {
  int i;
  char *p;
  i = GetModuleFileName(NULL,szProgramPath, sizeof(szProgramPath));
  p = strrchr(szProgramPath, '\\');
  *(p + 1) = '\0';
  strcat(szProgramPath,"data\\") ;
	number_of_processes++ ;
   if (number_of_processes == 1 && synthi == NULL) {
		synthi = new Synthese(NULL,szProgramPath,99) ; }
	if (synthi == NULL) {
		return(0) ; }
  return(1) ;
}


void _export HadiNewVoice(char *filename, char *path) {
	if (synthi != NULL)
	  synthi->change_voice(path,filename) ;

}
int _export HadiChangeAbbList(char *filename) {
	if (synthi != NULL)
	  return(synthi->change_abbreviation_list(filename)) ;

}
int _export HadiChangeSIAbbList(char *filename) {
	if (synthi != NULL)
	  return(synthi->change_SI_abbreviation_list(filename)) ;

}

void _export HadiNewSpeechRate(float rate) {
	if (synthi != NULL)
		synthi->change_speechrate(rate) ;
}

void _export HadiNewPitch(float value) {
	if (synthi != NULL)
		synthi->change_pitch(value) ;
}

int _export HadiSynthesize(char *  resultfilename, char *  filename, int (*Call)() = NULL) {
	if (synthi == NULL)
		return(NULL) ;
	int modus = 0 ;
	if (resultfilename == NULL) {
		resultfilename = "hadi.pip" ;
		modus = 100 ; }
	return(synthi->talk(resultfilename,modus,filename,0,Call)) ; }

int _export HadiSynthesizeBrutal(char *  resultfilename, char *  filename) {
	if (synthi == NULL)
		return(NULL) ;
	int modus = 0 ;
	if (resultfilename == NULL) {
		resultfilename = "hadi.pip" ;
		modus = 100 ; }
	return(synthi->talk(resultfilename,modus,filename,0,NULL)) ; }

int _export HadiSynthString(char *  resultfilename, char*  string, int (*Call)() = NULL) {
	if (synthi == NULL)
		return(NULL) ;
//	return(NULL) ;
//	fprintf(errfile,"\n%s\n",string) ;
	int modus  = 10 ;
	if (resultfilename == NULL) {
	  modus = 110 ;
	  resultfilename = "hadi.pip" ; }
	return(synthi->talk(resultfilename,modus,string,0,Call)) ; }



