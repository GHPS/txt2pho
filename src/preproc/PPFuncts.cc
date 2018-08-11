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
#include <ctype.h>
#include "PPdebug.h"
#include "PPNumbers.h"
#include "PPFuncts.h"

#define MAX_UNIT_LENGTH	20
#define MAX(a,b) ((a)>(b)?(a):(b))

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

char* single_numbers(char* in) {
	size_t i;
   char* result = new char[strlen(in)*7];	// 'sieben' is the longest digit + single space
   char* p = result;

	for (i = 0 ; i < strlen(in) ; i++) {
		p = digit2txt (p, in[i] - '0');
		strcpy (p++, " ");
	}
	delete (in);
	return (result);
}

char* numeral(char *in) {
	char *p = in;
	char *temp1, *temp2, *q;
	char *result;
	char c;
	int approx_len = 0, trailer_len;

   	temp1 = q = new char[strlen (in)+1];
	
	for (c = *p; (c >= '0' && c <= '9'); c = *++p) {
		*q++ = c;
		approx_len += 15;	// this should be enough per digit
	}
	*q = '\0';

	result = new char[approx_len + MAX(strlen (p), MAX_UNIT_LENGTH) + 1];
	if (number2txt (result, temp1) == NULL) {
		delete (result);
		return (single_numbers (in));
	}
	delete (temp1);

	if ((trailer_len = strlen (p)) > 0) {
		temp1 = new char[trailer_len+1];
		strcpy (temp1, p);
		temp2 = unit (temp1);
		if (temp1 != temp2) {
			strcat (result, " ");
		}
		strcat (result, temp2);
		delete (temp2);
	}

	delete (in);

	return (result);
}

char* dnumeral(char* in) {
   char *result;
	char *ext = in;
	char *dnum, *p;

	dnum = p = new char [strlen(in)+1];
	while (*ext >= '0' && *ext <= '9') {
		*p++ = *ext++;
	}
	*p = '\0';

   if ((strlen (dnum) != 4) || (!(dnum[0] == '1' && dnum[1] != '0'))) {
		char *temp;
		result = temp = numeral(dnum);
		if (*ext) {
   		result = new char[strlen(temp)+strlen(ext)+1];
		   strcat(strcpy(result, temp), ext);
		}
		return (result);
   }

   char* temp1 = new char[3];
   strncpy(temp1,dnum,2);
   temp1[2] = '\0';
   temp1 = numeral(temp1);

   char* temp2 = new char[3];
   if (!strcmp (&dnum[2], "00")) {
	   temp2[0] = '\0';
   } else {
   	strcpy(temp2,&dnum[2]);
		temp2 = numeral(temp2);
	}

   result = new char[strlen(temp1)+7+strlen(temp2)+strlen(ext)+1];
   strcat(strcat(strcat(strcpy(result, temp1), "hundert"), temp2), ext);

   delete (dnum);
   delete (temp1);
   delete (temp2);
   delete (in);

   return (result);
}

#define RANGE_LONG	1
#define RANGE_SMALL	2

char* dnumeral_range(char* in) {
	char *temp1 = new char[5] ;
	char *temp2 = new char[5] ;
	char *from, *to, *result;
	int range_type;

	if (to = strchr (in, '-')) {
		range_type = RANGE_LONG;
	} else if (to = strchr (in, '/')) {
		range_type = RANGE_SMALL;
	} else {
		return (in);
	}
	*to++ = '\0';
	
	strncpy (temp1, in, 5);
	strncpy (temp2, to, 5);

	from = dnumeral (temp1);
	to   = dnumeral (temp2);

	if (range_type == RANGE_LONG) {
		result = new char [strlen(from)+5+strlen(to)+1];
		strcat(strcat(strcpy (result, from), " bis "), to);
	} else {
		result = new char [strlen(from)+1+strlen(to)+1];
		strcat(strcat(strcpy (result, from), " "), to);
	}

	delete (in); delete (from); delete (to);
	return (result);
}

char* fraction(char* in) {
	char *denominator;
	char *temp1, *temp2;
	char *result;

	denominator = strchr (in, '/');
	*denominator++ = '\0';
	
	temp1 = new char [strlen (in) * 15];
	temp2 = new char [strlen (denominator) * 15];

	if (in[0] == '1' && in[1] == '\0') {
		strcpy (temp1, "ein");
	} else {
		number2txt(temp1, in);
	}
	denominator2txt(temp2, denominator);

	result = new char [strlen(temp1)+2+strlen(temp2)+1];
	strcat(strcpy (result, temp1), " ");
	if (!strncmp ("ein", temp2, 3)) {
		strcat(result, strchr (temp2, ' ') + 1);
	} else {
		strcat(result, temp2);
	}

	delete (in); delete (temp1); delete (temp2);
	return (result);
}

