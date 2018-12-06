/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  y.c
  --------------------------------------------------------
  generated at Mon Jun 22 16:04:22 1998
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
-0.048200, -0.584560, 0.463990, -0.952820, 0.404110, -0.192560, -0.180780, 0.595000, -0.771790, 0.390690, 
0.699590, 0.346240, 0.213100, -0.251860, -0.489420, -0.180710, -0.039680, 0.048000, -0.261680, 0.355430, 
-0.898780, 0.256780, -0.887780, 0.985140, 0.011140, 0.454460, 0.954880, -0.167790, 0.589080, -0.755390, 

0.516200, 0.382150, -0.760100, 0.042790, -0.392330, 0.439700, -0.711460, -0.372650, 0.083020, -0.919270, 
-0.484230, 0.287820, 0.589620, 0.346370, 0.427080, -0.297950, -0.400980, -0.130380, -0.603420, 0.228450, 
-0.625670, -0.673530, 0.639060, -0.886790, 0.147740, -0.041330, 0.907260, -0.812130, -0.753180, -0.522730, 

-0.395520, -0.574760, 0.250300, 0.803380, 0.067370, 0.515330, -0.750450, -0.114880, 0.997170, -0.721030, 
1.123340, -0.737860, 0.559300, 0.444120, -0.894830, -0.816170, -0.570020, 0.088670, 0.637850, -0.097640, 
0.373550, 0.317840, 0.477350, 0.652020, 0.968490, 0.910430, 0.530860, 0.157120, -0.318710, 0.556310, 

0.905190, 0.221380, 0.052630, 0.582700, 0.578110, -0.809760, 0.327420, 0.631480, 0.577530, -0.267360, 
0.925970, -0.535730, 0.969890, 0.146070, 0.664300, -0.838660, -0.796450, 0.051110, -0.719130, -0.386480, 
-0.846100, 0.104480, 0.202870, -0.786610, -0.383000, -0.677470, -0.450950, -0.268020, -0.348860, -0.154420, 

-0.891340, -0.293920, 0.888840, 0.210480, -0.279840, 0.635460, 0.250540, -0.280680, 0.948620, -0.682760, 
0.781060, -0.439480, 0.449570, -0.890600, 0.201250, 0.295760, 0.519190, -0.286030, 0.426520, 0.516680, 
0.501050, -0.911460, 0.726570, 0.459880, -0.161320, 0.351960, -0.763380, 0.405190, -0.400420, -0.666290, 

-0.314580, 0.820480, -0.796510, 0.493340, -0.203600, -0.658060, -0.682210, 0.262770, -0.514100, 0.781570, 
-0.668960, -0.203020, -0.709900, 0.351880, -0.364500, 0.338160, -0.761790, -0.938410, 0.820880, -0.934900, 
0.863190, -0.229310, 0.923750, 0.247050, 0.013760, 0.436150, -0.124610, -0.206660, -0.609990, 0.106930, 

0.024950, 0.414800, 0.411420, 0.604610, 0.956370, -0.701580, -0.137110, 0.778730, -0.465950, 0.761800, 
0.548860, -0.928810, -0.510380, -0.659650, -0.660730, 0.485330, 0.475710, 0.323020, 0.230540, -0.043040, 
0.436470, 0.173480, -0.741790, 0.908220, 0.409670, 0.211510, -0.152520, 0.358780, -0.639580, 0.049040, 

0.458020, -0.835350, -0.950020, 0.330560, -0.788550, 0.445910, 0.249260, -0.527840, 0.084350, -0.801260, 
0.230290, -0.199170, -0.958610, 0.323460, 0.152590, 0.665220, 0.590160, 0.396790, 0.130160, 0.950530, 
-0.408500, 0.824220, -0.102750, 0.367660, 0.391850, -0.001530, 0.863950, -0.886030, -0.420450, -0.612630, 

-0.378790, -0.415270, -0.715950, -0.277460, -0.948120, 0.064340, -0.059570, 0.955480, -0.215220, 0.904860, 
-0.331630, 0.339660, -0.830760, 0.265270, 0.341090, -0.765740, -0.517940, 0.756060, 0.232400, 0.121810, 
-0.910180, -0.216260, -0.663920, 0.125760, -0.575090, 0.881080, 0.719970, -0.098360, -0.942870, -0.769800, 

0.172600, -0.709160, 0.427890, 0.783930, -0.152510, -0.541140, 0.694840, -0.616040, -0.496190, 0.179950, 
0.042990, 0.302660, 0.169590, 0.954410, -0.050780, -0.434510, 0.529080, -0.384430, -0.565870, -0.527290, 
0.762810, 0.276270, -0.856500, -0.532010, 0.421780, -0.967320, 0.149080, 0.926950, -0.197240, 0.968810, 

0.815400, 0.319680, 0.586510, -0.140420, 0.591530, -0.517730, -0.492220, 0.154050, 0.429460, -0.700440, 
0.103460, -0.578620, 0.183470, 0.343720, -0.898890, 0.506540, 0.290220, 0.195280, -0.068000, -0.822990, 
-0.058760, -0.339000, -0.935520, 0.635260, -0.141350, 0.940670, 0.620760, 0.738400, -0.113970, 0.592020, 

