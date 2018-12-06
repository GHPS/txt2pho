/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(__INFILE_H__)
#define __INFILE_H__


#ifndef UNIX
    #include <dir.h>
#else
    #define MAXPATH 255
    #define _MAX_PATH 255
#endif


class Infilehandler
{

        FILE* infile ;
        FILE* wordfile ;
        char filename[MAXPATH] ;
        long* sentencelist ;
        int sentencenr ;
        int actsentencenr ;
        FILE* actinfile ;
        long lastpos ;
        int return_to_infile ;

    public:

        Infilehandler(char* name) ;
        ~Infilehandler() ;
        FILE* get_infile() ;
        int eof() ;
        int close() ;
        int next_sentence() ;
        int repeat_one_sentence() ;
        int repeat_this_sentence() ;
        int skip_one_sentence() ;
        int repeat_word(int word_in_sentence, int lastwordrep, int interpunction) ;
        int spell_word(int word_in_sentence, int interpunction) ;
        int proceed_after_word(int word_in_sentence, int interpunction) ;
} ;

#endif

