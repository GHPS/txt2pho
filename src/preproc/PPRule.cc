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
#include "PPRule.h"
#include <string.h>
#include "PPdebug.h"

PPRule::PPRule(char* in) {

  char* c ;

   cs = NULL ;
   cl = NULL ;

   c = strstr(in," AS ") ;
   if (c== NULL) {
   	fprintf(errfile,"Keyword AS missing in %s\n",in) ;
      return ; }

   c[0] = '\0' ;
	c = c+4 ;

   cs = new PPCategorystring(in) ;
   cl = new PPCategorylist(c) ; }

PPRule::~PPRule() {
	if (cs != NULL)
		delete(cs) ;
   if (cl != NULL)
	   delete(cl) ; }

void PPRule::list(FILE* lf) {
	if (cs != NULL)
		cs->list(lf) ;
   fprintf(lf," AS ") ;
   if (cl != NULL)
   	cl->list(lf) ;
   fprintf(lf,"\n") ; }

char* PPRule::apply(char* in, int tokenstart, int& success, PPRulecharlist& rcl) {
	int left ;
   if (cs == NULL || cl == NULL) {
   	success = 0 ;
   	return(in) ; }
	if (cs->find(in,tokenstart,left,rcl) == 0) {
   	success = 0 ;
   	return(in) ; }
   success = 1 ;
   char* out = new char[strlen(in)+ cl->length()+6] ;
   int i ;
   char ll ;
   ll = in[left+tokenstart] ;
   in[left+tokenstart] = '\0' ;
	if (ll != ' ') {
	   for (i = left+tokenstart+1 ; i < (int)strlen(&in[left+tokenstart+1])+left+tokenstart+1 ; i++)
   		if (in[i] == ' ') {
      		in[i] = '\0' ;
         	break ; }
	   sprintf(out,"%s(%s) %c%s",cl->get_value(),&in[tokenstart],ll,&in[left+tokenstart+1]) ; }
   else {
	   sprintf(out,"%s(%s)",cl->get_value(),&in[tokenstart]) ; }
   delete(in) ;
   return(out) ; }





