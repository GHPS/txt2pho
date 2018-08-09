/*********************************************************
  oe.h
  --------------------------------------------------------
  generated at Fri Jun  5 18:20:14 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int oe(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} oeREC = {30,1,oe};
