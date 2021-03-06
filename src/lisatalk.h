/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(__LISATALK_H__)
#define __LISATALK_H__


#ifdef UNIX
    #define String string
    #define _USERENTRY
#endif



using namespace std;

//#include <ctype.h>
#include <fstream>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

extern FILE* errfile ;
extern int debuglevel ;
extern ofstream debugstr ;

#undef isspace
#undef strlen

#if !defined(__FILETOOL_H__)
    #include "filetool.h"
#endif
#if !defined(__LIST_H__)
    #include "list.h"
#endif



#endif



