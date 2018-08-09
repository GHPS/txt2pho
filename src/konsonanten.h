/*********************************************************
  konsonanten.h
  --------------------------------------------------------
  generated at Wed May 20 14:52:15 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

extern "C" int konsonanten(float *in, float *out, int init);

static struct {
  int NoOfInput;    /* Number of Input Units  */
  int NoOfOutput;   /* Number of Output Units */
  int(* propFunc)(float *, float*, int);
} konsonantenREC = {27,1,konsonanten};
