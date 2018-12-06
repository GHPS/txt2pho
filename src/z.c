/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    z.c
    --------------------------------------------------------
    generated at Tue Jun 23 15:53:33 1998
    by snns2c ( Bernward Kett 1995 )
*********************************************************/

#ifdef IPHONDURNET

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
    -0.672170, 0.990740, 0.068580, -0.066900, -0.577770, 0.472340, -0.988200, 0.387990, -0.189680, -0.214930,
        0.584140, -0.764130, 0.377470, 0.696280, 0.314830, 0.245620, -0.297370, -0.503780, -0.213240, -0.056160,
        0.081590, -0.299080, 0.359530, -0.891530, 0.256070, -0.897280, 0.983160,
        0.427760, 0.970230, -0.166350, 0.599590, -0.688950, 0.870450, 0.626120, 0.389790, -0.766420, 0.003500,
        -0.428570, 0.467990, -0.646070, -0.351080, 0.138520, -0.911480, -0.550350, 0.229310, 0.566420, 0.254500,
        0.399370, -0.338940, -0.419210, -0.072500, -0.669350, 0.283590, -0.604430,
        0.627260, -0.878350, 0.169790, 0.003820, 0.890490, -0.836280, -0.669250, -0.525090, 0.209360, -0.397150,
        -0.510000, 0.217900, 0.790590, 0.030730, 0.582170, -0.777320, -0.050070, 0.991600, -0.725540, 0.957020,
        -0.620440, 0.532050, 0.388700, -0.911210, -0.869680, -0.609000, 0.036030,
        -0.147960, 0.422110, 0.358640, 0.479980, 0.659950, 0.999920, 0.909390, 0.517660, 0.171030, -0.397690,
        0.563910, -0.005100, 0.864660, 0.213870, 0.040570, 0.568160, 0.563570, -0.832110, 0.301050, 0.614450,
        0.576280, -0.259780, 0.898580, -0.559400, 0.941810, 0.112500, 0.650520,
        -0.811730, 0.063240, -0.737700, -0.385930, -0.826070, 0.103980, 0.237560, -0.786410, -0.388600, -0.668570,
        -0.465900, -0.295120, -0.334370, -0.154420, 0.468210, -0.859950, -0.318230, 0.904120, 0.268140, -0.237490,
        0.714290, 0.258480, -0.287650, 0.983340, -0.676810, 0.875100, -0.466770,
        -0.796990, 0.237980, 0.340070, 0.547450, -0.343210, 0.501530, 0.417830, 0.498700, -0.867550, 0.727150,
        0.466980, -0.090370, 0.306710, -0.730160, 0.371350, -0.335280, -0.696830, -0.745740, -0.331330, 0.861850,
        -0.807760, 0.498850, -0.207270, -0.724950, -0.691580, 0.234610, -0.536880,
        -0.665340, -0.123650, -0.720480, 0.305260, -0.374750, 0.321700, -0.838960, -0.916050, 0.743710, -0.935000,
        0.917520, -0.245130, 0.886670, 0.247050, -0.068040, 0.462370, -0.124360, -0.204190, -0.623780, 0.119980,
        0.947320, 0.081140, 0.425150, 0.427240, 0.617130, 0.954340, -0.654700,
        0.770030, -0.467100, 0.763940, 0.554180, -0.910480, -0.492710, -0.621980, -0.652570, 0.477800, 0.471160,
        0.312560, 0.213960, -0.035030, 0.467180, 0.197690, -0.753220, 0.897980, 0.411970, 0.207890, -0.117110,
        0.401290, -0.655590, 0.021460, 0.806150, 0.464950, -0.846390, -0.953190,
        -0.779830, 0.511780, 0.233400, -0.526180, 0.070620, -0.761810, 0.077850, -0.131560, -0.912100, 0.301660,
        0.166990, 0.659440, 0.513720, 0.325650, 0.049490, 0.964820, -0.384780, 0.885290, -0.122640, 0.374000,
        0.443450, 0.027900, 0.909620, -0.935680, -0.464240, -0.603850, 0.667450,
        -0.469380, -0.686070, -0.233120, -0.896720, 0.036600, -0.058750, 0.944490, -0.216370, 0.918490, -0.194240,
        0.198660, -0.790990, 0.341990, 0.378330, -0.704440, -0.476080, 0.801070, 0.317630, 0.185190, -0.973110,
        -0.259340, -0.657680, 0.137970, -0.586350, 0.876540, 0.717300, -0.084440,
        -0.758590, 0.223520, 0.190260, -0.678290, 0.466080, 0.785270, -0.052500, -0.555840, 0.709070, -0.611380,
        -0.473890, 0.184680, 0.088020, 0.311080, 0.191490, 0.949640, -0.029350, -0.437370, 0.538860, -0.379400,
        -0.543360, -0.501930, 0.774820, 0.298380, -0.834490, -0.521660, 0.447850,
        0.141870, 0.925350, -0.208220, 0.955840, -0.562430, 0.738530, 0.175690, 0.564310, -0.142170, 0.563370,
        -0.594870, -0.492120, 0.062660, 0.429460, -0.705810, 0.087760, -0.692280, 0.145110, 0.318730, -0.897280,
        0.504940, 0.266980, 0.151660, -0.034620, -0.788870, -0.136770, -0.381720,
        0.636940, -0.139480, 0.931810, 0.581670, 0.659090, -0.100520, 0.531020, 0.577510, 0.868840, 0.600440,
        -0.816460, -0.564220, 0.379870, 0.155980, -0.986680, -0.588610, 0.208000, 0.637970, 0.539200, -0.467670,
        -0.065390, -0.343060, 0.594650, 0.040370, -0.150880, 0.782780, 0.447360,
        -0.099650, -0.769090, 0.879660, 0.906300, 0.523480, 0.360280, -0.675490, 0.731900, -0.914290, 0.138630,
        0.851840, -0.572270, 0.148310, 0.157640, -0.359490, 0.591430, 0.763650, 0.501820, -0.300840, 0.726830,
        0.371220, -0.637040, 0.964450, -0.817890, 0.263080, -0.157780, 0.506170,
        -0.351370, -0.525250, 0.625350, 0.691160, 0.591980, 0.436070, -0.925290, 0.446330, -0.380490, -0.666540,
        -0.647950, 0.858250, 0.743680, 0.138040, -0.569390, 0.728760, 0.139050, 0.816270, -0.539700, -0.279090,
        -0.511370, -0.121000, 0.781020, -0.538180, -0.071360, -0.074600, 0.381960,
        0.144600, 0.011950, -0.413380, 0.458560, -0.645640, -0.769540, 0.962460, 0.788580, 0.445180, -0.968120,
        0.260310, -0.648800, -0.728220, 0.421170, -1.000820, 0.982140, 0.849560, -0.933510, -0.367280, 0.406060,
        -0.453770, -0.870180, -0.311800, -0.852370, -0.093780, -0.946020, 0.515140,
        -0.172430, -0.553770, 0.648750, -0.697600, 0.836890, -0.900600, -0.314780, 0.035000, -0.102810, 0.979360,
        0.271950, 0.303170, -0.374060, -0.087610, -0.293210, -0.228640, 0.479050, 0.772000, 0.430860, -0.090520,
        -0.800050, 0.175830, -0.882170, 0.613480, -0.013450, -0.250800, 0.686860,
        -0.114520, 0.695150, -0.053830, 0.659910, 0.520320, 0.268510, 0.880760, -0.251110, 0.497980, -0.914040,
        -0.306760, 0.537510, 0.146020, -0.685450, 0.210020, 0.655900, -0.831530, -0.374290, 0.679270, -0.557390,
        -0.362520, 0.579510, -0.595110, 0.575000, 0.468200, -0.340100, -0.865900,
        -0.567600, -0.595200, -0.985070, -0.408750, -0.287910, 0.814160, -0.439620, 0.691520, 0.382340, 0.146500,
        0.227900, 0.003570, -0.737230, -0.649800, -0.155460, -0.336020, 0.728500, -0.686150, -0.389360, 0.579940,
        0.833110, 0.167970, -0.650300, 0.440350, 0.345410, -0.048720, 0.929290,
        0.644300, -0.934190, -0.453780, 0.104710, -0.595240, 0.012950, 0.359280, 0.693220, -0.466420, 0.095880,
        0.300810, -0.230330, -0.869800, 0.724230, -0.528420, 0.939780, -0.173680, -0.318210, 0.973150, -0.930770,
        0.329170, -0.688610, -0.206130, 0.977940, -0.708510, -0.024920, 0.534070,
        -0.578760, 0.881330, -0.500200, -0.196440, -0.801940, 0.257220, 0.705670, 0.347420, -0.126010, -0.748170,
        -0.859610, 0.951160, 0.228330, -0.533630, -0.287040, -0.748380, -0.567550, -0.140580, -0.169030, -0.137660,
        -0.115390, 0.477980, -0.483740, 0.203890, -0.583760, 0.986070, 0.701760,
        -0.908600, -0.839360, 0.799500, -0.604870, 0.362280, -0.666410, 0.899080, 0.240130, 0.674400, 0.212090,
        0.709050, 0.352600, 0.044120, -0.289880, 0.754170, -0.253900, -0.484310, -0.778240, -0.785840, 0.809230,
        -0.760000, 0.222320, 0.983850, -0.528630, -0.007480, 0.786390, 0.848320,
        0.863590, -0.556600, 0.682820, 0.163940, 0.954900, -0.618920, -0.299680, 0.688100, -0.223660, -0.093580,
        -0.764270, 0.025650, 0.304760, 0.768170, 0.821990, 0.073730, 0.740040, -0.333150, -0.370390, 0.994170,
        0.426180, 0.435840, -0.556060, -0.935980, 0.711260, 0.305170, 0.063400,
        -0.871250, 0.227110, 0.698180, -0.077170, -0.851950, 0.293340, 0.211490, 0.545740, 0.107180, -0.491380,
        -0.189300, -0.850960, -0.730940, 0.207820, 0.078990, -0.355120, 0.161480, -0.254960, -0.417780, 0.499690,
        -0.736150, 0.445810, 0.238780, -0.143600, 0.533280, 0.409320, 1.002640,
        -0.285670, -0.309130, 0.472610, 0.082950, 0.897160, 0.578960, 0.514010, 0.479610, -0.679190, -0.514050,
        0.533290, -0.417260, -0.082990, -0.550940, -0.372800, 0.020650, -0.664420, 0.773050, -0.603500, -0.735390,
        -0.609650, -0.595110, -0.022550, 0.546840, -0.750280, -0.284960, -0.973150,
        0.427210, 0.081260, 0.093520, -0.923510, -0.038420, -0.564620, -0.312310, 0.123590, 0.109860, 0.957340,
        0.617640, -0.195590, 0.779300, 0.919930, -0.169510, 0.395300, -0.702580, -0.098140, 0.310710, -0.612970,
        0.355520, -0.150010, -0.343250, 0.925730, -0.222870, -0.413460, -0.578030,
        -0.794000, 0.686680, 0.854520, -0.069510, -0.403160, -0.923780, 0.097060, 0.211400, -0.474540, -0.916780,
        0.851930, 0.994590, -0.170460, -0.994420, -0.159970, -0.427590, 0.859720, -0.160530, -0.353090, 0.063300,
        0.108900, -0.512140, 0.474180, 0.343180, 0.230100, 0.148780, 0.190100,
        0.792930, -0.958050, -0.653010, -0.843930, 0.069970, -0.329070, 0.480070, -0.130500, -0.910110, -0.760930,
        -0.870660, -0.768920, 0.274070, 0.700130, 0.512330, 0.977280, -0.179720, -0.450400, -0.140780, -0.262590,
        -0.412300, 0.118650, 0.354870, 0.085460, 0.204000, -0.154180, 0.185780,
        -0.968680, 0.274890, 0.939570, -0.332410, -0.175230, -1.000930, 0.049890, 0.563790, -0.679470, -0.079180,
        0.907060, -0.299230, 0.306350, 0.072430, 0.009810, 0.080940, -0.268280, -0.161210, 0.689870, -0.443100,
        0.915040, -0.687430, 0.711470, 0.506410, -0.199430, 0.210350, 0.202510,
        -0.361470, -0.838610, 0.661730, 0.971130, -0.253970, 0.391360, -0.256510, 0.088540, 0.507280, 0.914410,
        0.800730, 0.625450, 0.534380, -0.768160, -0.143680, -0.421260, -0.503000, -0.256010, -0.043540, -0.865740,
        -0.695670, -0.798820, -0.835630, 0.364310, -0.127740, -0.898360, -0.459710,
        0.383770, -0.111230, -0.030490, -0.572580, -0.390750, 0.672410, -0.329850, -0.120580, 0.492100, 0.541920,
        -0.607460, 0.729060, -0.322330, 0.550010, -0.069600, 0.640410, 0.420630, -0.293870, -0.297730, -0.583170,
        -0.732060, 0.723570, -0.905280, 0.278860, -0.561770, -0.629830, -0.374990,
        -0.319630, -0.198780, -0.872620, 0.131020, -0.763410, -0.320640, -1.088470, -0.982040, 0.215090, 0.984670,
        -0.816170, -0.402450, -0.581480, 0.363950, -0.381750, -0.416850, 0.662540, 0.026200, -0.447990, 0.518410,
        0.944210, -0.154050, 0.137590, 0.845410, -0.198080, 0.807360, 0.559240,
        -0.727620, 0.060450, 0.481510, 0.595090, -0.055810, 0.184730, 0.775930, 0.613640, -0.883790, 0.367950,
        0.512750, -0.436970, -0.097600, -0.559460, 0.743370, 0.924820, -0.387180, 0.660390, 0.027540, -0.822280,
        0.838520, 0.704840, -0.052730, 0.428300, -0.090810, 0.587400, 0.950710,
        -0.135890, 0.522890, 0.769190, 0.336300, 0.722970, 0.562010, -0.236490, -0.058320, -0.626810, 0.383170,
        0.927650, 0.982470, -0.548360, 0.088820, -0.312230, 0.451860, -0.273650, -0.142100, -0.525240, 0.495410,
        -0.493620, 0.046350, -0.731260, 0.451430, 0.378760, -0.457170, -0.093000,
        -0.278730, -0.294070, 0.510570, 0.952620, -0.675500, 0.461780, 0.104080, 0.340430, -0.740370, -0.871480,
        -0.560270, 0.330080, 0.373460, -0.787090, -0.816570, 0.622760, 0.688020, -0.826420, 0.085180, 0.222140,
        -0.013490, 0.560000, -0.960910, -0.537830, 0.276220, 0.726600, -0.913230,
        0.731120, 0.525850, -0.379670, 0.864380, 0.846320, -0.022110, 0.254610, 0.142030, 0.638460, 0.494920,
        0.069550, -0.012750, -0.704570, 0.833780, -0.610080, 0.262540, 0.967750, -0.821080, -0.649170, -0.882240,
        0.792040, -0.242180, 0.260270, 0.099640, -0.652990, 0.854930, -0.491850,
        0.801720, 0.247600, -0.523340, -0.367090, -0.380460, -0.483000, -0.418280, 0.915870, -0.007260, -0.526140,
        0.557500, 0.864880, 0.860930, 0.983840, -0.897420, -0.759420, 0.333230, 0.631470, 0.637670, 0.569700,
        -0.618820, 0.982050, 0.970140, 0.255200, 0.235280, 0.498020, 0.086450,
        -0.615060, 0.714000, -0.965680, -0.871230, 0.303390, -0.165910, 0.040550, 0.256720, -0.846500, -0.105570,
        0.535930, -0.443980, 0.649810, 0.484840, 0.386820, -0.892640, 0.451360, 0.271260, 0.703390, 0.608900,
        -0.966610, -0.957010, 0.061970, 0.170230, 0.052200, 0.310860, -0.056860,
        -0.897660, -0.610600, 0.544850, -0.734330, 0.979350, -0.320550, 0.501670, 0.038660, 0.441420, 0.910500,
        -0.152700, -0.909960, -0.422240, 0.331330, 0.956290, -0.661380, -0.368980, -0.077400, -0.691020, 0.122730,
        -0.545770, -0.494440, 0.028380, 0.714960, 0.718680, -0.869230, -0.948470,
        0.243580, -0.047670, 0.495460, -0.184890, -0.647720, -0.689980, 0.581180, 0.158950, 0.352550, -0.300530,
        -0.348670, -0.634920, -0.271080, 0.372410, 0.771680, 0.209130, -0.400090, 0.664920, -0.320300, 0.318640,
        0.851050, 0.414140, 0.690450, -0.696420, 0.358440, 0.598490, -0.638020,
        -0.993270, -0.452320, -0.758790, 0.636250, -0.245040, -0.472660, 0.851800, 0.763690, -0.515700, 0.570450,
        0.675700, 0.030870, 0.813400, -0.863330, 0.751700, -0.610510, -0.894760, -0.636020, 0.469790, -0.372180,
        0.339670, 0.130060, 0.941200, 0.099590, -0.391610, 0.624460, 0.719760, 0.508020, -0.613420, 0.434160,
        -0.706190, 0.071010, -0.043910, -0.445960, 0.082140, -0.172870, -0.558870, -0.481810, -0.504240, 0.746280,

        -0.677620, -0.425620, -0.307280, 0.278320, 0.285870, -0.891110, 0.518090, -0.026320, -0.406460, -0.680740,
        -0.245710, -0.142020, -0.204790, -0.813930, 0.949890, 0.402580, -0.796360, -0.378450, 0.292500, -0.767500,
        -0.948180, 0.771020, -0.057960, -0.855790, -0.228550, -0.130000, 0.614750, 0.989930, 0.484910, 0.569730,
        -0.316340, 0.591950, -0.726110, -0.402410, -0.716930, 0.408460, 0.920170, -0.478170, 0.416830, -0.975640,

        0.817440, 0.295610, -0.428750, -0.627340, 0.485110, 0.900920, 0.408430, 0.894750, 0.150220, 0.181850,
        0.681350, 0.539720, 0.764290, -0.619080, 0.936270, 0.783490, -0.463790, -0.747590, -0.660020, 0.710720,
        -0.299220, 0.207610, -0.092650, 0.019900, -0.829470, -0.019930, -0.646880, -0.144120, 0.634680, 0.696640,
        0.221900, -0.502150, -0.455790, -0.957680, 0.612710, 0.105170, -0.815360, -0.237460, -0.904740, 0.905890,

        0.033160, 0.465110, -0.022650, -0.066870, 0.775740, 0.768140, -0.300440, 0.282270, 0.170100, 0.220300,
        0.232880, -0.422320, 0.283990, -0.830880, -0.810880, 0.382230, -0.062560, 0.904750, 0.687790, 0.843020,
        -0.376180, 0.510490, 0.704050, -0.706260, -0.926740, 0.707540, -0.332650, -0.536560, 0.623510, -0.293940,
        -0.752480, 0.670280, 0.537080, 0.770010, 0.919880, 0.629120, 0.809830, -0.569700, 0.361940, -0.933800,

        0.776160, 0.281160, -0.981380, 0.503990, 0.529130, 0.104190, 0.799430, 0.045790, -0.042760, -0.427440,
        -0.213020, -0.398690, -0.604890, 0.692940, -0.203740, -0.153200, -0.660230, -0.063660, 0.632870, 0.668310,
        -0.087170, 0.924860, 0.130560, 0.920570, -0.706910, 0.662860, -0.513820, 0.660930, 0.665970, 0.027900,
        -0.791920, 0.230910, 0.723300, -0.408570, 0.868130, 0.473850, 0.549100, -0.256430, -0.214110, -0.573500,

        -0.384940, -0.789740, -0.031360, -0.789070, -0.552660, -0.793860, 0.913540, -0.139620, 0.495460, 0.011890,
        0.395080, -0.602100, -0.682560, 0.097930, -0.906860, -0.221500, -0.805020, -0.386580, 0.829640, 0.766080,
        0.897960, 0.210480, 0.344850, -0.876840, 0.268460, 0.841190, -0.545160, 0.158310, -0.862060, -0.547590,
        0.623480, 0.824370, 0.692460, 0.668620, -0.400280, 0.675030, -0.295530, -0.228960, -0.485280, -0.578310,

        0.833590, 0.338030, 0.455750, 0.086960, 0.764850, 0.782320, 0.174020, 0.511860, 1.004680, -0.838550,
        0.841720, 0.873380, 0.353100, 0.796150, -0.658900, -0.044190, 0.625300, -0.392060, -0.911900, 0.899910,
        0.798870, 0.425340, -0.697570, -0.030480, 0.406420, 0.771220, -0.764500, 0.193170, -0.906240, -0.469070,
        0.007240, -0.424940, -0.329820, -0.202130, 0.586420, 0.552480, 0.421190, -0.944950, -0.512500, -0.160400,

        0.630760, 0.191550, 0.366330, -0.370730, 0.249240, -0.296320, -0.756460, -0.709380, 0.174200, -0.778130,
        0.275210, -0.500660, -0.590040, -0.415070, -0.990960, -0.703310, -0.661500, -0.876200, -0.248620, 0.175710,
        -0.069410, -0.632870, 0.329990, -0.761920, 0.174670, -0.834630, 0.338400, 0.660000, -0.079210, 0.577940,
        0.688350, -0.041890, -0.287960, -0.420530, -0.934160, -0.253490, 0.612260, 0.607330, -0.652450, -0.120090,

        -0.513600, 0.324680, 0.750350, 0.198840, -0.893710, -0.740910, 0.972130, 0.036930, -0.306940, -0.805720,
        -0.648090, 0.837500, 0.748510, 0.929830, -1.002190, 0.306490, -0.326010, 0.966210, 0.737680, 0.140320,
        -0.559290, 0.031590, 0.866040, -0.007710, -0.667210, 0.827840, 0.126830, 0.780150, 0.888690, 0.909170,
        0.233590, -0.080280, -0.132320, 0.568400, -0.587590, -0.217660, 0.764600, 0.149310, 0.556400, -0.112470,

        -0.817250, -0.030690, -0.403480, 0.989220, -0.860570, 0.367190, -0.901430, -0.060990, 0.283750, -0.951990,
        -0.282490, 0.185880, -0.448140, -0.600420, -0.674350, 0.283400, -0.472420, 0.472150, -0.836530, 0.762300,
        -0.851450, 0.001610, -0.830140, -0.985790, 0.648760, -0.689020, 0.294970, -0.875190, -0.500750, 0.346840,
        0.872550, 0.772170, -0.084380, 0.060370, -0.633800, -0.885480, -0.622970, 0.018970, -0.493580, 0.121760,

        0.677780, 0.334010, 0.957280, 0.609590, -0.908150, -0.160590, 0.917740, 0.063010, 0.305620, 0.071970,
        0.453080, 0.227090, 0.858490, 0.518540, 0.984110, 0.706720, 0.213090, 0.695130, 0.426290, 0.718020,
        0.024720, 0.827740, 0.237850, -0.704580, 0.535680, 0.589930, -0.637070, 0.363560, 0.226260, -0.018200,
        0.632610, -0.396410, 0.513820, 0.333670, -0.705620, -0.357690, 0.277630, -0.737450, -0.546870, -0.157780,

        0.046910, 0.841320, -0.154420, -0.472420, 0.468430, -0.492870, 0.091110, -0.564940, -0.935670, 0.340660,
        0.111610, -0.493060, -0.621960, -0.744970, -0.686280, 0.743020, 0.653630, 0.610680, 0.346910, 0.885160,
        -0.514380, -0.228400, 0.132680, 0.390690, -0.166210, 0.380730, 1.019460, 0.140050, -0.628140, 0.120790,
        -0.429190, -0.752660, 0.439810, -0.160390, -0.870340, -0.464500, -0.977890, -0.925090, 1.058370, -0.473570,

        -0.916280, 1.047350, 0.248680, -0.130260, 0.639850, -0.801970, 0.629090, 0.292120, 0.247020, -0.456640,
        0.371160, -0.470900, -0.834630, -0.559820, -0.534880, 0.155540, 0.977320, 0.333070, -0.321330, -0.584960,
        0.561560, 0.571240, -0.068450, -0.272930, -0.618850, 0.451150, 0.415160, 0.345630, 0.486140, 0.481910,
        0.172680, -0.217410, -0.615580, 0.182150, -0.260370, -0.746830, -0.641790, -0.081270, 0.508910, 0.818350,

        -0.906360, 0.914150, 0.327240, -0.904290, 0.007350, -0.547240, -0.171610, -0.154740, -0.829240, 0.858770,
        -0.452680, 0.771480, 0.676380, 0.764070, 0.446590, -0.702550, -0.637200, 0.800460, 0.401060, -0.141010,
        -0.711230, 0.917210, -0.647960, -0.004060, 0.848180, -0.375610, -0.591040, -0.262400, 0.952190, 0.947970,
        -1.042270, 0.530250, -0.965400, -0.462050, -0.251850, 0.365430, 0.020960, -0.029120, 0.707120, 0.524730,

        0.851390, 0.335930, 0.625340, 0.318040, 0.509080, -0.170280, 0.642770, -0.479180, -0.126720, 0.336860,
        -0.108040, 0.920170, -0.995090, -0.859480, -0.266520, 0.206770, 0.350410, -0.457740, -0.251790, -0.837270,
        -0.832290, -0.103560, -0.648950, -0.674760, 0.734890, -0.227350, 0.335440, -0.998050, -0.467120, -0.137260,
        -0.240880, -0.423140, -0.293630, -0.189300, -0.599290, -0.242640, -0.732420, -0.017820, -0.718520, -0.235440,

        -0.397710, 0.683940, 0.136740, 0.946500, -0.392280, 0.649820, -0.594300, -0.230080, -0.352090, 0.419500,
        -0.059060, 0.547270, 0.791960, -0.278060, -0.369980, 0.258520, 0.971540, 0.349110, 0.266050, 0.871850,
        -0.948240, 0.738020, 0.018150, -0.286960, 0.392040, 0.037560, 0.101390, 0.189200, -0.736300, 0.839010,
        -0.678580, 0.403180, 0.630660, -0.633890, 0.913450, -0.808350, -0.464830, 0.477000, -0.311990, 0.924990,

        0.958260, -0.955830, 0.809990, 0.723330, -0.626010, -0.250600, 0.134630, -0.611730, 0.353530, 0.623370,
        0.639800, -0.824100, 0.388310, 0.313180, 0.275410, -0.065370, 0.601560, -0.496180, 0.717380, 0.808790,
        0.731640, -0.276580, 0.346460, 0.907360, 0.774440, 0.122870, -0.379090, 0.231720, 0.292780, 0.015970,
        -0.925390, 0.280360, -0.271280, 0.693070, 0.223660, -0.026580, 0.312170, -0.625680, -0.301390, 0.113430,

        -0.307590, 0.871210, -0.199490, 0.256610, -0.041860, 0.094800, 0.801300, -0.599370, 0.851600, 0.477510,
        -0.625680, 0.699170, -0.367130, -0.496630, 0.698040, 0.705370, 0.919670, -0.746890, 0.453460, -0.430100,
        -0.358740, -0.391790, -0.363250, -0.566380, -0.055840, -0.607430, 0.465180, -0.692180, -0.697050, -0.970500,
        1.040580, 0.109800, -0.591430, 0.309140, 0.803130, -0.818120, -0.415120, 0.578230, -0.569680, -0.241280,

        -0.106690, 0.205930, 0.988060, 0.913190, 0.135760, -0.754070, 0.122440, -0.324130, 0.230300, 0.179180,
        -0.007440, -0.989280, -0.903690, -0.101910, 0.969920, -0.453440, -0.315730, 0.995170, 0.372260, -0.170950,
        -0.687790, 0.792910, 0.832330, -0.342630, 0.897480, 0.356590, -0.148170, -0.771160, -0.074070, -0.064360,
        0.109070, 0.253370, 0.737730, 0.463650, 0.660500, -0.149160, -0.995430, 0.456880, 0.333050, 0.497970,

        0.779740, -0.420730, -0.789370, 0.093900, -0.963380, 0.264890, -0.868070, -0.948860, -0.490210, -0.169680,
        -0.483910, 0.559740, 0.186530, -0.388920, -0.372620, -0.969720, 0.776170, -0.099060, 0.145300, 0.560420,
        -0.373290, -0.132090, -0.801240, 0.185490, -0.473840, -0.405450, -0.937620, 0.503820, 0.700870, -0.013970,
        -0.719370, -0.924870, 0.444480, -0.359750, -0.345070, -0.310320, -0.947740, 0.238710, 0.529890, 0.423690,

        -0.121830, 0.864070, 0.727350, 0.361230, 0.167330, 0.950490, -0.627710, -0.154930, -0.533330, -0.533280,
        0.076920, -0.854210, -1.017230, -0.446960, 0.563820, 0.392240, -1.233250, 0.847200, 0.149450, 0.484110,


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
        0.0, -0.324450, 27,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 29 (Old: 29) */
        0.0, 0.026210, 27,
        &Sources[27],
        &Weights[27],
    },
    { /* unit 30 (Old: 30) */
        0.0, -0.667760, 27,
        &Sources[54],
        &Weights[54],
    },
    { /* unit 31 (Old: 31) */
        0.0, 0.567150, 27,
        &Sources[81],
        &Weights[81],
    },
    { /* unit 32 (Old: 32) */
        0.0, -0.829640, 27,
        &Sources[108],
        &Weights[108],
    },
    { /* unit 33 (Old: 33) */
        0.0, 0.446850, 27,
        &Sources[135],
        &Weights[135],
    },
    { /* unit 34 (Old: 34) */
        0.0, 0.794250, 27,
        &Sources[162],
        &Weights[162],
    },
    { /* unit 35 (Old: 35) */
        0.0, -0.157890, 27,
        &Sources[189],
        &Weights[189],
    },
    { /* unit 36 (Old: 36) */
        0.0, 0.329790, 27,
        &Sources[216],
        &Weights[216],
    },
    { /* unit 37 (Old: 37) */
        0.0, -0.413930, 27,
        &Sources[243],
        &Weights[243],
    },
    { /* unit 38 (Old: 38) */
        0.0, -0.821480, 27,
        &Sources[270],
        &Weights[270],
    },
    { /* unit 39 (Old: 39) */
        0.0, -1.007840, 27,
        &Sources[297],
        &Weights[297],
    },
    { /* unit 40 (Old: 40) */
        0.0, -0.957500, 27,
        &Sources[324],
        &Weights[324],
    },
    { /* unit 41 (Old: 41) */
        0.0, 0.994900, 27,
        &Sources[351],
        &Weights[351],
    },
    { /* unit 42 (Old: 42) */
        0.0, 0.099040, 27,
        &Sources[378],
        &Weights[378],
    },
    { /* unit 43 (Old: 43) */
        0.0, -0.915480, 27,
        &Sources[405],
        &Weights[405],
    },
    { /* unit 44 (Old: 44) */
        0.0, 0.241050, 27,
        &Sources[432],
        &Weights[432],
    },
    { /* unit 45 (Old: 45) */
        0.0, -0.953120, 27,
        &Sources[459],
        &Weights[459],
    },
    { /* unit 46 (Old: 46) */
        0.0, -0.841790, 27,
        &Sources[486],
        &Weights[486],
    },
    { /* unit 47 (Old: 47) */
        0.0, -0.754730, 27,
        &Sources[513],
        &Weights[513],
    },
    { /* unit 48 (Old: 48) */
        0.0, -0.298340, 27,
        &Sources[540],
        &Weights[540],
    },
    { /* unit 49 (Old: 49) */
        0.0, -0.056170, 27,
        &Sources[567],
        &Weights[567],
    },
    { /* unit 50 (Old: 50) */
        0.0, -0.096380, 27,
        &Sources[594],
        &Weights[594],
    },
    { /* unit 51 (Old: 51) */
        0.0, 0.290460, 27,
        &Sources[621],
        &Weights[621],
    },
    { /* unit 52 (Old: 52) */
        0.0, 0.184740, 27,
        &Sources[648],
        &Weights[648],
    },
    { /* unit 53 (Old: 53) */
        0.0, -0.954220, 27,
        &Sources[675],
        &Weights[675],
    },
    { /* unit 54 (Old: 54) */
        0.0, -0.811660, 27,
        &Sources[702],
        &Weights[702],
    },
    { /* unit 55 (Old: 55) */
        0.0, 0.491980, 27,
        &Sources[729],
        &Weights[729],
    },
    { /* unit 56 (Old: 56) */
        0.0, -0.508340, 27,
        &Sources[756],
        &Weights[756],
    },
    { /* unit 57 (Old: 57) */
        0.0, -0.882170, 27,
        &Sources[783],
        &Weights[783],
    },
    { /* unit 58 (Old: 58) */
        0.0, 0.792570, 27,
        &Sources[810],
        &Weights[810],
    },
    { /* unit 59 (Old: 59) */
        0.0, 0.828190, 27,
        &Sources[837],
        &Weights[837],
    },
    { /* unit 60 (Old: 60) */
        0.0, 0.009820, 27,
        &Sources[864],
        &Weights[864],
    },
    { /* unit 61 (Old: 61) */
        0.0, 0.508800, 27,
        &Sources[891],
        &Weights[891],
    },
    { /* unit 62 (Old: 62) */
        0.0, 0.408690, 27,
        &Sources[918],
        &Weights[918],
    },
    { /* unit 63 (Old: 63) */
        0.0, -0.948850, 27,
        &Sources[945],
        &Weights[945],
    },
    { /* unit 64 (Old: 64) */
        0.0, -0.780650, 27,
        &Sources[972],
        &Weights[972],
    },
    { /* unit 65 (Old: 65) */
        0.0, -0.944000, 27,
        &Sources[999],
        &Weights[999],
    },
    { /* unit 66 (Old: 66) */
        0.0, -0.508430, 27,
        &Sources[1026],
        &Weights[1026],
    },
    { /* unit 67 (Old: 67) */
        0.0, -0.305870, 27,
        &Sources[1053],
        &Weights[1053],
    },
    { /* unit 68 (Old: 68) */
        0.0, -0.895120, 40,
        &Sources[1080],
        &Weights[1080],
    },
    { /* unit 69 (Old: 69) */
        0.0, 0.298550, 40,
        &Sources[1120],
        &Weights[1120],
    },
    { /* unit 70 (Old: 70) */
        0.0, -0.738370, 40,
        &Sources[1160],
        &Weights[1160],
    },
    { /* unit 71 (Old: 71) */
        0.0, 0.225220, 40,
        &Sources[1200],
        &Weights[1200],
    },
    { /* unit 72 (Old: 72) */
        0.0, 0.017970, 40,
        &Sources[1240],
        &Weights[1240],
    },
    { /* unit 73 (Old: 73) */
        0.0, -0.755990, 40,
        &Sources[1280],
        &Weights[1280],
    },
    { /* unit 74 (Old: 74) */
        0.0, 0.776510, 40,
        &Sources[1320],
        &Weights[1320],
    },
    { /* unit 75 (Old: 75) */
        0.0, -0.885520, 40,
        &Sources[1360],
        &Weights[1360],
    },
    { /* unit 76 (Old: 76) */
        0.0, -0.756270, 40,
        &Sources[1400],
        &Weights[1400],
    },
    { /* unit 77 (Old: 77) */
        0.0, -0.563740, 40,
        &Sources[1440],
        &Weights[1440],
    },
    { /* unit 78 (Old: 78) */
        0.0, 0.661770, 40,
        &Sources[1480],
        &Weights[1480],
    },
    { /* unit 79 (Old: 79) */
        0.0, 0.450840, 40,
        &Sources[1520],
        &Weights[1520],
    },
    { /* unit 80 (Old: 80) */
        0.0, -0.119680, 40,
        &Sources[1560],
        &Weights[1560],
    },
    { /* unit 81 (Old: 81) */
        0.0, 0.683740, 40,
        &Sources[1600],
        &Weights[1600],
    },
    { /* unit 82 (Old: 82) */
        0.0, -0.944030, 40,
        &Sources[1640],
        &Weights[1640],
    },
    { /* unit 83 (Old: 83) */
        0.0, 0.251000, 40,
        &Sources[1680],
        &Weights[1680],
    },
    { /* unit 84 (Old: 84) */
        0.0, 0.206930, 40,
        &Sources[1720],
        &Weights[1720],
    },
    { /* unit 85 (Old: 85) */
        0.0, -0.649420, 40,
        &Sources[1760],
        &Weights[1760],
    },
    { /* unit 86 (Old: 86) */
        0.0, 0.755210, 40,
        &Sources[1800],
        &Weights[1800],
    },
    { /* unit 87 (Old: 87) */
        0.0, -0.227740, 40,
        &Sources[1840],
        &Weights[1840],
    },
    { /* unit 88 (Old: 88) */
        0.0, -0.009520, 20,
        &Sources[1880],
        &Weights[1880],
    }

};



int z(float* in, float* out, int init)
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

#endif
