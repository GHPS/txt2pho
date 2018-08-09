/*********************************************************
  X@.h
  --------------------------------------------------------
  generated at Fri Jun  5 18:16:13 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int schwa(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} schwaREC = {30,1,schwa};
