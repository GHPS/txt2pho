/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  h.c
  --------------------------------------------------------
  generated at Tue Jun 23 14:52:17 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

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
1.019210, -0.884270, 0.267770, -0.882130, 0.348570, -0.308020, 0.087030, -0.063260, -0.215660, -0.488120, 
-0.267260, 0.205460, 0.331230, 0.697260, 0.389580, -0.773900, 0.574040, -0.217430, -0.217220, 0.394160, 
-0.955650, 0.488730, -0.544250, -0.065190, 0.073710, 1.025380, -0.688350, 
-0.689960, 0.206570, -0.640370, -0.126850, -0.433270, -0.311990, 0.368260, 0.290930, 0.576750, 0.183300, 
-0.576770, -0.849570, 0.076380, -0.349530, -0.733010, 0.439320, -0.420230, 0.003600, -0.754640, 0.384450, 
0.471510, 0.853850, -0.816920, 0.590070, -0.183090, 0.883540, 0.461840, 
0.045070, -0.610660, -0.867500, -0.920230, 0.380840, 0.513170, -0.618760, 0.962610, -0.722690, 1.034220, 
-0.036640, -0.767600, 0.566460, 0.034060, 0.754780, 0.182540, -0.519610, -0.376510, 0.193930, -0.521620, 
-0.764540, -0.806010, 0.893920, -0.041330, 0.154180, -0.857610, 0.638090, 
0.648830, 0.114830, 0.940030, -0.564340, 0.905400, -0.256000, 0.577520, 0.614610, 0.307010, -0.832290, 
0.562790, 0.577140, 0.041390, 0.218050, 0.871530, -0.001830, 0.558990, -0.403250, 0.176830, 0.517580, 
0.910310, 0.998180, 0.649490, 0.477350, 0.361090, 0.426760, -0.147850, 
-0.505180, 0.842620, -0.683480, 0.943230, -0.305310, 0.239510, 0.688870, -0.236390, 0.261190, 0.880960, 
-0.348290, -0.859800, 0.449530, -0.159800, -0.358580, -0.306460, -0.486320, -0.677470, -0.380630, -0.786810, 
0.203440, 0.065400, -0.890480, -0.391130, -0.751610, 0.033530, -0.821990, 
-0.499540, 0.251560, -0.666040, -0.684170, -0.284260, 0.429270, -0.803500, 0.853770, -0.315200, -0.725140, 
-0.684790, -0.419620, 0.425850, -0.750700, 0.339010, -0.142730, 0.441990, 0.726570, -0.916330, 0.509980, 
0.553950, 0.478880, -0.305220, 0.577130, 0.338970, 0.236600, -0.814060, 
-0.695270, 0.956940, 0.605770, 0.405930, 0.415630, 0.049290, 0.936880, 0.106930, -0.636710, -0.238120, 
-0.144110, 0.441510, -0.053430, 0.242200, 0.917790, -0.232840, 0.887200, -0.963090, 0.765550, -0.925240, 
-0.797070, 0.286570, -0.413060, 0.313810, -0.718280, -0.152520, -0.705060, 
-0.974200, -0.835920, 0.468310, 0.798810, 0.035020, -0.644810, 0.372990, -0.120000, 0.195640, 0.383360, 
0.892190, -0.746190, 0.179570, 0.462510, -0.053280, 0.227620, 0.318720, 0.487010, 0.496030, -0.653260, 
-0.642700, -0.494130, -0.899060, 0.552220, 0.756310, -0.471370, 0.787270, 
0.697320, -0.610910, -0.459260, -0.927620, 0.864060, -0.011600, 0.460290, 0.367660, -0.103430, 0.877950, 
-0.378640, 0.901500, 0.097210, 0.322030, 0.570880, 0.628530, 0.133320, 0.292260, -0.941680, -0.130630, 
0.154970, -0.812130, 0.077080, -0.504570, 0.249170, 0.519770, -0.807350, 
-0.043510, 0.737870, 0.883690, -0.567920, 0.135300, -0.669660, -0.239640, -0.970330, 0.178300, 0.366470, 
0.834200, -0.504590, -0.696640, 0.381510, 0.343810, -0.821220, 0.201060, -0.185540, 0.886480, -0.210920, 
0.943830, -0.022720, 0.086940, -0.910900, -0.228500, -0.648130, -0.458930, 
0.408830, -0.534960, -0.859370, 0.247850, 0.754810, -0.517920, -0.568090, -0.389730, 0.536040, -0.459350, 
-0.063910, 0.971320, 0.153300, 0.310390, 0.049520, 0.191080, -0.499830, -0.617350, 0.720520, -0.552360, 
-0.148510, 0.772190, 0.412940, -0.713730, 0.166750, 0.209900, -0.771010, 
-0.385930, -0.130970, -0.765760, 0.008930, 0.165260, 0.297760, 0.489050, -0.901740, 0.360550, 0.110130, 
-0.682640, 0.133960, -0.702380, 0.429800, 0.086840, -0.487100, -0.576820, 0.588670, -0.144800, 0.568690, 
0.256710, 0.726020, -0.539070, 0.968810, -0.199710, 0.901640, 0.151730, 
0.460980, 0.808610, -0.133260, 0.065720, 0.606430, -0.324170, -0.060220, -0.474770, 0.553410, 0.649790, 
0.232950, -0.596260, -0.978900, 0.159350, 0.395710, -0.562110, -0.800420, 0.613810, 0.864490, 0.578500, 
0.592970, -0.087300, 0.696100, 0.592080, 0.943610, -0.119530, 0.632990, 
0.471930, -0.171480, 0.245060, -0.849570, 0.951470, -0.667760, 0.355580, 0.724990, -0.318960, 0.505840, 
0.747130, 0.606240, -0.401900, 0.150690, 0.097470, -0.575910, 0.840700, 0.141090, -0.909150, 0.732780, 
-0.793200, 0.385440, 0.494940, 0.875960, 0.855940, -0.792400, -0.134990, 
0.421450, -0.039070, -0.060590, -0.471490, 0.794570, -0.096030, -0.472600, -0.283570, -0.526640, 0.787260, 
0.166410, 0.694650, -0.504860, 0.136150, 0.855640, 0.902330, -0.632520, -0.677780, -0.376110, 0.442070, 
-0.715270, 0.405430, 0.676720, 0.741590, 0.654370, -0.507970, -0.377340, 
0.535720, -0.951420, -0.070370, -0.828350, -0.285530, -0.836070, -0.450000, 0.396890, -0.364890, -0.933840, 
0.877250, 0.988900, -0.999400, 0.425340, -0.706720, -0.628270, 0.280590, -0.967970, 0.459010, 0.781810, 
0.993550, -0.756050, -0.619050, 0.483550, -0.401570, 0.019510, 0.149900, 
0.602060, -0.237540, -0.037610, 0.529880, -0.866400, 0.173380, -0.805930, -0.057540, 0.412800, 0.749420, 
0.446810, -0.132860, -0.374270, -0.075630, -0.455290, 0.286860, 0.244910, 0.975820, -0.095160, 0.032940, 
-0.535380, -0.844990, 0.740350, -0.802100, 0.615100, -0.583580, -0.153830, 
-0.918850, -0.330150, 0.481800, 0.554310, -0.619710, 0.579530, -0.433350, -0.560050, 0.640870, -0.353740, 
-0.879490, 0.700810, 0.117380, -0.707530, 0.039970, 0.532630, -0.266070, -0.887650, 0.548540, -0.237320, 
0.707340, 0.300970, 0.495690, 0.614880, -0.105760, 0.679070, -0.027970, 
0.967630, -0.065290, 0.324970, 0.412680, -0.701160, 0.105320, 0.859390, 0.584900, -0.412050, -0.675410, 
0.713950, -0.410110, -0.115680, -0.653530, -0.682830, -0.046920, 0.171760, 0.097560, 0.336650, 0.699390, 
-0.368080, 0.759100, -0.322080, -0.399780, -0.979420, -0.563400, -0.611670, 
0.508370, -0.023820, -0.711930, 0.963280, -0.215930, -0.683040, 0.334900, -0.933610, 0.980700, -0.318340, 
-0.178560, 0.920060, -0.528550, 0.726780, -0.882270, -0.227320, 0.305480, 0.102180, -0.463550, 0.685150, 
0.327320, 0.003940, -0.609790, 0.109970, -0.447670, -0.949650, 0.632260, 
0.615790, 0.986000, -0.601430, 0.151430, -0.525740, 0.441820, -0.166500, -0.151140, -0.186500, -0.195350, 
-0.634670, -0.730620, -0.331530, -0.542810, 0.182500, 0.935130, -0.906070, -0.748840, -0.099380, 0.339970, 
0.585820, 0.229880, -0.893950, -0.237140, -0.532290, 0.835680, -0.607810, 
0.846690, 0.765350, -0.013860, -0.543510, 0.953510, 0.186710, -0.766180, 0.810480, -0.794950, -0.770650, 
-0.500690, -0.297150, 0.762620, -0.296550, 0.039930, 0.320130, 0.687040, 0.198300, 0.663150, 0.241510, 
0.915200, -0.701490, 0.337180, -0.587060, 0.794720, -0.839050, -0.934440, 
-0.013230, 0.293350, 0.707490, -0.957090, -0.548520, 0.469020, 0.392330, 0.996280, -0.334560, -0.435140, 
0.693930, 0.146590, 0.815810, 0.772740, 0.335370, 0.055340, -0.782350, -0.111040, -0.173230, 0.678950, 
-0.266740, -0.680440, 0.858710, 0.177620, 0.683590, -0.626410, 0.857560, 
0.941080, 0.452440, 0.573670, -0.115760, 0.304550, 0.538290, -0.748920, 0.511750, -0.397280, -0.242760, 
0.176840, -0.199930, -0.001410, 0.222590, -0.821450, -0.834630, -0.107840, -0.435960, 0.160420, 0.542100, 
-0.005770, 0.395350, -0.865870, -0.152680, 0.675940, 0.183530, -0.774710, 
-0.957210, -0.255970, -0.752830, 0.546470, -0.036460, -0.615240, -0.594940, -0.730370, -0.619410, 0.821380, 
-0.665810, 0.001130, -0.369260, -0.552320, -0.096430, -0.453530, 0.531730, -0.515320, -0.696850, 0.487530, 
0.458060, 0.599660, 0.898260, 0.048620, 0.461460, -0.283700, -0.266670, 
-0.582280, -0.426220, -0.236650, 0.899880, -0.432640, -0.243150, 0.327570, -0.606920, 0.223050, -0.090770, 
-0.728370, 0.277710, -0.173120, 0.885500, 0.695000, -0.247940, 0.594090, 0.959230, 0.069900, 0.132850, 
-0.401890, -0.567820, -0.037370, -0.939350, 0.049070, 0.060710, 0.413610, 
0.134220, 0.108290, 0.228190, 0.310700, 0.537690, -0.417790, 0.118830, 0.083900, -0.345170, -0.232820, 
0.854930, -0.325840, -0.202370, -0.969610, -0.165040, 1.066360, 0.874350, -0.940350, -0.435800, 0.193380, 
0.061470, -0.926970, -0.459290, -0.066660, 0.878900, 0.642890, -0.778810, 
0.158680, -0.169150, 0.207790, 0.086590, 0.407800, 0.183150, -0.402800, -0.267940, -0.141800, -0.487130, 
-0.171360, 1.010410, 0.514420, 0.712500, 0.282910, -0.718300, -0.840580, -0.764770, -0.884430, -0.138760, 
0.520540, -0.324310, 0.061140, -0.804680, -0.622390, -0.984230, 0.787140, 
0.165700, 0.197800, -0.185420, 0.526580, 0.769580, -0.635650, 0.875870, -0.453270, 0.714890, -0.179700, 
-0.263440, 0.181580, -0.031270, 0.078270, 0.256890, -0.260750, 0.953500, -0.041000, -0.620330, 0.558210, 
0.026150, -0.964800, -0.182210, -0.329010, 0.949910, 0.214640, -0.939240, 
-0.459270, -0.889420, -0.113650, 0.400030, -0.798090, -0.742050, -0.724960, -0.861860, -0.045950, -0.246570, 
-0.511720, -0.380370, -0.170450, -0.771410, 0.469250, 0.664860, 0.861890, 0.948630, 0.560670, 0.089170, 
-0.339670, 0.437570, -0.224330, 0.981630, 0.642500, -0.836710, -0.323930, 
-0.332220, -0.608710, -0.564540, 0.340330, -0.899490, 0.729360, -0.709850, -0.587970, -0.286730, -0.332330, 
0.420460, 0.638090, -0.014190, 0.542400, -0.240750, 0.767310, -0.593590, 0.544770, 0.505790, -0.122860, 
-0.223300, 0.641240, -0.330240, -0.550510, -0.020250, -0.113230, 0.371240, 
0.632370, 0.799730, -0.225320, 0.829500, 0.062240, -0.259310, 1.001630, 0.523750, -0.485190, 0.070060, 
0.664260, -0.577930, -0.289740, 0.355820, -0.517520, -0.473540, -0.889980, 0.939740, 0.150210, -0.981930, 
-0.977840, -0.376820, -0.770520, 0.150130, -0.862770, -0.157400, -0.386120, 
0.938460, 0.575170, -0.111130, 0.394510, -0.092840, 0.658410, 0.838160, -0.820750, 0.022490, 0.647230, 
-0.408190, 0.890270, 0.745590, -0.565070, -0.104890, -0.455420, 0.474070, 0.346170, -0.909530, 0.615080, 
0.805520, 0.146740, -0.087260, 0.594470, 0.478190, 0.046840, -0.748720, 
-0.042680, -0.459730, 0.364480, 0.435340, -0.774830, -0.003230, -0.474900, 0.496810, -0.596010, -0.101910, 
-0.246230, 0.360500, -0.315150, 0.077480, -0.565710, 0.940310, 0.913060, 0.375700, -0.687420, -0.045500, 
-0.252480, 0.593480, 0.784530, 0.323790, 0.759890, 0.552560, -0.147610, 
-0.917460, 0.720490, 0.292720, -0.516770, -0.961210, 0.568820, 0.015840, 0.220960, 0.111230, -0.876170, 
0.722300, 0.641140, -0.801550, -0.780470, 0.421420, 0.343470, -0.566120, -0.857430, -0.755470, 0.330150, 
0.199100, 0.445850, -0.639340, 0.958900, 0.542950, -0.332390, -0.281230, 
-0.493730, 0.875360, -0.659430, 0.101150, 0.218020, -0.278040, 0.796690, -0.897460, -0.648760, -0.850710, 
0.958210, 0.227280, -0.578020, 0.824010, -0.664820, -0.017490, 0.038870, 0.475120, 0.622880, 0.139700, 
0.353430, -0.059490, 0.841760, 0.877060, -0.370590, 0.513470, 0.692470, 
0.128210, 0.517350, 0.243220, 0.273820, 0.933400, 0.948780, -0.595900, 0.553300, 0.594750, 0.659350, 
0.324090, -0.844100, -0.852850, 0.975400, 0.901820, 0.817850, 0.534900, -0.547110, -0.035320, 0.915790, 
-0.357550, -0.506780, -0.380790, -0.350860, -0.521660, 0.293650, 0.767470, 
-0.044260, 0.348020, 0.059100, 0.221130, 0.076650, -0.935740, -0.964990, 0.606920, 0.732500, 0.254730, 
0.451410, -0.848860, 0.404120, 0.487830, 0.683990, -0.432180, 0.543910, -0.089550, -0.834430, 0.254070, 
0.123710, -0.150030, 0.336800, -0.862710, -0.956460, 0.724570, -0.611340, 
-0.986810, -0.898880, 0.717630, 0.705830, 0.074900, -0.428080, -0.561470, 0.159260, -0.709330, -0.062880, 
-0.401530, -0.567800, 0.877490, 0.330550, -0.542150, -0.906730, -0.078210, 0.965690, 0.473000, 0.042650, 
0.325480, -0.282150, 0.950390, -0.756710, 0.512340, -0.642890, -0.822840, 
-0.679550, 0.588520, 0.368900, -0.750470, 0.681980, 0.388770, 0.830090, 0.339580, -0.343030, 0.655080, 
-0.411770, 0.258290, 0.687710, 0.371470, -0.346450, -0.686190, -0.370240, -0.273980, 0.351250, 0.161460, 
0.444320, -0.656170, -0.700880, -0.244860, 0.468060, -0.073550, 0.273600, 
0.738160, -0.502550, -0.495980, -0.607170, -0.165390, 0.052330, -0.517880, -0.090240, 0.025320, -0.706840, 
0.372290, -0.643390, 0.500170, 0.661030, 0.577000, -0.403190, 0.088080, 0.884520, 0.120300, 0.289030, 
-0.377570, 0.432930, -0.676220, -0.917590, -0.618180, 0.724220, -0.865360, 0.749930, 0.000210, 0.672170, 
0.482550, -0.531800, 0.743060, 0.826070, -0.557460, -0.281600, 0.586390, -0.735620, -0.449980, -1.040580, 

