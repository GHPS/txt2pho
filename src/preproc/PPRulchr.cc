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
#include "PPRulchr.h"
#include <stdlib.h>
#include <string.h>
#include "PPdebug.h"

PPRulechars::PPRulechars(char* in) {
   unsigned int i,j ;
   key = '\0' ;
   member = NULL ;
   for (i = 0 ; i < strlen(in) ; i++)
   	if (in[i] != ' ' && key == '\0') {
      	key = in[i] ; break ; }
	i++ ;
	while (i < strlen(in)) {
   	if (in[i] == ':')
      	break ;
      i++ ; }
   i++ ;
   while (i < strlen(in)) {
   	if (in[i] != ' ' && in[i] != 0x09)
      	break ;
      i++ ;}
   j = i ;
   while (i < strlen(in)) {
   	if (in[i] == ' ' || in[i] == 0x09 || in[i] == '\0' || in[i] == 0x0a || in[i] == 0x0d)
      	break ;
      i++ ;}
	member = new char[i+2-j] ;
   in[i] = '\0' ;
   strcpy(member,&in[j]) ; }

PPRulechars::~PPRulechars() {
	if (member != NULL)
   	delete(member) ; }

int PPRulechars::is_member(char c) {

	if (strchr(member,c) != NULL)
   	return(1) ;
   return(0) ; }

void PPRulechars::list(FILE* lf) {
	fprintf(lf,"KEY: %c  MEMBERS: %s\n",key,member) ; }
