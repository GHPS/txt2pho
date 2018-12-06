/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  oeh.c
  --------------------------------------------------------
  generated at Thu Jun 18 17:19:41 1998
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
-0.761740, 0.602480, -0.178290, 0.955710, 0.474460, 0.000730, 1.045720, -0.854480, 0.263920, -0.897630, 
0.416520, -0.312300, 0.083530, -0.063260, -0.167230, -0.487110, -0.287220, 0.267000, 0.373930, 0.678600, 
0.394430, -0.756600, 0.575120, -0.217430, -0.181510, 0.386430, -0.980720, 0.527230, -0.557700, -0.065190, 

-0.516320, -0.769340, -0.830410, 0.870740, -0.038850, 0.157170, -0.890100, 0.650550, -0.688020, -0.644950, 
0.263880, -0.660050, -0.123890, -0.437930, -0.334560, 0.401850, 0.290930, 0.545790, 0.267210, -0.561980, 
-0.919590, 0.091810, -0.351080, -0.729850, 0.398380, -0.420050, -0.012060, -0.783220, 0.383800, 0.478310, 

0.597770, -0.456140, 0.169850, 0.512300, 0.874110, 0.851490, 0.681100, 0.471020, 0.357870, 0.410340, 
-0.248680, 0.542320, 0.092650, -0.618860, -0.943770, -0.967790, 0.370860, 0.251380, -0.643070, 0.989950, 
-0.719450, 1.125180, -0.057640, -0.746240, 0.550140, 0.030730, 0.784840, 0.071420, -0.558040, -0.376510, 

-0.095030, -0.356790, -0.314190, -0.474620, -0.663940, -0.358010, -0.795310, 0.170270, 0.089820, -0.835760, 
-0.445010, -0.706460, 0.088770, -0.819300, -0.837320, 0.660700, 0.111810, 0.896090, -0.576460, 0.942880, 
-0.258410, 0.655100, 0.614610, 0.299560, -0.855740, 0.560980, 0.638070, 0.071250, 0.252490, 0.865940, 

-0.639530, -0.359320, 0.407240, -0.727500, 0.357750, -0.107960, 0.440520, 0.751220, -0.886440, 0.490130, 
0.555790, 0.485320, -0.285640, 0.577130, 0.372520, 0.250490, -0.803690, 0.478610, -0.486840, 0.848590, 
-0.679740, 0.970840, -0.289180, 0.245390, 0.705840, -0.236390, 0.261920, 0.915030, -0.312530, -0.870780, 

0.016280, -0.633980, -0.171650, -0.115910, 0.434560, -0.064770, 0.468240, 0.864890, -0.229550, 0.929050, 
-1.013300, 0.815180, -0.962500, -0.787170, 0.306420, -0.385130, 0.313810, -0.725260, -0.093240, -0.688890, 
0.767130, -0.588750, 0.254830, -0.664040, -0.596740, -0.222640, 0.485010, -0.829290, 0.876140, -0.299330, 

0.054390, -0.670230, 0.379250, -0.125460, 0.192680, 0.375180, 0.924650, -0.771930, 0.197560, 0.469270, 
-0.129150, 0.226690, 0.346520, 0.487010, 0.460390, -0.671090, -0.642710, -0.606090, -0.894300, 0.566160, 
0.763890, -0.426860, 0.790440, -0.146330, -0.666170, 0.964840, 0.628710, 0.366510, 0.391490, 0.056290, 

-0.595120, -0.487760, -0.958770, 0.857400, -0.037100, 0.406060, 0.315760, -0.106340, 0.875700, -0.387290, 
0.840710, 0.061980, 0.370040, 0.569360, 0.570690, 0.101420, 0.292260, -1.049300, -0.152120, 0.169280, 
-0.805170, 0.147370, -0.504570, 0.253670, 0.482170, -0.804150, 0.347640, -1.011520, -0.869550, 0.475200, 

-0.637320, -0.872220, -0.106690, 0.721920, 0.892250, -0.688500, 0.147540, -0.514880, -0.259190, -1.058860, 
0.342180, 0.186290, 0.922310, -0.468300, -0.687540, 0.389500, 0.339740, -0.941650, 0.317850, -0.201730, 
0.912720, -0.031890, 0.941230, -0.054170, 0.071210, -0.910900, -0.242710, -0.601390, -0.490050, -0.410040, 

0.911650, -0.157290, 0.949070, 0.168850, -0.929830, 0.511220, -0.504980, -0.910720, 0.258960, 0.799370, 
-0.431810, -0.496160, -0.473970, 0.527950, -0.360800, -0.014130, 0.952700, 0.382940, 0.311350, 0.033560, 
0.177110, -0.639090, -0.617350, 0.715500, -0.535920, -0.153350, 0.760490, 0.451130, -0.672460, 0.170880, 