-0.927280, 0.512890, -0.449790, 0.812230, 0.401560, -0.707700, -0.479890, -0.706410, 0.458390, -0.427890, 
0.563110, 0.610460, 1.033620, 0.751160, -0.250560, -0.200190, -0.823460, -0.040450, 0.862650, -0.916800, 
-0.825350, 0.175190, -0.318360, -0.822670, 0.449260, 0.894540, -0.844290, -0.199650, -0.131220, -0.356830, 
-0.724860, -0.295010, -0.001280, 0.504120, -0.886450, 0.315640, 0.282930, -0.213160, -0.379160, -0.717780, 

0.894940, -0.794640, -0.205430, -0.898070, 0.162080, 0.611000, -1.006960, -0.414820, -0.596890, 0.221110, 
0.664530, 0.694210, -0.101850, -0.624850, -0.110400, -0.772130, 0.046640, -0.090170, 0.302520, -0.309900, 
0.705390, -0.732990, -0.692510, -0.425770, 0.800560, 0.911830, -0.581220, 0.780960, 0.507820, 0.661400, 
0.119960, 0.188890, 0.904750, 0.400280, 0.873910, 0.473050, -0.605370, -0.372180, 0.333230, 0.747280, 

-1.009490, 0.330310, -0.607780, 0.704660, 0.609870, 0.910520, 0.715120, 0.529940, 0.582430, -0.804740, 
-0.337500, 0.595830, -0.633190, -0.423010, 0.606390, -0.924460, -0.768510, 0.714990, 0.482090, -0.360820, 
0.800610, 0.651720, 0.852110, -0.138870, 0.332470, -0.811100, -0.900140, 0.291550, -0.462630, 0.226120, 
0.192780, 0.097700, 0.184810, -0.402150, 0.797130, 0.704500, -0.148520, -0.088160, 0.447100, 0.026100, 

