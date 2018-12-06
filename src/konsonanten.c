/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

/*********************************************************
  konsonanten.c
  --------------------------------------------------------
  generated at Fri Jun  5 13:09:45 1998
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
  static UnitType Units[99];
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
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, 
Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, 
Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, 
Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, 
Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, 

Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, 
Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, 


  };

  /* Weigths definition section */
  static float Weights[] =  {
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
0.225810, -0.051360, -0.277750, -0.023380, -0.126130, 0.058570, -0.165640, -0.063960, -0.115350, 0.048580, 
0.026870, 0.203350, 0.186080, -0.445840, -0.109830, -0.291740, 0.021390, -0.117960, -0.239980, -0.035380, 
0.028810, -0.053850, 0.043230, -0.103900, -0.151300, 0.018520, -0.046440, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 
-0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, -0.070410, 

-0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, 
-0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, -0.652990, 


  };

  /* unit definition section (see also UnitType) */
  static UnitType Units[99] = 
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (Old: 1) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (Old: 2) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (Old: 3) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (Old: 4) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (Old: 5) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (Old: 6) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (Old: 7) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 8 (Old: 8) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 9 (Old: 9) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 10 (Old: 10) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 11 (Old: 11) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 12 (Old: 12) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 13 (Old: 13) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 14 (Old: 14) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 15 (Old: 15) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 16 (Old: 16) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 17 (Old: 17) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 18 (Old: 18) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 19 (Old: 19) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 20 (Old: 20) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 21 (Old: 21) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 22 (Old: 22) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 23 (Old: 23) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 24 (Old: 24) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 25 (Old: 25) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 26 (Old: 26) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 27 (Old: 27) */
      0.0, 0.000000, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 28 (Old: 28) */
      0.0, -0.232580, 27,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (Old: 29) */
      0.0, -0.232580, 27,
       &Sources[27] , 
       &Weights[27] , 
      },
    { /* unit 30 (Old: 30) */
      0.0, -0.232580, 27,
       &Sources[54] , 
       &Weights[54] , 
      },
    { /* unit 31 (Old: 31) */
      0.0, -0.232580, 27,
       &Sources[81] , 
       &Weights[81] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, -0.232580, 27,
       &Sources[108] , 
       &Weights[108] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, -0.232580, 27,
       &Sources[135] , 
       &Weights[135] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, -0.232580, 27,
       &Sources[162] , 
       &Weights[162] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, -0.232580, 27,
       &Sources[189] , 
       &Weights[189] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, -0.232580, 27,
       &Sources[216] , 
       &Weights[216] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, -0.232580, 27,
       &Sources[243] , 
       &Weights[243] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, -0.232580, 27,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, -0.232580, 27,
       &Sources[297] , 
       &Weights[297] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, -0.232580, 27,
       &Sources[324] , 
       &Weights[324] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, -0.232580, 27,
       &Sources[351] , 
       &Weights[351] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, -0.232580, 27,
       &Sources[378] , 
       &Weights[378] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, -0.232580, 27,
       &Sources[405] , 
       &Weights[405] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, -0.232580, 27,
       &Sources[432] , 
       &Weights[432] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, -0.232580, 27,
       &Sources[459] , 
       &Weights[459] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.232580, 27,
       &Sources[486] , 
       &Weights[486] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.232580, 27,
       &Sources[513] , 
       &Weights[513] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.232580, 27,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.232580, 27,
       &Sources[567] , 
       &Weights[567] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.232580, 27,
       &Sources[594] , 
       &Weights[594] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, -0.232580, 27,
       &Sources[621] , 
       &Weights[621] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, -0.232580, 27,
       &Sources[648] , 
       &Weights[648] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -0.232580, 27,
       &Sources[675] , 
       &Weights[675] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, -0.232580, 27,
       &Sources[702] , 
       &Weights[702] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, -0.232580, 27,
       &Sources[729] , 
       &Weights[729] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, -0.232580, 27,
       &Sources[756] , 
       &Weights[756] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.232580, 27,
       &Sources[783] , 
       &Weights[783] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, -0.232580, 27,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, -0.232580, 27,
       &Sources[837] , 
       &Weights[837] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, -0.232580, 27,
       &Sources[864] , 
       &Weights[864] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, -0.232580, 27,
       &Sources[891] , 
       &Weights[891] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, -0.232580, 27,
       &Sources[918] , 
       &Weights[918] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.232580, 27,
       &Sources[945] , 
       &Weights[945] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, -0.232580, 27,
       &Sources[972] , 
       &Weights[972] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.232580, 27,
       &Sources[999] , 
       &Weights[999] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, -0.232580, 27,
       &Sources[1026] , 
       &Weights[1026] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.232580, 27,
       &Sources[1053] , 
       &Weights[1053] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, -0.232580, 27,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, -0.232580, 27,
       &Sources[1107] , 
       &Weights[1107] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, -0.232580, 27,
       &Sources[1134] , 
       &Weights[1134] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, -0.232580, 27,
       &Sources[1161] , 
       &Weights[1161] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, -0.232580, 27,
       &Sources[1188] , 
       &Weights[1188] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.232580, 27,
       &Sources[1215] , 
       &Weights[1215] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, -0.232580, 27,
       &Sources[1242] , 
       &Weights[1242] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, -0.232580, 27,
       &Sources[1269] , 
       &Weights[1269] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.232580, 27,
       &Sources[1296] , 
       &Weights[1296] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.232580, 27,
       &Sources[1323] , 
       &Weights[1323] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.165960, 50,
       &Sources[1350] , 
       &Weights[1350] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.165960, 50,
       &Sources[1400] , 
       &Weights[1400] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, 0.165960, 50,
       &Sources[1450] , 
       &Weights[1450] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.165960, 50,
       &Sources[1500] , 
       &Weights[1500] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, 0.165960, 50,
       &Sources[1550] , 
       &Weights[1550] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.165960, 50,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.165960, 50,
       &Sources[1650] , 
       &Weights[1650] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, 0.165960, 50,
       &Sources[1700] , 
       &Weights[1700] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.165960, 50,
       &Sources[1750] , 
       &Weights[1750] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, 0.165960, 50,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, 0.165960, 50,
       &Sources[1850] , 
       &Weights[1850] , 
      },
    { /* unit 89 (Old: 89) */
      0.0, 0.165960, 50,
       &Sources[1900] , 
       &Weights[1900] , 
      },
    { /* unit 90 (Old: 90) */
      0.0, 0.165960, 50,
       &Sources[1950] , 
       &Weights[1950] , 
      },
    { /* unit 91 (Old: 91) */
      0.0, 0.165960, 50,
       &Sources[2000] , 
       &Weights[2000] , 
      },
    { /* unit 92 (Old: 92) */
      0.0, 0.165960, 50,
       &Sources[2050] , 
       &Weights[2050] , 
      },
    { /* unit 93 (Old: 93) */
      0.0, 0.165960, 50,
       &Sources[2100] , 
       &Weights[2100] , 
      },
    { /* unit 94 (Old: 94) */
      0.0, 0.165960, 50,
       &Sources[2150] , 
       &Weights[2150] , 
      },
    { /* unit 95 (Old: 95) */
      0.0, 0.165960, 50,
       &Sources[2200] , 
       &Weights[2200] , 
      },
    { /* unit 96 (Old: 96) */
      0.0, 0.165960, 50,
       &Sources[2250] , 
       &Weights[2250] , 
      },
    { /* unit 97 (Old: 97) */
      0.0, 0.165960, 50,
       &Sources[2300] , 
       &Weights[2300] , 
      },
    { /* unit 98 (Old: 98) */
      0.0, 2.423810, 20,
       &Sources[2350] , 
       &Weights[2350] , 
      }

  };



int konsonanten(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[27] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27}; /* members */

  static pUnit Hidden1[50] = {Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77}; /* members */

  static pUnit Hidden2[20] = {Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97}; /* members */

  static pUnit Output1[1] = {Units + 98}; /* members */

  static int Output[1] = {98};

  for(member = 0; member < 27; member++) {
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
