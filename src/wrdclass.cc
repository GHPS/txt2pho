
#include <assert.h>
#include <stdlib.h>


#include "wrdclass.h"


////////////////////////////////////////////////////////////////////////////////////////

string wcl2str (TWordClass wcl)
{
	switch (wcl)
	{
		case NOM:
			return "NOM";
		case NAM:
			return "NAM";
		case QPV:
			return "QPV";
		case QAN:
			return "QAN";
		case QPN:
			return "QPN";
		case QAV:
			return "QAV";
		case VRB:
			return "VRB";
		case VEM:
			return "VEM";
		case VEH:
			return "VEH";
		case VES:
			return "VES";
		case VEW:
			return "VEW";
		case ART:
			return "ART";
		case PRO:
			return "PRO";
		case PPR:
      	return "PPR";
      case VKN:
      	return "VKN";
		case KKN:
      	return "KKN" ;
		case ADD:
			return "ADD";
		case SBJ:
			return "SBJ";
		case KNJ:
			return "KNJ";
		case TME:
			return "TME";
		case NEG:
			return "NEG";
		case NUM:
			return "NUM";
		case RFW:
			return "RFW";
		case MOD:
			return "MOD";
		case INJ:
			return "INJ";
		case KMP:
			return "KMP";
		case NumberOfWordClasses:
			return "<Anzahl_der_Wortklassen>";
		case Unknown:
			return "<Unbekannt>";
		case Error:
			return "<Fehler>";
		default:
			return "<Da_ist_etwas_schiefgelaufen>";
	}
}


////////////////////////////////////////////////////////////////////////////////////////

string wcl2str (short cnt_wcls, const TWordClass *wcls)
{
	assert(cnt_wcls != 0);

	string result;

	for (short i = 0; i < cnt_wcls - 1; i++)
		result += wcl2str(wcls[i]) + ":";
	result += wcl2str(wcls[cnt_wcls - 1]);

	return result;
}


////////////////////////////////////////////////////////////////////////////////////////

TWordClass str2wcl (const string &str)
{
	if (str == "NOM")  return NOM;
	else if (str == "NAM")  return NAM;
	else if (str == "QPV")  return QPV;
	else if (str == "QAN")  return QAN;
	else if (str == "QPN")  return QPN;
	else if (str == "QAV")  return QAV;
	else if (str == "VRB")  return VRB;
	else if (str == "VEM")  return VEM;
	else if (str == "VEH")  return VEH;
	else if (str == "VES")  return VES;
	else if (str == "VEW")  return VEW;
	else if (str == "ART")  return ART;
	else if (str == "PRO")  return PRO;
	else if (str == "PPR")  return PPR;
	else if (str == "VKN")  return VKN;
	else if (str == "KKN")  return KKN;
	else if (str == "ADD")  return ADD;
	else if (str == "SBJ")  return SBJ;
	else if (str == "KNJ")  return KNJ;
	else if (str == "TME")  return TME;
	else if (str == "NEG")  return NEG;
	else if (str == "NUM")  return NUM;
	else if (str == "RFW")  return RFW;
	else if (str == "MOD")  return MOD;
	else if (str == "INJ")  return INJ;
	else if (str == "KMP")  return KMP;
	else if (str == "<NULL>")  return Unknown;
	else return Error;
}

