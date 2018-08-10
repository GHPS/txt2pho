
#if !defined(VV_HEADER)
#define VV_HEADER


#include <stdio.h>
#include <string.h>
#include <fstream>


#include "file.h"


////////////////////////////////////////////////////////////////////////////////////////

class VV
{
		char *abklst;
		int abklstlen;
		char *einlst;
		int einlstlen;
		char *symlst;
		int symlstlen;
		char *numlst;
		int numlstlen;
		char *ordlst;
		int ordlstlen;
		int stop ;
		FILE* in ;

		string abklstname;       // NEU
		string einlstname;       // NEU
		// FILE *eingabe (const char *datapath);  // NEU, aber unbenutzt

		char *isabkz (const char *in);
		char *iseinh (const char *in);
		char *issymb (char in);
		char *get_number (const char *in, int level);
		char *get_ordinumber (const char *in);
		char *isnumber (const char *in);

	public:

		VV (const string &datapath);
		virtual ~VV ();
		bool preprocess (const TFile &infile, TFile &outfile, const string &pid = "");
		FILE *next_input (const string &datapath, const string &filename, int piping, const string &pid = "", const char* lfn = NULL);

		int change_abbreviation_list (const string &filename);
		int change_SI_abbreviation_list (const string &filename);
		int add_abbreviation (const char *abb, const char *text);
};


#endif

