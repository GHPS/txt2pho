/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined(LEXEM_HEADER)
#define LEXEM_HEADER


#include <assert.h>
#include <stdio.h>



#include "file.h"
#include "flexion.h"
#include "wrdclass.h"


////////////////////////////////////////////////////////////////////////////////////////

class TLexem
{
	public:
		typedef enum 
		{
			comma, point, colon, semicolon, exclamation, question, dash, wordform,
			comment, control, nothing
		} TType;

	protected:
		string chars;
		string transcription;
		string lemma;
		TWordClass *wordClasses;
		short cntWordClasses;
		TType type;

		void setType ();

	public:

		string flexrul;

		TLexem ();
		TLexem (const string &str);
		TLexem (const TLexem &lexem) :
			wordClasses(NULL),
			cntWordClasses(0)
		{  init(lexem);  }

		virtual ~TLexem ();

		TLexem &operator= (const TLexem &lexem)
		{  init(lexem);  return *this;  }

		TLexem &operator+= (const TLexem &lexem);

		bool starts_with_one_of (const string &charset) const;
		bool contains_only (const string &charset) const;
		bool is_valid_word () const;
		bool has_word_class (TWordClass wcl) const;
		bool has_ending (const TFlexion::TRule &rule) const;

		// Erlaube (kontrollierten) Schreibzugriff auf private Datenelemente

		inline void SetChars (const string &s);
		inline void SetChars (size_t n, const string &s);
		inline void SetChars (size_t n, char c);
		inline void SetTranscription (const string &s);
		inline void SetTranscription (size_t n, const string &s);
		inline void SetLemma (const string &s);
		int EmailChange() ;
		int SetUmlaut (int email) ;
      void SetUmlautPhon () ;
		void SetWordClass (TWordClass wcl);
		void SetWordClasses (short cnt_wcls, const TWordClass *wcls);

		// Erlaube Lesezugriff auf private Datenelemente

		inline string Chars () const;
		inline char Chars (size_t pos) const;
		inline string Chars (size_t start, size_t len) const;
		inline string Transcription () const;
		inline char Transcription (size_t pos) const;
		inline string Transcription (size_t start, size_t len) const;
		inline string Lemma () const;
		inline char Lemma (size_t pos) const;
		inline string Lemma (size_t start, size_t len) const;
		inline const TWordClass *WordClasses () const;
		inline short WordClassesCount () const;
		inline TType Type () const;

	protected:
		void init (const TLexem &l);

	friend class TLexicon;
	friend class Synthese;
	friend int kanzler (TLexem &lexem);
	friend int rheinisch (TLexem &lexem);

	friend TLexem operator+ (const TLexem &l1, const TLexem &l2);
	friend int operator== (const TLexem &l1, const TLexem &l2);
};


////////////////////////////////////////////////////////////////////////////////////////

istream &operator>> (istream &is, TLexem &lexem);
ostream &operator<< (ostream &os, const TLexem &lexem);
void fread_lexem (FILE *infile, TLexem &lexem);
void fwrite_lexem (FILE *outfile, const TLexem &lexem);
void put_lexem (char** lexlist, int lexnr, const TLexem &lexem) ;

////////////////////////////////////////////////////////////////////////////////////////

inline void TLexem::SetChars (const string &s)
{
	chars = s;
	setType();
}


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexem::SetChars (size_t n, const string &s)
{
	assert(n <= chars.length());

	chars.replace(n, chars.length() - n, s);
	setType();
}


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexem::SetChars (size_t n, char c)
{
	assert(n <= chars.length());

	chars.replace(n, chars.length() - n, &c);
	setType();
}


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexem::SetLemma (const string &s)
{
	lemma = s;
}


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexem::SetTranscription (const string &s)
{
	transcription = s;
}


////////////////////////////////////////////////////////////////////////////////////////

inline void TLexem::SetTranscription (size_t n, const string &s)
{
	assert(n <= transcription.length());

	transcription.replace(n, transcription.length() - n, s);
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TLexem::Chars () const
{
	return chars;
}


////////////////////////////////////////////////////////////////////////////////////////

inline char TLexem::Chars (size_t pos) const
{
	return chars[pos];
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TLexem::Chars (size_t start, size_t len) const
{
	return chars.substr(start, len);
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TLexem::Transcription () const
{
	return transcription;
}


////////////////////////////////////////////////////////////////////////////////////////

inline char TLexem::Transcription (size_t pos) const
{
	return transcription[pos];
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TLexem::Transcription (size_t start, size_t len) const
{
	return transcription.substr(start, len);
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TLexem::Lemma () const
{
	return lemma;
}


////////////////////////////////////////////////////////////////////////////////////////

inline char TLexem::Lemma (size_t pos) const
{
	return lemma[pos];
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TLexem::Lemma (size_t start, size_t len) const
{
	return lemma.substr(start, len);
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TWordClass *TLexem::WordClasses () const
{
	return wordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////

inline short TLexem::WordClassesCount () const
{
	return cntWordClasses;
}


////////////////////////////////////////////////////////////////////////////////////////

inline TLexem::TType TLexem::Type () const
{
	return type;
}


#endif


