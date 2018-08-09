/*********************************************************
  oy.h
  --------------------------------------------------------
  generated at Mon Jun 22 15:56:38 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int oy(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} oyREC = {30,1,oy};
