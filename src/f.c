/*********************************************************
  f.c
  --------------------------------------------------------
  generated at Tue Jun 23 14:49:26 1998
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
1.100970, -0.874360, 0.213680, -0.934150, 0.631620, -0.266700, 0.102430, -0.083840, -0.221010, -0.322270, 
-0.219430, 0.183280, 0.386340, 0.696280, 0.210820, -0.716810, 0.638860, -0.296000, -0.251890, 0.520050, 
-0.828640, 0.513730, -0.514270, -0.065190, 0.033420, 1.102480, -0.649020, 
-0.783360, 0.144130, -0.517990, 0.090800, -0.756700, -0.327130, 0.685210, 0.401070, 0.584510, 0.065520, 
-0.654960, -0.957850, -0.038480, -0.351080, -0.655880, 0.561630, -0.469560, 0.148770, -0.672170, 0.198580, 
0.365430, 0.961070, -0.766210, 0.590070, -0.030640, 0.714010, 0.475800, 
-0.002170, -0.603590, -0.931320, -1.015670, 0.367450, 0.458890, -0.524780, 0.926700, -0.815050, 1.119360, 
-0.007500, -0.818500, 0.609900, 0.030730, 0.693170, 0.197610, -0.542350, -0.408330, 0.160140, -0.543270, 
-0.808070, -0.822390, 0.805010, -0.041330, 0.084190, -0.848410, 0.682700, 
0.651890, 0.094840, 0.948420, -0.532250, 0.894130, -0.257390, 0.591660, 0.640040, 0.301470, -0.858620, 
0.541990, 0.586150, 0.029610, 0.213870, 0.853460, 0.020420, 0.565030, -0.386920, 0.192490, 0.511860, 
0.915800, 0.993900, 0.656250, 0.477350, 0.387140, 0.387460, -0.130700, 
-0.575230, 0.834000, -0.666160, 0.973200, -0.366150, 0.216120, 0.666740, -0.243300, 0.248750, 0.825980, 
-0.325960, -0.878960, 0.410300, -0.154420, -0.376790, -0.292790, -0.482640, -0.653370, -0.380120, -0.794620, 
0.224780, 0.131160, -0.850120, -0.391130, -0.714020, 0.019720, -0.863550, 
-0.586450, 0.324440, -0.686660, -0.617690, -0.340280, 0.507130, -1.237060, 0.778380, -0.411880, -0.794150, 
-0.471810, -0.197920, 0.526140, -0.730160, 0.295760, -0.388360, 0.388500, 0.720670, -0.984230, 0.797590, 
0.660920, 0.575170, -0.195790, 0.577130, 0.289510, 0.346490, -0.820170, 
-0.683380, 0.926320, 0.673190, 0.483150, 0.387150, 0.096570, 0.913710, 0.136460, -0.500200, -0.294040, 
-0.189570, 0.469380, -0.064740, 0.247050, 1.075700, -0.222410, 0.892810, -0.928200, 0.818830, -1.070420, 
-0.864680, 0.288420, -0.383060, 0.313810, -0.661760, -0.205760, -0.694050, 
-0.942600, -0.824440, 0.556100, 0.858810, 0.009540, -0.564910, 0.440940, -0.056140, 0.325090, 0.320350, 
0.859420, -0.746770, 0.069480, 0.467180, 0.162590, 0.265910, 0.308140, 0.540640, 0.574390, -0.732700, 
-0.682420, -0.549000, -0.891160, 0.552220, 0.824100, -0.511260, 0.733030, 
0.682970, -0.648610, -0.482360, -1.019610, 0.934770, -0.037600, 0.417470, 0.359050, -0.100810, 0.899570, 
-0.407240, 0.800730, 0.145640, 0.325650, 0.501400, 0.660610, 0.156020, 0.244960, -0.972600, -0.153850, 
0.143260, -0.855570, 0.072520, -0.504570, 0.207260, 0.478980, -0.818600, 
-0.048400, 0.802630, 0.850330, -0.519860, -0.071940, -0.656330, -0.262320, -0.968430, 0.074680, 0.397890, 
0.899770, -0.316750, -0.702860, 0.378330, 0.370420, -0.990650, 0.104000, -0.148080, 0.861450, -0.013670, 
1.013870, -0.004470, -0.011170, -0.910900, -0.286440, -0.649600, -0.412920, 
0.437200, -0.593100, -0.880910, 0.195320, 0.881750, -0.582560, -0.587170, -0.396660, 0.528090, -0.439470, 
-0.179780, 0.867770, 0.139850, 0.311080, -0.083800, 0.239750, -0.447080, -0.680300, 0.692740, -0.523680, 
-0.077780, 0.702560, 0.417510, -0.713730, 0.129150, 0.155860, -0.822040, 
-0.449140, -0.134230, -0.742320, 0.037170, 0.091300, 0.270460, 0.472670, -0.895180, 0.301720, 0.002470, 
-0.712150, 0.104240, -0.732750, 0.429460, 0.113180, -0.506970, -0.595130, 0.617470, -0.132690, 0.554640, 
0.247680, 0.716740, -0.528550, 0.968810, -0.178350, 0.895230, 0.076160, 
0.462420, 0.745880, -0.160490, 0.016240, 0.731250, -0.408070, 0.078810, -0.492180, 0.595550, 0.705790, 
0.225780, -0.609210, -0.923420, 0.155980, 0.268440, -0.448130, -0.755960, 0.553780, 0.816940, 0.589780, 
0.634530, -0.080330, 0.708480, 0.592080, 0.897570, -0.209840, 0.636290, 
0.447200, -0.163950, 0.223980, -0.880180, 0.942680, -0.683860, 0.363440, 0.706660, -0.329560, 0.521400, 
0.753560, 0.601490, -0.403140, 0.157640, 0.096390, -0.601480, 0.833400, 0.112330, -0.937240, 0.742190, 
-0.795020, 0.358360, 0.488230, 0.875960, 0.804000, -0.791600, -0.156730, 
0.421820, -0.060650, -0.054350, -0.460030, 0.811910, -0.098020, -0.463180, -0.260390, -0.500760, 0.782240, 
0.105290, 0.654270, -0.533080, 0.138040, 0.865450, 0.897190, -0.610150, -0.685210, -0.368830, 0.425570, 
-0.723100, 0.375910, 0.689580, 0.741590, 0.665880, -0.563210, -0.377900, 
0.521060, -0.968320, -0.087040, -0.874120, -0.261770, -0.870960, -0.419500, 0.390350, -0.346330, -0.917020, 
0.818600, 0.946580, -0.999200, 0.421170, -0.735400, -0.606190, 0.291880, -0.982780, 0.458200, 0.726640, 
0.974870, -0.795880, -0.651910, 0.483550, -0.414130, 0.003620, 0.147070, 
0.618960, -0.228620, 0.011870, 0.583500, -0.918920, 0.167300, -0.710720, -0.066050, 0.424050, 0.718850, 
0.404730, -0.142340, -0.475320, -0.087610, -0.339850, 0.285980, 0.230450, 1.018060, -0.048170, -0.032350, 
-0.531910, -0.815500, 0.783380, -0.802100, 0.660730, -0.548060, -0.166450, 
-0.919460, -0.335170, 0.466600, 0.515880, -0.476000, 0.620070, -0.574530, -0.582090, 0.678110, -0.346640, 
-0.849420, 0.714220, 0.119920, -0.685450, 0.029980, 0.507620, -0.228000, -0.938540, 0.541670, -0.185290, 
0.751070, 0.313360, 0.539670, 0.614880, -0.138100, 0.672010, -0.065390, 
0.988000, -0.107210, 0.330710, 0.393980, -0.573770, 0.110760, 0.822150, 0.585280, -0.343810, -0.680310, 
0.712830, -0.360120, -0.104160, -0.649800, -0.756410, 0.025220, 0.214770, 0.061820, 0.320930, 0.756970, 
-0.307940, 0.777710, -0.280380, -0.399780, -0.983130, -0.614130, -0.627600, 
0.494560, -0.030030, -0.719030, 0.959970, -0.266080, -0.670180, 0.395950, -0.935830, 0.968850, -0.321710, 
-0.181490, 0.898530, -0.504980, 0.724230, -0.891660, -0.219000, 0.294500, 0.117400, -0.455540, 0.629820, 
0.281040, 0.003800, -0.624120, 0.109970, -0.438390, -0.949940, 0.662740, 
0.729290, 1.015910, -0.528900, 0.195190, -0.461710, 0.532630, -0.208740, -0.103280, -0.171010, -0.188230, 
-0.633490, -0.774150, -0.374080, -0.533630, 0.310820, 0.949070, -0.892680, -0.711230, -0.042270, 0.362380, 
0.617170, 0.272390, -0.838330, -0.237140, -0.454290, 0.906350, -0.621000, 
0.842200, 0.724380, -0.006240, -0.556410, 1.068190, 0.208120, -0.789010, 0.799100, -0.743400, -0.770990, 
-0.440980, -0.297410, 0.783990, -0.289880, 0.011120, 0.365100, 0.732600, 0.165690, 0.640250, 0.210910, 
0.901290, -0.654560, 0.430990, -0.587060, 0.800340, -0.879330, -0.910430, 
-0.072590, 0.263480, 0.834580, -0.831390, -0.664950, 0.448780, 0.261240, 0.961830, -0.243550, -0.697440, 
0.556160, 0.032950, 0.628620, 0.768170, 0.585040, 0.054670, -0.809710, -0.029470, -0.054430, 0.347160, 
-0.543390, -0.716030, 0.967810, 0.177620, 0.779770, -0.614760, 0.802630, 
0.953710, 0.448830, 0.563380, -0.114410, 0.210680, 0.501810, -0.843270, 0.502770, -0.482960, -0.206720, 
0.152980, -0.241390, 0.036390, 0.207820, -0.856630, -0.894920, -0.166630, -0.421530, 0.146920, 0.576730, 
-0.004440, 0.330960, -0.923930, -0.152680, 0.634890, 0.204860, -0.722710, 
-0.969810, -0.221540, -0.801750, 0.452730, -0.196000, -0.709650, -0.876900, -0.791600, -0.721670, 0.836190, 
-0.732060, 0.043340, -0.341870, -0.550940, -0.085190, -0.638070, 0.443650, -0.516390, -0.710800, 0.603570, 
0.476770, 0.496450, 0.711190, 0.048620, 0.358380, -0.258580, -0.299770, 
-0.702880, -0.414470, -0.294040, 0.786550, -0.434860, -0.274990, -0.025460, -0.725370, 0.140640, -0.068780, 
-0.724160, 0.294020, -0.235910, 0.919930, 0.602250, -0.411910, 0.541300, 0.858220, 0.002700, 0.332250, 
-0.242380, -0.608040, -0.117250, -0.939350, -0.154440, 0.023530, 0.240580, 
0.156160, 0.071720, 0.323650, 0.495840, 0.378790, -0.429090, 0.403770, 0.169090, -0.375970, -0.327480, 
0.784150, -0.433980, -0.285140, -0.994420, -0.097530, 1.225540, 0.900320, -0.818870, -0.358570, 0.051560, 
-0.015770, -0.918120, -0.353550, -0.066660, 1.081700, 0.631580, -0.703680, 
0.182180, -0.143130, 0.170380, 0.010950, 0.412150, 0.101950, -0.548840, -0.289460, -0.154240, -0.442830, 
-0.218000, 0.914670, 0.560520, 0.700130, 0.255900, -0.812780, -0.852100, -0.807500, -0.944840, -0.095420, 
0.552800, -0.380050, 0.036290, -0.804680, -0.701180, -0.913840, 0.706930, 
0.173620, 0.226920, -0.206750, 0.535300, 0.645170, -0.694550, 0.881160, -0.456010, 0.638210, -0.174250, 
-0.254370, 0.182910, -0.021900, 0.072430, 0.244450, -0.311120, 0.905800, -0.026920, -0.664510, 0.582820, 
0.028130, -0.980530, -0.213210, -0.329010, 0.916390, 0.289070, -0.952460, 
-0.461920, -0.890620, -0.113070, 0.396000, -0.773760, -0.720460, -0.809770, -0.861530, -0.027410, -0.235470, 
-0.522590, -0.413730, -0.167430, -0.768160, 0.463740, 0.643370, 0.869630, 0.936910, 0.564270, 0.120150, 
-0.315920, 0.423700, -0.217470, 0.981630, 0.633830, -0.844580, -0.337930, 
-0.370250, -0.592510, -0.556360, 0.354540, -0.914400, 0.758090, -0.864810, -0.599520, -0.291570, -0.383930, 
0.426870, 0.600030, -0.027110, 0.550010, -0.185730, 0.686420, -0.596920, 0.545460, 0.508290, -0.115150, 
-0.237630, 0.642250, -0.277540, -0.550510, -0.016450, -0.086420, 0.334070, 
0.559090, 0.841590, -0.298630, 0.723110, 0.012180, -0.239010, 0.832170, 0.484970, -0.528480, 0.055340, 
0.720950, -0.511650, -0.248390, 0.363950, -0.517380, -0.550000, -0.937230, 0.919750, 0.125530, -0.904560, 
-0.976530, -0.387490, -0.852180, 0.150130, -0.943440, -0.119870, -0.404630, 
0.894760, 0.587040, -0.138400, 0.358540, -0.183750, 0.625430, 0.787330, -0.820370, -0.015520, 0.636970, 
-0.466270, 0.843980, 0.746730, -0.559460, -0.110550, -0.521070, 0.446600, 0.339020, -0.926120, 0.642560, 
0.806960, 0.096060, -0.146120, 0.594470, 0.433420, 0.034530, -0.812420, 
-0.016910, -0.423030, 0.332030, 0.418280, -0.641670, 0.067700, -0.468020, 0.502160, -0.518260, 0.044900, 
-0.128030, 0.478130, -0.293330, 0.088820, -0.561280, 0.913510, 0.905150, 0.315990, -0.722190, 0.010810, 
-0.220060, 0.643500, 0.707600, 0.323790, 0.658730, 0.561120, -0.153080, 
-0.895050, 0.794900, 0.307950, -0.488460, -1.076280, 0.594740, -0.196100, 0.243520, 0.043090, -0.903210, 
0.689460, 0.537090, -0.818730, -0.787090, 0.552900, 0.168980, -0.610010, -0.825990, -0.745270, 0.373690, 
0.184930, 0.381950, -0.623890, 0.958900, 0.545540, -0.198990, -0.328190, 
-0.535470, 0.924850, -0.633780, 0.148270, 0.094260, -0.257550, 0.643890, -0.885680, -0.674980, -0.946000, 
0.948150, 0.262830, -0.617380, 0.833780, -0.558940, -0.110970, -0.001220, 0.519660, 0.655170, 0.168290, 
0.346090, -0.074100, 0.811130, 0.877060, -0.348530, 0.558580, 0.625520, 
0.115040, 0.441410, 0.266660, 0.335010, 1.282110, 0.994320, -0.726870, 0.474040, 0.596750, 0.702420, 
0.570000, -0.733400, -0.758830, 0.983840, 0.687920, 0.928520, 0.622340, -0.635240, -0.112410, 1.121630, 
-0.176710, -0.304240, -0.108530, -0.350860, -0.538710, 0.156390, 0.752640, 
-0.033110, 0.321200, 0.085190, 0.225400, 0.081430, -0.945940, -0.957710, 0.607150, 0.748790, 0.239480, 
0.414650, -0.896920, 0.401340, 0.484840, 0.662960, -0.407260, 0.563130, -0.082210, -0.825550, 0.212640, 
0.106660, -0.156830, 0.375510, -0.862710, -0.922350, 0.689400, -0.594150, 
-0.971960, -0.884350, 0.764830, 0.837020, 0.094930, -0.387430, -0.560940, 0.187280, -0.649600, -0.064940, 
-0.353030, -0.529700, 0.862690, 0.331330, -0.511380, -0.891550, -0.061680, 0.993900, 0.487930, 0.038110, 
0.322010, -0.213900, 1.026500, -0.756710, 0.573870, -0.619680, -0.776430, 
-0.671970, 0.627710, 0.382510, -0.736010, 0.614940, 0.414580, 0.698150, 0.360470, -0.374580, 0.617530, 
-0.460730, 0.239670, 0.655860, 0.372410, -0.264650, -0.770810, -0.409140, -0.247730, 0.380790, 0.205750, 
0.473340, -0.720920, -0.759040, -0.244860, 0.463860, -0.040820, 0.212400, 
0.791940, -0.539330, -0.452900, -0.600440, -0.161620, 0.120540, -0.630730, -0.269550, 0.094670, -0.649480, 
0.476720, -0.626170, 0.500720, 0.690880, 0.653450, -0.334820, -0.011920, 0.900040, 0.080820, 0.335440, 
-0.437290, 0.419340, -0.749550, -0.850850, -0.529480, 0.644920, -0.865440, 0.865120, 0.007240, 0.604960, 
0.423130, -0.708930, 0.795780, 0.761420, -0.600350, -0.189750, 0.701140, -0.719210, -0.480830, -1.009360, 

-0.959110, 0.498690, -0.408740, 0.748530, 0.404570, -0.718060, -0.650250, -0.803970, 0.498720, -0.419520, 
0.599150, 0.582950, 0.927970, 0.708410, -0.240660, -0.103660, -0.977740, -0.074020, 0.876850, -0.778550, 
-0.938540, 0.118810, -0.436550, -0.828700, 0.483770, 0.822790, -0.851520, -0.092020, -0.123880, -0.406360, 
-0.825830, -0.477700, 0.001490, 0.349210, -0.970800, 0.345380, 0.301700, -0.359090, -0.402430, -0.648000, 

0.976810, -0.957130, -0.241890, -0.967940, 0.155450, 0.964390, -1.293910, -0.874130, -0.724230, 0.407940, 
0.696130, 0.787350, -0.105320, -0.720030, -0.123760, -0.577290, -0.092730, 0.000460, 0.240030, -0.239850, 
0.789220, -0.690630, -0.868400, -0.108940, 0.986460, 0.848180, -0.698670, 0.968760, 0.468850, 0.611560, 
0.002700, -0.068530, 0.959470, 0.203010, 0.982140, 0.494860, -0.530000, -0.264860, 0.432500, 0.784540, 

-0.996000, 0.176410, -0.653950, 0.695310, 0.564530, 0.993900, 0.746600, 0.511870, 0.421790, -0.789200, 
-0.291450, 0.531160, -0.601970, -0.452090, 0.567650, -0.956950, -0.636770, 0.786990, 0.401290, -0.504330, 
0.809940, 0.789190, 0.932480, -0.038430, 0.357400, -0.769080, -0.947640, 0.283430, -0.554110, 0.288190, 
0.287160, 0.060210, 0.070360, -0.315190, 0.838410, 0.606260, -0.159730, 0.076050, 0.551580, -0.127790, 

-0.555240, -0.204550, -0.232500, 0.562250, 0.493850, 0.905870, -0.415170, 0.692950, 0.247270, -0.755350, 
0.035030, 0.686750, 0.683040, -0.493690, 0.682560, -0.683410, 0.907570, 0.126590, 0.942800, -0.082220, 
0.689680, 0.645420, -0.074650, -0.610800, -0.123920, -0.216720, 0.709680, -0.572980, -0.390960, -0.223310, 
-0.439810, -0.042550, 0.071170, 0.791300, 0.110500, 0.536680, 0.554230, -0.957070, 0.293630, 0.792500, 

-0.560650, -0.439440, -0.153600, -0.439340, 0.642720, -0.424100, 0.568350, 0.663920, 0.789400, 0.491230, 
-0.571620, -0.789610, 0.128540, -0.499780, 0.747520, 0.256600, -0.932880, 0.343880, 0.213390, 0.944130, 
0.680400, 0.737110, -0.413560, -0.861770, -0.250210, -0.999740, 0.031300, -0.680330, -0.597840, 0.289900, 
-0.059240, 0.484270, -0.192620, 0.799420, -0.832620, -0.562160, -0.776940, -0.022980, -0.803150, -0.367670, 

-0.156000, -0.521580, -0.954710, 0.453500, 0.535550, 0.584250, -0.194240, -0.334500, -0.397310, -0.001060, 
-0.460510, -0.925180, 0.189620, -0.769480, 0.784400, 0.383540, -0.000990, -0.681920, 0.391190, 0.784910, 
0.901700, -0.885380, -0.406950, 0.631710, -0.055370, -0.657620, 0.789100, 0.340270, 0.877990, 0.839240, 
-0.820350, 0.984810, 0.541700, 0.191120, 0.785770, 0.747440, 0.075900, 0.453710, 0.339290, 0.834900, 

-0.139110, -0.666400, 0.590390, 0.589580, -0.260540, -0.934850, -0.435250, -0.292580, -0.072610, 0.677350, 
0.569030, -0.094670, 0.640700, 0.313790, -0.858700, 0.173370, -0.763790, 0.332920, -0.638060, -0.076440, 
0.162420, -0.248820, -0.878650, -0.672780, -0.708160, -0.987620, -0.427670, -0.598050, -0.517890, 0.280370, 
-0.778780, 0.157140, -0.737180, -0.761940, -0.295440, 0.239520, -0.395430, 0.362800, 0.195210, 0.610440, 

-0.122980, 0.560550, 0.131480, 0.816090, -0.226040, -0.628630, 0.634630, -0.073050, -0.040620, 0.231210, 
0.927060, 0.879580, 0.767590, 0.160800, 0.863990, -0.685150, 0.003590, 0.846470, 0.059320, -0.532570, 
0.131370, 0.746020, 0.995980, -0.362060, 0.292850, -0.960470, 0.953070, 0.730370, 0.873950, -0.618250, 
-0.770880, -0.244720, 0.059220, 1.024020, -0.731610, -0.873420, 0.170100, 0.728470, 0.312490, -0.497580, 

0.130850, -0.497690, 0.025300, -0.593820, -0.875240, -0.632830, 0.077990, -0.075550, 0.808260, 0.892940, 
0.358260, -0.503600, -0.870920, 0.306850, -0.666040, 0.645070, -0.982730, -0.833960, 0.001150, -0.842610, 
0.778950, -0.815640, 0.467050, -0.459020, 0.285990, -0.667300, -0.584660, -0.446010, 0.199590, -0.276360, 
-0.955480, 0.294980, -0.036920, -0.886180, 0.352260, -0.858840, 1.013440, -0.399600, -0.029070, -0.792660, 

-0.183320, -0.572740, -0.761760, 0.242020, -0.366480, -0.722780, 0.321150, 0.498870, -0.435330, 0.625260, 
-0.040530, 0.222750, 0.343130, -0.670470, 0.555290, 0.533300, -0.711210, 0.238760, 0.824240, 0.026420, 
0.709010, 0.400450, 0.681320, 0.191270, 0.696800, 0.994670, 0.477420, 0.855160, 0.205980, 0.457670, 
0.066890, 0.298950, 0.035230, 0.890520, -0.146510, -0.939630, 0.566660, 0.945810, 0.336920, 0.657360, 

-0.480190, 0.994450, -1.042640, -0.843470, -0.517360, -0.960300, 0.009520, 0.503230, -0.686490, -0.381240, 
0.190700, -0.650760, 0.182240, 1.065290, 0.460070, -0.266360, 0.478190, 0.156530, -0.282270, -0.542360, 
0.935900, 0.413360, 0.581740, 0.617170, 0.697950, -0.611710, -0.757380, -0.707930, -0.435560, 0.155360, 
0.417870, -0.849190, -0.488890, 0.200560, -0.408020, 0.402830, -0.492830, -0.128530, 0.827960, 0.042590, 

0.764430, 0.437590, -0.148280, -0.630760, -0.772370, -0.325250, 0.087070, -0.756530, -0.169310, 0.208760, 
0.443810, 0.323800, 0.216480, 0.261260, 0.449060, -0.682970, -0.348090, -0.195970, 0.463230, 0.470510, 
-0.578870, -0.272940, 0.194410, 0.952790, 0.139790, -0.524880, -0.573670, -0.950820, -0.511830, 0.420490, 
-0.593560, 0.151450, 0.313610, 0.570550, -0.959870, 0.598130, -0.251550, 0.194020, 0.992190, -0.882990, 

0.518450, 0.705060, -0.142770, 0.156780, 0.367910, -0.315220, -0.250140, -0.800060, 0.609210, -1.020780, 
1.032240, 0.884570, -0.236320, -0.601440, -0.303200, 0.769410, 0.084530, -0.588430, 0.880130, -0.778990, 
-0.079770, 0.517510, 0.860450, -0.675390, -0.776740, 0.559540, 0.874250, 0.576730, 0.847030, -0.339710, 
0.961830, -0.788460, -0.137480, 0.008120, -0.512450, -0.025050, -0.900420, 0.323480, 0.902760, -0.954140, 

-0.227210, -0.711870, -0.008370, -0.728530, -0.241850, -0.594630, -0.192610, -0.295130, -0.414250, -0.243230, 
-0.134700, -0.462700, -0.997270, 0.344230, -0.221580, 0.738260, -0.677780, -0.648250, -0.102500, -0.832040, 
-0.838910, -0.252100, -0.454330, 0.356120, 0.210640, -0.273530, -0.853770, -0.989150, 0.921640, -0.115740, 
0.337130, -0.127000, -0.472140, 0.642440, -0.171460, 0.517250, 0.325560, 0.627010, 0.333590, 0.857950, 

0.956080, -0.306370, 0.597000, -0.594410, -0.809520, 0.917650, -0.884130, 0.523090, 0.444720, -0.782370, 
0.824840, -0.786760, 0.146750, 0.064850, -0.031990, 0.411040, -0.387790, -0.049230, 0.661340, -0.976510, 
0.793000, 0.295770, 0.207060, 0.953900, 0.241500, -0.497570, -0.256750, 0.800080, 0.558950, -0.172600, 
0.214730, -0.501470, -0.265520, -0.754930, 0.395780, -0.464810, 1.041990, 0.080950, 0.654510, -0.333800, 

0.129480, -0.365320, -0.576800, 0.277380, -0.059460, 0.236180, 0.456660, -0.452030, 0.348000, -0.914130, 
0.046740, 0.194470, 0.214140, -0.421510, 0.146620, 0.771640, 0.841070, 0.294920, -0.406510, 0.689580, 
0.740820, 0.811520, -0.635280, 0.654930, 0.003000, 0.167270, 0.307650, 0.391620, -0.855090, 0.581540, 
0.497030, 0.125050, -0.595210, 0.047790, -0.490750, -0.636380, 0.809050, 0.788420, -0.939910, 1.002980, 

-0.152480, -0.572700, 0.689910, -0.489760, -0.836450, 1.061690, 0.063860, -0.834840, -0.051420, 1.071510, 
-1.035470, -0.525520, -0.693680, 0.512310, -0.623130, 0.122430, -0.616440, -0.282250, -0.339800, -0.236570, 
-0.439680, 0.256940, -0.698570, 1.133440, 0.940330, 0.568770, -0.693480, -0.130910, 0.513930, -0.778330, 
0.526510, 0.816070, -0.532320, 0.662570, 0.255170, 0.130210, 0.199560, -0.075780, 0.931520, -0.288250, 

0.554870, 0.322100, 0.478230, -0.978710, -0.138350, 0.725110, 0.357610, 0.584380, 0.296490, 0.188080, 
-0.013590, -0.037560, -0.681650, -0.116020, 0.411670, 0.962550, -0.368560, 0.845540, 0.786120, -0.662560, 
-0.159320, 0.409090, 0.943130, -0.212950, -0.376740, 0.913250, -0.075320, -0.838670, -0.949070, -0.040810, 
0.107880, 0.131080, -0.256950, 0.092020, -0.799630, 0.163390, 1.033360, 1.038630, 0.231390, -0.093060, 

0.435330, 0.590790, 0.264040, -0.925620, -0.259440, -0.313830, -0.290270, 0.526200, -0.902460, -0.678020, 
0.021920, 0.752790, 0.548080, -0.911780, -0.379320, -0.412680, 0.230450, -0.763990, -0.067250, -0.347470, 
0.591230, 0.162000, -0.034600, 0.837630, -0.960810, -0.340380, -0.332860, 0.252150, 0.586430, -0.456830, 
-0.125780, -0.450350, -0.930820, -0.823320, 0.331170, -0.951510, 0.172910, -0.788870, -0.391460, 0.785350, 

0.437210, 0.845870, 1.710010, -1.345350, 0.609320, 0.456570, -0.039480, -0.835810, -0.931680, 0.440970, 
-0.828710, -0.626660, 0.211700, -0.541440, 0.373770, 0.863580, 0.577700, 1.177910, 0.410220, -0.098080, 


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
      0.0, -0.271970, 27,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 29 (Old: 29) */
      0.0, 0.048560, 27,
       &Sources[27] , 
       &Weights[27] , 
      },
    { /* unit 30 (Old: 30) */
      0.0, -0.718930, 27,
       &Sources[54] , 
       &Weights[54] , 
      },
    { /* unit 31 (Old: 31) */
      0.0, 0.584970, 27,
       &Sources[81] , 
       &Weights[81] , 
      },
    { /* unit 32 (Old: 32) */
      0.0, -0.900450, 27,
       &Sources[108] , 
       &Weights[108] , 
      },
    { /* unit 33 (Old: 33) */
      0.0, 0.461020, 27,
       &Sources[135] , 
       &Weights[135] , 
      },
    { /* unit 34 (Old: 34) */
      0.0, 0.799860, 27,
       &Sources[162] , 
       &Weights[162] , 
      },
    { /* unit 35 (Old: 35) */
      0.0, -0.077040, 27,
       &Sources[189] , 
       &Weights[189] , 
      },
    { /* unit 36 (Old: 36) */
      0.0, 0.260960, 27,
       &Sources[216] , 
       &Weights[216] , 
      },
    { /* unit 37 (Old: 37) */
      0.0, -0.371950, 27,
       &Sources[243] , 
       &Weights[243] , 
      },
    { /* unit 38 (Old: 38) */
      0.0, -0.952940, 27,
       &Sources[270] , 
       &Weights[270] , 
      },
    { /* unit 39 (Old: 39) */
      0.0, -0.998370, 27,
       &Sources[297] , 
       &Weights[297] , 
      },
    { /* unit 40 (Old: 40) */
      0.0, -0.955410, 27,
       &Sources[324] , 
       &Weights[324] , 
      },
    { /* unit 41 (Old: 41) */
      0.0, 0.907930, 27,
       &Sources[351] , 
       &Weights[351] , 
      },
    { /* unit 42 (Old: 42) */
      0.0, 0.152630, 27,
       &Sources[378] , 
       &Weights[378] , 
      },
    { /* unit 43 (Old: 43) */
      0.0, -0.935400, 27,
       &Sources[405] , 
       &Weights[405] , 
      },
    { /* unit 44 (Old: 44) */
      0.0, 0.217670, 27,
       &Sources[432] , 
       &Weights[432] , 
      },
    { /* unit 45 (Old: 45) */
      0.0, -1.020840, 27,
       &Sources[459] , 
       &Weights[459] , 
      },
    { /* unit 46 (Old: 46) */
      0.0, -0.885370, 27,
       &Sources[486] , 
       &Weights[486] , 
      },
    { /* unit 47 (Old: 47) */
      0.0, -0.757330, 27,
       &Sources[513] , 
       &Weights[513] , 
      },
    { /* unit 48 (Old: 48) */
      0.0, -0.265030, 27,
       &Sources[540] , 
       &Weights[540] , 
      },
    { /* unit 49 (Old: 49) */
      0.0, -0.069760, 27,
       &Sources[567] , 
       &Weights[567] , 
      },
    { /* unit 50 (Old: 50) */
      0.0, -0.147780, 27,
       &Sources[594] , 
       &Weights[594] , 
      },
    { /* unit 51 (Old: 51) */
      0.0, 0.310040, 27,
       &Sources[621] , 
       &Weights[621] , 
      },
    { /* unit 52 (Old: 52) */
      0.0, 0.018070, 27,
       &Sources[648] , 
       &Weights[648] , 
      },
    { /* unit 53 (Old: 53) */
      0.0, -1.239370, 27,
       &Sources[675] , 
       &Weights[675] , 
      },
    { /* unit 54 (Old: 54) */
      0.0, -0.659250, 27,
       &Sources[702] , 
       &Weights[702] , 
      },
    { /* unit 55 (Old: 55) */
      0.0, 0.401950, 27,
       &Sources[729] , 
       &Weights[729] , 
      },
    { /* unit 56 (Old: 56) */
      0.0, -0.514020, 27,
       &Sources[756] , 
       &Weights[756] , 
      },
    { /* unit 57 (Old: 57) */
      0.0, -0.867160, 27,
       &Sources[783] , 
       &Weights[783] , 
      },
    { /* unit 58 (Old: 58) */
      0.0, 0.819270, 27,
       &Sources[810] , 
       &Weights[810] , 
      },
    { /* unit 59 (Old: 59) */
      0.0, 0.723060, 27,
       &Sources[837] , 
       &Weights[837] , 
      },
    { /* unit 60 (Old: 60) */
      0.0, -0.122530, 27,
       &Sources[864] , 
       &Weights[864] , 
      },
    { /* unit 61 (Old: 61) */
      0.0, 0.532220, 27,
       &Sources[891] , 
       &Weights[891] , 
      },
    { /* unit 62 (Old: 62) */
      0.0, 0.424200, 27,
       &Sources[918] , 
       &Weights[918] , 
      },
    { /* unit 63 (Old: 63) */
      0.0, -0.983760, 27,
       &Sources[945] , 
       &Weights[945] , 
      },
    { /* unit 64 (Old: 64) */
      0.0, -0.652480, 27,
       &Sources[972] , 
       &Weights[972] , 
      },
    { /* unit 65 (Old: 65) */
      0.0, -0.902510, 27,
       &Sources[999] , 
       &Weights[999] , 
      },
    { /* unit 66 (Old: 66) */
      0.0, -0.425680, 27,
       &Sources[1026] , 
       &Weights[1026] , 
      },
    { /* unit 67 (Old: 67) */
      0.0, -0.370180, 27,
       &Sources[1053] , 
       &Weights[1053] , 
      },
    { /* unit 68 (Old: 68) */
      0.0, -0.965710, 40,
       &Sources[1080] , 
       &Weights[1080] , 
      },
    { /* unit 69 (Old: 69) */
      0.0, 0.207750, 40,
       &Sources[1120] , 
       &Weights[1120] , 
      },
    { /* unit 70 (Old: 70) */
      0.0, -0.820060, 40,
       &Sources[1160] , 
       &Weights[1160] , 
      },
    { /* unit 71 (Old: 71) */
      0.0, 0.120530, 40,
       &Sources[1200] , 
       &Weights[1200] , 
      },
    { /* unit 72 (Old: 72) */
      0.0, 0.037110, 40,
       &Sources[1240] , 
       &Weights[1240] , 
      },
    { /* unit 73 (Old: 73) */
      0.0, -0.829810, 40,
       &Sources[1280] , 
       &Weights[1280] , 
      },
    { /* unit 74 (Old: 74) */
      0.0, 0.782420, 40,
       &Sources[1320] , 
       &Weights[1320] , 
      },
    { /* unit 75 (Old: 75) */
      0.0, -0.907970, 40,
       &Sources[1360] , 
       &Weights[1360] , 
      },
    { /* unit 76 (Old: 76) */
      0.0, -0.724010, 40,
       &Sources[1400] , 
       &Weights[1400] , 
      },
    { /* unit 77 (Old: 77) */
      0.0, -0.540830, 40,
       &Sources[1440] , 
       &Weights[1440] , 
      },
    { /* unit 78 (Old: 78) */
      0.0, 0.626190, 40,
       &Sources[1480] , 
       &Weights[1480] , 
      },
    { /* unit 79 (Old: 79) */
      0.0, 0.507380, 40,
       &Sources[1520] , 
       &Weights[1520] , 
      },
    { /* unit 80 (Old: 80) */
      0.0, -0.226120, 40,
       &Sources[1560] , 
       &Weights[1560] , 
      },
    { /* unit 81 (Old: 81) */
      0.0, 0.776760, 40,
       &Sources[1600] , 
       &Weights[1600] , 
      },
    { /* unit 82 (Old: 82) */
      0.0, -0.939550, 40,
       &Sources[1640] , 
       &Weights[1640] , 
      },
    { /* unit 83 (Old: 83) */
      0.0, 0.140090, 40,
       &Sources[1680] , 
       &Weights[1680] , 
      },
    { /* unit 84 (Old: 84) */
      0.0, 0.125430, 40,
       &Sources[1720] , 
       &Weights[1720] , 
      },
    { /* unit 85 (Old: 85) */
      0.0, -0.679460, 40,
       &Sources[1760] , 
       &Weights[1760] , 
      },
    { /* unit 86 (Old: 86) */
      0.0, 0.768670, 40,
       &Sources[1800] , 
       &Weights[1800] , 
      },
    { /* unit 87 (Old: 87) */
      0.0, -0.146920, 40,
       &Sources[1840] , 
       &Weights[1840] , 
      },
    { /* unit 88 (Old: 88) */
      0.0, 0.057970, 20,
       &Sources[1880] , 
       &Weights[1880] , 
      }

  };



int f(float *in, float *out, int init)
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
