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