0.923200, 0.641580, -0.774250, -0.506920, 0.430180, 0.240220, -0.986780, -0.545570, 0.225060, 0.636120, 
0.629120, -0.436480, -0.000670, -0.258760, 0.631700, 0.115390, -0.085850, 0.822610, 0.447910, 0.969280, 
-0.083910, -0.757850, 0.859620, 0.875960, 0.517910, 0.385870, -0.722480, 0.771170, -0.881640, 0.141090, 

-0.504050, 0.101760, 0.153780, -0.371540, 0.609710, 0.919890, 0.523400, -0.272090, 0.724990, 0.354450, 
-0.674120, 1.035800, -0.726150, 0.226000, -0.174780, 0.461280, 0.158390, -0.483700, -0.567260, 0.592710, 
0.830850, 0.762930, 0.414480, -0.715190, 0.572710, -0.376850, -0.624540, -0.692190, 0.847520, 0.854120, 

-0.431390, 0.733770, 0.184320, 0.821590, -0.498740, -0.252990, -0.425500, -0.065820, 0.800240, -0.464650, 
-0.046240, 0.096800, 0.449490, -0.847640, 0.171230, 0.046660, -0.373620, 0.481440, -0.620590, -0.770640, 
1.036090, 0.819860, 0.453500, -0.967970, 0.339790, -0.633600, -0.665450, 0.456600, -1.026210, 0.982480, 

-0.941670, -0.358720, 0.393060, -0.459210, -0.862720, -0.282850, -0.822730, -0.067450, -0.953350, 0.533050, 
0.123290, -0.137510, -0.566800, 0.568550, -0.817660, 0.718400, -0.878070, -0.542400, 0.003740, -0.131830, 
0.990680, 0.239470, 0.244670, -0.457100, -0.073020, -0.355110, -0.181470, 0.411600, 0.763230, 0.402530, 

-0.836490, 0.141960, -0.941870, 0.466110, -0.093480, -0.176280, 0.517540, -1.011110, -0.006390, 0.679880, 
-0.214780, 0.683450, 0.500410, 0.232650, 0.644760, -0.325390, 0.505240, -0.900440, -0.358130, 0.462510, 
0.120990, -0.668500, 0.117630, 0.761960, -0.840250, -0.348530, 0.640490, -0.613690, -0.488980, 0.630360, 

0.506040, 0.455990, -0.347890, -0.945420, -0.857040, -0.737900, -0.658040, -1.029810, -0.399780, -0.329040, 
0.750040, -0.503140, 0.551050, 0.398890, 0.124690, 0.217560, 0.021240, -0.670470, -0.548600, -0.068540, 
-0.485670, 0.675530, -0.694650, -0.402500, 0.520130, 0.866090, 0.054170, -0.667510, 0.470540, 0.321880, 

1.019870, -0.718620, 0.649710, -0.889940, -0.428380, 0.189370, -0.548000, 0.065990, 0.337850, 0.692810, 
-0.467680, 0.227590, 0.339740, -0.183350, -0.856340, 0.764230, -0.481810, 0.881700, -0.166740, -0.323290, 
1.037870, -0.873510, 0.327470, -0.689190, -0.193470, 0.975300, -0.631540, 0.030300, 0.502000, -0.340890, 

0.916050, -0.519200, -0.214600, -0.809720, 0.301690, 0.649440, 0.381520, -0.070030, -0.748840, -0.896260, 
0.980780, 0.190990, -0.503420, -0.273430, -0.711780, -0.550240, -0.104430, -0.179770, -0.133600, -0.144360, 
0.454230, -0.492720, 0.161340, -0.602720, 1.047800, 0.663460, -0.048380, -0.915820, -0.824960, 0.803740, 

0.350650, -0.616560, 0.883530, 0.224450, 0.633270, 0.300150, 0.652170, 0.363910, 0.039590, -0.289880, 
0.609870, -0.145650, -0.489070, -0.847030, -0.823520, 0.760540, -0.802410, 0.184360, 0.847430, -0.594900, 
0.073780, 0.825810, 0.841650, -0.107480, 0.776660, -0.553920, 0.749850, 0.138520, 0.863100, -0.636360, 

0.674670, -0.235900, -0.123990, -0.790540, 0.025450, 0.296490, 0.779540, 0.827210, 0.045570, 0.738000, 
-0.349360, -0.385320, 0.983270, 0.423680, 0.418340, -0.573800, -0.957380, 0.701890, 0.303410, 0.065970, 
0.285840, -0.805820, 0.216330, 0.654520, -0.126800, -0.853500, 0.352690, -0.016640, 0.551870, 0.134370, 