-0.566110, -0.203950, -0.251070, 0.532600, 0.482560, 0.860790, -0.431910, 0.708850, 0.209300, -0.791380, 
0.005730, 0.666170, 0.674050, -0.517960, 0.645990, -0.703750, 0.927000, 0.108710, 0.942630, -0.105690, 
0.672280, 0.621770, -0.059130, -0.654420, -0.148560, -0.216800, 0.700910, -0.619560, -0.407760, -0.217560, 
-0.456890, -0.031480, 0.051060, 0.802030, 0.074400, 0.527410, 0.498320, -0.962330, 0.291940, 0.750810, 

-0.568660, -0.434190, -0.186180, -0.419920, 0.630020, -0.405510, 0.589500, 0.681240, 0.736030, 0.509620, 
-0.579380, -0.774280, 0.156160, -0.481420, 0.753210, 0.262260, -0.888490, 0.366680, 0.241250, 0.941010, 
0.700390, 0.741120, -0.381160, -0.838830, -0.205690, -0.971220, 0.023480, -0.689990, -0.618970, 0.321290, 
-0.003620, 0.535480, -0.184760, 0.860970, -0.779690, -0.521920, -0.825720, 0.005280, -0.758010, -0.403800, 

-0.158150, -0.527650, -0.946300, 0.447920, 0.536490, 0.582810, -0.191600, -0.344290, -0.391400, 0.003090, 
-0.461110, -0.929720, 0.171890, -0.773930, 0.789260, 0.388940, -0.032040, -0.697450, 0.388860, 0.783920, 
0.893530, -0.884370, -0.414680, 0.630670, -0.050260, -0.666600, 0.797080, 0.349170, 0.874110, 0.831120, 
-0.832530, 0.971690, 0.529430, 0.172830, 0.784870, 0.766300, 0.076880, 0.439460, 0.326610, 0.846530, 

