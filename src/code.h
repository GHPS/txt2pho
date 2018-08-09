#ifndef __CODE_H_
#define __CODE_H_
#include "rtab.h"

inline unsigned char decode(unsigned char in) {
	if (in == 0 || in == 10 || in == 13 || in == 255)
		return(in) ;
	return(randlist[in]) ; }


#endif



