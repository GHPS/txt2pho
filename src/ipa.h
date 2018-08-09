using namespace std ;
#if !defined(IPA_HEADER)
#define IPA_HEADER

#ifdef _Windows
#include <cstring.h>
#include <classlib/defs.h>
#else
#include <string>
#endif


////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   A C H T U N G                                    //
//                                  ---------------                                   //
//                                                                                    //
// Diese Datei enthält String- und Character-Konstanten im IPA-Zeichensatz. Sie darf  //
// unter keinesfalls automatisch in einen anderen Zeichensatz konvertiert werden.     //
//                                                                                    //
// Zur Kontrolle: »schwaa = x                                                         //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////


// Definitionen fNr Teilmengen des IPA-Alphabets

extern const string ipa_vowels;
extern const string ipa_consonants;

extern const string ipa_non_syllabic_vowels;

extern const char ipa_schwa[];
extern const char ipa_sylcor[];
extern const char ipa_sylcorstart[];
extern const char ipa_sylcorend[];
extern const char ipa_voicedplos[];
extern const char ipa_sylcons[];
extern const char ipa_beforeborder[];
extern const char ipa_voicedcons[];
extern const char ipa_sonorants[];


// Definitionen für Zeichen aus dem IPA-Alphabet

const char ipa_glottal_stop = '?';
const char ipa_primary_stress = '\'';
const char ipa_secondary_stress = ',';

// Aussprache der Buchstaben des Alphabets

extern const string spelling[29];


//

inline bool is_ipa_vowel (char ch)
{
#ifndef _Windows
	return ipa_vowels.find(ch) != string::npos;
#else
   return ipa_vowels.contains(ch) ? true : false;
#endif
}


inline bool is_ipa_consonant (char ch)
{
#ifndef _Windows
	return ipa_consonants.find(ch) != string::npos;
#else
   return ipa_consonants.contains(ch) ? true : false;
#endif
}


inline bool is_ipa_non_syllabic_vowel (char ch)
{
#ifndef _Windows
	return ipa_non_syllabic_vowels.find(ch) != string::npos;
#else
   return ipa_non_syllabic_vowels.contains(ch) ? true : false;
#endif
}


inline bool is_ipa_stress (char ch)
{
	return ch == ipa_primary_stress || ch == ipa_secondary_stress;
}


#endif

