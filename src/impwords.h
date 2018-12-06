/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "lisatalk.h"

class ImpossibleWords
{
        char* startpairs ;
        char* endpairs ;
        int startpairnr ;
        int endpairnr ;

    public:

        ImpossibleWords(char* path) ;
        ~ImpossibleWords() ;
        int is_impossible(char* word) ;
} ;




