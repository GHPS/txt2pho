/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPRULCHR_H_
#define _PPRULCHR_H_
#include <stdio.h>

class PPRulechars {

   char* member ;

public:

	char key ;

	PPRulechars(char* in) ;
   ~PPRulechars() ;
   void list(FILE* lf) ;
   int is_member(char c) ; } ;

#endif


