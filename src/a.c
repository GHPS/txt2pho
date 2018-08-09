/*********************************************************
  aa.c
  --------------------------------------------------------
  generated at Fri Jun  5 17:40:56 1998
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
0.150390, -0.606620, 0.534700, -0.816670, 0.398630, -0.343360, -0.295550, 0.807320, -0.771790, 0.390690, 
0.805430, 0.499960, 0.128160, -0.287220, -0.490950, -0.248440, -0.199070, -0.074160, -0.182270, 0.465000, 
-0.794910, 0.422430, -0.776470, 1.054210, 0.228350, 0.488040, 1.135830, -0.337740, 0.820830, -0.747310, 

0.475540, 0.379090, -0.702820, 0.074410, -0.428760, 0.286100, -0.537790, -0.316910, 0.083020, -0.919270, 
-0.631500, 0.100330, 0.559690, 0.290930, 0.333220, -0.429450, -0.467880, -0.125510, -0.690710, 0.181520, 
-0.542330, -0.774220, 0.625320, -0.884240, 0.381080, -0.056880, 0.993090, -0.843220, -0.821240, -0.555780, 

-0.426120, -0.659370, 0.232010, 0.678890, 0.033420, 0.664990, -0.899440, -0.112780, 0.997170, -0.721030, 
0.527660, -1.055070, 0.394390, 0.370860, -1.136200, -1.109150, -0.619220, -0.075540, 0.663030, -0.063350, 
0.317400, 0.226600, 0.418700, 0.637760, 0.648250, 0.837910, 0.511730, 0.197550, -0.534370, 0.453960, 

0.863850, 0.218940, 0.065810, 0.613080, 0.674540, -0.710420, 0.774170, 0.705220, 0.577530, -0.267360, 
1.084400, -0.853370, 1.020130, 0.111810, 0.881260, -0.708230, -0.787440, 0.072370, -0.869490, -0.504620, 
-0.903980, 0.065250, 0.136980, -0.834170, -0.241190, -0.681470, -0.599590, -0.301160, -0.269040, -0.037380, 

-0.996090, -0.341100, 0.863880, -0.107220, -0.226470, 0.656700, 0.015890, -0.586800, 0.948620, -0.682760, 
0.727940, -0.333150, 0.351060, -0.803690, 0.239810, 0.409340, 0.730270, -0.161210, 0.495290, 0.304560, 
0.356690, -1.163180, 0.710780, 0.440830, -0.045690, 0.399340, -1.038620, 0.590660, -0.406390, -0.668740, 

-0.400170, 0.797980, -0.821880, 0.459830, -0.239900, -0.786030, -0.775860, 0.182040, -0.514100, 0.781570, 
-0.675140, -0.054380, -0.683230, 0.313810, -0.466480, 0.279200, -0.731980, -0.955590, 0.819510, -0.932210, 
0.868290, -0.225550, 0.916640, 0.246100, -0.017560, 0.380320, -0.115630, -0.324610, -0.643340, 0.065460, 

-0.031670, 0.373300, 0.269990, 0.415580, 0.909370, -0.976430, -0.092800, 0.843740, -0.465950, 0.761800, 
0.318970, -1.009370, -0.637740, -0.642710, -0.892090, 0.323870, 0.568220, 0.162740, 0.250700, -0.201100, 
0.426870, 0.207890, -0.783930, 0.880320, 0.587970, 0.199150, -0.241550, 0.528000, -0.841170, -0.070880, 

0.463630, -0.871130, -0.928000, 0.283880, -0.827950, 0.399370, 0.276110, -0.477650, 0.084350, -0.801260, 
0.079320, -0.336950, -0.890450, 0.292260, 0.037000, 0.525390, 0.547820, 0.313830, 0.131720, 0.905850, 
-0.346990, 0.802550, -0.132430, 0.369850, 0.498700, -0.036380, 0.920190, -0.867810, -0.510820, -0.662620, 

-0.621590, -0.324100, -0.834970, -0.369810, -1.077730, 0.260340, -0.060180, 0.903510, -0.215220, 0.904860, 
-0.127550, 0.202200, -0.864080, 0.339740, 0.274160, -0.830130, -0.642500, 0.860820, 0.137210, 0.157160, 
-0.957530, -0.301000, -0.590270, 0.153130, -0.794210, 0.948540, 0.598850, -0.010610, -0.912070, -0.821890, 

0.163390, -0.725260, 0.468960, 0.812370, -0.054670, -0.691600, 0.690890, -0.484400, -0.496190, 0.179950, 
-0.191550, 0.176030, 0.031060, 0.952700, 0.030040, -0.362540, 0.627420, -0.338050, -0.698930, -0.625550, 
0.740840, 0.558810, -0.897280, -0.530940, 0.370930, -0.937630, 0.106250, 0.966060, -0.155330, 1.009640, 

0.899140, 0.406900, 0.420710, -0.349860, 0.432070, -0.725550, -0.192280, 0.051700, 0.429460, -0.700440, 
0.297130, -0.404030, 0.098550, 0.338010, -0.952890, 0.435460, 0.145730, 0.106340, -0.180580, -1.023770, 
-0.083350, -0.441090, -0.866610, 0.651910, 0.149080, 1.052670, 0.324140, 0.703470, 0.025170, 0.566410, 

1.128270, 0.747890, -0.802910, -0.665310, 0.150960, -0.407220, -1.514090, -0.608250, 0.225060, 0.636120, 
0.646280, -0.213220, -0.302420, -0.329470, 0.336450, -0.270500, -0.491230, 0.993090, 0.095150, 1.159840, 
-0.156510, -0.687710, 0.901950, 0.830570, 0.796400, 0.307930, -0.908030, 0.842880, -0.360110, 0.011150, 

-0.673700, 0.063610, 0.114810, -0.335980, 0.581380, 0.602680, 0.704450, -0.394210, 0.724990, 0.354450, 
-0.600570, 1.049640, -0.847350, 0.247290, -0.253400, 0.433460, 0.187730, -0.462630, -0.635390, 0.639790, 
0.795670, 0.730000, 0.433060, -0.679490, 0.271500, -0.329940, -0.625340, -0.872690, 0.843410, 0.809460, 

-0.677630, 0.659730, 0.200340, 0.902690, -0.668450, -0.699690, -0.797900, 0.045700, 0.800240, -0.464650, 
-0.289810, -0.223400, 0.382860, -0.894640, -0.112130, -0.242680, -0.539010, 0.352160, -0.889090, -0.869640, 
1.078760, 0.852710, 0.489340, -0.960600, 0.216990, -0.680240, -0.754440, 0.285860, -0.949160, 0.852530, 

-0.827890, -0.321550, 0.392940, -0.519920, -0.849070, -0.221780, -1.111030, -0.109430, -0.953350, 0.533050, 
0.368690, 0.128230, -0.633590, 0.599660, -0.713560, 0.806540, -0.936500, -0.532970, 0.177090, -0.047230, 
0.929560, 0.317990, 0.285090, -0.459710, -0.115140, -0.355540, -0.265670, 0.537340, 1.031470, 0.446800, 

-0.398580, 0.177010, -0.878050, 0.703550, -0.270200, -0.360840, -0.248020, -1.211380, -0.006390, 0.679880, 
-0.245890, 0.820660, 0.251090, 0.339620, 0.484970, -0.617190, 0.111810, -0.791610, -0.607960, 0.773030, 
-0.008680, -0.986640, 0.281560, 0.785440, -1.216620, -0.363580, 0.616590, -0.778080, 0.094650, 0.523730, 

0.346090, 0.390290, -0.278000, -1.017840, -0.808910, -0.833850, -1.009990, -0.876400, -0.399780, -0.329040, 
0.609570, -0.813670, 0.768230, 0.344630, 0.048660, 0.192230, 0.181130, -0.686210, -0.644570, -0.126840, 
-0.403660, 1.029510, -0.740160, -0.465400, 0.092740, 0.906610, 0.227520, -0.622160, 0.346230, 0.297430, 

1.000240, -0.786850, 0.657460, -0.831030, -0.421460, 0.343770, -0.571910, -0.058070, 0.337850, 0.692810, 
-0.353890, 0.239250, 0.347210, -0.236670, -0.795650, 0.803800, -0.518320, 0.754730, -0.093060, -0.312980, 
0.957030, -0.980610, 0.366600, -0.651100, -0.311800, 1.044420, -0.755700, -0.244850, 0.467080, -0.297210, 

1.228350, -0.466040, -0.309530, -0.768450, 0.098960, 0.333460, 0.163100, 0.066100, -0.748840, -0.896260, 
1.403480, 0.517370, -0.328040, -0.323920, -0.841250, -0.634210, -0.289890, -0.470870, -0.115480, 0.030270, 
0.445060, -0.568380, 0.232470, -0.541820, 0.860540, 0.671260, -0.101310, -1.325940, -0.704870, 0.751660, 

0.350670, -0.579100, 0.821180, 0.273940, 0.659400, 0.462770, 0.857540, 0.198750, 0.039590, -0.289880, 
0.747800, -0.058090, -0.596500, -0.780470, -0.737950, 0.787450, -0.900210, 0.345930, 0.800630, -0.553230, 
0.024150, 0.790950, 0.888550, -0.102140, 0.681510, -0.459960, 0.720950, 0.388270, 1.060890, -0.610230, 

0.856390, -0.207600, -0.023540, -0.703280, 0.232450, 0.746200, 1.386130, 1.065960, 0.045570, 0.738000, 
-0.271290, -0.612300, 1.071120, 0.439120, 0.778250, -0.311610, -0.908350, 0.714050, 0.367190, 0.121130, 
0.320810, -0.369530, 0.083740, 0.552970, -0.185630, -0.946380, 0.482130, 0.225020, 0.613270, 0.310460, 

-0.310820, -1.045230, -0.609400, 0.385900, 0.237700, -0.260530, 0.186810, -0.154860, -0.421410, 0.511750, 
-0.710900, 0.382170, 0.456660, -0.132570, 0.656430, 0.622640, 1.282390, 0.291630, -0.200990, -0.288120, 
0.478750, -0.174450, 0.861510, 0.665990, 0.609730, 0.407580, -0.392110, -0.531500, 0.346700, -0.383560, 

-0.501030, -0.239930, -0.095150, -0.869330, 0.729880, -0.491830, -0.430370, -0.545060, -0.599140, -0.032310, 
0.847660, -0.569950, -0.185950, -0.990240, -0.907820, 0.491820, 0.026200, 0.081940, -1.071770, -0.174620, 
-0.568490, -0.248870, 0.168260, 0.151030, 1.106330, 0.678370, -0.358740, 0.912670, 0.834790, -0.150920, 

-0.760290, -0.114780, 0.456140, -0.588300, 0.352650, -0.311620, -0.254650, 1.020000, -0.228560, -0.409020, 
-0.875240, -1.147350, -0.899380, 0.679000, 0.853550, -0.090910, -0.418540, -0.903340, 0.208270, 0.143660, 
-0.589910, -0.762720, 0.786350, 0.942000, -0.343750, -1.062160, -0.345420, -0.320250, 0.770630, -0.153750, 

0.054920, 0.533130, -0.674010, 0.306150, 0.008110, -0.958060, 0.834600, 0.622830, 0.496290, 0.774650, 
-0.620420, -0.860330, -0.439620, 0.072880, -0.551890, 0.207670, -0.569970, -0.899500, -1.506170, -1.376530, 
-0.418640, 0.626100, 0.842000, 0.585300, 1.477530, -0.169510, -0.660460, 0.312160, -0.374720, -0.515640, 

0.786640, 0.254650, 0.254080, 0.032320, -0.009010, -0.875570, -1.365830, 0.305330, 0.933310, -0.329010, 
0.218970, -0.642140, -0.048760, 0.564530, -0.777300, -0.341490, 0.537690, -0.279380, -0.086120, 0.141150, 
0.239880, 0.159900, -0.190320, -0.173990, 1.285650, -0.485120, 1.143820, -0.472420, 1.068140, 0.460030, 

0.326670, 0.063000, -0.859820, -0.322870, -0.706340, 0.966850, 0.515460, -0.337740, 0.445720, -0.339950, 
-0.025360, 0.485840, 0.993930, 0.864840, 0.647330, 0.436280, -0.691300, -0.185190, -0.232070, -0.261700, 
-0.279200, -0.200850, -0.881360, -0.698150, -1.059360, -0.868170, 0.688740, -0.098200, -1.055270, -0.467890, 

0.703880, -0.048660, 0.022660, -0.509000, -0.356710, 0.580940, -0.076610, 0.127770, 0.505710, 0.544770, 
-0.398460, 0.937700, -0.272720, 0.550010, 0.088490, 0.679870, 0.272790, -0.531950, -0.179880, -0.517100, 
-0.689050, 1.026360, -0.807680, 0.358230, -0.445950, -0.553850, -0.357250, 0.849930, -0.220320, -0.138730, 

-0.058920, -0.905300, -0.442200, -0.964350, -0.944880, 0.110840, 0.987630, -1.024210, -0.421170, -0.517950, 
0.381210, -0.223040, -0.442480, 0.652450, 0.006350, -0.359070, 0.724000, 0.901350, -0.158030, 0.036280, 
0.787850, -0.363480, 0.726030, 0.529440, 0.144820, -0.825630, 0.081640, 0.350590, 0.549040, -0.085840, 

0.832390, 0.619940, -0.914040, 0.305440, 0.444710, -0.491840, -0.161510, -0.556550, 0.749720, 0.895230, 
-0.404900, 0.639570, 0.033110, -0.820750, 0.757410, 0.561170, -0.144560, 0.414620, -0.165370, 0.573210, 
0.949940, 0.455980, -0.138520, 0.522660, 0.776950, 0.320000, 0.690280, 0.577880, -0.239100, -0.099290, 

0.461180, 0.927400, 1.137150, -0.784400, 0.295170, -0.325290, 0.789410, 0.012220, -0.141570, -0.530020, 
0.707690, -0.788040, 0.018790, -0.740800, 0.740680, 0.730540, -0.150360, -0.180000, 1.185940, -0.364700, 
-0.431180, 0.812740, 0.874760, -0.610050, 0.863910, 0.250070, 0.108180, -0.343450, -0.809240, -0.427380, 

0.376790, -0.725190, -0.743290, 0.810970, 0.708570, -0.809330, 0.400330, 0.295320, 0.005600, 0.540350, 
-0.787790, -0.437910, 0.520770, 0.731660, -0.807460, -0.926410, 0.577780, 0.558950, -0.526060, 0.979810, 
1.015890, -0.058060, 0.372460, 0.141130, 0.895420, 0.450500, 0.325510, 0.228180, -0.842310, 0.870020, 

0.111180, 1.039780, -0.846780, -0.656790, -0.909580, 0.983530, -0.283730, 0.237080, 0.106720, -0.657290, 
0.789630, -0.817600, -0.671070, 0.771660, 0.279310, -0.504080, -0.373140, -0.235350, -0.553070, -0.339880, 
0.865840, -0.077670, -0.599650, 0.506010, 0.797590, 0.839570, 0.950380, -0.729020, -0.892060, 0.352440, 

0.647270, 0.508160, -0.555170, 1.081930, 1.028200, 0.255020, 0.216660, 0.545880, 0.082690, -0.894300, 
-0.585450, 0.667390, -0.900300, -0.862710, 0.444440, -0.058840, 0.165080, 0.212500, -0.853760, -0.079110, 
0.570360, -0.271760, 0.665310, 0.479300, 0.344440, -0.909090, 0.530160, 0.223540, 0.715900, 0.654160, 

-0.976910, 0.018630, 0.182390, 0.140610, 0.437240, -0.153120, -1.105480, -0.726520, -0.629290, 0.514580, 
-0.297930, 1.185720, -0.298170, 0.325880, 0.111330, 0.628230, 1.130400, -0.156060, -0.784750, -0.543880, 
0.305420, 1.033210, -0.567840, -0.389590, 0.217020, -0.732590, 0.115640, -0.709420, -0.299360, 0.111430, 

0.599140, -0.646140, -1.226640, -0.474630, 0.035250, -0.040630, 0.538140, -0.535160, -0.698880, -0.647570, 
0.445260, 0.491240, 0.416110, -0.273980, -0.499540, -0.914000, -0.715110, 0.697780, 0.261090, 0.208400, 
-0.369420, 0.055860, -0.252110, 0.279210, 0.724130, 0.541540, 0.568750, -0.652810, 0.480070, 0.525990, 

-0.722420, -1.126590, -0.320610, -0.329920, 0.890560, -0.156330, -0.863930, 0.891820, 0.768870, -0.521400, 
0.690290, 0.801960, 0.118850, 0.810630, -0.701520, 0.846950, -0.563830, -1.005660, -0.642040, 0.748210, 
-0.138430, 0.485470, 0.146460, 1.005220, -0.077000, -0.376140, 1.295600, 0.532280, 0.498000, -0.549090, 

-0.691600, 0.055360, 0.001230, -0.474400, 0.209000, -0.004020, -0.431360, -0.328850, -0.508360, 0.749720, 
0.264000, -0.971620, -0.243820, -0.281520, 0.350970, 0.336800, -0.707350, 0.602410, 0.103060, -0.231960, 
-0.586850, -0.196510, -0.210290, -0.181250, -0.825710, 0.836160, 0.697270, -0.577620, -0.481190, 0.248270, 

-1.323200, 0.768500, 0.079460, -1.068970, -0.027690, -0.391680, 1.491460, 1.027890, 0.604350, 0.602330, 
-0.139360, 0.210790, -0.365670, -0.414020, -0.488700, 0.551200, 1.027820, -0.450960, 0.372790, -1.197990, 
-0.711530, 0.518690, 0.163020, -0.545530, -0.080250, 0.393340, 0.898040, 0.637630, 0.961310, 0.302050, 

0.704310, 0.535230, 0.879080, -0.516090, 0.950440, 0.534140, -0.396180, -0.817490, -0.660880, 0.724670, 
-0.217930, 0.464760, 0.002720, 0.065360, -0.842060, -0.107740, -0.576480, -0.100780, 0.499610, 0.655390, 
0.371950, -0.742290, -0.337110, -0.852900, 0.825120, 0.173300, -0.678100, -0.248860, -0.854890, 0.872590, 

-0.165090, 0.352250, 0.089430, -0.023810, 0.863330, 1.002580, -0.415210, 0.215630, 0.173910, 0.226300, 
-0.062460, -0.773620, 0.216900, -0.838180, -0.801580, 0.406080, 0.072500, 1.065880, 0.486880, 0.855700, 
-0.448480, 0.401330, 0.634790, -0.712970, -1.084400, 0.674490, -0.265200, -0.494120, 0.537360, -0.281480, 

0.398680, 0.343930, 0.766370, 0.704180, 0.768280, 0.594460, -1.064730, -0.065400, -0.933630, 0.029400, 
0.762040, 0.595610, -0.893190, 0.515560, 0.548260, 0.348130, 1.245710, 0.168940, 0.252670, -0.512000, 
-0.361160, -0.874560, -0.651140, 0.638950, -0.485660, -0.220760, -0.681500, -0.379170, 0.662380, 0.680320, 

0.877090, 0.312330, 0.837260, -0.856820, 0.510620, -0.444760, 0.848380, 0.611340, 0.032420, -0.787260, 
0.340980, 0.733170, -0.293960, 0.872220, 0.391620, 0.487180, -0.340450, -0.070040, -0.727610, -0.920320, 
-0.301820, -1.007210, 0.020620, -0.805980, -0.581100, -0.680540, 0.760290, -0.124460, 0.495410, -0.002550, 

-0.485780, -0.700770, 0.100540, -0.885090, -0.151780, -0.932710, -0.223210, 0.793380, 0.700630, 0.970310, 
0.127040, 0.266630, -0.815850, 0.269140, 0.783580, -0.489270, 0.158820, -0.830910, -0.496360, 0.451550, 
0.857000, 0.648580, 0.578300, -0.404460, 0.797870, -0.438000, -0.038710, -0.347340, -0.656020, 0.755010, 

0.304560, 0.467390, 0.043500, 0.791910, 0.760290, 0.210260, 0.562000, 0.996170, -0.860060, 0.826610, 
0.827850, 0.377350, 0.794700, -0.677510, -0.045920, 0.624230, -0.433420, -0.882670, 0.781270, 0.771080, 
0.404780, -0.707160, -0.030540, 0.388160, 0.758750, -0.778370, 0.199860, -0.924250, -0.499850, 0.002590, 

-0.436600, -0.214480, 0.551940, 0.424330, 0.388450, -0.998450, -0.407190, -0.131380, -0.885180, 0.630950, 
0.113200, 0.201480, -0.372160, 0.248910, -0.398320, -0.854610, -0.721390, 0.179640, -0.699770, 0.268400, 
-0.535400, -0.583370, -0.416510, -0.977620, -0.747080, -0.624740, -0.932110, -0.198840, 0.064030, -0.120870, 

0.501620, -0.552420, 0.141690, -0.914840, 0.349340, 0.785980, 0.330330, 0.910410, 0.689260, -0.041480, 
0.033030, -0.296460, -1.055650, -0.253110, 0.889800, 0.866110, -0.671160, -0.095040, -0.758390, -0.705980, 
0.288080, 1.074420, 0.215660, -0.925110, -0.535620, 1.008890, -0.280390, -0.112020, -0.434530, -0.499290, 

0.705270, 0.944690, -1.029120, 0.112820, -0.342340, 0.898720, 0.614630, 0.214690, -0.569560, 0.021170, 
0.785620, -0.218500, -0.693980, 0.834540, 0.061420, 0.718310, 0.894290, 0.921940, 0.465560, -0.097330, 
-0.187800, 0.567870, -0.612100, -0.220770, 0.762750, 0.207780, 0.474600, 0.016280, -0.623100, -0.839180, 

-0.334260, 0.909010, -0.709320, 0.255130, -0.906240, 0.028680, 0.108040, -1.132980, -0.273450, 0.186490, 
-0.651560, -0.595670, -0.636370, 0.281750, -0.557380, 0.263980, -0.920710, 1.061640, -0.450070, 0.039820, 
-0.882530, -1.687120, 0.606280, -0.695990, 1.302370, -0.917500, -0.424360, 0.532020, 1.141950, 0.742180, 

0.178890, -0.601100, -0.868240, -0.660490, -0.066030, -0.624730, 0.060510, 0.592120, 0.677800, 0.334110, 
0.872690, 0.678580, -0.943880, -0.160400, 0.843220, -0.075070, 0.152670, 0.085820, 0.226510, 0.244190, 
0.877990, 0.539980, 0.986860, 0.623090, -0.205930, 0.685660, 0.420480, 0.742440, 0.179530, 0.790670, 

-0.725070, 0.527150, 0.536280, -0.685370, 0.288610, 0.222510, -0.115910, 0.566710, -0.393900, 0.433380, 
0.291840, -0.732170, -0.416740, 0.252290, -0.761310, -0.566690, -0.165430, 0.384440, 0.063240, 0.727550, 
-0.250610, -0.590700, 0.399780, -0.605660, 0.077000, -0.592070, -0.993220, 0.218950, 0.077580, -0.580090, 
-0.801370, -0.801340, -0.689040, 0.656560, 0.614680, 0.483120, 0.375400, 0.833750, -0.616120, -0.355940, 
0.011450, 0.289720, -0.251990, 0.346060, 0.892860, 0.074940, -0.721050, 0.031320, -0.484280, -0.791510, 

-0.202430, -1.021760, -0.553980, -0.974130, -0.971370, 0.994430, -0.460420, -0.223460, -0.891040, 0.966440, 
0.233380, -0.237630, 0.523320, -1.072630, 0.543050, 0.246360, 0.140950, -0.567180, 0.364610, -0.455220, 
-0.855490, -0.614980, -0.575970, 0.159170, 0.869440, 0.152220, -0.234220, -0.573050, 0.460600, 0.441330, 
-0.087380, -0.326510, -0.777550, 0.454410, 0.234560, 0.288940, 0.261970, 0.464970, 0.315500, -0.193190, 
-0.625110, 0.134110, -0.406820, -0.872850, -0.616360, -0.184410, 0.433010, 0.773320, 0.720770, -0.910180, 

0.328320, -0.907970, 0.007350, -0.518860, -0.140780, -0.117690, -0.799030, 0.874870, -0.385320, 0.829240, 
0.670990, 0.816500, 0.530880, -0.660260, -0.612180, 0.761610, 0.448100, -0.114330, -0.726600, 0.946420, 
-0.604800, 0.018640, 0.844430, -0.316190, -0.565840, -0.275790, 0.935750, 1.002170, -0.954290, 0.631120, 
-0.912360, -0.402010, -0.232570, 0.454480, 0.072520, -0.013040, 0.703070, 0.510610, -0.856200, 0.858590, 
0.335950, 0.640350, 0.378320, 0.579740, -0.108570, 0.639690, -0.421610, -0.068590, 0.316700, -0.057570, 

-0.888450, -0.815950, -0.291400, 0.249810, 0.589550, -0.453110, 0.118590, -0.725330, -0.869760, 0.176260, 
-0.517440, -0.663620, 0.923110, -0.278120, 0.498980, -0.925870, -0.251410, -0.115150, -0.527290, -0.308980, 
-0.215580, 0.101030, -0.468400, -0.038860, -1.184860, 0.052660, -0.737990, -0.215980, 0.289140, -0.205740, 
0.906210, 0.210570, 0.576440, -0.228850, 0.891230, -0.665060, -0.195400, -0.100190, 0.575800, -0.136340, 
0.887480, 1.204910, -0.313600, -0.295170, 0.448240, 0.922030, 0.279670, 0.433180, 1.233800, -0.800180, 

-0.006230, -0.275160, 0.389800, -0.048440, 0.150380, 0.174720, -0.768800, 0.811110, -0.739100, 0.324910, 
0.588740, -0.690640, 0.877890, -0.866320, -0.567580, 0.473980, -0.321740, 0.930170, 0.155420, 0.934280, 
-0.984590, 0.767840, 0.634230, -0.688030, -0.323310, 0.035390, -0.569420, 0.259080, 0.594580, 0.593360, 
-0.863170, 0.301940, 0.308240, 0.214460, -0.089370, 0.557090, -0.596610, 0.734930, 0.748380, 0.718000, 
-0.387960, 0.254380, 0.860460, 0.653740, 0.087330, -0.427380, 0.142540, 0.202680, -0.006980, -0.987690, 

-0.476020, 0.774180, 0.177420, -0.122860, 0.068590, -0.616060, -0.643230, 0.149490, -0.641400, -0.386360, 
0.895100, -0.047790, 0.254340, 0.201620, 0.106640, 0.925990, -0.740910, 1.010730, 0.910470, -0.698670, 
0.529790, -0.376190, -0.542310, 0.392090, 1.212060, 0.928860, -0.652020, 0.582970, -0.508850, -0.308050, 
-0.558790, -0.302650, -0.294460, -0.017210, -0.674540, 0.662560, -0.700110, -0.765490, -1.218150, 1.172960, 
-0.347550, -0.726900, 0.507080, 0.823690, -0.886870, -0.403770, 0.627830, -0.583070, -0.494670, 0.736710, 

0.220110, 0.929810, 1.113660, 0.428210, -0.592980, 0.080390, 0.210550, 0.347200, 0.074010, 0.400520, 
-0.906160, -1.192830, -0.086530, 0.856610, -0.637260, -0.401750, 1.031950, 0.162860, -0.571360, -0.497900, 
1.116390, 0.883690, -0.472800, 1.148250, 0.044840, -0.109980, -0.773250, -0.288180, -0.106860, 0.207550, 
0.666290, 1.167090, 0.207440, 0.727440, -0.218300, -1.062150, 0.349930, 0.322030, 0.707440, -0.261630, 
1.039380, -0.344650, -0.866790, 0.287330, -0.816210, 0.267270, -0.837540, -0.800810, -0.156900, -0.127310, 

0.583870, 0.198600, -0.382800, -0.345730, -0.972510, 0.830230, 0.064100, 0.152530, 0.546440, -0.326450, 
-0.041630, -0.838330, 0.128540, -0.629930, -0.548060, -0.956800, 0.507330, 0.725520, -0.038990, -0.667850, 
-0.843960, 0.517160, -0.425830, -0.270820, -0.358460, -0.934870, 0.256540, 0.479730, 0.450940, 0.311280, 
0.028780, 0.972070, 0.791600, 0.675780, 0.416800, 0.422770, -0.470680, -0.210890, -0.182880, -0.568210, 
0.429840, -0.800610, -0.906170, -0.138640, 0.586090, 0.861910, -1.056140, 0.860320, 0.563690, 0.633520, 

-0.255220, -0.342630, 0.458460, 0.914650, -0.769570, -0.293070, -0.415370, 0.146080, 0.295300, -0.527470, 
-0.586600, 1.009640, -0.154730, -0.705990, -0.024070, 0.210120, -0.072620, 0.738760, 0.731090, 0.886320, 
-0.750400, -0.167500, 0.891590, -0.793830, 0.473790, -0.299990, 0.605280, -0.758790, -0.117520, 0.677390, 
0.620460, -0.030830, 1.049730, 0.205270, -0.776950, -0.729320, -0.276330, -0.055690, 0.824890, -0.834290, 
0.624180, -0.429130, 0.784350, -0.723940, -0.879030, 0.955460, 0.546660, -0.860840, 0.273390, -0.890580, 

0.873900, -0.785080, -0.355340, 0.588370, -0.272360, -0.874600, 0.764410, 0.184400, -0.361700, 0.183290, 
0.672240, 0.437850, 0.904010, -0.904720, 0.857290, -0.572480, -0.287400, -0.522350, 0.411830, 0.348010, 
0.482640, -0.025090, -0.977310, 0.627430, -0.689350, 0.851490, 0.148500, 0.919140, -0.423270, -1.017580, 
0.745970, -0.568650, 0.264890, 0.755220, 0.121620, 0.315730, 0.543160, -0.166940, 0.648610, -0.310690, 
-0.446850, -0.560910, 0.168260, 0.860230, -0.564220, 0.180570, -0.268700, 0.955960, -0.193210, 0.756990, 

-1.094000, -0.689110, 0.246490, 0.030770, 0.737430, -0.651030, -0.095110, -0.383330, 0.303750, -0.417820, 
-0.631610, -0.349320, -0.888450, -0.437000, 0.889210, -0.771630, -1.019820, -0.278980, -0.962020, -0.694530, 
1.057960, -0.771870, -0.420660, 0.471190, 1.094070, 0.423810, 0.964020, -0.412190, -0.814020, 0.332780, 
0.264910, 0.606970, 0.501620, 0.239200, -0.938020, 0.289450, -0.247320, 1.091680, -0.111330, -0.545600, 
-0.370170, -0.127350, -0.411010, -0.574810, -0.261910, 0.094170, -0.236270, 0.491460, -0.368850, 0.425110, 

-0.548130, -0.386910, 0.644330, -0.069090, 0.973300, -0.714290, -0.058390, -0.028920, 0.435580, 0.632810, 
0.610840, 0.414290, -0.914370, -1.048060, -0.358360, -0.130490, 0.559530, 1.016650, 0.209500, -0.361910, 
0.417470, -0.868220, 0.474000, 0.535400, -0.820020, -0.832370, 0.960830, -0.699550, 0.277600, -0.285790, 
0.892600, -1.031060, 0.184640, 1.031300, 0.569040, 0.179930, -0.830000, -0.109330, -0.960470, -0.318500, 
0.790800, 0.679360, 0.367200, -0.563830, -0.372530, -0.617150, -0.150730, 0.867510, -0.841710, 0.671960, 

-0.184560, -0.846310, -0.251910, 0.096640, 0.308150, -0.055370, 0.079290, 0.561720, 0.411840, -0.255570, 
0.129990, -0.769280, -0.498820, -0.442930, -1.046910, 0.789300, 0.468480, -0.861350, 0.016850, 0.721530, 
0.783430, -0.068970, 0.536700, 0.824320, 0.419090, -0.624190, -0.350630, 0.979460, -0.117960, -0.490070, 
-0.702180, 0.915450, 0.897680, -0.760910, -0.644740, -0.583380, -1.155410, -0.282870, 0.997130, -0.628670, 
0.171720, -0.820260, 0.342530, 0.090420, 0.560380, 0.040160, 0.478330, -0.926460, -0.165160, 0.113590, 

0.509220, 0.682820, 0.948280, 0.339660, -0.115120, -0.241880, 0.543800, -0.496200, 0.065050, 0.626300, 
1.105030, -0.320890, 0.838710, -0.805750, -0.087820, -0.960940, -0.297900, 0.535610, -0.909530, -0.348260, 
-0.910320, -0.284660, 0.693420, -0.251300, -0.363770, 0.987670, 0.811800, -0.959700, -0.687900, 0.497190, 
0.201590, -0.439570, 0.431610, -0.721330, -0.330240, 0.605210, 0.027590, -0.339410, 0.674020, 0.585660, 
0.436530, -0.470600, -0.667390, -0.484900, -0.684890, 0.769990, -0.703270, -0.183250, 0.679770, -0.203460, 

0.703440, -0.838870, -0.304470, -0.467470, 0.600820, 0.967780, 0.106130, 0.679360, -0.824850, -0.394840, 
-0.032220, -0.979720, -0.681740, 0.314670, 0.609660, 0.262060, -0.246960, -0.280180, 0.646770, -0.445440, 
0.281670, 0.939180, -0.547500, 0.948800, 0.254720, 0.270810, 0.147350, 0.091960, -0.295860, -0.522340, 
-0.804330, -0.381300, -1.330620, 0.783180, -0.314110, -0.886680, -0.059720, -0.471550, 0.384640, 0.219070, 
-0.299820, 0.875220, 0.669710, 0.360340, 0.386880, -0.459580, 0.695090, -0.813190, 1.163570, 0.431550, 

-0.903170, 0.064040, -0.403790, -0.042160, 0.412970, 0.534890, 0.115400, 0.633700, -1.050010, -0.085470, 
0.070580, -0.282810, -0.253050, -1.185570, -1.032540, 0.198160, 0.792280, -0.573010, 0.543040, -0.629730, 
0.624340, 0.700080, 0.020500, -0.573650, -0.689600, -0.868760, 1.042500, -0.798440, 0.223600, -0.071090, 
-0.523190, 0.961010, 0.135850, -0.169970, -0.360540, -0.748440, 0.675390, 0.968580, 0.734880, 0.765150, 
-0.518170, -0.282350, 0.167010, 0.745020, -0.197130, 0.726230, -0.896720, 0.030890, 0.499830, -0.455420, 

-0.080320, 0.164370, 0.757550, -0.223170, -0.314390, -0.204110, 0.589450, 0.271020, -0.390500, -0.344770, 
-0.605090, 0.469870, -1.186360, -1.016110, -0.374290, 0.165830, 0.807430, -0.762190, -0.415160, -0.362580, 
0.735150, -0.564560, -0.623490, -0.492770, -1.093820, 0.469690, 0.622460, 0.512310, -0.920670, 0.521840, 
0.177930, -0.046840, 0.531160, -0.233670, -0.631340, -0.489120, 0.727670, 0.311400, -0.895920, -0.499670, 
-0.444350, 0.137440, -0.503550, 0.672990, -0.033910, -0.985480, 0.204270, 0.287460, 0.963210, -0.018850, 

-0.759170, 0.039800, -0.177230, -0.896830, 0.824150, -0.679310, -0.265140, -0.773750, 0.665390, 0.611370, 
-0.640420, -0.771630, -0.013500, -0.415390, 0.663820, 0.781000, 0.009840, -0.843610, -0.718680, 0.276920, 
-0.868690, 0.445370, 0.292590, 0.697960, -0.457490, 0.394210, -0.077250, 0.527560, -0.069830, -1.007320, 
-0.188100, 0.114910, 0.339090, -0.635780, 0.440740, 0.762870, -0.066950, -0.117490, 0.332480, -0.210590, 
0.584830, 0.245690, -0.923180, -0.337520, 0.623860, -0.386470, 0.789500, -0.912250, 0.113400, 0.255740, 

1.175360, -0.249400, 0.070990, -1.428100, -1.073330, 0.809890, -0.280620, -0.293700, 0.553650, -0.549490, 
-0.785990, 1.322200, 0.472200, 0.649420, 0.494740, 1.036670, -0.084130, -0.092640, 1.252310, 0.373010, 
-0.813790, -0.427250, -0.707380, -0.620150, 0.196000, 1.354240, 0.760410, 0.113820, -0.656950, 0.568930, 
-1.278080, 0.782240, -0.036830, -0.181760, 1.080780, 0.236990, 1.597930, 0.050610, -1.484050, -0.077050, 
-0.283450, -1.038030, -0.568620, -0.465860, 0.391370, -0.369920, -1.172800, -0.916630, -0.177090, 0.235590, 

0.767520, -0.767710, 0.226880, -0.666250, -0.596820, 0.948850, 0.994710, 0.239410, -0.206110, -0.461790, 
-0.369190, 0.821550, 0.372270, 0.704690, 0.594140, -0.824870, 0.052880, -0.594730, -0.473830, -0.674490, 
0.141610, 0.620550, -0.648980, 0.922730, 0.679830, -0.916400, 0.811680, 0.872710, 0.051140, -0.469390, 
-0.033230, -0.625480, -0.518860, -0.834980, 0.596220, -1.034260, -0.085620, -0.335270, 0.532700, -0.709600, 
-0.063120, -0.714900, 0.040140, 0.411050, -0.406080, -0.025850, -0.000560, 0.109940, 0.051710, -0.797780, 

0.171060, -0.799520, 0.477900, -1.154680, 0.646210, 1.298090, -1.025940, -0.706480, 0.520040, -0.394100, 
1.279140, -0.939520, 1.005540, -0.693740, -0.512710, -1.040760, -0.893180, 0.687910, 2.432920, -0.386760, 


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
      0.0, 0.091390, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.815110, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, -0.002540, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.226270, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.448860, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.835540, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.705950, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.717730, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.591890, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.301880, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.564600, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.317540, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.754470, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, -0.121810, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 0.960970, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.270810, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.602370, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, 0.012510, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.708490, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.534770, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, 0.091040, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.343800, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.032240, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.403480, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.587030, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.000140, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.209680, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.963660, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.862340, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.072880, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.323730, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.382110, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.548000, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.721530, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.890450, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.583680, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.520070, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.485310, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.646500, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, 0.161780, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.240100, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.749090, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.173860, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.333490, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.836560, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.510100, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.356070, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.778800, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, -0.115390, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.159440, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.155950, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.349470, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.951870, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 1.115810, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.697990, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.272660, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.003490, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.489300, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.473160, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.409160, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.057890, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.341510, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.789530, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.701690, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.910930, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, -0.004470, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.698250, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -1.123240, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.634110, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.846280, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.668650, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int a(float *in, float *out, int init)
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
