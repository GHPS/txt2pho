/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    i.c
    --------------------------------------------------------
    generated at Thu Jun 18 17:52:41 1998
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
    -1.057510, 0.608730, -0.018020, 0.979430, 0.456150, 0.028660, 0.983760, -0.898200, 0.209130, -0.763400,
        0.250490, -0.515500, 0.079090, -0.063260, -0.180770, -0.583570, -0.260760, 0.248570, 0.444280, 0.760910,
        0.293760, -0.882610, 0.575120, -0.217430, -0.391100, 0.388210, -1.049110, 0.565040, -0.572070, -0.065190,

        -0.298030, -0.743670, -0.962250, 0.794180, -0.008560, 0.126750, -0.943560, 0.612460, -0.652790, -0.716130,
        0.243100, -0.545860, -0.122440, -0.437930, -0.292200, 0.479650, 0.338270, 0.612480, 0.374960, -0.584630,
        -0.822060, 0.262450, -0.351080, -0.729850, 0.534260, -0.439120, 0.120890, -0.711420, 0.460240, 0.478310,

        1.088700, -0.443760, -0.111740, 0.426630, 0.783620, 0.926550, 0.342940, 0.476980, 0.498460, 0.314620,
        -0.445340, 0.569320, -0.050060, -0.618860, -1.156400, -0.982070, 0.085560, 0.512390, -0.962440, 0.872430,
        -0.626640, 0.934830, -0.057640, -0.746240, 0.375380, 0.008170, 0.799150, 0.006300, -0.589310, -0.376510,

        -0.194140, -0.371280, -0.350540, -0.509870, -0.685590, -0.420310, -0.811940, 0.060940, 0.088580, -0.881940,
        -0.408810, -0.638840, 0.070110, -0.819300, -0.924510, 0.631660, 0.051650, 0.878330, -0.596620, 0.862030,
        -0.249700, 0.607790, 0.614610, 0.299560, -0.880280, 0.535700, 0.551930, -0.015760, 0.167060, 0.865940,

        -0.511420, -0.369620, 0.373070, -0.723010, 0.373950, -0.041580, 0.365050, 0.838470, -0.884480, 0.435900,
        0.505040, 0.412140, -0.283860, 0.577130, 0.380040, 0.299040, -0.784590, 0.443840, -0.509320, 0.847930,
        -0.649250, 0.934460, -0.289180, 0.245390, 0.746750, -0.200140, 0.312160, 0.972680, -0.291930, -0.870780,

        -0.076970, -0.606510, -0.125350, -0.100240, 0.444520, -0.164280, 0.342330, 0.995600, -0.254710, 0.965580,
        -1.026300, 0.672910, -0.939240, -0.787170, 0.384540, -0.405440, 0.388740, -0.652140, 0.077460, -0.669770,
        0.749190, -0.411160, 0.254830, -0.664040, -0.744080, -0.176620, 0.476390, -0.684320, 0.907460, -0.299330,

        0.140540, -0.633620, 0.361120, -0.122920, 0.220800, 0.429770, 0.928390, -0.770700, 0.241650, 0.465920,
        -0.062230, 0.259500, 0.292500, 0.487010, 0.518620, -0.620880, -0.622130, -0.396640, -0.838880, 0.544090,
        0.801480, -0.364190, 0.790440, -0.146330, -0.588940, 0.993330, 0.671870, 0.490860, 0.531180, 0.056290,

        -0.698660, -0.472740, -0.930820, 0.878080, -0.033530, 0.459970, 0.328830, -0.112380, 0.878110, -0.375540,
        0.911340, 0.056300, 0.315840, 0.569360, 0.584670, 0.115710, 0.235120, -0.936190, -0.170170, 0.137680,
        -0.807940, 0.095190, -0.504570, 0.253670, 0.495110, -0.797680, 0.305760, -1.021680, -0.850170, 0.475200,

        -0.502840, -0.816380, -0.195230, 0.743000, 0.982360, -0.422250, 0.119910, -0.789070, -0.258410, -1.061380,
        0.234760, 0.580740, 0.780760, -0.468300, -0.576320, 0.513040, 0.473310, -0.722420, 0.331490, -0.232010,
        1.018110, -0.110040, 0.941230, -0.054170, 0.232100, -0.920440, -0.103470, -0.549190, -0.352810, -0.410040,

        0.779720, -0.214400, 0.941050, 0.091960, -0.996630, 0.314680, -0.430770, -0.851930, 0.226830, 0.783650,
        -0.728990, -0.768860, -0.386260, 0.527950, -0.465870, -0.095660, 0.922610, 0.126760, 0.503090, 0.098820,
        0.163620, -0.407850, -0.617350, 0.715500, -0.651440, -0.133560, 0.811630, 0.440900, -0.733430, 0.170880,

        0.646070, -0.112400, 0.613710, 0.562010, 0.927780, -0.091530, 0.572500, -1.031900, -0.408530, -0.186520,
        -0.833540, 0.044880, 0.146620, 0.286410, 0.461170, -0.891570, 0.296920, 0.160540, -0.626850, 0.072840,
        -0.657340, 0.487600, 0.089330, -0.496740, -0.603890, 0.568050, -0.118860, 0.480470, 0.227770, 0.738640,

        0.200080, -0.923240, 0.657530, -0.791700, 0.428790, 0.568520, 0.914760, 0.718520, -0.782640, -0.208700,
        1.003570, 0.575520, 0.815490, -0.132990, 0.086290, 0.663180, -0.305530, -0.214840, -0.359410, 0.515880,
        0.702630, 0.258970, -0.594240, -0.979050, 0.348100, 0.399870, -0.498660, -0.744620, 0.659410, 0.865410,

        0.834550, 0.888660, -0.675120, -0.712720, -0.411010, 0.408210, -0.810130, 0.396590, 0.687450, 0.710230,
        0.616370, -0.532460, -0.359910, 0.172580, 0.395410, -0.189900, 0.165450, -0.881510, 0.852490, -0.667790,
        0.366510, 0.727340, -0.315860, 0.503880, 0.693240, 0.616660, -0.404920, 0.113270, 0.101410, -0.567330,

        1.137310, -1.021410, 0.401070, -0.621010, -0.576810, 0.390530, -0.648340, 0.617970, 0.851650, 0.903340,
        -0.577670, -0.594640, 0.484370, -0.404950, 0.131960, 0.311040, -0.774090, 0.389160, 0.108080, -0.057470,
        -0.395970, 0.896300, -0.094830, -0.469820, -0.021260, -0.465280, 0.925540, 0.152570, 0.769530, -0.499650,

        0.576620, 0.792690, 0.348880, -0.252300, -0.341120, -0.062100, -0.488270, 0.221090, 0.231520, 0.951110,
        -0.169480, 0.079660, -0.536230, -0.857330, 0.745900, -0.789620, 0.603840, -0.523100, -0.180500, 0.163490,
        0.580790, -0.869880, -0.072240, -0.831540, -0.307200, -0.872410, -0.376850, 0.444610, -0.368580, -0.935390,

        0.611930, -0.437790, -0.568770, 0.677550, -0.403110, -0.875410, 0.792180, 0.194300, -0.647560, 0.046650,
        0.540720, -0.408580, -0.884620, 0.576550, -0.322300, 0.668080, 0.262490, 0.424130, 0.577040, -0.089440,
        0.674150, -0.002250, -0.958510, 0.623450, -0.270920, -0.005300, 0.522120, -0.935200, 0.077140, -0.810030,

        1.018790, 0.446940, -0.918770, 0.124650, 0.901850, 0.846950, -0.614180, -0.771870, 0.838970, -0.551640,
        -0.218270, -0.462790, -0.767070, -0.014930, 0.164130, 0.234310, 0.331890, 0.855110, -0.573750, 0.694550,
        -0.161410, -0.315140, -0.972900, -0.594690, -0.474490, -0.819680, -0.706360, -0.168340, 0.471960, 0.569620,

        -0.480900, 0.566870, 0.087720, -0.717610, 1.007740, -0.284530, -0.761940, 0.453550, -0.935750, 1.082590,
        -0.428490, -0.311800, 0.937970, -0.517350, 0.809690, -0.903310, -0.151210, 0.404140, 0.146850, -0.379850,
        0.635040, 0.372930, 0.009220, -0.598550, -0.039500, -0.466600, -0.919140, 0.754080, -0.755770, 0.934150,

        0.712900, -0.828970, -0.896740, -0.137370, 0.628910, 0.899410, -0.512110, 0.273320, -0.504310, 0.469290,
        -0.275190, -0.351640, -0.147940, -0.138090, -0.634420, -0.780930, -0.370240, -0.510380, 0.226230, 0.980810,
        -0.932760, -0.736980, -0.112300, 0.348800, 0.507670, 0.303410, -0.859300, -0.141740, -0.534260, 0.879450,

        -0.600430, 0.930650, 0.213250, 0.731080, -0.515990, 0.925250, -0.240580, 0.750820, 0.771130, 0.027990,
        -0.528500, 1.138550, 0.205400, -0.758030, 0.852000, -0.785500, -0.738940, -0.456480, -0.400630, 0.777530,
        -0.313440, -0.033760, 0.345170, 0.694230, 0.236370, 0.627890, 0.226130, 0.897400, -0.665190, 0.347810,

        -0.010950, 0.595830, 0.170270, 0.366890, -0.842320, -0.188840, 0.601070, 0.357330, -0.894350, 0.408270,
        0.064620, 0.234130, 0.762820, -0.947080, -0.499300, 0.341690, 0.502050, 1.086660, -0.543850, -0.243620,
        0.612440, -0.192120, 0.838860, 0.768170, 0.218550, -0.045190, -0.895850, -0.045600, -0.262430, 0.687250,

        -0.325240, 0.524490, -0.544680, -0.693380, 0.495290, 0.455380, 0.574140, 0.865100, 0.069090, 0.442780,
        -0.317330, -0.178110, 0.185540, 0.961460, 0.455250, 0.584030, -0.133310, 0.225290, 0.450210, -0.762570,
        0.540270, -0.410410, -0.231100, 0.156150, -0.246950, -0.005050, 0.243190, -0.806490, -0.847720, -0.125210,

        -0.168810, 0.944080, 0.778580, -0.169950, 0.623010, 0.965700, 0.182170, 0.228490, -0.406630, -0.521770,
        -0.115060, -1.081270, 0.074340, 0.081150, 0.483920, -0.974960, -0.946320, -0.186460, -0.704280, 0.574190,
        -0.058910, -0.567370, -0.606860, -0.730370, -0.668800, 0.851720, -0.658840, 0.179290, -0.294350, -0.550940,

        -0.304050, 0.835620, -0.424530, -0.243800, -1.058280, -0.301570, 0.960580, 1.047690, -0.938540, -0.490390,
        0.118330, -0.264090, -0.910920, -0.435660, -0.146540, 0.806680, 0.599130, -0.767730, -0.775020, -0.571430,
        -0.423430, -0.137420, 0.903220, -0.329350, -0.272310, 0.349900, -0.591160, 0.234970, -0.086780, -0.713650,

        -0.501550, -0.252610, -0.110800, -0.351180, -0.160960, 1.014310, 0.641390, 0.624460, 0.270200, -0.736570,
        -0.664550, -0.713980, -0.923090, -0.132090, 0.573970, -0.339900, 0.121860, -0.839580, -0.622700, -0.995160,
        0.767920, 0.486620, 0.181080, 0.113220, 0.287960, 0.316430, 0.409260, -0.568560, 0.145710, 0.083900,

        0.489110, 0.754820, -0.560350, 0.956520, -0.430840, 0.727510, -0.152820, -0.284330, 0.065170, 0.018050,
        0.327920, 0.500450, -0.262410, 0.939890, -0.004880, -0.680700, 0.600650, 0.011730, -1.175090, -0.174840,
        -0.399500, 0.677280, 0.264330, -0.943000, -0.478380, 0.136510, -0.323020, 0.109510, 0.084350, 0.370680,

        -0.508890, -0.895730, -0.105840, 0.396990, -0.793450, -0.740700, -0.603970, -1.000660, -0.056380, -0.222680,
        -0.475590, -0.316820, -0.182740, -0.768160, 0.456950, 0.658000, 0.851460, 0.872680, 0.695350, 0.073690,
        -0.353170, 0.451810, -0.220720, 0.981630, 0.663830, -0.812710, -0.358960, -0.807430, 0.227610, 0.204270,

        -0.351480, -0.360140, 0.764180, -0.431090, -0.615300, -0.676160, 0.410990, -0.882160, 0.728570, -0.632360,
        -0.803020, -0.442330, -0.282370, 0.441790, 0.631920, -0.062110, 0.540800, -0.173710, 0.970790, -0.533840,
        0.528120, 0.579290, -0.120680, -0.221900, 0.532420, -0.329600, -0.529710, 0.075940, -0.108580, 0.375720,

        -0.131480, 0.585180, 0.462030, 0.003080, -0.786150, -0.052310, 0.595490, 0.787780, -0.224870, 0.796580,
        -0.026420, -0.327390, 0.995350, 0.523750, -0.532250, -0.007800, 0.578350, -0.508350, -0.258320, 0.367030,
        -0.523930, -0.388420, -0.886050, 0.939740, 0.106140, -0.972030, -0.978430, -0.375630, -0.789930, 0.150130,

        -0.921420, -0.304470, 0.953180, 0.657370, 0.192060, 0.545710, 0.870840, 0.092860, 0.526230, 1.186770,
        0.618160, -0.514180, 0.456270, -0.076020, 0.541880, 0.659450, -0.949810, -0.094620, 0.785270, -0.313400,
        0.686240, 0.708180, -0.559460, -0.096690, -0.828640, 0.490270, 0.107230, -1.041410, 0.674410, 0.803680,

        -0.784050, -0.886580, -0.698510, 0.369490, 0.206720, 0.382600, -0.490230, 1.035990, 0.510550, -0.244360,
        -0.333690, 0.271910, -0.080540, -0.462170, 0.404020, 0.415070, -0.708200, -0.043740, -0.350840, 0.545310,
        -0.567930, -0.091880, -0.280740, 0.452220, -0.370350, 0.135430, -0.558470, 0.970030, 0.965440, 0.375700,

        0.833130, -0.661340, -0.006080, 0.038330, 0.434000, 0.616090, 0.161340, 0.381230, -0.001710, 0.835100,
        1.001490, -0.391820, 0.531290, 0.697090, -1.008520, -0.882000, 0.664910, 0.252740, -0.557250, -1.027860,
        0.545910, 0.021940, 0.220960, 0.114210, -0.779620, 0.720960, 0.576570, -0.839830, -0.802740, 0.427040,

        0.147670, -0.784030, -0.736170, 1.056110, 0.893490, 0.844460, 0.358960, -0.414270, -0.051050, 0.986630,
        -0.421090, -0.634930, -0.361600, -0.350860, -0.504250, 0.193680, 0.778050, -0.761100, -0.599180, 0.938720,
        -0.761500, -0.033760, 0.247320, -0.257060, 0.588420, -0.923790, -0.752030, -0.902510, 0.862840, 0.233110,

        0.565690, 0.752220, 0.249310, 0.378370, -0.882060, 0.295170, 0.547910, 0.751020, -0.413580, 0.569620,
        -0.213350, -0.937630, 0.279510, 0.125740, -0.149520, 0.335980, -0.868140, -0.909750, 0.771440, -0.579530,
        -0.882730, 0.175600, 0.508220, 0.234860, 0.229890, 0.967160, 1.034110, -0.475110, 0.582030, 0.630870,

        0.036660, -0.396880, -0.588990, 0.121950, -0.689790, -0.124360, -0.147370, -0.602860, 0.881350, 0.328050,
        -0.481460, -0.875930, -0.067540, 0.965690, 0.550000, 0.081300, 0.405750, -0.316210, 1.162480, -0.782270,
        0.551920, -0.492990, -0.823460, -0.511710, 0.090680, 0.371100, 0.091730, 0.380490, 0.122120, -0.948150,

        0.871310, 0.333030, -0.927470, 0.617910, 0.350190, 0.910150, 0.499750, -0.420270, 0.689620, -0.568870,
        0.375410, 0.802390, 0.337660, -0.349080, -0.803940, -0.299840, -0.383120, 0.252400, 0.247050, 0.340270,
        -0.545430, -0.616890, -0.244860, 0.466180, 0.116670, 0.286530, -0.292060, -1.051280, -0.855650, 0.718940,

        -1.568350, 0.605040, 1.367100, 0.709890, -0.180310, -0.104250, 1.228600, 0.801530, 0.405620, 0.110870,
        0.500910, -1.231900, -0.663820, -0.613830, 1.211170, -0.948970, 1.264500, 0.157770, 1.244160, 0.911710,
        -0.783070, 0.847080, 0.862540, -0.478200, -0.639070, 0.669030, -0.775330, -0.031180, -0.527760, -0.890450,

        0.705270, -0.335390, -1.063080, 0.343770, 0.872070, -0.742600, -0.249690, -0.152460, -0.319460, -0.838100,
        -0.279090, -0.023170, 0.440290, -0.778180, 0.182360, 0.347950, -0.419620, -0.449540, -0.764200, 0.187320,
        0.891350, -0.435200, -0.486060, -0.541170, -0.060320, 0.100410, -0.338010, -0.102730, 0.129740, -0.692920,

        0.040790, 0.891090, 0.547180, 1.052030, 0.450990, -0.546260, -0.430810, 0.467450, 0.846810, -0.600060,
        -0.939140, 0.341580, -0.465760, 0.837130, 0.333490, -0.724050, -0.470910, -0.685980, 0.376860, -0.412610,
        0.548530, 0.546880, 0.984910, 0.751510, -0.304200, -0.184160, -0.898240, -0.169080, 0.881250, -0.878500,

        0.901370, -0.897630, -0.276680, -0.877930, 0.061650, 0.667390, -0.947590, -0.399490, -0.510870, 0.161900,
        0.577970, 0.581950, -0.117580, -0.563170, -0.280270, -0.832120, -0.187700, -0.167770, 0.231110, -0.282170,
        0.750060, -0.719780, -0.649620, -0.383230, 0.638540, 0.963720, -0.562700, 0.588880, 0.441050, 0.680120,

        0.074530, 0.560920, -0.800160, -0.431410, 0.647260, -1.036650, -0.873420, 0.587650, 0.562970, -0.570940,
        0.823450, 0.812830, 0.923580, -0.063070, 0.225460, -0.764770, -0.998570, 0.101560, -0.518760, 0.097790,
        0.394130, 0.386810, 0.282770, -0.309950, 0.951240, 0.793690, 0.060500, -0.202200, 0.499280, 0.032520,

        0.519170, 0.704340, -0.007660, -0.706230, -0.129760, -0.267000, 0.732170, -0.573690, -0.455760, -0.159030,
        -0.527960, -0.221820, 0.068540, 0.806130, 0.192770, 0.518660, 0.595360, -0.865450, 0.663300, 0.828280,
        0.015950, -0.780840, 0.374760, -0.565460, 0.672450, 0.631010, 0.958470, 0.937430, 0.664390, 0.659910,

        0.004500, 0.527940, -0.183300, 0.841200, -0.743170, -0.550010, -0.861780, -0.014600, -0.759870, -0.385140,
        -0.889780, -0.606450, -0.210200, -0.253220, 0.527410, 0.479080, 0.845880, -0.344170, 0.780590, 0.256230,
        -0.784140, 0.079680, 0.672890, 0.667420, -0.549070, 0.673300, -0.663470, 0.932190, 0.149770, 0.937580,

        0.615460, -0.540660, -0.344140, -0.116840, -0.388090, 0.611310, -0.394530, 0.650880, 0.734350, 0.847420,
        0.575910, -0.612650, -0.778900, 0.152240, -0.426110, 0.743520, 0.304560, -0.793960, 0.384480, 0.260430,
        0.918780, 0.670980, 0.767680, -0.363820, -0.871230, -0.189440, -1.018500, 0.064390, -0.621670, -0.607610,

        0.025980, -0.475410, -0.931760, 0.152180, -0.798440, 0.772630, 0.373990, 0.003760, -0.711640, 0.380870,
        0.765100, 0.871100, -0.899050, -0.428920, 0.597040, -0.061860, -0.700550, 0.784750, 0.297240, 0.865580,
        0.828460, -0.897930, 0.968790, 0.522820, 0.150720, 0.756620, 0.758620, 0.058090, 0.438130, 0.328390,

        -0.092790, 0.193600, -0.250830, -0.875660, -0.638160, -0.682570, -0.981210, -0.427910, -0.589470, -0.485930,
        0.297120, -0.773130, 0.173360, -0.708820, -0.708910, -0.283090, 0.296090, -0.324070, 0.413830, 0.194980,
        0.640820, -0.840290, -0.163220, -0.522770, -0.946740, 0.419020, 0.557610, 0.611610, -0.202620, -0.359530,

        -0.760390, -0.823960, -0.278620, 0.062080, 0.985470, -0.807010, -1.053050, 0.210530, 0.683090, 0.303800,
        -0.551490, -0.785820, -0.086930, -0.652380, 0.626870, 0.608520, -0.233200, -0.886320, -0.422580, -0.233840,
        -0.087770, 0.735750, 0.578220, -0.079610, 0.604450, 0.315060, -0.849230, 0.182120, -0.712850, 0.329780,

        -0.823520, -0.490650, -0.025510, 0.561540, 0.141600, 0.887220, -0.308420, -0.590890, 0.591120, -0.047750,
        -0.265040, 0.180440, 0.889740, 0.868650, 0.811470, 0.074690, 0.883020, -0.512480, -0.173290, 0.889420,
        -0.013300, -0.640780, 0.134850, 0.742310, 0.758760, -0.368810, 0.303730, -0.973590, 0.886210, 0.725210,

        0.554810, 0.915500, 0.510160, -0.406920, -0.787960, 0.308340, -0.820490, 0.717990, -0.982400, -0.631030,
        0.023480, -0.861090, 0.795360, -0.819720, 0.662650, -0.496610, 0.474880, -0.539620, -0.511020, -0.370520,
        0.121150, -0.289170, -0.961650, 0.282050, -0.204570, -0.989100, 0.337280, -0.850220, 1.072090, -0.403540,

        0.532460, 0.019600, 0.866370, 0.444910, 0.645460, 0.154370, 0.667930, 1.197340, 0.530060, 0.967850,
        0.250530, 0.148070, 0.087210, 0.305810, 0.038240, 0.840150, -0.185110, -0.856160, 0.534580, 1.019430,
        0.240320, 0.636450, 0.662020, 0.120070, -0.649750, 0.020480, -0.689470, -0.979970, -0.624260, 0.066620,

        -0.658410, -0.399900, 0.150550, -0.710620, 0.112540, 0.978100, 0.413820, -0.169920, 0.404130, 0.065230,
        -0.289590, -0.531410, 0.906300, 0.352280, 0.555360, 0.661550, 0.712890, -0.686560, -0.762270, -0.693290,
        -0.459560, 0.116450, 0.261750, -0.919560, -0.547150, 0.098420, -0.535940, 0.491150, -0.512850, -0.099730,
        0.807970, 0.070660, 0.420960, -0.119150, -0.554350, -0.704860, 0.369780, -0.355640, -0.691720, 0.364460,
        0.542010, -0.375710, 0.647350, -0.013770, 0.265550, 0.360830, -0.626030, 0.631030, 0.525660, -0.647900,

        -1.431390, 0.565230, 0.995750, 0.148030, -0.251420, -0.695260, -0.688910, -0.243790, 0.273940, -0.826990,
        -0.203910, 0.321350, 0.427300, 0.100320, 0.166320, 0.317510, 0.733110, -1.106930, -0.192250, -0.306550,
        0.403590, 0.286530, -0.742660, -0.323050, 0.285090, 1.111130, -0.100900, -0.766410, -0.734510, -1.506460,
        -0.699320, 0.548030, -0.539740, -0.089750, 0.289290, 1.009330, -2.011370, 0.895500, -0.363140, 0.358010,
        1.342330, -0.873010, -0.635130, -0.452470, 1.036080, -1.022600, -1.179320, -0.529700, -0.963390, -0.366820,

        -0.411230, 0.335670, -0.217850, -0.556460, 0.479890, -0.174890, 0.381560, 0.255010, 0.507610, 0.323180,
        0.677700, -1.066840, 0.426980, 0.746420, -0.320060, 0.154000, 0.326700, -0.480300, -0.427850, -1.157710,
        0.384360, -0.922390, 0.943920, 0.797260, 0.003350, -0.857390, -0.380920, 0.694960, -0.122610, -0.783420,
        0.799740, -0.804790, -0.172230, 0.526160, 0.911120, -0.747980, -0.987780, 0.463870, 0.778020, 0.427940,
        0.736930, -0.458330, 0.758490, -0.738930, -0.230060, -0.159700, -0.663500, -0.163460, -0.874720, 0.237140,

        -0.918920, 0.818730, 0.166460, 0.340850, 0.869260, 0.246660, -0.482630, -0.368150, 0.750810, 0.511580,
        -0.162740, 0.362060, -0.413210, -0.265560, -0.677310, 0.643340, -0.436180, 0.893150, 0.128790, 0.658970,
        -0.444910, 0.205780, -0.225480, -0.730000, -0.037850, -0.803060, -0.270780, -0.637840, -0.176510, -0.313410,
        -0.445100, -0.276100, -0.162990, -0.454850, -1.010070, 0.277940, -0.180150, 0.684550, -0.677050, -0.724360,
        -0.186550, -0.906740, -0.837610, -0.272560, -0.535880, 0.348340, 0.218350, -0.334300, -0.872060, -1.012660,

        -0.941890, -0.032510, 0.230340, 0.185730, -0.457900, 0.096670, 0.693670, 0.839950, 0.272030, -0.351040,
        0.720370, 0.754140, 0.701750, -0.589040, 0.567590, -0.115980, 0.273990, 0.283930, 0.319570, -0.834010,
        0.630320, 0.554510, 0.302370, -0.634240, 0.047480, -0.299070, -0.656370, 0.618700, 0.798460, -1.000380,
        0.964060, 0.137690, 0.914750, -0.354500, 0.452380, -0.515110, -0.875730, 0.922860, -0.668990, 0.623960,
        0.331080, -0.796040, 0.832980, -0.748750, 0.148870, 0.127370, -0.010450, 0.356610, -0.295910, -0.002460,

        0.823360, -0.226240, -0.554650, 0.633980, -0.431470, -0.830560, 0.843480, 0.323470, -0.503350, 0.049750,
        0.975560, -0.947400, -0.578980, -0.672530, 0.555180, -0.598570, -0.061370, -0.536670, -0.298670, -0.373520,
        -0.278490, -0.441550, 0.409990, -0.712670, 0.863570, 0.729600, 0.702730, -0.455990, -0.309410, 0.753170,
        -0.698540, 0.531250, 0.918620, -0.607790, 0.763660, 0.171340, 0.100610, 0.251500, -0.177960, 0.922180,
        -0.302000, -0.616140, 0.081310, -0.376350, -0.635450, 0.287380, -0.081080, 0.211440, 0.617650, -0.300830,

        0.013760, -0.510390, -0.976590, -0.801080, 0.331800, -0.941850, 0.181300, -0.812100, -0.402090, 0.761540,
        -0.121580, 0.471670, 0.293690, 0.428610, -0.965440, -0.224510, 0.584950, 0.501150, 0.727380, 0.308130,
        0.132390, -0.072670, -0.053410, -0.722710, -0.216370, 0.317290, 0.869200, -0.306580, 0.895310, 0.842380,
        -0.668770, -0.230230, 0.389850, 1.011820, -0.374500, -0.494290, 1.170090, -0.171060, -0.902250, -0.993090,
        -0.130720, 0.181000, 0.239670, -0.422650, 0.082630, -0.755830, 0.158540, 0.906190, 0.953950, 0.237030,

        0.269590, 0.515290, 0.980190, -0.976970, 0.856420, 0.547370, -0.099710, -0.983750, -0.946590, 0.604420,
        -0.584090, -0.326390, -0.103600, -0.104990, 0.286070, 0.488610, 0.814400, 0.882950, 0.905880, -0.124550,
        0.176570, 0.489410, 0.634560, 0.141310, -0.708860, -0.284620, -0.334580, -0.411710, 0.395480, -1.049300,
        -0.666400, 0.067770, 0.629160, 0.583340, -0.743300, -0.467700, -0.791280, 0.313950, -0.764050, -0.131290,
        -0.237010, 0.659110, 0.258500, 0.200690, 0.863750, -0.935550, -0.377410, -0.386790, 0.368610, 0.505860,

        -0.896250, 0.403080, -0.866540, 0.422180, 0.961590, -0.901810, -0.639880, 0.821200, -0.347130, 0.651340,
        -0.962270, 0.938940, -0.088650, -0.177770, -0.789130, -0.630430, 0.183000, 0.795770, 0.039770, 0.605660,
        0.666400, -0.078790, -0.886360, 0.354440, -0.102100, 0.194900, -0.765290, 0.969690, -0.138780, -0.885560,
        0.843320, 0.654890, 0.733600, 0.032090, 0.229850, 0.063800, -0.885540, -0.174980, 0.942360, -0.521640,
        -0.400680, 0.245030, 0.067880, -0.226850, -0.299830, -0.856310, 0.883710, 0.407570, -0.450660, -0.110860,

        0.403240, -0.209250, 0.997440, -0.393170, -0.030240, -0.667050, 0.855180, 0.224490, -0.606800, -0.451710,
        -0.462830, 0.592070, -0.208850, 0.531160, 0.106640, 0.163630, 0.864870, -0.129800, -0.550830, 0.620180,
        -1.195560, -0.533960, 0.919960, -0.039280, 1.097650, -0.692650, 0.530150, -1.217690, -0.193100, 0.281150,
        0.255730, 0.458590, -0.456530, -0.333080, -0.430390, 0.950290, -1.506160, 0.946650, 0.387580, 0.557400,
        0.245120, -0.454940, -0.013030, 0.914870, -0.911770, -0.316380, 0.433600, -0.467230, -0.814890, 0.686630,

        0.461250, -0.330310, 0.347500, -0.406980, 0.092090, -0.323680, -0.406270, -0.523670, -0.102940, -0.521490,
        -0.724030, -0.152930, 0.946580, -0.158750, 0.304770, -0.769050, 0.145970, 0.413800, 0.688940, 0.182730,
        0.314600, -0.823860, -0.642160, 0.672460, 0.604750, 0.859070, 0.445600, -0.512470, -0.659580, 0.853650,
        -0.812210, -0.968430, -0.370680, -0.895750, -0.761410, 0.879470, -0.524190, -0.949150, -0.417660, -0.622560,
        -0.390610, 0.101670, -0.433530, 0.038830, -0.674370, 0.572950, -0.074370, 0.206730, -0.740030, -0.918070,

        0.554570, -0.944370, 0.689620, -0.287360, -0.605820, -0.522280, -0.515040, 0.372070, 0.189860, 0.274950,
        -0.513730, -0.890730, -0.373220, -0.855390, 0.134910, 0.415790, 0.894180, 0.280560, -0.890120, 0.708060,
        -0.457740, 0.366970, -0.942920, 0.810770, -0.900730, -0.489930, 0.293550, 0.538590, -0.878930, 0.206750,
        -0.479770, 0.242270, 0.835130, 0.470220, -0.135690, -0.464240, -0.897940, -0.919220, 0.202340, 0.536050,
        0.668190, 0.323070, -0.163960, -0.225890, -0.743500, 0.729270, -0.082600, 0.586520, -0.517250, -0.663120,

        0.669780, 0.000190, -0.817140, 0.508540, 0.259470, 0.725360, 0.236670, 0.302870, -0.441520, 0.606300,
        -0.459130, 1.038530, -0.082720, -0.948570, -0.298020, -0.267020, -0.732590, 0.981380, 0.930540, -0.487930,
        -0.184110, -0.110580, 1.021100, -0.216380, -0.569650, -0.060860, 0.927230, 0.683560, 0.148780, 0.839740,
        0.933220, -0.144630, -0.831090, 0.685100, 0.876430, -0.976700, -0.115260, -0.517070, -0.598680, 0.303780,
        -0.203620, 0.496400, 0.937340, 0.299370, 0.019780, 0.450260, 0.055490, -0.042540, -0.848260, 0.226300,

        -0.115000, 0.512460, -0.128380, -0.596700, 0.786100, -0.715750, -0.512770, -0.697580, -0.465510, 0.530070,
        0.709310, 0.652620, -0.346420, 0.025730, 0.687150, -0.273570, -0.614540, 0.616850, -0.519480, 0.173140,
        0.557910, -0.795190, -0.852210, 0.950970, 0.826780, -0.159430, -0.235200, 0.644770, -0.283830, -0.893590,
        -0.357610, -0.786200, 0.523780, -0.447670, -0.992710, -0.007130, -0.702730, 0.913310, -0.337360, 1.099580,
        0.491360, 0.081910, -0.386790, 0.379080, -0.226410, -0.070550, 0.317080, 0.965180, 0.725210, 0.467420,

        0.447410, 0.962410, -0.814260, 0.837580, -0.529520, 0.315070, 0.286680, 0.706180, 0.897270, -0.277930,
        0.226690, 0.260420, -0.485240, -0.038130, -0.960670, -0.306030, 0.859940, -1.070210, -0.494110, -0.960980,
        -0.538770, -0.374250, 0.224820, 0.221080, 0.264850, 0.452860, 0.887470, -0.572300, 0.744530, 0.340700,
        -0.527430, 0.761520, -0.295710, -0.318830, 0.357520, 0.655700, 0.340370, -0.682830, -0.808870, -0.062900,
        -0.493080, -0.748540, 0.715010, 0.055460, 0.967040, 0.593280, -0.461610, -0.245770, -0.825380, 0.602220,

        -0.734200, 0.256350, 0.054670, -0.753000, 0.690370, -0.327890, 0.839970, 0.246120, -0.198340, -0.382340,
        0.648430, 0.924070, 0.954780, 0.756380, -0.995970, -0.458850, -0.139000, -0.118870, 0.676980, -0.663900,
        -0.244790, 0.205240, -0.596560, 0.618430, -0.570270, -0.410510, -0.389980, 0.140420, 0.463320, 0.606190,
        -0.687190, 0.537520, -0.579960, 0.843730, 0.129900, -0.731370, -1.335410, -0.052510, -0.228430, -0.053890,
        -0.202370, -0.828550, 0.538310, 0.079430, 0.621250, 0.157140, -0.064640, -0.522370, -0.235300, -0.961680,

        0.029830, 0.648550, 0.334840, 0.304660, -0.896140, 0.003090, 0.810280, -0.484400, -0.095340, -0.757070,
        -0.435420, -0.891440, 0.321690, 0.778080, -0.351970, -0.675870, -0.172880, 0.891350, -0.176890, 0.166470,
        0.542010, -0.974030, 0.596650, 0.791160, 0.129590, -0.614680, -0.624670, -0.598660, -0.239410, 0.459770,
        -0.320030, -0.159550, -0.947150, 0.680500, 0.250880, -0.448720, -0.734330, -0.963870, 0.279380, -0.834170,
        -0.340650, -0.435320, 0.436130, 0.225790, -0.248190, -0.169320, -0.122370, 0.644520, 0.221530, -0.268640,

        0.224480, 0.113380, -0.694380, 0.774170, -0.341610, 0.736380, -0.209500, -0.716940, 0.469300, 0.841860,
        -0.145790, 0.560010, 0.033620, -0.025910, 0.752160, 0.643600, -0.516780, 0.262190, 0.155190, -0.115360,
        -0.975870, -0.005840, 0.510240, -0.048850, 0.757580, -0.447730, 0.887550, 0.411680, 0.330430, -0.645360,
        0.323930, -0.816920, -0.885860, 0.148730, 1.082230, 0.698900, -0.696040, 0.181210, -0.737860, -0.558210,
        0.919520, 0.876920, -0.574550, 0.116560, -0.552420, 0.935180, -0.851130, -0.021650, -0.141100, -0.696500,

        0.465290, 0.375370, -0.898350, -0.822190, -0.500270, 0.697680, -0.645210, -0.409640, -0.851040, -0.347770,
        -0.195620, -0.808900, 0.191900, 0.985800, 0.134930, 0.677120, -0.448010, -0.215910, 0.690960, -0.666800,
        0.672520, -0.218480, 0.460320, 1.268060, 0.964730, 0.226220, -0.185580, -0.388620, 0.024400, 0.469210,
        0.495170, 0.894430, -0.069720, 0.311410, 0.585960, 0.023520, 1.234460, 0.251260, 0.840390, -0.647030,
        -0.373860, 0.489180, -0.289940, 0.050080, 0.713760, -0.733140, -0.804710, -0.278920, -0.550590, 1.147580,

        -0.679250, 0.076480, 0.131330, -0.005350, -0.031440, -0.307070, 0.449590, 0.120800, -0.797830, -0.314390,
        -0.624810, 0.557850, -0.359910, -0.053190, -0.924810, 0.586860, -0.793740, -0.299710, -0.593660, -0.047410,
        -0.355820, 0.157980, 0.898060, 0.880640, -1.026580, 0.780940, 0.736530, -0.511220, 0.808890, 0.124190,
        -0.586910, -0.265200, -0.594030, 0.061900, -0.867620, 0.553610, 0.997210, 0.415090, 0.896640, -0.369850,
        -0.402440, -0.232910, 0.262900, 0.926210, 0.888380, -0.502460, -0.618500, 0.222460, -0.653680, 0.781520,

        0.057220, 3.004830, 1.001160, -0.757020, -0.638660, -0.235930, -0.533780, 0.818630, 0.151140, 1.477110,
        -0.299580, 0.059520, -1.015630, -0.880890, 0.819440, 1.035050, -0.453260, 1.225370, -1.439790, -0.474700,


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
        0.0, 0.101710, 30,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 32 (Old: 32) */
        0.0, 0.928600, 30,
        &Sources[30],
        &Weights[30],
    },
    { /* unit 33 (Old: 33) */
        0.0, -0.083140, 30,
        &Sources[60],
        &Weights[60],
    },
    { /* unit 34 (Old: 34) */
        0.0, -0.067980, 30,
        &Sources[90],
        &Weights[90],
    },
    { /* unit 35 (Old: 35) */
        0.0, 0.472860, 30,
        &Sources[120],
        &Weights[120],
    },
    { /* unit 36 (Old: 36) */
        0.0, -0.677680, 30,
        &Sources[150],
        &Weights[150],
    },
    { /* unit 37 (Old: 37) */
        0.0, 0.966360, 30,
        &Sources[180],
        &Weights[180],
    },
    { /* unit 38 (Old: 38) */
        0.0, 0.760570, 30,
        &Sources[210],
        &Weights[210],
    },
    { /* unit 39 (Old: 39) */
        0.0, 0.829630, 30,
        &Sources[240],
        &Weights[240],
    },
    { /* unit 40 (Old: 40) */
        0.0, 0.190120, 30,
        &Sources[270],
        &Weights[270],
    },
    { /* unit 41 (Old: 41) */
        0.0, -0.554530, 30,
        &Sources[300],
        &Weights[300],
    },
    { /* unit 42 (Old: 42) */
        0.0, 0.601370, 30,
        &Sources[330],
        &Weights[330],
    },
    { /* unit 43 (Old: 43) */
        0.0, 0.761910, 30,
        &Sources[360],
        &Weights[360],
    },
    { /* unit 44 (Old: 44) */
        0.0, 0.258590, 30,
        &Sources[390],
        &Weights[390],
    },
    { /* unit 45 (Old: 45) */
        0.0, 0.876610, 30,
        &Sources[420],
        &Weights[420],
    },
    { /* unit 46 (Old: 46) */
        0.0, -0.134670, 30,
        &Sources[450],
        &Weights[450],
    },
    { /* unit 47 (Old: 47) */
        0.0, -0.566200, 30,
        &Sources[480],
        &Weights[480],
    },
    { /* unit 48 (Old: 48) */
        0.0, 0.010600, 30,
        &Sources[510],
        &Weights[510],
    },
    { /* unit 49 (Old: 49) */
        0.0, -0.650590, 30,
        &Sources[540],
        &Weights[540],
    },
    { /* unit 50 (Old: 50) */
        0.0, -0.545540, 30,
        &Sources[570],
        &Weights[570],
    },
    { /* unit 51 (Old: 51) */
        0.0, -0.198210, 30,
        &Sources[600],
        &Weights[600],
    },
    { /* unit 52 (Old: 52) */
        0.0, -0.436720, 30,
        &Sources[630],
        &Weights[630],
    },
    { /* unit 53 (Old: 53) */
        0.0, -0.057210, 30,
        &Sources[660],
        &Weights[660],
    },
    { /* unit 54 (Old: 54) */
        0.0, 0.320020, 30,
        &Sources[690],
        &Weights[690],
    },
    { /* unit 55 (Old: 55) */
        0.0, -0.319920, 30,
        &Sources[720],
        &Weights[720],
    },
    { /* unit 56 (Old: 56) */
        0.0, 0.173390, 30,
        &Sources[750],
        &Weights[750],
    },
    { /* unit 57 (Old: 57) */
        0.0, -0.200190, 30,
        &Sources[780],
        &Weights[780],
    },
    { /* unit 58 (Old: 58) */
        0.0, 0.852090, 30,
        &Sources[810],
        &Weights[810],
    },
    { /* unit 59 (Old: 59) */
        0.0, -0.931400, 30,
        &Sources[840],
        &Weights[840],
    },
    { /* unit 60 (Old: 60) */
        0.0, 0.026460, 30,
        &Sources[870],
        &Weights[870],
    },
    { /* unit 61 (Old: 61) */
        0.0, -0.597160, 30,
        &Sources[900],
        &Weights[900],
    },
    { /* unit 62 (Old: 62) */
        0.0, 0.242910, 30,
        &Sources[930],
        &Weights[930],
    },
    { /* unit 63 (Old: 63) */
        0.0, -0.572260, 30,
        &Sources[960],
        &Weights[960],
    },
    { /* unit 64 (Old: 64) */
        0.0, 0.621600, 30,
        &Sources[990],
        &Weights[990],
    },
    { /* unit 65 (Old: 65) */
        0.0, -0.878960, 30,
        &Sources[1020],
        &Weights[1020],
    },
    { /* unit 66 (Old: 66) */
        0.0, 0.602530, 30,
        &Sources[1050],
        &Weights[1050],
    },
    { /* unit 67 (Old: 67) */
        0.0, -0.215560, 30,
        &Sources[1080],
        &Weights[1080],
    },
    { /* unit 68 (Old: 68) */
        0.0, 0.294040, 30,
        &Sources[1110],
        &Weights[1110],
    },
    { /* unit 69 (Old: 69) */
        0.0, -0.891180, 30,
        &Sources[1140],
        &Weights[1140],
    },
    { /* unit 70 (Old: 70) */
        0.0, -0.007770, 30,
        &Sources[1170],
        &Weights[1170],
    },
    { /* unit 71 (Old: 71) */
        0.0, 0.062830, 30,
        &Sources[1200],
        &Weights[1200],
    },
    { /* unit 72 (Old: 72) */
        0.0, -0.686650, 30,
        &Sources[1230],
        &Weights[1230],
    },
    { /* unit 73 (Old: 73) */
        0.0, -0.108610, 30,
        &Sources[1260],
        &Weights[1260],
    },
    { /* unit 74 (Old: 74) */
        0.0, 0.363860, 30,
        &Sources[1290],
        &Weights[1290],
    },
    { /* unit 75 (Old: 75) */
        0.0, 0.807180, 30,
        &Sources[1320],
        &Weights[1320],
    },
    { /* unit 76 (Old: 76) */
        0.0, -0.361290, 30,
        &Sources[1350],
        &Weights[1350],
    },
    { /* unit 77 (Old: 77) */
        0.0, -0.613030, 30,
        &Sources[1380],
        &Weights[1380],
    },
    { /* unit 78 (Old: 78) */
        0.0, 0.882200, 30,
        &Sources[1410],
        &Weights[1410],
    },
    { /* unit 79 (Old: 79) */
        0.0, 0.164650, 30,
        &Sources[1440],
        &Weights[1440],
    },
    { /* unit 80 (Old: 80) */
        0.0, -0.109500, 30,
        &Sources[1470],
        &Weights[1470],
    },
    { /* unit 81 (Old: 81) */
        0.0, 0.281820, 50,
        &Sources[1500],
        &Weights[1500],
    },
    { /* unit 82 (Old: 82) */
        0.0, 0.266410, 50,
        &Sources[1550],
        &Weights[1550],
    },
    { /* unit 83 (Old: 83) */
        0.0, 0.733200, 50,
        &Sources[1600],
        &Weights[1600],
    },
    { /* unit 84 (Old: 84) */
        0.0, 0.848700, 50,
        &Sources[1650],
        &Weights[1650],
    },
    { /* unit 85 (Old: 85) */
        0.0, 0.706600, 50,
        &Sources[1700],
        &Weights[1700],
    },
    { /* unit 86 (Old: 86) */
        0.0, 0.323950, 50,
        &Sources[1750],
        &Weights[1750],
    },
    { /* unit 87 (Old: 87) */
        0.0, -0.122390, 50,
        &Sources[1800],
        &Weights[1800],
    },
    { /* unit 88 (Old: 88) */
        0.0, -0.472310, 50,
        &Sources[1850],
        &Weights[1850],
    },
    { /* unit 89 (Old: 89) */
        0.0, -0.504260, 50,
        &Sources[1900],
        &Weights[1900],
    },
    { /* unit 90 (Old: 90) */
        0.0, -0.555570, 50,
        &Sources[1950],
        &Weights[1950],
    },
    { /* unit 91 (Old: 91) */
        0.0, -0.174410, 50,
        &Sources[2000],
        &Weights[2000],
    },
    { /* unit 92 (Old: 92) */
        0.0, -0.533010, 50,
        &Sources[2050],
        &Weights[2050],
    },
    { /* unit 93 (Old: 93) */
        0.0, -0.513040, 50,
        &Sources[2100],
        &Weights[2100],
    },
    { /* unit 94 (Old: 94) */
        0.0, -0.641850, 50,
        &Sources[2150],
        &Weights[2150],
    },
    { /* unit 95 (Old: 95) */
        0.0, 0.909700, 50,
        &Sources[2200],
        &Weights[2200],
    },
    { /* unit 96 (Old: 96) */
        0.0, -0.042430, 50,
        &Sources[2250],
        &Weights[2250],
    },
    { /* unit 97 (Old: 97) */
        0.0, 0.725800, 50,
        &Sources[2300],
        &Weights[2300],
    },
    { /* unit 98 (Old: 98) */
        0.0, -0.907460, 50,
        &Sources[2350],
        &Weights[2350],
    },
    { /* unit 99 (Old: 99) */
        0.0, 0.795300, 50,
        &Sources[2400],
        &Weights[2400],
    },
    { /* unit 100 (Old: 100) */
        0.0, 0.883260, 50,
        &Sources[2450],
        &Weights[2450],
    },
    { /* unit 101 (Old: 101) */
        0.0, 0.477760, 20,
        &Sources[2500],
        &Weights[2500],
    }

};



int i(float* in, float* out, int init)
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