-0.157000, -0.877820, -0.857670, 0.177860, -0.001940, -0.344020, 0.141270, -0.267880, -0.421410, 0.511750, 
-0.758110, 0.472850, 0.210090, -0.125600, 0.567760, 0.461230, 0.966110, 0.175330, -0.222660, -0.263330, 
0.411400, 0.031940, 0.878740, 0.588510, 0.418420, 0.480280, -0.701680, -0.513730, 0.547060, -0.429640, 

-0.574730, -0.393950, 0.033280, -0.681780, 0.744320, -0.634200, -0.714140, -0.603130, -0.599140, -0.032310, 
0.511580, -0.738800, -0.264280, -1.059210, -1.011220, 0.388270, 0.035180, 0.048430, -0.982040, -0.082350, 
-0.552480, -0.422930, 0.124350, 0.136160, 0.943890, 0.619910, -0.211260, 0.692340, 0.877940, -0.185370, 

-0.717200, -0.086190, 0.268070, -0.666300, 0.313440, -0.194100, -0.302380, 0.923030, -0.228560, -0.409020, 
-0.680710, -0.825000, -0.850850, 0.632880, 0.826920, -0.101250, -0.466400, -0.951580, 0.058040, 0.191460, 
-0.496680, -0.940630, 0.850670, 0.992060, -0.135580, -0.994420, -0.220060, -0.426480, 0.825280, -0.155540, 

0.156050, 0.155820, -0.491020, 0.492080, 0.354100, 0.287560, 0.175700, 0.261300, 0.496290, 0.774650, 
-0.912950, -0.619350, -0.775410, 0.147660, -0.296370, 0.581080, -0.082230, -0.883190, -0.751810, -0.855550, 
-0.733280, 0.293260, 0.700130, 0.522580, 1.049740, -0.180810, -0.421250, -0.105690, -0.233950, -0.406580, 

0.418220, 0.103210, 0.172830, -0.194760, 0.158500, -0.391090, -0.938100, 0.272290, 0.933310, -0.329010, 
-0.289450, -0.857270, 0.072800, 0.506680, -0.669110, -0.084390, 0.901320, -0.333460, 0.174240, -0.029600, 
0.047790, 0.207400, -0.263000, -0.156280, 0.838740, -0.453270, 0.869460, -0.709800, 0.685010, 0.528580, 

0.158990, 0.178290, -0.837280, -0.303590, -0.824290, 0.607170, 0.944880, -0.245960, 0.445720, -0.339950, 
0.157160, 0.503590, 0.947390, 0.887750, 0.681650, 0.487490, -0.752890, -0.154900, -0.325760, -0.451010, 
-0.277110, -0.096380, -0.861860, -0.723150, -0.837800, -0.788320, 0.416690, -0.109910, -0.857250, -0.456460, 

0.353660, -0.086950, -0.027730, -0.583500, -0.320910, 0.638980, -0.229090, -0.134510, 0.505710, 0.544770, 
-0.621430, 0.774020, -0.258400, 0.524440, -0.026630, 0.621960, 0.424740, -0.300520, -0.295070, -0.594310, 
-0.704090, 0.723570, -0.876660, 0.347590, -0.587010, -0.603840, -0.330090, 0.793010, -0.387310, -0.189890, 

0.168000, -0.790970, -0.386610, -0.965880, -0.966420, 0.160760, 0.934140, -0.880230, -0.421170, -0.517950, 
0.394680, -0.312070, -0.520150, 0.689070, 0.029700, -0.430680, 0.548160, 0.991150, -0.191090, 0.108770, 
0.797340, -0.212500, 0.791080, 0.583130, -0.031860, -0.746330, 0.073160, 0.517350, 0.596700, -0.083320, 

0.822740, 0.610850, -0.884980, 0.382570, 0.501260, -0.403320, -0.102470, -0.553030, 0.749720, 0.895230, 
-0.367400, 0.652910, 0.050340, -0.774690, 0.863060, 0.705490, -0.045310, 0.403940, -0.092940, 0.585960, 
0.957950, 0.508620, -0.142420, 0.519980, 0.784610, 0.323790, 0.733840, 0.552260, -0.243510, -0.057970, 

0.380210, 0.911760, 0.992040, -0.529070, 0.109230, -0.350020, 0.450770, -0.311050, -0.141570, -0.530020, 
0.551620, -0.507780, 0.040620, -0.699980, 0.455040, 0.402030, -0.434970, -0.072370, 0.483700, -0.254520, 
-0.303180, 0.523260, 0.958900, -0.632290, 0.369180, 0.209010, 0.361120, -0.748470, -0.828420, -0.580400, 

0.491160, -0.765140, -0.804090, 0.593980, 0.704720, -0.720400, 0.113180, 0.264400, 0.005600, 0.540350, 
-1.051570, -0.416100, 0.353420, 0.708570, -0.891440, -0.959100, 0.681690, 0.486480, -0.409480, 0.808290, 
0.937520, 0.032370, 0.350920, 0.137970, 0.738200, 0.475120, 0.076490, -0.005860, -0.706900, 0.833780, 

