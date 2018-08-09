/*
		LISA - Funktionen in hadilib.lib

		(c) 22.4.1996 Thomas Portele*/



//		LisaInit() initializes the Synthesis Module
//			returns index of instance, -1 for failure
//			The index must be supplied in subsequent
//			calls to other functions as parameter p

extern int _stdcall _import LisaInit(char* path) ;



//		LisaClose() deletes the Synthesis Module
//			returns 1

extern int _stdcall _import LisaClose(int p=0) ;


//		Lisa_waehle_stimme(filename, path) chooses a new voice
//			The voice files are supposed to be in the
//			directory "path" and have names "filename"
//			"path" must be finished by '\'

extern void _stdcall _import Lisa_waehle_stimme(char * far filename, char * far path, int p=0) ;


//		Lisa_lies_schneller() and Lisa_lies_langsamer change the speech rate

extern void _stdcall _import Lisa_lies_schneller(int p=0) ;
extern void _stdcall _import Lisa_lies_langsamer(int p=0) ;


//		Lisa_lies_lebhafter() and Lisa_lies_monotoner() change F0 range

extern void _stdcall _import Lisa_lies_lebhafter(int p=0) ;
extern void _stdcall _import Lisa_lies_monotoner(int p=0) ;


//		Lisa_vorverarbeitung(char* inname, char* outname)
//			reads a file named inname, works on numbers,
//			abbreviations etc, divides it up into sentences
//			and writes the result in file named outname

extern void _stdcall _import Lisa_vorverarbeitung(char* inname, char* outname, int p=0) ;


//		Lisa_setze_startwerte() reinitializes the synthesis

extern void _stdcall _import Lisa_setze_startwerte(int p=0) ;

//		Lisa_satzzeichen_ein() enables reading of
// 		punctuation marks, Lisa_satzzeichen_aus() disables this feature

extern void _stdcall _import Lisa_satzzeichen_ein(int p=0) ;
extern void _stdcall _import Lisa_satzzeichen_aus(int p=0) ;

//		Lisa_lies_satz(resultfilename,string) synthesizes
//			the contents of "string" and
//			generates a wav file named "resultfilename"
//			if "resultfilename" is NULL no file is generated
//			and the sound is played using Windows sound devices
//			Call is the address of a function that is called
//			periodically during synthesis in order to react
//			on user input
//			if the input is already preprocessed, preproc must be 1,
//			otherwise 0
// 		if wpl == NULL nothing happens, otherwise it is
//			filled with a list of milliseconds denoting the beginning
//			of the input words, it MUST be long enough
//			the first value of the list gives the number of
//			list elements (add 1 to get the length of the
//			allocated long values)
//			the list must be deleted by the calling function
//			wordnr and wordlist should NOT be used in this version

extern int _stdcall _import Lisa_lies_satz(char *  far resultfilename,char* far string,long* wpl = NULL, int preproc = 0, int (*Call)() = NULL,  int* wordnr = NULL ,char*** wordlist = NULL, int p = 0) ;


extern int _stdcall _import Lisa_loesche_wortliste(int number, char** wordlist) ;
