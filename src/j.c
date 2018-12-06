/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  j.c
  --------------------------------------------------------
  generated at Tue Jun 23 14:56:23 1998
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
-0.691990, 0.993500, 0.068150, -0.075750, -0.575020, 0.455260, -0.975490, 0.386430, -0.200550, -0.222890, 
0.562300, -0.778560, 0.381270, 0.696280, 0.317780, 0.224000, -0.288890, -0.511770, -0.206260, -0.063260, 
0.080590, -0.317800, 0.329040, -0.905490, 0.254610, -0.886010, 0.985420, 
0.435720, 0.954990, -0.168800, 0.596400, -0.782170, 0.891240, 0.501400, 0.394340, -0.800440, 0.004840, 
-0.423700, 0.397470, -0.721130, -0.351080, 0.102500, -0.919730, -0.543210, 0.244560, 0.532310, 0.290930, 
0.401240, -0.343180, -0.408910, -0.146950, -0.647050, 0.206150, -0.666550, 
0.608390, -0.888340, 0.169400, -0.023470, 0.844980, -0.812160, -0.730820, -0.522730, 0.196590, -0.366010, 
-0.529070, 0.173190, 0.766850, 0.030730, 0.573230, -0.757510, -0.050200, 1.000050, -0.724870, 0.962610, 
-0.629110, 0.508260, 0.380940, -0.941170, -0.859430, -0.655610, -0.018100, 
-0.145250, 0.422550, 0.357140, 0.479320, 0.663510, 0.997470, 0.910350, 0.517650, 0.169270, -0.403450, 
0.565770, -0.002470, 0.864790, 0.213870, 0.039490, 0.568260, 0.562660, -0.832630, 0.300810, 0.614610, 
0.577500, -0.257900, 0.897560, -0.557250, 0.940480, 0.118030, 0.656010, 
-0.823550, 0.055350, -0.742020, -0.394040, -0.867550, 0.086640, 0.203440, -0.786610, -0.388130, -0.675040, 
-0.487120, -0.312860, -0.357430, -0.154420, 0.458430, -0.871740, -0.323150, 0.903660, 0.252180, -0.236390, 
0.703010, 0.237660, -0.291280, 0.939850, -0.684580, 0.847230, -0.491960, 
-0.797860, 0.245340, 0.335190, 0.535130, -0.312160, 0.442540, 0.482410, 0.498160, -0.885920, 0.712500, 
0.407960, -0.120370, 0.321570, -0.730160, 0.395140, -0.372280, -0.691810, -0.764390, -0.296020, 0.853770, 
-0.799240, 0.440920, -0.286110, -0.734420, -0.710350, 0.278460, -0.499670, 
-0.693400, -0.121380, -0.725200, 0.307840, -0.371680, 0.309380, -0.802690, -0.917420, 0.768480, -0.965650, 
0.893510, -0.204700, 0.919690, 0.247050, -0.063280, 0.431570, -0.126040, -0.210740, -0.626250, 0.106930, 
0.945200, 0.059850, 0.410950, 0.425100, 0.609820, 0.965680, -0.647160, 
0.769030, -0.463690, 0.777770, 0.563120, -0.914710, -0.462560, -0.609930, -0.652260, 0.486230, 0.496880, 
0.323980, 0.193290, -0.042630, 0.467180, 0.214050, -0.742270, 0.926260, 0.410220, 0.202770, -0.120000, 
0.379100, -0.644790, 0.080710, 0.809970, 0.492260, -0.846920, -0.983750, 
-0.762000, 0.513380, 0.222020, -0.523260, 0.122350, -0.832050, 0.079180, -0.131850, -0.923390, 0.269040, 
0.142870, 0.695500, 0.547540, 0.325650, 0.056470, 0.912750, -0.397050, 0.875370, -0.088320, 0.367660, 
0.461540, 0.004350, 0.830040, -0.913700, -0.489710, -0.586780, 0.750650, 
-0.455220, -0.681880, -0.228330, -0.904100, 0.052640, -0.050690, 0.961380, -0.215220, 0.899180, -0.180410, 
0.205190, -0.820820, 0.341140, 0.378330, -0.702270, -0.456430, 0.814250, 0.315770, 0.194140, -0.970330, 
-0.259030, -0.653440, 0.143280, -0.575270, 0.888190, 0.735320, -0.085500, 
-0.798520, 0.218810, 0.187850, -0.695830, 0.409740, 0.807790, -0.114980, -0.555200, 0.711010, -0.605310, 
-0.491720, 0.162860, 0.064420, 0.311080, 0.177140, 0.945490, -0.030540, -0.432980, 0.524500, -0.389730, 
-0.559190, -0.521030, 0.776120, 0.257280, -0.830290, -0.562850, 0.383670, 
0.141960, 0.926270, -0.199910, 0.957510, -0.522720, 0.720660, 0.239850, 0.565010, -0.158130, 0.586810, 
-0.595100, -0.515000, 0.081430, 0.429460, -0.696600, 0.096690, -0.672980, 0.134420, 0.337380, -0.901740, 
0.501200, 0.265350, 0.146100, -0.015850, -0.782060, -0.118180, -0.373300, 
0.630520, -0.130760, 0.937350, 0.577220, 0.670650, -0.111700, 0.592970, 0.577430, 0.863140, 0.617850, 
-0.824180, -0.586650, 0.387830, 0.155980, -0.968280, -0.599780, 0.219070, 0.631350, 0.547530, -0.474770, 
-0.068000, -0.350610, 0.584680, 0.039770, -0.146850, 0.819570, 0.447170, 
-0.168020, -0.769510, 0.876940, 0.883240, 0.448550, 0.399640, -0.759270, 0.731850, -0.909130, 0.148180, 
0.832600, -0.600310, 0.125190, 0.157640, -0.377380, 0.610920, 0.750360, 0.503550, -0.324150, 0.724990, 
0.355280, -0.656170, 0.989340, -0.874330, 0.249100, -0.189160, 0.431940, 
-0.350980, -0.506750, 0.633700, 0.714550, 0.681270, 0.380980, -0.772950, 0.442250, -0.367390, -0.695780, 
-0.652260, 0.929470, 0.840900, 0.138040, -0.513190, 0.686300, 0.137840, 0.794630, -0.516440, -0.283570, 
-0.471310, -0.117130, 0.757640, -0.478060, -0.098260, -0.013670, 0.463140, 
0.144750, 0.011790, -0.420950, 0.454180, -0.647910, -0.780700, 0.949510, 0.785800, 0.456290, -0.975370, 
0.249590, -0.632720, -0.721430, 0.421170, -1.000590, 0.964760, 0.847640, -0.935190, -0.365110, 0.396890, 
-0.451080, -0.875340, -0.332130, -0.858310, -0.098790, -0.947820, 0.534200, 
-0.168460, -0.558320, 0.629480, -0.761640, 0.771500, -0.817100, -0.466580, 0.040520, -0.122520, 0.993270, 
0.282490, 0.236080, -0.438540, -0.087610, -0.338850, -0.159220, 0.475340, 0.785570, 0.400140, -0.057540, 
-0.808500, 0.175340, -0.843680, 0.576560, 0.006570, -0.248440, 0.606140, 
-0.097370, 0.677480, -0.025760, 0.657080, 0.416670, 0.389890, 0.811580, -0.245170, 0.559920, -0.848680, 
-0.276740, 0.489220, 0.090220, -0.685450, 0.158830, 0.734240, -0.790110, -0.343110, 0.655300, -0.560050, 
-0.415800, 0.597640, -0.528560, 0.523250, 0.551320, -0.408230, -1.047450, 
-0.573860, -0.595700, -0.987730, -0.402640, -0.280860, 0.754990, -0.404150, 0.689210, 0.356080, 0.082300, 
0.206380, 0.035310, -0.702680, -0.649800, -0.157900, -0.365450, 0.700990, -0.694360, -0.393580, 0.584900, 
0.865420, 0.151070, -0.694440, 0.433810, 0.304940, -0.053080, 0.988560, 
0.648760, -0.933940, -0.472310, 0.098090, -0.590870, -0.002660, 0.308300, 0.692810, -0.467910, 0.085500, 
0.295610, -0.218330, -0.893730, 0.724230, -0.542960, 0.912570, -0.181130, -0.316730, 0.983140, -0.933610, 
0.326620, -0.693000, -0.238580, 0.973890, -0.715790, -0.016170, 0.545770, 
-0.652050, 0.872250, -0.503770, -0.213290, -0.881690, 0.309180, 0.626440, 0.348800, -0.107940, -0.739570, 
-0.896740, 0.947030, 0.212950, -0.533630, -0.315680, -0.759830, -0.582200, -0.126850, -0.172770, -0.151140, 
-0.146030, 0.438090, -0.500530, 0.158110, -0.578300, 0.935310, 0.619160, 
-0.919440, -0.841990, 0.792830, -0.604780, 0.340800, -0.708600, 0.887420, 0.240180, 0.669730, 0.189040, 
0.676810, 0.348890, 0.029490, -0.289880, 0.750320, -0.278250, -0.507410, -0.783410, -0.790140, 0.810480, 
-0.758520, 0.189970, 0.953030, -0.563130, -0.041280, 0.781980, 0.857130, 
0.866130, -0.556640, 0.675380, 0.169850, 0.962070, -0.644260, -0.294940, 0.687250, -0.212240, -0.119830, 
-0.765340, 0.065690, 0.315270, 0.768170, 0.820490, 0.048770, 0.722880, -0.333740, -0.370860, 0.996280, 
0.438590, 0.436460, -0.580120, -0.932340, 0.693400, 0.316190, 0.096720, 
-0.874920, 0.221040, 0.724110, -0.090680, -0.907810, 0.441290, 0.166220, 0.551170, 0.113560, -0.382740, 
-0.122960, -0.943540, -0.776380, 0.207820, 0.061360, -0.267810, 0.221210, -0.227440, -0.441130, 0.511750, 
-0.750860, 0.501300, 0.334870, -0.146560, 0.637450, 0.371870, 0.845210, 
-0.272960, -0.303970, 0.482600, 0.074120, 0.892950, 0.619910, 0.516140, 0.480280, -0.695330, -0.496430, 
0.564710, -0.445160, -0.086250, -0.550940, -0.365790, 0.049970, -0.648330, 0.780040, -0.612400, -0.730370, 
-0.605920, -0.565040, 0.021160, 0.559650, -0.722680, -0.270030, -0.998080, 
0.416050, 0.076970, 0.091460, -0.926030, -0.078890, -0.532160, -0.384350, 0.124350, 0.134500, 0.966530, 
0.623240, -0.193980, 0.750540, 0.919930, -0.183690, 0.395060, -0.698600, -0.088510, 0.297850, -0.606920, 
0.337370, -0.145920, -0.317170, 0.902350, -0.207240, -0.440690, -0.628670, 
-0.769800, 0.682070, 0.842070, -0.074300, -0.412620, -0.944520, 0.056390, 0.211810, -0.485590, -0.945590, 
0.864700, 1.003250, -0.187870, -0.994420, -0.178200, -0.413420, 0.839750, -0.157220, -0.367540, 0.083900, 
0.123980, -0.500200, 0.470310, 0.332650, 0.211230, 0.146630, 0.208550, 
0.787520, -0.958180, -0.661600, -0.828720, 0.059270, -0.348290, 0.483380, -0.132090, -0.902040, -0.784290, 
-0.871230, -0.734410, 0.270910, 0.700130, 0.502900, 0.954210, -0.204120, -0.449020, -0.152310, -0.267940, 
-0.407430, 0.121260, 0.346310, 0.077500, 0.179700, -0.149470, 0.200950, 
-0.989170, 0.268070, 0.948620, -0.330660, -0.220490, -0.962010, 0.057020, 0.564530, -0.644370, -0.026380, 
0.894710, -0.320100, 0.272720, 0.072430, 0.001510, 0.105670, -0.267000, -0.153820, 0.682200, -0.453270, 
0.878700, -0.701260, 0.739930, 0.479620, -0.189110, 0.173850, 0.142670, 
-0.336520, -0.833760, 0.663270, 1.000840, -0.253680, 0.465910, -0.305210, 0.088910, 0.544460, 0.943640, 
0.872130, 0.648360, 0.490930, -0.768160, -0.159580, -0.371690, -0.494580, -0.240870, -0.053680, -0.861860, 
-0.721230, -0.728180, -0.727290, 0.395910, -0.104160, -0.899140, -0.484480, 
0.385390, -0.100630, -0.035170, -0.568170, -0.310210, 0.641050, -0.285730, -0.120680, 0.512840, 0.521690, 
-0.606850, 0.802940, -0.246030, 0.550010, -0.043550, 0.626900, 0.418950, -0.311760, -0.278920, -0.587970, 
-0.697790, 0.724370, -0.926410, 0.335850, -0.584880, -0.610340, -0.301310, 
-0.315540, -0.188960, -0.880640, 0.142500, -0.729520, -0.408110, -1.025050, -0.984720, 0.194790, 0.920300, 
-0.847720, -0.348520, -0.531010, 0.363950, -0.345090, -0.483300, 0.619960, 0.012010, -0.446670, 0.523750, 
0.988350, -0.180230, 0.080760, 0.856180, -0.260580, 0.841260, 0.671300, 
-0.727290, 0.061890, 0.480270, 0.595090, -0.054730, 0.150380, 0.803030, 0.613320, -0.892170, 0.349990, 
0.489340, -0.434120, -0.101170, -0.559460, 0.748780, 0.905260, -0.403980, 0.657320, 0.030040, -0.820750, 
0.839790, 0.682060, -0.081460, 0.419620, -0.111640, 0.600960, 0.972610, 
-0.147340, 0.518290, 0.767960, 0.330060, 0.705240, 0.565660, -0.255690, -0.057970, -0.628900, 0.377180, 
0.920300, 0.978870, -0.548300, 0.088820, -0.321860, 0.451240, -0.276710, -0.140120, -0.529540, 0.496810, 
-0.492990, 0.038310, -0.738830, 0.438230, 0.378200, -0.473760, -0.106790, 
-0.271380, -0.284180, 0.502110, 0.919700, -0.636540, 0.384820, 0.141730, 0.340190, -0.763640, -0.867250, 
-0.623820, 0.298580, 0.397400, -0.787090, -0.793970, 0.601350, 0.685170, -0.849520, 0.120320, 0.220960, 
0.004230, 0.496930, -1.046920, -0.545140, 0.242910, 0.764110, -0.856710, 
0.703330, 0.535880, -0.376530, 0.864120, 0.866440, -0.048480, 0.329740, 0.137970, 0.642400, 0.469950, 
0.044100, 0.014970, -0.666130, 0.833780, -0.594770, 0.230860, 0.965420, -0.832600, -0.638400, -0.897460, 
0.803040, -0.259510, 0.221200, 0.108010, -0.667600, 0.884250, -0.461530, 
0.775230, 0.248160, -0.513740, -0.350170, -0.377840, -0.492740, -0.361930, 0.912280, -0.011690, -0.543220, 
0.551060, 0.880030, 0.895190, 0.983840, -0.889730, -0.774580, 0.330420, 0.629060, 0.635320, 0.553300, 
-0.601360, 0.982790, 0.950380, 0.259070, 0.232090, 0.510040, 0.095390, 
-0.602150, 0.723870, -0.964240, -0.870630, 0.355920, -0.158940, 0.103420, 0.256610, -0.844770, -0.097410, 
0.537600, -0.425350, 0.671970, 0.484840, 0.398600, -0.874550, 0.440760, 0.267310, 0.729000, 0.606920, 
-0.959370, -0.955120, 0.044100, 0.217390, 0.039050, 0.351330, -0.015100, 
-0.798670, -0.610050, 0.559760, -0.705220, 1.009630, -0.222020, 0.419580, 0.042970, 0.439190, 0.995880, 
0.015680, -0.949140, -0.511830, 0.331330, 0.931790, -0.530910, -0.338510, -0.055990, -0.738530, 0.159260, 
-0.553890, -0.334690, 0.234420, 0.783820, 0.776940, -0.845360, -0.968890, 
0.257850, -0.051870, 0.518400, -0.195740, -0.666280, -0.592620, 0.563790, 0.164850, 0.333320, -0.218610, 
-0.301250, -0.739020, -0.328700, 0.372410, 0.761580, 0.285660, -0.344610, 0.674390, -0.336160, 0.339580, 
0.830920, 0.449750, 0.777100, -0.689010, 0.434680, 0.585530, -0.687810, 
-0.989140, -0.453350, -0.767300, 0.652480, -0.249000, -0.451830, 0.870790, 0.785830, -0.515950, 0.587200, 
0.682720, 0.038180, 0.820670, -0.835850, 0.755060, -0.608530, -0.903070, -0.621810, 0.472960, -0.382170, 
0.320740, 0.138520, 0.940640, 0.122700, -0.372920, 0.631980, 0.716370, 0.513090, -0.612070, 0.438130, 
-0.695230, 0.067060, -0.032060, -0.428870, 0.096320, -0.160770, -0.542550, -0.482100, -0.476060, 0.768040, 

