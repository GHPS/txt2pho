/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(__ENVIRON_H__)
#define __ENVIRON_H__


class Environment
{

        char** list ;
        int number ;

    public:
        Environment(const char* path, const char* filename) ;
        ~Environment() ;
        void writex(const char* filename) ;
        int put_value(char* key, char* value) ;
        char* get_value(const char* key) ;
} ;


#endif

