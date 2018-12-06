/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

#ifndef __promguess_HEADER__
#define __promguess_HEADER__


typedef struct {
   float ACAT;
   const char* WAKZENT;
   const char* LAUT;
   const char* WSYLC;
   const char* WSYLP;
   float SONR;
   float BODI;
   const char* ACCE;
   const char* FACCE;
   const char* PACCE;
   const char* CODAC;
   const char* ONSEC;
   const char* WORTART;
  } promguess_struct ;

extern float promguess_wagon_comp(promguess_struct& st) ; 

#endif