0.209020, 0.958050, -0.838920, -0.656650, -0.907530, 0.766390, -0.287880, 0.193920, 0.106720, -0.657290, 
0.882670, -0.500610, -0.786490, 0.751540, 0.238630, -0.525730, -0.364270, -0.384120, -0.481660, -0.366610, 
0.898350, -0.038940, -0.547110, 0.543220, 0.800000, 0.898120, 0.962190, -0.897620, -0.770690, 0.337110, 

0.670110, 0.554690, -0.586180, 1.011010, 1.019930, 0.237940, 0.230510, 0.545840, 0.082690, -0.894300, 
-0.544470, 0.692840, -1.010440, -0.740280, 0.411160, -0.052270, 0.207360, 0.262570, -0.738060, -0.034700, 
0.513650, -0.438220, 0.677700, 0.484840, 0.399460, -0.868910, 0.475510, 0.350540, 0.775740, 0.606920, 

-0.934520, 0.091490, 0.219530, 0.065210, 0.353010, -0.023700, -0.512930, -0.808880, -0.629290, 0.514580, 
-0.754310, 0.997260, -0.274680, 0.335030, 0.047540, 0.477000, 0.971780, -0.068390, -0.924470, -0.533340, 
0.345320, 0.892000, -0.585120, -0.397550, -0.075550, -0.719000, 0.184060, -0.537790, -0.434980, 0.077250, 

0.759500, -0.829710, -0.984480, -0.329800, 0.242090, 0.105600, 0.424390, -0.171050, -0.698880, -0.647570, 
0.327710, 0.317860, 0.405410, -0.335710, -0.402420, -0.741090, -0.390230, 0.306940, 0.521490, 0.184440, 
-0.277910, 0.764090, -0.329640, 0.339580, 0.856290, 0.379450, 0.767100, -0.827400, 0.284780, 0.589980, 

-0.999740, -1.088220, -0.453760, -0.744160, 0.640950, -0.326540, -0.500640, 0.764150, 0.768870, -0.521400, 
0.653210, 0.535190, 0.018690, 0.812270, -0.850060, 0.758530, -0.612740, -0.899420, -0.558610, 0.549860, 
-0.457470, 0.252880, 0.127860, 0.937270, 0.086810, -0.392820, 0.604610, 0.623660, 0.552830, -0.623750, 

-0.636690, 0.079380, -0.006660, -0.413510, 0.137110, -0.171960, -0.501290, -0.464680, -0.508360, 0.749720, 
0.407470, -0.741350, -0.383050, -0.168400, 0.354340, 0.405300, -0.702770, 0.570400, 0.069800, -0.279850, 
-0.671940, -0.320630, -0.127450, -0.137230, -0.809970, 0.929120, 0.449260, -0.741080, -0.218130, 0.221680, 

-0.881590, 0.850890, -0.000420, -0.852240, -0.196850, -0.277060, 0.736200, 0.986460, 0.604350, 0.602330, 
-0.464670, 0.485260, -0.709380, -0.428010, -0.683480, 0.379880, 0.827810, -0.480660, 0.478180, -0.965570, 
-0.654900, 0.818050, 0.325140, -0.410730, -0.501920, 0.509450, 0.950610, 0.433690, 0.925330, 0.208160, 

0.758290, 0.595240, 0.877770, -0.524970, 0.974560, 0.956340, -0.349070, -0.576790, -0.660880, 0.724670, 
-0.267520, 0.409370, 0.081120, 0.078840, -0.751780, -0.017100, -0.554180, -0.137950, 0.657680, 0.715880, 
0.336330, -0.442510, -0.343740, -0.879880, 0.740600, 0.166200, -0.717900, -0.193810, -0.844100, 0.914340, 

0.099700, 0.497820, -0.023070, -0.083360, 0.781400, 0.760070, -0.259000, 0.301860, 0.173910, 0.226300, 
0.199720, -0.320400, 0.291940, -0.831120, -0.814930, 0.391130, -0.058360, 0.917990, 0.677950, 0.798080, 
-0.346870, 0.542260, 0.709190, -0.703020, -0.895880, 0.695820, -0.331550, -0.485470, 0.612640, -0.289920, 

0.607010, 0.513250, 0.765970, 0.928220, 0.620450, 0.759930, -0.582290, 0.361860, -0.933630, 0.029400, 
0.770380, 0.237240, -1.029930, 0.506040, 0.526140, 0.105830, 0.799790, 0.034360, -0.022370, -0.397630, 
-0.246190, -0.437860, -0.592830, 0.700170, -0.198990, -0.151640, -0.676330, -0.090200, 0.628890, 0.671640, 

0.922660, 0.148130, 0.921740, -0.702690, 0.639140, -0.541770, 0.670800, 0.675890, 0.032420, -0.787260, 
0.233170, 0.752790, -0.394280, 0.822740, 0.458450, 0.516630, -0.286210, -0.207360, -0.620210, -0.785140, 
-0.380540, -0.781720, -0.014280, -0.803000, -0.566570, -0.732000, 0.863620, -0.203510, 0.511920, 0.043240, 

