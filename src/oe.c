/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    oe.c
    --------------------------------------------------------
    generated at Fri Jun  5 18:20:14 1998
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
static UnitType Units[102];
/* Sources definition section */
static pUnit Sources[] =
{
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
static float Weights[] =
{
    -0.049040, -0.575120, 0.432320, -0.947980, 0.367330, -0.208720, -0.413960, 0.570290, -0.772730, 0.390370,
        0.806330, 0.443340, 0.223200, -0.296350, -0.529810, -0.219160, -0.070830, 0.108340, -0.431100, 0.337880,
        -0.865700, 0.231380, -0.878830, 0.986200, -0.096100, 0.457490, 0.976310, -0.250420, 0.510450, -0.762170,

        0.517080, 0.407690, -0.785640, -0.023730, -0.392390, 0.556680, -0.840370, -0.299420, 0.084310, -0.918840,
        -0.517540, 0.089330, 0.571190, 0.309610, 0.438700, -0.314690, -0.424820, -0.127970, -0.574080, 0.244120,
        -0.668690, -0.693880, 0.636540, -0.885750, 0.274110, -0.039690, 0.853990, -0.747930, -0.752670, -0.512410,

        -0.423630, -0.520810, 0.235050, 0.616130, -0.030900, 0.472030, -0.728820, -0.097150, 1.008240, -0.717340,
        0.782600, -0.975770, 0.527060, 0.315930, -1.062610, -1.007230, -0.662580, -0.026730, 0.743210, -0.118810,
        0.316890, 0.276770, 0.455290, 0.626190, 0.956760, 0.942370, 0.404450, 0.298850, -0.444300, 0.518200,

        0.888620, 0.239030, 0.178030, 0.645780, 0.709090, -0.662870, 0.577430, 0.726400, 0.592890, -0.262240,
        0.967560, -0.772910, 1.061700, 0.213100, 0.923100, -0.660160, -0.727320, 0.041550, -0.416410, -0.310250,
        -0.869120, 0.225450, 0.174990, -0.791390, -0.228150, -0.667200, -0.384440, -0.099900, -0.170540, -0.067110,

        -0.867180, -0.343370, 0.895490, 0.234280, -0.216720, 0.731850, 0.256790, -0.295570, 0.948540, -0.682790,
        0.693350, -0.512810, 0.411770, -0.820280, 0.267500, 0.392660, 0.584710, -0.343870, 0.631930, 0.519900,
        0.466270, -0.825950, 0.726080, 0.456680, -0.005040, 0.343910, -0.791640, 0.419470, -0.357760, -0.646590,

        -0.282310, 0.853560, -0.771330, 0.487340, -0.228460, -0.695290, -0.663200, 0.247080, -0.509880, 0.782970,
        -0.672760, -0.165060, -0.706400, 0.350180, -0.391790, 0.272070, -0.789920, -0.929450, 0.792100, -0.956100,
        0.877660, -0.238670, 0.904330, 0.230790, -0.106030, 0.449200, -0.130860, -0.173890, -0.647080, 0.084620,

        0.003010, 0.412640, 0.457680, 0.581140, 0.940060, -0.697570, 0.045090, 0.795460, -0.460740, 0.763540,
        0.467040, -1.016540, -0.493020, -0.657580, -0.705450, 0.443800, 0.469280, 0.279590, 0.335460, -0.056740,
        0.436420, 0.213500, -0.754560, 0.890600, 0.398680, 0.206600, -0.162870, 0.393730, -0.659980, 0.029870,

        0.443860, -0.897880, -0.926270, 0.349090, -0.798470, 0.604900, 0.372840, -0.516790, 0.089720, -0.799460,
        -0.019410, -0.288610, -1.024130, 0.141900, 0.139190, 0.689770, 0.570100, 0.169030, 0.344690, 0.898480,
        -0.463140, 0.858690, -0.113660, 0.411940, 0.502750, 0.115950, 0.731180, -0.933730, -0.510180, -0.536340,

        -0.395310, -0.416730, -0.760800, -0.227610, -0.915330, -0.038240, -0.256700, 0.944470, -0.224940, 0.901620,
        -0.051780, 0.404380, -0.749610, 0.346300, 0.374670, -0.688740, -0.469520, 0.935920, -0.037040, 0.203510,
        -0.904940, -0.308070, -0.642240, 0.152050, -0.647430, 0.847060, 0.820230, -0.171490, -0.816010, -0.774900,

        0.144080, -0.716860, 0.411810, 0.755630, -0.168830, -0.581940, 0.693380, -0.651750, -0.493950, 0.180700,
        0.052900, 0.356470, 0.155310, 0.938020, -0.082350, -0.453510, 0.517710, -0.398070, -0.572730, -0.532660,
        0.761050, 0.273720, -0.861360, -0.542520, 0.432120, -1.009710, 0.142110, 0.930930, -0.198420, 0.960780,

        0.823450, 0.285750, 0.521750, -0.151400, 0.617190, -0.541370, -0.372560, 0.122210, 0.413220, -0.705850,
        0.090700, -0.591050, 0.087990, 0.426100, -0.848790, 0.529510, 0.304060, 0.216790, 0.064060, -0.810150,
        -0.080630, -0.324710, -0.903740, 0.632580, -0.017650, 0.908370, 0.614970, 0.764160, -0.043650, 0.574450,

        1.008830, 0.659400, -0.867960, -0.510440, 0.435170, 0.232760, -1.025040, -0.568700, 0.203720, 0.629010,
        0.449250, -0.334560, -0.123770, -0.278970, 0.682620, 0.133610, -0.104230, 0.887140, 0.408860, 0.928570,
        -0.080180, -0.827270, 0.865020, 0.897190, 0.432990, 0.410780, -0.769370, 0.763340, -0.825440, 0.158980,

        -0.570420, 0.138450, 0.130910, -0.466080, 0.576650, 0.650490, 0.507660, -0.340810, 0.724530, 0.354300,
        -0.603330, 1.038120, -0.857900, 0.325460, -0.242290, 0.376990, 0.146530, -0.323800, -0.567950, 0.649800,
        0.770040, 0.669930, 0.425820, -0.724740, 0.398860, -0.428250, -0.650030, -0.610770, 0.860300, 0.775940,

        -0.461930, 0.716820, 0.076310, 0.733150, -0.560030, -0.190410, -0.958940, -0.064910, 0.794250, -0.466640,
        0.059860, 0.036090, 0.430130, -0.877090, 0.077660, -0.048800, -0.428300, 0.542300, -0.790050, -0.782000,
        1.029870, 0.790630, 0.462790, -0.982350, 0.273950, -0.701630, -0.691920, 0.397980, -1.056480, 0.938670,

        -0.831620, -0.279520, 0.224930, -0.487890, -0.938450, -0.501720, -1.276510, -0.161840, -0.971430, 0.527030,
        0.205770, 0.234930, -0.628840, 0.600670, -0.951230, 0.622760, -0.907040, -0.302020, -0.410280, -0.192030,
        1.078940, 0.126110, 0.263890, -0.479070, -0.237150, -0.414440, -0.138930, 0.343950, 0.747820, 0.327470,

        -0.641420, 0.149620, -1.068720, 0.427900, -0.087640, -0.294580, 0.069420, -1.084900, -0.030380, 0.671890,
        -0.141320, 0.902570, 0.351000, 0.471230, 0.616180, -0.371690, 0.549200, -0.825290, -0.455860, 0.506600,
        0.079740, -0.887480, 0.166000, 0.786040, -0.816880, -0.311180, 0.620500, -0.582640, -0.507790, 0.523530,

        0.392060, 0.373660, -0.192810, -0.973440, -0.866340, -0.483690, -0.640350, -0.872550, -0.348000, -0.311780,
        0.667660, -0.870370, 0.778900, 0.170650, 0.105810, 0.220570, -0.012190, -0.938290, -0.304700, -0.054650,
        -0.523260, 0.811060, -0.737030, -0.429760, 0.644240, 0.951190, 0.033520, -0.715820, 0.348660, 0.412990,

        1.009670, -0.706750, 0.643160, -0.883580, -0.387860, 0.193150, -0.606550, 0.072990, 0.331590, 0.690730,
        -0.294130, 0.173100, 0.378280, -0.111550, -0.747820, 0.813260, -0.472280, 1.010150, -0.222400, -0.287110,
        1.039980, -0.889520, 0.347680, -0.686200, -0.148520, 0.936740, -0.587700, 0.059750, 0.598600, -0.335860,

        0.939410, -0.514000, -0.279910, -0.856810, 0.248740, 0.575250, 0.272490, -0.158730, -0.754930, -0.898290,
        0.977770, 0.286620, -0.569430, -0.307540, -0.771500, -0.624400, -0.149590, -0.150400, -0.249740, -0.163100,
        0.455790, -0.607590, 0.188850, -0.570890, 0.962630, 0.694250, -0.078860, -0.933420, -0.925260, 0.778310,

        0.326890, -0.675790, 0.846830, 0.210270, 0.651260, 0.105920, 0.545840, 0.291720, 0.036650, -0.290860,
        0.853310, 0.017940, -0.493180, -0.767750, -0.811140, 0.814550, -0.765000, 0.250990, 0.785260, -0.573480,
        0.048350, 0.780680, 0.851400, -0.116170, 0.747930, -0.640480, 0.749250, 0.115030, 0.936970, -0.653170,

        0.705610, -0.209530, 0.038400, -0.676620, 0.154830, 0.359950, 1.086160, 0.977500, 0.057540, 0.741990,
        -0.257220, -0.695630, 1.157630, 0.463830, 0.640940, -0.398590, -0.875440, 0.693260, 0.450730, 0.155810,
        0.271320, -0.752680, 0.185350, 0.624210, -0.007470, -0.778740, 0.436320, 0.133380, 0.647550, 0.229450,

        -0.168200, -0.898990, -0.753220, 0.233880, 0.074200, -0.024790, -0.037750, -0.203170, -0.383220, 0.524480,
        -0.716690, 0.425460, 0.274240, -0.152500, 0.719340, 0.597100, 1.013150, 0.058180, 0.024910, -0.270760,
        0.388040, 0.207210, 0.870120, 0.628280, 0.495600, 0.558830, -0.728840, -0.465090, 0.490270, -0.342130,

        -0.618230, -0.410720, 0.023750, -0.696780, 0.770220, -0.572820, -0.775360, -0.634450, -0.592750, -0.030180,
        0.481690, -0.736390, -0.289980, -1.050280, -1.005280, 0.448740, 0.071630, 0.034390, -0.926950, -0.072130,
        -0.580030, -0.371740, 0.117120, 0.144730, 0.953240, 0.582530, -0.229030, 0.698550, 0.917900, -0.169630,

        -0.680130, -0.088090, 0.265520, -0.660530, 0.354740, -0.043300, -0.619070, 0.899710, -0.226680, -0.408390,
        -0.672900, -0.881920, -0.841330, 0.683400, 0.863640, -0.058260, -0.431090, -0.940030, 0.145950, 0.204230,
        -0.524450, -0.886740, 0.838160, 0.973670, -0.064110, -1.004600, -0.231820, -0.391660, 0.827000, -0.150900,

        0.115780, 0.096180, -0.588300, 0.521090, 0.315860, 0.265910, 0.083600, 0.211570, 0.467760, 0.765140,
        -0.950340, -0.542580, -0.862710, 0.043440, -0.344380, 0.549740, -0.135630, -0.919430, -0.905730, -0.889400,
        -0.743030, 0.256100, 0.732830, 0.550310, 1.021270, -0.166560, -0.476650, -0.293300, -0.287250, -0.397170,

        0.588660, 0.125380, 0.083200, -0.104540, 0.311610, -0.297520, -1.363200, 0.339430, 0.890160, -0.343400,
        -0.153860, -0.666950, -0.043100, 0.771740, -0.433240, 0.112410, 1.008880, -0.159900, 0.023530, 0.027260,
        0.047640, 0.077160, -0.211280, -0.189020, 1.019430, -0.559370, 0.938270, -0.757490, 0.815340, 0.528440,

        0.157260, 0.162710, -0.778890, -0.250600, -0.839380, 0.559180, 1.191380, -0.232680, 0.452000, -0.337850,
        0.079860, 0.526810, 0.994870, 0.851430, 0.676450, 0.470320, -0.766070, -0.219330, -0.402590, -0.474980,
        -0.247500, -0.085380, -0.866860, -0.692090, -0.900840, -0.708120, 0.424370, -0.192560, -0.872160, -0.446630,

        0.447210, -0.051450, -0.127960, -0.673600, -0.422320, 0.598710, -0.495860, -0.124400, 0.486410, 0.538330,
        -0.696850, 0.758670, -0.342030, 0.582020, -0.223470, 0.425980, 0.371900, -0.235360, -0.375680, -0.648420,
        -0.690710, 0.624870, -0.860110, 0.333760, -0.578480, -0.608010, -0.382350, 0.808590, -0.512030, -0.310710,

        0.089230, -0.842000, -0.363350, -0.974770, -0.984280, 0.198620, 0.988140, -0.944280, -0.405630, -0.512770,
        0.327240, -0.223670, -0.561130, 0.618050, 0.020270, -0.432230, 0.526720, 0.907050, -0.117470, 0.072480,
        0.800680, -0.144520, 0.772920, 0.574320, -0.038000, -0.774260, 0.045670, 0.461930, 0.590060, -0.061680,

        0.808350, 0.621150, -0.874880, 0.387590, 0.495340, -0.463270, -0.047480, -0.556920, 0.749390, 0.895120,
        -0.398210, 0.664450, 0.043460, -0.803880, 0.875570, 0.696670, -0.064170, 0.424450, -0.151100, 0.592650,
        0.941600, 0.464040, -0.142320, 0.539580, 0.730180, 0.355200, 0.713680, 0.543950, -0.253760, -0.048640,

        0.293990, 0.871050, 1.118360, -0.516650, 0.171990, -0.224570, 0.901560, -0.230170, -0.131520, -0.526670,
        0.418070, -0.794080, 0.108280, -0.804480, 0.568920, 0.504640, -0.417410, -0.241280, 0.803110, -0.234090,
        -0.361530, 0.597690, 0.938200, -0.633690, 0.501560, 0.238140, 0.306560, -0.658660, -0.797190, -0.481410,

        0.431290, -0.806000, -0.795890, 0.612080, 0.690840, -0.910350, 0.002420, 0.185120, 0.005410, 0.540290,
        -0.951540, -0.475440, 0.307340, 0.757140, -0.926970, -1.003750, 0.681400, 0.530470, -0.559740, 0.895760,
        0.848250, -0.122700, 0.351720, 0.162250, 0.510610, 0.518600, 0.040440, -0.081600, -0.651170, 0.797490,

        0.154680, 0.950260, -0.773840, -0.701000, -0.947310, 0.725140, -0.312260, 0.247270, 0.123470, -0.651710,
        0.767910, -0.808120, -0.701100, 0.730910, 0.138300, -0.622010, -0.387650, -0.449920, -0.480030, -0.299430,
        0.836540, -0.079590, -0.580960, 0.540390, 0.737180, 0.924540, 0.945010, -0.873660, -0.789030, 0.302300,

        0.633990, 0.524250, -0.562780, 1.033110, 1.013160, 0.356820, 0.285460, 0.560420, 0.091820, -0.891260,
        -0.561820, 0.678630, -0.928560, -0.880550, 0.453180, -0.041570, 0.160150, 0.199980, -0.752830, -0.070520,
        0.548290, -0.381190, 0.671470, 0.476270, 0.486870, -0.855650, 0.489600, 0.264730, 0.766970, 0.667450,

        -0.882900, 0.068930, 0.125230, 0.036130, 0.309610, 0.004220, -0.962180, -0.904860, -0.633260, 0.513250,
        -0.666920, 1.252430, -0.354050, 0.311610, 0.000840, 0.443190, 0.951640, -0.057640, -1.030730, -0.598710,
        0.364720, 0.839430, -0.580090, -0.379920, -0.172340, -0.704810, 0.137040, -0.615460, -0.474680, 0.063320,

        0.769250, -0.825950, -1.103600, -0.353270, 0.204680, -0.257920, 0.365260, -0.170580, -0.746520, -0.663450,
        0.448980, 0.395140, 0.322130, -0.180970, -0.504060, -0.819400, -0.393240, 0.569570, 0.214630, 0.203410,
        -0.308170, 0.579470, -0.298460, 0.317740, 0.790400, 0.273620, 0.747270, -0.857110, 0.418650, 0.477230,

        -0.949330, -1.017620, -0.422540, -0.758820, 0.629710, -0.223200, -0.487600, 0.805050, 0.784950, -0.516030,
        0.654310, 0.756490, 0.040560, 0.769790, -0.848450, 0.774230, -0.613020, -0.929100, -0.635190, 0.494340,
        -0.377940, 0.316790, 0.112590, 0.950550, 0.019020, -0.363830, 0.639390, 0.653480, 0.466920, -0.602120,

        -0.770900, 0.051860, 0.058920, -0.397640, 0.102910, -0.151380, -0.383580, -0.450220, -0.487930, 0.756530,
        0.308230, -0.860450, -0.320890, -0.340910, 0.334880, 0.362510, -0.765820, 0.426390, 0.017020, -0.271590,
        -0.691130, -0.330640, -0.167700, -0.136430, -0.893590, 0.971210, 0.423090, -0.831920, -0.282970, 0.269920,

        -0.960600, 0.781300, 0.116800, -0.899990, -0.183940, -0.302270, 0.784500, 0.873010, 0.661180, 0.621270,
        -0.284960, 0.498450, -0.693240, -0.381240, -0.643770, 0.376490, 0.848030, -0.653620, 0.770740, -0.925260,
        -0.683950, 0.922270, 0.257310, -0.443620, -0.543720, 0.538040, 0.967320, 0.553050, 0.850490, 0.208120,

        0.777440, 0.594050, 0.783590, -0.640160, 0.951200, 0.849910, -0.640080, -0.645180, -0.669080, 0.721940,
        -0.276750, 0.336530, -0.083210, 0.135140, -0.790790, -0.081310, -0.573920, -0.040930, 0.763580, 0.713990,
        0.247290, -0.531310, -0.310360, -0.870390, 0.710990, 0.153950, -0.845910, -0.114290, -0.880700, 0.863310,

        0.003160, 0.451310, -0.064270, -0.188240, 0.734390, 0.793020, -0.653040, 0.218120, 0.188390, 0.231130,
        0.202120, -0.450170, 0.277660, -0.878090, -0.911790, 0.309680, -0.094180, 0.868740, 0.683990, 0.839620,
        -0.417610, 0.522300, 0.695470, -0.718490, -0.911750, 0.658580, -0.384110, -0.512150, 0.552850, -0.316630,

        0.624280, 0.517550, 0.805900, 0.968230, 0.664970, 0.838760, -0.440620, 0.363660, -0.920250, 0.033860,
        0.766990, 0.327960, -0.983880, 0.487840, 0.604590, 0.198670, 0.830670, 0.006640, 0.047200, -0.418370,
        -0.209680, -0.316630, -0.601400, 0.693170, -0.164540, -0.156060, -0.641880, -0.071540, 0.656610, 0.722330,

        0.945870, 0.140310, 0.926890, -0.685270, 0.674550, -0.489670, 0.793910, 0.723680, 0.030000, -0.788060,
        0.205760, 0.651500, -0.399040, 0.915010, 0.496370, 0.552250, -0.248830, -0.208810, -0.522150, -0.775450,
        -0.382350, -0.749400, -0.001750, -0.794430, -0.461890, -0.737450, 0.877610, -0.145880, 0.533300, 0.028440,

        -0.654170, -0.699090, 0.104020, -0.976580, -0.201460, -0.748860, -0.240740, 0.812420, 0.705000, 0.971770,
        0.137100, 0.144000, -0.911270, 0.206830, 0.790110, -0.448360, 0.156100, -0.919180, -0.188810, 0.507720,
        0.687870, 0.770140, 0.605980, -0.431610, 0.732000, -0.375510, -0.282280, -0.362160, -0.637190, 0.789450,

        0.268690, 0.415910, 0.051400, 0.791880, 0.748290, 0.113140, 0.486370, 0.953630, -0.861010, 0.826290,
        0.912110, 0.413350, 0.815900, -0.714240, -0.074080, 0.627390, -0.436200, -0.940800, 0.790720, 0.767010,
        0.401910, -0.700770, -0.033620, 0.391030, 0.670650, -0.817670, 0.188290, -1.075320, -0.477190, 0.006870,

        -0.398200, -0.239430, 0.573460, 0.527150, 0.399750, -0.965870, -0.464760, -0.167890, -0.884420, 0.631200,
        0.158020, 0.307470, -0.375730, 0.191670, -0.352380, -0.786480, -0.727380, 0.140100, -0.749840, 0.274940,
        -0.518990, -0.601880, -0.415010, -0.987590, -0.712060, -0.657490, -0.905030, -0.281830, 0.157780, -0.069270,

        0.364560, -0.737010, 0.083810, -0.875310, 0.305990, 0.670540, -0.113770, 0.591110, 0.668970, -0.048240,
        -0.446050, -0.366450, -1.051380, -0.249430, 0.547490, 0.560600, -0.674200, -0.073780, -0.761240, -0.579410,
        0.331610, 0.758370, 0.192760, -0.914710, -0.650330, 0.915980, -0.007380, -0.285970, -0.819080, -0.672260,

        0.710240, 0.928620, -0.953660, 0.299180, -0.358140, 0.931570, 0.929320, 0.173960, -0.568600, 0.021490,
        0.889530, -0.180060, -0.646740, 0.822390, 0.076170, 0.717100, 0.855260, 0.902820, 0.267730, -0.068900,
        -0.180660, 0.508410, -0.597510, -0.219090, 0.814000, 0.164580, 0.503590, -0.091870, -0.603570, -0.825750,

        -0.422240, 0.989480, -0.849050, 0.345110, -0.908300, -0.109560, 0.331870, -1.028170, -0.269680, 0.187750,
        -0.559030, -0.543230, -0.709320, 0.256370, -0.502770, 0.444090, -0.830490, 0.764800, -0.817090, -0.017510,
        -0.849130, -1.000360, 0.639260, -0.674050, 0.212320, -0.851390, -0.548560, 0.335120, 0.855050, 0.782160,

        0.110500, -0.624950, -0.920240, -0.594610, 0.007000, -0.502370, 0.130480, 0.736500, 0.673940, 0.332830,
        0.957030, 0.572220, -0.920680, -0.110630, 0.906410, 0.038810, 0.301990, 0.103810, 0.376010, 0.212620,
        0.872710, 0.503220, 0.985200, 0.705170, 0.211050, 0.703430, 0.428040, 0.707760, 0.059180, 0.797370,

        -0.714210, 0.518060, 0.598430, -0.646970, 0.367640, 0.225360, -0.024030, 0.626590, -0.401720, 0.502360,
        0.327700, -0.719240, -0.368440, 0.266450, -0.742610, -0.559210, -0.161930, 0.378800, 0.037520, 0.811790,
        -0.154120, -0.553300, 0.433960, -0.548410, 0.070600, -0.552450, -0.988280, 0.252060, 0.087200, -0.521310,
        -0.715290, -0.769500, -0.706100, 0.707170, 0.604200, 0.523710, 0.368590, 0.865970, -0.572240, -0.305830,
        0.079250, 0.343590, -0.238850, 0.381970, 0.957370, 0.065040, -0.713160, 0.101640, -0.427360, -0.742050,

        -0.210380, -1.016510, -0.529300, -0.959730, -0.915050, 0.977830, -0.483140, -0.181140, -0.918210, 1.081630,
        0.210340, -0.320730, 0.602650, -0.989410, 0.558440, 0.354620, 0.141820, -0.606510, 0.398290, -0.417640,
        -0.880980, -0.555290, -0.530200, 0.116850, 0.911720, 0.123950, -0.184240, -0.566840, 0.504870, 0.465070,
        -0.102770, -0.310480, -0.757630, 0.489640, 0.252720, 0.288730, 0.314280, 0.437930, 0.329750, -0.160550,
        -0.778370, 0.134840, -0.300500, -0.778890, -0.574070, -0.168920, 0.375930, 0.809630, 0.716040, -0.892210,

        0.323360, -0.889540, -0.004060, -0.569240, -0.130020, -0.121610, -0.827270, 0.855680, -0.401660, 0.797740,
        0.657040, 0.814110, 0.502610, -0.707450, -0.614840, 0.776320, 0.439080, -0.102250, -0.745830, 0.918060,
        -0.638500, 0.017240, 0.838280, -0.312740, -0.618160, -0.245490, 0.912880, 0.951480, -0.954900, 0.608270,
        -0.952500, -0.420150, -0.257790, 0.430150, 0.086190, -0.037280, 0.688950, 0.514420, -0.929030, 0.848990,
        0.339640, 0.652070, 0.344600, 0.530100, -0.140050, 0.642450, -0.470410, -0.097200, 0.342760, -0.088560,

        -0.965710, -0.876220, -0.285300, 0.197750, 0.418110, -0.459110, -0.244250, -0.802970, -0.817870, -0.051000,
        -0.633540, -0.710190, 0.766810, -0.221460, 0.343100, -0.887970, -0.452050, -0.141210, -0.268990, -0.382260,
        -0.276200, -0.164870, -0.593260, -0.254220, -0.797730, -0.086570, -0.646220, -0.174850, 0.238300, -0.364170,
        0.737030, 0.135370, 0.890030, -0.354510, 0.709140, -0.608430, -0.225840, -0.311970, 0.502150, -0.090390,
        0.552600, 0.810110, -0.271500, -0.390090, 0.311930, 0.931160, 0.340080, 0.281970, 0.842270, -0.901040,

        0.033060, -0.289500, 0.374320, -0.001210, 0.116210, 0.176560, -0.715040, 0.822140, -0.742090, 0.366350,
        0.625300, -0.670820, 0.910560, -0.845410, -0.517410, 0.482530, -0.304290, 0.937630, 0.136220, 0.955480,
        -0.960750, 0.792140, 0.647260, -0.645240, -0.314100, 0.102330, -0.614460, 0.297940, 0.587370, 0.624360,
        -0.843070, 0.323920, 0.269880, 0.247290, -0.075240, 0.557890, -0.567920, 0.733020, 0.781950, 0.694740,
        -0.365250, 0.302230, 0.894330, 0.706480, 0.102020, -0.421710, 0.171000, 0.232270, -0.007140, -0.955200,

        -0.358890, 0.893980, 0.261880, -0.015520, 0.137340, -0.611260, -0.290490, 0.107630, -0.540340, -0.222540,
        1.026530, 0.168880, 0.296980, 0.020490, 0.232860, 0.631830, -0.621970, 1.064090, 0.699810, -0.714040,
        0.728030, -0.299790, -0.509890, 0.705800, 0.907590, 1.178940, -0.783510, 0.491800, -0.329430, -0.209090,
        -0.465620, -0.145910, -0.383960, 0.083110, -0.594420, 0.606920, -0.663090, -0.702260, -1.188720, 1.088340,
        0.036010, -0.426820, 0.420170, 0.817700, -0.856430, -0.434810, 0.639110, -0.455940, -0.178940, 0.838590,

        0.246160, 0.947660, 1.118580, 0.138970, -0.554460, 0.091360, -0.251130, 0.210360, 0.122790, -0.162630,
        -0.907430, -0.797820, -0.117280, 0.970340, -0.459380, -0.440760, 1.124960, 0.376410, -0.303790, -0.607370,
        0.852700, 0.701390, -0.159000, 1.062240, 0.242630, -0.118750, -0.922750, -0.040790, -0.164660, 0.057380,
        0.357680, 0.696160, 0.427160, 0.580440, -0.332790, -1.050560, 0.480080, 0.465080, 0.472570, 0.050280,
        0.970370, -0.442810, -0.979620, 0.154760, -0.987130, 0.284570, -0.835870, -0.939370, -0.436540, -0.179230,

        0.577370, 0.168600, -0.325380, -0.317570, -0.895090, 0.823240, -0.009350, 0.158960, 0.583600, -0.354870,
        -0.069000, -0.862780, 0.226010, -0.449940, -0.440040, -0.896260, 0.523400, 0.726580, -0.037470, -0.641950,
        -0.835790, 0.502690, -0.306670, -0.288770, -0.275780, -0.982720, 0.287570, 0.551470, 0.432410, 0.287070,
        -0.007880, 0.872600, 0.850160, 0.689380, 0.336680, 0.355090, -0.401310, -0.133100, -0.184340, -0.575140,
        0.430520, -0.766910, -0.878400, -0.109680, 0.572190, 0.869550, -0.983970, 0.883820, 0.467950, 0.633940,

        -0.119690, -0.440840, 0.406160, 0.903030, -0.849690, -0.311410, -0.279640, 0.082640, 0.218920, -0.410610,
        -0.497150, 0.948860, -0.175390, -0.834020, 0.053620, 0.184650, -0.007230, 0.725580, 0.644530, 0.879360,
        -0.880690, -0.116190, 0.966490, -0.763100, 0.219930, -0.170030, 0.370350, -0.878720, -0.103120, 0.694160,
        0.634710, 0.037960, 0.840760, 0.190100, -0.676370, -0.749490, -0.191170, -0.106550, 0.930070, -0.946570,
        0.636410, -0.352760, 0.800380, -0.642290, -0.887920, 0.963290, 0.450810, -0.887100, 0.395430, -0.842450,

        0.882500, -0.777550, -0.343320, 0.608750, -0.249390, -0.869160, 0.790220, 0.207390, -0.340420, 0.194070,
        0.694220, 0.458060, 0.929700, -0.889070, 0.866460, -0.559570, -0.276730, -0.503200, 0.415420, 0.371010,
        0.495580, -0.012360, -0.966310, 0.629680, -0.685780, 0.846340, 0.167650, 0.952450, -0.420930, -0.983750,
        0.768450, -0.563170, 0.275330, 0.786290, 0.122640, 0.328550, 0.551800, -0.133110, 0.672360, -0.297360,
        -0.412200, -0.530560, 0.193790, 0.868620, -0.543050, 0.183210, -0.229360, 0.988940, -0.199530, 0.789860,

        -0.877710, -0.664090, 0.155400, 0.083040, 0.579720, -0.659560, 0.124790, -0.387600, 0.127050, -0.242220,
        -0.571180, -0.464150, -0.846010, -0.571260, 0.833930, -0.709050, -0.903000, -0.336300, -0.941490, -0.792690,
        0.988350, -0.552950, -0.500040, 0.513630, 1.009180, 0.671550, 0.752500, -0.749510, -0.758030, 0.398290,
        0.223390, 0.807530, 0.443850, 0.311880, -0.778280, 0.355670, -0.156600, 0.988650, -0.126490, -0.856330,
        -0.516680, -0.016200, -0.375860, -0.414170, -0.216550, 0.133580, -0.376870, 0.463650, -0.287050, 0.447900,

        -0.581060, -0.520270, 0.714990, 0.056920, 0.929800, -0.739060, -0.048830, -0.027630, 0.336700, 0.801030,
        0.645420, 0.251450, -0.789460, -0.902530, -0.451890, -0.081400, 0.556450, 0.851630, 0.188040, -0.286400,
        0.430140, -0.822880, 0.621730, 0.420410, -0.508730, -0.865350, 0.923770, -0.881580, 0.431410, -0.312110,
        0.900990, -0.839260, 0.282700, 1.030580, 0.342320, 0.245450, -0.796890, -0.275020, -0.758500, -0.437670,
        0.393010, 0.305550, 0.493700, -0.428180, -0.359270, -0.609250, -0.273440, 0.864660, -0.897020, 0.683780,

        -0.022660, -0.813050, -0.232960, -0.112810, 0.263790, -0.070800, 0.242570, 0.555830, 0.287830, -0.264120,
        0.125550, -0.718090, -0.626880, -0.697830, -1.002300, 0.762980, 0.532060, -0.840820, -0.096170, 0.696140,
        0.561990, -0.046880, 0.400930, 0.817240, -0.083750, -0.456240, -0.523800, 0.869610, -0.195330, -0.473060,
        -0.736340, 0.929270, 0.701490, -0.804740, -0.334390, -0.631140, -1.022260, -0.241740, 0.844260, -0.729760,
        0.416860, -0.642350, 0.154330, 0.044120, 0.483010, 0.074640, 0.373290, -0.987920, 0.000650, 0.145800,

        0.466500, 0.714390, 0.974370, 0.298450, -0.065900, -0.230350, 0.476610, -0.387560, 0.115470, 0.503940,
        1.003460, -0.305750, 0.879040, -0.720490, -0.093320, -0.953570, -0.346070, 0.528400, -0.841940, -0.304900,
        -0.889970, -0.297700, 0.598990, -0.291730, -0.216670, 1.007110, 0.952820, -0.779680, -0.821210, 0.492100,
        0.214130, -0.541090, 0.518190, -0.720820, -0.290010, 0.598440, 0.074660, -0.331710, 0.645750, 0.695320,
        0.505300, -0.489530, -0.691780, -0.463720, -0.701130, 0.763460, -0.620500, -0.140440, 0.468810, -0.189770,

        0.624650, -0.784270, -0.180700, -0.475140, 0.603290, 1.012830, 0.030270, 0.761350, -0.708960, -0.582410,
        -0.083160, -0.846590, -0.659920, 0.497350, 0.609880, 0.259430, -0.296040, -0.269350, 0.763450, -0.447090,
        0.316310, 0.831340, -0.587370, 0.867340, 0.515760, 0.226490, 0.271220, 0.304320, -0.447550, -0.520100,
        -0.821120, -0.497110, -1.033260, 0.787650, -0.359720, -0.896200, -0.033840, -0.421970, 0.335810, 0.343880,
        -0.222100, 0.826110, 0.614210, 0.377180, 0.349030, -0.470450, 0.921460, -0.790310, 0.940490, 0.449290,

        -0.872250, -0.257190, -0.325090, 0.086320, 0.482680, 0.611690, 0.108340, 0.801090, -0.885080, -0.283040,
        0.104610, -0.171370, 0.097640, -1.009320, -0.742900, 0.012550, 0.849600, -0.519350, 0.464330, -0.381430,
        0.860310, 0.741310, 0.275150, -0.173800, -0.361060, -0.819470, 0.747320, -0.369000, 0.145010, 0.007380,
        -0.263670, 0.684070, 0.017300, -0.040210, -0.699190, -0.717580, 0.728290, 1.075250, 1.126600, 0.972590,
        -0.229830, -0.043450, 0.250980, 1.001490, -0.107910, 0.709380, -0.560130, 0.225040, 0.250020, -0.314050,

        -0.269220, -0.010890, 0.728360, -0.121470, 0.038830, -0.208990, 0.470680, 0.427500, -0.373990, -0.384000,
        -0.752120, 0.108420, -0.991550, -0.992510, -0.592440, 0.301090, 0.803470, -0.847840, -0.307660, -0.250680,
        0.872980, -0.320650, -0.550680, -0.487590, -0.716180, 0.119330, 0.818410, 0.526760, -0.865650, 0.466620,
        0.357060, -0.082960, 0.593900, -0.212660, -0.905430, -0.435480, 0.594210, 0.429030, -0.610780, -0.430780,
        -0.669610, -0.038350, -0.358810, 0.738410, 0.050600, -0.985610, 0.189100, 0.371700, 0.764300, -0.038340,

        -0.739910, 0.147690, -0.219210, -1.049130, 0.659900, -0.616660, -0.274450, -0.735550, 0.656640, 0.597140,
        -0.648630, -0.646090, 0.043570, -0.306910, 0.837770, 0.774030, 0.012290, -0.781350, -0.661580, 0.224700,
        -1.017040, 0.535350, 0.249830, 0.688570, -0.368190, 0.590150, -0.196500, 0.690090, -0.173830, -0.936130,
        -0.284140, 0.118610, 0.362420, -0.576750, 0.717880, 0.808620, -0.062460, -0.140220, 0.321340, -0.119200,
        0.676240, 0.285690, -0.956990, -0.258150, 0.629600, -0.372580, 0.912490, -0.919980, 0.085560, 0.312020,

        1.042890, -0.255080, -0.506680, -1.046420, -1.076580, 0.811380, -0.272120, -0.587470, 0.668640, -0.235190,
        -0.490910, 1.114900, 0.335310, 0.600810, 0.526680, 0.973440, -0.013540, 0.101630, 1.148250, 0.041570,
        -0.310760, -0.178450, -0.533080, -0.447240, 0.318440, 1.031780, 0.990180, 0.337250, -0.333010, 0.565580,
        -1.192360, 0.803900, -0.171230, -0.107450, 1.100520, 0.087550, 1.111130, 0.184290, -1.228330, -0.217270,
        -0.357330, -0.822480, -0.357750, -0.665750, 0.577850, -0.467580, -0.894130, -0.862640, 0.223850, 0.079990,

        0.771810, -0.718420, 0.374600, -0.622550, -0.402830, 0.964770, 1.039690, 0.360270, -0.153620, -0.380600,
        -0.296930, 0.893120, 0.529410, 0.871830, 0.642620, -0.804080, 0.087590, -0.555570, -0.336440, -0.533740,
        0.180180, 0.765220, -0.432530, 0.864690, 0.804170, -0.916870, 0.844080, 0.922440, 0.145720, -0.346640,
        0.058460, -0.585050, -0.341870, -0.718430, 0.585420, -0.879960, -0.052360, -0.274960, 0.684520, -0.503670,
        -0.132030, -0.683350, 0.180420, 0.536940, -0.286680, -0.023730, -0.002470, 0.249720, 0.114960, -0.657690,

        -0.166740, -0.876570, 0.367810, -0.542160, 0.329100, 1.354740, -1.214770, -0.056260, 0.102610, -0.584760,
        1.086490, -0.687080, 0.471310, -0.342230, -0.588230, -1.072460, -1.171770, 0.969720, 2.233930, -0.576530,


    };

/* unit definition section (see also UnitType) */
static UnitType Units[102] =
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
        0.0, -0.325660, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 29 (Old: 29) */
        0.0, -0.692950, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 30 (Old: 30) */
        0.0, 0.994490, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 31 (Old: 31) */
        0.0, 0.052540, 30,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 32 (Old: 32) */
        0.0, 0.920590, 30,
        &Sources[30],
        &Weights[30],
    },
    { /* unit 33 (Old: 33) */
        0.0, 0.071010, 30,
        &Sources[60],
        &Weights[60],
    },
    { /* unit 34 (Old: 34) */
        0.0, 0.268100, 30,
        &Sources[90],
        &Weights[90],
    },
    { /* unit 35 (Old: 35) */
        0.0, 0.476560, 30,
        &Sources[120],
        &Weights[120],
    },
    { /* unit 36 (Old: 36) */
        0.0, -0.760870, 30,
        &Sources[150],
        &Weights[150],
    },
    { /* unit 37 (Old: 37) */
        0.0, 0.892590, 30,
        &Sources[180],
        &Weights[180],
    },
    { /* unit 38 (Old: 38) */
        0.0, 0.819920, 30,
        &Sources[210],
        &Weights[210],
    },
    { /* unit 39 (Old: 39) */
        0.0, 0.692400, 30,
        &Sources[240],
        &Weights[240],
    },
    { /* unit 40 (Old: 40) */
        0.0, 0.189480, 30,
        &Sources[270],
        &Weights[270],
    },
    { /* unit 41 (Old: 41) */
        0.0, -0.460500, 30,
        &Sources[300],
        &Weights[300],
    },
    { /* unit 42 (Old: 42) */
        0.0, 0.663710, 30,
        &Sources[330],
        &Weights[330],
    },
    { /* unit 43 (Old: 43) */
        0.0, 0.765600, 30,
        &Sources[360],
        &Weights[360],
    },
    { /* unit 44 (Old: 44) */
        0.0, 0.067970, 30,
        &Sources[390],
        &Weights[390],
    },
    { /* unit 45 (Old: 45) */
        0.0, 0.723310, 30,
        &Sources[420],
        &Weights[420],
    },
    { /* unit 46 (Old: 46) */
        0.0, -0.139580, 30,
        &Sources[450],
        &Weights[450],
    },
    { /* unit 47 (Old: 47) */
        0.0, -0.545220, 30,
        &Sources[480],
        &Weights[480],
    },
    { /* unit 48 (Old: 48) */
        0.0, 0.060330, 30,
        &Sources[510],
        &Weights[510],
    },
    { /* unit 49 (Old: 49) */
        0.0, -0.638740, 30,
        &Sources[540],
        &Weights[540],
    },
    { /* unit 50 (Old: 50) */
        0.0, -0.607960, 30,
        &Sources[570],
        &Weights[570],
    },
    { /* unit 51 (Old: 51) */
        0.0, -0.046280, 30,
        &Sources[600],
        &Weights[600],
    },
    { /* unit 52 (Old: 52) */
        0.0, -0.280900, 30,
        &Sources[630],
        &Weights[630],
    },
    { /* unit 53 (Old: 53) */
        0.0, -0.129690, 30,
        &Sources[660],
        &Weights[660],
    },
    { /* unit 54 (Old: 54) */
        0.0, 0.413580, 30,
        &Sources[690],
        &Weights[690],
    },
    { /* unit 55 (Old: 55) */
        0.0, -0.379520, 30,
        &Sources[720],
        &Weights[720],
    },
    { /* unit 56 (Old: 56) */
        0.0, 0.344190, 30,
        &Sources[750],
        &Weights[750],
    },
    { /* unit 57 (Old: 57) */
        0.0, -0.180560, 30,
        &Sources[780],
        &Weights[780],
    },
    { /* unit 58 (Old: 58) */
        0.0, 0.651670, 30,
        &Sources[810],
        &Weights[810],
    },
    { /* unit 59 (Old: 59) */
        0.0, -0.848410, 30,
        &Sources[840],
        &Weights[840],
    },
    { /* unit 60 (Old: 60) */
        0.0, 0.191060, 30,
        &Sources[870],
        &Weights[870],
    },
    { /* unit 61 (Old: 61) */
        0.0, -0.495470, 30,
        &Sources[900],
        &Weights[900],
    },
    { /* unit 62 (Old: 62) */
        0.0, 0.262560, 30,
        &Sources[930],
        &Weights[930],
    },
    { /* unit 63 (Old: 63) */
        0.0, -0.689030, 30,
        &Sources[960],
        &Weights[960],
    },
    { /* unit 64 (Old: 64) */
        0.0, 0.730260, 30,
        &Sources[990],
        &Weights[990],
    },
    { /* unit 65 (Old: 65) */
        0.0, -1.000950, 30,
        &Sources[1020],
        &Weights[1020],
    },
    { /* unit 66 (Old: 66) */
        0.0, 0.579170, 30,
        &Sources[1050],
        &Weights[1050],
    },
    { /* unit 67 (Old: 67) */
        0.0, -0.666990, 30,
        &Sources[1080],
        &Weights[1080],
    },
    { /* unit 68 (Old: 68) */
        0.0, 0.469240, 30,
        &Sources[1110],
        &Weights[1110],
    },
    { /* unit 69 (Old: 69) */
        0.0, -0.801570, 30,
        &Sources[1140],
        &Weights[1140],
    },
    { /* unit 70 (Old: 70) */
        0.0, 0.213030, 30,
        &Sources[1170],
        &Weights[1170],
    },
    { /* unit 71 (Old: 71) */
        0.0, 0.129890, 30,
        &Sources[1200],
        &Weights[1200],
    },
    { /* unit 72 (Old: 72) */
        0.0, -0.692770, 30,
        &Sources[1230],
        &Weights[1230],
    },
    { /* unit 73 (Old: 73) */
        0.0, -0.069100, 30,
        &Sources[1260],
        &Weights[1260],
    },
    { /* unit 74 (Old: 74) */
        0.0, 0.340010, 30,
        &Sources[1290],
        &Weights[1290],
    },
    { /* unit 75 (Old: 75) */
        0.0, 0.808350, 30,
        &Sources[1320],
        &Weights[1320],
    },
    { /* unit 76 (Old: 76) */
        0.0, -0.464150, 30,
        &Sources[1350],
        &Weights[1350],
    },
    { /* unit 77 (Old: 77) */
        0.0, -0.698380, 30,
        &Sources[1380],
        &Weights[1380],
    },
    { /* unit 78 (Old: 78) */
        0.0, 0.793570, 30,
        &Sources[1410],
        &Weights[1410],
    },
    { /* unit 79 (Old: 79) */
        0.0, -0.060790, 30,
        &Sources[1440],
        &Weights[1440],
    },
    { /* unit 80 (Old: 80) */
        0.0, -0.096240, 30,
        &Sources[1470],
        &Weights[1470],
    },
    { /* unit 81 (Old: 81) */
        0.0, 0.226440, 50,
        &Sources[1500],
        &Weights[1500],
    },
    { /* unit 82 (Old: 82) */
        0.0, 0.385310, 50,
        &Sources[1550],
        &Weights[1550],
    },
    { /* unit 83 (Old: 83) */
        0.0, 0.923390, 50,
        &Sources[1600],
        &Weights[1600],
    },
    { /* unit 84 (Old: 84) */
        0.0, 0.966120, 50,
        &Sources[1650],
        &Weights[1650],
    },
    { /* unit 85 (Old: 85) */
        0.0, 0.731180, 50,
        &Sources[1700],
        &Weights[1700],
    },
    { /* unit 86 (Old: 86) */
        0.0, 0.362800, 50,
        &Sources[1750],
        &Weights[1750],
    },
    { /* unit 87 (Old: 87) */
        0.0, -0.109170, 50,
        &Sources[1800],
        &Weights[1800],
    },
    { /* unit 88 (Old: 88) */
        0.0, -0.458490, 50,
        &Sources[1850],
        &Weights[1850],
    },
    { /* unit 89 (Old: 89) */
        0.0, -0.499980, 50,
        &Sources[1900],
        &Weights[1900],
    },
    { /* unit 90 (Old: 90) */
        0.0, -0.373930, 50,
        &Sources[1950],
        &Weights[1950],
    },
    { /* unit 91 (Old: 91) */
        0.0, -0.076080, 50,
        &Sources[2000],
        &Weights[2000],
    },
    { /* unit 92 (Old: 92) */
        0.0, -0.350680, 50,
        &Sources[2050],
        &Weights[2050],
    },
    { /* unit 93 (Old: 93) */
        0.0, -0.845430, 50,
        &Sources[2100],
        &Weights[2100],
    },
    { /* unit 94 (Old: 94) */
        0.0, -0.667940, 50,
        &Sources[2150],
        &Weights[2150],
    },
    { /* unit 95 (Old: 95) */
        0.0, 0.936560, 50,
        &Sources[2200],
        &Weights[2200],
    },
    { /* unit 96 (Old: 96) */
        0.0, 0.203740, 50,
        &Sources[2250],
        &Weights[2250],
    },
    { /* unit 97 (Old: 97) */
        0.0, 0.783820, 50,
        &Sources[2300],
        &Weights[2300],
    },
    { /* unit 98 (Old: 98) */
        0.0, -1.101910, 50,
        &Sources[2350],
        &Weights[2350],
    },
    { /* unit 99 (Old: 99) */
        0.0, 0.675400, 50,
        &Sources[2400],
        &Weights[2400],
    },
    { /* unit 100 (Old: 100) */
        0.0, 0.989930, 50,
        &Sources[2450],
        &Weights[2450],
    },
    { /* unit 101 (Old: 101) */
        0.0, 0.417140, 20,
        &Sources[2500],
        &Weights[2500],
    }

};



