/*===========================================================================

	inventory.h

	describes an unit inventory for speech synthesis

	17.5.1993 tp

===========================================================================*/

#if !defined(__INVENT_H__)
#define __INVENT_H__

#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif

/*============================================================================

	definition of basis class Signal

	this class is used to describe various representations of a signal,
	up to now, only time-domain signals are supported by a derived class

	public methods:
		
		long get_signal_length() :
			returns length of contained signal in samples

================================*/

class Signal {

	protected:

	int mulaw ;
      long startpoint ;
      FILE* fil ;
		long length ;

	public:

		virtual ~Signal() ;
		long get_signal_length() ; } ;

/*============================================================================

	defines class Timesignal - derived from Signal

	public methods:

		Timesignal(FILE* sigfile, long start, int length) :
			constructor reads a signal part from a file
			sigfile: source file for signal
			start: begin of signal (in bytes)
			length: length of signal in bytes

		short* get_signal(int leftborder, int rightborder) :
			produces a copy of the signal part ranging
				from leftborder to rightborder
			leftborder: start of new signal in samples
			rightborder: end of new signal in samples

================================*/

class Timesignal:public Signal {

		short* pcmsignal ;		// time signal array

	public:

		Timesignal(FILE* sigfile, long start, long len, int mulw) ;
		~Timesignal() ;
		short* get_signal(long leftborder, long rightborder) ; } ;


typedef struct {
	int grade ;
	float mu ;
	float* rc ;
	short* residual ;
	float amplitude ;
	int type ;
	int length ; } LPC_Frame ;



class Relpsignal:public Signal {

		LPC_Frame* frames ;
		char* residualname ;
		float mu ;
		int grade ;


	public:

		Relpsignal(FILE* sigfile, long start, int number, char* ipath) ;
		~Relpsignal() ;
		LPC_Frame* get_signal(long leftborder, long rightborder, int& number) ; } ;
/*============================================================================

	definition of a unit

	following variables are used:
		name: name of the unit
		type: type (currently 'a','r','s','p','d' and 'x' (for errors))
		number: reference number
		sampling_frequency: in kHz
		data_format: up to now only 'T' (time signal) possible
		recording_session: up to now always 1
		sig: pointer to Signal class containing the (time) signal
		pitchmarks: points to an object of type Periodlist
		borders: points to an object of type Markerlist

=======================================*/

typedef struct {
	char name[10] ;
	char type ;
	int number ;
	int sampling_frequency ;
	char data_format ;
	int recording_session ;
	Timesignal* sig ;
	Relpsignal* lp ;
	Periodlist* pitchmarks ;
	Marklist* borders ; } Unit ;

/*============================================================================

	manages a unit inventory

	public methods:

		Inventory(char* inventory_name) :
			constructor sets up internal representation of an inventory,
				reads indexfile into internal structure, opens
				other files
			inventory_name: name of the inventory to be used

		Unit get_unit(char* name, char type) :
			fetches a unit from the inventory, returns it in structure
				Unit described above
			name: name of the unit
			type: type of the unit

=======================================*/
typedef struct {			// Unitindex descr.
	char name[7] ;
	char type ;
	long signal_start ;
	long signal_length ;
	long period_start ;
	int period_length ;
	long marker_start ;
	int marker_length ; } Unitindex ;

typedef struct {
	char name[10] ;
	char bytes ;
	char voice ;
	short sampling_frequency ; } Inventoryinfo ;

// Unitindexlist as internal object
class Unitindexlist {

	typedef struct {
		Unitindex* pointer ;
		int collision ; } Hashtableentry ;

	short hashtablesize ;
	short* freehashtableentries ;

	Hashtableentry* hashtable ;

	char invheader[14] ;

	Unitindex errorvalue ;

	public:

		Unitindexlist(char* indexfilename, Inventoryinfo& header, char* hashfilename) ;
		~Unitindexlist() ;

		int write(char* indexfilename) ;
		int del(char* name, char type) ;
                int add(Unitindex* i) ;
		int size() ;

		int read(char* indexfilename, char* hashfilename) ;

		int build_hashtable(char* indexfilename, char* hashfilename) ;
		Unitindex* get_unit_index_pointer(char* name, char type) ;

		Unitindex* get_index_by_number(int number) ;
		Unitindex get_unit_index(char* name, char type) ; } ;


class Inventory {

	private:

                char* invp ;
		Inventoryinfo header ;
		int mulaw ;

	protected:

		Unitindexlist* uilist ;		// instantiation
		FILE* pmfile ;			// period info file
		FILE* markerfile ;		// marker file
		FILE* tsfile ;			// time signal file

	public:

		Inventory(char* inventory_name, char* inventory_path, int mulw = 0) ;
		~Inventory() ;

		int get_sf() ;
		char get_bytes() ;

		Unitindex find_unit(char* name, char type) { return(uilist->get_unit_index(name,type)) ; } ;

		Unit get_unit(char* name, char type) ;

		Unit get_unit_signal(char* name, char type) ;

		Unit get_unit_info(char*name, char type) ; } ;

//============================================================================

#endif