-0.664120, -0.701600, -0.006920, -0.978470, -0.204000, -0.876150, -0.415200, 0.715420, 0.700630, 0.970310, 
0.275430, 0.315090, -0.908450, 0.279520, 0.783720, -0.453740, 0.159160, -0.797470, -0.478200, 0.571740, 
0.707890, 0.689570, 0.624510, -0.391650, 0.598040, -0.391220, -0.186640, -0.453920, -0.567150, 0.752510, 

0.325520, 0.468990, 0.049770, 0.750640, 0.754620, 0.167000, 0.520750, 0.983380, -0.860060, 0.826610, 
0.847240, 0.346360, 0.783370, -0.687750, -0.057350, 0.612380, -0.435750, -0.904540, 0.872490, 0.779230, 
0.392780, -0.710800, -0.034240, 0.384730, 0.749710, -0.788430, 0.185410, -0.931420, -0.490100, -0.000560, 

-0.348890, -0.217620, 0.576370, 0.546670, 0.433920, -0.950190, -0.525830, -0.158080, -0.885180, 0.630950, 
0.200750, 0.372930, -0.366380, 0.262850, -0.289740, -0.745650, -0.699530, 0.170600, -0.766040, 0.281910, 
-0.499330, -0.585470, -0.414300, -0.990430, -0.705180, -0.660920, -0.867100, -0.239570, 0.180580, -0.070050, 

0.346110, -0.725660, 0.175470, -0.841330, 0.334190, 0.693170, -0.089670, 0.610540, 0.689260, -0.041480, 
-0.314800, -0.405260, -0.927500, -0.260610, 0.609190, 0.601330, -0.657380, -0.085810, -0.814110, -0.528650, 
0.336800, 0.753140, 0.183820, -0.903130, -0.781400, 0.978170, 0.052050, -0.297110, -0.816300, -0.637700, 

0.730540, 0.926460, -0.987460, 0.308960, -0.332980, 0.961460, 0.740420, 0.139870, -0.569560, 0.021170, 
0.852440, -0.025600, -0.672620, 0.846770, 0.122440, 0.772200, 0.876810, 0.910920, 0.253920, -0.077100, 
-0.152130, 0.564130, -0.593730, -0.222210, 0.775480, 0.131080, 0.539150, -0.112790, -0.553900, -0.811760, 

-0.389900, 0.991230, -0.818140, 0.372140, -0.834910, -0.049920, 0.267030, -0.996450, -0.273450, 0.186490, 
-0.360330, -0.668400, -0.634830, 0.389260, -0.416710, 0.550150, -0.748040, 0.882540, -0.775300, 0.043860, 
-0.857240, -0.998260, 0.642300, -0.684180, 0.276840, -0.880610, -0.474450, 0.420750, 0.990230, 0.785630, 

0.061120, -0.619850, -0.894470, -0.623790, -0.016510, -0.486570, 0.110080, 0.693450, 0.677800, 0.334110, 
0.946150, 0.660170, -0.887130, -0.216140, 0.890000, 0.021140, 0.268650, 0.044100, 0.384920, 0.190640, 
0.889360, 0.496290, 0.984240, 0.706740, 0.211440, 0.695380, 0.424020, 0.699010, -0.029120, 0.827980, 

-0.678410, 0.506240, 0.624930, -0.617590, 0.406310, 0.230370, 0.018700, 0.648020, -0.362130, 0.513730, 
0.339310, -0.680010, -0.391690, 0.237130, -0.691010, -0.544060, -0.136770, 0.387530, 0.022120, 0.830330, 
-0.166400, -0.538470, 0.489460, -0.501700, 0.081750, -0.517280, -1.029420, 0.252070, 0.127750, -0.499460, 
-0.718670, -0.753700, -0.743220, 0.717700, 0.579060, 0.531150, 0.402050, 0.918370, -0.594060, -0.334240, 
0.123160, 0.375080, -0.233610, 0.415430, 0.970150, 0.082600, -0.726560, 0.131680, -0.364680, -0.713260, 

-0.157440, -0.924150, -0.377760, -0.928170, -0.889780, 0.997870, -0.429230, -0.148710, -0.904260, 1.004850, 
0.241880, -0.169380, 0.574640, -0.973840, 0.680820, 0.303970, 0.221280, -0.556570, 0.420750, -0.415810, 
-0.944400, -0.539700, -0.452430, 0.219230, 0.997810, 0.311610, -0.325880, -0.548070, 0.488010, 0.464600, 
-0.163660, -0.285200, -0.697670, 0.477670, 0.233760, 0.309100, 0.361670, 0.525360, 0.167030, -0.153550, 
-0.642130, 0.179070, -0.377750, -0.752910, -0.580320, -0.147870, 0.422640, 0.819050, 0.762800, -0.907730, 

