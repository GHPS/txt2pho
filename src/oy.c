/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  oy.c
  --------------------------------------------------------
  generated at Mon Jun 22 15:56:38 1998
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
-0.019390, -0.600560, 0.373060, -0.995080, 0.377670, -0.213050, -0.271880, 0.579790, -0.771790, 0.369480, 
0.709190, 0.292870, 0.184050, -0.304730, -0.524620, -0.211610, -0.069090, 0.034860, -0.411100, 0.322160, 
-0.932010, 0.240530, -0.887780, 0.985140, -0.124600, 0.442120, 0.860410, -0.230250, 0.633670, -0.772900, 

0.516140, 0.384580, -0.779530, 0.016560, -0.394550, 0.469860, -0.687970, -0.266030, 0.083020, -0.939340, 
-0.551360, 0.216790, 0.558090, 0.341940, 0.450370, -0.326780, -0.420930, -0.159560, -0.620140, 0.216370, 
-0.637190, -0.660440, 0.639060, -0.886790, 0.116060, -0.028680, 0.866370, -0.821300, -0.735900, -0.471720, 

-0.442250, -0.541560, 0.250040, 0.743760, 0.009850, 0.509280, -0.791030, -0.009230, 0.997170, -0.711090, 
0.842880, -0.614880, 0.507600, 0.329090, -0.973230, -0.881560, -0.632790, -0.031330, 0.683430, -0.159840, 
0.430770, 0.333160, 0.477350, 0.652020, 0.953950, 0.926150, 0.523220, 0.185150, -0.443550, 0.514540, 

0.896710, 0.220120, 0.070840, 0.592020, 0.594310, -0.787670, 0.342370, 0.666990, 0.577530, -0.270590, 
0.916570, -0.571670, 0.963650, 0.178480, 0.713850, -0.847680, -0.797070, 0.063380, -0.690570, -0.384280, 
-0.849380, 0.120200, 0.202870, -0.786610, -0.365300, -0.668650, -0.453590, -0.268620, -0.324170, -0.087750, 

-0.923020, -0.285510, 0.910130, 0.184680, -0.267680, 0.674730, 0.241420, -0.357670, 0.948620, -0.685060, 
0.810730, -0.488710, 0.506080, -0.866270, 0.182120, 0.345290, 0.556270, -0.209540, 0.452380, 0.560770, 
0.516530, -0.891410, 0.726570, 0.459880, -0.058890, 0.335740, -0.679080, 0.437600, -0.421960, -0.728880, 

-0.287580, 0.843790, -0.704600, 0.591540, -0.174330, -0.623140, -0.669480, 0.309570, -0.514100, 0.817970, 
-0.717370, -0.064060, -0.705520, 0.410430, -0.286920, 0.333760, -0.754960, -0.935770, 0.916860, -0.965210, 
0.904100, -0.188700, 0.923750, 0.247050, -0.008700, 0.443740, -0.100990, -0.157390, -0.563260, 0.203550, 

0.022880, 0.423530, 0.445850, 0.616650, 0.957460, -0.678660, -0.149430, 0.794560, -0.465950, 0.770180, 
0.524680, -0.881940, -0.476420, -0.657480, -0.667020, 0.494350, 0.482090, 0.305460, 0.270660, -0.053390, 
0.473480, 0.186550, -0.741790, 0.908220, 0.411940, 0.217800, -0.108430, 0.371730, -0.665000, 0.034280, 

0.408270, -0.850250, -0.857120, 0.381690, -0.811670, 0.499880, 0.299950, -0.464780, 0.084350, -0.778560, 
0.068830, -0.097800, -0.933040, 0.277200, 0.121930, 0.638050, 0.564340, 0.282730, 0.246370, 0.919060, 
-0.350550, 0.875030, -0.102750, 0.367660, 0.483850, 0.031460, 0.912690, -0.934820, -0.491860, -0.627690, 

-0.367240, -0.450790, -0.792200, -0.296310, -0.929950, 0.049710, -0.104870, 0.867210, -0.215220, 0.884580, 
-0.148860, 0.164280, -0.854120, 0.301620, 0.340210, -0.719420, -0.481000, 0.838450, 0.138680, 0.181620, 
-0.985320, -0.260620, -0.663920, 0.125760, -0.632560, 0.849900, 0.687870, -0.122280, -0.879480, -0.807920, 

0.159370, -0.709920, 0.428590, 0.776270, -0.161900, -0.562580, 0.706480, -0.625870, -0.496190, 0.182590, 
0.019980, 0.315040, 0.164250, 0.935600, -0.068720, -0.440060, 0.522250, -0.384660, -0.555230, -0.524690, 
0.756340, 0.259630, -0.856500, -0.532010, 0.423490, -0.970950, 0.143910, 0.937350, -0.211900, 0.951710, 

0.851790, 0.296150, 0.389270, -0.256010, 0.580490, -0.558560, -0.538600, 0.065020, 0.429460, -0.742460, 
0.123840, -0.733060, 0.103480, 0.321640, -0.918110, 0.498160, 0.280960, 0.244950, -0.239880, -0.773950, 
-0.165940, -0.357990, -0.935520, 0.635260, -0.168180, 0.902830, 0.524660, 0.730450, -0.081150, 0.575650, 

