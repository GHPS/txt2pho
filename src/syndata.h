
#if !defined(__SYNDATA_H__)
#define __SYNDATA_H__


#if !defined(__LIST_H__)
#include "list.h"
#endif

typedef enum {unvoiced, ppause, voiced, plosive, error } excitation ;

/*==========================================================================

	definition of structure Periodinfo

	the following variables are used:

		start: begin of period (position of pitchmark)
		excitation: 0 - unvoiced, 1 - pause, 2 - voiced, 3 - plosive
		rms: rms value of period
		length: length of period in samples

================================*/

typedef struct {
		long start ;
		int length ;
		short f0 ;
		float amp ;
		float dur ;
		excitation voiced ;
		unsigned char deletable ;
		unsigned char interpolate ; } Periodinfo ;

/*=============================================================================

	definition of structure Markerinfo

	the following variables are used:
		adress: position of marker in samples
		keylen: length of marker description
		key: marker description

================================*/

typedef struct {
		long adress ;
		char key[10] ; } Markerinfo ;


/*============================================================================

	definition of class Periodlist - derived from List using Periodinfo

	public methods:

		Periodlist :
			constructor builds a list from the info read
				from a file, the file record format can be
				defined in "invfiles.h"
			pmfile: pointer to the file
			start: start of period info to read (in bytes)
			length: number of bytes to read

		Periodinfo get_period_next_to(int sample) :
			returns the period which startpoint is closest
				to sample
			sample: adress to find next period start (pitchmark)

================================*/

class Periodlist:public List<Periodinfo> {

	public:

		Periodlist() ;
		Periodlist(FILE* pmfile, long start, int length) ;
		~Periodlist() ;

		int conc(Periodinfo i) ;
		Periodinfo* get_period_pointer() ;

		void print(FILE* ascoutfil) ;
		long input(FILE* ascinfil,long pos) ;
		int write(FILE* pmfile) ;

		double get_dB(long position) ;
		double get_max_dB() ;
		Periodinfo get_period_next_to_with_offset(long sample, int offset) ;
		Periodinfo get_period_next_to(long sample) ; } ;



/*=============================================================================

	definition of class Markerlist - derived from List using Markerinfo

	public methods:

		Markerlist :
			constructor builds a list from the info read
				from a file, the file record format can be
				defined in "invfiles.h"
			markerfile: pointer to the file
			start: start of marker info to read (in bytes)
			length: number of bytes to read

		Markerinfo get_marker_adress(char* key) :
			returns the adress of the next occurance of marker with key
				no more occurance: adress = -1
			key: marker description

=======================================*/


class Marklist:public List<Markerinfo> {

	public:
		Marklist(FILE* markerfile, long start, int length) ;
		Marklist() ;
		~Marklist() ;

		long get_marker_adress(char* key) ;
		long get_marker_adress_after(char* key) ;


		int conc(Markerinfo i) ;
		Markerinfo* get_marker_pointer() ;
		
		int write(FILE* markerfile) ;
		void print(FILE* ascoutfil) ;
		long input(FILE* ascinfil,long pos) ; } ;

#endif

