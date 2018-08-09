/*********************************************************
  vokale.c
  --------------------------------------------------------
  generated at Fri Jun  5 16:49:16 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

#ifdef PHONDURNET

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
-1.030690, 0.575860, 0.070530, 1.058580, 0.208780, -0.169170, 1.058640, -0.963180, 0.151730, -0.733290, 
0.647800, -0.304790, 0.575800, -0.250230, -0.380550, -0.962810, -0.424890, -0.133320, 0.353270, 0.902000, 
0.202800, -0.722280, 0.695230, -0.154510, -0.745720, 0.680520, -0.981900, 0.427690, -0.824780, -0.257340, 

-0.048900, -0.735230, -0.957540, 0.559850, 0.155180, 0.113950, -1.418210, 1.008880, -0.281840, -0.906320, 
1.010510, -1.865710, -0.108820, -0.718040, -0.452750, 0.796970, 0.252490, 1.152680, 0.148760, -0.807400, 
-0.696540, -0.047550, -0.165130, -0.670810, 0.638470, -0.573330, 0.032150, -0.795430, 0.322910, 0.155730, 

0.800970, -0.418740, -0.513710, 0.428550, 0.670030, 0.559550, 0.453680, 0.578430, 0.599100, 0.429170, 
-0.608880, 0.777790, 0.091440, -0.414840, -0.959890, -2.011100, 0.368690, 0.346370, -0.118280, 1.070460, 
-0.658020, 0.861850, 0.205030, -0.737240, 0.519270, 0.174630, 0.894550, 0.377720, -0.461620, -0.589800, 

-0.082110, -0.333930, -0.469700, -0.678050, -0.469790, 0.080530, -0.752160, 0.062060, 0.099430, -0.831030, 
-0.144390, -1.127640, -0.012120, -0.198700, -1.060360, 1.421820, 0.116080, 0.870710, -0.225410, 0.784620, 
-0.329080, 0.991380, 0.365930, 0.103970, -1.001630, 0.209280, 0.424520, 0.086680, 0.303280, 1.071610, 

-0.358840, -0.305530, 0.462090, -0.932650, 0.616430, -0.238040, 0.222340, 0.293900, -0.754570, 0.507270, 
0.455680, 0.802720, -0.584080, 0.358030, 0.185560, 0.261570, -0.666730, 0.671580, -0.283880, 0.912040, 
-0.704320, 1.689710, -0.180500, 0.152300, 0.192980, -0.411750, 0.259080, 0.661930, -0.060060, -1.119090, 

-0.158200, -0.653120, -0.002170, -0.132650, 0.234930, -0.271510, 0.692030, 0.938210, -0.238660, 1.296390, 
-0.585240, 1.081160, -0.660020, -0.818060, 0.426080, -1.337240, 0.509940, -0.576830, -0.100080, -0.651750, 
0.554590, -0.787860, 0.302990, -0.486900, -1.330260, -0.237680, 0.225320, -0.936350, 1.553140, -0.503210, 

0.043710, -0.635980, -0.063900, -0.219800, 0.007540, 0.485620, 1.145130, -1.154210, 0.272930, 0.560930, 
-0.637840, 0.794920, 0.190010, 0.520050, 0.521610, -0.276490, -0.573880, -0.723480, -0.465490, 0.527420, 
0.755060, -0.603570, 0.801010, 0.058250, -0.326230, 0.975880, 0.547880, 0.667540, 0.618510, 0.052720, 

-0.923350, -0.445930, -1.123490, 0.919210, 0.127010, 0.676490, 0.537490, 0.084720, 0.660420, -0.623900, 
0.716240, 0.048350, 0.642930, 0.089840, 1.153730, -0.216600, 0.436100, -0.971530, 0.296940, 0.089210, 
-0.600860, 0.682700, -0.572240, 0.428940, -0.033650, -0.893740, 0.647960, -1.432830, -0.673480, 0.344940, 

-1.372550, -0.884310, -0.332950, 0.737750, 0.799090, -0.524330, 0.098050, -0.892790, -0.364490, -0.988880, 
0.345670, 0.089980, 0.910480, -0.634780, -0.986820, 0.156260, 0.037460, -0.824980, 0.556610, -0.260760, 
0.779110, -0.149180, 0.968850, -0.206880, -0.122780, -0.988030, -0.485310, -0.830360, -0.157960, -0.711220, 

0.724690, -0.158860, 1.269760, 0.085720, -1.259240, 0.690230, -0.233350, -0.633920, 0.188870, 1.064760, 
-0.080350, -1.134880, -0.269390, 1.251160, -0.924280, -0.018580, 1.507460, 0.135910, 0.902980, 0.228560, 
-0.233080, -1.076240, -0.477380, 0.638790, -0.278170, 0.097730, 0.335330, 0.329090, -1.216770, 0.179170, 

1.271980, -0.229600, 0.606390, 0.293630, 1.016760, -0.865570, 1.213870, -0.788490, -0.378120, -0.285450, 
-1.142950, -0.901680, 0.340280, 0.593930, 0.953880, -2.014860, 1.047940, 0.208230, -1.237810, -0.150370, 
-0.251840, 1.001590, 0.168090, -0.117250, -1.088040, 0.309560, 0.218030, 0.829240, 0.190050, 0.847670, 

0.281100, -0.672750, 0.494080, -1.186810, 0.139190, 0.266340, 1.056330, 1.025770, -0.844020, -0.082790, 
1.273690, 0.544410, 0.708460, -0.079680, -0.238350, 0.007760, -0.405190, 0.323140, 0.159050, 0.536000, 
0.417950, -0.163470, -0.585250, -0.946030, -0.129600, 0.298730, -0.947210, -0.620500, 0.807310, 0.666290, 

0.983160, 0.923140, -0.621010, -0.731980, -0.471420, 0.296110, -1.019800, 0.742040, 0.718200, 0.642520, 
0.456610, -0.733940, -0.609570, 0.261290, 0.248770, -0.316330, 0.313490, -0.800810, 0.848790, -0.676320, 
0.328380, 0.411450, -0.253110, 0.675380, 0.796080, 0.652840, -0.516290, 0.146630, -0.030860, -0.336300, 

1.580040, -1.261950, 1.019060, -0.381510, -0.427030, 0.226930, -0.710950, 0.985410, 0.841040, 1.055360, 
-0.802020, -0.839340, 0.057910, -0.765320, 0.449170, 0.424450, -1.033690, 0.055630, -0.745910, -0.044170, 
-0.480750, 0.534930, -0.125750, -0.734740, 0.081030, -0.513410, 0.720510, 0.380790, 0.410350, -0.619680, 

0.001980, 0.687690, 0.171210, -0.042250, -0.430790, -0.189320, -0.569320, 0.147100, 0.255790, 1.026810, 
-0.309920, 0.530220, -0.525300, -0.718810, 1.156790, -1.454640, 0.939450, -0.874400, -0.132910, 0.202590, 
0.698830, -0.806130, 0.126100, -0.638700, -0.054410, -0.747730, -0.140100, 0.016170, -0.239030, -0.960040, 

0.576010, -0.429750, -0.285680, 0.675980, -0.625070, -1.189030, 0.910820, 0.306760, -0.761670, 0.320780, 
0.480500, -1.076580, -0.567520, 0.759090, -0.548840, 0.152250, 0.002580, 0.871370, -0.014730, 0.198760, 
0.436560, 0.088790, -0.894640, 0.578020, -0.746270, 0.147930, 0.495760, -0.938080, 0.030720, -0.911320, 

0.609430, 0.531880, -1.204500, 0.377610, 0.786440, 0.864580, -0.158240, -1.693340, 0.671890, -0.519350, 
-0.537250, 0.100130, -1.279260, -0.197800, 0.313630, -0.738840, 0.869130, 0.799220, -1.426710, 0.091300, 
-0.152120, -0.087180, -1.003940, -0.192100, -0.276870, -0.790600, -1.367300, 0.033550, 0.581290, 0.148020, 

-0.022390, 0.548800, 0.011710, -1.190860, 1.104570, -0.193820, -0.725860, 0.352180, -0.843720, 1.054100, 
0.014500, 0.019040, 1.166910, -0.538630, 0.336460, -0.941380, -0.219590, 0.828830, 0.665520, -0.377190, 
0.559730, 0.194340, 0.076350, -0.765150, -0.066540, -0.489860, -1.099280, 0.466260, -0.427680, 0.794510, 

0.662210, -0.851520, -0.573110, -0.080530, 0.890280, 0.952880, -0.557730, -0.039650, -0.473310, 0.483460, 
0.105840, -0.165800, -0.055730, -0.251860, -0.669320, -0.693970, 0.012700, -0.529490, 0.008390, 0.941350, 
-0.970840, -0.988630, 0.060720, 0.474660, 0.450760, 0.441550, -0.965750, -0.423800, -0.363880, 0.854910, 

-1.150570, 0.665780, -0.243560, 0.747550, -0.931880, 1.017870, -0.598150, 0.387120, 0.589460, -0.132410, 
-0.402750, 1.880570, 0.319040, -0.991630, 0.772610, -1.318540, -0.740460, -0.969590, -0.000570, 0.578140, 
-0.457770, 0.184220, 0.250840, 0.682330, 0.183300, 0.728560, -0.199680, 0.821350, -0.764120, 0.293770, 

-0.065970, 0.585100, 0.585990, 0.491960, -1.055570, -0.644410, 0.593350, -0.065420, -0.905050, 0.313260, 
0.111000, -0.032060, 1.032130, -0.902370, -0.970810, 0.852970, 0.651370, 1.707350, -1.170520, -0.245700, 
0.583960, -0.751330, 0.814320, 0.692680, -0.027890, 0.203350, -0.930690, 0.339860, -0.061100, 1.085180, 

-0.556840, 0.586340, -0.623880, -0.596880, 0.529970, 0.761150, 0.403400, 1.153450, 0.096360, 0.396640, 
-0.136180, -0.229000, 0.502030, 1.092320, 0.703920, 0.302910, 0.031460, 0.338540, 0.957660, -0.784830, 
0.591530, -0.380490, -0.187340, 0.263280, -0.331950, 0.001740, 0.311950, -1.008220, -0.530610, -0.247810, 

0.124260, 1.076480, 0.935830, -0.433140, 0.739800, 0.905470, 0.204550, 0.044850, -0.404280, -0.407450, 
0.163760, -0.921320, 0.349740, 0.118230, 0.474940, -1.365590, -1.110730, -0.231360, -1.098230, 0.516310, 
-0.248040, -0.412910, -0.672760, -0.670410, -0.710680, 0.915840, -1.056640, 0.207140, -0.322690, -0.278020, 

0.442180, 0.800800, 0.456050, 0.230590, -0.893960, -0.152760, 1.616860, 1.134640, -0.957090, -0.528970, 
-0.108060, 0.153470, -1.254000, -0.675250, 0.169660, 1.506160, 0.496410, -0.865190, -1.483850, -0.588140, 
-0.385880, -0.975970, 0.832200, -0.406110, 0.184310, 0.412970, -0.607820, 0.659150, -0.515940, -0.390090, 

-0.483530, -0.424320, -0.194340, -0.408260, -0.097640, 1.002770, 0.341880, 0.844210, 0.179800, -0.771230, 
-0.825530, -0.728380, -0.991960, 0.300050, 0.903940, 0.082660, -0.166060, -1.272450, -1.667960, -1.085130, 
0.719430, 0.499370, -0.029130, 0.045710, 0.524220, 0.241860, 0.259930, -0.401360, 0.116050, 0.487100, 

-0.165170, 0.799810, -0.553210, 1.319610, -0.168190, 0.294280, -0.482320, -0.380580, 0.024410, -0.439430, 
0.044410, 0.467470, -0.305250, 1.035240, 0.015270, -0.118340, 0.761670, -0.482620, -2.495770, 0.191110, 
-0.528140, 1.565900, 0.302440, -1.079140, -1.286050, 0.063730, 0.032990, 0.218060, -0.071470, 0.017860, 

-1.397540, -0.900160, -0.606580, 0.051100, -1.081270, -1.018690, -0.847520, -1.219930, -0.415460, -0.097600, 
-0.596880, -0.325470, 0.366210, -0.660550, 0.368530, -0.081000, 0.739610, 0.706000, 0.824810, 0.113910, 
-0.558160, 0.594530, -0.273890, 0.904240, 0.461300, -0.792510, -0.577660, -0.925510, 0.580230, 0.322490, 

-0.188130, -0.422820, 0.815190, -0.782610, -0.676050, -0.557370, 0.990670, -1.263180, 0.868350, -0.438310, 
-1.514330, -0.252860, -0.477330, -0.428940, 0.371290, -0.075360, 0.343220, 0.193320, 1.979000, -0.508900, 
0.653630, 0.604810, -0.146940, -0.488610, 0.809190, -0.629450, -0.254420, -0.550910, 0.154540, 0.067910, 

-0.250780, 0.687310, 0.699850, 0.164020, -0.683780, -0.246840, 0.432460, 0.612310, -0.037890, 0.916400, 
0.307160, -0.250840, 0.728450, 0.862700, -0.826860, -0.208340, 0.403460, -0.532320, -0.831270, 0.214400, 
-0.687720, -0.278780, -0.891720, 1.054320, 0.287360, -1.038200, -1.450290, -0.471040, -0.843130, 0.468690, 

-0.385640, -0.388050, 1.191890, 0.742820, 0.155970, 0.629430, 1.026510, -0.329580, 0.522470, 1.295060, 
0.523330, -0.147330, 0.346650, -0.574330, 0.145160, 1.014060, -1.049520, 0.171370, 0.715660, 0.001630, 
0.438940, 1.012720, -0.551460, -0.087050, -0.539920, 0.588750, 0.020470, -1.491890, 0.449950, 0.769130, 

-0.547580, -1.082730, -0.839180, -0.128820, 0.213070, 0.532430, -0.229700, 1.243990, 0.472160, 0.021780, 
-0.467090, 0.381460, 0.027570, -0.827330, 0.417740, 0.781530, -0.885060, -0.023570, -0.078270, 0.512530, 
-0.690560, -0.622840, -0.499200, 0.485700, -0.563250, -0.026360, -0.766130, 0.701190, 1.552900, 0.513460, 

0.510800, -0.587730, 0.225400, 0.098110, 0.740570, 0.692500, -0.272250, 0.557310, -0.051100, 0.607630, 
1.274300, -0.468460, 0.713960, 0.567040, -0.831340, -0.859500, 0.348920, 0.298390, -1.707970, -1.087050, 
0.473170, 0.414710, 0.358760, 0.203210, -0.908300, 0.750310, 0.391140, -0.878400, -0.681540, 0.586120, 

0.239990, -0.738390, -0.798930, 0.855120, 0.819010, 0.969720, 0.528230, -0.660340, 0.111800, 1.036070, 
-0.688220, -0.583800, -0.230540, -0.082940, -0.743250, -0.047650, 0.911360, -0.667820, -0.730810, 0.868040, 
-0.596840, 0.283700, 0.336410, -0.211880, 0.857780, -0.912120, -0.568670, -0.718530, 0.940270, 0.307470, 

0.583490, 0.912450, 0.341230, 0.142320, -0.694180, 0.206380, 0.603420, 0.911940, -0.400290, 0.862270, 
-0.379640, -1.160800, 0.529390, 0.159390, -0.141700, -0.297150, -0.651000, -0.544120, 0.849300, -0.050590, 
-1.116390, 0.098120, 0.505900, 0.214680, 0.151830, 0.909840, 1.257310, -0.125280, 0.585180, 1.078050, 

0.118360, -0.372040, -0.618340, 0.191140, -0.642510, 0.197690, -0.049850, -0.359380, 0.843570, 0.376890, 
-0.787600, -1.241250, -0.111340, 0.984570, 0.358450, 0.357270, 0.505590, -0.537380, 0.905790, -0.822320, 
0.467500, -1.006150, -0.876060, -0.441840, -0.046200, 0.490800, -0.056430, 0.147470, 0.015480, -0.928110, 

0.653770, 0.277980, -0.851010, 0.917730, 0.278800, 0.934290, 0.503480, -0.031100, 0.512600, -0.897230, 
0.683150, 1.098220, 0.626990, -0.147310, -0.077500, -0.663820, -0.436740, -0.037940, 0.368430, 0.184330, 
-0.507910, -0.739150, -0.080730, 0.694710, 0.357320, 0.203360, -0.395230, -0.931800, -0.783070, 1.179560, 

-2.196090, 0.504580, 1.571800, -0.093620, -0.906670, 0.392850, 2.503620, 0.343250, 0.873900, 0.353070, 
0.761110, -0.154760, -0.059250, -1.461560, 0.840810, -1.188420, 0.596050, -0.217020, 1.054120, 1.244330, 
-0.549730, 1.190520, 0.734470, -0.324700, -0.596450, 0.314910, -0.061790, -0.465410, -1.407750, -0.260190, 

0.430070, -0.383030, -1.424750, -0.051820, 0.949330, -1.282490, -0.588930, -0.040830, -0.328160, -0.968840, 
-0.129240, 0.469590, 0.126310, -0.649340, 0.666900, -0.390660, -0.146570, -0.605470, -0.830600, 0.051510, 
0.913040, -0.272380, -0.371430, -0.324350, 0.218260, 0.197000, -0.476940, -0.155830, 0.146120, -0.446850, 

0.004700, 0.709760, 0.473940, 1.148810, 0.275930, -0.540950, -0.616080, 0.349220, 0.943530, -0.736170, 
-1.355460, 0.740240, -0.563490, 0.916000, 0.287530, -0.600960, -0.797210, -0.792330, -0.122750, -0.522420, 
0.620070, 0.342630, 0.852770, 0.718120, 0.002200, -0.213350, -0.943880, -0.548760, 0.764910, -0.426430, 

0.895010, -0.604750, -0.945470, -1.457380, 0.072640, 0.524020, -0.353290, -0.675220, -0.540560, 0.116210, 
0.216070, 1.386210, -0.278950, -0.061310, -0.075740, -1.265940, -0.303310, -0.309980, 0.461970, -0.582960, 
0.393920, -0.244620, -0.682090, -0.463490, 0.749060, 1.247050, -1.458110, 0.793570, 0.694310, 0.905960, 

-0.044590, 0.542120, -0.964830, -0.586060, 0.737720, -1.172140, -0.875320, 0.468980, 0.542720, -0.464170, 
0.285200, 1.135820, 0.737060, -0.335900, 0.818040, -1.287900, -0.930140, -0.320950, -0.594440, 0.084180, 
0.420510, 0.481730, 0.251980, -0.201200, 0.859800, 0.711180, 0.066660, -0.521900, 0.282060, -0.038060, 

0.117030, 0.411700, -0.086610, -1.427360, -0.444300, -0.565500, 0.471520, -0.734580, -0.488220, 0.359420, 
-0.321120, 0.334060, 0.384040, 1.465030, -0.677190, 0.021700, 0.989140, -0.855640, -0.411090, 0.948620, 
0.213850, -1.060600, 0.439370, -0.617000, 1.134660, 0.474330, 1.452040, 0.819340, 1.202180, 0.403460, 

0.345210, 0.715000, -0.577140, 0.796110, -0.737240, -0.066170, -0.936890, -0.128960, -0.781590, -0.439960, 
-1.166110, -1.000910, -0.182850, -0.863020, 0.316430, 0.362540, 0.681730, -0.449120, 1.310730, 0.116300, 
-0.592330, 0.120890, 0.623670, 0.661110, -0.691500, 0.652500, -0.522810, 1.087840, 0.248620, 0.672520, 

0.524910, -0.504140, -0.335560, -0.024160, -0.577480, 0.734660, -0.084530, 0.818080, 0.583760, 0.829050, 
0.166470, -1.214540, -1.436590, 0.433020, -1.062520, 0.681670, 0.019910, -0.579300, 0.132230, 0.705740, 
0.548250, 0.136080, 0.604790, -0.319350, -1.672240, -0.295540, -1.139800, 0.754130, -0.531720, -0.732270, 

-0.537310, -0.447640, -0.524170, 0.139150, -1.112270, 1.189540, 0.265030, -0.089860, -0.654140, 0.361230, 
1.214400, 0.750730, -0.795710, -0.939690, 0.674270, -0.443730, -1.064400, 0.549770, -0.303620, 0.734730, 
1.006090, -1.343230, 0.990640, 0.822520, 0.025270, 0.650650, 0.888710, 0.250030, 0.330620, 0.301580, 

-0.106130, 0.286110, -0.207880, -0.823920, -0.722740, -0.543750, -0.981670, -0.406580, -0.575680, -0.413100, 
0.404370, -0.827090, 0.043420, -0.628080, -0.791700, -0.428960, 0.176590, -0.237760, 0.398660, 0.271980, 
0.546000, -0.664700, -0.168140, -0.527630, -0.998700, 0.340220, 0.460520, 0.787390, -0.082530, -0.371070, 

-0.700980, -1.067350, -0.730000, -0.099790, 0.992560, -0.644950, -0.361430, -0.305280, 0.690400, 0.254580, 
-0.845080, -0.332700, -0.147690, -0.991950, 0.807760, 1.003380, -0.545380, -1.092730, 0.811570, -0.415840, 
-0.036180, 1.092940, 0.454030, -0.278880, 1.208910, 0.096030, -0.945540, -0.193840, -0.534150, 0.485270, 

-0.811800, -0.498330, -0.157660, 0.592930, -0.107740, 0.653630, -1.143110, -1.187980, 0.661210, -0.321280, 
0.138860, 0.143200, 0.417070, 1.244470, 0.194140, 1.083970, 1.354580, -0.834570, -0.314250, 0.872720, 
0.068750, -0.178650, 0.161830, 0.717760, 0.504800, -0.323260, 0.349650, -0.503370, 0.973500, 0.021800, 

0.226330, 0.863970, 0.633400, -0.506590, -0.815310, 0.240460, -0.769810, 0.812850, -1.056720, -0.479310, 
0.615620, -1.658320, 0.465310, -1.092950, 0.432270, -0.799020, 0.210120, -0.559150, -0.872340, -0.703730, 
0.131790, -0.301810, -1.034440, 0.193400, 0.396440, -0.930920, 0.001450, -0.672360, 1.025390, -1.111060, 

0.646510, -0.242490, 1.090200, 0.297390, 0.770940, -0.102000, 1.139070, 0.823320, 0.495020, 1.056740, 
-0.055830, 0.565310, 0.174650, 0.115520, 0.014810, 1.196720, -0.165670, -1.066320, -0.039890, 1.057060, 
0.110480, 0.355170, 0.537390, 0.085530, -0.911180, -0.014810, -0.859280, -1.209210, -0.954570, -0.116770, 

-0.624210, -0.627000, 0.026120, -0.698660, 0.017190, 0.958090, 0.240600, -0.381730, 0.420920, 0.070730, 
-0.434940, -0.647460, 0.725050, 0.306480, 0.385210, 0.649840, 0.619060, -0.868880, -0.838280, -0.742250, 
-0.413890, -0.018520, 0.209390, -0.995800, -0.651450, 0.058290, -0.511630, 0.381340, -0.526130, -0.242830, 
0.788270, 0.026000, 0.333490, -0.202060, -0.573990, -0.841380, 0.280760, -0.459370, -0.754490, 0.241120, 
0.381580, -0.453910, 0.578950, 0.039080, 0.074370, 0.347390, -0.675960, 0.500020, 0.442430, -0.744590, 

-1.139120, 0.891100, 0.408760, -0.088490, -0.420880, -0.886600, -0.587370, 0.078250, -0.091940, -1.443430, 
-0.059890, -0.088360, 0.218020, -0.375300, 0.426070, -0.004350, 0.748290, -0.935660, -0.359180, -0.068890, 
0.125700, 0.511510, -0.284700, 0.029210, 0.527290, 0.917410, -0.423290, -1.535280, -0.569800, -1.553420, 
-0.519360, 0.511960, -0.678360, -0.299910, 0.340440, 0.752060, -1.659220, 1.095540, 0.052040, 0.091450, 
1.264440, -0.837920, -0.215210, -0.803760, 1.142630, -0.860920, -1.431460, -0.621350, -1.007260, -0.561940, 

-0.866770, 0.516920, -0.022780, -0.587520, 0.405570, 0.072080, 0.632180, 0.133810, 0.113970, 0.071960, 
1.413480, -1.464860, 0.576760, 0.801150, 0.082410, -0.140530, 0.659140, -0.370690, -0.304620, -1.378440, 
0.498320, -0.883350, 1.028810, 0.970090, 0.314290, -1.294600, -0.617250, 0.692830, 0.464400, -0.531120, 
0.554200, -0.797930, 0.118020, 0.227890, 0.412100, -0.795400, -1.260820, 0.564010, 0.875180, 0.589190, 
0.914990, -0.578410, 0.596710, -1.414960, 0.120840, -0.132410, -0.664730, -0.300150, -1.154780, 0.703320, 

-0.865500, 0.863770, 0.289560, 0.549030, 1.035240, 0.048740, -0.746050, -0.610500, 0.713190, 0.622090, 
-0.298490, 0.496470, -0.350520, -0.211690, -0.708360, 0.730210, -0.342210, 1.039310, 0.038460, 0.305530, 
-0.225590, -0.025850, -0.297330, -0.641270, -0.436590, -0.526600, -0.259060, -0.715750, -0.190400, -0.471010, 
-0.480020, -0.168100, -0.151170, -0.440350, -1.011890, 0.072340, -0.158320, 0.631230, -0.805910, -0.746110, 
-0.115980, -0.774180, -0.829990, -0.012100, -0.636650, 0.379630, 0.208040, -0.375170, -0.754800, -1.215740, 

-0.898640, -0.010720, 0.247180, 0.183760, -0.381030, 0.079260, 0.745110, 0.903980, 0.315560, -0.317260, 
0.723380, 0.824450, 0.782690, -0.601260, 0.568400, -0.032810, 0.263550, 0.278800, 0.311070, -0.812650, 
0.667350, 0.565940, 0.306070, -0.599030, 0.059440, -0.254180, -0.624370, 0.677910, 0.792140, -0.953600, 
0.963760, 0.175370, 0.907240, -0.267870, 0.498040, -0.489070, -0.846770, 0.919550, -0.671530, 0.693770, 
0.378750, -0.701760, 0.866870, -0.663240, 0.219000, 0.137820, -0.041880, 0.407160, -0.308650, 0.027700, 

0.713010, -0.072120, -0.569740, 0.890490, -0.369570, -1.509150, 0.767160, 0.400050, -0.642770, -0.060590, 
1.344880, -1.316510, -0.531550, -1.074280, 0.393830, -1.014420, 0.060650, -0.583050, -0.346540, -0.621930, 
-0.270640, -0.619970, 0.521390, -0.653690, 1.132710, 0.754320, 0.489770, -0.816660, 0.168740, 0.485390, 
-1.022940, 0.652650, 0.934300, -0.724990, 0.691850, -0.153550, -0.320940, 0.277850, -0.209730, 0.766050, 
-0.296030, -0.505010, 0.317270, -0.152980, -1.050400, 0.405240, -0.196080, 0.188310, 0.451310, -0.745380, 

0.233580, -0.706450, -0.722140, -0.829850, 0.278360, -0.925560, 0.181540, -1.047090, -0.330280, 1.156430, 
0.028210, 0.526590, 0.275320, 0.774660, -1.116780, -0.077060, 0.527500, 0.448410, 0.798240, 0.419260, 
0.420570, -0.284710, -0.038040, -0.767100, 0.113480, 0.842000, 0.765070, -0.193790, 0.979710, 1.022940, 
-0.561950, 0.227560, 0.495640, 1.221760, -0.234890, -0.587960, 1.424710, -0.163560, -1.036490, -1.368810, 
-0.424750, 0.231210, 0.302760, -0.062550, -0.252490, -0.799700, 0.183400, 0.782220, 1.111920, 0.065130, 

0.574470, 0.585890, 1.405580, -1.141060, 1.044240, 0.853860, -0.104360, -0.902540, -0.838750, 0.534620, 
0.527870, -0.434890, 0.001990, -0.347200, 0.949020, 0.263170, 0.891210, 1.236100, 0.729260, -0.340490, 
0.288360, 0.675360, 1.056190, 0.083630, -1.282460, -0.790000, -0.499680, -0.594370, 0.988870, -1.061640, 
-1.329250, 0.306330, 0.588030, 0.369460, -1.338860, -0.144010, 0.107480, -0.060940, -0.691670, -0.030000, 
0.095170, 0.596890, -0.293040, -0.386510, 1.272240, -0.935160, -1.002470, -0.252080, 0.369590, 0.926670, 

-1.354110, 0.675230, -0.954690, 0.863640, 1.191220, -0.952220, -0.498070, 0.762820, -0.620220, 0.634360, 
-0.985470, 1.286280, -0.201180, -0.167030, -1.040330, -0.672340, 0.260180, 1.078770, -0.009330, 0.107110, 
0.680890, 0.525710, -1.209130, 0.710780, -0.013150, -0.205590, -1.127360, 1.089570, -0.142550, -0.527060, 
0.949230, 0.482330, 0.853250, 0.056360, -0.041940, 0.239100, -0.929220, -0.262880, 0.978780, -0.487800, 
-0.618650, 0.516880, -0.165110, -0.424400, 0.064490, -0.757030, 0.824240, 0.548540, -0.568890, 0.240700, 

0.071870, -0.306430, 0.867100, -0.761670, 0.038860, -0.573280, 0.988110, 0.591630, -0.941990, -1.473790, 
-0.135290, 0.428120, -0.472060, -0.153030, 0.289750, -0.217260, 1.079780, 0.284610, -0.502130, 1.116800, 
-1.464140, -0.293260, 1.093630, 0.270610, 1.022230, -1.673240, 0.627580, -1.498340, 0.044270, 0.093620, 
0.191090, 0.005590, -0.861240, -0.982730, -0.956530, 1.451030, -1.808860, 1.156960, 0.916370, 1.416310, 
0.746780, -0.868350, 0.216170, -0.293770, -0.382400, -0.283760, 0.715010, -0.854570, -1.360590, 1.220070, 

0.515670, -0.430830, 0.378760, -0.409870, 0.096710, -0.301250, -0.417060, -0.550010, -0.086530, -0.431940, 
-0.774610, -0.094330, 0.976970, -0.208200, 0.251510, -0.758980, 0.127700, 0.456620, 0.728160, 0.320020, 
0.326960, -0.866150, -0.705480, 0.538370, 0.538110, 0.924990, 0.476270, -0.424980, -0.699100, 0.847080, 
-0.791050, -0.906910, -0.505450, -0.872680, -0.807100, 0.961530, -0.486590, -0.981900, -0.453690, -0.511690, 
-0.318620, 0.262670, -0.401260, 0.010790, -0.651010, 0.573730, -0.101910, 0.245430, -0.703440, -0.959770, 

0.727020, -1.151600, 0.811100, -0.227180, -0.582430, -0.538230, -0.470500, 0.270940, 0.145040, 0.302150, 
-0.428450, -0.892980, -0.464040, -0.734670, -0.092720, 0.419890, 0.860020, 0.297610, -0.859070, 0.982760, 
-0.281570, 0.236880, -0.938590, 0.555670, -0.962660, -0.248680, 0.250050, 0.462240, -0.932000, 0.242960, 
-0.393430, 0.465380, 0.748850, 0.496570, -0.229070, -0.430250, -0.851620, -1.018780, 0.101870, 0.487450, 
0.746300, 0.510420, -0.275060, -0.350160, -0.865300, 0.697190, -0.181250, 0.616840, -0.519980, -0.663040, 

1.096890, -0.041930, -0.907580, 0.570460, 0.193130, 1.439450, 0.123450, 0.215240, 0.222650, 1.009640, 
-0.750180, 1.387530, 0.193910, -1.243830, -0.640370, 0.313180, -1.024000, 0.902240, 0.917590, -0.910230, 
0.223020, 0.101160, 0.930020, -0.478280, -1.140690, -0.203900, 1.392420, 1.012900, -0.129200, 0.857790, 
1.130590, -0.307770, -0.661160, 1.360640, 1.248590, -0.688530, -0.351730, -0.442080, -1.006190, 0.665000, 
-0.363600, 0.823890, 0.997590, 0.724130, -0.083800, 0.349660, -0.168800, 0.066330, -0.564010, 0.103820, 

-0.001470, 0.247920, -0.123370, -0.923680, 0.885780, -0.573620, -0.349860, -0.635290, -0.246040, 0.600980, 
0.372190, 0.758780, -0.444240, 0.004950, 0.852980, -0.131760, -0.756960, 0.475580, -0.739520, 0.196880, 
0.315390, -0.748240, -0.926010, 1.189600, 0.929740, 0.044530, -0.206400, 0.827430, -0.731290, -0.953560, 
-0.271770, -0.953160, 0.558340, -0.356340, -0.540060, -0.312270, -0.558850, 0.951420, -0.403350, 1.019400, 
0.265970, 0.344970, -0.418290, 0.790430, -0.216090, -0.048640, 0.480550, 1.164230, 0.532820, 0.402230, 

0.447000, 1.267840, -1.062950, 0.819160, -0.238200, -0.057660, 0.604010, 0.859280, 0.744540, -0.322760, 
0.408130, 0.179330, -0.649180, -0.019340, -0.872860, -0.766010, 0.570830, -0.984810, -0.660470, -1.455530, 
-0.956250, -0.020960, 0.701650, 0.884150, 0.413280, 0.090090, 0.506350, -0.785660, 0.776050, 0.355180, 
-0.642720, 0.438670, -0.168370, -0.142840, 0.272480, 0.473530, 0.802250, -1.130630, -0.809410, -0.349840, 
-0.950970, -0.994750, 0.797560, 0.023840, 1.368900, 0.709870, -0.476630, -0.243410, -0.795400, 0.988410, 

-0.998140, 0.771060, -0.053090, -0.526150, 0.772150, -0.571340, 0.819630, 0.356350, -0.504970, -0.821550, 
1.165320, 0.577380, 1.010470, 0.649170, -0.642650, -0.819070, 0.071100, 0.115730, 0.664770, -0.915010, 
-0.313060, 0.254990, -0.354850, 1.066840, -0.570200, -0.820520, -0.527690, 0.001260, 0.980910, 0.725190, 
-0.825130, 0.337560, -0.573820, 0.565730, -0.543760, -0.770610, -1.203940, -0.054120, -0.047020, -0.119030, 
-0.133470, -1.495480, 0.666870, -0.195310, 0.911330, 0.213320, -0.020800, -0.687160, -0.320180, -0.615510, 

0.117920, 0.723130, -0.077780, 0.395470, -1.301650, -0.279270, 0.547420, -0.859630, -0.089490, -0.388280, 
-0.912250, -0.832910, 0.309370, 0.775760, -0.544630, -0.305710, -0.256360, 0.697290, -0.102450, -0.118810, 
0.845830, -1.083740, 0.429410, 1.285390, -0.049710, -0.810940, -0.910600, -0.484700, -0.261600, 0.560320, 
-0.106880, -0.236740, -1.008770, 1.087870, 0.619700, -0.338480, -0.972050, -0.973070, 0.074880, -0.866660, 
-1.106210, -0.313700, 0.636490, 0.925830, -0.055240, -0.242030, 0.105940, 0.281670, -0.135940, -0.434340, 

0.160240, 0.128280, -0.729280, 0.965150, -0.271810, 0.816330, -0.189290, -0.747940, 0.262020, 0.741480, 
-0.087980, 0.480940, -0.106080, -0.032010, 0.970410, 0.214530, -0.538610, 0.420250, 0.099460, -0.135850, 
-1.205620, 0.093620, 0.614030, -0.095080, 0.551970, -0.530880, 0.621340, 0.143760, 0.429980, -0.758090, 
0.370550, -0.869860, -0.978760, 0.002730, 0.730190, 0.621980, -0.755450, 0.137050, -0.693210, -0.592430, 
0.842850, 0.775710, -0.615770, -0.087550, -0.664030, 1.032110, -0.999470, 0.125360, 0.063640, -0.665450, 

0.415800, -0.653930, -0.799830, -0.748490, -0.269310, 0.545990, -0.241340, -1.064140, -1.125420, 0.137140, 
0.033670, -0.293360, 0.032100, 1.741670, 0.142340, 0.856240, 0.055820, -0.272810, 0.834420, -0.658300, 
1.733500, -1.013090, 0.578760, 2.147490, 1.284220, 1.216120, -0.733890, -1.137900, 0.206190, 0.601780, 
0.744150, 2.041660, -0.079450, 0.060890, 0.143270, 0.276240, 1.206470, 0.712570, 0.483420, -1.264120, 
0.162910, 0.707410, -1.159170, 0.014550, 0.882480, -0.716290, -0.858840, 0.009600, -0.086140, 1.376820, 

-0.731730, -0.171070, 0.070990, 0.058060, -0.117150, -0.596070, 0.230640, -0.167350, -0.911310, -0.276290, 
-0.734960, 0.408640, -0.560820, -0.031330, -1.225460, 0.450810, -0.859800, -0.393860, -0.729570, -0.153690, 
-0.477290, -0.026850, 0.826070, 0.703360, -1.193560, 0.758190, 0.621780, -0.624230, 0.587200, -0.208970, 
-0.678110, -0.414950, -0.833560, -0.051810, -0.811450, 0.371030, 0.701700, 0.262140, 0.680410, -0.507150, 
-0.689980, -0.231050, 0.234970, 1.100740, 0.648230, -0.493010, -0.686300, -0.000920, -0.833130, 0.463920, 

0.034940, 2.261290, 1.155630, -0.990830, -0.382710, 1.688870, -0.883090, 1.278730, 1.528280, 1.574950, 
-0.485430, -0.535710, -1.897370, -0.638550, 1.366010, 0.900500, -1.165560, 0.868120, -2.946950, -0.560270, 


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
      0.0, 0.223060, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.235910, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, -0.220170, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, -0.080300, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.357810, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.615030, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.906130, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.874780, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.350980, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.381860, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.685880, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.095340, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.724900, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.439970, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 1.061520, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.200690, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.667520, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.144670, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.351960, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.748350, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.082870, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.377490, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.019740, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.511010, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.326030, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.173240, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.332140, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.758320, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -1.214450, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.355510, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.464340, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.212300, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.515680, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.767190, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.923460, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.688490, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.155480, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.192240, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -1.191480, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, -0.350380, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.166420, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.960440, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.415440, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, -0.228560, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.477450, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.367920, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.517140, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.762340, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.596270, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.294880, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.141300, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.077030, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.621460, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.909320, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.775600, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.170030, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.078690, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.467380, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.406440, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.695140, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.162300, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.559220, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.277030, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.560940, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.887990, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, -0.118470, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.738960, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -0.986010, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.973340, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.668840, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.501750, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int vokale(float *in, float *out, int init)
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
