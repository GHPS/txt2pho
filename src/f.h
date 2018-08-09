/*********************************************************
  f.h
  --------------------------------------------------------
  generated at Tue Jun 23 14:49:26 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int f(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} fREC = {27,1,f};
