/*
		Txt2pho - Fuctions in hadidll.dll

		(c) 22.11.1997 Thomas Portele
*/



//		Txt2phoInit() initializes the Synthesis Module
//			returns 1 for success, 0 for failure

extern int _stdcall Txt2phoInit(char* pathtofiles, char* voice, int messagebox) ;



//		Txt2phoClose() deletes the Synthesis Module
//			returns 1

extern int _stdcall Txt2phoClose() ;


//		Txt2phoNewSpeechRate(rate) changes the speech rate
//			valid values are between 0.5 and 2.5

extern void _stdcall Txt2phoNewSpeechRate(float rate) ;


//		Txt2phoNewPitch(value) changes F0
// 		valid values are between 70 and 400 (Hz)

extern void _stdcall Txt2phoNewPitch(float value) ;


//		Txt2phoRun(resultfilename,filename) synthesizes
//			the text in the file named "filename" and
//			generates a pho file named "resultfilename"


extern int _stdcall Txt2phoRun(char *  resultfilename,char * filename) ;