0.667570, -0.115590, 0.666850, 0.586400, 0.937810, -0.132830, 0.592750, -0.927960, -0.371000, -0.138080, 
-0.813650, -0.011730, 0.220930, 0.286410, 0.496530, -0.904610, 0.338010, 0.012150, -0.650650, 0.121650, 
-0.689300, 0.531890, 0.089330, -0.496740, -0.626390, 0.588670, -0.111770, 0.581940, 0.219030, 0.738640, 

0.177590, -0.891560, 0.724450, -0.788150, 0.394110, 0.526850, 0.807520, 0.833760, -0.773880, -0.107750, 
0.905650, 0.475990, 0.813910, -0.132990, 0.078840, 0.604580, -0.329470, -0.059500, -0.511440, 0.593440, 
0.646720, 0.262130, -0.594240, -0.979050, 0.160860, 0.394820, -0.495650, -0.795740, 0.647590, 0.865410, 

0.858640, 0.909990, -0.648620, -0.692110, -0.391940, 0.424730, -0.823440, 0.407010, 0.682020, 0.735940, 
0.630850, -0.515920, -0.371590, 0.172580, 0.447070, -0.179230, 0.247290, -0.817860, 0.902190, -0.639520, 
0.351550, 0.729040, -0.315860, 0.503880, 0.734570, 0.620360, -0.401800, 0.168890, 0.135480, -0.567330, 

0.972770, -1.044090, 0.399920, -0.749340, -0.705410, 0.140540, -1.059360, 0.504170, 0.785800, 0.928630, 
-0.833930, -0.726400, 0.526310, -0.404950, -0.132210, 0.075920, -0.894640, 0.236790, -0.067940, -0.090970, 
-0.476660, 0.837900, -0.094830, -0.469820, -0.310540, -0.522250, 0.735770, 0.082300, 0.584860, -0.499650, 

0.304460, 0.815050, 0.476730, -0.164310, -0.343580, -0.036410, -0.451820, 0.163790, 0.232530, 1.034340, 
-0.124180, 0.128290, -0.631390, -0.857330, 0.764790, -0.790570, 0.599660, -0.396120, -0.235790, 0.153350, 
0.529380, -1.116160, -0.072240, -0.831540, -0.256900, -0.847170, -0.468150, 0.366920, -0.308840, -0.935390, 

0.586160, -0.413640, -0.542010, 0.674230, -0.342750, -0.833680, 0.837370, 0.128550, -0.685450, 0.057370, 
0.619330, -0.236940, -0.914690, 0.576550, -0.233610, 0.704020, 0.339620, 0.544440, 0.626110, -0.102560, 
0.671550, -0.052150, -0.958510, 0.623450, -0.222360, -0.040000, 0.493780, -0.897600, 0.139790, -0.810030, 

0.335050, 0.370570, -0.722560, 0.093970, 0.817280, 0.496460, -0.521060, -0.726650, 0.719120, -0.387000, 
-0.280770, -0.654360, -0.644200, -0.014930, 0.079250, 0.048750, 0.344630, 0.574520, -0.505100, 0.808460, 
-0.335580, -0.310120, -0.972900, -0.594690, -0.635400, -0.884170, -0.878660, -0.383040, 0.517970, 0.569620, 

-0.479610, 0.548640, 0.002440, -0.712440, 0.947240, -0.263950, -0.711220, 0.279050, -0.933610, 0.984040, 
-0.288890, -0.167510, 0.813890, -0.517350, 0.668130, -0.911060, -0.236670, 0.443260, 0.052810, -0.536980, 
0.677900, 0.139720, 0.009220, -0.598550, 0.170740, -0.455040, -1.028440, 0.564110, -0.798840, 0.934150, 

0.774430, -0.850330, -0.921640, -0.073680, 0.657600, 0.985440, -0.567510, 0.171430, -0.498200, 0.435770, 
-0.120210, -0.155320, -0.184660, -0.138090, -0.599820, -0.742890, -0.323920, -0.537850, 0.200190, 0.913090, 
-0.900780, -0.773290, -0.112300, 0.348800, 0.575260, 0.276450, -0.886690, -0.265920, -0.538730, 0.879450, 

-0.586260, 0.947590, 0.183060, 0.704090, -0.529570, 0.859410, -0.072300, 0.856570, 0.762490, -0.013280, 
-0.495820, 0.974500, 0.228850, -0.758030, 0.859180, -0.765880, -0.780470, -0.491780, -0.220070, 0.760890, 
-0.281730, 0.076370, 0.345170, 0.694230, 0.198570, 0.666550, 0.263380, 0.944180, -0.681700, 0.347810, 

0.078260, 0.566860, 0.023570, 0.378320, -0.847240, -0.141120, 0.692950, 0.231500, -0.789030, 0.304190, 
0.099690, 0.306550, 0.654070, -0.947080, -0.549700, 0.432330, 0.439120, 1.083260, -0.382740, -0.366100, 
0.732400, -0.044040, 0.838860, 0.768170, 0.362060, 0.033170, -0.820760, -0.104250, -0.208010, 0.687250, 

