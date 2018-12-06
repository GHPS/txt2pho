/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/* Copyright (C) 1998  Thomas Portele


*/
#ifndef _PPCTGLST_H_
#define _PPCTGLST_H_

#include <stdio.h>

class PPCategorylist {

	char* category ;

public:

	PPCategorylist(char* in) ;
   ~PPCategorylist() ;
   int length() ;
   void list(FILE* lf) ;
   char* get_value() ; } ;

#endif