-0.123070, -0.656530, 0.604190, 0.611520, -0.253880, -0.932450, -0.417250, -0.285590, -0.043640, 0.687850, 
0.579630, -0.080320, 0.654480, 0.333220, -0.836600, 0.175750, -0.765450, 0.335020, -0.634680, -0.066470, 
0.176340, -0.244680, -0.879040, -0.661350, -0.707720, -0.986520, -0.418020, -0.584470, -0.500440, 0.276740, 
-0.774680, 0.170850, -0.712930, -0.761280, -0.291540, 0.243990, -0.371840, 0.360630, 0.190700, 0.635220, 

-0.105450, 0.538540, 0.140210, 0.813070, -0.218600, -0.582730, 0.596000, -0.131400, -0.049250, 0.256780, 
0.937180, 0.881690, 0.780640, 0.148640, 0.869440, -0.672300, -0.003750, 0.860270, 0.028600, -0.552540, 
0.143180, 0.762050, 0.979030, -0.317680, 0.310470, -0.981660, 0.938010, 0.751460, 0.850970, -0.634050, 
-0.782480, -0.299280, 0.055640, 1.003130, -0.732760, -0.883900, 0.216260, 0.747930, 0.309860, -0.497420, 

0.123240, -0.506100, 0.013600, -0.610740, -0.881790, -0.637180, 0.066110, -0.085780, 0.788050, 0.887750, 
0.345630, -0.511970, -0.875670, 0.291800, -0.681900, 0.641750, -0.981760, -0.837080, -0.004130, -0.854870, 
0.770210, -0.821670, 0.470650, -0.468870, 0.284700, -0.667550, -0.592050, -0.463860, 0.187690, -0.274120, 
-0.964240, 0.285430, -0.053770, -0.886010, 0.351310, -0.859510, 0.993220, -0.399040, -0.028120, -0.812800, 