-0.377110, 0.492770, -0.543470, -0.691550, 0.460290, 0.370980, 0.594220, 0.876130, 0.048620, 0.445550, 
-0.320720, -0.288100, 0.260690, 0.961460, 0.416010, 0.544270, -0.132570, 0.096220, 0.513260, -0.729120, 
0.513780, -0.266620, -0.231100, 0.156150, -0.294060, -0.005420, 0.240630, -0.879420, -0.873650, -0.125210, 

-0.277140, 0.945530, 0.762960, -0.190900, 0.622960, 0.957530, 0.226950, 0.145970, -0.411400, -0.559890, 
0.020560, -0.949550, 0.021690, 0.081150, 0.446090, -0.973670, -0.990240, -0.136750, -0.736850, 0.475520, 
-0.045180, -0.713950, -0.606860, -0.730370, -0.544560, 0.778800, -0.765260, 0.074470, -0.380720, -0.550940, 

-0.176500, 0.828750, -0.435760, -0.188710, -1.022530, -0.219550, 0.952180, 0.903660, -0.940350, -0.524350, 
0.212070, 0.016790, -0.928410, -0.435660, -0.122900, 0.821860, 0.679000, -0.855810, -0.836020, -0.634420, 
-0.412710, -0.226480, 0.903220, -0.329350, -0.161320, 0.336500, -0.657240, 0.270640, -0.145630, -0.713650, 

-0.528570, -0.251530, -0.085790, -0.429140, -0.160400, 1.084510, 0.691960, 0.608320, 0.279820, -0.683320, 
-0.891100, -0.655170, -1.021340, -0.132090, 0.565810, -0.313350, 0.072880, -0.724280, -0.628860, -0.959310, 
0.765730, 0.328210, 0.181080, 0.113220, 0.241380, 0.316710, 0.445040, -0.542720, 0.132430, 0.083900, 

0.556450, 0.745090, -0.653550, 0.886030, -0.441150, 0.712470, -0.112180, -0.271780, 0.136660, -0.016550, 
0.075850, 0.275890, -0.259330, 0.939890, -0.016760, -0.628060, 0.564530, -0.017350, -0.935970, -0.142610, 
-0.324030, 0.978550, 0.264330, -0.943000, -0.521380, 0.187430, -0.142730, 0.211340, 0.097380, 0.370680, 

-0.465600, -0.896850, -0.115530, 0.397270, -0.799250, -0.750870, -0.727100, -0.871260, -0.038410, -0.246540, 
-0.497800, -0.380440, -0.157790, -0.768160, 0.448460, 0.659260, 0.864840, 0.920740, 0.568230, 0.079900, 
-0.341220, 0.457940, -0.220720, 0.981630, 0.632080, -0.835750, -0.334090, -0.856770, 0.180030, 0.204270, 

-0.246410, -0.367210, 0.791780, -0.313670, -0.613760, -0.556440, 0.299480, -0.937310, 0.743930, -0.670240, 
-0.652510, -0.248320, -0.365210, 0.441790, 0.621300, -0.023760, 0.550010, -0.152680, 0.698290, -0.577570, 
0.540770, 0.419580, -0.120680, -0.221900, 0.701230, -0.308120, -0.545230, -0.037720, -0.068310, 0.375720, 

-0.007580, 0.580570, 0.478310, 0.064090, -0.729910, -0.015890, 0.623500, 0.876260, -0.229890, 0.768070, 
0.152820, -0.273440, 1.044530, 0.523750, -0.425280, 0.027810, 0.652450, -0.604480, -0.232460, 0.352810, 
-0.510330, -0.325900, -0.886050, 0.939740, 0.142140, -0.984720, -0.979560, -0.344710, -0.827510, 0.150130, 

-0.059030, -0.264700, 0.561440, 0.705290, 0.325200, 0.762110, 0.539830, -0.132080, 0.492010, 0.940090, 
0.593300, -0.116120, 0.399010, -0.076020, 0.673760, 0.841430, -0.820750, 0.026040, 0.670940, -0.404870, 
0.892910, 0.741930, -0.559460, -0.096690, -0.450090, 0.478220, 0.335910, -0.898150, 0.606500, 0.803680, 

-0.726190, -0.806710, -0.735390, 0.345680, 0.221580, 0.551640, -0.584960, 0.846120, 0.525330, -0.203730, 
-0.388380, 0.567660, -0.254560, -0.462170, 0.396550, 0.447200, -0.740800, 0.300070, -0.614910, 0.510580, 
-0.545810, -0.384320, -0.280740, 0.452220, -0.250670, 0.088820, -0.561030, 0.999250, 1.000850, 0.375700, 

0.891280, -0.662960, -0.008300, 0.050530, 0.489070, 0.641050, 0.204800, 0.410210, -0.040010, 0.850220, 
0.868840, -0.376270, 0.581310, 0.697090, -0.913870, -0.865940, 0.731660, 0.204180, -0.458380, -0.964920, 
0.545410, 0.094320, 0.220960, 0.114210, -0.861100, 0.716270, 0.638400, -0.753360, -0.775340, 0.427040, 