1.043700, 0.628340, -1.030970, -0.647290, 0.388670, 0.132780, -0.977190, -0.529550, 0.225060, 0.566500, 
0.583030, -0.579200, -0.094720, -0.341770, 0.584040, 0.059280, -0.137090, 0.821960, 0.162000, 0.961700, 
-0.220710, -0.803760, 0.859620, 0.875960, 0.408690, 0.360210, -0.946400, 0.734620, -0.857040, 0.128790, 

-0.539220, 0.101920, 0.101480, -0.409980, 0.618160, 0.746590, 0.444490, -0.334270, 0.724990, 0.350630, 
-0.618850, 0.966600, -0.876700, 0.242890, -0.168540, 0.476150, 0.171110, -0.394560, -0.578540, 0.640080, 
0.727260, 0.673550, 0.414480, -0.715190, 0.407430, -0.392880, -0.721420, -0.654760, 0.913110, 0.849720, 

-0.482020, 0.688840, 0.151300, 0.779090, -0.518910, -0.263320, -0.492160, -0.096650, 0.800240, -0.475740, 
-0.077060, -0.055580, 0.424750, -0.887980, 0.154390, 0.013080, -0.402730, 0.499410, -0.651930, -0.770800, 
0.988680, 0.791570, 0.453500, -0.967970, 0.227840, -0.636730, -0.736930, 0.428500, -0.980510, 0.989140, 

-0.903180, -0.357280, 0.309910, -0.511380, -0.861130, -0.316560, -0.896020, -0.113640, -0.953350, 0.515130, 
0.189160, -0.190630, -0.584240, 0.571740, -0.830030, 0.734740, -0.866640, -0.502060, -0.085520, -0.121960, 
0.952300, 0.203370, 0.244670, -0.457100, -0.144100, -0.375790, -0.228230, 0.433940, 0.796730, 0.374610, 

-0.689690, 0.125580, -1.167520, 0.370750, -0.089970, -0.303800, 0.496790, -0.962360, -0.006390, 0.607900, 
-0.064020, 0.506910, 0.426180, 0.239670, 0.598280, -0.270150, 0.543240, -0.886180, -0.582190, 0.539020, 
-0.049010, -0.777320, 0.117630, 0.761960, -1.059070, -0.400800, 0.467540, -0.573170, -0.421560, 0.530410, 

0.418550, 0.454350, -0.147180, -0.812060, -0.904900, -0.641890, -0.468350, -1.021730, -0.399780, -0.277390, 
0.743800, -0.301910, 0.728720, 0.303170, 0.056100, 0.166500, -0.028750, -0.758770, -0.445660, -0.120000, 
-0.334660, 0.727300, -0.694650, -0.402500, 0.685920, 0.922520, 0.221530, -0.788640, 0.348030, 0.280420, 

0.977230, -0.742870, 0.603790, -0.942320, -0.438770, 0.161160, -0.598320, -0.003400, 0.337850, 0.679440, 
-0.433650, 0.082120, 0.305450, -0.204130, -0.850480, 0.732370, -0.506510, 0.952170, -0.238010, -0.315890, 
0.982000, -0.904360, 0.327470, -0.689190, -0.237570, 0.967850, -0.702730, -0.007870, 0.566660, -0.308360, 

0.925280, -0.518140, -0.254540, -0.834210, 0.300940, 0.613440, 0.396330, -0.061810, -0.748840, -0.911960, 
0.993120, 0.165690, -0.525170, -0.274930, -0.688040, -0.575860, -0.121760, -0.188830, -0.164490, -0.141030, 
0.434530, -0.486350, 0.161340, -0.602720, 0.998890, 0.670230, -0.074980, -0.933780, -0.809860, 0.852730, 

0.436940, -0.639980, 0.812140, 0.182180, 0.678500, 0.229950, 0.648510, 0.300790, 0.039590, -0.310290, 
0.815020, -0.306090, -0.500080, -0.756570, -0.766340, 0.816450, -0.750060, 0.311370, 0.804980, -0.545250, 
-0.026700, 0.778910, 0.841650, -0.107480, 0.870900, -0.601810, 0.672440, 0.236630, 0.948580, -0.612470, 

0.679730, -0.226290, -0.104310, -0.780500, 0.030260, 0.318920, 0.793030, 0.862410, 0.045570, 0.730340, 
-0.348990, -0.390330, 1.004730, 0.433300, 0.420250, -0.563690, -0.949010, 0.692860, 0.316060, 0.067970, 
0.302480, -0.788050, 0.216330, 0.654520, -0.162460, -0.845320, 0.377950, -0.001850, 0.544280, 0.128550, 

-0.242770, -0.896450, -0.686920, 0.280080, -0.012870, -0.267430, 0.164400, -0.258530, -0.421410, 0.554060, 
-0.793070, 0.562510, 0.262740, -0.147460, 0.549370, 0.452280, 0.956500, 0.121800, -0.084450, -0.315350, 
0.506150, 0.046900, 0.878740, 0.588510, 0.473650, 0.511540, -0.620960, -0.572370, 0.500750, -0.444530, 

-0.521280, -0.371750, 0.019060, -0.691710, 0.790470, -0.583440, -0.734660, -0.594930, -0.599140, -0.041670, 
0.546250, -0.769620, -0.253100, -0.966910, -0.953390, 0.445830, 0.088930, 0.106760, -0.963390, -0.061350, 
-0.552940, -0.394080, 0.124350, 0.136160, 0.964650, 0.611770, -0.183270, 0.773140, 0.938400, -0.162040, 

