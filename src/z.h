/*********************************************************
  z.h
  --------------------------------------------------------
  generated at Tue Jun 23 15:53:33 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int z(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} zREC = {27,1,z};