0.322750, -0.890650, -0.015310, -0.591560, -0.146330, -0.123480, -0.849960, 0.833350, -0.405140, 0.774180, 
0.658990, 0.816050, 0.484490, -0.708770, -0.611730, 0.778470, 0.442950, -0.099040, -0.752280, 0.893370, 
-0.670050, -0.005300, 0.840910, -0.327460, -0.643250, -0.261210, 0.897850, 0.954260, -0.966600, 0.587450, 
-0.974350, -0.426450, -0.262290, 0.406550, 0.089780, -0.052340, 0.685620, 0.516070, -0.939040, 0.855680, 
0.335600, 0.630120, 0.323620, 0.509610, -0.163500, 0.641090, -0.475910, -0.121210, 0.336800, -0.107330, 

-0.983560, -0.872060, -0.256250, 0.220250, 0.370890, -0.457020, -0.238980, -0.828210, -0.828240, -0.091370, 
-0.636340, -0.664960, 0.729080, -0.238640, 0.352610, -0.992830, -0.458330, -0.130670, -0.256020, -0.407670, 
-0.286310, -0.185930, -0.589420, -0.231430, -0.735630, -0.006440, -0.719770, -0.227310, 0.239380, -0.396730, 
0.694860, 0.137060, 0.895070, -0.381620, 0.665990, -0.622640, -0.242850, -0.333090, 0.425580, -0.120480, 
0.568830, 0.802030, -0.313990, -0.413970, 0.270390, 0.937800, 0.335960, 0.251730, 0.859000, -0.930120, 

0.023950, -0.292750, 0.374490, -0.015730, 0.114050, 0.177190, -0.722340, 0.822940, -0.752710, 0.349160, 
0.612090, -0.680250, 0.918070, -0.841810, -0.524420, 0.480690, -0.304450, 0.930720, 0.137470, 0.953490, 
-0.969200, 0.796070, 0.648580, -0.644640, -0.312030, 0.094540, -0.624540, 0.293470, 0.571840, 0.617900, 
-0.841080, 0.315280, 0.274310, 0.242200, -0.073470, 0.556080, -0.573230, 0.733030, 0.784340, 0.698670, 
-0.364670, 0.293630, 0.875970, 0.708850, 0.095850, -0.426060, 0.177190, 0.222840, -0.011410, -0.962590, 

-0.372770, 0.705320, 0.142580, -0.107970, 0.204430, -0.662570, -0.404610, 0.082870, -0.677900, -0.288070, 
0.891250, -0.208440, 0.359990, 0.070240, 0.068900, 0.766550, -0.649340, 0.921820, 0.574300, -0.706280, 
0.727850, -0.333860, -0.590630, 0.573140, 0.726910, 0.889770, -0.636410, 0.443720, -0.485920, -0.302000, 
-0.349810, -0.276000, -0.456030, 0.002030, -0.552260, 0.537090, -0.685940, -0.677260, -0.934150, 1.006120, 
0.020730, -0.562520, 0.335150, 0.790650, -0.840960, -0.489050, 0.672500, -0.546740, -0.309990, 0.739270, 

0.233330, 0.950800, 1.000400, 0.162350, -0.687470, 0.139470, -0.268150, 0.285030, 0.197180, 0.035620, 
-0.994310, -0.863920, -0.115410, 0.911210, -0.383380, -0.290630, 1.066960, 0.371640, -0.167800, -0.615710, 
0.777310, 0.900030, -0.250640, 1.000380, 0.409850, -0.076190, -0.854100, -0.062720, -0.006210, 0.134100, 
0.282420, 0.792370, 0.389870, 0.661990, -0.183220, -0.923050, 0.495230, 0.389140, 0.448040, -0.134030, 
0.814430, -0.371450, -0.799590, 0.246070, -0.920950, 0.347250, -0.879370, -0.884160, -0.374140, -0.095470, 

0.638540, 0.234520, -0.282630, -0.296310, -0.873260, 0.847580, 0.038010, 0.210880, 0.652460, -0.307840, 
-0.022830, -0.712070, 0.216720, -0.450230, -0.301050, -0.867820, 0.561440, 0.768010, -0.022310, -0.624710, 
-0.885720, 0.534490, -0.245150, -0.240050, -0.266030, -0.876160, 0.261130, 0.635040, 0.492710, 0.344080, 
-0.065150, 0.877260, 0.833380, 0.724770, 0.400410, 0.377880, -0.303290, -0.095410, -0.242670, -0.546460, 
0.481330, -0.677090, -0.823830, -0.034460, 0.607450, 0.906010, -0.991700, 0.949860, 0.532830, 0.712280, 

-0.121090, -0.443960, 0.407910, 0.900740, -0.850730, -0.311250, -0.279650, 0.083150, 0.220620, -0.412650, 
-0.498760, 0.949330, -0.178810, -0.835080, 0.053920, 0.181420, -0.007890, 0.724760, 0.644320, 0.878860, 
-0.882670, -0.118860, 0.965290, -0.765300, 0.217660, -0.171440, 0.368880, -0.876730, -0.102570, 0.693190, 
0.635580, 0.035700, 0.839830, 0.187150, -0.676610, -0.750560, -0.192650, -0.106320, 0.930730, -0.944000, 
0.638940, -0.353990, 0.798380, -0.641040, -0.891710, 0.963070, 0.450270, -0.888100, 0.398060, -0.841860, 

