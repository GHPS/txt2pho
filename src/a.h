/*********************************************************
  aa.h
  --------------------------------------------------------
  generated at Fri Jun  5 17:40:56 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int a(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} aREC = {30,1,a};
