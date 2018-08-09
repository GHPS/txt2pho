/*
		HADIFIX - Funktionen in hadilib.lib

		(c) 22.4.1996 Thomas Portele
*/



//		HadiInit() initializes the Synthesis Module
//			returns 1 for success, 0 for failure

extern int HadiInit() ;



//		HadiClose() deletes the Synthesis Module
//			returns 1

extern int HadiClose() ;


//		HadiNewVoice(filename, path) chooses a new voice
//			The voice files are supposed to be in the
//			directory "path" and have names "filename"

extern void HadiNewVoice(char * far filename, char * far path) ;


//		HadiChangeAbbList(filename) loads a new abbreviation list
//			named "filename"
//			The list is supposed to contain abbreviations
//			terminated by a .
//			returns 1 for success, -1 for failure

extern int HadiChangeAbbList(char * far filename) ;


//		HadiChangeSIAbbList(filename) loads a new abbreviation list
//			named "filename"
//			The list is supposed to contain those abbreviations
//			not terminated by a .  e.g. SI units
//			returns 1 for success, -1 for failure

extern int HadiChangeSIAbbList(char * far filename) ;


//		HadiNewSpeechRate(rate) changes the speech rate
//			valid values are between 0.5 and 2.5

extern void HadiNewSpeechRate(float rate) ;


//		HadiNewPitch(value) changes F0
// 		valid values are between 70 and 400 (Hz)

extern void HadiNewPitch(float value) ;


//		HadiSynthesize(resultfilename,filename) synthesizes
//			the text in the file named "filename" and
//			generates a wav file named "resultfilename"
//			if "resultfilename" is NULL no file is generated
//			and the sound is played using Windows sound devices
// 		returns 0 in case of success, 1 in case of an error
//			Call ist the address of a function that is called
//			periodically during synthesis in order to react
//			on user input
//

extern int HadiSynthesize(char * far resultfilename,char * far filename, int (*Call)() = NULL  ) ;
extern int HadiSynthesizeBrutal(char * far resultfilename,char * far filename) ;


//		HadiSynthString(resultfilename,string) synthesizes
//			the contents of "string" and
//			generates a wav file named "resultfilename"
//			if "resultfilename" is NULL no file is generated
//			and the sound is played using Windows sound devices
// 		returns 0 in case of success, 1 in case of an error
//			Call ist the address of a function that is called
//			periodically during synthesis in order to react
//			on user input

extern int HadiSynthString(char *  far resultfilename,char* far string, int (*Call)() = NULL) ;


