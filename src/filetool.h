/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/


#if !defined(__FILETOOL_H__)
#define __FILETOOL_H__


long fsize (FILE* xstream);

FILE* FOPEN(const char*, const char*) ;
int FCLOSE(FILE*) ;

#endif

