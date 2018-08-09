
#if !defined(__LIST_H__)
#define __LIST_H__
#include <stdio.h>

#define nulltest(i) if ((i) == NULL) {printf("out of heap\n");exit(0);}
#define abs(a) ((a)>0?(a):-(a))
//#define min(a,b) ((a)>(b)?(b):(a))
//#define max(a,b) ((a)<(b)?(b):(a))



/*==========================================================================

	definition of template List - describes a doubly linked list with
		a pointer to the actual position

	List needs a structure or class as generic parameter that contains
		the information stored in the list

	Public methods are:

		void reset() :
			resets the actual position pointer to the start

		Info get() :
			retrieves the information at the actual position

		Info get(int indexnumber) :

			retrieves the information at the specified entry
			indexnumber: number of the entry to use

		int get_number() :
			returns index number of actual position

		Info get_and_advance() :
			retrieves the information at the actual position and moves
				the actual position pointer to the next element of the list

================================*/
template <class Info> class List {

	protected:

		Info errorvalue ;		// special error item

		typedef struct listentry {	// element of the list
			Info i ;		// information
			int index ;		// index number
			listentry* after ;	// successor
			listentry* before ; } Listentry ;	// predecessor

		Listentry* start ;		// first element (no information)
		Listentry* end ;		// last element of the list
		Listentry* act ;		// pointer to actual element
		int append(Info i) ;		// appends Info i to end of list
		Info* xappend(Info i) ;

	public:

		int numb ;
		List() ;			// constructor
		virtual ~List() ;		// destructor

		void exclude(int index) ;
		void insert(Info i, int index) ;
		int advance() ;
		int decrease() ;
		int length() ;
		Info exclude_and_advance_and_get() ;
		void clear() ;
		void reset() ;			// see above comment
		Info get(int indexnumber) ;
		Info get() ;
		int get_number() ;
		Info get_and_advance() ; } ;

#if !defined(__LISTBODY_H__)
#include "listbody.h"
#endif

#endif

