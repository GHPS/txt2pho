/*********************************************************
  aa.c
  --------------------------------------------------------
  generated at Fri Jun  5 18:10:45 1998
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
-0.988840, 0.538540, -0.128870, 0.995450, 0.410280, -0.113070, 1.001050, -0.924320, 0.263920, -0.785630, 
0.322920, -0.287300, 0.177300, -0.063260, -0.295580, -0.617600, -0.287220, 0.237640, 0.308440, 0.682470, 
0.307170, -0.926420, 0.546480, -0.248790, -0.124940, 0.426970, -1.115010, 0.312090, -0.564430, -0.109370, 

-0.371730, -0.751950, -0.896060, 0.870750, -0.029180, 0.156890, -1.024780, 0.666160, -0.688020, -0.756730, 
0.259770, -0.724800, -0.267490, -0.437930, -0.315230, 0.498670, 0.290930, 0.469130, 0.289010, -0.552330, 
-0.879430, 0.250550, -0.322270, -0.699320, 0.284590, -0.487090, 0.063110, -0.752680, 0.329310, 0.490470, 

0.689120, -0.374510, 0.066470, 0.349360, 0.854590, 0.980940, 0.507750, 0.327340, 0.357870, 0.326100, 
-0.339390, 0.643590, -0.116630, -0.618860, -0.982800, -0.929650, 0.370860, 0.490360, -0.672790, 0.953130, 
-0.671420, 0.902430, 0.006490, -0.689690, 0.534820, 0.039510, 0.817410, 0.337030, -0.619750, -0.432350, 

-0.180930, -0.360280, -0.325240, -0.482650, -0.707190, -0.435370, -0.842150, 0.094300, 0.089820, -0.873620, 
-0.384810, -0.709860, 0.036210, -0.819300, -0.923790, 0.619320, 0.111810, 0.901560, -0.571790, 0.871120, 
-0.298420, 0.524290, 0.608030, 0.311660, -0.909900, 0.532470, 0.487670, -0.022280, 0.174280, 0.836220, 

-0.626250, -0.356020, 0.390050, -0.713820, 0.332910, -0.115280, 0.418210, 0.643230, -0.886440, 0.481510, 
0.502980, 0.504410, -0.297520, 0.577130, 0.322840, 0.236170, -0.803690, 0.506440, -0.593960, 0.853820, 
-0.663900, 0.891540, -0.286760, 0.245850, 0.803540, -0.235300, 0.291090, 0.908310, -0.393020, -0.889820, 

0.083780, -0.642910, -0.183440, -0.033980, 0.505660, -0.016930, 0.348510, 0.905560, -0.229550, 0.937450, 
-0.804650, 0.809330, -0.842610, -0.787170, 0.448610, -0.350460, 0.313810, -0.715240, 0.012080, -0.695470, 
0.766710, -0.498720, 0.239920, -0.674910, -0.653700, -0.242560, 0.476750, -0.830950, 0.957430, -0.229830, 

-0.090570, -0.693070, 0.419410, -0.054510, 0.206600, 0.417920, 0.813800, -0.511630, 0.197560, 0.503690, 
-0.104930, 0.134820, 0.334560, 0.487010, 0.488220, -0.669830, -0.642710, -0.540890, -0.851070, 0.550130, 
0.722450, -0.328410, 0.787230, -0.189380, -1.078720, 1.015460, 0.543020, 0.311400, 0.504630, 0.051380, 

-0.690030, -0.456470, -0.917040, 0.854780, -0.021090, 0.453170, 0.330750, -0.081720, 0.875700, -0.372540, 
0.883760, 0.011170, 0.323700, 0.569360, 0.602710, 0.122040, 0.292260, -0.963830, -0.186880, 0.168480, 
-0.813400, 0.096500, -0.504510, 0.264140, 0.506970, -0.831360, 0.334010, -0.983360, -0.877860, 0.455650, 

-0.599020, -0.853360, -0.124210, 0.757940, 0.925520, -0.550630, -0.106310, -0.645000, -0.259190, -1.115880, 
0.376060, 0.402990, 0.701000, -0.468300, -0.621020, 0.486890, 0.339740, -0.931630, 0.228310, -0.236930, 
0.946130, -0.348850, 0.972570, -0.021390, 0.055580, -0.984300, -0.228670, -0.646450, -0.487360, -0.365600, 

0.927200, -0.199620, 0.910150, 0.151580, -0.977770, 0.396400, -0.489870, -0.974960, 0.258960, 0.765580, 
-0.543430, -0.541080, -0.372640, 0.527950, -0.456670, -0.074670, 0.952700, 0.188660, 0.308470, 0.047760, 
0.161170, -0.570010, -0.651240, 0.698520, -0.456640, -0.194130, 0.750220, 0.350190, -0.730770, 0.160440, 

0.632600, -0.065450, 0.711470, 0.583110, 0.914930, -0.159720, 0.667160, -0.925680, -0.371000, -0.146830, 
-0.860610, -0.053140, 0.201620, 0.286410, 0.450770, -0.923640, 0.338010, 0.167060, -0.819710, 0.117180, 
-0.669550, 0.416020, 0.102830, -0.473630, -0.427180, 0.618830, -0.084080, 0.584980, 0.121980, 0.712900, 

0.167850, -0.889100, 0.711740, -0.794850, 0.405940, 0.511850, 0.842290, 0.821720, -0.773880, -0.140140, 
1.061470, 0.512940, 0.781440, -0.132990, 0.102500, 0.626260, -0.329470, -0.069210, -0.403620, 0.538420, 
0.632420, 0.219380, -0.606780, -0.984580, 0.195930, 0.371690, -0.584980, -0.749380, 0.674080, 0.885490, 

0.856240, 0.887850, -0.642570, -0.679450, -0.436030, 0.383750, -0.914420, 0.485860, 0.682020, 0.685570, 
0.467720, -0.587520, -0.445130, 0.172580, 0.358890, -0.203790, 0.247290, -0.915410, 0.831900, -0.655340, 
0.376690, 0.786690, -0.258470, 0.548230, 0.393430, 0.668930, -0.379590, 0.058830, -0.038750, -0.626510, 

1.160020, -0.972490, 0.417540, -0.739130, -0.627110, 0.393150, -1.056320, 0.714520, 0.785800, 0.883840, 
-0.706430, -0.737430, 0.335920, -0.404950, 0.024390, 0.232530, -0.894640, 0.283480, -0.130900, -0.072800, 
-0.365490, 0.869840, -0.076690, -0.448930, -0.391400, -0.522890, 0.937270, 0.138360, 0.598950, -0.493160, 

0.689600, 0.866880, 0.425430, -0.241930, -0.343620, -0.011590, -0.640110, 0.394350, 0.232530, 0.793950, 
-0.073760, 0.044440, -0.664370, -0.857330, 0.764710, -0.698620, 0.599660, -0.665140, -0.110020, 0.122430, 
0.618730, -1.036860, -0.030460, -0.752150, -0.293040, -0.956820, -0.360340, 0.555430, -0.498090, -0.923890, 

0.716420, -0.414490, -0.554190, 0.665600, -0.350030, -0.861250, 0.895660, -0.018050, -0.685450, 0.013370, 
0.584670, -0.276330, -0.863400, 0.576550, -0.248160, 0.702150, 0.339620, 0.505670, 0.558130, -0.075860, 
0.703160, -0.028820, -0.919430, 0.674390, -0.208580, -0.042280, 0.576960, -0.891670, -0.038970, -0.811510, 

0.504780, 0.467730, -0.807680, 0.029660, 0.834640, 0.609480, -0.700660, -0.971550, 0.719120, -0.544470, 
-0.154170, -0.456530, -0.846560, -0.014930, 0.113950, 0.137700, 0.344630, 0.560600, -0.423290, 0.701500, 
-0.259030, -0.627960, -0.965230, -0.531230, -0.606400, -0.973790, -0.884040, -0.246820, 0.432780, 0.538160, 

-0.576480, 0.490640, -0.010200, -0.663590, 0.960600, -0.309850, -0.799630, 0.225410, -0.933610, 1.161970, 
-0.184530, -0.046420, 0.994810, -0.517350, 0.694810, -0.968070, -0.236670, 0.411630, 0.232230, -0.513350, 
0.566000, 0.375750, -0.110010, -0.732100, 0.046690, -0.446790, -1.186110, 0.535180, -0.466060, 0.919450, 

0.746650, -0.893150, -0.913360, -0.014740, 0.709320, 1.018780, -0.431790, 0.080500, -0.498200, 0.509700, 
-0.099920, -0.139060, -0.092440, -0.138090, -0.496390, -0.738490, -0.323920, -0.537920, 0.287390, 0.984130, 
-0.912110, -0.746590, -0.173500, 0.297330, 0.615090, 0.244570, -0.822150, -0.281190, -0.434180, 0.925310, 

-0.714270, 0.944110, 0.194130, 0.725920, -0.552310, 0.840480, -0.163330, 0.906320, 0.762490, 0.041470, 
-0.540140, 0.973520, 0.240000, -0.758030, 0.813670, -0.821850, -0.780470, -0.439890, -0.257140, 0.746600, 
-0.337780, 0.067500, 0.341870, 0.685660, 0.104200, 0.693340, 0.154690, 0.938700, -0.691230, 0.349400, 

0.182940, 0.551090, 0.072090, 0.396390, -0.838940, -0.138400, 0.885570, 0.229110, -0.789030, 0.368590, 
0.011100, 0.212630, 0.816960, -0.947080, -0.533090, 0.396330, 0.439120, 1.093920, -0.486610, -0.301470, 
0.775280, 0.116080, 0.842220, 0.754660, 0.438560, 0.116150, -0.673880, -0.044890, -0.279510, 0.701820, 

-0.401300, 0.541640, -0.549720, -0.694450, 0.486440, 0.409980, 0.650580, 0.698200, 0.048620, 0.443940, 
-0.377730, -0.203350, 0.199270, 0.961460, 0.468320, 0.561470, -0.132570, 0.314890, 0.438570, -0.726570, 
0.511030, -0.527380, -0.235410, 0.176250, -0.151120, -0.024860, 0.237320, -0.741380, -0.888880, -0.119060, 

-0.235900, 0.902280, 0.726360, -0.213800, 0.602030, 0.923210, 0.044850, 0.151490, -0.411400, -0.545900, 
-0.056150, -0.935570, 0.041290, 0.081150, 0.404240, -0.985650, -0.990240, -0.340300, -0.671920, 0.520140, 
-0.056740, -0.581640, -0.609010, -0.752020, -0.789220, 0.769170, -0.728590, 0.009450, -0.322510, -0.568810, 

-0.046690, 0.863760, -0.357130, -0.144390, -0.999680, -0.087310, 1.062560, 1.037410, -0.940350, -0.510550, 
0.238010, -0.060220, -0.927230, -0.435660, -0.077200, 0.859690, 0.679000, -0.861090, -0.948440, -0.599020, 
-0.326470, -0.082470, 0.973430, -0.276850, -0.141510, 0.411000, -0.473350, 0.232660, -0.246840, -0.718920, 

-0.337370, -0.244990, -0.077790, -0.425780, -0.121020, 1.091240, 0.653890, 0.923120, 0.279820, -0.755850, 
-0.655060, -0.821480, -0.891060, -0.132090, 0.644570, -0.277200, 0.072880, -0.824410, -0.504960, -0.948390, 
0.796280, 0.699060, 0.208170, 0.153410, 0.251570, 0.329650, 0.512790, -0.499150, 0.096010, 0.143690, 

0.543370, 0.761760, -0.674600, 0.816200, -0.461530, 0.635380, 0.066940, -0.417860, 0.136660, -0.025440, 
-0.008840, 0.260510, -0.219050, 0.939890, -0.057530, -0.668230, 0.564530, 0.088950, -1.027570, -0.111650, 
-0.318810, 0.890170, 0.271400, -0.917060, -0.382870, 0.180910, -0.096320, 0.276800, 0.042420, 0.362420, 

-0.493420, -0.898320, -0.181150, 0.384370, -0.745970, -0.754950, -0.764950, -0.950110, -0.038410, -0.256380, 
-0.411510, -0.239470, -0.199300, -0.768160, 0.555020, 0.728570, 0.864840, 0.925390, 0.758450, 0.091950, 
-0.379900, 0.374880, -0.271070, 0.950210, 0.668800, -0.930110, -0.384470, -0.794820, 0.394630, 0.246630, 

-0.170900, -0.357700, 0.797630, -0.269640, -0.607840, -0.563580, 0.331160, -0.945440, 0.743930, -0.720050, 
-0.619650, -0.253970, -0.296450, 0.441790, 0.633120, -0.014350, 0.550010, -0.213480, 0.668090, -0.593950, 
0.566520, 0.391150, -0.141910, -0.227540, 0.868280, -0.347710, -0.525030, -0.097690, -0.123750, 0.371710, 

-0.103430, 0.594760, 0.475070, 0.066660, -0.757000, -0.030570, 0.519870, 0.810240, -0.229890, 0.793110, 
0.050450, -0.237870, 0.971890, 0.523750, -0.479490, 0.007690, 0.652450, -0.511060, -0.350010, 0.360300, 
-0.522040, -0.428640, -0.899230, 0.932990, 0.154560, -0.998210, -0.989960, -0.425510, -0.797950, 0.139460, 

-0.183220, -0.404950, 0.565100, 0.632000, 0.201650, 0.561620, 0.688720, -0.305360, 0.492010, 0.974760, 
0.236310, -0.214170, 0.414320, -0.076020, 0.426660, 0.709290, -0.820750, 0.018220, 0.532320, -0.405180, 
0.883430, 0.721730, -0.589140, -0.183230, -0.724800, 0.569240, 0.318900, -1.080730, 0.481570, 0.681530, 

-0.526000, -0.846330, -0.756150, 0.369530, 0.224780, 0.489540, -0.688710, 1.043940, 0.525330, -0.346700, 
-0.202210, 0.404190, -0.158910, -0.462170, 0.402940, 0.488130, -0.740800, -0.032000, -0.476650, 0.483050, 
-0.515910, -0.134680, -0.263050, 0.465990, -0.408740, 0.062190, -0.544790, 0.890290, 0.937830, 0.391470, 

0.859220, -0.635610, 0.007580, 0.017160, 0.510800, 0.640630, 0.247500, 0.369660, -0.040010, 0.872310, 
0.969310, -0.368970, 0.572530, 0.697090, -0.870420, -0.859010, 0.731660, 0.305900, -0.433170, -0.966270, 
0.558460, 0.128030, 0.230070, 0.135960, -0.866680, 0.722450, 0.660970, -0.642060, -0.801480, 0.462710, 

0.191120, -0.783680, -0.834800, 0.966020, 0.811780, 0.777640, 0.722280, -0.662600, -0.022000, 1.017390, 
-0.499850, -0.692940, -0.237110, -0.350860, -0.683300, 0.099720, 0.771660, -0.725790, -0.730580, 0.937310, 
-0.706520, 0.057510, 0.211170, -0.284770, 0.826240, -0.885900, -0.661100, -0.851100, 0.844540, 0.146780, 

0.627950, 0.709190, 0.248710, 0.451610, -0.872450, 0.385290, 0.446540, 0.652480, -0.438910, 0.534930, 
-0.103310, -0.809970, 0.238730, 0.125740, -0.151180, 0.355110, -0.862710, -0.968540, 0.753800, -0.622530, 
-0.885430, 0.066130, 0.507010, 0.220440, 0.234560, 0.957700, 0.976470, -0.599000, 0.591520, 0.627330, 

0.113970, -0.435250, -0.602150, 0.160120, -0.694710, -0.065620, -0.447340, -0.676320, 0.883200, 0.266960, 
-0.393470, -0.816730, -0.146290, 0.965690, 0.518710, 0.106450, 0.325880, -0.351000, 1.066530, -0.778210, 
0.504390, -0.657890, -0.822660, -0.502950, -0.066420, 0.265280, 0.015640, 0.180850, 0.162640, -0.923860, 

0.705870, 0.406200, -0.798690, 0.640270, 0.404660, 0.842840, 0.436020, -0.367200, 0.674350, -0.517140, 
0.351100, 0.649580, 0.316560, -0.349080, -0.644380, -0.298000, -0.273980, 0.250600, 0.185100, 0.473590, 
-0.617060, -0.711910, -0.238530, 0.533310, -0.050150, 0.178270, -0.266800, -0.881540, -1.045370, 0.744150, 

-1.073240, 0.466030, 0.829410, 0.762820, -0.341510, 0.082180, 1.643490, -0.151730, 0.329670, -0.041090, 
0.611010, -0.267860, -0.498790, -0.613830, 0.859940, -1.008700, 0.810630, 0.333800, 0.731950, 0.580690, 
-0.710610, 0.739950, 0.853360, -0.513290, -0.130550, 0.914100, -1.045310, -0.337040, -0.824510, -0.839140, 

0.482970, -0.236980, -0.861930, 0.371750, 0.924610, -0.793610, -0.136000, -0.157550, -0.340980, -0.789800, 
-0.302500, -0.113730, 0.391180, -0.778180, 0.311450, 0.377700, -0.281520, -0.442540, -0.791710, 0.310460, 
0.842640, -0.541640, -0.401090, -0.442230, 0.013980, 0.058040, -0.286880, 0.048770, -0.166650, -0.697430, 

0.185420, 0.928440, 0.516710, 1.013100, 0.493320, -0.497480, -0.188690, 0.440300, 0.826820, -0.621960, 
-1.063490, 0.366720, -0.413390, 0.837130, 0.358100, -0.703120, -0.414020, -0.684910, 0.332030, -0.405720, 
0.636270, 0.711190, 1.059210, 0.793520, -0.330970, -0.079040, -0.750280, -0.080890, 0.754080, -0.894630, 

0.956230, -0.779720, -0.208170, -0.856840, 0.104310, 0.606460, -0.819690, -0.450990, -0.509630, 0.216470, 
0.667970, 0.716770, -0.075770, -0.563170, -0.151000, -0.811630, 0.065360, 0.010460, 0.150310, -0.252910, 
0.743020, -0.729980, -0.624470, -0.350250, 0.840020, 0.991450, -0.536990, 0.947000, 0.471040, 0.618220, 

-0.011060, 0.659100, -0.643520, -0.332400, 0.685180, -1.005570, -0.719160, 0.476010, 0.516950, -0.557380, 
0.811870, 0.754690, 0.800790, -0.063070, 0.364560, -0.721210, -0.838180, 0.272560, -0.562600, 0.208910, 
0.305600, 0.232330, 0.319300, -0.247620, 0.740390, 0.777990, 0.041350, -0.005220, 0.398790, 0.021880, 

0.542050, 0.606930, -0.055920, -0.680760, -0.175910, -0.240690, 0.725080, -0.621640, -0.395460, -0.171710, 
-0.470540, -0.066050, 0.117890, 0.806130, 0.064410, 0.473580, 0.515560, -1.010320, 0.327970, 0.786820, 
-0.019700, -1.010750, 0.328840, -0.591260, 0.743910, 0.587340, 0.855370, 0.714860, 0.544140, 0.635640, 

0.043980, 0.532290, -0.214920, 0.865790, -0.747760, -0.523540, -0.987350, 0.005310, -0.761990, -0.430780, 
-0.778710, -0.515140, -0.278500, -0.253220, 0.522230, 0.506660, 0.872220, -0.490790, 0.725340, 0.221710, 
-0.778930, -0.000210, 0.702120, 0.683280, -0.568920, 0.665280, -0.696250, 0.891950, 0.212040, 0.921820, 

0.383660, -0.608050, -0.455380, -0.252670, -0.550810, 0.498490, -0.767150, 0.908420, 0.706980, 0.831090, 
0.349510, -0.684940, -0.857190, 0.152240, -0.780690, 0.599700, 0.269140, -0.946790, 0.419090, 0.163220, 
0.828360, 0.847750, 0.750260, -0.405870, -1.509640, -0.191910, -1.280560, -0.211840, -0.712530, -0.767200, 

-0.012100, -0.469940, -0.986430, 0.105010, -0.833470, 0.727550, 0.436440, -0.195810, -0.710890, 0.379020, 
0.627900, 0.892250, -0.867030, -0.428920, 0.529980, -0.105700, -0.677510, 0.815250, 0.196120, 0.903750, 
0.833590, -0.986100, 0.970410, 0.531190, 0.230530, 0.759430, 0.813080, 0.095830, 0.399110, 0.283340, 

-0.099790, 0.174080, -0.242970, -0.870710, -0.658740, -0.686480, -1.024390, -0.362470, -0.590180, -0.493840, 
0.302090, -0.770300, 0.166340, -0.708820, -0.751740, -0.296770, 0.248910, -0.378570, 0.388940, 0.182650, 
0.622000, -0.875750, -0.165490, -0.525060, -0.966680, 0.428280, 0.512960, 0.559350, -0.203800, -0.357350, 

-0.808330, -0.860060, -0.299460, 0.046300, 0.990450, -0.694550, -1.072700, 0.385540, 0.747380, 0.348770, 
-0.507390, -0.852120, -0.172660, -0.652380, 0.631530, 0.644590, -0.253110, -0.958610, -0.296510, -0.291210, 
-0.089830, 0.921060, 0.512490, -0.155110, 0.442240, 0.364190, -0.917830, 0.094060, -0.676220, 0.342060, 

-0.884890, -0.590860, -0.082190, 0.598890, 0.140710, 0.825010, -0.379770, -0.331670, 0.561390, -0.137480, 
-0.105050, 0.317690, 0.897700, 0.868650, 0.782260, 0.105130, 0.834540, -0.657150, 0.058070, 0.777670, 
0.006640, -0.633170, 0.128280, 0.702130, 0.824460, -0.314210, 0.202720, -1.069850, 0.940350, 0.734840, 

0.594570, 0.839940, 0.449980, -0.380490, -0.876320, 0.438120, -0.749270, 0.889550, -0.984220, -0.714470, 
0.025850, -0.915930, 0.852590, -0.819720, 0.478110, -0.545070, 0.281750, -0.725830, -0.551780, -0.463450, 
0.128310, -0.261440, -0.964810, 0.259830, -0.108590, -0.859710, 0.257840, -1.027730, 1.004320, -0.399240, 

0.705120, -0.005800, 0.769990, 0.397580, 0.613550, 0.167560, 0.803750, 1.085080, 0.518660, 0.901390, 
0.040290, 0.220900, 0.125050, 0.305810, -0.100710, 0.810490, -0.160400, -0.915840, 0.415030, 0.998750, 
0.323310, 0.758620, 0.665390, 0.113700, -0.615440, 0.068160, -0.577700, -1.017770, -0.775590, -0.015210, 

-0.683990, -0.465260, 0.124120, -0.722380, 0.063500, 0.954020, 0.405850, -0.224340, 0.366450, 0.063690, 
-0.292400, -0.587050, 0.849750, 0.337750, 0.496620, 0.622390, 0.699640, -0.708050, -0.776900, -0.728510, 
-0.488440, 0.113990, 0.259900, -0.977870, -0.560690, 0.062530, -0.577120, 0.438750, -0.524480, -0.155440, 
0.759800, 0.064390, 0.410550, -0.157790, -0.553870, -0.731730, 0.321220, -0.384910, -0.724850, 0.315050, 
0.487420, -0.402730, 0.594460, -0.015130, 0.212350, 0.360120, -0.653790, 0.574270, 0.503440, -0.686540, 

-1.213590, 0.775620, 0.710100, 0.396560, -0.239130, -0.591640, -0.901080, -0.130810, 0.309320, -0.504030, 
-0.143320, 0.232160, 0.595180, 0.362460, 0.464870, 0.448680, 0.746820, -0.886330, -0.221900, -0.258470, 
0.373510, 0.374430, -0.613710, -0.164180, 0.401530, 1.045640, 0.144770, -0.379760, -0.656700, -1.007770, 
-0.445100, 0.426560, -0.802240, 0.130620, 0.375120, 0.742800, -1.355280, 0.765180, -0.241920, 0.323330, 
1.033280, -0.574250, -0.034750, -0.886690, 1.174070, -0.915550, -1.124830, -0.460710, -0.923810, -0.180010, 

-0.395660, 0.238260, -0.152230, -0.522620, 0.433200, -0.161720, 0.336010, 0.345590, 0.656530, 0.409250, 
0.813160, -1.091340, 0.397660, 0.645880, -0.098620, 0.102100, 0.426530, -0.579560, -0.435560, -1.073840, 
0.570500, -1.014800, 0.933520, 0.956490, -0.023270, -0.642880, -0.468170, 0.753800, -0.056190, -0.866210, 
0.732070, -0.694160, -0.251170, 0.338660, 0.738980, -0.624390, -1.000810, 0.536540, 0.741770, 0.517370, 
0.670690, -0.316790, 0.688520, -1.231310, -0.190930, -0.151240, -0.718670, -0.076140, -0.813190, 0.274540, 

-0.728580, 0.788280, 0.344280, 0.328530, 1.045070, 0.160450, -0.315020, -0.351030, 0.782650, 0.553840, 
-0.005100, 0.457690, -0.345430, -0.269240, -0.697550, 0.723840, -0.418130, 1.055880, 0.133880, 0.665340, 
-0.276720, 0.266110, -0.260760, -0.781720, -0.167520, -0.728160, -0.136050, -0.477230, -0.151160, -0.220750, 
-0.511020, -0.246410, -0.028710, -0.450750, -0.972290, 0.408430, -0.031780, 0.741150, -0.755410, -0.581900, 
-0.070600, -0.809950, -0.891130, -0.182550, -0.420630, 0.342620, 0.258210, -0.258240, -1.007700, -1.028410, 

-0.943830, 0.016280, 0.237590, 0.179810, -0.406740, 0.114750, 0.721230, 0.890080, 0.302270, -0.357380, 
0.702540, 0.803830, 0.756990, -0.548620, 0.581270, -0.074300, 0.252380, 0.302320, 0.324760, -0.823060, 
0.626050, 0.591730, 0.311150, -0.620490, 0.095660, -0.308490, -0.629000, 0.659380, 0.805470, -0.945360, 
0.985210, 0.143140, 0.936600, -0.286100, 0.488850, -0.510240, -0.832740, 0.922210, -0.657490, 0.638570, 
0.374370, -0.758600, 0.849200, -0.674790, 0.189050, 0.127680, 0.008210, 0.397160, -0.278470, 0.041150, 

0.841750, -0.255940, -0.501040, 0.610380, -0.423030, -0.855410, 0.863030, 0.286960, -0.557150, 0.023980, 
0.958010, -0.962810, -0.607650, -0.698880, 0.494000, -0.634140, -0.093270, -0.527420, -0.288240, -0.355740, 
-0.284210, -0.427540, 0.399240, -0.765780, 0.876140, 0.661200, 0.701890, -0.471160, -0.314390, 0.705260, 
-0.708380, 0.456710, 0.986090, -0.607300, 0.788150, 0.143330, 0.044050, 0.246160, -0.221030, 0.913980, 
-0.279500, -0.592410, 0.020950, -0.393190, -0.647590, 0.271080, -0.092900, 0.210980, 0.582920, -0.371800, 

-0.128570, -0.523510, -0.974010, -0.813190, 0.272870, -0.972210, 0.136140, -0.953190, -0.511370, 0.734900, 
-0.174010, 0.401330, 0.234620, 0.447630, -1.076790, -0.222340, 0.609390, 0.460070, 0.690850, 0.194730, 
0.063160, -0.098810, -0.086040, -0.831260, -0.249630, 0.304690, 0.883690, -0.432320, 0.827650, 0.720240, 
-0.724780, -0.249970, 0.365720, 0.908950, -0.326530, -0.557350, 0.974200, -0.152540, -0.916110, -1.080250, 
-0.080820, 0.065000, 0.186140, -0.239010, 0.004300, -0.763970, 0.156810, 0.811770, 0.955310, 0.093890, 

0.550790, 0.524270, 0.891140, -1.015620, 0.877010, 0.610850, -0.040790, -0.726090, -0.635650, 0.499440, 
-0.526360, -0.215820, -0.113130, -0.328880, 0.454570, 0.493530, 0.769770, 0.802980, 0.942130, -0.041670, 
0.275280, 0.396830, 0.565280, 0.280380, -0.831450, -0.197830, -0.288480, -0.213270, 0.486990, -0.872100, 
-0.646960, 0.046800, 0.766660, 0.579000, -0.887890, -0.267970, -0.549460, 0.341240, -0.762260, -0.026400, 
-0.319740, 0.777540, 0.211610, -0.181040, 0.935040, -0.945490, -0.390800, -0.245340, 0.297260, 0.629660, 

-0.901440, 0.346720, -0.937290, 0.417380, 0.872890, -0.929110, -0.715660, 0.803480, -0.341860, 0.648000, 
-0.974290, 0.859930, -0.165970, -0.246970, -0.774450, -0.689330, 0.185500, 0.745940, 0.029450, 0.586320, 
0.665110, -0.134620, -0.886920, 0.372790, -0.155650, 0.193070, -0.822090, 0.922230, -0.125330, -0.961070, 
0.805010, 0.650630, 0.680070, -0.070400, 0.165670, 0.043800, -0.906640, -0.194060, 0.913580, -0.565850, 
-0.480390, 0.210340, 0.040240, -0.365870, -0.364950, -0.851240, 0.851580, 0.350360, -0.456400, -0.142100, 

0.532780, -0.136960, 0.780610, -0.217840, 0.051720, -0.516690, 0.672150, 0.189620, -0.554210, -0.432140, 
-0.493780, 0.572180, -0.107880, 0.605350, 0.358150, 0.111900, 0.828210, 0.154450, -0.600830, 0.696490, 
-1.203980, -0.472030, 0.958290, 0.252960, 0.968920, -0.694780, 0.529810, -1.115980, -0.075540, 0.376910, 
0.417750, 0.446270, -0.741100, -0.341740, -0.562700, 0.738560, -1.014780, 0.858320, 0.537950, 0.574390, 
0.106690, -0.486210, 0.355920, 0.862240, -0.963120, -0.241190, 0.591820, -0.485050, -0.698610, 0.934440, 

0.440550, -0.340640, 0.393200, -0.403720, 0.106440, -0.330700, -0.381340, -0.533850, -0.112790, -0.511550, 
-0.689880, -0.143660, 0.944590, -0.143210, 0.283380, -0.746180, 0.149860, 0.414050, 0.675230, 0.167260, 
0.339780, -0.831970, -0.658660, 0.647620, 0.595690, 0.878700, 0.463800, -0.506460, -0.669560, 0.847850, 
-0.834580, -0.949690, -0.360850, -0.915340, -0.761620, 0.887980, -0.554600, -0.931650, -0.432280, -0.614520, 
-0.361080, 0.104050, -0.466110, 0.040080, -0.664780, 0.570070, -0.077170, 0.210720, -0.749420, -0.926270, 

0.571580, -0.956870, 0.717260, -0.285440, -0.589150, -0.525280, -0.491830, 0.368340, 0.184450, 0.283330, 
-0.487790, -0.880920, -0.375330, -0.849230, 0.137810, 0.426170, 0.887890, 0.293120, -0.893800, 0.711160, 
-0.432500, 0.372340, -0.943360, 0.809520, -0.907940, -0.481940, 0.295540, 0.552850, -0.874560, 0.218050, 
-0.487110, 0.247200, 0.849310, 0.475460, -0.135930, -0.454570, -0.887090, -0.906550, 0.191880, 0.551030, 
0.677920, 0.341240, -0.180530, -0.234520, -0.731770, 0.727080, -0.085580, 0.597080, -0.520300, -0.663880, 

0.566900, 0.141840, -0.910100, 0.445430, 0.216190, 0.703790, 0.265280, 0.239360, -0.419380, 0.446160, 
-0.655540, 1.053730, -0.108960, -1.040170, -0.487560, -0.241950, -0.586280, 0.937090, 0.931960, -0.720980, 
-0.377300, -0.212670, 0.891400, -0.582540, -0.767950, -0.119060, 1.190140, 0.570090, 0.046820, 0.806420, 
0.978560, -0.298540, -0.597330, 0.592210, 0.966990, -0.917740, -0.508920, -0.450550, -0.624220, 0.312310, 
-0.019980, 0.359690, 0.780280, 0.656940, -0.010800, 0.439440, 0.038160, -0.053110, -0.880700, -0.093120, 

-0.155490, 0.519740, -0.050270, -0.651070, 0.851040, -0.783910, -0.531530, -0.719430, -0.595980, 0.415330, 
0.575250, 0.673780, -0.275650, 0.119550, 0.593140, -0.293530, -0.796860, 0.619940, -0.521020, 0.247270, 
0.541090, -0.748540, -0.789370, 0.972420, 0.978440, -0.232790, -0.342950, 0.570770, -0.252840, -0.876430, 
-0.327400, -0.788370, 0.598700, -0.320980, -0.967210, -0.121650, -0.601410, 0.801520, -0.357410, 1.029310, 
0.561040, -0.014400, -0.456930, 0.619990, -0.267510, -0.123730, 0.379850, 0.919230, 0.756840, 0.500600, 

0.397010, 0.969520, -0.867080, 0.856670, -0.567770, 0.332270, 0.200780, 0.729880, 0.896020, -0.287700, 
0.178250, 0.219180, -0.480110, -0.041840, -0.864800, -0.382870, 0.851920, -1.057730, -0.464290, -0.925120, 
-0.544590, -0.420010, 0.263550, 0.314940, 0.257190, 0.438120, 0.812190, -0.617710, 0.827610, 0.258450, 
-0.466930, 0.768750, -0.315560, -0.364370, 0.274930, 0.574040, 0.421640, -0.688440, -0.803820, -0.113250, 
-0.546490, -0.779140, 0.746280, -0.012780, 0.907240, 0.593790, -0.406030, -0.247860, -0.739510, 0.654020, 

-0.619780, 0.250730, -0.030480, -0.656820, 0.662930, -0.251850, 0.778890, 0.230280, -0.182980, -0.384260, 
0.673570, 0.887110, 0.910010, 0.718850, -0.762980, -0.627550, -0.108250, -0.010240, 0.720800, -0.536640, 
-0.212390, 0.109810, -0.562290, 0.716680, -0.767210, -0.321760, -0.420010, 0.124860, 0.583680, 0.609750, 
-0.556030, 0.551930, -0.599210, 0.723890, -0.054630, -0.760350, -1.143940, -0.049840, -0.209190, -0.021120, 
-0.329830, -0.902580, 0.627860, -0.148350, 0.564740, 0.177110, 0.025130, -0.494080, -0.122120, -0.944720, 

-0.077470, 0.755110, 0.157180, 0.298780, -0.980010, 0.170000, 0.813210, -0.542600, -0.115650, -0.858640, 
-0.610740, -0.891100, 0.403110, 0.850540, -0.464410, -0.611370, -0.231620, 0.790820, -0.245780, 0.046380, 
0.250940, -0.939370, 0.615540, 0.773090, 0.254880, -0.655260, -0.639290, -0.758200, -0.310940, 0.568610, 
-0.273580, -0.126510, -0.921480, 0.798250, 0.363780, -0.601310, -0.675010, -1.105670, 0.458130, -0.927420, 
-0.463740, -0.695150, 0.557970, 0.820770, -0.347260, -0.165620, -0.073160, 0.569140, 0.300700, -0.194780, 

0.182250, 0.354550, -1.049590, 0.777860, -0.578060, 0.873190, -0.475980, -0.542510, 0.600040, 0.819760, 
-0.404630, 0.531830, -0.011640, -0.178130, 1.095710, 0.535560, -0.274520, 0.253650, 0.334550, -0.109330, 
-1.052670, -0.081240, 0.624950, -0.010260, 0.505570, -0.444260, 0.887900, 0.299620, 0.498900, -0.659640, 
0.571770, -0.755720, -0.931390, -0.015250, 0.840750, 0.885170, -0.703640, 0.178070, -0.708080, -0.556930, 
0.734660, 0.713130, -0.506710, -0.124990, -0.614640, 0.977240, -0.869560, 0.032460, 0.136120, -0.665420, 

0.336650, 0.179360, -0.411550, -0.859870, -0.425240, 0.594290, -0.338960, -0.460470, -0.861930, -0.188290, 
0.143470, -0.747650, 0.153180, 1.061480, -0.044430, 0.755760, -0.287530, -0.274520, 0.660500, -0.630890, 
0.853240, -0.151100, 0.358650, 1.024530, 1.053060, 0.444600, -0.200840, -0.419930, -0.103520, 0.304550, 
0.238550, 1.131780, 0.053740, 0.139560, 0.635470, 0.325020, 0.774130, 0.420470, 0.711070, -0.530270, 
-0.219430, 0.499890, -0.630660, 0.023480, 0.837520, -0.759370, -0.923100, -0.243840, -0.718500, 1.107230, 

-0.640630, -0.055900, 0.181660, -0.028470, -0.061760, -0.329630, 0.523350, 0.004080, -0.829060, -0.304770, 
-0.550570, 0.486690, -0.468530, -0.123540, -1.060650, 0.556860, -0.813060, -0.369680, -0.648060, -0.092630, 
-0.393730, 0.155400, 0.838150, 0.794210, -1.036410, 0.756350, 0.748430, -0.527880, 0.747790, 0.028120, 
-0.722090, -0.369860, -0.510940, -0.025060, -0.799470, 0.526920, 0.917200, 0.408110, 0.859560, -0.445960, 
-0.488330, -0.222080, 0.185190, 0.965510, 0.838420, -0.521580, -0.669540, 0.166070, -0.782980, 0.656220, 

-0.055680, 1.703880, 1.218330, -1.050770, -0.679730, -0.218550, -0.523570, 0.445060, 0.361500, 0.871970, 
-0.329310, -0.203550, -1.423950, -1.077090, 0.607300, 0.274620, -1.338950, 1.347350, -1.156160, -0.572100, 


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
      0.0, -0.013110, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.905570, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.090470, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, -0.067260, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.415670, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.613610, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.935960, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.778610, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.784920, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.199330, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.564930, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.617570, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.725390, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.151030, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 0.895420, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.060540, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.616390, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.104260, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.512560, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.583870, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.232010, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.423650, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.136880, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.389370, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.249310, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.120730, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.102100, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.853290, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.878650, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, -0.088760, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.598230, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.381010, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.751310, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.619930, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.910250, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.762090, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.566790, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.423130, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.866560, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, 0.121510, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.201920, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.815010, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.113800, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.009280, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.740120, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.404130, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.608370, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.852990, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, -0.019890, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.248450, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.223470, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.437920, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.758820, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.973740, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.751400, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.300250, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.210990, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.397340, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.575970, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.483960, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.167080, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.520800, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.567340, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.677160, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.880970, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, -0.041290, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.656750, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -0.945800, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.845590, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.810970, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.358360, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int aa(float *in, float *out, int init)
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
