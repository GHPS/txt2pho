#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#include <dos.h>
#include "lisalib.h"

SECURITY_ATTRIBUTES sa;

static short dumm[8192] ;

int thread ;

int text(char*& in) {
	long i,counter = 64000 ;
   char* zeichen="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz01234556789!\"'(),-.:;?∞#$%&*+/<=>@[\\]^_`|~≤≥‰ˆ¸ƒ÷‹ﬂ";
   char c ;

//   randomize() ;

   for (i=0L; i < 130 ; i++) {
   	c = random(strlen(zeichen)) ;
   	in[i] = zeichen[c] ;
      if ((i+1)%128L == 0L) {
      	in[i++] = '.' ;
         in[i++] = ' ' ;
         in[i] = '\0' ; }
      }

   return(0) ; }

DWORD WINAPI ThreadFunc(LPVOID s) {
		int synhandle = *((long*)s) ;
		char name[256] ;
		long wpl[2048] ;
      int wnr ;
      char** wc = (char**)malloc(1) ;
      int i = 0 ;
      char* dummy ;
      char dummr[2048] ;
      i=0 ;
      int j ;
      switch(synhandle) {
      	case 0: dummy = "Dies ist Thread Null . Dampflos . " ; break ;
         case 1: dummy = "Dies ist Thread Eins . Katastrophenmanagement . " ; break ; }
      printf("synhandle %d\n",synhandle) ;
	   sprintf(name,"hadi%ld.wav",synhandle) ;
      while (i < 400) {
      	i++ ;
	      text(dummr) ;
	      printf("%d %ld %d\n",Lisa_lies_satz(name,dummy,wpl,0,NULL,&wnr,&wc,(int)synhandle),synhandle,i) ;
/*			for (j=0 ; j < wnr ; j++)
         	printf("%6d: %10ld %s\n",j,wpl[j+1],wc[j]) ;
			printf("%ld words\n",wpl[0]) ;
*/			Lisa_loesche_wortliste(wnr,wc) ;
			wc = (char**) malloc(1) ;
         if (synhandle < 0)
         	PlaySound(name,NULL,SND_SYNC) ; }
      thread-- ;
      return(synhandle) ; }


int main() {

	FILE* trace = fopen("lisa.trc","w") ;
	long result[2048] ;
	int i ;
	long speakhandle = LisaInit(".\\") ;
   long laberhandle = LisaInit(".\\") ;
	int wwc ;
   char dummy[256] ;
   char** wwl = (char**)malloc(0) ;
   DWORD ta,tb ;
   Lisa_waehle_stimme("horst","d:\\hadivoic\\",laberhandle) ;
   HANDLE a,b ;
	sa.nLength = sizeof(SECURITY_ATTRIBUTES) ;
   sa.lpSecurityDescriptor = NULL ;
   sa.bInheritHandle=FALSE ;


	printf("%d %d\n",laberhandle,speakhandle) ;

   sprintf(dummy,"Dampflos . ") ;

//	char* drummy = "Hallo . Dies ist Thread 0 . Dampflos . " ;
//   for (int i=0 ; i < 5000 ; i++)
//	      printf("%d %ld %d\n",Lisa_lies_satz("hadi9.wav",drummy,NULL,1,NULL,NULL,NULL,(int)laberhandle),laberhandle,i) ;


   a = CreateThread(&sa,0,&(ThreadFunc),&speakhandle,0,&ta) ;
   b = CreateThread(&sa,0,&(ThreadFunc),&laberhandle,0,&tb) ;

   thread = 2 ;
   while (thread > 0) ;

	LisaClose(speakhandle) ;
   LisaClose(laberhandle) ;
	fclose(trace) ;

   printf("Hallo") ;

   return(0) ;

   while (1) {
      text(dummy) ;
      printf("%d %d\n",Lisa_lies_satz("hadi3.wav",dummy,NULL,0,NULL,NULL,NULL, laberhandle),laberhandle) ;
		printf("%d %d\n",Lisa_lies_satz("hadi2.wav",dummy,NULL,0, NULL, NULL, NULL, speakhandle ),speakhandle) ; }
	fprintf(trace,"%ld words\n",result[0]) ;
	for (i = 1 ; i < result[0]+1 ; i++) {
		fprintf(trace,"%ld %s\n",result[i],wwl[i-1]) ;
      fflush(trace) ;  }
	Lisa_loesche_wortliste(wwc,wwl) ;
	Lisa_lies_schneller() ;
	Lisa_lies_schneller() ;
	Lisa_lies_monotoner() ;
	Lisa_lies_monotoner() ;
	Lisa_satzzeichen_ein() ;
	Lisa_lies_satz("hadi1.wav","., aus.") ;
	Lisa_satzzeichen_aus() ;
	Lisa_setze_startwerte() ;
	Lisa_vorverarbeitung("demo.txt","tes3.vv") ;
   char buffer[8192] ;
	FILE* infile = fopen("tes3.vv","r") ;
   i = 0;
   while (!feof(infile)) {
   	buffer[i++] = fgetc(infile) ;
      if (buffer[i-1] == '.') {
      	buffer[i] = '\0' ;
         i = 0 ;
         Lisa_lies_satz("demo.wav",buffer, result, 1) ;
			fprintf(trace,"%ld words\n",result[0]) ;
			fflush(trace) ; } }
   fclose(infile) ;
	LisaClose(speakhandle) ;
   LisaClose(laberhandle) ;
   fprintf(trace,"LISA CLOSED\n") ;
	fclose(trace) ;
	return(1) ; }