0.250670, -0.771880, -0.854810, 0.984420, 0.884720, 0.844420, 0.601180, -0.619600, -0.022000, 0.952070, 
-0.412750, -0.434080, -0.442090, -0.350860, -0.537430, 0.235290, 0.771660, -0.750610, -0.522870, 0.875200, 
-0.663680, 0.011730, 0.247320, -0.257060, 0.840170, -0.897460, -0.665220, -0.890570, 0.994500, 0.233110, 

0.599300, 0.698860, 0.247280, 0.437660, -0.916540, 0.314090, 0.408740, 0.626180, -0.438910, 0.551120, 
-0.253940, -0.837360, 0.281000, 0.125740, -0.239380, 0.302300, -0.862710, -1.068820, 0.622940, -0.569080, 
-0.900550, 0.121240, 0.508220, 0.234860, 0.254300, 0.958710, 1.017110, -0.693430, 0.560710, 0.630870, 

0.041580, -0.429330, -0.554250, 0.146860, -0.735040, -0.069880, -0.379980, -0.577880, 0.883200, 0.323420, 
-0.560580, -0.925840, -0.087340, 0.965690, 0.438050, 0.026930, 0.325880, -0.293000, 0.947330, -0.774680, 
0.507400, -0.653380, -0.823460, -0.511710, -0.028640, 0.348440, 0.023590, 0.217740, 0.056460, -0.948150, 

0.630510, 0.353000, -0.746140, 0.686520, 0.385140, 0.824710, 0.385050, -0.286100, 0.674350, -0.425430, 
0.326580, 0.662870, 0.425890, -0.349080, -0.683420, -0.365870, -0.273980, 0.269140, 0.237220, 0.437910, 
-0.643420, -0.605500, -0.244860, 0.466180, -0.101930, 0.272960, -0.353700, -0.960710, -0.916000, 0.718940, 

-0.587320, 0.532550, 0.725640, 0.656420, -0.342570, 0.196710, 1.056120, 0.186070, 0.329670, -0.353350, 
0.495360, -0.618350, -0.905320, -0.613830, 0.857820, -0.800620, 0.810630, 0.097030, 0.746850, 0.594190, 
-0.514310, 0.776650, 0.862540, -0.478200, -0.205970, 0.640130, -0.717040, -0.359280, -0.933110, -0.890450, 

0.189470, -0.305030, -0.826020, 0.431150, 0.923670, -0.851380, -0.155730, -0.144430, -0.340980, -0.639500, 
-0.297350, -0.031060, 0.482210, -0.778180, 0.309560, 0.292340, -0.281520, -0.368300, -0.682850, 0.281560, 
0.748580, -0.552830, -0.486060, -0.541170, -0.183890, 0.080550, -0.471280, -0.077830, 0.060000, -0.692920, 

0.222310, 0.932990, 0.447390, 0.977560, 0.504540, -0.565800, -0.346280, 0.436140, 0.826820, -0.687700, 
-0.941530, 0.402120, -0.437780, 0.837130, 0.380550, -0.681400, -0.414020, -0.734890, 0.539480, -0.468290, 
0.600430, 0.623150, 0.984910, 0.751510, -0.202420, -0.189850, -0.883850, 0.052340, 0.822900, -0.878500, 

0.874670, -0.809140, -0.194900, -0.806900, 0.147280, 0.643190, -0.957140, -0.437310, -0.509630, 0.268850, 
0.732590, 0.761250, -0.109030, -0.563170, -0.065060, -0.777450, 0.065360, 0.017880, 0.244880, -0.249120, 
0.722580, -0.695990, -0.649620, -0.383230, 0.786180, 0.967820, -0.565660, 0.820900, 0.556560, 0.680120, 

-0.247310, 0.638830, -0.550770, -0.322670, 0.704330, -0.912050, -0.750120, 0.684690, 0.516950, -0.358260, 
0.807230, 0.699810, 0.926550, -0.063070, 0.402870, -0.809950, -0.838180, 0.296740, -0.451230, 0.255400, 
0.231500, 0.214010, 0.282770, -0.309950, 0.769960, 0.777870, -0.020310, 0.008640, 0.503980, 0.032520, 

0.474990, 0.611140, -0.041130, -0.674180, -0.217970, -0.259680, 0.677750, -0.678080, -0.395460, -0.217040, 
-0.443760, -0.046130, -0.043470, 0.806130, -0.019700, 0.464580, 0.515560, -0.928330, 0.221110, 0.710640, 
0.001800, -1.128530, 0.374760, -0.565460, 0.830960, 0.625210, 0.797650, 0.602070, 0.439850, 0.659910, 

0.099390, 0.527040, -0.205170, 0.864180, -0.740420, -0.538370, -0.879330, -0.020360, -0.761990, -0.390480, 
-0.839990, -0.580630, -0.161940, -0.253220, 0.536900, 0.474770, 0.872220, -0.455550, 0.698350, 0.270740, 
-0.783640, 0.113090, 0.672890, 0.667420, -0.512850, 0.663890, -0.645210, 0.942880, 0.154670, 0.937580, 

