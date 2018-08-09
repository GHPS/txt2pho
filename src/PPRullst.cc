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
#include "PPRullst.h"
#include <stdlib.h>
#include <string.h>
#include "PPdebug.h"

char* get_tokenend(char* in) {
	int i = 0;
   	while(in[i] == ' ') {
   		if (in[i] == '\0')
      			return(NULL) ;
   		i++ ; }
	while(in[i] != ' ') {
   		if (in[i] == '\0')
      			return(NULL) ;
   		i++ ; }
   	return(&in[i]) ; }

PPRulelist::PPRulelist(FILE* rf) {

	char buffer[2048] ;

   rulenr = 0 ;
   rulelist = (PPRule**)malloc(sizeof(PPRule*)) ;

   while (fgets(buffer,2047,rf) != NULL) {
   	if (strlen(buffer) < 3)
      	continue ;
      if (buffer[0] == '#')
      	continue ;
		if (strncmp(buffer,"Rules",5) == 0)
      	break ;
      buffer[strlen(buffer)-1] = '\0' ;
      rcl.add(buffer) ; }

   while (fgets(buffer,2047,rf) != NULL) {
   	if (strlen(buffer) < 3)
      	continue ;
      if (buffer[0] == '#')
      	continue ;
      buffer[strlen(buffer)-1] = '\0' ;
      rulelist[rulenr] = new PPRule(buffer) ;
      rulenr++ ;
      rulelist = (PPRule**)realloc(rulelist,(rulenr+1)*sizeof(PPRule*)) ; }

   return ; }

PPRulelist::~PPRulelist() {
	int i ;
   for (i=0 ; i < rulenr ; i++)
   	delete(rulelist[i]) ;
   delete(rulelist) ; }

char* PPRulelist::apply(char* in, int tokenstart) {
	int i ;
   int suc = 0 ;
   char* result ;
   char* p = NULL  ;
   for (i=0 ; i < rulenr ; i++) {
   	in = rulelist[i]->apply(in,tokenstart, suc,rcl) ;
      if (suc == 1)
      	break ; }
   if (suc == 0) {
   	result = new char[strlen(&in[tokenstart])+1] ;
      strcpy(result,&in[tokenstart]) ;
      p = get_tokenend(result) ;
      if (p!= NULL) 
      	p[0] = '\0' ;
      delete(in) ;
      return(result) ; }
   return(in) ; }

void PPRulelist::list(FILE* lf) {
	int i ;
	rcl.list(lf) ;
   for (i=0 ; i < rulenr ; i++)
   	rulelist[i]->list(lf) ; }