int oe(float* in, float* out, int init)
{
    int member, source;
    float sum;
    enum {OK, Error, Not_Valid};
    pUnit unit;
    /* layer definition section (names & member units) */
    static pUnit Input[30] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, Units + 8, Units + 9, Units + 10, Units + 11, Units + 12, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, Units + 21, Units + 22, Units + 23, Units + 24, Units + 25, Units + 26, Units + 27, Units + 28, Units + 29, Units + 30}; /* members */
    static pUnit Hidden1[50] = {Units + 31, Units + 32, Units + 33, Units + 34, Units + 35, Units + 36, Units + 37, Units + 38, Units + 39, Units + 40, Units + 41, Units + 42, Units + 43, Units + 44, Units + 45, Units + 46, Units + 47, Units + 48, Units + 49, Units + 50, Units + 51, Units + 52, Units + 53, Units + 54, Units + 55, Units + 56, Units + 57, Units + 58, Units + 59, Units + 60, Units + 61, Units + 62, Units + 63, Units + 64, Units + 65, Units + 66, Units + 67, Units + 68, Units + 69, Units + 70, Units + 71, Units + 72, Units + 73, Units + 74, Units + 75, Units + 76, Units + 77, Units + 78, Units + 79, Units + 80}; /* members */
    static pUnit Hidden2[20] = {Units + 81, Units + 82, Units + 83, Units + 84, Units + 85, Units + 86, Units + 87, Units + 88, Units + 89, Units + 90, Units + 91, Units + 92, Units + 93, Units + 94, Units + 95, Units + 96, Units + 97, Units + 98, Units + 99, Units + 100}; /* members */
    static pUnit Output1[1] = {Units + 101}; /* members */
    static int Output[1] = {101};
    for (member = 0; member < 30; member++)
    {
        Input[member]->act = in[member];
    }
    for (member = 0; member < 50; member++)
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
