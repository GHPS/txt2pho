#ifndef __MATRIXH__
#define __MATRIXH__

#include <iostream.h>

class vector;

class matrix
{
private:
  int     row;
  int     column;
  static double  prand = 1;
  float **values;
public:
  friend ostream & operator << (ostream &, const matrix &);
  matrix();
  matrix(const matrix &);
  matrix(const vector &);
  matrix(const int);
  matrix(const int, const int);
  ~matrix();

  matrix & operator =  (const matrix &);
  bool     operator == (const matrix &);
  bool     operator != (const matrix &);
  matrix   operator *  (const matrix &);
  matrix & operator *= (const matrix &);
  matrix   operator +  (const matrix &);
  matrix & operator += (const matrix &);
  matrix   operator -  (const matrix &);
  matrix & operator -= (const matrix &);
  matrix   operator !  ();
  float  & operator () (const int, const int);
  float    operator () (const int, const int) const;

  void     InitRandom  (const int, const int);
  int      Row()    const { return row;    }
  int      Column() const { return column; }
};

#endif