-0.162970, -0.554130, -0.738650, 0.275570, -0.359840, -0.702510, 0.336870, 0.516570, -0.400930, 0.630990, 
-0.018300, 0.222120, 0.355150, -0.640630, 0.587500, 0.537170, -0.708390, 0.239820, 0.828670, 0.027500, 
0.715330, 0.432590, 0.696060, 0.212340, 0.704660, 0.986550, 0.515380, 0.865280, 0.224430, 0.454810, 
0.077350, 0.300820, 0.056600, 0.914980, -0.151820, -0.910230, 0.606010, 0.948800, 0.334140, 0.679000, 

-0.507970, 0.981190, -0.982030, -0.960930, -0.510620, -0.913490, -0.186240, 0.371850, -0.736160, -0.428360, 
0.115970, -0.716670, 0.044530, 0.958290, 0.379300, -0.218760, 0.345980, 0.087800, -0.316980, -0.570110, 
0.861870, 0.379420, 0.527240, 0.605880, 0.719360, -0.690630, -0.768860, -0.709420, -0.514260, 0.100590, 
0.269360, -0.996330, -0.568550, 0.070430, -0.521920, 0.432650, -0.546720, -0.181190, 0.799380, 0.055400, 

0.778790, 0.427500, -0.160680, -0.599800, -0.776690, -0.349620, 0.137090, -0.730080, -0.157030, 0.233630, 
0.470950, 0.337350, 0.276080, 0.294970, 0.479910, -0.700710, -0.301960, -0.180240, 0.451190, 0.461160, 
-0.567000, -0.261910, 0.206810, 0.956540, 0.141430, -0.514640, -0.564150, -0.954420, -0.485120, 0.429160, 
-0.571410, 0.174950, 0.332550, 0.604200, -0.947580, 0.581360, -0.215730, 0.237160, 1.001020, -0.903090, 

