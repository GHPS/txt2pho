/*********************************************************
  oo.c
  --------------------------------------------------------
  generated at Fri Jun  5 17:58:30 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

#ifdef IPHONDURNET

#include <math.h>

#define Act_Logistic(sum, bias)  ( (sum+bias<10000.0) ? ( 1.0/(1.0 + exp(-sum-bias) ) ) : 0.0 )
#define NULL (void *)0

typedef struct UT {
          float act;         /* Activation       */
          float Bias;        /* Bias of the Unit */
          int   NoOfSources; /* Number of predecessor units */
   struct UT   **sources; /* predecessor units */
          float *weights; /* weights from predecessor units */
        } UnitType, *pUnit;

  /* Forward Declaration for all unit types */
  static UnitType Units[102];
  /* Sources definition section */
  static pUnit Sources[] =  {
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, 
Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, 
Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, 
Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, 
Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, 

Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, 
Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100, 


  };

  /* Weigths definition section */
  static float Weights[] =  {
-0.095310, -0.622670, 0.465190, -1.028070, 0.365560, -0.202130, -0.432180, 0.494300, -0.771790, 0.384190, 
0.596620, 0.351290, 0.225440, -0.328960, -0.548840, -0.214590, -0.091080, 0.048030, -0.311810, 0.303220, 
-0.829320, 0.399900, -0.887780, 1.137910, -0.123210, 0.432590, 1.001950, -0.129240, 0.548840, -0.797120, 

0.523550, 0.606060, -0.934090, 0.000000, -0.406110, 0.374280, -0.895720, -0.208990, 0.083020, -1.080080, 
-0.395330, 0.033070, 0.392190, 0.318810, 0.427240, -0.233330, -0.419350, -0.221140, -0.917710, 0.182950, 
-0.571870, -0.473980, 0.639060, -0.862010, 0.345900, -0.051990, 0.930800, -0.908020, -0.627000, -0.494850, 

-0.369870, -0.531420, 0.179690, 0.764860, 0.042370, 0.612500, -0.721430, -0.012450, 0.997170, -0.772490, 
0.900730, -0.704990, 0.508870, 0.394140, -0.908180, -0.821380, -0.603340, 0.033070, 0.608630, -0.191950, 
0.422580, 0.395190, 0.477350, 0.692610, 1.070440, 0.905910, 0.471590, 0.155150, -0.431420, 0.579600, 

1.026240, -0.048180, 0.054240, 0.820760, 0.593030, -0.668390, 0.867750, 0.936580, 0.577530, -0.322590, 
1.202860, -0.928420, 1.129110, 0.175910, 0.711290, -0.783020, -0.776550, 0.128520, -0.870140, -0.451660, 
-0.916420, -0.335350, 0.202870, -0.905380, -0.193520, -0.675810, -0.641700, -0.659720, -0.545220, -0.090320, 

-0.713560, -0.375670, 0.981350, 0.474920, -0.199320, 0.797120, 0.292550, -0.175380, 0.948620, -0.647920, 
1.053430, -0.549860, 0.527840, -0.729540, 0.318850, 0.367710, 0.626560, -0.289430, 0.285670, 0.598570, 
0.455250, -1.114410, 0.726570, 0.344300, -0.121280, 0.358230, -0.731790, 0.368940, -0.332690, -0.592150, 

-0.374140, 0.734750, -0.796460, 0.371530, -0.203160, -0.743950, -0.544950, 0.438660, -0.514100, 0.786490, 
-0.601170, -0.173630, -0.659430, 0.352750, -0.344600, 0.335510, -0.761200, -0.977070, 0.932610, -0.991520, 
0.966020, -0.065200, 0.923750, 0.279500, -0.174460, 0.440840, -0.033500, -0.337870, -0.529280, 0.145870, 

0.059800, 0.424070, 0.468590, 0.674570, 0.985150, -0.518200, -0.085740, 0.832090, -0.465950, 0.753790, 
0.452380, -0.908460, -0.444370, -0.602110, -0.611660, 0.532110, 0.514080, 0.447820, 0.359350, -0.061800, 
0.445480, 0.193030, -0.741790, 0.892240, 0.436760, 0.212140, -0.163320, 0.404080, -0.650280, 0.089650, 

0.578060, -0.851770, -0.898030, 0.344810, -0.743650, 0.636170, 0.335630, -0.393010, 0.084350, -0.743440, 
0.192410, -0.140890, -0.876090, 0.413260, 0.257990, 0.662190, 0.650040, 0.387620, 0.216090, 0.944670, 
-0.376360, 0.829670, -0.102750, 0.383540, 0.367600, 0.014270, 0.902130, -0.772500, -0.392540, -0.491630, 

-0.466210, -0.422520, -0.765680, -0.283380, -0.961270, -0.082630, -0.175060, 0.867190, -0.215220, 0.833370, 
-0.281750, 0.107750, -0.851280, 0.238980, 0.277570, -0.711230, -0.535470, 0.664660, 0.217380, 0.191350, 
-0.969230, -0.264200, -0.663920, 0.145970, -0.475650, 0.857270, 0.725320, -0.124920, -0.910030, -0.870560, 

0.195170, -0.630060, 0.438490, 0.791370, -0.155120, -0.521820, 0.774480, -0.636680, -0.496190, 0.166610, 
0.046060, 0.287240, 0.164650, 0.949160, -0.055170, -0.429780, 0.525590, -0.338570, -0.566220, -0.517490, 
0.751440, 0.184740, -0.856500, -0.554350, 0.450470, -0.965410, 0.144730, 0.998660, -0.204470, 0.965260, 

0.983810, 0.434340, 0.267140, -0.189740, 0.629520, -0.567600, -0.058270, 0.368140, 0.429460, -0.744480, 
0.255210, -0.884270, 0.027290, 0.419690, -0.820070, 0.541540, 0.340860, -0.062600, -0.412540, -0.696310, 
-0.203630, -0.649310, -0.935520, 0.707000, -0.112630, 0.922220, 0.557520, 0.853780, -0.014040, 0.673690, 

0.707110, 0.766210, -0.956830, -0.914020, 0.342650, 0.029430, -0.840320, -0.834820, 0.225060, 0.724920, 
0.427030, -0.276250, -0.190180, -0.433810, 0.491990, -0.066530, -0.202560, 0.897270, 0.307300, 0.960180, 
-0.175240, -0.725180, 0.859620, 0.942390, -0.031770, 0.366220, -0.875470, 0.755900, -0.839220, 0.036750, 

-0.639940, 0.151550, 0.109170, -0.467610, 0.573870, 0.699640, 0.421350, -0.421950, 0.724990, 0.335350, 
-0.766600, 0.993700, -0.864010, 0.154340, -0.257090, 0.445400, 0.110610, -0.369360, -0.490830, 0.655860, 
0.730850, 0.702700, 0.414480, -0.729650, 0.535390, -0.383880, -0.696750, -0.679230, 0.845820, 0.761170, 

-0.512480, 0.778010, 0.215150, 0.793670, -0.498470, -0.304060, -0.719320, -0.179800, 0.800240, -0.504410, 
-0.164030, 0.021220, 0.361640, -0.847100, 0.195280, 0.068960, -0.373250, 0.497780, -0.582700, -0.789890, 
1.062130, 1.021600, 0.453500, -0.915580, 0.315080, -0.637660, -0.642300, 0.498090, -0.975170, 1.030020, 

-0.963060, -0.350060, 0.441170, -0.427820, -0.817150, -0.247880, -0.969390, -0.243560, -0.953350, 0.537680, 
0.013990, 0.012110, -0.601950, 0.659700, -0.742060, 0.776070, -0.817320, -0.459680, 0.043610, -0.126880, 
1.029200, 0.363920, 0.244670, -0.419980, 0.022870, -0.374950, -0.111120, 0.430040, 0.783140, 0.462570, 

-0.880130, 0.179990, -1.403660, 0.043460, -0.118290, -0.815150, 0.898400, -1.225820, -0.006390, 0.698840, 
0.134210, 0.848800, 0.294010, 0.183040, 0.541650, -0.389670, 0.472160, -1.304080, -0.590430, 0.536720, 
-0.060310, -0.851580, 0.117630, 0.692720, -1.087980, -0.364880, 0.446710, -0.395930, -0.257170, 0.473780, 

0.502170, 0.194450, -0.199000, -0.789750, -0.886740, -0.742220, -0.486930, -0.753590, -0.399780, -0.359210, 
0.923970, -0.567580, 0.858640, 0.339500, 0.092440, 0.210070, -0.018350, -0.913550, -0.356570, -0.130410, 
-0.330890, 0.770510, -0.694650, -0.385950, 0.601970, 0.888190, 0.215070, -0.777840, 0.552840, 0.316750, 

0.831160, -0.737620, 0.583530, -0.924960, -0.507040, -0.043770, -0.566330, 0.045850, 0.337850, 0.591260, 
-0.404770, -0.013970, 0.251180, -0.340660, -0.987010, 0.742130, -0.586690, 0.799020, -0.275810, -0.353180, 
1.000210, -0.875660, 0.327470, -0.691390, -0.162160, 0.956050, -0.718360, -0.182140, 0.545890, -0.444890, 

0.907180, -0.456950, -0.359440, -0.946840, 0.303410, 0.522650, 0.364010, -0.188220, -0.748840, -0.875950, 
1.083550, 0.284700, -0.589430, -0.269980, -0.683090, -0.587120, -0.102140, -0.268610, -0.058620, -0.131360, 
0.471420, -0.468300, 0.161340, -0.578460, 1.063930, 0.662230, -0.004340, -0.845730, -0.762190, 0.857680, 

0.418240, -0.211150, 0.919360, 0.055650, 0.641700, 0.022870, 0.701810, 0.385080, 0.039590, -0.364370, 
0.809630, -0.483560, -0.566140, -0.830190, -0.839950, 0.808680, -0.791190, 0.311190, 1.081060, -0.519330, 
-0.014790, 0.778580, 0.841650, -0.132680, 1.096430, -0.562540, 0.722590, 0.499680, 1.101870, -0.686090, 

0.741160, -0.442110, -0.096550, -0.678240, 0.041260, 0.357330, 0.932060, 0.972360, 0.045570, 0.731980, 
-0.085520, -0.502640, 1.070480, 0.455290, 0.442240, -0.545480, -0.936290, 0.672450, 0.331510, 0.071240, 
0.295250, -0.838460, 0.216330, 0.596700, -0.121250, -0.836290, 0.370300, -0.214390, 0.518750, 0.150540, 

0.044930, -1.348520, -0.441890, 0.392780, 0.092830, 0.019080, -0.111840, -0.235670, -0.421410, 0.678290, 
-0.576840, 0.632120, 0.600000, 0.063930, 0.760770, 0.476950, 1.092450, 0.250300, -0.133180, -0.325300, 
0.603370, 0.084540, 0.878740, 0.758630, 0.311710, 0.508490, -0.477340, -0.371010, 0.405260, -0.233140, 

-0.548920, -0.272880, -0.026870, -0.682770, 0.805670, -0.632720, -0.698840, -0.556210, -0.599140, -0.041010, 
0.637410, -0.714090, -0.280370, -0.936510, -0.922990, 0.467610, 0.116970, 0.109600, -0.945640, -0.060570, 
-0.554920, -0.354810, 0.124350, 0.121820, 0.956340, 0.621630, -0.185490, 0.773550, 0.940130, -0.131640, 

-0.629000, -0.046870, 0.322340, -0.604280, 0.348170, -0.029160, -0.257260, 1.053440, -0.228560, -0.356980, 
-0.533570, -0.884720, -0.815620, 0.702330, 0.873300, -0.101170, -0.420100, -0.856880, -0.023390, 0.239530, 
-0.529320, -1.020580, 0.850670, 0.983980, -0.287010, -0.974470, -0.211170, -0.379110, 0.801470, -0.132210, 

0.172860, 0.293130, -0.540330, 0.580900, 0.368500, 0.381720, 0.040420, 0.339690, 0.496290, 0.804670, 
-1.029280, -0.658500, -0.878890, 0.176450, -0.230190, 0.543050, -0.063030, -0.839200, -0.911950, -0.800430, 
-0.796530, 0.408950, 0.700130, 0.585900, 0.991690, -0.178280, -0.449630, -0.196850, -0.317800, -0.303010, 

0.414650, 0.412960, -0.306320, -0.273240, 0.211780, -0.925020, -1.077660, 0.502950, 0.933310, -0.485440, 
0.279030, -1.111840, -0.286460, 0.613230, -0.591490, 0.042650, 0.972350, -0.932010, 0.022530, 0.079120, 
0.124900, 0.317780, -0.263000, -0.091680, 0.994690, -0.499450, 1.133600, -0.626640, 1.481930, 0.577280, 

0.161960, -0.059010, -0.767970, -0.384920, -0.851330, 0.677940, 0.845340, -0.354860, 0.445720, -0.281330, 
-0.110550, 0.649500, 1.079940, 0.833670, 0.639020, 0.439500, -0.788920, -0.179350, -0.307220, -0.508580, 
-0.247470, 0.003490, -0.861860, -0.663370, -0.791380, -0.784530, 0.387050, -0.070370, -1.046750, -0.487620, 

0.489480, 0.071520, -0.097570, -0.628160, -0.285780, 0.765390, -0.001470, 0.059330, 0.505710, 0.555140, 
-0.530040, 0.669780, -0.271220, 0.594710, 0.030860, 0.642930, 0.471590, -0.153540, -0.494080, -0.557600, 
-0.805630, 0.644980, -0.876660, 0.444260, -0.551820, -0.606770, -0.448440, 0.934190, -0.471140, -0.145190, 

0.152800, -0.944360, -0.227570, -0.868530, -0.910330, 0.247330, 1.171400, -0.886050, -0.421170, -0.475910, 
0.405310, -0.229590, -0.402320, 0.801200, 0.160140, -0.404990, 0.622910, 1.003910, 0.028920, 0.084880, 
0.871760, -0.287170, 0.791080, 0.556680, -0.078980, -0.746170, 0.164990, 0.473420, 0.732260, 0.065430, 

0.685830, 0.567800, -0.878670, 0.357450, 0.426830, -0.509700, -0.183430, -0.763460, 0.749720, 0.881550, 
-0.576250, 0.699000, 0.007680, -0.923540, 0.737230, 0.636150, -0.144540, 0.344050, -0.111870, 0.549430, 
0.965080, 0.518110, -0.142420, 0.559270, 0.762540, 0.299390, 0.700620, 0.482060, -0.274930, -0.160760, 

0.118820, 0.650670, 1.186520, -0.352470, 0.071930, -0.519800, 0.528600, -0.503900, -0.141570, -0.546740, 
0.462130, -0.193570, 0.070000, -0.774610, 0.400830, 0.391630, -0.484710, -0.195500, 0.677500, -0.377830, 
-0.173670, 0.645750, 0.958900, -0.766010, 0.474830, 0.208500, 0.414400, -1.205300, -0.843690, -0.614210, 

0.387630, -0.952220, -0.757970, 0.640280, 0.735750, -0.888000, -0.053380, 0.018980, 0.005600, 0.554580, 
-0.952620, -0.341800, 0.368970, 0.770620, -0.840930, -0.918920, 0.723050, 0.448470, -0.199810, 0.877550, 
0.920420, 0.023190, 0.350920, 0.198210, 0.787820, 0.468330, 0.143780, 0.056730, -0.672060, 0.872740, 

0.167990, 0.995600, -0.806720, -0.612440, -0.858860, 0.778570, -0.107840, 0.210560, 0.106720, -0.654300, 
0.973750, -0.356650, -0.749620, 0.848880, 0.325910, -0.475920, -0.299380, -0.427630, -0.319180, -0.358650, 
0.912090, 0.019620, -0.547110, 0.522840, 1.042970, 0.904770, 0.988570, -0.921080, -0.703780, 0.414340, 

0.631490, 0.543200, -0.558060, 1.007150, 0.963190, 0.249050, 0.225440, 0.570210, 0.082690, -0.895510, 
-0.579260, 0.726300, -0.966090, -0.853750, 0.358900, -0.137050, 0.131710, 0.265620, -0.800710, -0.102560, 
0.551730, -0.402670, 0.677700, 0.487940, 0.373020, -0.854330, 0.453160, 0.270620, 0.753770, 0.615880, 

-1.132340, 0.127370, 0.250420, -0.127380, 0.316690, -0.211380, -0.670900, -0.982660, -0.629290, 0.544820, 
-0.871370, 1.068150, -0.297900, 0.262380, -0.020540, 0.415310, 0.923350, -0.136990, -1.052600, -0.548160, 
0.366480, 1.034100, -0.585120, -0.290850, -0.258550, -0.719820, 0.205410, -0.527710, -0.323920, 0.013750, 

0.703560, -0.295840, -1.333410, -0.520240, 0.159390, -0.302630, 0.371190, -0.144250, -0.698880, -0.786940, 
0.440300, -0.104100, -0.104110, -0.501120, -0.598690, -0.764050, -0.500510, 0.406230, 0.364850, 0.221310, 
-0.501100, 0.644810, -0.329640, 0.144480, 0.723890, 0.355560, 0.482150, -0.779910, 0.453910, 0.362840, 

-0.924150, -1.179730, -0.391920, -0.895390, 0.677770, -0.319950, -0.610900, 0.758680, 0.768870, -0.540900, 
0.653850, 0.838090, 0.085840, 0.885900, -0.775600, 0.824540, -0.563650, -0.962190, -0.292290, 0.395410, 
-0.237420, 0.555700, 0.127860, 1.053910, 0.195160, -0.399980, 0.745270, 0.908800, 0.579180, -0.548480, 

-0.695480, -0.024590, -0.008700, -0.457560, 0.081260, -0.133330, -0.553010, -0.411150, -0.508360, 0.781300, 
0.328450, -0.669000, -0.349250, -0.280090, 0.299220, 0.307190, -0.777230, 0.534340, 0.157730, -0.327310, 
-0.640030, -0.261650, -0.127450, -0.115260, -0.890150, 0.940220, 0.432390, -0.747960, -0.363540, 0.223110, 

-1.443540, 0.324710, 0.760670, -1.044680, -0.184130, -0.394750, 1.419220, 0.789830, 0.604350, 0.970910, 
-0.792540, 0.899020, -0.197760, -0.402570, -0.665050, 0.201050, 0.844770, -0.464480, 1.618180, -0.872370, 
-0.614040, 0.650860, 0.325140, -0.492620, -1.132350, 0.548580, 1.129060, 1.017230, 1.134820, 0.219610, 

0.866290, 0.641630, 0.819960, -0.558250, 1.014980, 0.894170, -0.347750, -0.612500, -0.660880, 0.729830, 
-0.075070, 0.308540, -0.025250, 0.159680, -0.664210, 0.006780, -0.500290, 0.051460, 0.544660, 0.781280, 
0.225120, -0.657220, -0.343740, -0.920020, 0.771730, 0.162070, -0.801770, -0.027120, -0.848650, 1.008650, 

0.055610, 0.470500, -0.002460, -0.110170, 0.767790, 0.819140, -0.396270, 0.249210, 0.173910, 0.249220, 
0.240600, -0.383360, 0.318650, -0.858320, -0.838610, 0.358430, -0.076490, 0.972000, 0.691420, 0.832810, 
-0.370740, 0.471670, 0.709190, -0.692650, -0.944180, 0.702420, -0.324260, -0.463970, 0.598160, -0.310060, 

0.588140, 0.463200, 0.842310, 0.976140, 0.583260, 0.777970, -0.540440, 0.384380, -0.933630, 0.016370, 
0.662440, 0.239590, -0.989080, 0.431640, 0.446990, 0.084570, 0.750190, 0.001190, -0.071010, -0.462180, 
-0.207000, -0.419700, -0.592830, 0.707450, -0.322650, -0.150560, -0.697040, -0.188770, 0.626030, 0.587740, 

0.881950, 0.051930, 0.896960, -0.702510, 0.584560, -0.518220, 0.631340, 0.724730, 0.032420, -0.765410, 
0.180150, 0.579700, -0.383590, 0.713560, 0.324530, 0.457820, -0.359000, -0.240410, -0.833170, -0.774010, 
-0.426880, -0.876840, -0.014280, -0.833290, -0.712830, -0.726030, 0.807250, -0.328440, 0.487790, -0.115420, 

-0.546200, -0.813890, 0.038460, -1.000520, -0.185990, -0.713360, -0.233510, 0.735830, 0.700630, 1.079020, 
0.322280, 0.481840, -0.771730, 0.315550, 0.824950, -0.515620, 0.183180, -0.728970, -0.667280, 0.539060, 
0.750650, 0.543220, 0.624510, -0.376920, 0.401540, -0.378390, -0.170760, -0.386280, -0.564850, 0.798920, 

0.263370, 0.448770, 0.061270, 0.838960, 0.783410, 0.076710, 0.441780, 0.936360, -0.860060, 0.802870, 
0.803280, 0.432510, 0.760650, -0.630180, -0.004890, 0.664380, -0.397370, -1.044940, 0.845930, 0.777270, 
0.415480, -0.603200, -0.034240, 0.376440, 0.830380, -0.789930, 0.225460, -1.072020, -0.403150, 0.046770, 

-0.352900, -0.227820, 0.632820, 0.542860, 0.421440, -0.929080, -0.390570, -0.215110, -0.885180, 0.618090, 
0.435700, 0.551720, -0.309580, 0.237890, -0.307730, -0.744560, -0.716170, 0.328490, -0.539520, 0.261910, 
-0.516260, -0.699930, -0.414300, -1.014650, -0.470070, -0.657030, -0.918020, -0.182950, 0.109150, -0.081060, 

0.386830, -0.698640, 0.204820, -0.741870, 0.354490, 0.735880, 0.044300, 0.553920, 0.689260, -0.038050, 
-0.283080, -0.396630, -0.930550, -0.220000, 0.646060, 0.615390, -0.630320, -0.084170, -0.860480, -0.479920, 
0.304130, 0.562520, 0.183820, -0.939530, -0.623610, 0.975370, 0.066520, -0.312370, -0.762280, -0.604590, 

0.645360, 0.938600, -1.116610, 0.098440, -0.427070, 0.867750, 0.832470, 0.190930, -0.569560, -0.041830, 
0.937950, -0.112450, -0.627980, 0.658580, -0.059630, 0.723150, 0.751350, 0.922540, 0.352360, -0.121160, 
-0.166370, 0.535270, -0.593730, -0.218490, 0.801820, 0.127250, 0.463380, -0.084330, -0.548380, -0.987710, 

-0.545920, 0.798120, -0.722360, 0.441640, -0.903480, 0.049240, 0.357400, -1.331580, -0.273450, 0.272400, 
-0.775320, -0.249370, -0.623740, 0.252100, -0.500120, 0.414470, -0.839490, 0.777720, -0.780930, 0.009730, 
-0.898920, -1.190300, 0.642300, -0.705750, 0.535240, -0.879620, -0.599870, 0.228380, 0.830480, 0.755970, 

0.077810, -0.633940, -0.929480, -0.628250, -0.029360, -0.571050, -0.254940, 0.888040, 0.677800, 0.309930, 
0.878510, 0.390580, -1.030930, -0.241840, 0.836420, 0.030700, 0.251520, -0.020610, 0.161440, 0.220570, 
0.844700, 0.609440, 0.984240, 0.731490, 0.039760, 0.695460, 0.395990, 0.573110, -0.017090, 0.746540, 

-0.754710, 0.526870, 0.498470, -0.750090, 0.313310, 0.235260, -0.035870, 0.591160, -0.427420, 0.465920, 
0.358800, -0.709640, -0.335970, 0.277910, -0.769500, -0.521610, -0.190180, 0.340390, 0.026290, 0.847220, 
-0.204340, -0.653270, 0.426450, -0.495890, 0.139270, -0.460190, -1.018170, 0.286830, 0.048000, -0.616110, 
-0.797160, -0.867460, -0.656620, 0.688710, 0.651690, 0.478820, 0.324860, 0.862040, -0.613120, -0.341960, 
0.077830, 0.303190, -0.275050, 0.353220, 0.957220, 0.057680, -0.774210, 0.044680, -0.494010, -0.756010, 

-0.223180, -1.040980, -0.564950, -0.908340, -0.918850, 0.989620, -0.509830, -0.248620, -0.859500, 0.957790, 
0.140760, -0.346920, 0.557040, -1.027610, 0.493170, 0.275520, 0.053020, -0.548150, 0.387690, -0.475250, 
-0.831810, -0.580020, -0.568640, 0.159560, 0.933620, 0.072250, -0.201840, -0.657460, 0.482000, 0.370680, 
-0.130160, -0.322360, -0.815020, 0.436680, 0.150360, 0.249280, 0.223460, 0.460890, 0.336050, -0.183170, 
-0.671440, 0.109840, -0.359310, -0.873050, -0.600070, -0.179370, 0.408410, 0.766990, 0.725930, -0.953620, 

0.227830, -0.890620, -0.162150, -0.626700, -0.132960, -0.165480, -0.927810, 0.705220, -0.418370, 0.664850, 
0.636680, 0.823440, 0.388890, -0.744590, -0.794210, 0.735850, 0.366110, -0.107390, -0.787710, 0.782650, 
-0.717170, -0.154800, 0.826920, -0.348130, -0.605070, -0.376790, 0.893440, 0.914410, -1.061060, 0.396760, 
-1.089230, -0.529140, -0.329420, 0.284100, 0.031300, -0.209660, 0.512870, 0.494930, -1.138800, 0.838540, 
0.328190, 0.509030, 0.216720, 0.384600, -0.283860, 0.640270, -0.546650, -0.254380, 0.316210, -0.227780, 

-0.919170, -0.905760, -0.108710, 0.240890, 0.399400, -0.445270, -0.282570, -0.752280, -0.801610, -0.027100, 
-0.886520, -0.829880, 0.871410, -0.265090, 0.412540, -0.914430, -0.364830, -0.086040, -0.110440, -0.357800, 
-0.249330, 0.060020, -0.617020, -0.406170, -0.910670, -0.132010, -0.682610, -0.418120, 0.263790, -0.242290, 
0.954720, 0.256220, 0.847620, -0.347470, 0.685800, -0.403320, -0.180700, -0.351890, 0.564350, -0.036070, 
0.523480, 0.866030, -0.252810, -0.296490, 0.362480, 0.956910, 0.331200, 0.355260, 0.952610, -0.906840, 

0.021750, -0.295550, 0.375840, -0.012580, 0.123750, 0.177990, -0.718940, 0.823730, -0.754460, 0.349660, 
0.614210, -0.677940, 0.913120, -0.844730, -0.524970, 0.483390, -0.305460, 0.929000, 0.138040, 0.960830, 
-0.973980, 0.790510, 0.651950, -0.640770, -0.309280, 0.098660, -0.626360, 0.289860, 0.572970, 0.616140, 
-0.837150, 0.309850, 0.271030, 0.239870, -0.075430, 0.555100, -0.578020, 0.734750, 0.778940, 0.700430, 
-0.365460, 0.293450, 0.875880, 0.703970, 0.100980, -0.424560, 0.168760, 0.223050, -0.006260, -0.963060, 

-0.520940, 0.957840, -0.063190, -0.242430, 0.092930, -0.734900, -0.426880, 0.059490, -0.804080, -0.369590, 
1.049620, -0.052750, 0.383360, 0.046680, -0.086980, 0.977720, -0.481550, 0.784950, 0.799230, -0.726490, 
0.514470, -0.635760, -0.475110, 0.729940, 1.007980, 1.260820, -0.720370, 0.513640, -0.432760, -0.583330, 
-0.613650, -0.522080, -0.093030, -0.083660, -0.410230, 0.501830, -0.896610, -0.614940, -1.518510, 0.976080, 
-0.038930, -0.698670, 0.217230, 0.787300, -0.922460, -0.488130, 0.470960, -0.694310, -0.328940, 0.733020, 

0.308020, 0.837320, 1.152860, 0.376630, -0.546380, 0.151250, -0.184310, 0.275740, 0.294880, 0.065690, 
-0.998770, -0.931090, -0.186980, 0.929170, -0.404630, -0.478240, 0.928000, 0.460500, -0.209300, -0.652190, 
1.001830, 0.973960, -0.357090, 0.852000, 0.246520, -0.352850, -0.733040, -0.145520, 0.001960, 0.264990, 
0.448630, 0.901870, 0.321870, 0.713340, -0.390980, -0.944150, 0.558950, 0.344200, 0.750510, -0.131900, 
0.868730, -0.268180, -0.695560, 0.180400, -0.866900, 0.307790, -0.725360, -0.778010, -0.396810, -0.086890, 

0.618070, 0.170960, -0.304980, -0.278370, -0.927770, 0.843220, -0.031910, 0.158160, 0.637480, -0.349060, 
-0.132200, -0.827590, 0.203960, -0.430980, -0.352100, -0.960430, 0.504940, 0.771340, 0.003670, -0.674430, 
-0.867820, 0.579440, -0.310250, -0.315620, -0.297630, -1.026470, 0.287090, 0.560480, 0.451240, 0.318160, 
-0.037070, 0.866610, 0.823770, 0.705850, 0.359770, 0.388520, -0.308440, -0.145460, -0.142860, -0.601820, 
0.439710, -0.720010, -0.843170, -0.062850, 0.568440, 0.886470, -0.935880, 0.911560, 0.492600, 0.672200, 

-0.124080, -0.442820, 0.404910, 0.898400, -0.852650, -0.311700, -0.282790, 0.080550, 0.219180, -0.415420, 
-0.499710, 0.948690, -0.180290, -0.834520, 0.051390, 0.180830, -0.009750, 0.723640, 0.644410, 0.875960, 
-0.884100, -0.121070, 0.963820, -0.766830, 0.218180, -0.173180, 0.369230, -0.877440, -0.104600, 0.690330, 
0.633270, 0.033740, 0.841000, 0.184680, -0.676510, -0.752810, -0.195100, -0.108260, 0.928270, -0.944300, 
0.636780, -0.357100, 0.795810, -0.644410, -0.893960, 0.962590, 0.450290, -0.891300, 0.395620, -0.845090, 

0.885660, -0.759430, -0.344940, 0.607860, -0.252140, -0.873680, 0.787290, 0.225770, -0.335130, 0.221490, 
0.686630, 0.473260, 0.956780, -0.884370, 0.873880, -0.535210, -0.284270, -0.502880, 0.431290, 0.368920, 
0.513430, 0.003280, -0.971990, 0.621400, -0.687260, 0.840710, 0.196830, 0.976390, -0.394500, -0.964080, 
0.757030, -0.554300, 0.283120, 0.806520, 0.142990, 0.340480, 0.561370, -0.140600, 0.679190, -0.274700, 
-0.415840, -0.510360, 0.219200, 0.886540, -0.532000, 0.186280, -0.232390, 1.010180, -0.186570, 0.809120, 

-0.986900, -0.708110, 0.212220, -0.049560, 0.580670, -0.649010, 0.050130, -0.431760, 0.098220, -0.359330, 
-0.616680, -0.438410, -0.916290, -0.550520, 0.838620, -0.805100, -0.941520, -0.377090, -0.942250, -0.807860, 
0.828670, -0.682520, -0.518480, 0.478500, 0.957990, 0.604770, 0.631460, -0.657450, -0.883710, 0.266500, 
0.175720, 0.684440, 0.436930, 0.167040, -0.763540, 0.266960, -0.226680, 0.961730, -0.207030, -0.688520, 
-0.508010, -0.114160, -0.546950, -0.409210, -0.329280, 0.118660, -0.416170, 0.357790, -0.313330, 0.399790, 

-0.668530, -0.532150, 0.529690, -0.068900, 0.719420, -0.735850, -0.233020, -0.173920, 0.332690, 0.655690, 
0.538710, 0.154770, -0.868310, -0.956700, -0.489800, -0.102870, 0.479000, 0.836310, 0.253680, -0.451990, 
0.250760, -0.907860, 0.526690, 0.359770, -0.469630, -0.876280, 0.824560, -0.957080, 0.367220, -0.516850, 
0.704360, -0.929840, 0.279350, 0.886020, 0.395040, 0.169940, -0.889810, -0.357690, -0.829470, -0.522270, 
0.316280, 0.182030, 0.399280, -0.508580, -0.505010, -0.608670, -0.306280, 0.691430, -0.945190, 0.566870, 

-0.049510, -0.749950, -0.285160, -0.062960, 0.466630, -0.086550, 0.381700, 0.647750, 0.283540, -0.174610, 
0.240360, -0.597600, -0.446430, -0.718080, -1.110880, 0.986500, 0.496760, -0.856580, -0.019170, 0.853940, 
0.707070, -0.102940, 0.381850, 0.905530, -0.008640, -0.380400, -0.389320, 0.983880, -0.169740, -0.460310, 
-0.723430, 0.835540, 0.772170, -0.703510, -0.360910, -0.602280, -1.123920, -0.186930, 0.868350, -0.552340, 
0.533550, -0.559730, 0.261780, 0.090440, 0.636600, 0.075470, 0.320470, -0.888520, -0.015790, 0.269740, 

0.447250, 0.736880, 0.932530, 0.269100, -0.114520, -0.240650, 0.445910, -0.403910, 0.087830, 0.512260, 
0.997160, -0.307390, 0.865270, -0.693870, -0.108520, -0.939180, -0.350070, 0.509760, -0.825560, -0.335970, 
-0.935780, -0.312120, 0.598800, -0.343360, -0.201510, 1.000160, 0.970070, -0.786030, -0.800120, 0.487190, 
0.176390, -0.539420, 0.541840, -0.721210, -0.254830, 0.593410, 0.050520, -0.354310, 0.593690, 0.659110, 
0.456690, -0.517980, -0.702800, -0.502730, -0.715580, 0.767030, -0.640980, -0.167980, 0.474620, -0.214900, 

0.718910, -0.817360, -0.201120, -0.259780, 0.731450, 0.976270, -0.009430, 0.651020, -0.613050, -0.532180, 
-0.169750, -0.981880, -0.784530, 0.404600, 0.589970, 0.249350, -0.404280, -0.136680, 0.717940, -0.611120, 
0.360040, 0.917560, -0.639250, 0.766790, 0.401490, -0.049760, 0.306670, 0.103220, -0.510560, -0.497330, 
-0.819240, -0.393820, -1.324490, 0.767160, -0.441270, -1.024660, -0.014160, -0.432750, 0.315460, 0.269010, 
-0.258340, 0.868380, 0.732230, 0.335910, 0.275550, -0.424310, 0.974900, -0.795930, 0.949650, 0.370800, 

-0.695470, -0.386050, -0.371330, 0.452810, 0.426510, 0.536970, 0.023980, 0.574790, -0.741140, -0.263410, 
0.034730, -0.256700, -0.213000, -1.286340, -0.768620, -0.067280, 0.865820, -0.369700, 0.631610, -0.617610, 
1.042960, 0.750980, 0.173910, -0.451970, -0.650730, -1.182700, 0.919610, -0.702350, 0.369860, -0.060970, 
-0.398480, 0.832880, -0.208980, -0.173590, -1.057810, -0.611650, 0.943130, 0.962850, 1.298320, 0.681150, 
-0.268840, -0.091690, 0.417870, 0.950550, -0.229430, 0.702440, -0.444290, 0.197980, 0.237120, -0.295500, 

-0.139870, 0.198030, 0.756090, -0.189610, -0.162790, -0.194810, 0.336010, 0.455780, -0.324630, -0.335200, 
-0.928940, 0.276150, -0.870230, -0.820450, -0.335770, 0.417230, 0.857710, -0.813380, -0.074510, -0.322740, 
0.657540, -0.171270, -0.559100, -0.613880, -0.666070, 0.276640, 0.871260, 0.575230, -0.838400, 0.554710, 
0.184100, -0.079860, 0.705570, -0.156430, -0.555940, -0.250860, 0.849390, 0.366910, -0.729740, -0.483720, 
-0.751450, 0.049210, -0.296140, 0.909630, 0.127670, -0.939900, 0.239120, 0.404160, 0.749100, 0.046280, 

-0.716210, 0.163740, -0.129780, -0.922660, 0.937800, -0.679410, -0.080620, -0.595950, 0.638320, 0.802030, 
-0.471540, -0.629520, 0.169600, -0.363250, 0.700420, 0.918690, 0.056110, -0.850190, -0.670370, 0.389230, 
-0.709790, 0.512580, 0.273290, 0.764350, -0.365870, 0.610920, 0.009060, 0.752040, -0.050840, -0.809380, 
-0.108170, 0.200700, 0.412600, -0.461460, 0.616170, 0.796500, -0.086610, -0.071890, 0.336120, 0.004340, 
0.703480, 0.374990, -0.820720, -0.209880, 0.758080, -0.375930, 0.853900, -0.763370, 0.089310, 0.406710, 

0.859950, -0.526910, -0.396870, -1.918370, -1.179500, 0.824110, -0.261110, -0.449340, 0.322310, -0.332260, 
-0.557870, 0.991120, 0.554720, 0.572760, 0.535810, 1.048080, 0.019680, -0.283490, 0.819280, 0.483170, 
-0.326630, -0.223450, -0.441560, -0.342840, 0.354760, 1.391310, 0.687060, 0.492160, -0.432140, 0.648790, 
-0.832120, 0.651680, -0.193120, -0.261030, 1.203350, 0.059710, 1.125460, 0.115050, -1.221510, -0.060430, 
-0.563570, -1.061310, -0.821010, -0.490580, 0.486810, -0.561270, -1.047310, -1.039000, 0.102010, -0.089420, 

0.892680, -0.856530, 0.283770, -0.569230, -0.504000, 0.947090, 0.942510, 0.253730, -0.036020, -0.443800, 
-0.429990, 0.828760, 0.412520, 0.743780, 0.593150, -0.952580, 0.014430, -0.455920, -0.377730, -0.746580, 
0.331760, 0.858690, -0.481020, 0.781650, 0.729240, -1.247800, 0.964780, 0.886010, 0.280280, -0.438690, 
0.005290, -0.542140, -0.508600, -0.797050, 0.424710, -0.874350, 0.056140, -0.259900, 0.795150, -0.742570, 
-0.075230, -0.742900, 0.170450, 0.455350, -0.396920, -0.055940, 0.069120, 0.233530, 0.145550, -0.703740, 

0.644190, -0.746650, 0.912680, -1.068230, 0.507320, 2.047200, -1.132450, -0.592310, -0.009020, -0.401940, 
0.905150, 0.304300, 1.100200, 0.114940, -0.912430, -1.724000, -0.898310, 0.918910, 2.722170, -1.070130, 


  };

  /* unit definition section (see also UnitType) */
  static UnitType Units[102] = 
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (Old: 1) */
      0.0, 0.207070, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (Old: 2) */
      0.0, -0.680970, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (Old: 3) */
      0.0, 0.293330, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (Old: 4) */
      0.0, 0.106830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (Old: 5) */
      0.0, 0.362610, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (Old: 6) */
      0.0, -0.772860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (Old: 7) */
      0.0, 0.968830, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 8 (Old: 8) */
      0.0, -0.168180, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 9 (Old: 9) */
      0.0, 0.681260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 10 (Old: 10) */
      0.0, 0.232570, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 11 (Old: 11) */
      0.0, -0.382010, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 12 (Old: 12) */
      0.0, 0.882280, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 13 (Old: 13) */
      0.0, -0.799710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 14 (Old: 14) */
      0.0, 0.672910, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 15 (Old: 15) */
      0.0, 0.681860, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 16 (Old: 16) */
      0.0, -0.066130, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 17 (Old: 17) */
      0.0, -0.208290, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 18 (Old: 18) */
      0.0, -0.165400, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 19 (Old: 19) */
      0.0, 0.460060, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 20 (Old: 20) */
      0.0, 0.219040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 21 (Old: 21) */
      0.0, 0.413200, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 22 (Old: 22) */
      0.0, -0.484750, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 23 (Old: 23) */
      0.0, 0.402950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 24 (Old: 24) */
      0.0, 0.848920, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 25 (Old: 25) */
      0.0, 0.190030, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 26 (Old: 26) */
      0.0, -0.714760, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 27 (Old: 27) */
      0.0, -0.883940, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 28 (Old: 28) */
      0.0, -0.325660, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (Old: 29) */
      0.0, -0.692950, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 30 (Old: 30) */
      0.0, 0.994490, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 31 (Old: 31) */
      0.0, 0.033510, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.909150, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.225440, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.056280, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.527910, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.713670, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.986380, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.938720, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.595290, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.216670, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.431770, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.473080, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.750800, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.185600, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 0.932470, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.214130, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.558600, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.178850, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.550330, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.636780, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.244980, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.239460, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.047410, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.423230, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.265330, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.185950, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.217980, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.906010, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.708550, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.052730, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.663580, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.348630, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.501430, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.635980, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -1.022330, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.484550, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.594150, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.433570, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.822850, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, 0.339620, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.203070, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.850360, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.240940, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.374850, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.877550, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.419500, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.599820, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.657770, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, -0.058130, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.166230, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.188630, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.338270, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.774460, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 1.001680, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.723100, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.166520, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, 0.001080, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.445600, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.504600, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.355740, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.171810, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.529850, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.722530, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.696700, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.922390, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, 0.090270, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.805770, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -0.933720, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.582630, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.917200, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.564520, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int oo(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[30] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30}; /* members */

  static pUnit Hidden1[50] = {Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80}; /* members */

  static pUnit Hidden2[20] = {Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100}; /* members */

  static pUnit Output1[1] = {Units + 101}; /* members */

  static int Output[1] = {101};

  for(member = 0; member < 30; member++) {
    Input[member]->act = in[member];
  }

  for (member = 0; member < 50; member++) {
    unit = Hidden1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 20; member++) {
    unit = Hidden2[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Output1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for(member = 0; member < 1; member++) {
    out[member] = Units[Output[member]].act;
  }

  return(OK);
}

#endif

