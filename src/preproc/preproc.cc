/* Copyright (C) 1998  Thomas Portele


*/
#include "PPRullst.h"
#include "PPInput.h"
#include "PPAbblst.h"
#include "PPFnclst.h"
#include <string.h>
#include <unistd.h>

FILE* errfile ;

int main(int argc, char** argv) {

	PPFunctionlist fl ;
	PPRulelist* rl ;
   PPAbbreviationlist* al ;
   char namebuffer[256] ;
   char* xinput ;
   char* output ;
   int g ;

   char pid[32] ;
   sprintf(pid,"%d",getpid()) ;
   char errfilename[512] ;
   strcat(strcat(strcpy(errfilename,"/tmp/preproc"),pid),".log") ;
   errfile = fopen(errfilename,"w") ;

   PPInput ip("-","()&\%") ;

   FILE* abbfile = NULL ;
   al = NULL ;

   if (argc < 2) {
   	fprintf(stdout,"Usage: preproc Rules-File <Abbreviations-File> | read from stdin, write to stdout\n") ;
		return(1) ; }

   FILE* rlfile = fopen(argv[1],"r") ;
   if (rlfile == NULL) {
   	fprintf(stderr,"Cannot open Rules-File %s\n",argv[1]) ;
      return(2) ; }

   if (argc > 2) {
   	abbfile = fopen(argv[2],"r") ;
	   if (abbfile == NULL) {
	   	fprintf(stderr,"Cannot open Abbreviations-File %s\n",argv[2]) ; } }

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

fprintf(errfile,"-%s-",&xinput[g]) ;
fflush(errfile) ;
	output = rl->apply(xinput,g) ;
fprintf(errfile,"-%s-",output) ;
fflush(errfile) ;
      	if (al != NULL)
      		output = al->apply(output) ;
fprintf(errfile,"-%s-",output) ;
fflush(errfile) ;
     	output = fl.call(output) ;
fprintf(errfile,"-%s-",output) ;
fflush(errfile) ;
	if (strlen(output) < 1) {
		delete(output) ;
		continue ; }
fprintf(errfile,"-%s\n",output) ;
fflush(errfile) ;
	p = output[strlen(output)-1] ;
        output[strlen(output)-1] = '\0' ;
      	fprintf(stdout,"%s",output) ;
        if (strchr(",.;:?!",p) != NULL)
        	fprintf(stdout," ") ;
        fprintf(stdout,"%c ",p) ;
        if (strchr(".:?!",p) != NULL)
        	fprintf(stdout,"\n") ;
      	delete(output) ; }
   if (al != NULL)
   	delete(al) ;
   delete(rl) ;
   fclose(errfile) ;
   unlink(errfilename) ;
   return(0) ; }