-0.702210, -0.413020, -0.245270, 0.258070, 0.316930, -0.921800, 0.478080, -0.132550, -0.341330, -0.725900, 
-0.323760, -0.166930, -0.172610, -0.915010, 0.945250, 0.406100, -0.743770, -0.393260, 0.264720, -0.732710, 
-0.824670, 0.828990, 0.014700, -0.925680, -0.286080, -0.203310, 0.716130, 0.990550, 0.550500, 0.555200, 
-0.405830, 0.586230, -0.708300, -0.442360, -0.761720, 0.397280, 0.867040, -0.469200, 0.312640, -1.038080, 

0.798370, 0.299680, -0.414970, -0.650120, 0.498490, 0.883820, 0.339780, 0.864380, 0.132010, 0.190540, 
0.645500, 0.519950, 0.806140, -0.687920, 0.888640, 0.786200, -0.417780, -0.758780, -0.679710, 0.710360, 
-0.256940, 0.206580, -0.051800, -0.024700, -0.868750, -0.049690, -0.629480, -0.155300, 0.653430, 0.701770, 
0.178220, -0.505670, -0.463820, -0.996440, 0.588170, 0.102060, -0.883820, -0.208260, -0.897240, 0.863190, 

0.021950, 0.457040, -0.019230, -0.104740, 0.773310, 0.740000, -0.342150, 0.248380, 0.154720, 0.202720, 
0.216680, -0.435320, 0.273790, -0.875630, -0.840720, 0.380040, -0.061420, 0.871160, 0.679290, 0.844550, 
-0.372310, 0.489370, 0.697580, -0.735320, -0.961830, 0.693150, -0.345620, -0.551880, 0.612220, -0.311880, 
-0.781200, 0.668380, 0.506350, 0.732670, 0.891920, 0.610290, 0.776810, -0.572320, 0.336440, -0.955770, 

