
#if !defined(REDIRECT_HEADER)
#define REDIRECT_HEADER


#include <fstream.h>


void redirect (istream_withassign &istr, const char *filename);
void redirect (ostream_withassign &ostr, const char *filename);


#endif

