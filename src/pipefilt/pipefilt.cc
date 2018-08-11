#include <stdio.h>
#include <stdlib.h>

int isspace(char u) {
	if (u == (char)13 || u == (char)9 || u == (char)10 || u == (char)32 || u == (char)0)
		return(1) ;
	return(0) ; }

int ispoint(char u) {
	if (u == '.' || u == ';' || u == '!' || u == ':')
		return(1) ;
	return(0) ; }


int main() {
	
        setvbuf(stdin, NULL, _IOLBF, BUFSIZ);
        setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
	
	char a,b ;
	a =getchar() ;
	while (!feof(stdin)) {
		b = getchar() ;
		if (ispoint(a) && isspace(b)) { 
			printf("%c\n",a) ;
			a = getchar() ;
			continue ; }
		if (isspace(a)) {
			printf(" ") ;
			a = b ;
			continue ; }
		printf("%c",a) ;
		a = b ; }
	printf("%c\n",b) ;
	return(0) ; }					