0.775110, 0.284260, -0.979000, 0.511140, 0.530540, 0.109070, 0.802090, 0.047110, -0.039660, -0.423000, 
-0.212120, -0.396850, -0.594900, 0.695240, -0.202160, -0.152300, -0.654180, -0.056840, 0.631790, 0.671400, 
-0.082290, 0.934060, 0.136450, 0.922340, -0.703080, 0.663360, -0.510190, 0.664720, 0.669880, 0.031380, 
-0.789090, 0.231360, 0.730790, -0.403320, 0.869540, 0.480660, 0.550360, -0.253840, -0.209390, -0.571370, 

-0.391490, -0.760610, 0.019520, -0.783200, -0.513760, -0.812740, 0.891110, -0.197530, 0.540370, -0.003400, 
0.360010, -0.625550, -0.664240, 0.017960, -0.897330, -0.218360, -0.730550, -0.369900, 0.824670, 0.782230, 
1.015670, 0.246710, 0.408600, -0.934010, 0.242320, 0.812370, -0.460600, 0.158900, -0.801740, -0.528510, 
0.588130, 0.833760, 0.716960, 0.656850, -0.421400, 0.644570, -0.335530, -0.192520, -0.530790, -0.644660, 

0.836890, 0.329800, 0.446830, 0.091950, 0.756960, 0.785090, 0.188850, 0.540570, 0.982780, -0.833460, 
0.832480, 0.872560, 0.347240, 0.827620, -0.663550, -0.045890, 0.623100, -0.406170, -0.899980, 0.889570, 
0.765770, 0.412340, -0.697580, -0.000790, 0.411790, 0.771210, -0.770630, 0.193380, -0.913590, -0.475870, 
0.007380, -0.411070, -0.329750, -0.192850, 0.593650, 0.561450, 0.445150, -0.943870, -0.490890, -0.144140, 

