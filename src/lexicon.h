/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined(LEXICON_HEADER)
#define LEXICON_HEADER


#ifdef Windows
#include <cstring.h>
#else
#include <string>
#endif

#define NEWTABLE

#include "flexion.h"
#include "lexem.h"
#include "lexemnod.h"
#include "ptra.h"
#include "wrdclass.h"
#include "newtable.h"


////////////////////////////////////////////////////////////////////////////////////////


class TLexicon
{
#ifndef NEWTABLE
		TTable table;
#else
		Newtable table ;
		Newtable brittable ;
#endif
		TFlexion flexion;

#if !defined(NPETRA)
		PTRA *ptra;
#endif


		int valid_prefix ;
      int email ;

		bool transcribe_literally (TLexem &lexem, TWordClass wcl = Unknown);
#if !defined(NSPELLING)
		bool transcribe_as_abbreviation (TLexem &lexem);
#endif
		bool transcribe_as_inflected (TLexem &lexem, TWordClass wcl = Unknown);
		bool transcribe_as_compound (TLexemNode* root);
		bool transcribe_as_prefix (TLexem& lexem) ;
#if !defined(NPETRA)
		bool transcribe_with_PTRA(TLexem &lexem) ;
#endif

	public:
		TLexicon (const string &datapath);
		virtual ~TLexicon ();

		void transcribe (TLexem &lexem, int sevenbit = 0);

		inline long Entries () const;
#ifndef NEWTABLE
		inline const TTable::TRecord &operator[] (long i) const;
#else
		inline const Newtable::TRecord &operator[] (long i) ;
#endif
};


inline long TLexicon::Entries () const
{
	return table.Entries();
}


#ifndef NEWTABLE
inline const TTable::TRecord &TLexicon::operator[] (long i) const
#else
inline const Newtable::TRecord &TLexicon::operator[] (long i)
#endif

{
	return table[i];
}


#endif