0.752740, -0.561630, -0.423440, -0.165200, -0.362460, 0.684250, -0.322300, 0.617120, 0.706980, 0.779700, 
0.544750, -0.518900, -0.801020, 0.152240, -0.404000, 0.807300, 0.269140, -0.834280, 0.440120, 0.247510, 
0.973850, 0.652070, 0.767680, -0.363820, -0.821390, -0.209190, -0.948020, 0.037110, -0.648720, -0.607610, 

0.040630, -0.476790, -0.931620, 0.181160, -0.767840, 0.787300, 0.420490, -0.003060, -0.710890, 0.382520, 
0.808820, 0.885950, -0.882680, -0.428920, 0.661250, -0.031640, -0.677510, 0.774330, 0.367080, 0.870060, 
0.832800, -0.815880, 0.968790, 0.522820, 0.153980, 0.759770, 0.771260, 0.094510, 0.463640, 0.328390, 

-0.073020, 0.181330, -0.248330, -0.876430, -0.659300, -0.691800, -1.006810, -0.419770, -0.590180, -0.498000, 
0.277420, -0.774590, 0.165530, -0.708820, -0.752870, -0.295100, 0.248910, -0.344110, 0.359300, 0.191120, 
0.630990, -0.900760, -0.163220, -0.522770, -0.951130, 0.426950, 0.537410, 0.579130, -0.215970, -0.359530, 

-0.608360, -0.815400, -0.311850, 0.037030, 0.990290, -0.748430, -0.906650, 0.189940, 0.747380, 0.306730, 
-0.505530, -0.774340, -0.111510, -0.652380, 0.631190, 0.625060, -0.253110, -0.937160, -0.393010, -0.280660, 
-0.033570, 0.705880, 0.578220, -0.079610, 0.675590, 0.337930, -0.812670, 0.191920, -0.770490, 0.329780, 

-0.988900, -0.499050, -0.094330, 0.526590, 0.118210, 0.823860, -0.407780, -0.743510, 0.561390, -0.100050, 
-0.059600, 0.322900, 0.733850, 0.868650, 0.737260, 0.103450, 0.834540, -0.309110, -0.205130, 0.799120, 
0.002450, -0.884850, 0.134850, 0.742310, 1.023280, -0.339100, 0.221880, -1.011340, 0.971290, 0.725210, 

0.764530, 0.904040, 0.351180, -0.505040, -0.876000, 0.321390, -0.756310, 0.562060, -0.984220, -0.794340, 
-0.066750, -0.793330, 0.725800, -0.819720, 0.478750, -0.465840, 0.281750, -0.582330, -0.657890, -0.431670, 
0.191440, -0.339680, -0.961650, 0.282050, -0.030110, -0.888670, 0.398090, -0.885890, 1.019260, -0.403540, 

0.805620, 0.025940, 0.728480, 0.426280, 0.698640, 0.193260, 0.754190, 1.053160, 0.518660, 0.820480, 
0.349960, 0.395920, 0.067230, 0.305810, 0.069470, 0.921120, -0.160400, -0.886630, 0.678500, 0.897990, 
0.329640, 0.649940, 0.662020, 0.120070, -0.501750, 0.011360, -0.690780, -0.869920, -0.672890, 0.066620, 

-0.652650, -0.382720, 0.120600, -0.711340, 0.106350, 1.063980, 0.417850, -0.283570, 0.277640, 0.181570, 
-0.281240, -0.553630, 0.846140, 0.328380, 0.655950, 0.619230, 0.843810, -0.690350, -0.757950, -0.658280, 
-0.421840, 0.099140, 0.318490, -0.996840, -0.545910, 0.107550, -0.518060, 0.430310, -0.579430, -0.121720, 
0.931450, 0.001180, 0.491760, -0.219800, -0.547960, -0.657240, 0.199010, -0.365270, -0.763730, 0.392730, 
0.506080, -0.372890, 0.569400, -0.151330, 0.308190, 0.369090, -0.696290, 0.750090, 0.475930, -0.733930, 

-1.014500, 0.637290, 0.845440, 0.491980, -0.133610, -0.630070, -0.706950, -0.298590, 0.219110, -0.727410, 
-0.065280, 0.239960, 0.514050, 0.472000, 0.217650, 0.280260, 0.447510, -0.706950, -0.305240, -0.175070, 
0.367240, 0.400430, -0.627830, -0.282770, 0.194220, 1.031410, 0.128060, -0.517170, -0.536880, -0.925670, 
-0.535300, 0.479470, -0.581950, 0.240050, 0.318390, 0.559100, -0.934810, 0.644040, -0.148440, 0.245460, 
1.037480, -0.852950, -0.126550, -0.382710, 0.989900, -0.980280, -0.905040, -0.536260, -0.838260, -0.155990, 