0.630800, 0.191170, 0.365890, -0.372050, 0.248840, -0.296550, -0.757570, -0.708730, 0.173320, -0.778580, 
0.275010, -0.500620, -0.591020, -0.415760, -0.991890, -0.703400, -0.662610, -0.876890, -0.249020, 0.174810, 
-0.070600, -0.634320, 0.328810, -0.762550, 0.174160, -0.834530, 0.337220, 0.658850, -0.080190, 0.578300, 
0.688070, -0.042800, -0.289350, -0.421570, -0.934570, -0.254610, 0.611200, 0.606730, -0.652110, -0.120180, 

-0.511960, 0.313480, 0.742710, 0.191680, -0.901180, -0.735670, 0.985230, 0.046950, -0.309860, -0.807300, 
-0.640110, 0.840820, 0.729870, 0.936680, -0.991810, 0.304880, -0.351330, 0.972690, 0.738130, 0.120470, 
-0.574500, 0.026960, 0.838890, -0.006620, -0.661730, 0.831190, 0.123900, 0.759240, 0.876560, 0.918520, 
0.243530, -0.095450, -0.143830, 0.568020, -0.579460, -0.224520, 0.774050, 0.133460, 0.554460, -0.107350, 

-0.809660, -0.025680, -0.404760, 0.994800, -0.860610, 0.366270, -0.885140, -0.053810, 0.287230, -0.958730, 
-0.273010, 0.190680, -0.458690, -0.589400, -0.663450, 0.282990, -0.480020, 0.475930, -0.824740, 0.764110, 
-0.852680, -0.001030, -0.837010, -0.978780, 0.650200, -0.685800, 0.293290, -0.878520, -0.507740, 0.346840, 
0.883690, 0.778750, -0.081240, 0.069060, -0.631030, -0.884090, -0.611170, 0.011380, -0.504180, 0.125560, 

