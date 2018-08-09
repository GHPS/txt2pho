
#if !defined(__UNIT_H__)
#define __UNIT_H__


#if !defined(__INVENT_H__)
#include "invent.h"
#endif
#if !defined(__LIST_H__)
#include "list.h"
#endif
#if !defined(__SOUND_H__)
#include "sound.h"
#endif
#if !defined(__UNITPAR_H__)
#include "unitpar.h"
#endif


typedef struct {
	char name[8] ;
	int firstsound ;
	float soundnr ;
	char type ;
	char startmark[6] ;
	char endmark[6] ; } Unitinfo ;

class Unitlist: public List<Unitinfo> {

		void build_sce(char*,int,int,int, Inventory& i) ;
		Unitinfo* get_unit_pointer() ;

	public:
		Unitlist() ;
		~Unitlist() ;

		int build(Soundlist* soli, Inventory&) ;


		Parameterset get_next_set(Soundlist* soli) ;
		void print(FILE* ascoutfil) ;
		void optimize(Soundlist* soli, Inventory& invent, char* method) ; } ;

#endif