-0.747740, -0.092630, 0.262650, -0.656320, 0.296500, -0.190810, -0.376550, 0.848080, -0.228560, -0.411780, 
-0.653710, -0.842270, -0.825960, 0.598990, 0.769960, -0.086670, -0.462330, -0.927700, 0.019860, 0.204060, 
-0.493990, -0.958650, 0.850670, 0.992060, -0.210600, -1.016860, -0.197240, -0.443160, 0.804940, -0.235560, 

0.153060, 0.142500, -0.571090, 0.468730, 0.331240, 0.239540, 0.169670, 0.198080, 0.496290, 0.758280, 
-0.911760, -0.664740, -0.791270, 0.101930, -0.304710, 0.532250, -0.122400, -0.887640, -0.846120, -0.842860, 
-0.779510, 0.300770, 0.700130, 0.522580, 0.988500, -0.186000, -0.473300, -0.139680, -0.244440, -0.377530, 

0.541310, 0.106210, -0.086530, -0.288180, 0.156280, -0.491390, -1.015390, 0.251560, 0.933310, -0.395960, 
-0.160410, -1.064780, -0.049330, 0.502230, -0.702490, -0.056580, 0.919130, -0.264130, -0.106570, 0.045490, 
-0.125420, 0.125020, -0.263000, -0.156280, 0.533260, -0.512010, 0.692730, -0.656090, 0.753140, 0.466280, 

0.229900, 0.180140, -0.898730, -0.323770, -0.845720, 0.629140, 1.005820, -0.220180, 0.445720, -0.355410, 
0.136010, 0.539650, 0.933600, 0.844910, 0.650260, 0.465330, -0.774800, -0.219140, -0.441840, -0.510870, 
-0.271090, -0.061090, -0.861860, -0.723150, -0.784070, -0.774140, 0.346480, -0.169430, -0.855550, -0.476400, 

0.454080, -0.108110, -0.122090, -0.580870, -0.307640, 0.644530, -0.253230, -0.067900, 0.505710, 0.513640, 
-0.571080, 0.727600, -0.269010, 0.550990, -0.012870, 0.641380, 0.442110, -0.364080, -0.394270, -0.602930, 
-0.744140, 0.718670, -0.876660, 0.347590, -0.636320, -0.622570, -0.404430, 0.764130, -0.351750, -0.188920, 

0.082060, -0.806190, -0.306410, -0.950490, -0.987620, 0.180960, 0.966720, -0.915630, -0.421170, -0.501560, 
0.347650, -0.296230, -0.479740, 0.646670, 0.005600, -0.459580, 0.521820, 1.002560, -0.134330, 0.093230, 
0.834140, -0.218930, 0.791080, 0.583130, 0.025470, -0.737060, 0.114830, 0.474600, 0.565730, -0.089110, 

0.876360, 0.611630, -0.921170, 0.381220, 0.518790, -0.422040, -0.095140, -0.509930, 0.749720, 0.890780, 
-0.307700, 0.650740, 0.024680, -0.739620, 0.921160, 0.691220, -0.048970, 0.393240, -0.119410, 0.577820, 
0.936840, 0.487860, -0.142420, 0.519980, 0.757330, 0.330730, 0.689510, 0.558700, -0.202240, 0.023160, 

0.310590, 0.913430, 1.113580, -0.496340, 0.113280, -0.294370, 0.493150, -0.280710, -0.141570, -0.502170, 
0.514650, -0.451390, 0.087190, -0.691880, 0.483550, 0.383640, -0.445870, -0.084410, 0.609060, -0.273600, 
-0.239760, 0.537640, 0.958900, -0.632290, 0.493580, 0.235420, 0.433740, -0.747790, -0.860280, -0.531490, 

0.449850, -0.800110, -0.846700, 0.586320, 0.708390, -0.837890, 0.083700, 0.191010, 0.005600, 0.527860, 
-0.956340, -0.523860, 0.270600, 0.715910, -0.895640, -0.945710, 0.691840, 0.530040, -0.434020, 0.860680, 
0.844700, -0.048360, 0.350920, 0.137970, 0.575030, 0.465390, 0.002410, -0.034380, -0.635760, 0.818030, 

0.217230, 0.961210, -0.746230, -0.579530, -0.869820, 0.819570, -0.225610, 0.313970, 0.106720, -0.639760, 
0.889740, -0.453610, -0.776350, 0.826930, 0.303970, -0.496820, -0.332430, -0.439500, -0.352690, -0.359210, 
0.936900, -0.014440, -0.547110, 0.543220, 0.888570, 0.922420, 1.027590, -0.893290, -0.771790, 0.392390, 

0.628150, 0.554220, -0.527720, 1.039950, 0.992480, 0.286190, 0.327870, 0.549550, 0.082690, -0.883640, 
-0.578140, 0.740910, -0.910950, -0.795160, 0.417490, -0.127210, 0.148250, 0.254880, -0.755170, -0.072290, 
0.565220, -0.406660, 0.677700, 0.484840, 0.482440, -0.835910, 0.511120, 0.274860, 0.750750, 0.674470, 

-0.947220, 0.066540, 0.242810, 0.087980, 0.361210, -0.017650, -0.512450, -0.839540, -0.629290, 0.530050, 
-0.734690, 0.984580, -0.273730, 0.351430, 0.068510, 0.476530, 0.974200, -0.072580, -0.883380, -0.536910, 
0.336940, 0.887300, -0.585120, -0.397550, -0.021790, -0.719570, 0.171630, -0.552200, -0.410110, 0.102800, 

