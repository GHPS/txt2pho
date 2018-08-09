/*********************************************************
  vokal7.h
  --------------------------------------------------------
  generated at Sun Sep  6 13:29:25 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int vokal7(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} vokal7REC = {7,1,vokal7};