char* ratio(char* in) {
	char *r2, *temp1, *temp2, *result;

	r2 = strchr (in, ':');
	*r2++ = '\0';
	
	temp1 = new char [strlen (in) * 15];
	temp2 = new char [strlen (r2) * 15];

	number2txt(temp1, in);
	number2txt(temp2, r2);
	
	result = new char [strlen(temp1)+4+strlen(temp2)+1];
	strcat(strcat(strcpy (result, temp1), " zu "), temp2);

	delete (in); delete (temp1); delete (temp2);
	return (result);
}

char* thousands_separated_number(char* in) {
	int offset = 0;
	int in_len = strlen(in)+1;
	char *p = in;
	while (in_len--) {
		if (*p == '.' && in_len >= 4 && isdigit (*(p+1)) && isdigit (*(p+2)) && isdigit (*(p+3))) {
			offset++;
		} else if (offset) {
			*(p-offset) = *p;
		}
		p++;
	}
	return (numeral(in));
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
   end = numeral(end) ;
   char* result = new char[strlen(start)+strlen(end)+10] ;
   strcat(strcat(strcpy(result,start)," Uhr "),end) ;
   delete(temp) ;
   delete(start) ;
   delete(end) ;
   delete(in) ;
   return(result) ; }


char* time_before_Uhr(char* in) {
	return(time(in)) ; }

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
	char *p;
	char *temp;

	if ((p = strchr (in, '.'))) {
		*p = '\0';
	} else {
		return (in);	// this doesn't look like an ordinal
	}
   temp = numeral(in) ;
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
   return(result) ;
}

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
   if (end[0] == '0' && end[2] == '\0') {
		end = single_numbers(end) ;
	} else {
	   end = dnumeral(end) ;
	}
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
   if (end[0] == '0' && end[2] == '\0') {
		end = single_numbers(end) ;
	} else {
	   end = dnumeral(end) ;
	}
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
	int unit;
	int offset = 0;
	char *result = new char[MAX_UNIT_LENGTH] ;
	char *ptr_punctuation, punctuation;

	if (strchr(",.;:?!", *(ptr_punctuation = in+strlen(in)-1))) {
		punctuation = *ptr_punctuation;	// save punctuation to append it later
		*ptr_punctuation = '\0';
	} else {
		punctuation = '\0';
	}

	result[0] = '\0';
	if (strlen (in) > 1) {
		offset = 1;	
		switch (in[0]) {
			case 'p':
				strcpy (result, "piko");
				break;
			case 'n':
				strcpy (result, "nano");
				break;
			case 'µ': /* will this always work? */
				strcpy (result, "mikro");
				break;
			case 'm':
				strcpy (result, "milli");
				break;
			case 'c':
				strcpy (result, "zenti");
				break;
			case 'd':
				strcpy (result, "dezi");
				break;
			case 'h':
				strcpy (result, "hekto");
				break;
			case 'k':
			case 'K': /* this is not correct, but widely used */
				strcpy (result, "kilo");
				break;
			case 'M':
				strcpy (result, "mega");
				break;
			case 'G':
				strcpy (result, "giga");
				break;
			case 'T':
				strcpy (result, "tera");
				break;
			default:
				offset = 0;
		}
	}

	do {
		unit = 1;
		if (in[offset+1] == '\0') {
			switch (in[offset]) {
				case 'g':
					strcat (result, "gramm");
					break;
				case 't':
					strcat (result, "tonne");
					break;
				case 'm':
					strcat (result, "meter");
					break;
				case 'l':
					strcat (result, "liter");
					break;
				case 's':
					strcat (result, "sekunde");
					break;
				case 'h':
					strcat (result, "stunde");
					break;
				case 'b':
					strcat (result, "bel");
					break;
				case 'J':
					strcat (result, "joule");
					break;
				case 'p':
					strcat (result, "pond");
					break;
				case 'N':
					strcat (result, "newton");
					break;
				case 'A':
					strcat (result, "ampere");
					break;
				case 'U':
					strcat (result, "umdrehungen");
					break;
				case 'V':
					strcat (result, "volt");
					break;
				case 'W':
					strcat (result, "watt");
					break;
				case 'B':
					strcat (result, "byte");
					break;
				case '°':
					strcat (result, "grad");
					break;
				case 'v':
					// Ohh, this is so ugly...
					// Because of the rule "U*E AFTER Z AS unit" the phrase "v. Chr."
					// ends up here. I don't like this!
					if (punctuation) {
						strcat (result, "vor");
						punctuation = '\0';
					}
					break;
				case 'n':
					// Ohh, this is so ugly...
					// Because of the rule "U*E AFTER Z AS unit" the phrase "n. Chr."
					// ends up here. I don't like this!
					if (punctuation) {
						strcat (result, "nach");
						punctuation = '\0';
					}
					break;
				default:
					unit = 0;
			}
		} else {
			if (!strcmp (in+offset, "Bit")) {
				strcat (result, "bit");
			} else if (!strcmp (in+offset, "Byte")) {
				strcat (result, "byte");
			} else if (!strcmp (in+offset, "cal")) {
				strcat (result, "kalorie");
			} else if (!strcmp (in+offset, "Hz")) {
				strcat (result, "hertz");
			} else if (!strcmp (in+offset, "Nm")) {
				strcat (result, "newtonmeter");
			} else if (!strcmp (in+offset, "bar")) {
				strcat (result, "bar");
			} else if (!strcmp (in+offset, "Std")) {
				strcat (result, "stunde");
			} else if (!strcmp (in+offset, "°C")) {
				strcat (result, "grad celsius");
			} else if (!strcmp (in+offset, "m²")) {
				char *temp = new char[MAX_UNIT_LENGTH] ;
				strcpy (temp, "quadrat");
				strcat (temp, result);
				strcat (temp, "meter");
				delete (result);
				result = temp;
			} else if (!strcmp (in+offset, "Min")) {
				strcat (result, "minute");
			} else {
				unit = 0;
			}
		}
		if (!unit) {
			offset--;
			result[0] = '\0';
		}
	} while (!unit && offset == 0);
	if (strlen(result) == 0) {
		delete (result);
		if (punctuation)
			*ptr_punctuation = punctuation;
		return (in);
	}
   if (punctuation) {
		char temp[2];
		temp[0] = punctuation; temp[1] = '\0';
		strcat (result, temp);
	}
   delete(in);
	return(result);
}

