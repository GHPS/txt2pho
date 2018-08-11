/* Copyright (C) 1998  Thomas Portele

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

Thomas Portele
tpo@ikp.uni-bonn.de http://www.ikp.uni-bonn.de/~tpo
IKP Poppelsdorfer Allee 47, D-53115 Bonn Germany

__________________________

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

