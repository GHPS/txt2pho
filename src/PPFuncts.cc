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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "PPdebug.h"

char* strfind(char* s, char* targets) {
	unsigned int i ;
   for (i=0 ; i < strlen(s) ; i++) {
   	if (strchr(targets,s[i]) != NULL)
      	return(&s[i]) ; }
   return(NULL) ; }
char* strrfind(char* s, char* targets) {
	int i ;
   for (i=strlen(s)-1 ; i >=0 ; i--) {
   	if (strchr(targets,s[i]) != NULL)
      	return(&s[i]) ; }
   return(NULL) ; }

char* Realloc(char* org, int i) {
	char* l = new char[i] ;
	if ((int)strlen(org) > i) {
		fprintf(errfile,"ERROR IN REALLOC\n") ; }
	else
		strcpy(l,org) ;
	delete(org) ;
	return(l) ; }

char* decom(char* in)
{
  if (strcmp(in,"de") == 0 || strncmp(in,"de/",3) == 0 ||
   strcmp(in,"DE") == 0 || strncmp(in,"DE/",3) == 0)
   {
      char* result = new char[strlen(in)+8] ;
      strcat(strcpy(result,"D E "),&in[2]) ;
      delete(in) ;
      return(result) ;
    }
  if (strcmp(in,"com") == 0 || strncmp(in,"com/",3) == 0 ||
   strcmp(in,"COM") == 0 || strncmp(in,"COM/",3) == 0)
   {
      char* result = new char[strlen(in)+8] ;
      strcat(strcpy(result,"komm"),&in[2]) ;
      delete(in) ;
      return(result) ;
    }
  return(in) ;
}

char* find_number(char* in) {
	unsigned int i ;
   for (i=0 ; i < strlen(in) ; i++) {
   	if (strchr("0123456789",in[i]) != NULL)
      	return(&in[i]) ;}
   return(NULL) ; }

char* find_non_number(char* in) {
	unsigned int i ;
   for (i=0 ; i < strlen(in) ; i++) {
   	if (strchr("0123456789",in[i]) == NULL)
      	return(&in[i]) ;}
   return(NULL) ; }

#define MAX_NUMBER 999999

char* single_numbers(char* in) {
	unsigned int i ;
   char* result = new char[strlen(in)*12] ;
   strcpy(result,"") ;
   for (i = 0 ; i < strlen(in) ; i++) {
   	switch (in[i]) {
      	case '0' : strcat(result,"Null ") ; break ;
      	case '1' : strcat(result,"Eins ") ; break ;
      	case '2' : strcat(result,"Zwei ") ; break ;
      	case '3' : strcat(result,"Drei ") ; break ;
      	case '4' : strcat(result,"Vier ") ; break ;
      	case '5' : strcat(result,"Fünf ") ; break ;
      	case '6' : strcat(result,"Sechs ") ; break ;
      	case '7' : strcat(result,"Sieben ") ; break ;
      	case '8' : strcat(result,"Acht ") ; break ;
      	case '9' : strcat(result,"Neun ") ; break ; } }
   delete(in) ;
   return(result) ; }

