/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/* Copyright (C) 1998  Thomas Portele


*/
#include "PPCtglst.h"
#include <string.h>

PPCategorylist::PPCategorylist(char* in) {
	category = new char[strlen(in)+1] ;
   strcpy(category,in) ; }

PPCategorylist::~PPCategorylist() {
	delete(category) ; }

void PPCategorylist::list(FILE* lf) {
	fprintf(lf,"%s",category) ; }

int PPCategorylist::length() {
	return(strlen(category)) ; }

char* PPCategorylist::get_value() {
	return(category) ; }