0.887600, -0.774520, -0.350980, 0.598670, -0.262130, -0.872100, 0.774380, 0.206620, -0.343390, 0.194570, 
0.677470, 0.455880, 0.928580, -0.891680, 0.879680, -0.551640, -0.277880, -0.511870, 0.419180, 0.366520, 
0.483900, -0.011980, -0.965950, 0.631250, -0.683440, 0.849720, 0.167360, 0.955560, -0.415280, -0.991390, 
0.752080, -0.571740, 0.273860, 0.779390, 0.137900, 0.328440, 0.567330, -0.141890, 0.664170, -0.307000, 
-0.423740, -0.535620, 0.193510, 0.878630, -0.546380, 0.186390, -0.236640, 0.982560, -0.195460, 0.785720, 

-0.966380, -0.746720, 0.174470, -0.108080, 0.515150, -0.660400, -0.005600, -0.481210, 0.082880, -0.394550, 
-0.640130, -0.462740, -0.943310, -0.571350, 0.852240, -0.785880, -0.924200, -0.379610, -0.953800, -0.846800, 
0.823470, -0.685450, -0.522980, 0.439640, 0.889000, 0.568870, 0.632010, -0.689730, -0.860520, 0.281020, 
0.168190, 0.672680, 0.427260, 0.137680, -0.760330, 0.280840, -0.178490, 0.941600, -0.145070, -0.734560, 
-0.555530, -0.154490, -0.559940, -0.413660, -0.374390, 0.100480, -0.401410, 0.322000, -0.329010, 0.376960, 

-0.644760, -0.557290, 0.575060, -0.061330, 0.750730, -0.736190, -0.204350, -0.169720, 0.371380, 0.658370, 
0.548270, 0.207960, -0.966780, -0.935690, -0.431380, -0.123720, 0.463090, 0.837200, 0.192630, -0.484000, 
0.193250, -0.895910, 0.573680, 0.331670, -0.510480, -0.906670, 0.772310, -0.955120, 0.392270, -0.462500, 
0.696310, -0.900000, 0.207500, 0.879250, 0.384140, 0.106020, -0.840850, -0.324900, -0.879960, -0.558090, 
0.317050, 0.201670, 0.371790, -0.500250, -0.538860, -0.585460, -0.302830, 0.695630, -0.887800, 0.566950, 

-0.040790, -0.812230, -0.254240, -0.135150, 0.271340, -0.072320, 0.279180, 0.615260, 0.272410, -0.225590, 
0.116890, -0.720820, -0.492040, -0.594460, -1.017200, 0.791690, 0.515700, -0.839870, -0.047940, 0.765930, 
0.636030, 0.021820, 0.375040, 0.818480, -0.043060, -0.484850, -0.443950, 0.935700, -0.217900, -0.388640, 
-0.662860, 0.930470, 0.771720, -0.705490, -0.279360, -0.567480, -1.049860, -0.247380, 0.972700, -0.666210, 
0.424680, -0.597080, 0.222180, 0.088490, 0.556360, 0.053480, 0.444380, -0.929220, -0.021190, 0.225230, 

0.465090, 0.704770, 0.933110, 0.301790, -0.096570, -0.240210, 0.450840, -0.415400, 0.101210, 0.513490, 
0.984390, -0.342600, 0.868760, -0.719860, -0.106340, -0.936880, -0.362040, 0.518700, -0.837670, -0.326750, 
-0.905610, -0.306670, 0.582620, -0.327290, -0.221440, 0.981180, 0.970400, -0.812940, -0.810910, 0.474830, 
0.189890, -0.541710, 0.512320, -0.725580, -0.281630, 0.589800, 0.062260, -0.348870, 0.637400, 0.641020, 
0.475310, -0.507740, -0.684320, -0.493550, -0.709260, 0.768080, -0.635990, -0.162090, 0.460370, -0.211720, 

0.660760, -0.857830, -0.236540, -0.434320, 0.598620, 1.003170, 0.034300, 0.700360, -0.658740, -0.558640, 
-0.105100, -0.836330, -0.746250, 0.411070, 0.662940, 0.293200, -0.289660, -0.276200, 0.750170, -0.460090, 
0.291620, 0.822110, -0.492870, 0.930530, 0.511930, 0.217320, 0.194750, 0.225150, -0.342020, -0.543620, 
-0.876530, -0.492160, -1.119530, 0.777730, -0.429710, -0.916810, 0.017900, -0.389050, 0.292300, 0.213830, 
-0.278020, 0.820140, 0.629190, 0.412060, 0.327960, -0.439110, 0.831670, -0.801600, 1.040640, 0.467760, 