char* numeral(char* in) {
   long number = atol(in) ;
   if (number > MAX_NUMBER || number == 0L)
   	return(single_numbers(in)) ;
   long x ;
   char* result ;
   char* temp1 = NULL ;
   char* temp2 = NULL ;
   char* temp3 = NULL ;
   char* temp4 = NULL ;
   if (number > 999) {
      x = (number / 1000) ;
      temp1 = new char[12] ;
      sprintf(temp1,"%ld",x) ;
      temp1 = numeral(temp1) ;
      number = number % 1000 ; }
   if (number > 99) {
      x = (number / 100) ;
      temp2 = new char[12] ;
      sprintf(temp2,"%ld",x) ;
      temp2 = numeral(temp2) ;
      number = number % 100 ; }
   if (number > 19) {
   	x = (number / 10) ;
		switch (x) {
      	case 2: temp3 = "zwanzig" ; break ;
      	case 3: temp3 = "dreissig" ; break ;
      	case 4: temp3 = "vierzig" ; break ;
      	case 5: temp3 = "fünfzig" ; break ;
      	case 6: temp3 = "sechzig" ; break ;
      	case 7: temp3 = "siebzig" ; break ;
      	case 8: temp3 = "achtzig" ; break ;
      	case 9: temp3 = "neunzig" ; break ; }
      number = number % 10 ; }
   switch (number) {
   		case 0: temp4 = "" ; break ;
         case 1: temp4 = "ein"; break ;
      	case 2: temp4 = "zwei" ; break ;
      	case 3: temp4 = "drei" ; break ;
      	case 4: temp4 = "vier" ; break ;
      	case 5: temp4 = "fünf" ; break ;
      	case 6: temp4 = "sechs" ; break ;
      	case 7: temp4 = "sieben" ; break ;
      	case 8: temp4 = "acht" ; break ;
      	case 9: temp4 = "neun" ; break ;
   		case 10: temp4 = "zehn" ; break ;
         case 11: temp4 = "elf" ; break ;
      	case 12: temp4 = "zwölf" ; break ;
      	case 13: temp4 = "dreizehn" ; break ;
      	case 14: temp4 = "vierzehn" ; break ;
      	case 15: temp4 = "fünfzehn" ; break ;
      	case 16: temp4 = "sechzehn" ; break ;
      	case 17: temp4 = "siebzehn" ; break ;
      	case 18: temp4 = "achtzehn" ; break ;
      	case 19: temp4 = "neunzehn" ; break ; }
   int len = strlen(temp4)+30 ;
   if (temp3 != NULL)
   	len += strlen(temp3) ;
   if (temp2 != NULL)
   	len += strlen(temp2) ;
   if (temp1 != NULL)
   	len += strlen(temp1) ;
   result = new char[len+40] ;
  strcpy(result,"") ;   if (temp1 != NULL) {
   	if (strstr(temp1,"eins") != NULL)
      	temp1[strlen(temp1)-1] = '\0' ;
   	strcat(result,temp1) ;
   	strcat(result,"tausend ") ; }
   if (temp2 != NULL) {
   	if (strstr(temp2,"eins") != NULL)
      	temp2[strlen(temp2)-1] = '\0' ;
   	strcat(result,temp2) ;
   	strcat(result,"hundert ") ; }
   if (temp3 != NULL) {
   	if (strlen(temp4) > 2) {
	   	strcat(result,temp4) ;
   	        strcat(result,"und") ; }
      	strcat(result,temp3) ; }
   else {
   	strcat(result,temp4) ;
        if (strcmp(temp4,"ein") == 0)
      		strcat(result,"s") ; }
   if (temp2 != NULL)
   	delete(temp2) ;
   if (temp1 != NULL)
   	delete(temp1) ;
   delete(in) ;
   return(result) ; }

char* dnumeral(char* in) {
   long number = atol(in) ;
   if (number > MAX_NUMBER)
   	return(single_numbers(in)) ;
   long x ;
   char* result ;
   if (in[0] == '0' && in[1] == '0')
     {
       delete in ;
       result = new char[20] ;
       strcpy(result,"zweitausend") ;
       return result;
     }
   if (!(in[0] == '1' && in[1] != '0'))
     {
       return(numeral(in)) ;
     }


   char* temp1 = NULL ;
   char* temp2 = NULL ;
   char* temp3 = NULL ;
   char* temp4 = NULL ;
   temp1 = new char[4] ;
   temp2 = new char[4] ;

   strncpy(temp1,in,2) ;
   temp1[2] = '\0' ;
   strncpy(temp2,&in[2],2) ;
   temp2[2] = '\0' ;
   temp1 = numeral(temp1) ;
   temp2 = numeral(temp2) ;
   result = new char[strlen(temp1)+strlen(temp2)+12] ;
   strcat(strcat(strcpy(result,temp1),"hundert"),temp2) ;
   delete temp1 ;
   delete temp2 ;
   delete in ;
   return result ;
}

