/*********************************************************
  oo.h
  --------------------------------------------------------
  generated at Fri Jun  5 17:58:30 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int oo(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} ooREC = {30,1,oo};