0.757990, -0.871790, -1.101730, -0.431310, 0.250030, -0.071970, 0.449070, -0.353030, -0.698880, -0.679490, 
0.565310, 0.116960, 0.330520, -0.319840, -0.417420, -0.706260, -0.364370, 0.444490, 0.449140, 0.254900, 
-0.417150, 0.651540, -0.329640, 0.339580, 0.786260, 0.362900, 0.656780, -0.798480, 0.353790, 0.544120, 

-0.905730, -1.018360, -0.388490, -0.703340, 0.660620, -0.229440, -0.468860, 0.916790, 0.768870, -0.505220, 
0.546270, 0.708330, 0.023170, 0.851620, -0.809890, 0.767560, -0.600170, -0.950280, -0.510260, 0.471240, 
-0.354210, 0.338250, 0.127860, 0.937270, 0.086100, -0.370230, 0.649410, 0.704600, 0.521420, -0.582760, 

-0.722610, 0.077290, 0.039900, -0.364070, 0.095730, -0.148320, -0.484930, -0.468560, -0.508360, 0.779180, 
0.292100, -0.634280, -0.372340, -0.251160, 0.328140, 0.328050, -0.768060, 0.476230, 0.091870, -0.317040, 
-0.623180, -0.313850, -0.127450, -0.137230, -0.775070, 0.960540, 0.471700, -0.825340, -0.288480, 0.252040, 

-0.978790, 0.843720, 0.226510, -0.714160, -0.152690, -0.220000, 0.837570, 0.988340, 0.604350, 0.647240, 
-0.406050, 0.548610, -0.579560, -0.339690, -0.602150, 0.408960, 0.861910, -0.428440, 0.712120, -0.926920, 
-0.582100, 0.822690, 0.325140, -0.410730, -0.422530, 0.529100, 1.114730, 0.437550, 0.898700, 0.282490, 

0.764450, 0.579420, 0.804500, -0.573350, 0.993980, 0.842300, -0.395110, -0.633640, -0.660880, 0.708700, 
-0.186320, 0.283080, -0.011420, 0.117680, -0.706200, -0.014120, -0.545730, -0.052700, 0.626960, 0.755450, 
0.229800, -0.489490, -0.343740, -0.879880, 0.668350, 0.151980, -0.825270, -0.158760, -0.756540, 0.966660, 

0.021580, 0.474840, -0.049420, -0.105450, 0.757670, 0.775810, -0.340910, 0.235760, 0.173910, 0.222200, 
0.184370, -0.427610, 0.285040, -0.878590, -0.858880, 0.375740, -0.076540, 0.943830, 0.624830, 0.831120, 
-0.373180, 0.521950, 0.709190, -0.703020, -0.936540, 0.678190, -0.330200, -0.533190, 0.608540, -0.330330, 

0.645130, 0.542120, 0.807470, 0.942260, 0.641350, 0.803990, -0.535830, 0.381990, -0.933630, 0.031540, 
0.819300, 0.288210, -0.949440, 0.547840, 0.563180, 0.121030, 0.816890, 0.062620, 0.005250, -0.411910, 
-0.196190, -0.397300, -0.592830, 0.700170, -0.172370, -0.147940, -0.619430, -0.055130, 0.637890, 0.703920, 

0.945320, 0.147590, 0.908960, -0.719370, 0.659820, -0.507100, 0.670810, 0.674180, 0.032420, -0.796590, 
0.218230, 0.721010, -0.396830, 0.864100, 0.475070, 0.551720, -0.255930, -0.187280, -0.596500, -0.774370, 
-0.386420, -0.756970, -0.014280, -0.803000, -0.518210, -0.733930, 0.871560, -0.161610, 0.527830, 0.035110, 

-0.657980, -0.666560, 0.117430, -0.913930, -0.202820, -0.844630, -0.322440, 0.827450, 0.700630, 0.983040, 
0.218620, 0.414210, -0.866900, 0.281890, 0.791280, -0.458340, 0.156490, -0.820270, -0.403280, 0.522950, 
0.779200, 0.693290, 0.624510, -0.391650, 0.627860, -0.355700, -0.144410, -0.456730, -0.581910, 0.765250, 

0.331130, 0.453950, 0.061910, 0.752490, 0.761040, 0.152540, 0.516900, 0.966480, -0.860060, 0.827550, 
0.856900, 0.328390, 0.790880, -0.674970, -0.049690, 0.620720, -0.428070, -0.883520, 0.892570, 0.774020, 
0.384970, -0.717720, -0.034240, 0.384730, 0.781040, -0.791040, 0.172750, -0.920240, -0.483020, 0.001970, 

-0.394740, -0.218820, 0.604300, 0.560970, 0.412480, -0.950420, -0.538120, -0.201520, -0.885180, 0.656060, 
0.128800, 0.404040, -0.379580, 0.219960, -0.325660, -0.763340, -0.718470, 0.175600, -0.734070, 0.273800, 
-0.492550, -0.566730, -0.414300, -0.990430, -0.662330, -0.655660, -0.865820, -0.238610, 0.170020, -0.099000, 

