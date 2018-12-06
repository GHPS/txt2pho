/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/


#if !defined(CMDLINE_HEADER)
#define CMDLINE_HEADER


#include <assert.h>
#include <cstring.h>
#include <dir.h>
#include <limits.h>
#include <values.h>
#include <sys/stat.h>
#include <classlib/defs.h>


#include "file.h"


////////////////////////////////////////////////////////////////////////////////////////

class TCommandLine
{
		int argc;
		string *argv;

		int actArg;

		TFile program;
		TFile workingDirectory;

	public:
		TCommandLine (int ArgC, char *ArgV[]);
		virtual ~TCommandLine ();

		inline int ArgC () const;
		inline const char *ArgV(int i) const;
		inline string operator[] (int i) const;

		inline const TFile &Program () const;
		inline const TFile &WorkingDirectory () const;

		bool GetParameter (string &param);
		bool GetParameter (float &param, float min = -MAXFLOAT, float max = MAXFLOAT);
		bool GetParameter (double &param, double min = -MAXDOUBLE, double max = MAXDOUBLE);
		bool GetParameter (short &param, short min = SHRT_MIN, short max = SHRT_MAX);
		bool GetParameter (int &param, int min = INT_MIN, int max = INT_MAX);
		bool GetParameter (long &param, long min = LONG_MIN, long max = LONG_MAX);
		bool GetParameter (TFile &param);

		bool GetFlag (char opt, int &value);
};


////////////////////////////////////////////////////////////////////////////////////////

inline int TCommandLine::ArgC () const
{
	return argc;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const char *TCommandLine::ArgV (int i) const
{
	return argv[i].c_str();
}


////////////////////////////////////////////////////////////////////////////////////////

inline string TCommandLine::operator[] (int i) const
{
	assert(i >= 0 && i < argc);
	return argv[i];
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TFile &TCommandLine::Program () const
{
	return program;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TFile &TCommandLine::WorkingDirectory () const
{
	return workingDirectory;
}


#endif

