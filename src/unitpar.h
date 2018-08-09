
#if !defined(__UNITPAR_H__)
#define __UNITPAR_H__

struct Parameterset {
	char name[8] ;
	char type ;
	float dau ;
	float apl ;
	float apr ;
	int acc ;
	int lct ;
	int rct ;
	char lcs[6] ;
	char rcs[6] ;
	int inp ; } ;

class Unitparameter {

	private:

		int parpos ;
		char* parameter ;

	public:

		Unitparameter(char* parameterfilename) ;
		~Unitparameter() ;

		int end() ;

		Parameterset get_next_set() ; } ;

#endif