0.344680, -0.752030, 0.144660, -0.847940, 0.336980, 0.649260, -0.087110, 0.555510, 0.689260, -0.045070, 
-0.243010, -0.425410, -0.943550, -0.255030, 0.611020, 0.606480, -0.653030, -0.103620, -0.825930, -0.513710, 
0.305860, 0.735490, 0.183820, -0.903130, -0.741200, 0.963480, 0.028740, -0.320220, -0.830660, -0.639620, 

0.739830, 0.929700, -0.966610, 0.323390, -0.320410, 0.981770, 0.753330, 0.179510, -0.569560, 0.025360, 
0.822100, -0.013950, -0.671910, 0.871910, 0.153680, 0.772330, 0.881110, 0.902050, 0.302470, -0.080530, 
-0.145740, 0.581080, -0.593730, -0.222210, 0.783270, 0.139750, 0.545140, -0.083890, -0.543950, -0.774390, 

-0.429280, 0.963540, -0.847160, 0.392210, -0.895900, -0.090480, 0.302140, -0.967920, -0.273450, 0.195400, 
-0.426380, -0.580990, -0.667400, 0.267290, -0.484920, 0.465900, -0.824540, 0.707460, -0.837790, -0.005560, 
-0.842480, -1.013020, 0.642300, -0.684180, 0.296950, -0.875150, -0.527910, 0.272460, 0.881910, 0.771180, 

0.092710, -0.632880, -0.937780, -0.640420, 0.003270, -0.515310, 0.131100, 0.651110, 0.677800, 0.316010, 
0.973880, 0.582680, -0.904860, -0.176580, 0.901680, 0.058900, 0.300420, 0.086530, 0.369880, 0.226750, 
0.836120, 0.512650, 0.984240, 0.706740, 0.199510, 0.688250, 0.389650, 0.714580, 0.033830, 0.811800, 

-0.717520, 0.478610, 0.634030, -0.700050, 0.418040, 0.260790, 0.019600, 0.607560, -0.389340, 0.525620, 
0.321970, -0.766720, -0.360540, 0.292010, -0.721630, -0.568850, -0.213950, 0.391250, -0.004600, 0.869660, 
-0.164810, -0.543190, 0.416810, -0.591440, 0.022980, -0.555150, -1.039630, 0.223420, 0.061170, -0.473210, 
-0.662010, -0.747880, -0.745740, 0.721470, 0.645870, 0.506520, 0.342390, 0.844890, -0.523030, -0.248340, 
0.068240, 0.355100, -0.237650, 0.398660, 0.996600, 0.050900, -0.743300, 0.113450, -0.482050, -0.724040, 

-0.203420, -0.961160, -0.460020, -0.989050, -0.933620, 1.047670, -0.451440, -0.210510, -0.897180, 1.011900, 
0.202680, -0.260570, 0.597040, -0.940700, 0.639980, 0.334680, 0.138240, -0.582850, 0.405270, -0.439540, 
-0.992760, -0.541680, -0.536590, 0.144260, 0.936240, 0.218000, -0.315740, -0.582070, 0.375600, 0.463720, 
-0.154340, -0.308260, -0.733120, 0.482610, 0.318010, 0.253590, 0.323420, 0.459970, 0.269330, -0.103780, 
-0.754390, 0.155280, -0.348860, -0.731200, -0.531150, -0.152510, 0.397530, 0.782070, 0.640440, -0.892810, 

0.299880, -0.888550, -0.085670, -0.627060, -0.213500, -0.136570, -0.915350, 0.798890, -0.418350, 0.711460, 
0.627850, 0.813400, 0.429050, -0.731420, -0.636900, 0.757250, 0.438920, -0.110520, -0.768050, 0.822760, 
-0.734960, -0.015370, 0.847070, -0.346540, -0.619160, -0.302780, 0.872350, 0.944860, -0.982050, 0.533770, 
-1.034610, -0.467950, -0.287860, 0.351080, 0.081150, -0.097300, 0.676120, 0.510400, -0.983670, 0.790000, 
0.310680, 0.568590, 0.264400, 0.467650, -0.232700, 0.647300, -0.474480, -0.184590, 0.356440, -0.170020, 

-0.969130, -0.858960, -0.137280, 0.247530, 0.447960, -0.407130, -0.130170, -0.776590, -0.802560, 0.007910, 
-0.613820, -0.668700, 0.827390, -0.182760, 0.397720, -0.962450, -0.456940, -0.128940, -0.225350, -0.303320, 
-0.223280, -0.152530, -0.605370, -0.215390, -0.759230, 0.055780, -0.717340, -0.212660, 0.213010, -0.298070, 
0.784070, 0.214450, 0.958880, -0.289980, 0.713190, -0.560910, -0.235780, -0.333900, 0.497320, 0.014130, 
0.561720, 0.892500, -0.234050, -0.308240, 0.406740, 0.933910, 0.321700, 0.344330, 0.808810, -0.831600, 

0.032880, -0.287110, 0.383760, -0.001330, 0.124580, 0.174970, -0.711390, 0.834790, -0.748380, 0.360130, 
0.621920, -0.663720, 0.920530, -0.840690, -0.516930, 0.487390, -0.294980, 0.934340, 0.143710, 0.958300, 
-0.963760, 0.799450, 0.656270, -0.638900, -0.310340, 0.102910, -0.617300, 0.301390, 0.582970, 0.626600, 
-0.839310, 0.319430, 0.278520, 0.250480, -0.075110, 0.565150, -0.564370, 0.742160, 0.778770, 0.702560, 
-0.357770, 0.306060, 0.887080, 0.714340, 0.105240, -0.421840, 0.176500, 0.235930, -0.000810, -0.950860, 

