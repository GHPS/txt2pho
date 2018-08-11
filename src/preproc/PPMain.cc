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
#include "PPInput.h"
#include "PPAbblst.h"
#include "PPFnclst.h"
#include <string.h>
#include <unistd.h>

extern FILE* errfile ;

int PPmain(char* rulefilename, char* abbfilename, char* infilename, char* outfilename) {

	PPFunctionlist fl ;
	PPRulelist* rl ;
   PPAbbreviationlist* al ;
   char* xinput ;
   char* output ;
   int g ;

   PPInput ip(infilename,"()&%") ;

   FILE* abbfile = NULL ;
   al = NULL ;

   FILE* outfile = fopen(outfilename,"w") ;

   FILE* rlfile = fopen(rulefilename,"r") ;
   if (rlfile == NULL) {
   	fprintf(errfile,"Cannot open %s\n",rulefilename) ;
      return(2) ; }

   if (abbfilename != NULL) {
   	abbfile = fopen(abbfilename,"r") ;
	   if (abbfile == NULL) {
	   	fprintf(errfile,"Cannot open %s\n",abbfilename) ; } }

   char p ;
   char* n ;
   rl = new PPRulelist(rlfile) ;
   fclose(rlfile) ;

   if (abbfile != NULL) {
		al = new PPAbbreviationlist(abbfile) ;
      fclose(abbfile) ; }

   while ((xinput = ip.get_next_token_with_lookahead(g)) != NULL) {
      if (strncmp(&xinput[g],"{UsePrepocRules:",16) == 0) {
      	n = strchr(&xinput[g],'}') ;
         if (n != NULL) {
         	p = *n ;
            n[0] = '\0' ;
            rlfile = fopen(&xinput[g+16],"r") ;
            if (rlfile != NULL) {
            	delete(rl) ;
				   rl = new PPRulelist(rlfile) ;
					rl->list(errfile) ;
				   fclose(rlfile) ; } } }
      if (strncmp(&xinput[g],"{UseAbbreviationList:",21) == 0) {
      	n = strchr(&xinput[g],'}') ;
         if (n != NULL) {
         	p = *n ;
            n[0] = '\0' ;
            abbfile = fopen(&xinput[g+21],"r") ;
            if (abbfile != NULL) {
            	if (al != NULL)
	            	delete(al) ;
				   al = new PPAbbreviationlist(abbfile) ;
				   fclose(abbfile) ; } } }
	output = rl->apply(xinput,g) ;

	//	fprintf(stderr,"%s\n",output) ;

 	if (al != NULL) 
      		output = al->apply(output) ;

	//	fprintf(stderr,"%s\n",output) ;

     	output = fl.call(output) ;

	if (strlen(output) < 1) {
		delete(output) ;
		continue ; }

	p = output[strlen(output)-1] ;
        output[strlen(output)-1] = '\0' ;
      	fprintf(outfile,"%s",output) ;
        if (strchr(",.;:?!",p) != NULL)
        	fprintf(outfile," ") ;
        fprintf(outfile,"%c ",p) ;
        if (strchr(".;?!",p) != NULL)
        	fprintf(outfile,"\n") ;
      	delete(output) ; }
   if (al != NULL)
   	delete(al) ;
   delete(rl) ;
   fclose(outfile) ;
   return(0) ; }








