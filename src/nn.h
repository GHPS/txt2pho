/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(__NN_H__)
#define __NN_H__

#if !defined(__LIST_H__)
    #include "list.h"
#endif



struct Condition
{
    int column ;
    int block ;
    float minval ;
    float maxval ;
} ;

class Netz
{

        int inputvaluenr ;
        int outputvaluenr ;
        Condition* inputvalues ;
        Condition* outputvalues ;

    public:

        Netz(char* name, char* path) ;
        ~Netz() ;

        int compute(FILE* infile, FILE* outfile, int(*netzfkt)(float*, float*, int)) ;
} ;

#endif

