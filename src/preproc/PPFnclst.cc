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
#include "PPFnclst.h"
#include "PPFuncts.h"
#include <string.h>
#include <stdio.h>
#include "PPdebug.h"

#define EXECUTE(p) if (strcmp(temp,#p) == 0)  { result=p(result) ; success = 1 ; }

char* PPFunctionlist::call(char* in) {
   char* p ;
   char* t ;
	int success = 0 ;
	if ((p = strchr(in,'(')) == NULL)
   	return(in) ;
   char* temp = new char[strlen(in)+1] ;
   strcpy(temp,in) ;
   p = strrchr(temp,')') ;
   if (p == NULL) {
	delete(temp) ;
	return(in) ; }
   *p = '\0' ;
   t = p+1 ;
   p = strchr(temp,'(') ;
   *p = '\0' ;
   p++ ;
   char* result = new char[strlen(p)+1] ;
   strcpy(result,p) ;
   EXECUTE(single_numbers) ;
   EXECUTE(numeral) ;
   EXECUTE(dnumeral) ;
   EXECUTE(dnumeral_range) ;
   EXECUTE(fraction) ;
   EXECUTE(ratio) ;
   EXECUTE(thousands_separated_number) ;
   EXECUTE(countnumber) ;
   EXECUTE(phone_number_prefix) ;
   EXECUTE(international_phone_prefix) ;
   EXECUTE(phone_number) ;
   EXECUTE(money_post) ;
   EXECUTE(money_pre) ;
   EXECUTE(money_no_change) ;
   EXECUTE(time) ;
   EXECUTE(time_before_Uhr) ;
   EXECUTE(ordinal_fem) ;
   EXECUTE(ordinal_neutr) ;
   EXECUTE(ordinal_dativ) ;
   EXECUTE(short_date) ;
   EXECUTE(short_date_flex) ;
   EXECUTE(full_date) ;
   EXECUTE(full_date_flex) ;
   EXECUTE(version) ;
   EXECUTE(real_number) ;
   EXECUTE(real_number_with_point) ;
   EXECUTE(email) ;
   EXECUTE(http_address) ;
   EXECUTE(computer_address) ;
   EXECUTE(unit) ;
   EXECUTE(unit_per) ;
   EXECUTE(street) ;
   EXECUTE(bracket) ;
   EXECUTE(dash) ;
   EXECUTE(at) ;
   EXECUTE(euro) ;
   EXECUTE(dollar) ;
   EXECUTE(ando) ;
   EXECUTE(paragraph) ;
   EXECUTE(percent) ;
   EXECUTE(sign) ;
   EXECUTE(plus) ;
   EXECUTE(minus) ;
   EXECUTE(divide) ;
   EXECUTE(times) ;
   EXECUTE(equals) ;
   EXECUTE(arithmetic) ;
   EXECUTE(colon_numbers) ;
   EXECUTE(short_date_before_point) ;
   EXECUTE(short_date_flex_before_point) ;
   EXECUTE(full_date_before_point) ;
   EXECUTE(full_date_flex_before_point) ;
   EXECUTE(word_before_point) ;
   EXECUTE(colon_numbers_before_point) ;
   EXECUTE(real_number_before_point) ;
	EXECUTE(number_mixture) ;
   if (success == 0) {
   	delete(result) ;
      delete(temp) ;
      return(in) ; }
   p = new char[strlen(result)+strlen(t)+3] ;
   strcat(strcpy(p,result),t) ;
	delete(in) ;
	delete(temp) ;
   delete(result) ;
   return(p) ; }





