
#if !defined(FLEXION_HEADER)
#define FLEXION_HEADER

using namespace std ;

#include <assert.h>
#ifdef Windows
#include <cstring.h>
#else
#include <string>
#endif

#ifndef _Windows
#define _USERENTRY
#endif


#include "ascii.h"
#include "file.h"
#include "wrdclass.h"


////////////////////////////////////////////////////////////////////////////////////////

class TFlexion
{
  string tok1, tok2, tok3, tok4, tok5, tok6;
	public:
		struct TRule
		{
				string orth_flex;
				string orth_base;
				string phon_base;
				string phon_flex;
				bool may_umlaut;
				TWordClass promote_from;
				TWordClass promote_to;

			public:
				TRule ()
					{  }
				TRule (const TRule &rule)
					{  init(rule);  }
				// Initialisierung mit sieben Strings
				TRule (const string &of, const string &ob, const string &pb, const string &pf, const string &mu, TWordClass p_f, const string &p_t);
				// Initialisierung mit einem Speicherbereich
				TRule (const char *&mem);

				~TRule ();

				TRule &operator= (const TRule &rule)
					{  init(rule);  return *this;  }

				static int _USERENTRY compare (const void *cvpa, const void *cvpb);
				static int _USERENTRY compare_ptr (const void *cvpa, const void *cvpb);

			protected:
				void init (const TRule &rule);
		};

	private:
		TRule *rules;
		short *idx_rules;
		short *cnt_rules;
		short cnt_lines;

		int GetLine (const TFile &sourcefile, string &s1, string &s2, string &s3, string &s4, string &s5, string &s6);
		bool Compile (const TFile &sourcefile, TFile &binaryfile);
		bool Load (const TFile &binaryfile);

	public:
		TFlexion (const string &datapath, const string &basename);
		virtual ~TFlexion ();

		inline short Entries (char ch) const;
		inline const TRule &operator() (char ch, short index) const;
};


////////////////////////////////////////////////////////////////////////////////////////

inline short TFlexion::Entries (char ch) const
{
	if ((ch >= 'a' && ch <= 'z') || ch == asc_sz_lig)
		return cnt_rules[(ch != asc_sz_lig) ? ch - 'a' + 1 : 0];
	else
    	return 0;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TFlexion::TRule &TFlexion::operator() (char ch, short i) const
{
	assert(i < Entries(ch) && ((ch >= 'a' && ch <= 'z') || ch == asc_sz_lig));

	return rules[idx_rules[(ch != asc_sz_lig) ? ch - 'a' + 1 : 0] + i];
}


string reverse (const string &s);


#endif