-0.342720, 0.767740, 0.056150, 0.013080, 0.112360, -0.734720, -0.457730, 0.100520, -0.635490, -0.352120, 
0.929710, -0.033410, 0.240740, -0.008140, 0.088610, 0.763100, -0.532700, 0.921330, 0.584620, -0.858210, 
0.706960, -0.356420, -0.445090, 0.703230, 0.826300, 0.917600, -0.625500, 0.516630, -0.354130, -0.380430, 
-0.503040, -0.298210, -0.482900, -0.050410, -0.687950, 0.534890, -0.589590, -0.574080, -1.095020, 0.819290, 
0.083210, -0.582410, 0.300110, 0.774180, -0.965200, -0.437170, 0.700310, -0.566650, -0.078550, 0.708620, 

0.198090, 0.884040, 1.020270, 0.071560, -0.610040, 0.211240, -0.243300, 0.228700, 0.200790, 0.036410, 
-1.030270, -1.052840, -0.059180, 0.948260, -0.397480, -0.284170, 0.905220, 0.357700, -0.227410, -0.540730, 
0.794730, 0.857790, -0.405190, 0.922920, 0.294910, -0.129670, -0.855370, -0.123200, -0.184720, 0.138730, 
0.363830, 0.755210, 0.395340, 0.668660, -0.103890, -1.004990, 0.429060, 0.316300, 0.631070, -0.041060, 
0.791770, -0.361470, -0.774170, 0.247020, -0.832550, 0.305910, -0.860490, -0.899910, -0.604400, -0.092240, 

0.586120, 0.196980, -0.304320, -0.372400, -0.902790, 0.858070, -0.031150, 0.150020, 0.584930, -0.357380, 
-0.108270, -0.855130, 0.222390, -0.449760, -0.380720, -0.885800, 0.513530, 0.734370, 0.009790, -0.623940, 
-0.926000, 0.532130, -0.323980, -0.316050, -0.277720, -0.938770, 0.230860, 0.528940, 0.377460, 0.282810, 
-0.030250, 0.848660, 0.861520, 0.677170, 0.429100, 0.351940, -0.376820, -0.167070, -0.225720, -0.529320, 
0.383180, -0.754970, -0.878000, -0.057470, 0.603680, 0.876560, -1.003430, 0.865750, 0.397930, 0.642670, 

-0.121720, -0.437420, 0.408040, 0.906140, -0.853810, -0.311060, -0.278890, 0.086810, 0.222000, -0.408790, 
-0.496230, 0.955550, -0.172490, -0.831750, 0.056190, 0.183470, -0.005320, 0.725450, 0.648100, 0.877180, 
-0.877860, -0.116490, 0.965820, -0.759460, 0.223460, -0.167010, 0.374680, -0.868240, -0.102020, 0.695250, 
0.631090, 0.038740, 0.845400, 0.192460, -0.676090, -0.746230, -0.189560, -0.105930, 0.930440, -0.942060, 
0.640160, -0.348890, 0.803320, -0.638050, -0.889700, 0.964320, 0.454750, -0.883590, 0.400590, -0.838420, 

0.883880, -0.775860, -0.354660, 0.592040, -0.265060, -0.870110, 0.768650, 0.201340, -0.346970, 0.191220, 
0.672100, 0.446210, 0.928490, -0.891020, 0.876430, -0.550800, -0.281310, -0.514680, 0.419800, 0.363560, 
0.476440, -0.013750, -0.973010, 0.622770, -0.689040, 0.843220, 0.165970, 0.948880, -0.424970, -0.995390, 
0.753630, -0.577020, 0.276110, 0.774800, 0.143610, 0.323870, 0.562790, -0.145380, 0.666330, -0.305440, 
-0.431460, -0.541490, 0.189780, 0.878080, -0.547260, 0.185150, -0.236960, 0.976130, -0.206860, 0.781270, 

-0.946920, -0.732310, 0.156750, -0.110090, 0.523560, -0.681790, -0.019960, -0.470780, 0.085160, -0.414860, 
-0.636230, -0.431060, -0.990530, -0.592080, 0.853430, -0.780270, -0.909520, -0.373670, -0.969380, -0.871490, 
0.784450, -0.693060, -0.499180, 0.415570, 0.881860, 0.555310, 0.636160, -0.686560, -0.832150, 0.272690, 
0.146510, 0.645660, 0.400020, 0.110510, -0.764370, 0.263700, -0.157450, 0.961510, -0.191770, -0.772650, 
-0.536330, -0.173360, -0.581240, -0.451940, -0.405450, 0.112230, -0.413230, 0.311610, -0.293250, 0.355860, 

-0.658270, -0.553600, 0.623150, -0.109140, 0.776060, -0.734830, -0.205970, -0.163730, 0.318280, 0.673420, 
0.526790, 0.141700, -0.925150, -0.900800, -0.485680, -0.145060, 0.446340, 0.823780, 0.239890, -0.419270, 
0.211610, -0.890670, 0.522360, 0.251010, -0.518220, -0.915740, 0.796690, -1.005580, 0.357810, -0.443500, 
0.779330, -0.878920, 0.277070, 0.881450, 0.419110, 0.141160, -0.876820, -0.393250, -0.854020, -0.489280, 
0.262550, 0.176130, 0.363580, -0.514900, -0.499510, -0.623240, -0.314980, 0.686940, -0.988670, 0.551460, 

