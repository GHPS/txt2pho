/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined (PTRA_HEADER)
#define PTRA_HEADER


#ifdef Windows
#include <cstring.h>
#else
#include <string>
#endif



#include "file.h"
#include "list.h"


////////////////////////////////////////////////////////////////////////////////////////

struct Klasse
{
	char members[80];
	char name[10];
};


////////////////////////////////////////////////////////////////////////////////////////

class Klassenliste : public List<Klasse>
{
	public:
		Klassenliste (const TFile &rulefile);
		int ismember (char input, char *name, int modus);
};


////////////////////////////////////////////////////////////////////////////////////////

struct Regel
{
	char *precontext;
	char *suchtext;
	char *postcontext;
	int ucasesuchtext;
	int precontextmodus;
	char *result;

	Regel () :
		precontext(NULL),
		suchtext(NULL),
		postcontext(NULL),
		ucasesuchtext(0),
		precontextmodus(0),
		result(NULL)
		{  }

//	virtual ~Regel ();
};


////////////////////////////////////////////////////////////////////////////////////////

class Regelliste : public List<Regel>
{
                int trace ;
	  
	public:

		Regelliste (char letter, const TFile &rulefil);
		virtual ~Regelliste ();
		int matcher (char *grapheme, int &graphempos, char *phoneme, int &phonempos, Klassenliste* kl);
};


////////////////////////////////////////////////////////////////////////////////////////

class PTRA
{
		Klassenliste *kli;
		Regelliste **rl;
		const char *letters;


	      

	public:
		PTRA (const string &datapath, const string &basename);
		virtual ~PTRA ();
		char* sylborders (char *in, bool gs_insert);
		char* accents (char *in);
		char* transcribe (const char *word);
};


#endif

