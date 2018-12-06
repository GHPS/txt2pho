/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

#ifndef __CODE_H_
#define __CODE_H_
#include "rtab.h"

inline unsigned char decode(unsigned char in) {
	if (in == 0 || in == 10 || in == 13 || in == 255)
		return(in) ;
	return(randlist[in]) ; }


#endif



