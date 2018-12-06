/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    X@.c
    --------------------------------------------------------
    generated at Fri Jun  5 18:16:13 1998
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
    -0.760150, 0.594410, -0.183010, 0.916160, 0.471530, -0.058010, 1.189470, -0.861600, 0.258730, -0.894470,
        0.276860, -0.414590, 0.077240, -0.063260, -0.191650, -0.501290, -0.282030, 0.225720, 0.372140, 0.704270,
        0.354760, -0.773430, 0.564580, -0.228120, -0.152990, 0.428850, -1.013400, 0.492450, -0.486010, -0.057400,

        -0.516110, -0.773770, -0.840860, 0.831300, -0.068250, 0.210180, -1.057940, 0.671470, -0.695100, -0.639890,
        0.219110, -0.736880, -0.119220, -0.437930, -0.398020, 0.354760, 0.271430, 0.541440, 0.200840, -0.544400,
        -0.907170, 0.015390, -0.325380, -0.708110, 0.438950, -0.453150, 0.028900, -0.830440, 0.319030, 0.449070,

        0.670610, -0.421390, 0.102190, 0.536050, 0.874290, 1.082290, 0.335980, 0.366130, 0.333270, 0.413740,
        -0.371450, 0.798190, -0.230130, -0.618860, -0.942190, -0.986870, 0.347160, 0.509050, -0.624840, 0.868470,
        -0.634080, 0.931840, 0.084860, -0.627220, 0.594710, 0.082530, 0.775660, 0.114760, -0.701340, -0.412050,

        -0.169320, -0.355050, -0.284470, -0.430690, -0.654800, -0.355420, -0.897680, 0.162060, 0.092700, -0.859420,
        -0.372700, -0.625940, 0.060940, -0.819300, -0.814360, 0.696010, 0.128470, 0.939330, -0.530260, 0.897140,
        -0.252860, 0.632350, 0.595680, 0.281210, -0.883450, 0.543580, 0.592060, 0.043130, 0.200310, 0.890930,

        -0.661350, -0.374470, 0.341550, -0.752450, 0.354620, -0.022730, 0.444410, 0.738810, -0.896150, 0.494920,
        0.528860, 0.576310, -0.365210, 0.577130, 0.364270, 0.274100, -0.802570, 0.485930, -0.463910, 0.817210,
        -0.627950, 0.955610, -0.236740, 0.278280, 0.823570, -0.275800, 0.307120, 0.825720, -0.283800, -0.869110,

        0.043120, -0.631020, -0.180720, -0.162960, 0.396440, -0.165110, 0.464460, 0.859850, -0.223780, 0.891870,
        -0.872580, 0.725500, -0.862080, -0.787170, 0.231280, -0.466870, 0.287690, -0.714860, -0.123710, -0.688550,
        0.737690, -0.530200, 0.230820, -0.684510, -0.794280, -0.220490, 0.438310, -0.787110, 0.866080, -0.338490,

        0.027240, -0.642260, 0.366920, -0.162670, 0.196900, 0.386440, 0.832440, -0.764300, 0.200440, 0.468140,
        -0.029930, 0.249360, 0.316770, 0.487010, 0.467380, -0.687070, -0.652940, -0.477720, -0.948080, 0.551650,
        0.726250, -0.468510, 0.787220, -0.155040, -0.650090, 0.987790, 0.551080, 0.430950, 0.414440, 0.040960,

        -0.638950, -0.464280, -0.954640, 0.861960, -0.016200, 0.472720, 0.330330, -0.106490, 0.875320, -0.367890,
        0.912760, 0.107180, 0.321090, 0.569360, 0.612950, 0.121150, 0.282630, -0.941490, -0.126750, 0.152010,
        -0.790520, 0.086900, -0.489150, 0.264490, 0.541120, -0.838680, 0.350340, -0.987150, -0.833030, 0.460760,

        -0.810630, -0.864560, -0.109640, 0.736620, 0.833640, -0.547800, -0.115080, -0.761340, -0.248330, -0.966710,
        0.190590, 0.558890, 0.749250, -0.468300, -0.772580, 0.320090, 0.318850, -0.809780, 0.182400, -0.209600,
        0.928620, -0.169600, 0.946460, -0.051210, -0.060060, -0.935750, -0.226710, -0.700780, -0.557180, -0.441380,

        0.914040, -0.194920, 0.963610, 0.126480, -1.006820, 0.380390, -0.389890, -0.855710, 0.268990, 0.760220,
        -0.543860, -0.690650, -0.347450, 0.527950, -0.515110, -0.133550, 0.926270, 0.167060, 0.290630, 0.066110,
        0.130850, -0.502990, -0.632560, 0.702770, -0.635130, -0.151640, 0.725560, 0.432090, -0.765540, 0.131220,

        0.568500, -0.095530, 0.662360, 0.593980, 0.910440, -0.192630, 0.449930, -1.023470, -0.361610, -0.123200,
        -0.852500, 0.197830, 0.086210, 0.286410, 0.470370, -0.934810, 0.327380, 0.139280, -0.743350, 0.077610,
        -0.707570, 0.475960, 0.070390, -0.510960, -0.629800, 0.569770, -0.193860, 0.564890, 0.200290, 0.722700,

        0.128640, -0.900870, 0.725080, -0.779770, 0.390210, 0.498580, 0.884170, 0.857100, -0.776560, -0.128660,
        0.969770, 0.493190, 0.796240, -0.132990, 0.071110, 0.612270, -0.326550, -0.068050, -0.466060, 0.546230,
        0.649250, 0.240530, -0.584750, -0.974620, 0.174070, 0.375290, -0.548220, -0.830840, 0.625570, 0.869800,

        0.888200, 0.901410, -0.656170, -0.696850, -0.392460, 0.430770, -0.930230, 0.414570, 0.681280, 0.741340,
        0.641990, -0.508730, -0.383900, 0.172580, 0.445970, -0.192730, 0.236870, -0.847840, 0.883360, -0.654650,
        0.369790, 0.650070, -0.299180, 0.510640, 0.746570, 0.620920, -0.390790, 0.152370, 0.073000, -0.582980,

        1.007770, -1.002010, 0.382420, -0.696240, -0.624870, 0.319170, -0.991620, 0.472580, 0.774730, 0.994050,
        -0.806450, -0.588060, 0.447580, -0.404950, 0.025720, 0.169650, -0.889870, 0.426600, 0.010690, -0.069820,
        -0.425860, 0.802610, -0.090460, -0.463900, -0.227440, -0.557120, 0.842440, 0.158230, 0.733300, -0.492490,

        0.444040, 0.778150, 0.423080, -0.112360, -0.340160, -0.037140, -0.618930, 0.229200, 0.232310, 0.975750,
        -0.180530, 0.181670, -0.599020, -0.857330, 0.782780, -0.757470, 0.613350, -0.562190, -0.166180, 0.143970,
        0.596620, -0.923300, -0.061740, -0.818740, -0.302550, -0.868840, -0.371820, 0.369500, -0.409520, -0.914870,

        0.599150, -0.417960, -0.569020, 0.621580, -0.363290, -0.846580, 0.853000, 0.150020, -0.681200, 0.054070,
        0.543400, -0.369720, -0.824320, 0.576550, -0.281140, 0.662540, 0.327630, 0.502270, 0.643270, -0.055920,
        0.670460, -0.019210, -0.970180, 0.617480, -0.309090, -0.043610, 0.548020, -0.898670, 0.161940, -0.828010,

        0.380090, 0.379090, -0.783430, 0.114150, 0.810780, 0.615930, -0.611840, -0.767430, 0.696870, -0.391370,
        -0.379450, -0.443010, -0.944050, -0.014930, 0.077550, 0.016960, 0.311520, 0.683970, -0.304990, 0.683560,
        -0.237670, -0.382380, -0.960520, -0.596350, -0.559890, -0.962450, -0.871870, -0.405460, 0.412950, 0.519950,

        -0.381660, 0.535500, 0.013300, -0.754540, 0.980030, -0.200110, -0.516810, 0.404690, -0.932290, 0.980630,
        -0.165270, -0.409690, 1.020460, -0.517350, 0.708560, -0.903490, -0.241890, 0.300400, 0.097130, -0.434620,
        0.632410, 0.321770, -0.003960, -0.613950, 0.160000, -0.430170, -0.978410, 0.658290, -0.720950, 0.926310,

        0.791940, -0.836830, -0.930280, -0.127900, 0.655210, 0.949010, -0.607670, 0.234140, -0.496750, 0.439050,
        -0.142530, -0.427190, -0.062810, -0.138090, -0.626380, -0.784420, -0.336690, -0.532060, 0.183300, 0.977540,
        -0.932970, -0.781820, -0.168140, 0.294730, 0.552540, 0.275750, -0.860860, -0.200320, -0.494640, 0.860320,

        -0.602890, 0.941580, 0.176300, 0.697040, -0.553460, 0.847820, -0.005830, 0.857280, 0.745090, -0.019750,
        -0.580950, 0.906750, 0.171190, -0.758030, 0.802290, -0.798030, -0.783200, -0.486210, -0.233920, 0.738470,
        -0.286670, -0.004270, 0.368710, 0.715610, 0.226260, 0.693460, 0.228580, 0.912740, -0.681920, 0.343720,

        0.116450, 0.561330, 0.058600, 0.390180, -0.811540, -0.132830, 0.681920, 0.237440, -0.771850, 0.307210,
        0.258110, 0.255600, 0.837310, -0.947080, -0.484810, 0.493260, 0.464920, 0.998850, -0.427930, -0.295360,
        0.708760, 0.056170, 0.821670, 0.757810, 0.321050, 0.058570, -0.773690, -0.065620, -0.188830, 0.725960,

        -0.398090, 0.529840, -0.520930, -0.679940, 0.488880, 0.397670, 0.689140, 0.865890, 0.043340, 0.458610,
        -0.399520, -0.250500, 0.139390, 0.961460, 0.477670, 0.584090, -0.125350, 0.259510, 0.551570, -0.766190,
        0.525310, -0.462300, -0.236570, 0.147360, -0.308930, -0.000540, 0.214590, -0.826560, -0.809000, -0.114380,

        -0.210020, 0.919940, 0.735470, -0.207290, 0.606570, 0.979140, 0.066630, 0.136460, -0.409730, -0.552530,
        -0.055890, -0.987830, 0.093490, 0.081150, 0.403540, -1.013700, -1.002380, -0.262950, -0.771290, 0.540350,
        -0.052000, -0.563250, -0.611030, -0.736580, -0.575460, 0.778540, -0.698370, 0.037050, -0.412550, -0.569160,

        -0.082420, 0.833390, -0.466490, -0.267840, -1.028500, -0.186150, 0.877630, 0.971340, -0.959400, -0.490450,
        0.175380, -0.253820, -0.979560, -0.435660, -0.176060, 0.759290, 0.642530, -0.802200, -1.020270, -0.607950,
        -0.406500, -0.364320, 0.956990, -0.289840, 0.079610, 0.299620, -0.615550, 0.236520, -0.192940, -0.768350,

        -0.458020, -0.252520, -0.077950, -0.331290, -0.106000, 1.019040, 0.870810, 0.838260, 0.288040, -0.753650,
        -0.769380, -0.966680, -0.745380, -0.132090, 0.663160, -0.210230, 0.118940, -0.800240, -0.549630, -0.882550,
        0.748190, 0.582590, 0.106270, 0.064990, 0.214760, 0.317010, 0.509110, -0.450730, 0.251500, 0.152990,

        0.507110, 0.765020, -0.624500, 0.928290, -0.447660, 0.621650, -0.180750, -0.308890, 0.153320, -0.024050,
        0.033420, 0.307230, -0.216240, 0.939890, -0.007070, -0.622670, 0.575840, 0.035540, -0.959170, -0.133690,
        -0.337870, 0.947450, 0.173540, -1.015030, -0.696490, 0.160210, -0.154150, 0.260740, 0.139500, 0.387650,

        -0.444850, -0.891750, -0.132840, 0.413180, -0.822070, -0.809310, -0.686430, -0.907410, -0.045870, -0.243550,
        -0.685190, -0.295230, -0.265260, -0.768160, 0.418240, 0.617930, 0.847480, 0.947650, 0.588530, 0.058160,
        -0.328860, 0.429760, -0.212630, 0.989400, 0.570190, -0.834270, -0.340390, -0.853900, 0.176220, 0.178240,

        -0.193420, -0.385960, 0.797270, -0.259360, -0.575660, -0.511340, 0.319310, -0.880920, 0.745240, -0.696370,
        -0.485980, -0.180890, -0.308960, 0.441790, 0.704010, 0.055710, 0.570970, -0.236010, 0.749560, -0.591120,
        0.569690, 0.535920, -0.110770, -0.218500, 0.720300, -0.330640, -0.515230, -0.036100, -0.087340, 0.407160,

        -0.058140, 0.590710, 0.469250, 0.047620, -0.740240, -0.049970, 0.688370, 0.801800, -0.236030, 0.802610,
        0.010880, -0.233730, 0.944950, 0.523750, -0.451260, 0.018930, 0.654750, -0.509760, -0.298540, 0.350830,
        -0.515130, -0.426760, -0.882970, 0.930720, 0.216840, -0.979930, -0.989630, -0.399280, -0.745110, 0.153570,

        -0.034040, -0.255230, 0.553180, 0.668420, 0.323940, 0.728550, 0.514590, -0.136430, 0.492390, 0.945330,
        0.556800, -0.187750, 0.419570, -0.076020, 0.669040, 0.827560, -0.821380, 0.026920, 0.698410, -0.393390,
        0.876650, 0.741040, -0.583480, -0.116970, -0.473510, 0.506900, 0.323630, -0.849510, 0.653520, 0.802710,

        -0.612860, -0.862620, -0.804180, 0.293020, 0.186340, 0.478400, -0.762500, 1.001060, 0.528710, -0.286780,
        -0.141360, 0.372560, -0.041480, -0.462170, 0.323420, 0.401560, -0.756800, 0.034470, -0.515690, 0.512260,
        -0.513250, -0.153200, -0.246070, 0.484730, -0.246490, 0.064500, -0.506940, 0.942240, 0.873080, 0.351700,

        0.849140, -0.645550, -0.002250, 0.003530, 0.481520, 0.607330, 0.274360, 0.430050, -0.048540, 0.857160,
        0.805910, -0.612030, 0.605150, 0.697090, -0.949830, -0.893640, 0.728980, 0.294140, -0.453530, -0.952440,
        0.514610, -0.053670, 0.208210, 0.107310, -0.859260, 0.739010, 0.604120, -0.755720, -0.714180, 0.423010,

        0.299010, -0.770480, -0.847370, 0.955290, 0.900230, 0.811370, 0.802740, -0.489800, -0.012920, 0.915310,
        -0.396180, -0.678080, -0.337130, -0.350860, -0.514740, 0.234320, 0.770280, -0.784970, -0.456680, 0.909530,
        -0.715090, 0.108960, 0.189380, -0.311240, 0.753380, -0.896610, -0.706250, -0.802310, 1.023150, 0.231060,

        0.599330, 0.728080, 0.270020, 0.406110, -0.865550, 0.374540, 0.583830, 0.689010, -0.437430, 0.545060,
        -0.086840, -0.899100, 0.278760, 0.125740, -0.145860, 0.345500, -0.863300, -0.954650, 0.737130, -0.603500,
        -0.921550, 0.079400, 0.494140, 0.220730, 0.251240, 0.962940, 0.942200, -0.583490, 0.598440, 0.629980,

        0.065690, -0.425490, -0.562880, 0.140090, -0.727070, -0.066740, -0.507640, -0.610310, 0.892650, 0.334480,
        -0.511250, -0.881580, -0.050460, 0.965690, 0.455930, 0.029830, 0.321150, -0.277720, 0.939670, -0.750140,
        0.515270, -0.623400, -0.827470, -0.514380, -0.063620, 0.331680, 0.065630, 0.222270, 0.061200, -0.955260,

        0.636040, 0.361290, -0.784360, 0.715850, 0.353900, 0.823530, 0.312970, -0.301340, 0.656590, -0.409080,
        0.047120, 0.657790, 0.284590, -0.349080, -0.738510, -0.404570, -0.288550, 0.347540, 0.243670, 0.421310,
        -0.589520, -0.759000, -0.216740, 0.490660, -0.093620, 0.242810, -0.287400, -1.023360, -0.940070, 0.697080,

        -0.743510, 0.546840, 0.860210, 0.620620, -0.221620, 0.241110, 1.881050, 0.352820, 0.339680, -0.364950,
        0.563670, -1.250510, -0.510690, -0.613830, 1.016300, -0.626240, 0.896950, 0.040240, 0.784010, 0.708180,
        -0.716640, 0.746560, 0.786020, -0.545010, -0.283360, 0.793910, -0.903970, -0.270480, -0.649880, -0.760950,

        0.259280, -0.316640, -0.894210, 0.430310, 0.880310, -0.846210, -0.298900, -0.125440, -0.346240, -0.643670,
        -0.513050, 0.052800, 0.334240, -0.778180, 0.240820, 0.238920, -0.308070, -0.400720, -0.706850, 0.256590,
        0.816710, -0.551440, -0.424340, -0.486540, -0.115830, 0.045640, -0.392210, -0.117770, -0.019360, -0.732740,

        0.231830, 0.927290, 0.357500, 0.966460, 0.487720, -0.402770, -0.716820, 0.427790, 0.817450, -0.641390,
        -0.912340, 0.351600, -0.491500, 0.837130, 0.330940, -0.706890, -0.433840, -0.668150, 0.439200, -0.445770,
        0.634890, 0.603750, 1.114610, 0.857790, 0.097190, -0.180100, -0.801690, -0.043840, 0.788700, -0.908210,

        1.037740, -0.823510, -0.267510, -0.844720, 0.078430, 0.488910, -1.330320, -0.529910, -0.521560, 0.240360,
        0.420930, 1.098010, -0.421350, -0.563170, -0.158720, -0.880020, 0.021530, -0.015350, 0.290750, -0.364380,
        0.785630, -0.796960, -0.507070, -0.247860, 0.656000, 1.036600, -0.603090, 0.813820, 0.269000, 0.614370,

        -0.255960, 0.621720, -0.612740, -0.347290, 0.682140, -0.902380, -1.088240, 0.624360, 0.517170, -0.371870,
        0.679860, 0.983520, 0.779400, -0.063070, 0.376850, -0.812490, -0.841180, 0.292480, -0.413270, 0.175200,
        0.295170, 0.193950, 0.319350, -0.279290, 0.698750, 0.737350, -0.014670, -0.078800, 0.436420, 0.028020,

        0.585680, 0.642590, -0.010390, -0.777840, -0.147530, -0.310390, 1.172680, -0.442600, -0.388060, -0.208260,
        -0.290740, -0.526100, 0.281410, 0.806130, 0.084410, 0.492510, 0.506020, -0.975170, 0.235590, 0.860450,
        -0.071280, -0.993780, 0.320320, -0.613270, 0.777210, 0.638980, 0.860490, 0.802440, 0.628110, 0.645640,

        0.126170, 0.527180, -0.203250, 0.905070, -0.745550, -0.475930, -1.051130, -0.049750, -0.765650, -0.384240,
        -0.844590, -0.453120, -0.346960, -0.253220, 0.534100, 0.461660, 0.865670, -0.401120, 0.669230, 0.183780,
        -0.749040, 0.030430, 0.721840, 0.706990, -0.396220, 0.698330, -0.694190, 0.912420, 0.046510, 0.927750,

        0.739680, -0.566500, -0.401440, -0.180210, -0.383080, 0.594820, -0.139480, 0.699170, 0.702940, 0.758030,
        0.562290, -0.771740, -0.686630, 0.152240, -0.462250, 0.768240, 0.268900, -0.880590, 0.418880, 0.279620,
        0.934070, 0.658470, 0.760270, -0.363140, -0.824870, -0.168770, -0.973140, 0.054980, -0.619730, -0.607970,

        0.010570, -0.477650, -0.927960, 0.186710, -0.781290, 0.764540, 0.397300, -0.026630, -0.711000, 0.385400,
        0.764500, 0.893080, -0.904540, -0.428920, 0.638490, -0.035230, -0.671370, 0.791850, 0.328280, 0.865990,
        0.831890, -0.864420, 0.968220, 0.523250, 0.161730, 0.763480, 0.764910, 0.064740, 0.461730, 0.337590,

        -0.072690, 0.179630, -0.240190, -0.880660, -0.670170, -0.708360, -0.991750, -0.425320, -0.589680, -0.500420,
        0.247060, -0.791610, 0.149350, -0.708820, -0.775580, -0.320990, 0.242420, -0.369820, 0.372130, 0.185950,
        0.603590, -0.877480, -0.164510, -0.525120, -0.936040, 0.448450, 0.487370, 0.589620, -0.223220, -0.369270,

        -0.597510, -0.824330, -0.310170, 0.060070, 1.006990, -0.749850, -0.715390, 0.205130, 0.731700, 0.303790,
        -0.533700, -0.776220, -0.202830, -0.652380, 0.648590, 0.660240, -0.239230, -0.936090, -0.388850, -0.311700,
        -0.039960, 0.668130, 0.649370, -0.019730, 0.827010, 0.395840, -0.860140, 0.154460, -0.752070, 0.350590,

        -0.749140, -0.547440, -0.089700, 0.562930, 0.172110, 0.790110, -0.174210, -0.583950, 0.563320, -0.151100,
        -0.077450, 0.258580, 0.917100, 0.868650, 0.846860, 0.177110, 0.862490, -0.675730, 0.028710, 0.844360,
        0.016280, -0.560130, 0.127790, 0.738650, 0.918930, -0.257430, 0.298270, -0.910880, 0.956530, 0.767130,

        0.723470, 0.914780, 0.397780, -0.671870, -0.866160, 0.209350, -0.888340, 0.684000, -0.976310, -0.831390,
        0.327970, -1.207150, 1.035650, -0.819720, 0.450390, -0.520060, 0.275380, -0.658350, -0.712960, -0.365640,
        0.018130, -0.254000, -0.977650, 0.303250, -0.087950, -0.738220, 0.200030, -0.734260, 0.982350, -0.413100,

        0.830460, 0.023210, 0.710220, 0.400580, 0.675610, 0.172500, 0.747020, 1.005470, 0.516640, 0.858020,
        0.211310, 0.383430, 0.066040, 0.305810, 0.024450, 0.879170, -0.173230, -0.908480, 0.602250, 0.956890,
        0.334260, 0.649140, 0.665970, 0.126630, -0.515610, 0.008420, -0.612720, -0.890660, -0.653090, 0.047370,

        -0.664960, -0.451410, 0.154010, -0.674760, 0.099440, 0.962980, 0.466450, -0.214190, 0.409780, 0.110360,
        -0.220840, -0.538840, 0.827300, 0.388480, 0.525890, 0.608370, 0.741890, -0.654690, -0.758550, -0.675310,
        -0.491140, 0.096590, 0.312860, -1.031210, -0.550360, 0.151590, -0.593720, 0.455240, -0.523880, -0.109950,
        0.854770, 0.101180, 0.395430, -0.085600, -0.540810, -0.709070, 0.372030, -0.353750, -0.734780, 0.305170,
        0.543520, -0.409330, 0.627900, -0.015980, 0.257060, 0.368770, -0.714100, 0.615000, 0.581170, -0.672310,

        -1.186160, 0.780140, 0.793300, 0.436750, -0.334580, -0.416450, -0.884910, -0.373980, 0.223120, -0.616930,
        -0.185050, 0.150220, 0.480270, 0.402890, 0.472540, 0.213070, 0.610040, -0.773310, -0.332720, -0.050400,
        0.268490, 0.352250, -0.713180, -0.426850, 0.027100, 1.065680, 0.313990, -0.533350, -0.670090, -0.995920,
        -0.432210, 0.312230, -0.776210, -0.088390, 0.360700, 0.698570, -1.452080, 0.685310, 0.068000, 0.525150,
        1.016600, -1.193790, 0.024360, -0.449550, 1.002860, -0.965460, -0.919200, -0.519170, -1.126980, -0.214920,

        -0.442400, 0.357260, -0.121450, -0.583360, 0.525080, -0.207510, 0.224310, 0.245440, 0.580730, 0.246990,
        0.555930, -1.123050, 0.582540, 0.656090, -0.037090, -0.120460, 0.407560, -0.376630, -0.449020, -0.939210,
        0.420140, -1.130220, 0.754330, 0.757370, -0.423220, -0.690450, -0.237770, 0.711180, -0.090260, -0.852120,
        0.848940, -0.883380, -0.258120, 0.094030, 0.730540, -0.630390, -1.185420, 0.386700, 0.922500, 0.877950,
        0.831710, -0.737520, 0.804220, -0.864130, -0.246670, -0.183250, -0.480950, -0.141130, -1.101930, 0.159160,

        -0.820130, 0.826430, 0.317520, 0.330760, 1.027810, 0.242170, -0.335310, -0.257760, 0.846230, 0.515450,
        -0.080550, 0.497480, -0.358760, -0.257750, -0.707310, 0.707970, -0.406680, 0.938670, 0.133510, 0.743650,
        -0.331120, 0.287700, -0.193240, -0.718940, 0.068770, -0.704240, -0.289830, -0.554080, -0.140380, -0.227110,
        -0.410140, -0.171740, -0.042310, -0.343900, -1.017560, 0.380840, -0.020750, 0.668970, -0.739290, -0.745230,
        -0.098490, -0.790920, -0.904000, -0.230470, -0.406600, 0.332880, 0.130300, -0.212720, -0.827870, -0.929290,

        -0.955830, -0.020450, 0.245080, 0.178190, -0.424830, 0.107220, 0.719460, 0.877030, 0.320330, -0.352250,
        0.714000, 0.781920, 0.706050, -0.573340, 0.565770, -0.079810, 0.247440, 0.275970, 0.304910, -0.829740,
        0.614710, 0.563800, 0.301210, -0.653510, 0.074300, -0.289160, -0.654780, 0.645690, 0.797920, -0.967040,
        0.962480, 0.143060, 0.912310, -0.316220, 0.479540, -0.514930, -0.849920, 0.920370, -0.683140, 0.607700,
        0.363430, -0.782710, 0.803950, -0.717740, 0.174500, 0.127310, -0.044570, 0.374700, -0.298270, 0.026790,

        0.785660, -0.244770, -0.487420, 0.662900, -0.419610, -0.833190, 0.883150, 0.306010, -0.525440, 0.117940,
        1.067570, -0.939290, -0.627630, -0.611740, 0.547350, -0.663390, -0.008420, -0.496160, -0.267320, -0.307090,
        -0.313120, -0.459240, 0.480160, -0.768250, 0.938470, 0.805500, 0.683830, -0.463020, -0.327770, 0.736110,
        -0.612520, 0.507180, 0.937100, -0.567190, 0.799220, 0.154170, 0.082990, 0.300800, -0.188340, 0.863590,
        -0.272430, -0.643960, 0.121840, -0.358720, -0.629360, 0.288660, -0.085180, 0.219480, 0.668070, -0.320450,

        -0.020120, -0.589650, -0.974430, -0.840460, 0.316680, -0.938970, 0.229210, -0.869940, -0.426370, 0.785670,
        -0.002650, 0.473150, 0.176990, 0.390320, -1.042580, -0.135470, 0.636810, 0.468800, 0.713880, 0.181560,
        0.121850, -0.092230, -0.018090, -0.771150, -0.158950, 0.376650, 0.807440, -0.328450, 0.831210, 0.766920,
        -0.720960, -0.213680, 0.370310, 1.020690, -0.318620, -0.510850, 1.135890, -0.108950, -0.971900, -1.144570,
        -0.099300, 0.226520, 0.154520, -0.409680, 0.077210, -0.745580, 0.009250, 0.854300, 0.973640, 0.166160,

        0.585590, 0.463300, 0.813720, -1.037950, 0.801810, 0.605920, -0.162950, -0.911240, -0.881330, 0.362870,
        -0.627710, -0.331510, -0.137930, -0.363760, 0.349880, 0.441790, 0.682160, 0.805340, 0.863630, -0.152440,
        0.259460, 0.475250, 0.533500, 0.334100, -0.849860, -0.368500, -0.303440, -0.316330, 0.500310, -0.983500,
        -0.770300, -0.053850, 0.767720, 0.475850, -0.910020, -0.436190, -0.459040, 0.179620, -0.739000, -0.103830,
        -0.506100, 0.646810, 0.151920, -0.033610, 0.767930, -0.969050, -0.282710, -0.390370, 0.174790, 0.532690,

        -0.866660, 0.492950, -0.905700, 0.448220, 0.975490, -0.926020, -0.661250, 0.858430, -0.373080, 0.613530,
        -1.068140, 0.957060, 0.010750, -0.156240, -0.755790, -0.631510, 0.176650, 0.831940, 0.048630, 0.598300,
        0.715040, -0.032100, -0.887490, 0.427090, -0.113810, 0.131710, -0.762030, 0.941160, -0.086090, -0.862110,
        0.863460, 0.719250, 0.764990, 0.034190, 0.186330, 0.060290, -0.876490, -0.195500, 0.936890, -0.457510,
        -0.392620, 0.290870, 0.080990, -0.220070, -0.282550, -0.850030, 0.949080, 0.447970, -0.373750, -0.094930,

        0.627100, -0.224780, 0.867370, -0.335280, 0.012160, -0.516230, 0.659880, 0.085290, -0.684290, -0.489590,
        -0.528420, 0.489520, -0.080480, 0.515740, 0.286790, 0.135310, 0.715410, 0.089230, -0.584380, 0.706210,
        -1.102690, -0.422960, 0.799830, 0.202850, 0.811150, -0.885290, 0.679210, -1.052420, -0.080980, 0.310160,
        0.216790, 0.281310, -0.631780, -0.465600, -0.546700, 0.827120, -1.153930, 0.829990, 0.585840, 0.761310,
        0.051110, -0.401130, 0.270650, 0.752640, -0.988480, -0.277560, 0.669600, -0.484310, -0.996250, 0.768920,

        0.423120, -0.331330, 0.364660, -0.405510, 0.094200, -0.329710, -0.405310, -0.537850, -0.117570, -0.512490,
        -0.716880, -0.155620, 0.942660, -0.143150, 0.299190, -0.765890, 0.162280, 0.415200, 0.685430, 0.168240,
        0.311910, -0.840030, -0.651250, 0.644480, 0.601470, 0.873960, 0.448870, -0.524160, -0.672790, 0.828500,
        -0.816120, -0.962490, -0.380400, -0.918740, -0.759760, 0.872470, -0.574160, -0.938140, -0.427890, -0.628460,
        -0.364970, 0.102840, -0.452380, 0.034150, -0.674640, 0.573210, -0.094450, 0.201580, -0.728530, -0.945180,

        0.554200, -0.934600, 0.702660, -0.284130, -0.595560, -0.525090, -0.507560, 0.385990, 0.194700, 0.281550,
        -0.513760, -0.878220, -0.347620, -0.849090, 0.144420, 0.416020, 0.899560, 0.285520, -0.881850, 0.724090,
        -0.447850, 0.373510, -0.942700, 0.823690, -0.891580, -0.483030, 0.301260, 0.545350, -0.876940, 0.218640,
        -0.473490, 0.257160, 0.841410, 0.478150, -0.135180, -0.447740, -0.897760, -0.917060, 0.212330, 0.562630,
        0.680260, 0.330090, -0.145730, -0.210210, -0.728730, 0.729620, -0.064420, 0.602230, -0.513760, -0.649170,

        0.361710, -0.035290, -0.816400, 0.432080, 0.088340, 0.597570, 0.161940, 0.266670, -0.476390, 0.534660,
        -0.600240, 0.950060, -0.272020, -0.986440, -0.530040, -0.319880, -0.670370, 0.766670, 0.936580, -0.651040,
        -0.317890, -0.197040, 1.032380, -0.463470, -0.462910, -0.063100, 0.804350, 0.390810, 0.065580, 0.657710,
        0.862130, -0.037770, -0.841170, 0.593360, 0.867650, -0.968320, -0.551880, -0.484910, -0.736430, 0.101850,
        -0.116890, 0.290680, 0.638730, 0.329120, -0.094280, 0.423020, -0.123840, -0.170140, -0.728420, 0.034290,

        -0.074170, 0.506250, -0.028240, -0.616200, 0.886870, -0.682910, -0.342100, -0.559670, -0.385560, 0.523530,
        0.779560, 0.773550, -0.341420, 0.050380, 0.631110, -0.188180, -0.696970, 0.546940, -0.534260, 0.289770,
        0.595620, -0.741270, -0.754400, 1.040650, 1.043980, -0.117520, -0.312730, 0.680710, -0.254790, -0.770990,
        -0.271680, -0.750910, 0.612380, -0.233010, -0.941000, 0.004210, -0.548610, 0.927260, -0.339690, 0.969990,
        0.557110, 0.160670, -0.379200, 0.500560, -0.127270, -0.090080, 0.299010, 1.056740, 0.737050, 0.600920,

        0.480400, 0.924380, -0.751160, 0.858040, -0.490580, 0.428470, 0.335540, 0.690680, 0.860810, -0.275140,
        0.281060, 0.275700, -0.487680, -0.005600, -0.867140, -0.331380, 0.832540, -1.044480, -0.485270, -0.849480,
        -0.484340, -0.360740, 0.262860, 0.344020, 0.245720, 0.474930, 0.838240, -0.586120, 0.823950, 0.320900,
        -0.465040, 0.765450, -0.259350, -0.318410, 0.278290, 0.629380, 0.490860, -0.673380, -0.770470, -0.078380,
        -0.556130, -0.725880, 0.750680, 0.029370, 0.964050, 0.586230, -0.422060, -0.217150, -0.795850, 0.668010,

        -0.526570, 0.279060, 0.011150, -0.679830, 0.720040, -0.203450, 0.816550, 0.238680, -0.211990, -0.428260,
        0.677080, 0.931930, 1.012650, 0.704170, -0.767020, -0.571710, -0.147310, 0.020830, 0.690450, -0.515330,
        -0.136870, 0.201970, -0.624490, 0.789160, -0.793560, -0.384770, -0.313490, 0.207370, 0.595040, 0.665580,
        -0.599610, 0.507400, -0.510010, 0.724340, -0.045500, -0.733390, -1.088050, -0.079710, -0.124830, 0.104760,
        -0.348180, -0.869210, 0.664050, -0.053620, 0.601350, 0.167730, 0.139040, -0.467370, -0.270690, -0.886210,

        0.016680, 0.657810, 0.358960, 0.285640, -0.905230, -0.090560, 0.886980, -0.401490, -0.005490, -0.720250,
        -0.410080, -0.837600, 0.311940, 0.782270, -0.416630, -0.677000, -0.189430, 0.850180, -0.131550, 0.118240,
        0.450630, -1.019560, 0.723970, 0.693860, 0.242600, -0.566610, -0.737870, -0.651980, -0.247160, 0.558560,
        -0.314210, -0.023320, -0.868320, 0.862340, 0.336250, -0.408800, -0.687200, -0.959780, 0.175310, -0.860280,
        -0.303740, -0.459650, 0.351240, 0.330640, -0.228340, -0.170010, -0.225520, 0.652620, 0.365210, -0.223370,

        0.342240, 0.137090, -0.762650, 0.888100, -0.419720, 0.819910, -0.284040, -0.812890, 0.362670, 0.747820,
        -0.228130, 0.511120, -0.083420, -0.050910, 0.890280, 0.456350, -0.501470, 0.348370, 0.161100, 0.001680,
        -0.881790, -0.033310, 0.586660, -0.018760, 0.513590, -0.411230, 0.814530, 0.228910, 0.494240, -0.647270,
        0.463780, -0.724110, -0.865300, 0.003930, 0.794660, 0.676240, -0.474690, 0.091890, -0.749750, -0.580670,
        0.739530, 0.646520, -0.647500, -0.045270, -0.660180, 0.930930, -0.810570, -0.069860, 0.000440, -0.679850,

        0.315010, 0.336920, -0.767180, -0.806040, -0.447010, 0.516850, -0.435260, -0.410230, -0.889790, -0.209030,
        -0.071210, -0.724160, 0.175170, 1.083890, 0.014170, 0.725830, -0.177680, -0.231340, 0.782050, -0.805220,
        0.706100, -0.167340, 0.453300, 1.034060, 1.130160, 0.301040, -0.271850, -0.489410, -0.063490, 0.247110,
        0.446700, 1.058420, 0.066560, 0.300090, 0.683360, 0.194200, 0.769200, 0.446050, 0.572630, -0.781500,
        -0.228230, 0.803100, -0.530110, 0.041290, 0.822870, -0.716150, -1.009730, -0.194540, -0.329230, 0.937070,

        -0.703630, 0.107090, 0.192690, -0.037610, -0.006380, -0.333440, 0.492410, 0.186100, -0.721090, -0.239410,
        -0.585120, 0.593920, -0.317100, -0.048070, -0.916800, 0.627700, -0.735310, -0.316460, -0.573180, -0.038770,
        -0.382140, 0.179660, 0.876770, 0.849050, -0.941450, 0.812740, 0.777420, -0.452140, 0.761730, 0.110030,
        -0.623290, -0.271280, -0.556260, 0.077020, -0.781340, 0.623780, 0.872680, 0.481590, 0.895720, -0.329140,
        -0.370100, -0.162280, 0.294220, 0.964930, 0.948900, -0.499780, -0.632640, 0.280830, -0.663750, 0.765930,

        -0.516490, 1.613690, 0.978400, -0.947300, -0.621190, -0.637880, -0.796940, 0.743460, 0.645650, 1.023830,
        -0.297570, 0.185020, -0.489170, -0.732920, 0.522890, 0.578050, -0.702420, 0.693890, -1.240560, -0.014560,


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
        0.0, 0.090820, 30,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 32 (Old: 32) */
        0.0, 0.822770, 30,
        &Sources[30],
        &Weights[30],
    },
    { /* unit 33 (Old: 33) */
        0.0, 0.131080, 30,
        &Sources[60],
        &Weights[60],
    },
    { /* unit 34 (Old: 34) */
        0.0, 0.042170, 30,
        &Sources[90],
        &Weights[90],
    },
    { /* unit 35 (Old: 35) */
        0.0, 0.457100, 30,
        &Sources[120],
        &Weights[120],
    },
    { /* unit 36 (Old: 36) */
        0.0, -0.830940, 30,
        &Sources[150],
        &Weights[150],
    },
    { /* unit 37 (Old: 37) */
        0.0, 0.915110, 30,
        &Sources[180],
        &Weights[180],
    },
    { /* unit 38 (Old: 38) */
        0.0, 0.788840, 30,
        &Sources[210],
        &Weights[210],
    },
    { /* unit 39 (Old: 39) */
        0.0, 0.633370, 30,
        &Sources[240],
        &Weights[240],
    },
    { /* unit 40 (Old: 40) */
        0.0, 0.140890, 30,
        &Sources[270],
        &Weights[270],
    },
    { /* unit 41 (Old: 41) */
        0.0, -0.545330, 30,
        &Sources[300],
        &Weights[300],
    },
    { /* unit 42 (Old: 42) */
        0.0, 0.586170, 30,
        &Sources[330],
        &Weights[330],
    },
    { /* unit 43 (Old: 43) */
        0.0, 0.812470, 30,
        &Sources[360],
        &Weights[360],
    },
    { /* unit 44 (Old: 44) */
        0.0, 0.152350, 30,
        &Sources[390],
        &Weights[390],
    },
    { /* unit 45 (Old: 45) */
        0.0, 0.913480, 30,
        &Sources[420],
        &Weights[420],
    },
    { /* unit 46 (Old: 46) */
        0.0, -0.093520, 30,
        &Sources[450],
        &Weights[450],
    },
    { /* unit 47 (Old: 47) */
        0.0, -0.652790, 30,
        &Sources[480],
        &Weights[480],
    },
    { /* unit 48 (Old: 48) */
        0.0, -0.090520, 30,
        &Sources[510],
        &Weights[510],
    },
    { /* unit 49 (Old: 49) */
        0.0, -0.642550, 30,
        &Sources[540],
        &Weights[540],
    },
    { /* unit 50 (Old: 50) */
        0.0, -0.595240, 30,
        &Sources[570],
        &Weights[570],
    },
    { /* unit 51 (Old: 51) */
        0.0, -0.183730, 30,
        &Sources[600],
        &Weights[600],
    },
    { /* unit 52 (Old: 52) */
        0.0, -0.414300, 30,
        &Sources[630],
        &Weights[630],
    },
    { /* unit 53 (Old: 53) */
        0.0, -0.137580, 30,
        &Sources[660],
        &Weights[660],
    },
    { /* unit 54 (Old: 54) */
        0.0, 0.290510, 30,
        &Sources[690],
        &Weights[690],
    },
    { /* unit 55 (Old: 55) */
        0.0, -0.230720, 30,
        &Sources[720],
        &Weights[720],
    },
    { /* unit 56 (Old: 56) */
        0.0, 0.171190, 30,
        &Sources[750],
        &Weights[750],
    },
    { /* unit 57 (Old: 57) */
        0.0, -0.238890, 30,
        &Sources[780],
        &Weights[780],
    },
    { /* unit 58 (Old: 58) */
        0.0, 0.924180, 30,
        &Sources[810],
        &Weights[810],
    },
    { /* unit 59 (Old: 59) */
        0.0, -0.850420, 30,
        &Sources[840],
        &Weights[840],
    },
    { /* unit 60 (Old: 60) */
        0.0, 0.153600, 30,
        &Sources[870],
        &Weights[870],
    },
    { /* unit 61 (Old: 61) */
        0.0, -0.677760, 30,
        &Sources[900],
        &Weights[900],
    },
    { /* unit 62 (Old: 62) */
        0.0, 0.301600, 30,
        &Sources[930],
        &Weights[930],
    },
    { /* unit 63 (Old: 63) */
        0.0, -0.582750, 30,
        &Sources[960],
        &Weights[960],
    },
    { /* unit 64 (Old: 64) */
        0.0, 0.625260, 30,
        &Sources[990],
        &Weights[990],
    },
    { /* unit 65 (Old: 65) */
        0.0, -0.973030, 30,
        &Sources[1020],
        &Weights[1020],
    },
    { /* unit 66 (Old: 66) */
        0.0, 0.667960, 30,
        &Sources[1050],
        &Weights[1050],
    },
    { /* unit 67 (Old: 67) */
        0.0, -0.410440, 30,
        &Sources[1080],
        &Weights[1080],
    },
    { /* unit 68 (Old: 68) */
        0.0, 0.352500, 30,
        &Sources[1110],
        &Weights[1110],
    },
    { /* unit 69 (Old: 69) */
        0.0, -0.893730, 30,
        &Sources[1140],
        &Weights[1140],
    },
    { /* unit 70 (Old: 70) */
        0.0, 0.113790, 30,
        &Sources[1170],
        &Weights[1170],
    },
    { /* unit 71 (Old: 71) */
        0.0, 0.214210, 30,
        &Sources[1200],
        &Weights[1200],
    },
    { /* unit 72 (Old: 72) */
        0.0, -0.795010, 30,
        &Sources[1230],
        &Weights[1230],
    },
    { /* unit 73 (Old: 73) */
        0.0, -0.101940, 30,
        &Sources[1260],
        &Weights[1260],
    },
    { /* unit 74 (Old: 74) */
        0.0, 0.327720, 30,
        &Sources[1290],
        &Weights[1290],
    },
    { /* unit 75 (Old: 75) */
        0.0, 0.848630, 30,
        &Sources[1320],
        &Weights[1320],
    },
    { /* unit 76 (Old: 76) */
        0.0, -0.427950, 30,
        &Sources[1350],
        &Weights[1350],
    },
    { /* unit 77 (Old: 77) */
        0.0, -0.591300, 30,
        &Sources[1380],
        &Weights[1380],
    },
    { /* unit 78 (Old: 78) */
        0.0, 0.917600, 30,
        &Sources[1410],
        &Weights[1410],
    },
    { /* unit 79 (Old: 79) */
        0.0, -0.047600, 30,
        &Sources[1440],
        &Weights[1440],
    },
    { /* unit 80 (Old: 80) */
        0.0, -0.123290, 30,
        &Sources[1470],
        &Weights[1470],
    },
    { /* unit 81 (Old: 81) */
        0.0, 0.280850, 50,
        &Sources[1500],
        &Weights[1500],
    },
    { /* unit 82 (Old: 82) */
        0.0, 0.333580, 50,
        &Sources[1550],
        &Weights[1550],
    },
    { /* unit 83 (Old: 83) */
        0.0, 0.720010, 50,
        &Sources[1600],
        &Weights[1600],
    },
    { /* unit 84 (Old: 84) */
        0.0, 0.975950, 50,
        &Sources[1650],
        &Weights[1650],
    },
    { /* unit 85 (Old: 85) */
        0.0, 0.728410, 50,
        &Sources[1700],
        &Weights[1700],
    },
    { /* unit 86 (Old: 86) */
        0.0, 0.342520, 50,
        &Sources[1750],
        &Weights[1750],
    },
    { /* unit 87 (Old: 87) */
        0.0, -0.137870, 50,
        &Sources[1800],
        &Weights[1800],
    },
    { /* unit 88 (Old: 88) */
        0.0, -0.543070, 50,
        &Sources[1850],
        &Weights[1850],
    },
    { /* unit 89 (Old: 89) */
        0.0, -0.483880, 50,
        &Sources[1900],
        &Weights[1900],
    },
    { /* unit 90 (Old: 90) */
        0.0, -0.556960, 50,
        &Sources[1950],
        &Weights[1950],
    },
    { /* unit 91 (Old: 91) */
        0.0, -0.177650, 50,
        &Sources[2000],
        &Weights[2000],
    },
    { /* unit 92 (Old: 92) */
        0.0, -0.518310, 50,
        &Sources[2050],
        &Weights[2050],
    },
    { /* unit 93 (Old: 93) */
        0.0, -0.686270, 50,
        &Sources[2100],
        &Weights[2100],
    },
    { /* unit 94 (Old: 94) */
        0.0, -0.552530, 50,
        &Sources[2150],
        &Weights[2150],
    },
    { /* unit 95 (Old: 95) */
        0.0, 0.934700, 50,
        &Sources[2200],
        &Weights[2200],
    },
    { /* unit 96 (Old: 96) */
        0.0, 0.000400, 50,
        &Sources[2250],
        &Weights[2250],
    },
    { /* unit 97 (Old: 97) */
        0.0, 0.736310, 50,
        &Sources[2300],
        &Weights[2300],
    },
    { /* unit 98 (Old: 98) */
        0.0, -0.972700, 50,
        &Sources[2350],
        &Weights[2350],
    },
    { /* unit 99 (Old: 99) */
        0.0, 0.854010, 50,
        &Sources[2400],
        &Weights[2400],
    },
    { /* unit 100 (Old: 100) */
        0.0, 0.927950, 50,
        &Sources[2450],
        &Weights[2450],
    },
    { /* unit 101 (Old: 101) */
        0.0, 0.449480, 20,
        &Sources[2500],
        &Weights[2500],
    }

};



int schwa(float* in, float* out, int init)
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
