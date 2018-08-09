
#include "lisatalk.h"
#include "hannwin.src"


unsigned short* get_win(int length, int slope) {


	unsigned short* result = new unsigned short[length] ;
	if (result == NULL) {
//		printf("out of heap\n") ;
		exit(0) ; }
	unsigned short* source ;
	int i, j ,diff ;
	if (length >= winlen[28])
		i = 29 ;
	else
		for (i=0; length>=winlen[i] ; i++) ;
	diff = length - winlen[--i] ;
	if (i == -1) {
		source = (unsigned short*)hann1[0] ;
		for (j=0 ; j < length ; j++)
			result[j] = source[(int)((float)j*37.0/(float)length)] ;
		return(result) ; }
	source = (unsigned short*)(i<18 ? hann1[i] : (i < 25 ? hann2[i-18] : hann3[i-25])) ;
	switch (slope) {
		case 1 : for (j = 0 ; j < diff/2 ; result[j++] = 65535) ;
					memcpy(&result[j],source,winlen[i]*sizeof(unsigned short)) ;
					for(j+= winlen[i]; j < length; result[j++] = 0) ;
					break ;
		case -1 : for (j = length-1 ; j >= winlen[i] ; result[j--] = 65535) ;
//					printf("neg slope\n") ;
					while (j >= 0) {
						result[j] = source[winlen[i]-1-j]  ;
						j-- ; }
					break ;
	default: /*printf("Wrong slope %d\n",slope) ; */exit(1) ; }
	return(result) ; }




