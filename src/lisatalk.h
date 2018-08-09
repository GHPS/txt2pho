
#if !defined(__LISATALK_H__)
#define __LISATALK_H__

// defines lassen sich durch Voranstellen von N ausschalten
#define IKP_VERSION
#define PETRA
#define SPELLING
#define VORVERARBEITUNG

#ifdef UNIX
//#define max(a,b) ((a)>(b)?(a):(b))
//#define min(a,b) ((a)<(b)?(a):(b))
//#define random(i) 0
#define String string
#define _USERENTRY
#endif


#if defined(_Windows)
#define Windows
#ifdef NOWINMOD
#undef _Windows
#else
#ifdef NN
#define INC_OLE2
#else
#define WIN31
#endif
#endif
#define STRICT
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

#if defined(_Windows)
#include <windows.h>
#include <mmsystem.h>
#endif

#undef isspace
#undef strlen

#if !defined(__FILETOOL_H__)
#include "filetool.h"
#endif
#if !defined(__LIST_H__)
#include "list.h"
#endif



#endif



