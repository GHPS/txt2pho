/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  r.c
  --------------------------------------------------------
  generated at Tue Jun 23 15:43:37 1998
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
  static UnitType Units[89];
  /* Sources definition section */
  static pUnit Sources[] =  {
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, 
Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, 
Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 

Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 
Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, 


  };

  /* Weigths definition section */
  static float Weights[] =  {
1.110670, -0.868680, 0.223720, -0.873870, 0.394340, -0.294430, 0.049680, -0.046340, -0.172120, -0.468560, 
-0.099620, 0.193050, 0.374070, 0.722530, 0.369610, -0.785130, 0.665420, -0.234060, -0.280930, 0.398950, 
-0.869530, 0.578050, -0.515910, 0.013530, 0.147390, 1.070100, -0.630720, 
-0.795240, 0.176150, -0.533210, -0.072000, -0.522110, -0.245600, 0.506320, 0.359910, 0.499540, 0.177900, 
-0.773360, -0.845350, 0.040200, -0.349830, -0.667690, 0.505420, -0.607810, 0.053200, -0.706410, 0.413050, 
0.347020, 0.724190, -0.694700, 0.593820, -0.311850, 0.830860, 0.420520, 
0.049310, -0.600960, -0.873280, -0.930260, 0.340990, 0.513740, -0.656810, 0.986160, -0.721490, 0.982920, 
-0.020120, -0.742170, 0.567870, 0.038300, 0.781050, 0.175340, -0.519730, -0.365560, 0.196410, -0.520160, 
-0.747260, -0.820630, 0.871170, -0.018640, 0.169750, -0.832580, 0.647550, 
0.651930, 0.105910, 0.960140, -0.522580, 0.926020, -0.212740, 0.641860, 0.630980, 0.301720, -0.814880, 
0.525960, 0.569320, 0.038030, 0.235370, 0.860280, 0.037810, 0.556090, -0.389790, 0.183650, 0.519080, 
0.913170, 0.983710, 0.660690, 0.541860, 0.379430, 0.412040, -0.137320, 
-0.506720, 0.830940, -0.657510, 0.971420, -0.333830, 0.272910, 0.752710, -0.196440, 0.239890, 0.882470, 
-0.401700, -0.881700, 0.460160, -0.150190, -0.380480, -0.256710, -0.499550, -0.661910, -0.385140, -0.784600, 
0.201610, 0.021070, -0.844650, -0.378430, -0.741300, 0.020100, -0.816940, 
-0.498650, 0.254580, -0.754450, -0.760760, -0.247180, 0.307010, -1.035370, 0.709110, -0.267750, -0.704630, 
-0.510020, -0.429010, 0.385440, -0.794540, 0.255530, -0.265730, 0.519950, 0.674740, -0.926200, 0.451830, 
0.543050, 0.552210, -0.455140, 0.383990, 0.344460, 0.240220, -0.856880, 
-0.727850, 0.953200, 0.641200, 0.415880, 0.466510, 0.088770, 0.975220, 0.094420, -0.705260, -0.234860, 
-0.240010, 0.433020, -0.076820, 0.244490, 0.945570, -0.198400, 0.843840, -0.953230, 0.806960, -0.923490, 
-0.826450, 0.249040, -0.425370, 0.306110, -0.747960, -0.137600, -0.695220, 
-0.971900, -0.844400, 0.499830, 0.825730, 0.097280, -0.598840, 0.374820, -0.114490, 0.203170, 0.422150, 
0.931010, -0.730220, 0.208750, 0.474540, -0.026120, 0.244610, 0.294130, 0.484890, 0.506600, -0.629370, 
-0.654080, -0.456030, -0.845090, 0.574300, 0.729680, -0.479440, 0.815310, 
0.695140, -0.613330, -0.488450, -0.966810, 0.931090, -0.046590, 0.421790, 0.307490, -0.090410, 0.894470, 
-0.351940, 0.906260, 0.065940, 0.311700, 0.554230, 0.627590, 0.164000, 0.269090, -0.945750, -0.136380, 
0.151550, -0.768240, 0.063820, -0.546420, 0.247840, 0.521840, -0.809020, 
-0.077120, 0.738690, 0.884370, -0.577110, 0.082970, -0.668940, -0.271120, -0.951680, 0.192890, 0.312550, 
0.805260, -0.478420, -0.700130, 0.377700, 0.347960, -0.825920, 0.192270, -0.173580, 0.911980, -0.216420, 
0.938480, -0.078210, 0.022090, -0.912760, -0.220370, -0.673550, -0.468810, 
0.411590, -0.547990, -0.858320, 0.256920, 0.812510, -0.538130, -0.515250, -0.405240, 0.543790, -0.418830, 
-0.050930, 0.947280, 0.147490, 0.308660, 0.033280, 0.189710, -0.491240, -0.639990, 0.704240, -0.540470, 
-0.153410, 0.826590, 0.488560, -0.720970, 0.141160, 0.179040, -0.763090, 
-0.440160, -0.145110, -0.702780, 0.045980, 0.170100, 0.342690, 0.578780, -0.879940, 0.345310, 0.139390, 
-0.819650, 0.130080, -0.735710, 0.432300, 0.100780, -0.454970, -0.652880, 0.608470, -0.105640, 0.582980, 
0.199290, 0.663450, -0.473920, 0.977320, -0.252120, 0.873400, 0.120670, 
0.404550, 0.781160, -0.139600, 0.064940, 0.628330, -0.342040, 0.014220, -0.501510, 0.569750, 0.647530, 
0.231480, -0.573280, -0.989530, 0.148190, 0.357640, -0.553590, -0.788880, 0.589850, 0.852770, 0.579920, 
0.594670, -0.047320, 0.720710, 0.568700, 0.919020, -0.225810, 0.625040, 
0.478570, -0.160290, 0.236200, -0.853840, 0.936900, -0.659420, 0.346830, 0.726330, -0.315450, 0.492130, 
0.771490, 0.612220, -0.394100, 0.154260, 0.111630, -0.587720, 0.847270, 0.141280, -0.906900, 0.730630, 
-0.780650, 0.383510, 0.480670, 0.865830, 0.863130, -0.771480, -0.130690, 
0.325630, -0.074980, -0.036110, -0.462430, 0.810310, -0.101730, -0.402270, -0.307510, -0.520940, 0.796400, 
0.115740, 0.701470, -0.522650, 0.115290, 0.829750, 0.893610, -0.665740, -0.705900, -0.374450, 0.451220, 
-0.751270, 0.410360, 0.712370, 0.673320, 0.577040, -0.640830, -0.401050, 
0.576590, -0.947000, -0.073890, -0.825020, -0.249230, -0.824600, -0.463340, 0.384230, -0.364400, -0.926310, 
0.919950, 0.996670, -1.004330, 0.435530, -0.693590, -0.602930, 0.290810, -0.963450, 0.457730, 0.768520, 
1.002380, -0.723810, -0.617080, 0.526620, -0.382470, 0.059260, 0.169040, 
0.632620, -0.240250, -0.009230, 0.568290, -0.872030, 0.183820, -0.762400, -0.038520, 0.413360, 0.799930, 
0.405560, -0.157560, -0.355810, -0.068740, -0.454930, 0.306090, 0.211790, 0.993860, -0.088230, 0.029030, 
-0.538310, -0.878530, 0.748460, -0.745480, 0.607460, -0.555600, -0.151150, 
-0.950720, -0.336800, 0.463280, 0.537450, -0.527790, 0.568800, -0.443940, -0.606950, 0.688790, -0.325740, 
-0.796580, 0.742700, 0.119390, -0.709590, 0.022130, 0.516750, -0.215740, -0.931590, 0.539900, -0.228340, 
0.713950, 0.399730, 0.526220, 0.542440, -0.116430, 0.634020, -0.021990, 
0.933360, -0.075400, 0.323150, 0.400680, -0.622560, 0.139260, 0.893180, 0.587610, -0.391510, -0.670840, 
0.742850, -0.381430, -0.135670, -0.645680, -0.699280, -0.006820, 0.188750, 0.078550, 0.332480, 0.709410, 
-0.371870, 0.810830, -0.270030, -0.387440, -0.987830, -0.600940, -0.601880, 
0.531730, -0.019650, -0.705190, 0.962710, -0.250940, -0.694320, 0.303420, -0.931170, 0.972080, -0.332840, 
-0.196400, 0.901800, -0.515650, 0.721130, -0.874750, -0.236310, 0.295010, 0.114330, -0.461050, 0.679390, 
0.329250, -0.034160, -0.641600, 0.100650, -0.440000, -0.919570, 0.643010, 
0.630790, 0.984800, -0.606970, 0.131490, -0.416960, 0.414480, -0.203990, -0.212760, -0.190750, -0.118990, 
-0.601020, -0.737660, -0.368410, -0.551990, 0.192900, 0.930060, -0.917760, -0.777600, -0.099210, 0.343390, 
0.540390, 0.295850, -0.840050, -0.292220, -0.586000, 0.862590, -0.618340, 
0.818800, 0.753160, -0.043390, -0.575220, 1.016450, 0.157120, -0.749860, 0.735130, -0.790300, -0.771520, 
-0.468360, -0.272870, 0.715560, -0.307580, 0.013360, 0.324740, 0.733980, 0.171010, 0.671960, 0.236850, 
0.903220, -0.638540, 0.325660, -0.640140, 0.806320, -0.884490, -0.943780, 
-0.066960, 0.283690, 0.751330, -0.973850, -0.530450, 0.394590, 0.256910, 0.886000, -0.442570, -0.401150, 
0.383620, 0.067880, 0.678680, 0.733640, 0.434970, 0.005520, -0.913300, -0.108440, -0.118500, 0.673280, 
-0.391900, -0.813040, 0.912180, 0.074030, 0.535980, -0.566820, 0.780960, 
0.971060, 0.465530, 0.531800, -0.157750, 0.277020, 0.468240, -0.823880, 0.442650, -0.440450, -0.236630, 
0.168320, -0.240690, -0.028640, 0.199440, -0.812730, -0.888310, -0.109210, -0.436790, 0.155860, 0.526340, 
-0.013910, 0.382250, -0.945090, -0.177820, 0.669750, 0.246630, -0.797550, 
-0.976910, -0.252660, -0.771120, 0.543730, -0.031340, -0.610720, -0.590610, -0.726680, -0.577200, 0.802190, 
-0.637210, 0.052840, -0.356980, -0.552270, -0.130320, -0.456850, 0.588020, -0.526300, -0.714950, 0.500790, 
0.487810, 0.634800, 0.882010, 0.044620, 0.503060, -0.321950, -0.265320, 
-0.567600, -0.389260, -0.299600, 0.814250, -0.420320, -0.261090, 0.181830, -0.619530, 0.252080, -0.107370, 
-0.703490, 0.285980, -0.177200, 0.876510, 0.738260, -0.307580, 0.666750, 0.917870, 0.064040, 0.165870, 
-0.376390, -0.554440, -0.040550, -1.069620, 0.060920, 0.115080, 0.401660, 
0.100300, 0.087720, 0.331600, 0.400300, 0.437160, -0.394850, 0.214530, 0.156370, -0.383410, -0.202050, 
0.691010, -0.348580, -0.202520, -0.968420, -0.091210, 1.088480, 0.708360, -0.885600, -0.401680, 0.215350, 
-0.001220, -1.043810, -0.389270, 0.011340, 0.780550, 0.635540, -0.794220, 
0.166730, -0.169900, 0.192940, 0.078350, 0.401060, 0.109640, -0.414410, -0.282470, -0.137420, -0.433010, 
-0.196380, 0.948090, 0.511670, 0.689000, 0.259620, -0.777670, -0.845330, -0.785150, -0.918140, -0.119510, 
0.529230, -0.322110, 0.094400, -0.838080, -0.661720, -0.982010, 0.763930, 
0.188680, 0.214510, -0.167750, 0.562070, 0.650790, -0.637300, 0.912380, -0.379340, 0.670730, -0.198780, 
-0.326630, 0.123450, -0.020570, 0.079370, 0.270910, -0.298310, 0.917310, -0.009710, -0.631510, 0.584030, 
0.046390, -1.039220, -0.166620, -0.308190, 0.952430, 0.264480, -0.950420, 
-0.445150, -0.888860, -0.136540, 0.367510, -0.780890, -0.775450, -0.793430, -0.880720, -0.051610, -0.234030, 
-0.481340, -0.416790, -0.165430, -0.784580, 0.458860, 0.639400, 0.884240, 0.925410, 0.534150, 0.088900, 
-0.337670, 0.453460, -0.215180, 0.932360, 0.632050, -0.831610, -0.313540, 
-0.271480, -0.584990, -0.609400, 0.303020, -0.856870, 0.683460, -0.778510, -0.648510, -0.283280, -0.300440, 
0.504160, 0.637790, -0.018840, 0.537640, -0.246090, 0.735280, -0.535070, 0.523200, 0.486250, -0.127770, 
-0.207700, 0.717540, -0.332820, -0.587640, 0.009750, -0.039450, 0.363590, 
0.616370, 0.809950, -0.260600, 0.794110, 0.052660, -0.265800, 0.914860, 0.503210, -0.453910, 0.014230, 
0.723110, -0.527630, -0.297780, 0.357940, -0.526710, -0.465580, -0.838350, 0.937040, 0.158580, -1.016990, 
-0.961110, -0.378280, -0.883160, 0.132110, -0.810090, -0.146990, -0.383060, 
0.928570, 0.574000, -0.099910, 0.409450, -0.109960, 0.673610, 0.853040, -0.793710, 0.025680, 0.653680, 
-0.414330, 0.879710, 0.765020, -0.563360, -0.110890, -0.464080, 0.466350, 0.346950, -0.916580, 0.620370, 
0.804440, 0.133930, -0.065260, 0.582780, 0.470300, 0.034130, -0.750940, 
-0.108260, -0.458850, 0.338170, 0.411170, -0.800210, -0.009680, -0.481030, 0.478800, -0.516390, -0.111330, 
-0.247370, 0.381700, -0.289150, 0.066660, -0.600900, 0.916770, 0.951610, 0.352200, -0.672830, -0.064620, 
-0.239200, 0.575200, 0.665350, 0.257290, 0.765730, 0.478640, -0.176170, 
-0.879220, 0.743260, 0.286500, -0.517820, -1.007010, 0.530960, -0.085660, 0.223730, 0.098890, -0.844170, 
0.715220, 0.596890, -0.774150, -0.794090, 0.429700, 0.273220, -0.599770, -0.850510, -0.768100, 0.328480, 
0.202070, 0.402270, -0.685210, 0.937880, 0.514820, -0.246740, -0.297880, 
-0.478430, 0.881230, -0.632000, 0.130680, 0.248550, -0.217360, 0.832630, -0.858900, -0.663750, -0.845500, 
0.942660, 0.237210, -0.567290, 0.846530, -0.669960, 0.038430, 0.025010, 0.493450, 0.640780, 0.130900, 
0.345640, -0.076540, 0.859850, 0.915300, -0.354530, 0.548880, 0.715440, 
0.229180, 0.554710, 0.144130, 0.201130, 1.138170, 0.949780, -0.700300, 0.435830, 0.648950, 0.692130, 
0.604940, -0.742520, -0.855900, 1.001530, 0.881360, 0.868600, 0.689020, -0.590980, -0.076270, 0.920230, 
-0.291970, -0.265360, -0.359020, -0.297790, -0.417490, 0.412740, 0.807820, 
-0.063770, 0.337200, 0.064490, 0.213650, 0.115210, -0.950690, -0.954730, 0.577000, 0.685230, 0.247330, 
0.449080, -0.862540, 0.376030, 0.476400, 0.695890, -0.443310, 0.521000, -0.106120, -0.845710, 0.254400, 
0.092180, -0.113080, 0.386000, -0.888010, -1.006170, 0.694880, -0.609340, 
-0.966820, -0.905140, 0.758490, 0.767550, 0.060040, -0.342830, -0.453800, 0.244770, -0.721160, -0.057180, 
-0.383130, -0.579690, 0.908050, 0.363520, -0.538200, -0.848280, -0.108320, 0.997110, 0.484610, 0.057120, 
0.334140, -0.298050, 1.006940, -0.660140, 0.530630, -0.641790, -0.784090, 
-0.645460, 0.594830, 0.372980, -0.756930, 0.739990, 0.380300, 0.744770, 0.317630, -0.324620, 0.704350, 
-0.410220, 0.272300, 0.685070, 0.372630, -0.341400, -0.680360, -0.382670, -0.273740, 0.369810, 0.150550, 
0.416770, -0.653890, -0.715880, -0.244200, 0.456900, -0.011210, 0.274040, 
0.749690, -0.482580, -0.591990, -0.595170, -0.174010, 0.058110, -0.614520, -0.058150, 0.032770, -0.689020, 
0.371270, -0.707940, 0.483480, 0.658140, 0.547240, -0.362180, 0.094830, 0.807600, 0.099960, 0.345210, 
-0.411210, 0.463810, -0.665070, -0.876430, -0.553200, 0.706240, -0.776630, 0.768340, 0.066190, 0.649900, 
0.479010, -0.618560, 0.764620, 0.806170, -0.524880, -0.287110, 0.618710, -0.732070, -0.499090, -1.073440, 

-0.960880, 0.467480, -0.557170, 0.770880, 0.384160, -0.760500, -0.541380, -0.710220, 0.455040, -0.432020, 
0.583550, 0.565970, 0.972010, 0.701890, -0.272830, -0.201430, -0.876000, -0.085360, 0.832680, -0.852550, 
-0.896560, 0.179250, -0.381110, -0.869240, 0.492430, 0.887750, -0.824240, -0.185680, -0.080760, -0.372480, 
-0.743050, -0.437690, -0.047760, 0.422100, -0.866720, 0.284790, 0.270560, -0.273650, -0.440880, -0.745170, 

0.964540, -0.801270, -0.281240, -0.867590, 0.138380, 0.648300, -1.121390, -0.439660, -0.551720, 0.250350, 
0.708380, 0.638370, -0.088240, -0.618360, -0.103460, -0.726210, 0.078980, -0.153520, 0.234010, -0.274250, 
0.703600, -0.667150, -0.725730, -0.322150, 0.880090, 0.900090, -0.502630, 0.818740, 0.580360, 0.616240, 
0.117200, 0.073550, 0.917860, 0.367320, 0.882790, 0.443330, -0.505030, -0.344370, 0.275310, 0.715710, 

-1.013970, 0.297260, -0.563050, 0.685890, 0.616110, 0.851920, 0.764050, 0.488460, 0.576150, -0.780850, 
-0.298230, 0.617890, -0.602790, -0.424370, 0.649840, -0.963460, -0.781860, 0.711600, 0.480810, -0.395280, 
0.800260, 0.623760, 0.795440, -0.141230, 0.344180, -0.814590, -0.930070, 0.290180, -0.492790, 0.211840, 
0.181270, 0.116680, 0.161040, -0.405130, 0.702470, 0.713120, -0.136700, -0.067290, 0.465300, 0.037920, 

-0.571830, -0.197550, -0.268490, 0.547290, 0.485460, 0.867050, -0.426590, 0.739970, 0.227330, -0.788080, 
0.022880, 0.663650, 0.663740, -0.513810, 0.652440, -0.697080, 0.935100, 0.124410, 0.930210, -0.075480, 
0.669620, 0.628290, -0.065440, -0.646320, -0.145720, -0.205240, 0.714170, -0.599120, -0.383470, -0.215500, 
-0.433720, -0.046640, 0.053410, 0.797950, 0.102700, 0.514510, 0.519190, -0.975380, 0.277460, 0.771990, 

-0.571620, -0.484950, -0.222660, -0.450760, 0.606840, -0.435520, 0.543140, 0.662240, 0.723420, 0.518270, 
-0.553460, -0.812350, 0.136950, -0.512280, 0.745460, 0.277410, -0.918740, 0.331790, 0.212130, 0.952440, 
0.666460, 0.735070, -0.424980, -0.855630, -0.200300, -0.981830, 0.025620, -0.675310, -0.629010, 0.303080, 
-0.005810, 0.456190, -0.227180, 0.808650, -0.783670, -0.539690, -0.811300, -0.005850, -0.795360, -0.443030, 

-0.153610, -0.509210, -0.918320, 0.463760, 0.542500, 0.598800, -0.171900, -0.334260, -0.387380, -0.001840, 
-0.473510, -0.912320, 0.188840, -0.754390, 0.801960, 0.385200, -0.021280, -0.683500, 0.399360, 0.771180, 
0.907870, -0.876380, -0.395090, 0.642580, -0.056910, -0.666020, 0.792340, 0.347460, 0.865480, 0.837780, 
-0.827900, 1.011530, 0.546280, 0.197790, 0.785720, 0.778510, 0.082730, 0.446090, 0.347280, 0.859360, 

-0.113520, -0.652180, 0.616830, 0.627940, -0.254810, -0.923640, -0.400480, -0.278160, -0.035160, 0.689720, 
0.588340, -0.070280, 0.672030, 0.351850, -0.820130, 0.179430, -0.758060, 0.343660, -0.629990, -0.066280, 
0.181130, -0.239720, -0.865690, -0.650990, -0.703650, -0.985770, -0.414150, -0.583320, -0.503000, 0.282040, 
-0.759610, 0.187080, -0.702510, -0.737850, -0.281710, 0.264040, -0.358740, 0.363790, 0.197120, 0.639020, 

-0.187090, 0.512720, 0.141680, 0.756390, -0.204290, -0.636040, 0.651220, -0.175090, -0.103330, 0.239980, 
0.921270, 0.889970, 0.742290, 0.106220, 0.827160, -0.723800, -0.050030, 0.895130, 0.069200, -0.546610, 
0.089810, 0.718730, 0.973520, -0.432120, 0.290470, -0.966320, 0.852230, 0.733400, 0.850260, -0.625410, 
-0.849740, -0.328230, 0.022650, 0.964060, -0.756970, -0.910240, 0.103770, 0.718710, 0.348850, -0.472160, 

0.124440, -0.503670, 0.008370, -0.608970, -0.881590, -0.634870, 0.064070, -0.079520, 0.790380, 0.886820, 
0.345400, -0.511620, -0.877510, 0.291720, -0.683070, 0.645140, -0.980820, -0.837220, -0.004770, -0.850540, 
0.771120, -0.817620, 0.470030, -0.465390, 0.282830, -0.666220, -0.587270, -0.463560, 0.194440, -0.273030, 
-0.962300, 0.284180, -0.051740, -0.887900, 0.355370, -0.862440, 0.994450, -0.402130, -0.030410, -0.810050, 

-0.180910, -0.559490, -0.716740, 0.270810, -0.353830, -0.714590, 0.368730, 0.514120, -0.410110, 0.628630, 
-0.023460, 0.226830, 0.348630, -0.641750, 0.591900, 0.518470, -0.717570, 0.253360, 0.841340, 0.018040, 
0.709700, 0.421440, 0.696210, 0.192730, 0.694950, 0.990760, 0.494440, 0.870100, 0.210850, 0.455470, 
0.071940, 0.313900, 0.050720, 0.914650, -0.158980, -0.911880, 0.595260, 0.945510, 0.347990, 0.692600, 

-0.542180, 0.992420, -0.926750, -0.958860, -0.487950, -0.929450, -0.121680, 0.375950, -0.746120, -0.434480, 
0.100180, -0.703980, 0.037380, 0.963130, 0.378950, -0.248740, 0.348960, 0.116840, -0.279080, -0.589650, 
0.869880, 0.370860, 0.548860, 0.574550, 0.695800, -0.678690, -0.804500, -0.700600, -0.534100, 0.105020, 
0.263250, -0.940080, -0.563100, 0.084100, -0.543910, 0.430040, -0.571450, -0.181290, 0.841340, 0.094280, 

0.763620, 0.428650, -0.151360, -0.594660, -0.773290, -0.342750, 0.159410, -0.717410, -0.151560, 0.226770, 
0.462240, 0.335860, 0.263380, 0.297020, 0.481130, -0.703900, -0.303330, -0.171740, 0.459440, 0.461660, 
-0.568670, -0.254240, 0.224370, 0.945250, 0.136550, -0.508700, -0.563130, -0.949950, -0.485140, 0.436500, 
-0.558640, 0.183880, 0.327530, 0.611600, -0.924590, 0.590370, -0.222050, 0.221070, 1.002380, -0.887830, 

0.490540, 0.714840, 0.039550, 0.161210, 0.424510, -0.232500, -0.269990, -0.939600, 0.633160, -0.975100, 
0.984580, 0.964840, -0.232360, -0.583070, -0.264150, 0.817190, 0.025220, -0.550940, 0.937880, -0.747170, 
-0.062730, 0.477750, 0.855730, -0.625350, -0.738930, 0.527310, 0.773500, 0.697580, 0.768170, -0.369300, 
0.903170, -0.757400, -0.089180, -0.051940, -0.525900, 0.034440, -0.876160, 0.292120, 0.962790, -0.816670, 

-0.229900, -0.715720, -0.022790, -0.734670, -0.244340, -0.599110, -0.196730, -0.292770, -0.423610, -0.243820, 
-0.139190, -0.464830, -0.996140, 0.337090, -0.229330, 0.736670, -0.676450, -0.652910, -0.105060, -0.830990, 
-0.838660, -0.252860, -0.461340, 0.354310, 0.210690, -0.270170, -0.853250, -0.996480, 0.923310, -0.111950, 
0.334980, -0.128270, -0.477990, 0.640080, -0.170870, 0.508970, 0.320750, 0.627790, 0.331240, 0.847660, 

0.972230, -0.370540, 0.405330, -0.577220, -0.875840, 0.837640, -0.782200, 0.558520, 0.333410, -0.730230, 
0.858950, -0.739690, 0.201090, 0.091480, 0.001190, 0.392190, -0.364010, -0.071420, 0.681200, -0.932260, 
0.785150, 0.186620, 0.218600, 0.919810, 0.326090, -0.460570, -0.313170, 0.775080, 0.535520, -0.154210, 
0.364670, -0.460100, -0.285080, -0.725880, 0.587670, -0.388520, 0.959830, 0.157160, 0.624100, -0.502980, 

0.199000, -0.403660, -0.770100, 0.246760, -0.120530, 0.129480, 0.498680, -0.377670, 0.328300, -0.930500, 
0.043530, 0.241220, 0.249160, -0.444800, 0.134130, 0.738640, 0.838210, 0.194580, -0.462980, 0.728130, 
0.766440, 0.722550, -0.715450, 0.609840, 0.006000, 0.201790, 0.354110, 0.259100, -0.773540, 0.604440, 
0.519160, 0.169620, -0.627760, 0.029750, -0.430420, -0.644610, 0.742820, 0.819640, -1.059900, 0.867700, 

-0.089040, -0.502250, 0.464120, -0.486420, -0.878410, 0.928870, 0.086940, -0.557900, 0.057380, 0.973850, 
-1.055300, -0.649780, -0.634000, 0.499100, -0.728510, 0.058080, -0.530070, -0.428260, -0.427270, -0.317140, 
-0.411670, 0.459770, -0.759630, 1.087670, 0.766250, 0.641200, -0.372480, -0.425890, 0.793160, -0.691260, 
0.459410, 0.853350, -0.582710, 0.756950, 0.142710, -0.052470, 0.288920, -0.125060, 0.808290, -0.378600, 

0.563600, 0.356190, 0.436230, -0.949540, -0.158250, 0.666490, 0.426510, 0.734280, 0.279160, 0.129290, 
-0.030660, -0.060550, -0.706370, -0.091160, 0.412740, 0.919170, -0.326760, 0.803670, 0.785670, -0.672570, 
-0.173880, 0.378940, 1.006910, -0.254210, -0.386530, 0.937850, -0.057910, -0.884150, -0.970930, -0.027080, 
0.184580, 0.202530, -0.272820, 0.149320, -0.748220, 0.182900, 0.985130, 1.031130, 0.188480, -0.151360, 

0.431530, 0.591150, 0.267450, -0.928660, -0.255670, -0.317690, -0.289130, 0.522680, -0.902410, -0.678080, 
0.018690, 0.752430, 0.543100, -0.914810, -0.380360, -0.414670, 0.225150, -0.764790, -0.066000, -0.348540, 
0.592540, 0.157880, -0.038620, 0.831390, -0.961370, -0.342790, -0.332800, 0.252440, 0.584480, -0.459190, 
-0.132610, -0.448750, -0.932030, -0.827470, 0.327420, -0.950800, 0.169690, -0.789560, -0.393580, 0.789120, 

0.427040, 0.601230, 0.584410, -1.419830, 0.542520, 0.380100, -0.228850, -0.883580, -1.110730, 0.398720, 
-0.894730, -0.291570, -0.015910, -0.426280, 0.353520, 0.610780, 0.706020, 0.954210, 0.331290, -0.058250, 


  };

  /* unit definition section (see also UnitType) */
  static UnitType Units[89] = 
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
      0.0, -0.246940, 27,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (Old: 29) */
      0.0, -0.029470, 27,
       &Sources[27] , 
       &Weights[27] , 
      },
    { /* unit 30 (Old: 30) */
      0.0, -0.665320, 27,
       &Sources[54] , 
       &Weights[54] , 
      },
    { /* unit 31 (Old: 31) */
      0.0, 0.624230, 27,
       &Sources[81] , 
       &Weights[81] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, -0.851650, 27,
       &Sources[108] , 
       &Weights[108] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.294890, 27,
       &Sources[135] , 
       &Weights[135] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.773870, 27,
       &Sources[162] , 
       &Weights[162] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, -0.124250, 27,
       &Sources[189] , 
       &Weights[189] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, 0.293970, 27,
       &Sources[216] , 
       &Weights[216] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, -0.411910, 27,
       &Sources[243] , 
       &Weights[243] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, -0.868150, 27,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, -0.958810, 27,
       &Sources[297] , 
       &Weights[297] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, -0.958890, 27,
       &Sources[324] , 
       &Weights[324] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, 0.955250, 27,
       &Sources[351] , 
       &Weights[351] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.104320, 27,
       &Sources[378] , 
       &Weights[378] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, -0.851570, 27,
       &Sources[405] , 
       &Weights[405] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.219500, 27,
       &Sources[432] , 
       &Weights[432] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, -1.030950, 27,
       &Sources[459] , 
       &Weights[459] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.871830, 27,
       &Sources[486] , 
       &Weights[486] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.766710, 27,
       &Sources[513] , 
       &Weights[513] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.395970, 27,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.127830, 27,
       &Sources[567] , 
       &Weights[567] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.211070, 27,
       &Sources[594] , 
       &Weights[594] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, 0.276350, 27,
       &Sources[621] , 
       &Weights[621] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, 0.165840, 27,
       &Sources[648] , 
       &Weights[648] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -1.106990, 27,
       &Sources[675] , 
       &Weights[675] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, -0.760130, 27,
       &Sources[702] , 
       &Weights[702] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, 0.462900, 27,
       &Sources[729] , 
       &Weights[729] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, -0.465350, 27,
       &Sources[756] , 
       &Weights[756] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.892450, 27,
       &Sources[783] , 
       &Weights[783] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.824180, 27,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, 0.769430, 27,
       &Sources[837] , 
       &Weights[837] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, -0.029130, 27,
       &Sources[864] , 
       &Weights[864] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, 0.425510, 27,
       &Sources[891] , 
       &Weights[891] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.420370, 27,
       &Sources[918] , 
       &Weights[918] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.903530, 27,
       &Sources[945] , 
       &Weights[945] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, -0.733710, 27,
       &Sources[972] , 
       &Weights[972] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.919600, 27,
       &Sources[999] , 
       &Weights[999] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, -0.415140, 27,
       &Sources[1026] , 
       &Weights[1026] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.349470, 27,
       &Sources[1053] , 
       &Weights[1053] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, -0.968600, 40,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, 0.218440, 40,
       &Sources[1120] , 
       &Weights[1120] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, -0.737180, 40,
       &Sources[1160] , 
       &Weights[1160] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.117930, 40,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, 0.020290, 40,
       &Sources[1240] , 
       &Weights[1240] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.849730, 40,
       &Sources[1280] , 
       &Weights[1280] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.794860, 40,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, -0.868190, 40,
       &Sources[1360] , 
       &Weights[1360] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.780800, 40,
       &Sources[1400] , 
       &Weights[1400] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.557440, 40,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.658590, 40,
       &Sources[1480] , 
       &Weights[1480] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.396980, 40,
       &Sources[1520] , 
       &Weights[1520] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.188460, 40,
       &Sources[1560] , 
       &Weights[1560] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.798980, 40,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, -0.946420, 40,
       &Sources[1640] , 
       &Weights[1640] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.130770, 40,
       &Sources[1680] , 
       &Weights[1680] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.070090, 40,
       &Sources[1720] , 
       &Weights[1720] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, -0.683880, 40,
       &Sources[1760] , 
       &Weights[1760] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.787680, 40,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.149780, 40,
       &Sources[1840] , 
       &Weights[1840] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.048080, 20,
       &Sources[1880] , 
       &Weights[1880] , 
      }

  };



int r(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[27] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27}; /* members */

  static pUnit Hidden1[40] = {Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67}; /* members */

  static pUnit Hidden2[20] = {Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87}; /* members */

  static pUnit Output1[1] = {Units + 88}; /* members */

  static int Output[1] = {88};

  for(member = 0; member < 27; member++) {
    Input[member]->act = in[member];
  }

  for (member = 0; member < 40; member++) {
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