-0.184060, 0.320610, -0.152480, -0.453400, 0.606670, -0.263290, 0.460200, 0.281910, 0.627140, 0.242080, 
0.813370, -0.993260, 0.520720, 0.718740, -0.134130, 0.045880, 0.343560, -0.262070, -0.439850, -1.023130, 
0.541870, -1.007020, 0.910820, 0.916940, -0.274760, -0.683510, -0.353240, 0.819550, 0.015760, -0.730820, 
0.855160, -0.777950, -0.203900, 0.442710, 0.773890, -0.717070, -0.713440, 0.481060, 0.850640, 0.627120, 
0.811890, -0.428230, 0.883240, -0.831000, -0.197610, -0.148700, -0.554490, -0.143990, -0.842320, 0.280570, 

-0.811920, 0.928900, 0.241250, 0.304480, 0.993850, 0.296050, -0.393900, -0.268840, 0.785320, 0.580410, 
-0.131360, 0.507280, -0.292380, -0.291620, -0.554140, 0.770120, -0.346610, 0.965500, 0.150000, 0.713380, 
-0.320020, 0.306920, -0.157300, -0.659070, 0.000730, -0.730070, -0.227490, -0.554390, -0.189210, -0.224730, 
-0.376980, -0.191250, -0.115480, -0.442140, -0.979720, 0.434390, -0.153080, 0.739490, -0.697760, -0.599160, 
-0.079360, -0.840160, -0.841250, -0.214760, -0.372130, 0.367100, 0.181910, -0.228050, -0.882530, -0.922420, 

-0.956060, -0.015390, 0.172250, 0.158960, -0.478300, 0.121480, 0.660860, 0.822960, 0.257310, -0.356450, 
0.666580, 0.734180, 0.662050, -0.633730, 0.563170, -0.118460, 0.274400, 0.241750, 0.304320, -0.871220, 
0.631780, 0.537440, 0.293350, -0.666080, 0.070800, -0.340040, -0.631330, 0.607380, 0.771070, -1.019110, 
0.970190, 0.095120, 0.950590, -0.389190, 0.468620, -0.520860, -0.908660, 0.883810, -0.723670, 0.591420, 
0.315480, -0.794130, 0.761260, -0.808170, 0.140090, 0.123050, -0.038610, 0.410280, -0.341430, -0.041180, 

0.863570, -0.174290, -0.499780, 0.601120, -0.396410, -0.799380, 0.878020, 0.345090, -0.553920, 0.132850, 
0.982810, -0.901770, -0.549290, -0.664760, 0.612600, -0.563480, -0.001890, -0.517430, -0.276570, -0.307090, 
-0.246100, -0.380790, 0.489840, -0.692340, 0.946620, 0.750410, 0.688670, -0.458530, -0.340150, 0.767680, 
-0.622020, 0.553380, 0.954150, -0.590500, 0.805700, 0.230030, 0.029680, 0.286570, -0.191970, 0.949080, 
-0.281030, -0.613490, 0.091780, -0.335030, -0.563120, 0.295840, -0.100050, 0.266790, 0.612840, -0.282260, 

-0.146820, -0.457710, -0.937740, -0.825560, 0.315440, -0.953450, 0.165420, -0.794760, -0.394700, 0.785140, 
-0.152210, 0.484850, 0.326170, 0.459930, -1.004070, -0.157700, 0.658980, 0.457540, 0.741570, 0.245090, 
0.097500, -0.069760, -0.077200, -0.775270, -0.149720, 0.349540, 0.898130, -0.350280, 0.834390, 0.784890, 
-0.696210, -0.175280, 0.363440, 0.993020, -0.315340, -0.459670, 0.961730, -0.102950, -0.899840, -0.998750, 
-0.015450, 0.176370, 0.233170, -0.330020, 0.109680, -0.750660, 0.138740, 0.902380, 0.989750, 0.196140, 

0.638130, 0.491330, 0.944420, -0.949420, 0.945750, 0.544750, -0.008060, -0.801750, -0.697780, 0.379520, 
-0.494690, -0.194640, -0.081860, -0.275690, 0.352850, 0.470060, 0.687440, 0.931600, 0.863640, -0.053410, 
0.308340, 0.444170, 0.579760, 0.291000, -0.920030, -0.200040, -0.311470, -0.253650, 0.539090, -0.837720, 
-0.665870, 0.068730, 0.749140, 0.620340, -0.910240, -0.386010, -0.364690, 0.272260, -0.722180, -0.022370, 
-0.269500, 0.634460, 0.211840, 0.051980, 0.878880, -0.960000, -0.312400, -0.320450, 0.310730, 0.652970, 

-0.821770, 0.404980, -0.895450, 0.440050, 0.966180, -0.883100, -0.645230, 0.793620, -0.364460, 0.642130, 
-0.949670, 0.935170, -0.109490, -0.211360, -0.736600, -0.669800, 0.193700, 0.843540, 0.035060, 0.638560, 
0.707120, -0.094840, -0.865180, 0.376810, -0.169930, 0.211150, -0.763140, 0.968170, -0.122300, -0.880670, 
0.887050, 0.640290, 0.730680, -0.015140, 0.183380, 0.064960, -0.833860, -0.183790, 0.939850, -0.496210, 
-0.417610, 0.217840, 0.073450, -0.295440, -0.301920, -0.849740, 0.891420, 0.416800, -0.455400, -0.121530, 