char* unit_per(char* in) {
	char *temp;
	char *temp1, *temp2, *result;

	*(temp = strchr (in, '/')) = '\0';

	temp1 = new char[strlen(in)+1];
	temp2 = new char[strlen(temp+1)+1];
	strcpy (temp1, in);
	strcpy (temp2, temp+1);

	temp1 = unit (temp1);
	temp2 = unit (temp2);

	result = new char[strlen(temp1)+5+strlen(temp2)+1];

	strcpy (result, temp1);
	strcat (result, " pro ");
	strcat (result, temp2);

	delete (temp1);
	delete (temp2);
	delete (in);
	return (result);
}

char* divide(char* in) {
	char* result = new char[20] ;
   strcpy(result,"geteilt durch") ;
	delete(in) ;
   return(result) ; }

char* times(char* in) {
	char* result = new char[20] ;
   strcpy(result,"mal") ;
	delete(in) ;
   return(result) ; }

char* equals(char* in) {
	char* result = new char[20] ;
   strcpy(result,"ist gleich") ;
	delete(in) ;
   return(result) ; }

char* minus(char* in) {
	char* result = new char[20] ;
   strcpy(result,"minus") ;
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

char* paragraph(char* in) {
	char* result = new char[20] ;
   strcpy(result,"Paragraph") ;
	delete(in) ;
   return(result) ; }

char* ando(char* in) {
	char* result = new char[20] ;
   strcpy(result,"und") ;
	delete(in) ;
   return(result) ; }

char* euro(char* in) {
	char* result = new char[20] ;
   strcpy(result,"Euro") ;
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
	char* result = new char[30] ;
   if (in[0] == '(')
	   strcpy(result,"Klammer auf ,") ;
   else
   	strcpy(result,"Klammer zu ,") ;
   delete(in) ;
   return(result) ; }

char* dash(char* in) {
	char *result;
	char *dash;
	dash = strchr(in, '-');
	*dash = '\0';
	while (*++dash == '-');
	result = new char[strlen(in)+3+strlen(dash)+1];
	*result = '\0';
	if (*in != '\0') {
		strcat(result, in);
		strcat(result, " ");
	}
	strcat(result, ",");
	if (*dash != '\0') {
		strcat(result, " ");
		strcat(result, dash);
	}
	delete(in);
	return(result);
}

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
      	case '-' : strcat(temp," minus ") ; break ;
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

