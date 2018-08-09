
#include "synthese.h"
#include "windows.h"

char szProgramPath[_MAX_PATH] ;
Synthese* synthi = NULL ;
static int number_of_processes = 0 ;
FILE* logfile;

bool WINAPI DllEntryPoint(HINSTANCE* hinstDll, DWORD fdwReason, LPVOID lpvReserved) {
   return(1) ; }

int _stdcall _export Txt2phoClose() {
   number_of_processes-- ;
   if (number_of_processes < 1) {
   	number_of_processes = 0 ;
		if (synthi != NULL) {
			delete(synthi) ;
         synthi = NULL ; } }
	return(1) ; }

int _stdcall _export Txt2phoInit(char* path, char* voice, int messagebox) {

	if (messagebox != 0)
		if (MessageBox(NULL,"You are using the Dll 'hadidll.dll 0.9.0'. This software is for non-commercial non-military use only. If in doubt, consult the license notes.\nCopyright 1997 by Institut für Kommunikationsforschung und Phonetik, Universität Bonn\n\nDo you agree?","License Agreement.",MB_YESNO | MB_DEFBUTTON2) != IDYES)
   		 return(0) ;

   strcpy(szProgramPath,path) ;
	number_of_processes++ ;
   if (number_of_processes == 1 && synthi == NULL) {
		synthi = new Synthese(NULL,szProgramPath,0,0,1) ;
//      synthi->talk(NULL,10,"Hadifix für M Brola, Version 0.8.0") ;
	 }
	if (synthi == NULL) {
		return(0) ; }
   synthi->change_voice(path,voice) ;
  return(1) ;
}



void _stdcall _export Txt2phoNewSpeechRate(float rate) {
	if (synthi != NULL)
		synthi->change_speechrate(rate) ;
}

void _stdcall _export Txt2phoNewPitch(float value) {
	if (synthi != NULL)
		synthi->change_pitch(value) ;
}

int _stdcall _export Txt2phoRun(char *  resultfilename, char *  filename) {
	if (synthi == NULL)
		return(NULL) ;
	int modus = 8 ;
	return(synthi->talk(resultfilename,modus,filename,0,NULL)) ; }

int _stdcall _export Txt2phoRunStep(char *  resultfilename, char *  filename) {
	if (synthi == NULL)
		return(NULL) ;
	int modus = 18 ;
	return(synthi->talk(resultfilename,modus,filename,0,NULL)) ; }