0.505780, 0.664750, -0.064820, 0.126130, 0.395770, -0.243490, -0.373580, -0.933500, 0.615290, -0.962790, 
1.000740, 0.900110, -0.284820, -0.630210, -0.296310, 0.856680, -0.007580, -0.616680, 0.887290, -0.702990, 
-0.099190, 0.484170, 0.795370, -0.600040, -0.727800, 0.512210, 0.805530, 0.724550, 0.788510, -0.392030, 
0.908660, -0.872880, -0.125410, -0.138620, -0.507150, -0.015570, -0.864580, 0.278010, 0.887280, -0.865280, 

-0.231970, -0.713560, -0.014840, -0.733650, -0.242040, -0.600580, -0.191810, -0.292820, -0.425200, -0.243220, 
-0.139840, -0.462860, -0.992680, 0.339050, -0.228510, 0.734320, -0.673130, -0.649700, -0.101070, -0.833490, 
-0.837820, -0.256150, -0.458400, 0.352150, 0.208750, -0.269340, -0.858250, -0.997620, 0.920380, -0.111550, 
0.333440, -0.120530, -0.476230, 0.642670, -0.175510, 0.509910, 0.318570, 0.630900, 0.336990, 0.850560, 

0.936840, -0.297020, 0.486920, -0.520250, -0.843120, 0.915490, -0.676440, 0.613090, 0.356640, -0.748850, 
0.823870, -0.710960, 0.182680, 0.125170, -0.009490, 0.381110, -0.293380, 0.024080, 0.732030, -0.947810, 
0.844670, 0.233710, 0.340150, 0.932220, 0.267950, -0.418640, -0.315400, 0.778940, 0.543500, -0.117140, 
0.416950, -0.343860, -0.245200, -0.629060, 0.664470, -0.380790, 0.916440, 0.142800, 0.691400, -0.408620, 

