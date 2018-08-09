#include <stdio.h>
#include <windows.h>
#include "hadilib.h"

int main(int argc, char** argv) {

	if (argc < 3) {
   	printf("Usage: hadifix <text file> <wave file>\n") ;
      return(-1) ; }
   HadiInit() ;
 	HadiSynthesizeBrutal(argv[2],argv[1]) ;
   HadiClose() ;

	return(1) ; }

