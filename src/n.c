/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    n.c
    --------------------------------------------------------
    generated at Tue Jun 23 16:27:46 1998
    by snns2c ( Bernward Kett 1995 )
*********************************************************/

#include <math.h>

#define Act_Logistic(sum, bias)  ( (sum+bias<10000.0) ? ( 1.0/(1.0 + exp(-sum-bias) ) ) : 0.0 )
#define NULL (void *)0

typedef struct UT
{
    float act;         /* Activation       */
    float Bias;        /* Bias of the Unit */
    int   NoOfSources; /* Number of predecessor units */
    struct UT**   sources; /* predecessor units */
    float* weights; /* weights from predecessor units */
} UnitType, *pUnit;

/* Forward Declaration for all unit types */
static UnitType Units[89];
/* Sources definition section */
static pUnit Sources[] =
{
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
static float Weights[] =
{
    1.068650, -0.846450, 0.109390, -0.815870, 0.385280, -0.173280, -0.132950, -0.120350, -0.407600, -0.828130,
    -0.088030, 0.216630, 0.171970, 0.698910, 0.325940, -0.998780, 0.595090, -0.264180, -0.112340, 0.351470,
    -1.104250, 0.479830, -0.410870, -0.057310, 0.020920, 1.129780, -0.626760,
    -0.911680, 0.030040, -0.425180, -0.081330, -0.146580, -0.423910, 0.848780, 0.444510, 0.744030, 0.570520,
    -0.549130, -0.949220, 0.332580, -0.274390, -0.809260, 1.186290, -0.287250, 0.005780, -0.864970, 0.401290,
    0.644080, 1.053380, -0.801540, 0.820160, -0.015210, 0.601560, 0.653680,
    0.006420, -0.615130, -0.905170, -0.948180, 0.419710, 0.508580, -0.570020, 0.916620, -0.721220, 1.003860,
    0.029500, -0.737460, 0.580020, 0.037260, 0.777700, 0.201660, -0.483820, -0.391760, 0.211460, -0.548510,
    -0.757100, -0.745400, 0.880110, -0.021740, 0.172120, -0.867400, 0.670630,
    0.653410, 0.112300, 0.963600, -0.569250, 0.919730, -0.268030, 0.514590, 0.641440, 0.298590, -0.798920,
    0.536790, 0.542350, 0.065030, 0.211380, 0.865530, 0.038580, 0.566990, -0.390630, 0.216780, 0.515970,
    0.904610, 0.988500, 0.623120, 0.469890, 0.392700, 0.431200, -0.122080,
    -0.476250, 0.855970, -0.666390, 0.951150, -0.249610, 0.253530, 0.693990, -0.250360, 0.266170, 0.936240,
    -0.313380, -0.843740, 0.449520, -0.146310, -0.343330, -0.268320, -0.468630, -0.682600, -0.398610, -0.791630,
    0.205380, 0.116260, -0.849130, -0.366800, -0.738250, 0.076130, -0.813000,
    -0.444310, 0.290080, -0.897130, -0.590370, -0.302570, 0.619440, -1.159450, 0.757040, -0.388340, -1.010100,
    -0.526300, -0.352590, 0.252860, -0.749600, 0.306150, -0.695250, 0.383130, 0.686710, -0.770170, 0.571360,
    0.364800, 0.502350, -0.269300, 0.518810, 0.204010, 0.248760, -0.873450,
    -0.752520, 0.869490, 0.699410, 0.333850, 0.472990, -0.020620, 1.011160, 0.142330, -0.594180, -0.099750,
    -0.260760, 0.404070, 0.054720, 0.225060, 0.912340, -0.060280, 0.885460, -0.944550, 0.821340, -1.025830,
    -0.788290, 0.253650, -0.606450, 0.247840, -0.689550, -0.253450, -0.691080,
    -1.015620, -0.853900, 0.545140, 0.745530, -0.030830, -0.699390, 0.508150, -0.016280, 0.202170, 0.460100,
    0.673200, -0.843200, 0.195790, 0.444540, -0.047050, 0.366630, 0.291300, 0.492430, 0.443960, -0.615590,
    -0.591370, -0.633680, -0.963630, 0.484310, 0.733950, -0.524640, 0.785210,
    0.648530, -0.633690, -0.516700, -1.015620, 0.957740, -0.131140, 0.566580, 0.342790, -0.086050, 0.882110,
    -0.401600, 0.811040, 0.190980, 0.322130, 0.568870, 0.801950, 0.201210, 0.268560, -0.901440, -0.149290,
    0.156860, -0.840260, 0.016070, -0.515120, 0.292560, 0.564660, -0.678290,
    -0.093410, 0.743850, 0.903250, -0.555540, 0.270420, -0.592790, -0.252520, -0.995310, 0.235560, 0.367140,
    0.928770, -0.337290, -0.720780, 0.416240, 0.399750, -0.788140, 0.216920, -0.210560, 0.872670, -0.284740,
    0.949470, 0.105920, 0.075200, -0.797170, -0.249290, -0.668440, -0.473580,
    0.452140, -0.505390, -0.903820, 0.247910, 0.876930, -0.569020, -0.661790, -0.402930, 0.473630, -0.499870,
    -0.010900, 0.843610, 0.123660, 0.296280, -0.033080, 0.222960, -0.414710, -0.697080, 0.701830, -0.557550,
    -0.202240, 0.822900, 0.583290, -0.758120, 0.141510, 0.363880, -0.655380,
    -0.434020, -0.151860, -0.734080, -0.009680, 0.226360, 0.219830, 0.515040, -0.924330, 0.364480, 0.221470,
    -0.704770, 0.025980, -0.748480, 0.411010, 0.054960, -0.389130, -0.537850, 0.536570, -0.203530, 0.559070,
    0.278650, 0.772730, -0.501220, 0.913470, -0.236010, 0.883200, 0.154600,
    0.419560, 0.774770, -0.117400, -0.031900, 0.695700, -0.453720, -0.041680, -0.488980, 0.567290, 0.677860,
    0.174830, -0.706830, -0.952760, 0.132840, 0.325680, -0.313340, -0.738680, 0.559060, 0.808280, 0.543770,
    0.598360, -0.105950, 0.729080, 0.522640, 0.933280, -0.065760, 0.713710,
    0.450930, -0.166550, 0.226140, -0.874280, 0.980810, -0.677270, 0.362310, 0.684670, -0.320980, 0.494420,
    0.776900, 0.623830, -0.400930, 0.150240, 0.118180, -0.564990, 0.851680, 0.131210, -0.893690, 0.706750,
    -0.799200, 0.398470, 0.468980, 0.853770, 0.853270, -0.779430, -0.117690,
    0.420310, -0.051030, -0.005110, -0.531430, 0.706500, -0.112380, -0.557850, -0.276420, -0.546620, 0.817580,
    0.077200, 0.702320, -0.524770, 0.105460, 0.800200, 0.996610, -0.657260, -0.677340, -0.429090, 0.443570,
    -0.700200, 0.382960, 0.714750, 0.643840, 0.628750, -0.460220, -0.394470,
    0.577370, -0.943290, -0.095130, -0.793600, -0.347890, -0.863670, -0.282100, 0.408730, -0.338360, -0.970940,
    0.823800, 0.956490, -0.944670, 0.436320, -0.672140, -0.604490, 0.275310, -0.922250, 0.470500, 0.884970,
    0.993410, -0.873920, -0.671580, 0.528990, -0.335590, -0.003930, 0.184110,
    0.620390, -0.238310, 0.018620, 0.555470, -0.870550, 0.156660, -0.837610, 0.006610, 0.397860, 0.812660,
    0.356580, -0.183440, -0.354650, -0.082060, -0.459600, 0.283370, 0.222220, 0.983130, -0.120990, 0.038010,
    -0.560980, -0.884240, 0.766730, -0.785450, 0.599060, -0.550920, -0.150580,
    -0.891350, -0.335580, 0.400460, 0.449880, -0.443030, 0.534680, -0.533270, -0.675590, 0.601140, -0.433860,
    -0.812150, 0.710670, 0.151220, -0.716490, -0.051900, 0.637770, -0.168070, -0.974300, 0.579360, -0.336520,
    0.630480, 0.373500, 0.572240, 0.521760, -0.125180, 0.837390, 0.100060,
    0.935440, -0.088040, 0.265530, 0.411790, -0.706060, 0.118650, 0.788650, 0.589860, -0.354050, -0.729990,
    0.621720, -0.455830, -0.180780, -0.664990, -0.720850, -0.147490, 0.159370, 0.098990, 0.447620, 0.805560,
    -0.402970, 0.633800, -0.402080, -0.445360, -0.991970, -0.695320, -0.673090,
    0.539140, -0.004690, -0.696140, 0.991390, -0.159620, -0.654480, 0.332090, -0.944830, 1.040660, -0.260750,
    -0.171160, 0.970800, -0.561510, 0.737610, -0.836460, -0.283890, 0.287430, 0.107270, -0.459030, 0.715340,
    0.325180, 0.009620, -0.606220, 0.150110, -0.461700, -0.917060, 0.623170,
    0.689670, 0.990480, -0.542990, 0.188940, -0.584910, 0.496260, -0.167920, -0.050980, -0.134810, -0.098760,
    -0.756090, -0.714980, -0.357110, -0.533730, 0.163750, 0.919780, -0.952940, -0.719300, -0.117680, 0.413460,
    0.589420, 0.205630, -0.824980, -0.237430, -0.541080, 0.881840, -0.663190,
    0.855600, 0.729270, -0.054640, -0.626840, 1.127840, 0.103210, -0.667840, 0.748810, -0.776630, -0.778060,
    -0.405070, -0.306420, 0.866220, -0.283020, -0.022920, 0.612050, 0.796360, 0.161430, 0.674830, 0.171430,
    0.901720, -0.600030, 0.400830, -0.566460, 0.868480, -0.716310, -0.751250,
    -0.104530, 0.217190, 0.789710, -1.099150, -0.471560, 0.169830, 0.637830, 0.982860, -0.253790, -0.083680,
    0.491320, -0.197670, 0.805740, 0.707060, 0.401020, 0.272950, -0.700180, -0.217020, -0.371740, 0.637580,
    -0.148790, -0.801940, 0.726050, -0.005730, 0.614250, -0.746490, 0.802060,
    0.969080, 0.464680, 0.572910, -0.078640, 0.150600, 0.560500, -0.667650, 0.575220, -0.374270, -0.227910,
    0.118480, -0.242520, -0.033940, 0.208870, -0.756380, -1.013080, -0.191930, -0.388380, 0.165250, 0.572250,
    -0.006870, 0.310200, -0.971410, -0.149520, 0.649270, 0.123530, -0.892150,
    -0.952310, -0.246740, -0.755180, 0.602310, -0.128930, -0.494300, -0.732950, -0.742120, -0.622200, 0.745000,
    -0.613130, 0.158340, -0.428560, -0.543010, -0.091540, -0.617270, 0.460790, -0.479500, -0.659350, 0.476170,
    0.430190, 0.659690, 0.891730, 0.072410, 0.433600, -0.337910, -0.349440,
    -0.601800, -0.423620, -0.354160, 0.998630, -0.368810, -0.155440, 0.318730, -0.702870, 0.311800, -0.235120,
    -0.601700, 0.595110, -0.187000, 0.961900, 0.672500, -0.468120, 0.560460, 0.926700, 0.170230, 0.270600,
    -0.386770, -0.548740, -0.070660, -0.813420, -0.045720, -0.059620, 0.430040,
    0.246640, -0.014910, 0.527070, 0.374240, 0.778880, -0.423920, 0.457550, 0.267220, -0.225860, 0.209750,
    1.006340, -0.458410, 0.047560, -0.887410, -0.181460, 1.830580, 1.029160, -0.942700, -0.686730, 0.096790,
    0.282480, -0.723730, -0.277820, 0.254330, 1.066480, 0.670720, -0.527700,
    0.225940, -0.132840, 0.129020, 0.071290, 0.348790, 0.153050, -0.599440, -0.345050, -0.217990, -0.532240,
    -0.151690, 0.944840, 0.376520, 0.668060, 0.239270, -0.961720, -0.880980, -0.819780, -0.887270, -0.114000,
    0.466570, -0.287540, 0.156750, -0.900920, -0.758500, -0.874750, 0.693790,
    0.156390, 0.216990, -0.107120, 0.561570, 0.767670, -0.593320, 0.783900, -0.466200, 0.697980, -0.076940,
    -0.176440, 0.231190, -0.136010, 0.063060, 0.301990, -0.314330, 0.915970, -0.057050, -0.689160, 0.471600,
    0.037240, -0.755240, -0.073770, -0.357120, 0.879900, 0.293000, -1.087420,
    -0.400400, -0.861700, -0.165460, 0.468130, -0.803330, -0.611840, -0.804250, -0.897710, -0.043090, -0.308070,
    -0.459270, -0.259900, -0.286650, -0.752440, 0.466430, 0.422530, 0.812370, 0.949040, 0.624370, 0.163560,
    -0.374920, 0.466080, -0.187160, 1.028800, 0.583200, -0.816020, -0.356350,
    -0.257300, -0.570620, -0.712500, 0.221470, -1.086630, 0.598710, -0.543780, -0.668500, -0.347990, -0.527370,
    0.373380, 0.581080, 0.199280, 0.515810, -0.224840, 0.721950, -0.586810, 0.572260, 0.522720, -0.187290,
    -0.290870, 0.471890, -0.431300, -0.653190, 0.027070, -0.008250, 0.460050,
    0.620100, 0.829950, -0.299610, 0.830230, -0.033850, -0.155850, 0.835830, 0.458980, -0.447660, -0.032090,
    0.625610, -0.430590, -0.414530, 0.351520, -0.441710, -0.747150, -0.953870, 0.968400, 0.216350, -0.962160,
    -1.013820, -0.448560, -0.857360, 0.112850, -0.895770, -0.235560, -0.508420,
    0.946370, 0.577200, -0.105060, 0.416480, -0.096060, 0.674290, 0.748420, -0.841920, 0.010060, 0.640940,
    -0.392560, 0.930050, 0.700620, -0.564620, -0.126700, -0.503500, 0.453680, 0.347030, -0.908430, 0.620160,
    0.795810, 0.153280, -0.045100, 0.578980, 0.455130, 0.056950, -0.771570,
    -0.122260, -0.482380, 0.331510, 0.372600, -0.860430, -0.002270, -0.578100, 0.432890, -0.592420, -0.213400,
    -0.319840, 0.452260, -0.339280, 0.043780, -0.615220, 0.893270, 0.879950, 0.365590, -0.598680, -0.096460,
    -0.284620, 0.532250, 0.642420, 0.188660, 0.704380, 0.498140, -0.195750,
    -0.878440, 0.787070, 0.309930, -0.430170, -1.161080, 0.661940, -0.135500, 0.288830, 0.134550, -0.857870,
    0.660530, 0.705210, -0.910920, -0.786470, 0.534160, -0.023750, -0.727470, -0.813280, -0.762170, 0.413020,
    0.167060, 0.389370, -0.639780, 0.960770, 0.417370, -0.350290, -0.465600,
    -0.430390, 0.915130, -0.648510, 0.208020, 0.256530, -0.146210, 0.879970, -0.850580, -0.627540, -0.851960,
    0.973920, 0.268760, -0.622410, 0.864160, -0.604530, -0.107430, 0.023810, 0.479980, 0.616470, 0.174540,
    0.370020, -0.075310, 0.882670, 0.968200, -0.383700, 0.528220, 0.658820,
    0.083640, 0.493380, 0.132370, 0.144790, 0.983160, 0.896680, -0.515560, 0.436300, 0.634490, 0.548900,
    0.383600, -0.774380, -0.767480, 0.978530, 0.842530, 0.967110, 0.596260, -0.573520, 0.027200, 0.887230,
    -0.367900, -0.492550, -0.397250, -0.366800, -0.488440, 0.370410, 0.885160,
    -0.085570, 0.311540, 0.086210, 0.222740, 0.140230, -0.971470, -0.942990, 0.636830, 0.789460, 0.332800,
    0.360700, -0.901520, 0.346750, 0.475820, 0.653910, -0.410090, 0.543520, -0.122170, -0.839570, 0.281870,
    0.125380, -0.174430, 0.335870, -0.889740, -1.008680, 0.631310, -0.677490,
    -0.953390, -0.902110, 0.801060, 0.793090, 0.065220, -0.339090, -0.598910, 0.258270, -0.754510, -0.044110,
    -0.342480, -0.561050, 0.906990, 0.355470, -0.547900, -0.832000, -0.091430, 1.003270, 0.438130, 0.066130,
    0.334770, -0.230640, 1.045720, -0.684280, 0.556720, -0.661550, -0.811480,
    -0.637040, 0.604420, 0.437080, -0.629860, 0.601040, 0.525480, 0.699180, 0.449020, -0.350610, 0.675160,
    -0.497930, 0.332970, 0.659700, 0.400590, -0.304250, -0.827830, -0.464340, -0.203840, 0.355410, 0.230420,
    0.430490, -0.708960, -0.709410, -0.160320, 0.466360, -0.135360, 0.189490,
    0.983080, -0.766110, -0.591970, -0.642420, -0.218220, 0.071190, -0.543870, -0.296330, -0.057740, -0.764270,
    0.696750, -0.624850, 0.540830, 0.628220, 0.578170, -0.263980, -0.070290, 0.917620, 0.045790, 0.264160,
    -0.479280, 0.417210, -0.710890, -0.871470, -0.586220, 0.705410, -1.027990, 0.822030, -0.066480, 0.529340,
    0.620160, -0.667400, 0.591300, 0.782350, -0.714400, -0.045250, 0.509610, -0.823580, -0.643920, -1.211580,

    -0.960340, 0.478810, -0.469980, 0.774230, 0.376350, -0.719830, -0.517280, -0.597500, 0.425080, -0.506910,
    0.629090, 0.551400, 0.993250, 0.701870, -0.315230, -0.145030, -0.909710, -0.061210, 0.843680, -0.854980,
    -0.913350, 0.254690, -0.227990, -0.890110, 0.403500, 0.935890, -0.888500, -0.198600, -0.138870, -0.318260,
    -0.643410, -0.432420, -0.153560, 0.442430, -0.949260, 0.347680, 0.228600, -0.314250, -0.472430, -0.702620,

    1.070090, -1.501890, -0.355080, -0.973050, 0.116700, 0.867090, -1.097720, -0.823770, -1.009890, 0.269240,
    0.921830, 0.733520, -0.057830, -0.694110, -0.161060, -0.524560, 0.139380, -0.076300, 0.383070, -0.190340,
    0.629690, -0.777290, -0.913180, 0.005940, 0.978290, 0.940680, -1.162220, 1.120660, 0.305120, 0.561700,
    0.342340, 0.302020, 0.758770, 0.258900, 1.027050, 0.513030, -0.886160, -0.452670, 0.309500, 0.581100,

    -0.956660, 0.350040, -0.563590, 0.786080, 0.627160, 0.914360, 0.767300, 0.533950, 0.637790, -0.748090,
    -0.288160, 0.645100, -0.538710, -0.332500, 0.696640, -0.933890, -0.686880, 0.719860, 0.512120, -0.359100,
    0.835040, 0.659570, 0.854930, -0.051940, 0.397610, -0.814560, -0.869900, 0.316030, -0.437530, 0.233630,
    0.221890, 0.183050, 0.268570, -0.332700, 0.797800, 0.733180, -0.048530, -0.016390, 0.489500, 0.040960,

    -0.548010, -0.228120, -0.250120, 0.576760, 0.480410, 0.903540, -0.389720, 0.743480, 0.224080, -0.795560,
    0.051580, 0.683100, 0.679580, -0.482630, 0.680680, -0.676660, 0.943480, 0.154020, 0.945200, -0.063390,
    0.667640, 0.642920, -0.021670, -0.617690, -0.141390, -0.186960, 0.674990, -0.560060, -0.400900, -0.202860,
    -0.383230, -0.010530, 0.066680, 0.830190, 0.134740, 0.559000, 0.496830, -0.982320, 0.291330, 0.784170,

    -0.567390, -0.469450, -0.186540, -0.441210, 0.620340, -0.427820, 0.584710, 0.684030, 0.744580, 0.497750,
    -0.543770, -0.787310, 0.157510, -0.505020, 0.725700, 0.274900, -0.919600, 0.350600, 0.213850, 0.956320,
    0.677930, 0.771870, -0.386040, -0.851440, -0.238870, -0.950280, 0.013450, -0.678480, -0.606210, 0.311240,
    -0.007820, 0.485760, -0.240170, 0.810420, -0.817590, -0.532420, -0.802630, -0.016590, -0.787120, -0.377540,

    -0.265900, -0.629600, -0.987130, 0.348740, 0.535970, 0.608040, -0.301040, -0.474740, -0.486070, 0.032800,
    -0.603180, -0.973590, 0.081810, -0.879990, 0.703980, 0.363820, 0.078520, -0.715110, 0.413770, 0.774920,
    0.952360, -0.951370, -0.532410, 0.683000, -0.067890, -0.674980, 0.680860, 0.374670, 0.823420, 0.841190,
    -0.917970, 1.008490, 0.533370, 0.116060, 0.853350, 0.572980, -0.022030, 0.462800, 0.422450, 0.833210,

    -0.123130, -0.656280, 0.604300, 0.609930, -0.252130, -0.936460, -0.421500, -0.296220, -0.038590, 0.695690,
    0.577890, -0.074570, 0.663180, 0.335270, -0.832420, 0.172330, -0.757120, 0.330820, -0.637290, -0.065800,
    0.179080, -0.256780, -0.892410, -0.661060, -0.696530, -0.990670, -0.416810, -0.586470, -0.496210, 0.273620,
    -0.785930, 0.171550, -0.707840, -0.760600, -0.292100, 0.240320, -0.361280, 0.370810, 0.191870, 0.627120,

    -0.313740, 0.782620, 0.152860, 0.613060, -0.252850, -0.851500, 0.451400, -0.195410, -0.058560, 0.277970,
    0.844420, 0.685870, 0.492160, -0.079520, 0.828000, -0.884670, -0.101700, 0.930790, -0.155960, -0.842870,
    0.142440, 0.642220, 0.721210, -0.701890, 0.198000, -1.137520, 1.160270, 0.517960, 0.673140, -0.637250,
    -0.945460, -0.645620, -0.112520, 0.960090, -0.936060, -1.110880, 0.254640, 0.674060, 0.316240, -0.709480,

    0.121280, -0.508200, 0.013670, -0.612790, -0.883140, -0.636670, 0.064840, -0.082370, 0.785730, 0.883410,
    0.344450, -0.516270, -0.880350, 0.288270, -0.685980, 0.643010, -0.984830, -0.837390, -0.004360, -0.855040,
    0.768170, -0.818620, 0.474300, -0.470970, 0.278830, -0.665990, -0.592400, -0.462430, 0.185120, -0.274210,
    -0.961770, 0.282440, -0.059560, -0.889090, 0.352530, -0.860160, 0.991290, -0.403190, -0.029730, -0.811980,

    -0.216470, -0.546980, -0.762340, 0.233370, -0.354460, -0.732800, 0.296830, 0.482670, -0.411760, 0.637290,
    -0.078260, 0.217540, 0.303620, -0.687470, 0.546620, 0.519560, -0.698120, 0.238500, 0.838800, 0.031030,
    0.740440, 0.386580, 0.658370, 0.183250, 0.674300, 0.982500, 0.487120, 0.846970, 0.214760, 0.456610,
    0.040520, 0.302810, 0.050490, 0.883020, -0.139820, -0.985130, 0.558530, 0.947720, 0.351540, 0.689130,

    -0.584470, 1.000220, -0.937870, -0.990700, -0.509300, -0.884410, -0.239810, 0.369030, -0.753990, -0.426910,
    0.005940, -0.796190, -0.037810, 0.925330, 0.366420, -0.266640, 0.440720, 0.080910, -0.306530, -0.621670,
    0.902010, 0.397350, 0.516210, 0.622140, 0.685450, -0.703950, -0.778120, -0.715330, -0.562310, 0.134350,
    0.230740, -0.956860, -0.553800, 0.097670, -0.499920, 0.287740, -0.556810, -0.156810, 0.901240, 0.066240,

    0.745350, 0.379640, -0.173700, -0.660580, -0.780140, -0.390730, 0.108060, -0.729650, -0.188230, 0.210480,
    0.439530, 0.306910, 0.271850, 0.237130, 0.407520, -0.695000, -0.358550, -0.251920, 0.465890, 0.452070,
    -0.593220, -0.259880, 0.193020, 0.908980, 0.115860, -0.520300, -0.608110, -1.007120, -0.471160, 0.404220,
    -0.624440, 0.148450, 0.247760, 0.533950, -1.006610, 0.570350, -0.235500, 0.221360, 0.951430, -0.904530,

    0.457950, 0.746780, -0.034010, 0.098390, 0.413820, -0.305610, -0.415610, -0.903740, 0.641450, -0.962660,
    0.892620, 0.879480, -0.248500, -0.637150, -0.321940, 0.808570, 0.005180, -0.701660, 0.915000, -0.737040,
    -0.084550, 0.473480, 0.786970, -0.657680, -0.725040, 0.480450, 0.864380, 0.605200, 0.838520, -0.400660,
    0.779290, -0.832050, -0.116890, -0.139600, -0.595110, -0.054260, -0.823070, 0.329750, 0.902280, -0.869840,

    -0.223690, -0.715310, -0.015100, -0.723840, -0.242950, -0.593620, -0.180180, -0.287840, -0.421830, -0.244940,
    -0.128320, -0.458200, -0.991170, 0.347790, -0.222960, 0.740280, -0.676180, -0.642950, -0.096850, -0.828840,
    -0.839210, -0.249060, -0.449260, 0.359680, 0.205560, -0.266320, -0.856880, -0.991900, 0.920130, -0.110480,
    0.348690, -0.115340, -0.473870, 0.648090, -0.163390, 0.523090, 0.317760, 0.626410, 0.332320, 0.855530,

    0.922010, -0.410420, 0.462760, -0.649350, -0.856860, 0.868800, -0.785830, 0.557020, 0.231700, -0.816500,
    0.815500, -0.787290, 0.152550, 0.005950, -0.175180, 0.418420, -0.385330, -0.106530, 0.746400, -0.988220,
    0.781760, 0.242970, 0.324910, 0.891930, 0.224770, -0.431330, -0.409780, 0.724290, 0.515900, -0.173410,
    0.328290, -0.415880, -0.416550, -0.758080, 0.492850, -0.402550, 0.837610, 0.106050, 0.635110, -0.458850,

    0.172630, -0.483880, -0.684310, 0.183080, -0.089250, 0.125400, 0.580720, -0.382460, 0.238290, -1.020600,
    0.066170, 0.216100, 0.207940, -0.507740, -0.023640, 0.759940, 0.765570, 0.196760, -0.414050, 0.700720,
    0.707460, 0.720340, -0.585360, 0.543690, -0.113780, 0.269490, 0.189100, 0.287190, -0.825970, 0.563330,
    0.510640, 0.231490, -0.764530, -0.036030, -0.545090, -0.600460, 0.608600, 0.779450, -1.090980, 0.937380,

    -0.039130, -0.890370, 0.472080, -0.522740, -0.851330, 0.886860, 0.344810, -0.737380, -0.092270, 0.949060,
    -0.803680, -0.549650, -0.683970, 0.494720, -0.715780, 0.031340, -0.654470, -0.302600, -0.313930, -0.290990,
    -0.535860, 0.265790, -0.824400, 1.073470, 0.709360, 0.670420, -0.800740, -0.239050, 0.587790, -0.748780,
    0.647880, 1.027060, -0.638100, 0.685210, 0.218960, 0.116530, -0.023660, -0.196040, 0.762490, -0.379460,

    0.485000, 0.172610, 0.393290, -1.121860, -0.166220, 0.690150, 0.310060, 0.657040, 0.119890, 0.027310,
    -0.103810, -0.125590, -0.803280, -0.263080, 0.187740, 0.979260, -0.361830, 0.741810, 0.805740, -0.646610,
    -0.217240, 0.371700, 1.042490, -0.300700, -0.477980, 0.996680, -0.287420, -0.880970, -1.001380, -0.031260,
    0.132620, 0.181970, -0.432140, 0.018920, -0.877020, 0.106530, 0.723010, 0.949820, 0.172590, -0.137760,

    0.436560, 0.591970, 0.267720, -0.927440, -0.257040, -0.313450, -0.293770, 0.520370, -0.900010, -0.676330,
    0.017550, 0.752210, 0.545240, -0.913690, -0.377650, -0.413640, 0.229420, -0.766220, -0.069040, -0.351250,
    0.596030, 0.159530, -0.039810, 0.837000, -0.959790, -0.343760, -0.330830, 0.251220, 0.585750, -0.459300,
    -0.133880, -0.449950, -0.929920, -0.826550, 0.327510, -0.953130, 0.174670, -0.786950, -0.393580, 0.786330,

    1.123390, 0.833890, 1.914680, -1.113360, 0.677400, 0.451900, -0.771540, -0.860690, -1.433950, 0.390160,
    -0.703310, -0.463820, 0.234610, 0.106910, 0.388490, 0.378920, 0.555230, 1.024080, 0.579310, -0.072530,


};

/* unit definition section (see also UnitType) */
static UnitType Units[89] =
{
    { 0.0, 0.0, 0, NULL, NULL },
    { /* unit 1 (Old: 1) */
        0.0, 0.207070, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 2 (Old: 2) */
        0.0, -0.680970, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 3 (Old: 3) */
        0.0, 0.293330, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 4 (Old: 4) */
        0.0, 0.106830, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 5 (Old: 5) */
        0.0, 0.362610, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 6 (Old: 6) */
        0.0, -0.772860, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 7 (Old: 7) */
        0.0, 0.968830, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 8 (Old: 8) */
        0.0, -0.168180, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 9 (Old: 9) */
        0.0, 0.681260, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 10 (Old: 10) */
        0.0, 0.232570, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 11 (Old: 11) */
        0.0, -0.382010, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 12 (Old: 12) */
        0.0, 0.882280, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 13 (Old: 13) */
        0.0, -0.799710, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 14 (Old: 14) */
        0.0, 0.672910, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 15 (Old: 15) */
        0.0, 0.681860, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 16 (Old: 16) */
        0.0, -0.066130, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 17 (Old: 17) */
        0.0, -0.208290, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 18 (Old: 18) */
        0.0, -0.165400, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 19 (Old: 19) */
        0.0, 0.460060, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 20 (Old: 20) */
        0.0, 0.219040, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 21 (Old: 21) */
        0.0, 0.413200, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 22 (Old: 22) */
        0.0, -0.484750, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 23 (Old: 23) */
        0.0, 0.402950, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 24 (Old: 24) */
        0.0, 0.848920, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 25 (Old: 25) */
        0.0, 0.190030, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 26 (Old: 26) */
        0.0, -0.714760, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 27 (Old: 27) */
        0.0, -0.883940, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 28 (Old: 28) */
        0.0, -0.317790, 27,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 29 (Old: 29) */
        0.0, 0.196890, 27,
        &Sources[27],
        &Weights[27],
    },
    { /* unit 30 (Old: 30) */
        0.0, -0.668420, 27,
        &Sources[54],
        &Weights[54],
    },
    { /* unit 31 (Old: 31) */
        0.0, 0.552270, 27,
        &Sources[81],
        &Weights[81],
    },
    { /* unit 32 (Old: 32) */
        0.0, -0.840020, 27,
        &Sources[108],
        &Weights[108],
    },
    { /* unit 33 (Old: 33) */
        0.0, 0.429700, 27,
        &Sources[135],
        &Weights[135],
    },
    { /* unit 34 (Old: 34) */
        0.0, 0.715600, 27,
        &Sources[162],
        &Weights[162],
    },
    { /* unit 35 (Old: 35) */
        0.0, -0.214250, 27,
        &Sources[189],
        &Weights[189],
    },
    { /* unit 36 (Old: 36) */
        0.0, 0.325270, 27,
        &Sources[216],
        &Weights[216],
    },
    { /* unit 37 (Old: 37) */
        0.0, -0.296290, 27,
        &Sources[243],
        &Weights[243],
    },
    { /* unit 38 (Old: 38) */
        0.0, -0.905300, 27,
        &Sources[270],
        &Weights[270],
    },
    { /* unit 39 (Old: 39) */
        0.0, -1.022670, 27,
        &Sources[297],
        &Weights[297],
    },
    { /* unit 40 (Old: 40) */
        0.0, -1.004950, 27,
        &Sources[324],
        &Weights[324],
    },
    { /* unit 41 (Old: 41) */
        0.0, 0.943190, 27,
        &Sources[351],
        &Weights[351],
    },
    { /* unit 42 (Old: 42) */
        0.0, 0.074820, 27,
        &Sources[378],
        &Weights[378],
    },
    { /* unit 43 (Old: 43) */
        0.0, -0.849210, 27,
        &Sources[405],
        &Weights[405],
    },
    { /* unit 44 (Old: 44) */
        0.0, 0.179530, 27,
        &Sources[432],
        &Weights[432],
    },
    { /* unit 45 (Old: 45) */
        0.0, -1.051630, 27,
        &Sources[459],
        &Weights[459],
    },
    { /* unit 46 (Old: 46) */
        0.0, -0.929750, 27,
        &Sources[486],
        &Weights[486],
    },
    { /* unit 47 (Old: 47) */
        0.0, -0.717240, 27,
        &Sources[513],
        &Weights[513],
    },
    { /* unit 48 (Old: 48) */
        0.0, -0.341190, 27,
        &Sources[540],
        &Weights[540],
    },
    { /* unit 49 (Old: 49) */
        0.0, -0.054160, 27,
        &Sources[567],
        &Weights[567],
    },
    { /* unit 50 (Old: 50) */
        0.0, -0.290830, 27,
        &Sources[594],
        &Weights[594],
    },
    { /* unit 51 (Old: 51) */
        0.0, 0.304650, 27,
        &Sources[621],
        &Weights[621],
    },
    { /* unit 52 (Old: 52) */
        0.0, 0.193630, 27,
        &Sources[648],
        &Weights[648],
    },
    { /* unit 53 (Old: 53) */
        0.0, -0.850790, 27,
        &Sources[675],
        &Weights[675],
    },
    { /* unit 54 (Old: 54) */
        0.0, -0.517140, 27,
        &Sources[702],
        &Weights[702],
    },
    { /* unit 55 (Old: 55) */
        0.0, 0.400040, 27,
        &Sources[729],
        &Weights[729],
    },
    { /* unit 56 (Old: 56) */
        0.0, -0.514280, 27,
        &Sources[756],
        &Weights[756],
    },
    { /* unit 57 (Old: 57) */
        0.0, -0.796030, 27,
        &Sources[783],
        &Weights[783],
    },
    { /* unit 58 (Old: 58) */
        0.0, 0.758630, 27,
        &Sources[810],
        &Weights[810],
    },
    { /* unit 59 (Old: 59) */
        0.0, 0.750160, 27,
        &Sources[837],
        &Weights[837],
    },
    { /* unit 60 (Old: 60) */
        0.0, -0.032930, 27,
        &Sources[864],
        &Weights[864],
    },
    { /* unit 61 (Old: 61) */
        0.0, 0.356880, 27,
        &Sources[891],
        &Weights[891],
    },
    { /* unit 62 (Old: 62) */
        0.0, 0.443260, 27,
        &Sources[918],
        &Weights[918],
    },
    { /* unit 63 (Old: 63) */
        0.0, -0.850630, 27,
        &Sources[945],
        &Weights[945],
    },
    { /* unit 64 (Old: 64) */
        0.0, -0.802710, 27,
        &Sources[972],
        &Weights[972],
    },
    { /* unit 65 (Old: 65) */
        0.0, -0.921330, 27,
        &Sources[999],
        &Weights[999],
    },
    { /* unit 66 (Old: 66) */
        0.0, -0.439290, 27,
        &Sources[1026],
        &Weights[1026],
    },
    { /* unit 67 (Old: 67) */
        0.0, -0.265590, 27,
        &Sources[1053],
        &Weights[1053],
    },
    { /* unit 68 (Old: 68) */
        0.0, -1.008350, 40,
        &Sources[1080],
        &Weights[1080],
    },
    { /* unit 69 (Old: 69) */
        0.0, 0.249780, 40,
        &Sources[1120],
        &Weights[1120],
    },
    { /* unit 70 (Old: 70) */
        0.0, -0.811270, 40,
        &Sources[1160],
        &Weights[1160],
    },
    { /* unit 71 (Old: 71) */
        0.0, 0.214780, 40,
        &Sources[1200],
        &Weights[1200],
    },
    { /* unit 72 (Old: 72) */
        0.0, 0.055230, 40,
        &Sources[1240],
        &Weights[1240],
    },
    { /* unit 73 (Old: 73) */
        0.0, -0.825460, 40,
        &Sources[1280],
        &Weights[1280],
    },
    { /* unit 74 (Old: 74) */
        0.0, 0.677410, 40,
        &Sources[1320],
        &Weights[1320],
    },
    { /* unit 75 (Old: 75) */
        0.0, -0.888090, 40,
        &Sources[1360],
        &Weights[1360],
    },
    { /* unit 76 (Old: 76) */
        0.0, -0.961650, 40,
        &Sources[1400],
        &Weights[1400],
    },
    { /* unit 77 (Old: 77) */
        0.0, -0.560800, 40,
        &Sources[1440],
        &Weights[1440],
    },
    { /* unit 78 (Old: 78) */
        0.0, 0.616220, 40,
        &Sources[1480],
        &Weights[1480],
    },
    { /* unit 79 (Old: 79) */
        0.0, 0.355590, 40,
        &Sources[1520],
        &Weights[1520],
    },
    { /* unit 80 (Old: 80) */
        0.0, -0.260300, 40,
        &Sources[1560],
        &Weights[1560],
    },
    { /* unit 81 (Old: 81) */
        0.0, 0.709150, 40,
        &Sources[1600],
        &Weights[1600],
    },
    { /* unit 82 (Old: 82) */
        0.0, -0.934050, 40,
        &Sources[1640],
        &Weights[1640],
    },
    { /* unit 83 (Old: 83) */
        0.0, 0.085270, 40,
        &Sources[1680],
        &Weights[1680],
    },
    { /* unit 84 (Old: 84) */
        0.0, 0.043290, 40,
        &Sources[1720],
        &Weights[1720],
    },
    { /* unit 85 (Old: 85) */
        0.0, -0.700770, 40,
        &Sources[1760],
        &Weights[1760],
    },
    { /* unit 86 (Old: 86) */
        0.0, 0.641930, 40,
        &Sources[1800],
        &Weights[1800],
    },
    { /* unit 87 (Old: 87) */
        0.0, -0.149110, 40,
        &Sources[1840],
        &Weights[1840],
    },
    { /* unit 88 (Old: 88) */
        0.0, 0.175440, 20,
        &Sources[1880],
        &Weights[1880],
    }

};



int n(float* in, float* out, int init)
{
    int member, source;
    float sum;
    enum {OK, Error, Not_Valid};
    pUnit unit;
    /* layer definition section (names & member units) */
    static pUnit Input[27] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27}; /* members */
    static pUnit Hidden1[40] = {Units + 28, Units + 29, Units + 30, Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67}; /* members */
    static pUnit Hidden2[20] = {Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80, Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87}; /* members */
    static pUnit Output1[1] = {Units + 88}; /* members */
    static int Output[1] = {88};
    for (member = 0; member < 27; member++)
    {
        Input[member]->act = in[member];
    }
    for (member = 0; member < 40; member++)
    {
        unit = Hidden1[member];
        sum = 0.0;
        for (source = 0; source < unit->NoOfSources; source++)
        {
            sum += unit->sources[source]->act
                   * unit->weights[source];
        }
        unit->act = Act_Logistic(sum, unit->Bias);
    };
    for (member = 0; member < 20; member++)
    {
        unit = Hidden2[member];
        sum = 0.0;
        for (source = 0; source < unit->NoOfSources; source++)
        {
            sum += unit->sources[source]->act
                   * unit->weights[source];
        }
        unit->act = Act_Logistic(sum, unit->Bias);
    };
    for (member = 0; member < 1; member++)
    {
        unit = Output1[member];
        sum = 0.0;
        for (source = 0; source < unit->NoOfSources; source++)
        {
            sum += unit->sources[source]->act
                   * unit->weights[source];
        }
        unit->act = Act_Logistic(sum, unit->Bias);
    };
    for (member = 0; member < 1; member++)
    {
        out[member] = Units[Output[member]].act;
    }
    return (OK);
}