0.113330, -0.339590, -0.642860, 0.294730, -0.071100, 0.187220, 0.635400, -0.350570, 0.302200, -0.947550, 
-0.014060, 0.243810, 0.203560, -0.413650, 0.111640, 0.708340, 0.893900, 0.289420, -0.355320, 0.687880, 
0.798180, 0.729100, -0.561860, 0.575160, -0.066610, 0.241050, 0.282190, 0.301800, -0.830350, 0.619150, 
0.558410, 0.325280, -0.599300, 0.108670, -0.350810, -0.629940, 0.664420, 0.824860, -0.956290, 0.962370, 

-0.219550, -0.511160, 0.635250, -0.513190, -0.834990, 0.790160, 0.229300, -0.568960, 0.021530, 0.968820, 
-1.036070, -0.620690, -0.614070, 0.512990, -0.671900, -0.061590, -0.547390, -0.362790, -0.344640, -0.351270, 
-0.464510, 0.371260, -0.760510, 0.926570, 0.740600, 0.633940, -0.514790, -0.400830, 0.680160, -0.694870, 
0.418640, 0.939660, -0.599920, 0.767620, 0.020980, -0.046210, 0.235450, -0.119050, 0.912570, -0.340030, 

0.519870, 0.363680, 0.454530, -1.049180, -0.145410, 0.628520, 0.370870, 0.667650, 0.201400, 0.096790, 
-0.126150, -0.074210, -0.739860, -0.173730, 0.309400, 0.888310, -0.343600, 0.771960, 0.799380, -0.748490, 
-0.160850, 0.318870, 0.976310, -0.320510, -0.447390, 0.925550, -0.099560, -0.975360, -1.017610, -0.027580, 
0.081020, 0.247520, -0.319740, 0.112980, -0.866330, 0.131160, 0.878230, 1.051060, 0.223720, -0.170920, 

0.439340, 0.592890, 0.267270, -0.922470, -0.255780, -0.313210, -0.286570, 0.524560, -0.896810, -0.675460, 
0.021580, 0.755280, 0.547790, -0.910430, -0.376010, -0.411850, 0.226640, -0.765290, -0.066750, -0.348660, 
0.596780, 0.161770, -0.035490, 0.839120, -0.960880, -0.341600, -0.328840, 0.254070, 0.588700, -0.459560, 
-0.129140, -0.446170, -0.927270, -0.826260, 0.330770, -0.948230, 0.176230, -0.786720, -0.395560, 0.791030, 