0.677730, 0.334060, 0.957220, 0.609500, -0.908100, -0.160570, 0.917570, 0.062800, 0.305640, 0.071980, 
0.453140, 0.227110, 0.858520, 0.518350, 0.984030, 0.706710, 0.213060, 0.695170, 0.426170, 0.718080, 
0.024850, 0.827720, 0.237760, -0.704720, 0.535710, 0.589970, -0.637130, 0.363580, 0.226290, -0.018240, 
0.632570, -0.396490, 0.513760, 0.333560, -0.705650, -0.357750, 0.277430, -0.737420, -0.546930, -0.157850, 

0.053340, 0.808220, -0.166250, -0.531690, 0.438950, -0.526410, 0.088930, -0.529060, -0.978950, 0.280530, 
0.087540, -0.497710, -0.707100, -0.739590, -0.702520, 0.732380, 0.587670, 0.544860, 0.357400, 0.848720, 
-0.597480, -0.304290, 0.080580, 0.383910, -0.202310, 0.374270, 0.977470, 0.080430, -0.692970, 0.103820, 
-0.441050, -0.754360, 0.372690, -0.192870, -0.897140, -0.494040, -0.961490, -0.975630, 1.030930, -0.465020, 

-0.885330, 1.010070, 0.204710, -0.219040, 0.590440, -0.851330, 0.605110, 0.375830, 0.167810, -0.532760, 
0.411140, -0.465540, -0.963980, -0.541870, -0.539010, 0.146350, 0.859530, 0.246070, -0.297350, -0.648640, 
0.421020, 0.441260, -0.208410, -0.265150, -0.659550, 0.457050, 0.308850, 0.248450, 0.359910, 0.487870, 
0.193830, -0.227730, -0.735510, 0.134250, -0.299560, -0.816600, -0.630890, -0.153320, 0.499720, 0.823670, 

