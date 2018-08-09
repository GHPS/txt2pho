#ifndef __promguess_HEADER__
#define __promguess_HEADER__


typedef struct {
   float ACAT;
   char* WAKZENT;
   char* LAUT;
   char* WSYLC;
   char* WSYLP;
   float SONR;
   float BODI;
   char* ACCE;
   char* FACCE;
   char* PACCE;
   char* CODAC;
   char* ONSEC;
   char* WORTART;
  } promguess_struct ;

extern float promguess_wagon_comp(promguess_struct& st) ; 

#endif
