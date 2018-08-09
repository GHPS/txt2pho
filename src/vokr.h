/*********************************************************
  vokr.h
  --------------------------------------------------------
  generated at Tue Jun 23 14:38:35 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int vokr(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} vokrREC = {27,1,vokr};