0.230280, 0.704970, 0.601320, -1.379160, 0.605600, 0.496220, -0.265530, -0.862690, -1.016780, 0.395200, 
-0.856300, -0.192100, 0.417570, -0.454270, 0.360240, 0.063930, 0.339330, 0.816860, 0.704410, -0.126820, 


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
      0.0, -0.322730, 27,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (Old: 29) */
      0.0, -0.028540, 27,
       &Sources[27] , 
       &Weights[27] , 
      },
    { /* unit 30 (Old: 30) */
      0.0, -0.678040, 27,
       &Sources[54] , 
       &Weights[54] , 
      },
    { /* unit 31 (Old: 31) */
      0.0, 0.572260, 27,
       &Sources[81] , 
       &Weights[81] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, -0.880490, 27,
       &Sources[108] , 
       &Weights[108] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.426410, 27,
       &Sources[135] , 
       &Weights[135] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.766990, 27,
       &Sources[162] , 
       &Weights[162] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, -0.160350, 27,
       &Sources[189] , 
       &Weights[189] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, 0.324950, 27,
       &Sources[216] , 
       &Weights[216] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, -0.400490, 27,
       &Sources[243] , 
       &Weights[243] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, -0.862970, 27,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, -0.966320, 27,
       &Sources[297] , 
       &Weights[297] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, -0.925430, 27,
       &Sources[324] , 
       &Weights[324] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, 0.944530, 27,
       &Sources[351] , 
       &Weights[351] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.166900, 27,
       &Sources[378] , 
       &Weights[378] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, -0.882150, 27,
       &Sources[405] , 
       &Weights[405] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.198820, 27,
       &Sources[432] , 
       &Weights[432] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, -1.024750, 27,
       &Sources[459] , 
       &Weights[459] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.895370, 27,
       &Sources[486] , 
       &Weights[486] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.749750, 27,
       &Sources[513] , 
       &Weights[513] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.368430, 27,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.094740, 27,
       &Sources[567] , 
       &Weights[567] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.093770, 27,
       &Sources[594] , 
       &Weights[594] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, 0.345800, 27,
       &Sources[621] , 
       &Weights[621] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, 0.165690, 27,
       &Sources[648] , 
       &Weights[648] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -1.080010, 27,
       &Sources[675] , 
       &Weights[675] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, -0.763690, 27,
       &Sources[702] , 
       &Weights[702] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, 0.533400, 27,
       &Sources[729] , 
       &Weights[729] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, -0.468640, 27,
       &Sources[756] , 
       &Weights[756] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.852940, 27,
       &Sources[783] , 
       &Weights[783] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.838480, 27,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, 0.763060, 27,
       &Sources[837] , 
       &Weights[837] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, -0.034260, 27,
       &Sources[864] , 
       &Weights[864] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, 0.457970, 27,
       &Sources[891] , 
       &Weights[891] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.461240, 27,
       &Sources[918] , 
       &Weights[918] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.971070, 27,
       &Sources[945] , 
       &Weights[945] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, -0.812080, 27,
       &Sources[972] , 
       &Weights[972] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.885310, 27,
       &Sources[999] , 
       &Weights[999] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, -0.514070, 27,
       &Sources[1026] , 
       &Weights[1026] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.352960, 27,
       &Sources[1053] , 
       &Weights[1053] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, -0.959690, 40,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, 0.278940, 40,
       &Sources[1120] , 
       &Weights[1120] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, -0.740390, 40,
       &Sources[1160] , 
       &Weights[1160] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.131480, 40,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, 0.006330, 40,
       &Sources[1240] , 
       &Weights[1240] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.806860, 40,
       &Sources[1280] , 
       &Weights[1280] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.774550, 40,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, -0.886190, 40,
       &Sources[1360] , 
       &Weights[1360] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.731870, 40,
       &Sources[1400] , 
       &Weights[1400] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.558910, 40,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.660130, 40,
       &Sources[1480] , 
       &Weights[1480] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.383180, 40,
       &Sources[1520] , 
       &Weights[1520] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.196970, 40,
       &Sources[1560] , 
       &Weights[1560] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.741160, 40,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, -0.944140, 40,
       &Sources[1640] , 
       &Weights[1640] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.215190, 40,
       &Sources[1680] , 
       &Weights[1680] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.145530, 40,
       &Sources[1720] , 
       &Weights[1720] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, -0.686760, 40,
       &Sources[1760] , 
       &Weights[1760] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.699790, 40,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.144140, 40,
       &Sources[1840] , 
       &Weights[1840] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.009420, 20,
       &Sources[1880] , 
       &Weights[1880] , 
      }

  };



int h(float *in, float *out, int init)
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
