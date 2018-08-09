
#include "ascii.h"
#include "debug.h"


////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   A C H T U N G                                    //
//                                  ---------------                                   //
//                                                                                    //
// Diese Datei enthält String- und Character-Konstanten mit ASCII- und IPA-Zeichen.   //
// Sie darf unter keinen Umständen automatisch in einen anderen Zeichensatz           //
// konvertiert werden.                                                                //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////


// Definitionen für häufig benutzte Zeichenmengen

const string asc_lower_chars = "abcdefghijklmnopqrstuvwxyzäöüßáàâìíîòóôúùûéèêñÑ";
const string asc_upper_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZÄÖÜ";
const string asc_consonants = "BCDFGHJKLMNPQRSTVWXZbcdfghjklmnpqrstvwxzßñÑ";
const string asc_vowels = "AEIOUYÄÖÜaeiouyäöüáàâíìîúùûóòôéèê";


// Mapping-Routinen


char ucase (char c)
{
	if (c >= 'A' && c <= 'Z')
		return c;
	if (c >= 'a' && c <= 'z')
		return toupper(c);
	switch (c)
	{
		case asc_a_acc_acute:
		case asc_a_acc_grave:
		case asc_a_acc_hat:    return 'A';
		case asc_i_acc_acute:
		case asc_i_acc_grave:
		case asc_i_acc_hat:    return 'I';
		case asc_a_umlaut:     return asc_A_umlaut;
		case asc_e_acc_acute:
		case asc_e_acc_grave:
		case asc_e_acc_hat:     return 'E';
		case asc_o_acc_acute:
	        case asc_o_acc_grave:
		case asc_o_acc_hat:    return 'O';
		case asc_o_umlaut:     return asc_O_umlaut;
        	case asc_u_acc_grave:
	        case asc_u_acc_hat:
		case asc_u_acc_acute:  return 'U';
		case asc_u_umlaut:     return asc_U_umlaut;
		case asc_n_tilde:
		case asc_N_tilde:      return 'N';
		case asc_sz_lig:       return 'S';
		case '_':              return ' ';
		default:               return c;
	}
}


char voll7bit (char c)
{
	char d = ucase(c);

	switch (d)
	{
		case asc_A_umlaut:  return 'A';
		case asc_O_umlaut:  return 'O';
		case asc_U_umlaut:  return 'U';
		default:            return d;
	}
}


char upper_char (char c)
{
	if (c >= 'A' && c <= 'Z')
		return c;
	if (c >= 'a' && c <= 'z')
		return toupper(c);
	switch (c)
	{
		case '_':              return ' ';
		case asc_a_acc_acute:  return asc_A_acc_acute;
		case asc_a_acc_grave:  return asc_A_acc_grave;
		case asc_a_acc_hat:    return asc_A_acc_hat;
		case asc_a_umlaut:     return asc_A_umlaut;
		case asc_e_acc_acute:  return asc_E_acc_acute;
		case asc_e_acc_grave:  return asc_E_acc_grave;
		case asc_e_acc_hat:    return asc_E_acc_hat;
		case asc_o_acc_acute:  return asc_O_acc_acute;
		case asc_o_acc_grave:  return asc_O_acc_grave;
		case asc_o_acc_hat:    return asc_O_acc_hat;
		case asc_o_umlaut:     return asc_O_umlaut;
		case asc_u_acc_acute:  return asc_U_acc_acute;
		case asc_u_acc_grave:  return asc_U_acc_grave;
		case asc_u_acc_hat:    return asc_U_acc_hat;
		case asc_u_umlaut:     return asc_U_umlaut;
		case asc_n_tilde:      return asc_N_tilde;
		case asc_sz_lig:       return 'S';
		default:               return c;
	}
}


char remap_char (char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c < 'z'))
		return c;
	switch (c)
	{
		case '_':  return ' ';
		case asc_a_acc_acute:
		case asc_a_acc_grave:
		case asc_a_acc_hat:
		case asc_a_umlaut:     return 'a';
		case asc_e_acc_acute:
		case asc_e_acc_grave:
		case asc_e_acc_hat:    return 'e';
		case asc_i_acc_acute:
		case asc_i_acc_grave:
		case asc_i_acc_hat:    return 'i';
		case asc_o_acc_acute:
		case asc_o_acc_grave:
		case asc_o_acc_hat:
		case asc_o_umlaut:     return 'o';
		case asc_u_acc_acute:
		case asc_u_acc_grave:
		case asc_u_acc_hat:
		case asc_u_umlaut:     return 'u';
		case asc_n_tilde:      return 'n';
		case asc_sz_lig:       return 's';
		case asc_A_acc_acute:
		case asc_A_acc_grave:
		case asc_A_acc_hat:
		case asc_A_umlaut:     return 'A';
		case asc_E_acc_acute:
		case asc_E_acc_grave:
		case asc_E_acc_hat:    return 'E';
		case asc_I_acc_acute:
		case asc_I_acc_grave:
		case asc_I_acc_hat:    return 'I';
		case asc_O_acc_acute:
		case asc_O_acc_grave:
		case asc_O_acc_hat:
		case asc_O_umlaut:     return 'O';
		case asc_U_acc_acute:
		case asc_U_acc_grave:
		case asc_U_acc_hat:
		case asc_U_umlaut:     return 'U';
		case asc_N_tilde:      return 'N';
		default:               return c;
	}
}

//#if defined(__GNUC__)

char *strrev (char *str) {
	if (str == NULL)
		return NULL;

	char *start = str, *end = str + strlen(str) - 1;

	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
	return str;
}



char* strdup(const char* in) {
	char* temp = new char[strlen(in)+1] ;
	strcpy(temp,in) ;
	return(temp) ; }

char* strdup(char* in) {
	char* temp = new char[strlen(in)+1] ;
	strcpy(temp,in) ;
	return(temp) ; }

//#endif