-0.895130, 0.902280, 0.296790, -0.898930, -0.015100, -0.516650, -0.151700, -0.088760, -0.850780, 0.868530, 
-0.425090, 0.791060, 0.667940, 0.826340, 0.444290, -0.702120, -0.690410, 0.803400, 0.397170, -0.169130, 
-0.789210, 0.896880, -0.687920, 0.039170, 0.877460, -0.352400, -0.638430, -0.270110, 0.921630, 0.950210, 
-1.015850, 0.514600, -0.975630, -0.445230, -0.238510, 0.383610, 0.049560, -0.050650, 0.763910, 0.576590, 

0.850590, 0.334530, 0.626500, 0.316300, 0.509220, -0.171140, 0.639850, -0.481900, -0.126410, 0.337010, 
-0.111220, 0.918240, -0.994400, -0.862160, -0.269190, 0.206760, 0.352010, -0.460270, -0.253000, -0.837450, 
-0.831850, -0.103940, -0.645410, -0.677040, 0.732960, -0.228210, 0.336100, -0.996980, -0.465180, -0.139230, 
-0.244860, -0.423690, -0.294310, -0.191620, -0.600380, -0.243560, -0.734920, -0.016460, -0.718640, -0.236230, 

-0.416460, 0.678590, 0.155640, 0.904880, -0.387470, 0.609770, -0.636670, -0.306560, -0.344660, 0.389080, 
-0.105160, 0.525730, 0.783710, -0.335260, -0.404800, 0.256270, 0.977260, 0.293860, 0.254780, 0.898610, 
-0.916980, 0.732880, 0.039930, -0.321120, 0.342920, 0.003390, 0.112980, 0.198920, -0.725400, 0.790900, 
-0.743500, 0.409440, 0.610310, -0.680960, 0.875720, -0.825610, -0.497930, 0.479970, -0.377800, 0.904170, 