0.749410, -0.216570, 0.945500, -0.226930, 0.151440, -0.594840, 0.841430, 0.174710, -0.538630, -0.449860, 
-0.332690, 0.625920, -0.166580, 0.561310, 0.290760, 0.111090, 0.763750, 0.275580, -0.579640, 0.715050, 
-1.021530, -0.453120, 0.930480, 0.145050, 0.812030, -0.696750, 0.616700, -0.998200, -0.015600, 0.444410, 
0.328930, 0.420570, -0.555820, -0.307990, -0.556150, 0.844630, -0.904340, 0.918800, 0.442100, 0.659710, 
0.188880, -0.382380, 0.203430, 0.772750, -0.915180, -0.267710, 0.603310, -0.402990, -0.768160, 0.848370, 

0.446400, -0.297610, 0.383660, -0.411590, 0.125200, -0.319610, -0.388530, -0.503520, -0.101560, -0.502250, 
-0.710170, -0.117750, 0.982970, -0.142530, 0.328110, -0.740750, 0.175240, 0.432520, 0.694430, 0.191020, 
0.336830, -0.816220, -0.638140, 0.674330, 0.614720, 0.889850, 0.469930, -0.492280, -0.670700, 0.864690, 
-0.795090, -0.947190, -0.364170, -0.897320, -0.753370, 0.905410, -0.559220, -0.923430, -0.413820, -0.588740, 
-0.342240, 0.115100, -0.428590, 0.060690, -0.635800, 0.575660, -0.073650, 0.230080, -0.729470, -0.907180, 

0.556580, -0.940400, 0.693520, -0.287750, -0.600730, -0.518110, -0.511150, 0.376760, 0.191960, 0.277910, 
-0.509980, -0.884240, -0.367760, -0.855730, 0.141680, 0.419580, 0.897290, 0.283710, -0.888790, 0.710360, 
-0.453020, 0.369110, -0.941070, 0.815560, -0.898840, -0.484550, 0.296030, 0.542920, -0.878710, 0.211420, 
-0.475130, 0.245000, 0.840110, 0.471640, -0.135910, -0.459850, -0.897340, -0.915330, 0.203960, 0.543090, 
0.671310, 0.328870, -0.161710, -0.224000, -0.736920, 0.729730, -0.082850, 0.593350, -0.514120, -0.658670, 

0.473710, 0.080060, -0.895120, 0.325230, 0.073470, 0.722500, 0.076830, 0.254050, -0.583570, 0.577960, 
-0.707390, 0.970060, -0.233730, -1.144610, -0.395960, -0.261470, -0.584380, 0.745150, 0.938110, -0.624750, 
-0.201920, -0.111660, 1.058990, -0.378910, -0.423400, -0.119450, 0.892610, 0.430740, 0.003110, 0.664520, 
0.933830, -0.103670, -0.767230, 0.465420, 0.881200, -0.845620, -0.643920, -0.533890, -0.754840, 0.187480, 
-0.188120, 0.271720, 0.600300, 0.252260, -0.018060, 0.430850, -0.114480, -0.053600, -0.916750, 0.032950, 

-0.089600, 0.539440, -0.219690, -0.670460, 0.758870, -0.614330, -0.528090, -0.744350, -0.588930, 0.610840, 
0.598890, 0.632190, -0.409470, -0.049090, 0.732200, -0.284830, -0.581280, 0.533380, -0.529520, 0.205250, 
0.575210, -0.786020, -0.724660, 0.906920, 0.953360, -0.219630, -0.274050, 0.550650, -0.364710, -0.899310, 
-0.221870, -0.858830, 0.600120, -0.487710, -0.928610, 0.023380, -0.803760, 0.828890, -0.445100, 1.037470, 
0.463270, 0.041350, -0.513850, 0.330260, -0.182480, -0.074310, 0.228700, 1.089150, 0.605130, 0.404380, 

0.409900, 0.924120, -0.720640, 0.943400, -0.463460, 0.356980, 0.383950, 0.710710, 0.893060, -0.255840, 
0.318490, 0.292510, -0.430740, 0.103460, -0.902380, -0.375160, 0.840540, -0.996360, -0.456060, -0.849050, 
-0.533090, -0.403120, 0.263800, 0.293540, 0.238560, 0.543890, 0.821260, -0.604830, 0.840320, 0.353410, 
-0.440720, 0.832980, -0.278820, -0.267280, 0.286640, 0.600880, 0.508880, -0.644070, -0.769440, -0.038030, 
-0.475260, -0.702990, 0.801710, 0.122560, 0.969010, 0.593580, -0.384210, -0.229860, -0.693670, 0.674630, 

