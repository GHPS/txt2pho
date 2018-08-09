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

  TSR(char* tsrfilename, char* path) ;

  ~TSR() ;

  int get_coeffnr() ;

  float compute(float* invals, int actnode) ; } ;

#endif