char* phone_number_prefix(char* in) {
	return(single_numbers(in)) ; }

char* international_phone_prefix(char* in) {
	char* temp = single_numbers(in) ;
   char* result = new char[strlen(temp)+60] ;
   strcpy(result,"Landesvorwahl : Null Null ") ;
   strcat(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }

char* phone_number(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strchr(temp,'/') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = single_numbers(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   end = single_numbers(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcpy(result,"") ;
   strcat(strcat(strcpy(result,start)," , "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* money_post(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strchr(temp,',') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = numeral(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   end = numeral(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcpy(result,"") ;
   strcat(strcat(strcpy(result,start)," Komma "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* money_pre(char* in) {
	return(money_post(in)) ; }

char* money_no_change(char* in) {
	return(numeral(in)) ; }

char* time(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strchr(temp,':') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = numeral(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   if (atol(end) == 0)
     strcpy(end,"") ;
   else
     end = numeral(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," Uhr "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }


char* time_before_Uhr(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strchr(temp,':') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+20] ;
   strcpy(start,temp) ;
   start = numeral(start) ;
   char* end = new char[strlen(p)+20] ;
   strcpy(end,p) ;
   if (atol(end) == 0)
     strcpy(end,"") ;
   else
     end = numeral(end) ;
       
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," Uhr "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* junk(char* in) {
   char* temp = new char[2] ;
   strcpy(temp,"") ;
   delete in ;
   return temp ; }

char* version(char* in) {
   char* temp = new char[2] ;
   strcpy(temp,"") ;
   char* p ;
   char* r ;
   char* t ;
   r = in ;
   while ((p = strchr(r,'.')) != NULL) {
		*p = '\0' ;
		t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
      t = numeral(t) ;
      temp = Realloc(temp,strlen(temp)+strlen(t)+10) ;
      strcat(temp,t) ;
      strcat(temp," Punkt ") ;
      delete(t) ;
      r = p+1 ; }
   t = new char[strlen(r)+2] ;
   strcpy(t,r) ;
   t = numeral(t) ;
   temp = Realloc(temp,strlen(temp)+strlen(t)+2) ;
   strcat(temp,t) ;
   delete(t) ;
	char* result = new char[strlen(temp)+1] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }


char* ordinal_fem(char* in) {
	char* temp = new char[strlen(in)+5] ;
   strcpy(temp,in) ;
   temp = numeral(temp) ;
   char* result = new char[strlen(temp)+8] ;
   strcpy(result,temp) ;
   if ((strncmp(&temp[strlen(temp)-2],"ig",2) == 0) ||
       (strncmp(&temp[strlen(temp)-4],"dert",4) == 0) ||
       (strncmp(&temp[strlen(temp)-4],"send",4) == 0))
   	strcat(result,"s") ;
   delete(temp) ;
   temp = strstr(result,"eins") ;
   if (temp != NULL) {
   	temp[1] = 'r' ;
      temp[2] = 's' ;
      temp[3] = '\0' ;}
   temp = strstr(result,"drei") ;
   if (temp != NULL && temp[4] == '\0') {
   	temp[2] = 'i' ;
      temp[3] = 't' ;
      temp[4] = '\0' ;}
   temp = strstr(result,"sieben") ;
   if (temp != NULL && temp[6] == '\0') {
      temp[4] = '\0' ;}
   strcat(result,"te") ;
   delete(in) ;
   return(result) ; }

char* ordinal_neutr(char* in) {
	char* temp = new char[strlen(in)+5] ;
   strcpy(temp,in) ;
   temp = ordinal_fem(temp) ;
   char* result = new char[strlen(temp)+8] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
	strcat(result,"r") ;
   return(result) ; }

char* countnumber(char* in) {
	char* temp = new char[strlen(in)+5] ;
   strcpy(temp,in) ;
   temp = ordinal_fem(temp) ;
   char* result = new char[strlen(temp)+8] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
	strcat(result,"ns") ;
   return(result) ; }

char* ordinal_dativ(char* in) {
	char* temp = new char[strlen(in)+5] ;
   strcpy(temp,in) ;
   temp = ordinal_fem(temp) ;
   char* result = new char[strlen(temp)+8] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
	strcat(result,"n") ;
   return(result) ; }

char* short_date(char* in) {
   char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strchr(temp,'.') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = ordinal_fem(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   end = ordinal_fem(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* short_date_flex(char* in) {
   char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   delete(in) ;
   char* p = strchr(temp,'.') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = ordinal_dativ(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   end = ordinal_dativ(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   return(result) ; }

char* full_date(char* in) {
   char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrchr(temp,'.') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = short_date(start) ;
   char* end = new char[strlen(p)+4] ;
   strcpy(end,p) ;
   end = dnumeral(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* full_date_flex(char* in) {
   char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrchr(temp,'.') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = short_date_flex(start) ;
   char* end = new char[strlen(p)+4] ;
   strcpy(end,p) ;
   end = dnumeral(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* colon_numbers(char* in) {
   char* temp = new char[2] ;
   strcpy(temp,"") ;
   char* p ;
   char* r ;
   char* t ;
   char* result ; 
   r = in ;
   while ((p = strchr(r,':')) != NULL) {
      *p = '\0' ;
      t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
      t = numeral(t) ;
      temp = Realloc(temp,strlen(temp)+strlen(t)+18) ;
      strcat(temp,t) ;
      strcat(temp," Doppelpunkt ") ;
      delete(t) ;
      r = p+1 ; }
   t = new char[strlen(r)+2] ;
   strcpy(t,r) ;
   t = numeral(t) ;
   temp = Realloc(temp,strlen(temp)+strlen(t)+2) ;
   strcat(temp,t) ;
   delete(t) ;
   result = new char[strlen(temp)+1] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }

char* real_number(char* in) {
   char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrchr(temp,',') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = numeral(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   end = single_numbers(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," Komma "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* real_number_with_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrchr(temp,'.') ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = numeral(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p) ;
   end = single_numbers(end) ;
   char* result = new char[strlen(start)+strlen(end)+12] ;
   strcat(strcat(strcpy(result,start)," Punkt "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* spell(char* in) {
   char* temp = new char[strlen(in)+1] ;
   strcpy(temp,"") ;
   char* r ;
   char* t ;
   r = in ;
   unsigned int i ;
   for (i=0 ; i < strlen(in) ; i++) {
   	if (strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ",in[i]) != NULL) {
		t = "gross " ;
		temp = Realloc(temp,strlen(temp)+strlen(t)+3) ;
   	   	strcat(temp,t) ; }
      	if (strchr("~-_@/",in[i]) != NULL) {
      		t = new char[20] ;
         	switch (in[i]) {
         		case '@': strcpy(t,"Ätt ,") ; break ;
         		case '/': strcpy(t,"Schrägstrich ,") ; break ;
         		case '~': strcpy(t,"Tilde, ") ; break ;
         		case '-': strcpy(t,"Bindestrich ,") ; break ;
         		case '_': strcpy(t,"Unterstrich ,") ; break ; 
			default : strcpy(t,"") ; } }
		else {
			t = new char[5] ;
   	   		t[0] = in[i] ;
      			t[1] = '\0' ;
	      		if(strchr("0123456789",in[i]) != NULL)
   	   			t = single_numbers(t) ;   }
	temp = Realloc(temp,strlen(temp)+strlen(t)+4) ;
      	strcat(temp,t) ;
      	strcat(temp," ") ;
      	delete(t) ; }
   char* result = new char[strlen(temp)+2] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }

char* street(char* in)
{  
   char* result = new char[strlen(in)+10] ;
   char* p = strstr(in,"str.") ;
   if (p == NULL)
     {
       delete[] result ;
       return in ;
     }
   p[0] = '\0' ;
   strcat(strcpy(result,in),"strasse") ;
   delete(in) ;
   return(result) ; }
   

char* email(char* in) {
   char* temp = new char[strlen(in)+1] ;
   strcpy(temp,"") ;
   char* p ;
   char* r ;
   char* t ;
   r = in ;
   while (strchr(r,'.') != NULL && strchr(r,'@') != NULL && strchr(r,'.') < strchr(r,'@'))
     {
      p =  strchr(r,'.') ; 
     *p = '\0' ;
      t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
      t = decom(t) ;
      temp = Realloc(temp,strlen(temp)+strlen(t)+18) ;
      strcat(temp,t) ;
      strcat(temp," , Punkt , ") ;
      delete(t) ;
      r = p+1 ; }
       
	 
   while ((p = strchr(r,'@')) != NULL) {
     *p = '\0' ;
      t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
      t = decom(t) ;
      temp = Realloc(temp,strlen(temp)+strlen(t)+18) ;
      strcat(temp,t) ;
      strcat(temp," Ätt ") ;
      delete(t) ;
      r = p+1 ; }
   while ((p = strchr(r,'.')) != NULL) {
     *p = '\0' ;
      t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
      t = decom(t) ;
      temp = Realloc(temp,strlen(temp)+strlen(t)+18) ;
      strcat(temp,t) ;
      strcat(temp," , Punkt , ") ;
      delete(t) ;
      r = p+1 ; }
   t = new char[strlen(r)+2] ;
   strcpy(t,r) ;
   t = decom(t) ;
   temp = Realloc(temp,strlen(temp)+strlen(t)+2) ;
   strcat(temp,t) ;
   delete(t) ;
   char* result = new char[strlen(temp)+1] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }

char* http_address(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   if (temp[strlen(temp)-1] == '/')
     temp[strlen(temp)-1] = '\0' ;
   char* p = strrchr(temp,':') ;
   if (p == NULL)
     {
       delete(in) ;
       return(email(temp)) ;
     }
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+5] ;
   strcat(strcpy(start,temp)," ,") ;
   start = spell(start) ;
   char* end = new char[strlen(p)+2] ;
   strcpy(end,p+2) ;
   end = email(end) ;
   char* result = new char[strlen(start)+strlen(end)+20] ;
   strcat(strcat(strcpy(result,start)," "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* computer_address(char* in) {
	return(email(in)) ; }

char* unit(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   delete(in) ;
	return(temp) ; }

char* divide(char* in) {
	char* result = new char[20] ;
   strcpy(result,"Schrägstrich") ;
	delete(in) ;
   return(result) ; }

char* equals(char* in) {
	char* result = new char[20] ;
   strcpy(result,"ist gleich") ;
	delete(in) ;
   return(result) ; }

char* minus(char* in) {
	char* result = new char[20] ;
   strcpy(result,"strich") ;
	delete(in) ;
   return(result) ; }

char* plus(char* in) {
	char* result = new char[20] ;
   strcpy(result,"plus") ;
	delete(in) ;
   return(result) ; }

char* sign(char* in) {
	char* result = new char[20] ;
   strcpy(result,"") ;
	delete(in) ;
   return(result) ; }

char* percent(char* in) {
	char* result = new char[20] ;
   strcpy(result,"Prozent") ;
	delete(in) ;
   return(result) ; }

char* ando(char* in) {
	char* result = new char[20] ;
   strcpy(result,"und") ;
	delete(in) ;
   return(result) ; }

char* dollar(char* in) {
	char* result = new char[20] ;
   strcpy(result,"Dollar") ;
	delete(in) ;
   return(result) ; }

char* at(char* in) {
	char* result = new char[20] ;
   strcpy(result,"Klammeraffe") ;
	delete(in) ;
   return(result) ; }

char* bracket(char* in) {
	char* result = new char[20] ;
   if (in[0] == '(')
	   strcpy(result,"Klammer auf ,") ;
   else
   	strcpy(result,"Klammer zu ,") ;
	delete(in) ;
   return(result) ; }


char* arithmetic(char* in) {
   char* temp = new char[2] ;
   strcpy(temp,"") ;
   char* p ;
   char* r ;
   char* t ;
   char v ;
   r = in ;
   while ((p = strfind(r,"+-*/=")) != NULL) {
   	v = *p ;
		*p = '\0' ;
		t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
      t = numeral(t) ;
      temp = Realloc(temp,strlen(temp)+strlen(t)+20) ;
      strcat(temp,t) ;
      switch(v) {
      	case '+' : strcat(temp," plus ") ; break ;
      	case '-' : strcat(temp," strich ") ; break ;
      	case '*' : strcat(temp," mal ") ; break ;
      	case '/' : strcat(temp," geteilt durch ") ; break ;
      	case '=' : strcat(temp," ist gleich ") ; break ; }
      delete(t) ;
      r = p+1 ; }
	t = new char[strlen(r)+2] ;
   strcpy(t,r) ;
   t = numeral(t) ;
   temp = Realloc(temp,strlen(temp)+strlen(t)+2) ;
   strcat(temp,t) ;
   delete(t) ;
	char* result = new char[strlen(temp)+2] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }

char* numeral_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = numeral(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* word_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* short_date_flex_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = short_date_flex(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* short_date_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = short_date(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* full_date_flex_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = full_date_flex(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* full_date_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = full_date(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* real_number_before_point(char* in) {
	char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = real_number(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }

char* colon_numbers_before_point(char* in) {
   char* temp = new char[strlen(in)+2] ;
   strcpy(temp,in) ;
   char* p = strrfind(temp,".,;:?!") ;
   char v = *p ;
   *p = '\0' ;
   p++ ;
   char* start = new char[strlen(temp)+2] ;
   strcpy(start,temp) ;
   start = colon_numbers(start) ;
   char* result = new char[strlen(start)+8] ;
   char* end = new char[7] ;
   sprintf(end," %c ",v) ;
   strcat(strcpy(result,start),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }


char* number_mixture(char* in) {
   char* temp = new char[strlen(in)+1] ;
   strcpy(temp,"") ;
   char* p ;
   char* r ;
   char* t ;
   char store ;
   r = in ;
   while ((p = find_number(r)) != NULL) {
		if (p != r) {
	   	store = *p ;
   	  *p = '\0' ;
      	t = new char[strlen(r)+2] ;
	      strcpy(t,r) ;
   	   temp = Realloc(temp,strlen(temp)+strlen(t)+8) ;
      	strcat(temp,t) ;
	      strcat(temp," ") ;
   	   delete(t) ;
	      *p = store ;
	      r = p ; }
      if ((p = find_non_number(r)) != NULL) {
	   	store = *p ;
   	  *p = '\0' ;
      	t = new char[strlen(r)+2] ;
	      strcpy(t,r) ;
         t = numeral(t) ;
	      temp = Realloc(temp,strlen(temp)+strlen(t)+8) ;
	      strcat(temp,t) ;
	      strcat(temp," ") ;
	      delete(t) ;
	      *p = store ;
	      r = p ; }
      else {
      	t = new char[strlen(r)+2] ;
	      strcpy(t,r) ;
         t = numeral(t) ;
	      temp = Realloc(temp,strlen(temp)+strlen(t)+8) ;
	      strcat(temp,t) ;
	      strcat(temp," ") ;
	      delete(t) ;
         *r = '\0' ; } }
   if (strlen(r) > 0) {
     	t = new char[strlen(r)+2] ;
      strcpy(t,r) ;
  	   temp = Realloc(temp,strlen(temp)+strlen(t)+8) ;
     	strcat(temp,t) ;
      strcat(temp," ") ;
  	   delete(t) ; }
   char* result = new char[strlen(temp)+1] ;
   strcpy(result,temp) ;
   delete(temp) ;
   delete(in) ;
   return(result) ; }

