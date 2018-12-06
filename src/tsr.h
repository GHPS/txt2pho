/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

#ifndef __TSR_H__
#define __TSR_H__

class TSR {

  float** parameters ;
  int coeffnr ;
  int nodenr ;
  int* splitcoeffs ;
  float* splitvals ;
  int** sons ;

public:

  TSR(const char* tsrfilename, const char* path) ;

  ~TSR() ;

  int get_coeffnr() ;

  float compute(float* invals, int actnode) ; } ;

#endif