-0.681740, 0.106960, 0.050150, -0.552920, 0.669250, -0.325490, 0.873640, 0.196090, -0.118730, -0.443540, 
0.779550, 0.846250, 0.893860, 0.841470, -0.919020, -0.705060, -0.222060, 0.021720, 0.696640, -0.550440, 
-0.299830, 0.080710, -0.647650, 0.640230, -0.834320, -0.308580, -0.428890, 0.099770, 0.651100, 0.602380, 
-0.688940, 0.583040, -0.600050, 0.801030, -0.064290, -0.862370, -1.016390, -0.058100, -0.148200, -0.058500, 
-0.341260, -0.921640, 0.660940, 0.006100, 0.466410, 0.161250, 0.113670, -0.615280, -0.087580, -0.945520, 

0.045970, 0.723260, 0.271000, 0.198560, -0.949860, 0.069770, 0.824390, -0.391430, -0.040280, -0.727770, 
-0.497090, -0.851800, 0.326600, 0.683150, -0.366210, -0.554220, -0.164070, 0.732440, -0.161830, 0.100580, 
0.512680, -0.914930, 0.641670, 0.798860, 0.296840, -0.676400, -0.614300, -0.583800, -0.293360, 0.541070, 
-0.340670, -0.158290, -0.834550, 0.764540, 0.347500, -0.358990, -0.800150, -0.979460, 0.253630, -0.852730, 
-0.416900, -0.397970, 0.380850, 0.249350, -0.189960, -0.173110, -0.217890, 0.710260, 0.183530, -0.233100, 

0.333110, 0.064690, -0.783940, 0.887540, -0.457340, 0.775470, -0.302360, -0.872620, 0.338800, 0.736290, 
-0.196010, 0.459060, -0.139210, -0.080250, 0.848600, 0.387500, -0.527830, 0.324590, 0.168350, -0.007030, 
-0.908540, -0.097660, 0.582880, -0.035210, 0.491280, -0.423370, 0.788330, 0.212090, 0.496150, -0.698870, 
0.435360, -0.761900, -0.874710, -0.009540, 0.788690, 0.635020, -0.455080, 0.070910, -0.766240, -0.611460, 
0.708910, 0.643630, -0.648630, -0.090430, -0.720410, 0.925070, -0.797730, -0.108030, -0.016500, -0.728230, 

0.315220, 0.388620, -0.878620, -1.068090, -0.632230, 0.718730, -0.702770, -0.524350, -0.953060, -0.220010, 
-0.244070, -0.848340, 0.068330, 0.702800, 0.208040, 0.648210, -0.118430, -0.357620, 0.739380, -0.714120, 
0.711640, -0.242550, 0.412820, 1.052960, 0.980030, 0.266480, -0.139760, -0.477220, -0.217080, 0.099790, 
0.498880, 0.833960, -0.061590, -0.137510, 0.666150, 0.360440, 0.435200, 0.358930, 0.696370, -0.585260, 
-0.358510, 0.415480, -0.560920, -0.107850, 0.776560, -0.733570, -1.040470, -0.236310, -0.821730, 0.856470, 

-0.692480, 0.105080, 0.172570, -0.065760, -0.023810, -0.325710, 0.472980, 0.193920, -0.713340, -0.263880, 
-0.602410, 0.588040, -0.331680, -0.085840, -0.926300, 0.637800, -0.748960, -0.331660, -0.580560, -0.055400, 
-0.379210, 0.185820, 0.866880, 0.863940, -0.945450, 0.793220, 0.779270, -0.442860, 0.760020, 0.096590, 
-0.643180, -0.281350, -0.563420, 0.061670, -0.784670, 0.627600, 0.877180, 0.472830, 0.898340, -0.344110, 
-0.390290, -0.179530, 0.284510, 0.959390, 0.936230, -0.501960, -0.639370, 0.263210, -0.692560, 0.768410, 

-0.791660, 0.719360, 0.910140, -0.963490, -0.789020, -0.361600, 0.158170, 0.278680, -0.117870, 0.698600, 
-0.411780, -0.065750, -1.043740, -1.112870, 0.482280, 1.286520, -0.280630, 0.604480, -1.607240, -0.294400, 


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
      0.0, 0.115240, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.886230, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.129500, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.019220, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.465340, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.755800, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.908130, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.746580, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.718400, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.295190, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.519170, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.593910, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.813560, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, -0.005580, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 0.895490, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.045990, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.651080, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.130960, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.615990, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.538360, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.248620, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.475960, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.095040, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.343660, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.328070, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.161500, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.208670, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.841460, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.824440, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.158340, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.604630, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.337550, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.605440, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.531740, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.990910, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.723060, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.568900, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.421240, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.844120, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, 0.207440, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.240240, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.899110, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.099130, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.385970, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.871390, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.405250, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.608700, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.807990, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, -0.019250, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.078260, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.286010, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.387270, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.842410, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.992990, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.678250, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.375080, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.119200, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.399220, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.498260, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.425090, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.139080, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.526230, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.666430, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.668650, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.963600, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, -0.078800, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.727510, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -1.023530, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.715130, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.912080, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.386520, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int oeh(float *in, float *out, int init)
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
