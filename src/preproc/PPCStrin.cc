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
#include "PPCStrin.h"
#include "PPdebug.h"
#include <string.h>

PPCString::PPCString(char* in) {

	target = NULL ;

   int i ;

	target = new char[strlen(in)+1] ;

   strcpy(target,in) ; }

PPCString::~PPCString() {
	if (target != NULL)
  		delete(target) ; }

int PPCString::find(char* in, int tokenstart, int direction, int& left, PPRulecharlist& rcl) {
	if (target == NULL)
   	return(0) ;
	int i,j,k,l ;
   i = j = 0 ;
   PPCString* temp ;
   char v ;

	j = tokenstart ;
   while (i < strlen(target)) {
   	if (target[i] == '*') {
      	while (rcl.check(target[i-1],in[j]) == 1)
         	if (direction == -1)
	         	j-- ;
            else
            	j++ ;
         if (direction == -1)
         	i-- ;
         else
	         i++ ;
         continue ; }
      if (target[i] == '[') {
      	if (direction == -1) {
         	fprintf(errfile,"DIRECTION -1 NOT SUPPORTED WITH []\n") ;
            return(0) ; }
      	k = ++i ;
       	while (target[i] != ']')
         	i++ ;
         v = target[i] ;
         target[i] = '\0' ;
         temp = new PPCString(&target[k]) ;
         target[i] = v ;
   		if (temp->find(in,j,1,l,rcl) == 0) {
         	delete(temp) ;
            return(0) ; }
			j += l ;
			while (temp->find(in,j,1,l,rcl) != 0)
         	j += l ;
         delete(temp) ;
         i++ ;
         continue ; }
      if (rcl.check(target[i],in[j]) == 0)
      	return(0) ;
      if (direction == -1) {
      	i--; j-- ; }
      else {
      	i++ ; j++ ; } }
   if (in[j] != ' ' && direction == 0)
   	return(0) ;
   left = j - tokenstart ;
   return(1) ; }





/*
int PPCString::find(char* in, int tokenstart, int direction, int& left) {
	if (target == NULL)
   	return(0) ;
	int i,j,k ;
   char* number = "0123456789" ;
   char* ucaseletter = "ABCDEFGHIJKLMNOPQRSTUVWXYZý›Ù" ;
   char* locaseletter = "abcdefghijklmnopqrstuvwxyz„’÷ž" ;
   char* blank = " " ;
   char* symbol = ":.,-+/()&%?$!@\'\"" ;
   i=j=0 ;
   int result = 1 ;
   while (i < strlen(target)) {
   	switch (target[i]) {
      	case 'Z':
         	if (strchr(number,in[tokenstart+j]) == NULL)
            	result = 0 ;
            if (direction == -1)
            	j-- ;
            else
            j++ ;
            break ;
      	case 'G':
         	if (strchr(ucaseletter,in[tokenstart+j]) == NULL)
            	result = 0 ;
            if (direction == -1)
            	j-- ;
            else
            j++ ;
            break ;
      	case 'K':
         	if (strchr(locaseletter,in[tokenstart+j]) == NULL)
            	result = 0 ;
            if (direction == -1)
            	j-- ;
            else
            j++ ;
            break ;
      	case 'L':
         	if (strchr(ucaseletter,in[tokenstart+j]) == NULL && strchr(locaseletter,in[tokenstart+j]) == NULL)
            	result = 0 ;
            if (direction == -1)
            	j-- ;
            else
            j++ ;
            break ;
			case ':':
         case ',':
         case '.':
         case '-':
         case '+':
         case '/':
         case '(':
         case ')':
         case '&':
         case '@':
         case '=':
         case '%':
         case '$':
         case '?':
         case '!':
         case '\'':
         case '"':
         	if (in[tokenstart+j] != target[i])
               result = 0 ;
            if (direction == -1)
            	j-- ;
            else
            j++ ;
         	break ;
         case '*':
            switch(target[i-1]) {
            	case 'Z':
               	while (strchr(number,in[tokenstart+j]) != NULL)
			            if (direction == -1)
         			   	j-- ;
			            else
         	         	j++ ;
                  break ;
            	case 'G':
               	while (strchr(ucaseletter,in[tokenstart+j]) != NULL)
			            if (direction == -1)
         			   	j-- ;
			            else
            	      	j++ ;
                  break ;
            	case 'K':
               	while (strchr(locaseletter,in[tokenstart+j]) != NULL)
			            if (direction == -1)
         			   	j-- ;
			            else
               	   	j++ ;
                  break ;
            	case 'L':
               	while (strchr(locaseletter,in[tokenstart+j]) != NULL || strchr(ucaseletter,in[tokenstart+j]) != NULL)
			            if (direction == -1)
         			   	j-- ;
			            else
                  		j++ ;
                  break ;
               default:
               	fprintf(errfile,"INVALID CHARACTER '%c' BEFORE '*'\n",target[i-1]) ; }
         	break ;
         default:
              	fprintf(errfile,"INVALID CHARACTER '%c'\n",target[i]) ; }
		if (direction == -1)
      	i-- ;
      else
      i++ ; }
   left = j ;
   return(result) ; }
*/
void PPCString::list(FILE* lf) {
	if (target != NULL)
		fprintf(lf,"%s", target) ; }

