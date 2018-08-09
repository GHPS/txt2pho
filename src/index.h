
#if !defined(INDEX_HEADER)
#define INDEX_HEADER


#include <assert.h>
#include <string.h>
#ifdef Windows
#include <cstring.h>
#else
#include <string>
#include <cstring>
#endif


#include "file.h"


////////////////////////////////////////////////////////////////////////////////////////

const int valid_chars = 10;


////////////////////////////////////////////////////////////////////////////////////////

string convert_string (const string &str, bool remap_case, bool remap_umlaut);


////////////////////////////////////////////////////////////////////////////////////////

class TIndex
{
		struct TRecord
		{
				char chars[valid_chars + 1];
				char dummy;
				long pointer;
				long start;

				static int _USERENTRY compare_by_chars (const void *cvpa, const void *cvpb);
				static int _USERENTRY compare_by_start (const void *cvpa, const void *cvpb);
		};

	private:
		mutable TRecord *records;
		mutable short cnt_records;

                void map (char*, TRecord) ;
		bool Compile (const TFile &sourcefile, TFile &binaryfile, int minblocksize = 32);
		bool Load (const TFile &binaryfile);

	public:
		TIndex (const string &datapath, const string &basename);
		virtual ~TIndex ();

		short Search (const string &lexem, short hint) const;
		short Search (long i, short hint) const;

		inline short Entries () const;
		inline const TRecord &operator[] (short i) const;
};


////////////////////////////////////////////////////////////////////////////////////////

inline short TIndex::Entries () const
{
	return cnt_records - 1;
}


////////////////////////////////////////////////////////////////////////////////////////

inline const TIndex::TRecord &TIndex::operator[] (short i) const
{
	assert(i >= 0 && i < cnt_records);

	return records[i];
}


#endif