0.974150, -0.953990, 0.802220, 0.709420, -0.632460, -0.268810, 0.150130, -0.597850, 0.338740, 0.597330, 
0.643340, -0.821900, 0.346380, 0.326620, 0.284620, -0.068820, 0.572380, -0.522430, 0.744000, 0.795580, 
0.710310, -0.309440, 0.318900, 0.925830, 0.759600, 0.115920, -0.391110, 0.209620, 0.267340, 0.005040, 
-0.925610, 0.297470, -0.291680, 0.689760, 0.219420, -0.046520, 0.331270, -0.645230, -0.330450, 0.114980, 

-0.306610, 0.877700, -0.152100, 0.296450, -0.016330, 0.074190, 0.804330, -0.661690, 0.921470, 0.480300, 
-0.660160, 0.671570, -0.328950, -0.508240, 0.708670, 0.711470, 1.024370, -0.759630, 0.469720, -0.366410, 
-0.291880, -0.343160, -0.241150, -0.598810, -0.071910, -0.595560, 0.521720, -0.610490, -0.617360, -0.993960, 
1.010740, 0.159830, -0.531510, 0.328270, 0.797440, -0.803980, -0.417990, 0.626740, -0.598900, -0.270000, 

-0.107610, 0.206680, 0.989000, 0.913620, 0.136720, -0.753370, 0.121410, -0.327900, 0.231900, 0.179710, 
-0.007090, -0.989340, -0.901280, -0.103600, 0.970100, -0.453130, -0.314500, 0.995880, 0.370370, -0.169640, 
-0.684520, 0.795970, 0.832920, -0.343180, 0.898030, 0.355440, -0.146590, -0.769070, -0.072080, -0.065470, 
0.107730, 0.252920, 0.738740, 0.463110, 0.659410, -0.147990, -0.996970, 0.458350, 0.332610, 0.497030, 

0.780240, -0.400790, -0.786610, 0.127820, -0.952000, 0.292960, -0.863750, -0.949790, -0.470540, -0.157620, 
-0.467690, 0.574020, 0.216930, -0.373390, -0.363400, -0.966460, 0.818560, -0.068250, 0.153950, 0.586640, 
-0.346310, -0.106790, -0.794680, 0.191550, -0.445480, -0.390060, -0.929520, 0.518820, 0.726020, 0.008290, 
-0.695450, -0.908800, 0.478560, -0.330870, -0.336630, -0.293080, -0.950000, 0.257480, 0.554370, 0.411500, 

