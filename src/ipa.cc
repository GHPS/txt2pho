
#include "ipa.h"


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


// Definitionen für Teilmengen des IPA-Alphabets

const string ipa_vowels = "aeiouEIOU29yY@:~<";
const string ipa_consonants = "ptkbdgfsSCxvzZjhrlmnN";

const string ipa_non_syllabic_vowels = "iuo";
const char ipa_schwa[] = "@=6" ;

const char ipa_sylcor[] = "aEOIUIYa:eiouyYI@E=OU92~";
const char ipa_sylcorstart[] = "aEUOaeiouyYI@=92";
const char ipa_sylcorend[] = "IUIYa:eiouyYI@EOU92~";
const char ipa_voicedplos[] = "6dbgzv";
const char ipa_sylcons[] = "lmnN6";
const char ipa_beforeborder[] = "?bdZghzj,'";
const char ipa_voicedcons[] = "6rlmnNvj";
const char ipa_sonorants[] = "6rlmnN";


// Aussprache der Buchstaben des Alphabets

const string spelling[29] =
{
	"?a:", "be:", "tse:", "de:", "?e:", "?Ef",  "ge:",      "ha:",  "?i:",
	"jOt", "ka:", "?El",  "?Em", "?En", "?o:",  "pe:",      "ku:",  "?Er",
	"?Es", "te:", "?u:",  "faU", "ve:", "?Iks", "?YpsilOn", "tsEt", "?E:",
	"?2:", "?y:"
};







