/*********************************************************
  vokale.h
  --------------------------------------------------------
  generated at Wed May 20 14:53:50 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int vokale(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} vokaleREC = {30,1,vokale};