-0.200140, 0.987520, 0.678640, 0.413220, 0.052090, 0.948520, -0.656820, -0.145760, -0.590810, -0.545090, 
0.030880, -0.740720, -0.841030, -0.747320, 0.560510, 0.443520, -1.295250, 0.946730, 0.101190, 0.572260, 


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
      0.0, -0.338410, 27,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (Old: 29) */
      0.0, -0.048240, 27,
       &Sources[27] , 
       &Weights[27] , 
      },
    { /* unit 30 (Old: 30) */
      0.0, -0.697720, 27,
       &Sources[54] , 
       &Weights[54] , 
      },
    { /* unit 31 (Old: 31) */
      0.0, 0.569300, 27,
       &Sources[81] , 
       &Weights[81] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, -0.873130, 27,
       &Sources[108] , 
       &Weights[108] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.437380, 27,
       &Sources[135] , 
       &Weights[135] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.792120, 27,
       &Sources[162] , 
       &Weights[162] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, -0.154080, 27,
       &Sources[189] , 
       &Weights[189] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, 0.351770, 27,
       &Sources[216] , 
       &Weights[216] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, -0.402860, 27,
       &Sources[243] , 
       &Weights[243] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, -0.862590, 27,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, -0.989070, 27,
       &Sources[297] , 
       &Weights[297] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, -0.958100, 27,
       &Sources[324] , 
       &Weights[324] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, 0.938460, 27,
       &Sources[351] , 
       &Weights[351] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.159170, 27,
       &Sources[378] , 
       &Weights[378] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, -0.921420, 27,
       &Sources[405] , 
       &Weights[405] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.204130, 27,
       &Sources[432] , 
       &Weights[432] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, -1.004880, 27,
       &Sources[459] , 
       &Weights[459] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.848330, 27,
       &Sources[486] , 
       &Weights[486] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.758790, 27,
       &Sources[513] , 
       &Weights[513] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.344120, 27,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.090680, 27,
       &Sources[567] , 
       &Weights[567] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.092740, 27,
       &Sources[594] , 
       &Weights[594] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, 0.287490, 27,
       &Sources[621] , 
       &Weights[621] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, 0.197540, 27,
       &Sources[648] , 
       &Weights[648] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.977600, 27,
       &Sources[675] , 
       &Weights[675] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, -0.822200, 27,
       &Sources[702] , 
       &Weights[702] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, 0.484020, 27,
       &Sources[729] , 
       &Weights[729] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, -0.535140, 27,
       &Sources[756] , 
       &Weights[756] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.850560, 27,
       &Sources[783] , 
       &Weights[783] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.849570, 27,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, 0.838970, 27,
       &Sources[837] , 
       &Weights[837] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, 0.001140, 27,
       &Sources[864] , 
       &Weights[864] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, 0.495600, 27,
       &Sources[891] , 
       &Weights[891] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.401380, 27,
       &Sources[918] , 
       &Weights[918] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.940480, 27,
       &Sources[945] , 
       &Weights[945] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, -0.776780, 27,
       &Sources[972] , 
       &Weights[972] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.896850, 27,
       &Sources[999] , 
       &Weights[999] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, -0.439570, 27,
       &Sources[1026] , 
       &Weights[1026] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.298470, 27,
       &Sources[1053] , 
       &Weights[1053] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, -0.880520, 40,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, 0.281130, 40,
       &Sources[1120] , 
       &Weights[1120] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, -0.760920, 40,
       &Sources[1160] , 
       &Weights[1160] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.188150, 40,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, 0.025150, 40,
       &Sources[1240] , 
       &Weights[1240] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.744890, 40,
       &Sources[1280] , 
       &Weights[1280] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.780960, 40,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, -0.886880, 40,
       &Sources[1360] , 
       &Weights[1360] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.764590, 40,
       &Sources[1400] , 
       &Weights[1400] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.557860, 40,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.661680, 40,
       &Sources[1480] , 
       &Weights[1480] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.391450, 40,
       &Sources[1520] , 
       &Weights[1520] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.210100, 40,
       &Sources[1560] , 
       &Weights[1560] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.685060, 40,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, -0.945820, 40,
       &Sources[1640] , 
       &Weights[1640] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.211090, 40,
       &Sources[1680] , 
       &Weights[1680] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.192840, 40,
       &Sources[1720] , 
       &Weights[1720] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, -0.605210, 40,
       &Sources[1760] , 
       &Weights[1760] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.755660, 40,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.191990, 40,
       &Sources[1840] , 
       &Weights[1840] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, -0.057050, 20,
       &Sources[1880] , 
       &Weights[1880] , 
      }

  };



int j(float *in, float *out, int init)
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