-0.859210, -0.203550, -0.455080, 0.079040, 0.224830, 0.575270, -0.050950, 0.598070, -0.895040, -0.325930, 
0.021550, -0.202000, -0.130580, -1.009000, -0.719240, -0.036540, 0.788840, -0.531280, 0.537520, -0.566770, 
0.665490, 0.605330, 0.205470, -0.369910, -0.355820, -0.799790, 0.688380, -0.555610, 0.184600, -0.126450, 
-0.514050, 0.677030, 0.048980, -0.168350, -0.649790, -0.799620, 0.729610, 0.953310, 0.911060, 0.718390, 
-0.362220, -0.169700, 0.204340, 0.882690, -0.248570, 0.748190, -0.666780, 0.049130, 0.246550, -0.443820, 

-0.119800, 0.131980, 0.827710, -0.122110, 0.029590, -0.194490, 0.410700, 0.447910, -0.316860, -0.411310, 
-0.860100, 0.344840, -1.108680, -0.928390, -0.244370, 0.369940, 0.877620, -0.821860, -0.243090, -0.275700, 
0.540450, -0.285060, -0.431160, -0.469020, -0.659600, 0.391690, 0.637480, 0.570170, -0.798290, 0.439370, 
0.097890, -0.206150, 0.546930, -0.271110, -0.697130, -0.398600, 0.799190, 0.531140, -0.953480, -0.562600, 
-0.544460, 0.034470, -0.434080, 0.885800, 0.049540, -0.889050, 0.146650, 0.356740, 0.884690, -0.031220, 

-0.785020, -0.069780, -0.230930, -0.897900, 0.780440, -0.677590, -0.212480, -0.778240, 0.614040, 0.608390, 
-0.667090, -0.870660, -0.004340, -0.417010, 0.585950, 0.734960, -0.030560, -0.888420, -0.757610, 0.313930, 
-0.742870, 0.440000, 0.208310, 0.704520, -0.451560, 0.358570, -0.071070, 0.501160, -0.122070, -0.985200, 
-0.042580, 0.095720, 0.321130, -0.615680, 0.438900, 0.765800, -0.176200, -0.132590, 0.480340, -0.257750, 
0.632110, 0.199900, -0.960500, -0.320360, 0.624490, -0.423190, 0.869270, -0.921420, 0.071200, 0.270330, 

0.808710, -0.588820, -0.305650, -1.013840, -0.827910, 0.776480, -0.067760, -0.454900, 0.460950, -0.240560, 
-0.567640, 0.736340, 0.546690, 0.464360, 0.179590, 0.643550, -0.046740, -0.119730, 0.969740, 0.386410, 
0.161030, -0.184640, -0.565610, -0.207760, 0.437130, 0.885870, 1.020910, 0.260900, -0.434920, 0.557200, 
-0.688300, 0.768400, -0.206730, -0.122410, 0.687010, 0.130290, 0.933180, 0.063380, -0.837430, -0.052930, 
-0.315810, -0.898880, -0.488610, -0.613830, 0.614640, -0.606360, -0.866180, -0.793430, 0.209000, 0.049350, 

0.810550, -0.710570, 0.297970, -0.603140, -0.447180, 0.964340, 1.018050, 0.323640, -0.096990, -0.360130, 
-0.305190, 0.937170, 0.451010, 0.811970, 0.693190, -0.743760, 0.080690, -0.550510, -0.331810, -0.599440, 
0.107460, 0.763710, -0.387540, 0.861920, 0.803320, -0.916500, 0.815690, 0.881070, 0.230910, -0.362160, 
-0.038040, -0.566830, -0.406860, -0.726370, 0.601570, -0.916730, -0.007820, -0.253480, 0.609820, -0.614910, 
-0.170620, -0.675920, 0.208940, 0.533270, -0.305150, 0.016970, -0.067580, 0.237440, 0.188430, -0.659280, 

-0.394980, -0.893310, 0.316880, -0.458930, 0.259330, 0.692890, -0.884900, -0.316030, -0.090470, -0.722410, 
0.840310, -0.328870, 0.632170, 0.026890, -0.788500, -0.457150, -1.348000, 0.732380, 0.789480, -0.497130, 


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
      0.0, 0.110610, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.936700, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.275420, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.026440, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.366860, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.714540, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.928840, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.848910, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.621580, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.221900, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.507740, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.648140, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.822450, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.185040, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 0.841320, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.164510, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.499210, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.021540, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.553780, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.653630, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.276590, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.429000, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.170090, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.353780, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.294120, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.079400, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.163910, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.835730, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.820680, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.201580, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.588940, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.286560, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.598760, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.749450, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.949680, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.649950, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.667780, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.545260, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.848280, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, 0.258780, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.230270, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.775970, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.131760, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.338820, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.819980, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.394540, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.640430, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.845950, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.079030, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.140530, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.258910, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.410260, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.901090, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.933080, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.722400, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.276780, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.057830, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.386940, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.501300, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.381390, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.214860, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.523290, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.783530, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.691450, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.922640, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, 0.015320, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.783880, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -1.134490, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.704720, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.974290, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.296420, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int y(float *in, float *out, int init)
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
