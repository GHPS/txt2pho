/* Copyright (C) 1998  Thomas Portele


*/
#include "PPRlchls.h"
#include <stdlib.h>

PPRulecharlist::PPRulecharlist() {
	lst = (PPRulechars**)malloc(sizeof(PPRulechars*)) ;
   listnumber = 0 ; }

PPRulecharlist::~PPRulecharlist() {
	int i ;
   for (i=0 ; i < listnumber ; i++)
   	delete(lst[i]) ;
   free(lst) ; }

int PPRulecharlist::add(char* in) {
	lst[listnumber++] = new PPRulechars(in) ;
   lst = (PPRulechars**)realloc(lst,sizeof(PPRulechars*)*(listnumber+1)) ;
   return(listnumber) ; }

int PPRulecharlist::check(char key, char c) {
   int i ;
   for (i=0 ; i < listnumber ; i++) {
   	if (lst[i]->key == key)
      	return(lst[i]->is_member(c)) ; }
   return(0) ; }

void PPRulecharlist::list(FILE* lf) {
   int i ;
   for (i=0 ; i < listnumber ; i++) {
   	lst[i]->list(lf) ; } }

