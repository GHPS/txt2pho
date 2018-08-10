using namespace std ;

#if !defined(ASCII_HEADER)
#define ASCII_HEADER


#if 'z' - 'a' + 1 != 26
#error "Kein ASCII-Zeichensatz"
#endif

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
// Diese Datei enthÑlt String- und Character-Konstanten mit ASCII- und IPA-Zeichen.   //
// Sie darf unter keinen UmstÑnden automatisch in einen anderen Zeichensatz           //
// konvertiert werden.                                                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////


const int cnt_chars_in_alphabet = 'z' - 'a' + 1;


extern const string asc_lower_chars;
extern const string asc_upper_chars;
extern const string asc_consonants;
extern const string asc_vowels;

// Definitionen fÅr europÑische Sonderzeichen

const char asc_a_acc_acute = '·';
const char asc_a_acc_grave = '‡';
const char asc_a_acc_hat   = '‚';
const char asc_a_umlaut    = '‰';
const char asc_A_acc_acute = '¡';
const char asc_A_acc_grave = '¿';
const char asc_A_acc_hat   = '¬';
const char asc_A_umlaut    = 'ƒ';
const char asc_e_acc_acute = 'È';
const char asc_e_acc_grave = 'Ë';
const char asc_e_acc_hat   = 'Í';
const char asc_E_acc_acute = '…';
const char asc_E_acc_grave = '»';
const char asc_E_acc_hat   = ' ';
const char asc_i_acc_acute = 'Ì';
const char asc_i_acc_grave = 'Ï';
const char asc_i_acc_hat   = 'Ó';
const char asc_I_acc_acute = 'Õ';
const char asc_I_acc_grave = 'Ã';
const char asc_I_acc_hat   = 'Œ';
const char asc_I_acc_trema = 'À';
const char asc_o_acc_acute = 'Û';
const char asc_o_acc_grave = 'Ú';
const char asc_o_acc_hat   = 'Ù';
const char asc_o_umlaut    = 'ˆ';
const char asc_O_acc_acute = '”';
const char asc_O_acc_grave = '“';
const char asc_O_acc_hat   = '‘';
const char asc_O_umlaut    = '÷';
const char asc_u_acc_acute = '˙';
const char asc_u_acc_grave = '˘';
const char asc_u_acc_hat   = '˚';
const char asc_u_umlaut    = '¸';
const char asc_U_acc_acute = '⁄';
const char asc_U_acc_grave = 'Ÿ';
const char asc_U_acc_hat   = '€';
const char asc_U_umlaut    = '‹';
const char asc_n_tilde     = 'Ò';
const char asc_N_tilde     = '—';
const char asc_sz_lig      = 'ﬂ';

////////////////////////////////////////////////////////////////////////////////////////

// Mapping-Routinen

char ucase (char c);
char voll7bit (char c);
char upper_char (char c);
char remap_char (char c);


////////////////////////////////////////////////////////////////////////////////////////

inline bool is_whitespace (char c)
{
	return c == '\0' || c == '\t' || c == '\n' || c == '\r' || c == ' ' || c == 0x0d || c == 0x0a || c == 0x20 ;
}


//

inline bool is_ascii_vowel (char ch)
{
#ifdef _Windows
   return asc_vowels.contains(ch) ? true : false;
#else
	return asc_vowels.find(ch) != string::npos;
#endif
}


inline bool is_ascii_consonant (char ch)
{
#ifdef _Windows
   return asc_consonants.contains(ch) ? true : false;
#else
	return asc_consonants.find(ch) != string::npos;
#endif
}


////////////////////////////////////////////////////////////////////////////////////////

//#if defined(__GNUC__)
char *strrev(char *str);
//char *strdup(const char *str);
//#endif


#endif




