/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(__PHDURNN_H__)
#define __PHDURNN_H__

#if !defined(__LIST_H__)
    #include "list.h"
#endif

#if !defined(__SYLLABLE_H__)
    #include "syllable.h"
#endif

class PhonNetz;

#if !defined(__PROSODY_H__)
    #include "prosody.h"
#endif


#if !defined(__TSR_H__)
    #include "tsr.h"
#endif

class PhonNetz
{

        struct Condition
        {
            int column ;
            int block ;
            float minval ;
            float maxval ;
        } ;

        TSR* voktsr;
        TSR* kontsr;


        int kinputvaluenr ;
        int vinputvaluenr ;
        int outputvaluenr ;
        Condition* kinputvalues ;
        Condition* vinputvalues ;
        Condition* outputvalues ;

    public:

        PhonNetz(const char* vname, const char* kname, const char* path) ;
        ~PhonNetz() ;

        int compute(Syllablelist* s, Soundlist* soli, DBSyllist* dbs, float sr = 1.0, int use_net=1) ;
} ;

#endif










