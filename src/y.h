/*********************************************************
  y.h
  --------------------------------------------------------
  generated at Mon Jun 22 16:04:22 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int y(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} yREC = {30,1,y};