0.008320, -0.792900, -0.271690, -0.109360, 0.313050, -0.104760, 0.263340, 0.629230, 0.278190, -0.249650, 
0.109720, -0.678550, -0.592100, -0.652410, -1.004310, 0.813420, 0.546500, -0.840740, -0.099350, 0.746750, 
0.559730, -0.000540, 0.434020, 0.787390, -0.069150, -0.502490, -0.442570, 0.939290, -0.157890, -0.402680, 
-0.695880, 0.869790, 0.689880, -0.757580, -0.304800, -0.591170, -0.992870, -0.207780, 0.875170, -0.757500, 
0.475770, -0.628770, 0.179960, 0.034870, 0.511140, 0.078430, 0.401890, -0.943190, 0.057190, 0.180840, 

0.468490, 0.722010, 0.918620, 0.306350, -0.117210, -0.251150, 0.443570, -0.413430, 0.104790, 0.509100, 
0.997480, -0.311960, 0.862160, -0.714360, -0.104000, -0.946380, -0.348960, 0.527180, -0.839860, -0.349620, 
-0.904930, -0.309600, 0.600350, -0.326990, -0.213310, 0.983810, 0.977790, -0.790430, -0.788060, 0.477190, 
0.168290, -0.541150, 0.516250, -0.723860, -0.285240, 0.588050, 0.073340, -0.342500, 0.621190, 0.627800, 
0.482160, -0.509720, -0.686110, -0.501950, -0.731120, 0.772110, -0.628820, -0.162120, 0.490290, -0.213360, 

0.666340, -0.846380, -0.189770, -0.507570, 0.651860, 1.005230, 0.022470, 0.702320, -0.740910, -0.554970, 
-0.122450, -0.939390, -0.729550, 0.465010, 0.597340, 0.280430, -0.337450, -0.274880, 0.759350, -0.385120, 
0.270270, 0.814330, -0.609260, 0.744610, 0.429830, 0.182440, 0.244090, 0.149030, -0.427510, -0.515980, 
-0.776670, -0.516270, -1.071670, 0.759350, -0.332780, -0.918500, -0.042600, -0.478500, 0.314230, 0.286420, 
-0.314000, 0.785730, 0.618310, 0.327900, 0.380710, -0.478930, 0.814730, -0.826480, 0.860920, 0.424520, 

-0.900720, -0.286390, -0.428890, -0.020450, 0.271630, 0.611590, -0.043460, 0.579260, -0.927120, -0.313850, 
-0.024130, -0.337900, -0.083090, -0.987230, -0.742150, -0.044290, 0.706170, -0.544680, 0.525670, -0.480900, 
0.649950, 0.620280, 0.126260, -0.440020, -0.397300, -0.837630, 0.654020, -0.629760, 0.107720, -0.117610, 
-0.420300, 0.681540, 0.027850, -0.177710, -0.591120, -0.809670, 0.653840, 0.888360, 1.004330, 0.801930, 
-0.412690, -0.189770, 0.191370, 0.873840, -0.222290, 0.710480, -0.683970, 0.031580, 0.109180, -0.451290, 

-0.143140, 0.200260, 0.861040, -0.106770, -0.021170, -0.083530, 0.501600, 0.475310, -0.304510, -0.265650, 
-0.808340, 0.264610, -0.832070, -0.796060, -0.297310, 0.431940, 0.807370, -0.855750, -0.084140, -0.187440, 
0.668830, -0.214950, -0.618460, -0.461300, -0.625350, 0.424920, 0.789970, 0.623350, -1.027340, 0.533560, 
0.211330, -0.077100, 0.757440, -0.091610, -0.541670, -0.316800, 0.805390, 0.382450, -0.681850, -0.322750, 
-0.705300, 0.148450, -0.211450, 1.025630, 0.336130, -0.928020, 0.226980, 0.450130, 0.574250, 0.127230, 

-0.735660, -0.047150, -0.232150, -0.905980, 0.836470, -0.706160, -0.209510, -0.739890, 0.609190, 0.588290, 
-0.648510, -0.830540, -0.060610, -0.469390, 0.598750, 0.729810, -0.016760, -0.877870, -0.791670, 0.325570, 
-0.779730, 0.436140, 0.248140, 0.698040, -0.432310, 0.372530, -0.059300, 0.532220, -0.072770, -0.987650, 
-0.052650, 0.062160, 0.277650, -0.650270, 0.418680, 0.754980, -0.115210, -0.118990, 0.425760, -0.309690, 
0.687450, 0.185070, -0.984940, -0.392770, 0.608130, -0.415350, 0.859680, -0.918610, 0.110790, 0.234660, 

0.878430, -0.519930, -0.399510, -0.852910, -0.902420, 0.693730, -0.095770, -0.397690, 0.515740, -0.268760, 
-0.488070, 0.965440, 0.440650, 0.395010, 0.243150, 0.674100, 0.095050, -0.075180, 0.962670, 0.241760, 
0.147470, -0.197410, -0.412340, -0.098240, 0.493750, 0.916650, 1.072620, 0.378480, -0.235860, 0.520700, 
-0.849860, 0.722150, -0.258950, -0.135710, 0.585860, 0.134440, 1.036820, 0.221570, -0.993690, -0.248660, 
-0.180360, -0.863440, -0.475830, -0.643180, 0.484220, -0.531460, -0.826660, -0.765280, 0.492920, 0.062880, 

