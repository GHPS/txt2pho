
#if !defined(__DI_H__)
#define __DI_H__

#if !defined(__LIST_H__)
#include "list.h"
#endif
#if !defined(__SONUD_H__)
#include "sound.h"
#endif
#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif


typedef struct {
	char name[7] ;
	char type ;
	float f0[30] ;
	int f0pos[30] ;
	int f0nr ;
	int initial_value ;
	int amp ;
	long start ;
	int value ; } Duration_unit ;


class Duration {

	class Durationlist:public List<Duration_unit> {
	float maxfact ;
	int maxdur ;

	public:

		Duration_unit* get_durinf_pointer(int indexnr) ;
		void multiply_value(int indexnr, float factor) ;
		char* get_name(int indexnr) ;
		int conc(Duration_unit a) ;
		Durationlist() ;
		~Durationlist() ; } ;

	Durationlist durl ;

	long newactsample ;
	Duration_unit du1 ;
	float actf0 ;
	float lastampfac ;
	float lastactf0 ;
	float actf0pos,lastactf0pos;
	int actf0nr ;
	long actms ;
	Duration_unit du2;
	int sf ;

public:

	Duration(int samplingf) ;

//===============

	// destructor

	~Duration() ;

//===============

	int write_sentence_duration(Periodlist& pl, Marklist& ml,long start, long end, FILE* nmkfile = NULL) ;

	int input_duration(Soundlist* soli) ;

	void reset() ;

} ;

//=============================================================================

#endif

