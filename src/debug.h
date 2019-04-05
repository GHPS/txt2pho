/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(DEBUG_HEADER)
#define DEBUG_HEADER

#ifndef NUSE_WRAPPER
    #define NUSE_WRAPPER
#endif

#define IKP_VERSION

//#include <alloc.h>
#include <assert.h>
#ifdef _Windows
    #include <cstring.h>
    #include <except.h>
    #include <typeinfo.h>
    #include <assert.h>
    #define Windows
#else
    #include <string>
    #include <stdlib.h>
    #define _USERENTRY
#endif
#include <iostream>
#include <string.h>
#include <fstream>

extern std::ofstream debugstr ;

#if defined(USE_WRAPPER)
    #include "pointer.h"
#endif

#if defined(DEBUG) && !defined(NDEBUG)
    #pragma option -vi-
#else
    #pragma option -vi+
#endif

#include <fstream>



#define ERRMSG(str)                                                                    \
    do                                                                                 \
    {                                                                                  \
        debugstr << "\n"                                                                   \
                 << "\aFehler in '" __FILE__ << "' (" << __LINE__ << "): " << str << "!\n"  \
                 << endl;                                                                  \
        exit(0);                                                            \
    }   while (0)




#define WARNMSG(str)                                                                   \
    do                                                                                 \
    {                                                                                  \
        debugstr << "\n"                                                                   \
                 << "\aWarnung in '" __FILE__ << "' (" << __LINE__ << "): " << str << "!\n" \
                 << "\n"                                                                   \
                 << "'Q' für Abbruch, jede andere Taste zum Fortsetzen ";                  \
        int c = cin.get();                                                             \
        cerr << endl;                                                                  \
        if (c == 0)                                                                    \
            cin.get();                                                                 \
        else if (c == 'Q' || c == 'q' || c == EOF)      \
            exit(0);                                                        \
    }   while (0)

#ifdef Windows

#if !defined(NDEBUG)

#define ALLOCATE(type, dest, n)                                                        \
    do                                                                                 \
    {                                                                                  \
        size_t size = n;                                                               \
        \
        if (dest)                                                                      \
            WARNMSG("Speicheranforderung für bereits benutzten Zeiger '"#dest"'");     \
        if (size < 1)                                                                  \
            ERRMSG("Nicht-positive Speicheranforderung für Zeiger '"#dest"'");         \
        try                                                                            \
        {                                                                              \
            (dest) = new type[size];                                                   \
        }                                                                              \
        catch (xalloc)                                                                 \
        {                                                                              \
            ERRMSG("Speicheranforderung für Zeiger '"#dest"' fehlgeschlagen");         \
        }                                                                              \
    }   while (0)

#define DUPLICATE(dest, source)                                                        \
    do                                                                                 \
    {                                                                                  \
        if (dest)                                                                      \
            WARNMSG("Speicheranforderung für bereits benutzten Zeiger '"#dest"'");     \
        if (!(source))                                                                 \
        {                                                                              \
            WARNMSG("Kopieren des unbenutzen Zeigers '"#source"'");                    \
            dest = NULL;                                                               \
        }                                                                              \
        else                                                                           \
        {                                                                              \
            try                                                                        \
            {                                                                          \
                (dest) = new char[strlen(source) + 1];                                 \
            }                                                                          \
            catch (xalloc)                                                             \
            {                                                                          \
                ERRMSG("Speicheranforderung für Zeiger '"#dest"' fehlgeschlagen");     \
            }                                                                          \
            strcpy(dest, source);                                                      \
        }                                                                              \
    }   while (0)

#define CLEAR(ptr)                                                                     \
    do                                                                                 \
    {                                                                                  \
        if (!(ptr))                                                                    \
            WARNMSG("Speicherfreigabe des unbenutzten Zeigers '"#ptr"'");              \
        delete[] (ptr);                                                                \
        (ptr) = NULL;                                                                  \
    }   while (0)

#define CallDebugger()  asm int3

#else

#define ALLOCATE(type, dest, n)                                                        \
    do                                                                                 \
    {                                                                                  \
        try                                                                            \
        {                                                                              \
            (dest) = new type[n];                                                      \
        }                                                                              \
        catch (xalloc)                                                                 \
        {                                                                              \
            ERRMSG("Speicheranforderung für Zeiger '"#dest"' fehlgeschlagen");         \
        }                                                                              \
    }   while (0)

#define DUPLICATE(dest, source)                                                        \
    do                                                                                 \
    {                                                                                  \
        try                                                                            \
        {                                                                              \
            (dest) = new char[strlen(source) + 1];                                     \
        }                                                                              \
        catch (xalloc)                                                                 \
        {                                                                              \
            ERRMSG("Speicheranforderung für Zeiger '"#dest"' fehlgeschlagen");         \
        }                                                                              \
        strcpy(dest, source);                                                          \
    }   while (0)

#define CLEAR(ptr)                                                                     \
    do                                                                                 \
    {                                                                                  \
        delete[] (ptr);                                                                \
        (ptr) = NULL;                                                                  \
    }   while (0)

#define CallDebugger()

#endif

#else

#define ALLOCATE(type, dest, n)                                                        \
    do                                                                                 \
    {                                                                                  \
        {                                                                              \
            (dest) = new type[n];                                                      \
        }                                                                              \
        if ((dest) == NULL)								\
        {                                                                              \
            ERRMSG("Speicheranforderung für Zeiger '"#dest"' fehlgeschlagen");         \
        }                                                                              \
    }   while (0)

#define DUPLICATE(dest, source)                                                        \
    do                                                                                 \
    {                                                                                  \
        {                                                                              \
            (dest) = new char[strlen(source) + 1];                                     \
        }                                                                              \
        if ((dest) == NULL) 								\
        {                                                                              \
            ERRMSG("Speicheranforderung für Zeiger '"#dest"' fehlgeschlagen");         \
        }                                                                              \
        strcpy(dest, source);                                                          \
    }   while (0)

#define CLEAR(ptr)                                                                     \
    do                                                                                 \
    {                                                                                  \
        delete[] (ptr);                                                                \
        (ptr) = NULL;                                                                  \
    }   while (0)



#endif


////////////////////////////////////////////////////////////////////////////////////////

#if !defined(NSTATISTICS)

    #define statistics(str) debugstr << str << endl

#else

    #define statistics(str)

#endif

#if defined(USE_WRAPPER)
    typedef Pointer<char> PChar;
#else
    typedef char* PChar;
#endif


////////////////////////////////////////////////////////////////////////////////////////

/*
    #undef strlen
    #undef strcmp
    #undef stricmp
    #define strlen(s)       ((s) ? strlen((s)) : 0)
    #define strcmp(s1, s2)  ((s1) ? ((s2) ? stricmp((s1), (s2)) : stricmp((s1), "")) : ((s2) ? stricmp("", (s2)) : 0))
*/
#endif