0.745860, -0.743180, 0.276720, -0.705070, -0.476500, 0.991820, 0.952360, 0.239600, -0.168200, -0.409010, 
-0.368010, 0.816680, 0.451840, 0.831380, 0.639820, -0.790830, 0.008480, -0.564580, -0.344920, -0.609470, 
0.064530, 0.759370, -0.471900, 0.787230, 0.789320, -0.971420, 0.778060, 0.828710, 0.099520, -0.415610, 
-0.031430, -0.605080, -0.412440, -0.775820, 0.642280, -0.973910, -0.077980, -0.344400, 0.629160, -0.580090, 
-0.255410, -0.750470, 0.147290, 0.485480, -0.316640, -0.015970, -0.069160, 0.152410, 0.045080, -0.742880, 

-0.660830, -0.838360, 0.588960, -0.745730, 0.344410, 1.006910, -0.813990, -0.127440, 0.126690, -0.598890, 
0.817380, -0.390670, 0.550000, 0.005850, -0.413020, -0.411560, -0.897800, 0.744090, 0.989570, -0.430120, 


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
      0.0, 0.057730, 30,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, 0.932270, 30,
       &Sources[30] , 
       &Weights[30] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.160390, 30,
       &Sources[60] , 
       &Weights[60] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.058860, 30,
       &Sources[90] , 
       &Weights[90] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, 0.391180, 30,
       &Sources[120] , 
       &Weights[120] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.655990, 30,
       &Sources[150] , 
       &Weights[150] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, 0.931010, 30,
       &Sources[180] , 
       &Weights[180] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, 0.802650, 30,
       &Sources[210] , 
       &Weights[210] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, 0.657930, 30,
       &Sources[240] , 
       &Weights[240] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, 0.203110, 30,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.529810, 30,
       &Sources[300] , 
       &Weights[300] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.565130, 30,
       &Sources[330] , 
       &Weights[330] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, 0.839350, 30,
       &Sources[360] , 
       &Weights[360] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.144700, 30,
       &Sources[390] , 
       &Weights[390] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, 0.844510, 30,
       &Sources[420] , 
       &Weights[420] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.157490, 30,
       &Sources[450] , 
       &Weights[450] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.594930, 30,
       &Sources[480] , 
       &Weights[480] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.042320, 30,
       &Sources[510] , 
       &Weights[510] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.555280, 30,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.563170, 30,
       &Sources[570] , 
       &Weights[570] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.266960, 30,
       &Sources[600] , 
       &Weights[600] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.450860, 30,
       &Sources[630] , 
       &Weights[630] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.077810, 30,
       &Sources[660] , 
       &Weights[660] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, 0.319890, 30,
       &Sources[690] , 
       &Weights[690] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.339850, 30,
       &Sources[720] , 
       &Weights[720] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, 0.074950, 30,
       &Sources[750] , 
       &Weights[750] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.206750, 30,
       &Sources[780] , 
       &Weights[780] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.862280, 30,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.863080, 30,
       &Sources[840] , 
       &Weights[840] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.236650, 30,
       &Sources[870] , 
       &Weights[870] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.580850, 30,
       &Sources[900] , 
       &Weights[900] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.293900, 30,
       &Sources[930] , 
       &Weights[930] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.523370, 30,
       &Sources[960] , 
       &Weights[960] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, 0.694570, 30,
       &Sources[990] , 
       &Weights[990] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.933280, 30,
       &Sources[1020] , 
       &Weights[1020] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, 0.665810, 30,
       &Sources[1050] , 
       &Weights[1050] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.628430, 30,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, 0.462500, 30,
       &Sources[1110] , 
       &Weights[1110] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.759960, 30,
       &Sources[1140] , 
       &Weights[1140] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, 0.297620, 30,
       &Sources[1170] , 
       &Weights[1170] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.182800, 30,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.734170, 30,
       &Sources[1230] , 
       &Weights[1230] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.090400, 30,
       &Sources[1260] , 
       &Weights[1260] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.341190, 30,
       &Sources[1290] , 
       &Weights[1290] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, 0.832770, 30,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.437430, 30,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.634850, 30,
       &Sources[1380] , 
       &Weights[1380] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.871090, 30,
       &Sources[1410] , 
       &Weights[1410] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, -0.042940, 30,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.100970, 30,
       &Sources[1470] , 
       &Weights[1470] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.243130, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.378520, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.833710, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 1.032610, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.735170, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.248570, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.062510, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.469680, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, -0.496680, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, -0.387690, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, -0.229970, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, -0.534530, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, -0.804660, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, -0.693300, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.895010, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, 0.001140, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.894450, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, -1.138700, 50,
       &Sources[2350] , 
       &Weights[2350] , 
      },
    { /* unit 99 (Old: 99) */
      0.0, 0.723850, 50,
       &Sources[2400] , 
       &Weights[2400] , 
      },
    { /* unit 100 (Old: 100) */
      0.0, 0.893090, 50,
       &Sources[2450] , 
       &Weights[2450] , 
      },
    { /* unit 101 (Old: 101) */
      0.0, 0.429050, 20,
       &Sources[2500] , 
       &Weights[2500] , 
      }

  };



int oy(float *in, float *out, int init)
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
