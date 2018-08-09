#include "lisatalk.h"

class ImpossibleWords {
	char* startpairs ;
	char* endpairs ;
	int startpairnr ;
	int endpairnr ;

public:

	ImpossibleWords(char* path) ;
	~ImpossibleWords() ;
        int is_impossible(char* word) ; } ;




