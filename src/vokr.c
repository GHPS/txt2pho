/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    vokr.c
    --------------------------------------------------------
    generated at Tue Jun 23 14:38:35 1998
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
    -0.741700, 0.981120, 0.015300, -0.260990, -0.500390, 0.648360, -0.928420, 0.424120, -0.201710, -0.217430,
        0.373060, -0.900410, 0.390690, 0.696280, 0.310410, 0.321150, -0.255650, -0.487860, -0.162050, -0.078000,
        0.069950, -0.481950, 0.263180, -0.892740, 0.332610, -0.946590, 1.213040,
        0.369260, 0.972650, -0.013920, 0.947380, -0.726370, 0.784700, -0.095710, 0.356050, -0.782990, 0.003600,
        -0.542590, 0.797360, -0.729850, -0.351080, 0.100940, -1.656570, -0.582640, 0.282830, 0.622940, 0.240040,
        0.426720, -0.549670, -0.316520, -0.131910, -0.631420, 0.304060, -0.707490,
        0.607730, -0.881180, 0.069000, -0.234830, 0.816340, -0.866820, -0.743260, -0.512970, 0.202150, -0.376510,
        -0.807330, 0.124870, 0.749500, 0.030730, 0.565310, -0.572390, -0.068820, 0.937890, -0.844660, 0.973770,
        -0.626210, 0.224090, 0.326870, -0.931470, -0.979380, -0.597730, 0.046730,
        -0.158620, 0.422010, 0.356620, 0.484160, 0.648550, 0.970500, 0.920660, 0.521000, 0.169100, -0.403250,
        0.460580, -0.013820, 0.865940, 0.213870, 0.041010, 0.552560, 0.559890, -0.858540, 0.233760, 0.614560,
        0.577600, -0.349600, 0.896790, -0.566820, 0.895530, 0.112190, 0.689280,
        -0.806920, 0.058000, -0.714670, -0.280410, -0.807020, 0.145200, 0.124620, -0.808170, -0.387090, -0.677470,
        -0.570550, -0.105580, -0.356310, -0.154420, 0.456540, -0.986970, -0.328960, 0.966440, 0.385850, -0.235760,
        0.708050, 0.180050, -0.270180, 0.948620, -0.590840, 0.860380, -0.545260,
        -0.793080, 0.187150, 0.604600, 0.608830, -0.207040, 0.871580, 0.625370, 0.568990, -0.886440, 0.726570,
        0.659830, -0.320450, 0.351960, -0.730160, 0.339380, -0.748140, -0.615850, -0.660580, -0.152590, 0.805540,
        -0.885450, 0.676020, -0.166660, -0.683780, -0.456250, 0.068470, -0.834880,
        -0.692470, -0.126700, -1.008330, 0.204570, -0.422780, 0.487640, -1.239390, -0.984380, 0.756530, -0.963090,
        0.608190, -0.109170, 0.923750, 0.247050, -0.072550, 0.754110, -0.152770, -0.311180, -0.996720, 0.074140,
        0.933840, 0.106920, 0.601670, 0.414550, 0.415910, 0.953120, -0.697000,
        0.826580, -0.472240, 0.879260, 0.699190, -0.953820, -0.533750, -0.815740, -0.641690, 0.498040, 0.487010,
        0.375180, 0.089850, -0.054640, 0.467180, 0.190350, -1.368870, 0.906180, 0.463670, 0.285160, -0.131320,
        0.366990, -0.486340, 0.087150, 0.817710, 0.557240, -0.852070, -1.232500,
        -0.791850, 0.477360, 0.107710, -0.777890, -0.049780, -1.109810, 0.187880, -0.312510, -0.940920, 0.292260,
        -0.212130, 0.627030, 0.569360, 0.325650, 0.043450, 1.218280, -0.358930, 0.829700, -0.159040, 0.368060,
        0.416590, 0.071360, 0.791130, -0.929650, -0.522160, -0.771980, 0.699190,
        -0.412370, -0.675320, -0.147640, -1.087340, 0.065880, 0.279650, 1.064970, -0.198070, 0.904860, -0.185540,
        0.247430, -0.787420, 0.339740, 0.378330, -0.696520, -0.365940, 0.807730, 0.310020, 0.105540, -0.940770,
        -0.236940, -0.774090, 0.151110, -0.582450, 0.872560, 0.748330, -0.017070,
        -0.812190, 0.235040, -0.001930, -0.609030, 0.494070, 0.641780, -0.151240, -0.522630, 0.715500, -0.617350,
        -0.962980, 0.263570, 0.049770, 0.311080, 0.184250, 1.514650, -0.064210, -0.510790, 0.416230, -0.390560,
        -0.541080, -0.767830, 0.600050, 0.258960, -0.991640, -0.478720, 0.802060,
        0.302800, 0.881020, 0.035590, 1.067070, -0.367350, 0.954710, 0.128620, 0.588540, -0.155590, 0.588670,
        -0.437470, -0.344070, 0.089330, 0.429460, -0.745640, -0.427430, -0.632630, 0.264060, 0.583770, -0.926320,
        0.430140, 0.460520, 0.295740, 0.005890, -0.526420, -0.265120, -0.385800,
        0.646980, -0.140160, 1.076000, 0.540530, 0.701470, 0.036730, 0.636460, 0.664810, 0.865410, 0.613810,
        -0.744930, -0.837160, 0.394820, 0.155980, -0.979640, -0.982710, 0.238710, 0.666520, 0.605820, -0.476520,
        -0.077990, -0.505550, 0.563400, 0.062350, -0.067970, 0.790390, 0.417360,
        -0.148050, -0.765330, 0.836990, 0.777500, 0.433740, 0.335210, -0.742440, 0.757050, -0.895420, 0.141090,
        0.790140, -0.709180, 0.112660, 0.157640, -0.393530, 0.677520, 0.748600, 0.462090, -0.372470, 0.733380,
        0.369430, -0.621570, 0.916420, -0.847410, 0.181680, -0.139560, 0.591950,
        -0.319340, -0.559970, 0.919900, 1.553270, 0.653590, 0.482940, -1.579120, 0.315420, -0.376850, -0.677780,
        -1.948550, 1.175640, 0.854120, 0.138040, -0.575170, 0.410110, 0.218470, 0.491640, -1.831640, -0.340680,
        -0.516670, -0.588760, 0.994750, -0.464650, -0.491380, -0.241970, 0.111590,
        0.079600, 0.008530, -0.478840, 0.554100, -0.644790, -0.742480, 0.822320, 0.691500, 0.453500, -0.967970,
        0.221700, -0.449740, -0.710520, 0.421170, -1.007990, 1.133220, 0.843690, -0.992560, -0.542160, 0.367240,
        -0.453840, -0.737420, -0.210680, -0.831540, -0.198220, -0.957780, 0.522630,
        -0.235970, -0.540670, 0.684530, -0.883550, 0.661840, -1.126490, -0.401980, 0.075060, -0.112750, 0.975820,
        -0.021250, 0.263430, -0.457100, -0.087610, -0.333800, -0.278490, 0.450620, 0.723550, 0.301370, -0.040910,
        -0.766030, -0.208440, -0.935630, 0.535310, -0.117880, -0.186230, 0.925400,
        -0.143300, 0.729180, 0.028960, 0.548100, 0.255890, 0.008940, 0.765370, -0.134740, 0.576550, -0.887650,
        -0.055270, 0.108980, 0.052650, -0.685450, 0.166700, 0.336650, -0.848620, -0.347070, 0.861550, -0.542580,
        -0.340000, 0.453680, -0.590900, 0.569620, 0.484000, -0.160510, -1.268640,
        -0.639730, -0.578380, -1.141120, -0.469520, -0.267310, 1.134840, -0.534490, 0.746570, 0.344630, 0.097560,
        0.005250, -0.055000, -0.692550, -0.649800, -0.124810, -0.063690, 0.705940, -0.713010, -0.529650, 0.601950,
        0.886210, -0.041340, -0.675990, 0.397970, 0.276680, -0.006790, 1.075230,
        0.477760, -0.878950, -0.563640, 0.398900, -0.597520, -0.278870, 0.402570, 0.797940, -0.474440, 0.102180,
        -0.041050, -0.442830, -0.883010, 0.724230, -0.456730, 1.558880, -0.178320, -0.400540, 0.809460, -0.911150,
        0.406030, -1.179480, -0.457600, 0.975300, -0.847460, 0.138070, 0.680380,
        -0.650270, 0.917550, -0.889650, -0.618520, -0.870860, 0.074790, 0.766020, 0.352010, -0.112300, -0.748840,
        -1.446410, 0.899570, 0.189230, -0.533630, -0.269250, 0.012910, -0.628060, -0.280440, -0.422600, -0.111750,
        -0.100730, 0.161600, -0.696950, 0.161340, -0.878420, 1.127890, 0.899220,
        -0.951890, -0.839410, 0.737010, -0.563990, 0.313640, -0.921750, 0.830920, 0.175110, 0.666550, 0.198300,
        0.657740, 0.411500, 0.039590, -0.289880, 0.759850, -0.404760, -0.511250, -0.769500, -0.685700, 0.797860,
        -0.755940, 0.238000, 0.956690, -0.547200, -0.027070, 0.784570, 0.724500,
        0.765560, -0.539260, 0.611890, 0.288780, 0.941520, -0.557620, -0.295840, 0.876210, -0.222470, -0.111040,
        -0.907560, -0.158460, 0.325890, 0.768170, 0.851660, 0.143930, 0.755910, -0.372130, -0.442610, 0.990890,
        0.464870, 0.372720, -0.559080, -0.947080, 0.668580, 0.350460, 0.064070,
        -1.098730, 0.277100, 0.629150, -0.337660, -0.952070, 0.574040, -0.013990, 0.807550, 0.134370, -0.435960,
        -0.047380, -1.350870, -0.828420, 0.207820, 0.056060, -0.413780, 0.174090, -0.226000, -0.345540, 0.500090,
        -0.629120, 0.342500, 0.068740, -0.132570, 0.593930, 0.617580, 0.951470,
        -0.338340, -0.299250, 0.339770, 0.008460, 0.826530, 0.725750, 0.525930, 0.457040, -0.685760, -0.515320,
        0.446120, -0.624790, -0.101140, -0.550940, -0.375670, 0.484570, -0.693720, 0.715900, -0.855230, -0.707370,
        -0.601100, -0.730910, -0.096610, 0.531950, -0.876320, -0.222690, -1.028790,
        0.401760, 0.103770, 0.109080, -0.841780, -0.092210, -0.659820, -0.457480, 0.119660, 0.136160, 0.959230,
        0.545290, -0.077790, 0.738870, 0.919930, -0.162320, 0.526540, -0.720400, -0.083150, 0.314760, -0.600330,
        0.379470, -0.223480, -0.375660, 0.903220, -0.222250, -0.343940, -0.480050,
        -0.899600, 0.704440, 0.977750, 0.567900, -0.352630, -0.987150, -0.265610, 0.197370, -0.484100, -0.940350,
        1.255100, 1.462050, -0.178690, -0.994420, -0.151330, -0.800300, 0.803160, -0.182470, -0.503090, 0.080000,
        0.148220, -0.451770, 0.713580, 0.316710, 0.125360, 0.227680, 0.250230,
        0.815580, -0.919130, -0.732380, -0.698620, 0.040710, -0.570240, 0.430450, -0.103620, -0.907610, -0.764770,
        -1.167230, -0.823370, 0.279820, 0.700130, 0.569820, 0.987770, -0.200400, -0.477340, -0.192600, -0.221740,
        -0.357710, -0.113830, 0.249440, 0.089770, 0.135810, -0.037780, 0.336580,
        -0.965020, 0.272280, 1.063730, -0.134900, -0.102760, -1.401420, 0.297060, 0.662250, -0.640190, -0.041000,
        0.671200, -0.349500, 0.256320, 0.072430, -0.020200, -0.109990, -0.243690, -0.068360, 1.053970, -0.465740,
        0.901210, -0.877050, 0.574300, 0.528580, -0.022970, 0.213870, 0.341050,
        -0.441910, -0.829180, 0.788980, 1.454050, -0.175360, 0.133920, -0.411780, 0.152340, 0.562840, 0.948630,
        0.913100, 0.665900, 0.470320, -0.768160, -0.161400, -0.897430, -0.512150, -0.239340, 0.028590, -0.883940,
        -0.714750, -0.742330, -0.784070, 0.403300, -0.119120, -0.864410, -0.434940,
        0.525880, -0.167130, 0.100790, -0.664390, -0.319890, 0.867150, -0.703470, -0.239560, 0.505710, 0.544770,
        -0.734420, 0.981600, -0.235230, 0.550010, -0.106040, 0.117430, 0.483020, -0.316210, -0.495200, -0.614990,
        -0.800470, 0.897970, -0.645940, 0.347590, -0.518220, -0.855550, -0.314970,
        -0.356700, -0.225020, -0.942800, 0.384040, -0.684860, -0.316670, -0.904520, -1.029400, 0.176780, 0.939740,
        -0.965180, -0.258660, -0.517950, 0.363950, -0.364160, 0.059980, 0.653040, 0.031550, -0.474040, 0.502390,
        0.931690, -0.102520, 0.091620, 0.804650, -0.196930, 0.685740, 0.694000,
        -0.809560, 0.062540, 0.469700, 0.327760, -0.223980, 0.123590, 0.882620, 0.625730, -0.902490, 0.346170,
        0.733160, -0.802640, -0.096690, -0.559460, 0.757530, 1.201920, -0.395570, 0.572830, -0.124440, -0.805630,
        0.840820, 0.813550, -0.092310, 0.401040, -0.239170, 0.588320, 0.789790,
        -0.154570, 0.527130, 0.651040, 0.198910, 0.641320, 0.551610, -0.231460, -0.079430, -0.629760, 0.375700,
        0.820320, 0.914960, -0.552300, 0.088820, -0.313370, 0.644320, -0.295970, -0.215130, -0.693910, 0.513360,
        -0.481430, 0.023510, -0.734810, 0.434630, 0.235440, -0.439900, -0.054240,
        -0.213250, -0.336460, 0.492470, 0.894650, -0.602340, 0.447230, 0.303440, 0.207090, -0.768900, -0.857430,
        -0.593570, 0.311060, 0.427040, -0.787090, -0.855470, 0.684470, 0.705500, -0.885070, -0.063870, 0.174060,
        -0.061280, 0.796460, -0.922010, -0.505120, 0.205780, 0.574850, -0.970140,
        0.681580, 0.519030, -0.492710, 0.684410, 0.844790, 0.106220, 0.290280, 0.083240, 0.630020, 0.475120,
        0.005580, -0.190140, -0.653370, 0.833780, -0.595920, 0.368340, 0.975380, -0.842560, -0.690710, -0.907840,
        0.762610, -0.210120, 0.228640, 0.106720, -0.673680, 0.830200, -0.566560,
        0.855660, 0.226790, -0.444860, -0.368300, -0.433040, -0.226160, -0.937520, 0.886220, -0.022000, -0.547110,
        0.792790, 0.744780, 0.898120, 0.983840, -0.910230, -1.711150, 0.336870, 0.748510, 0.901300, 0.557000,
        -0.641490, 1.242460, 1.091720, 0.249070, 0.428970, 0.445900, -0.177340,
        -0.462690, 0.689190, -0.705440, -1.071050, 0.458200, -0.180020, 0.684230, 0.212480, -0.847190, -0.089550,
        0.715430, -0.322720, 0.677700, 0.484840, 0.355230, -1.067370, 0.448780, 0.398260, 1.066750, 0.563320,
        -0.972830, -1.008790, 0.075350, 0.219940, 0.255600, 0.182130, -0.369510,
        -0.808320, -0.615560, 0.579440, -0.619910, 1.003100, -0.153570, 0.162550, 0.140250, 0.470140, 0.965690,
        0.148710, -0.917110, -0.539750, 0.331330, 0.903170, -0.646020, -0.401340, -0.045660, -0.728860, 0.153660,
        -0.552280, -0.509810, 0.140510, 0.711680, 0.725660, -0.831570, -0.882840,
        0.204940, -0.025030, 0.642000, 0.203370, -0.716520, -1.205610, 0.840660, 0.290280, 0.349530, -0.273980,
        -0.296190, -0.761740, -0.349080, 0.372410, 0.755380, 0.479580, -0.403620, 0.704370, -0.022880, 0.362260,
        0.893340, 0.285320, 0.456530, -0.740680, 0.418530, 0.718070, -0.557100,
        -0.936090, -0.390370, -0.777860, 0.591240, -0.233420, -0.430960, 0.959820, 0.627370, -0.598280, 0.531680,
        0.649520, 0.047030, 0.718290, -0.939350, 0.527370, -0.691130, -1.042130, -0.707590, 0.561010, -0.365110,
        0.407870, 0.168930, 0.873070, 0.137830, -0.371400, 0.625640, 0.743980, 0.466680, -0.595840, 0.384650,
        -0.780480, 0.085930, -0.060080, -0.487880, 0.023800, -0.077360, -0.651560, -0.506040, -0.546040, 0.786350,

        -0.861460, -0.338710, -0.128890, 0.208320, 0.389390, -0.819800, 0.565780, 0.455730, -0.508170, -0.719540,
        -0.584690, -0.028310, -0.015020, -0.876190, 1.499540, 0.239430, -0.802890, -0.234780, -0.039650, -1.164710,
        -1.113200, 0.552960, 0.051540, -1.044630, -0.367780, -0.239230, 0.650760, 0.814770, 0.269220, 0.778520,
        -0.274140, 0.507400, -0.956230, -0.471910, -0.576070, 0.320000, 1.366590, -0.416880, 0.494730, -1.167650,

        0.715730, 0.204180, -0.316230, -0.676810, 0.511400, 0.795960, 0.289240, 1.136120, 0.102690, 0.227610,
        0.655980, 0.488950, 0.933740, -0.589210, 1.302910, 0.745060, -0.251910, -0.698220, -0.794610, 0.566110,
        -0.413720, 0.022560, 0.003550, -0.063850, -0.890810, -0.013260, -0.765610, -0.187810, 0.570480, 0.773400,
        0.293660, -0.455660, -0.595380, -1.000510, 0.585330, -0.024190, -0.724270, -0.165720, -0.767840, 0.786480,

        -0.058890, 0.361860, -0.038940, -0.138860, 0.772570, 0.670560, -0.394360, 0.302950, 0.183920, 0.238490,
        0.224350, -0.498300, 0.273170, -0.900800, -0.785060, 0.415230, -0.059660, 0.942160, 0.587870, 0.847160,
        -0.406590, 0.443880, 0.676040, -0.785020, -0.974640, 0.704340, -0.423190, -0.503550, 0.596430, -0.362780,
        -0.800620, 0.613800, 0.487710, 0.692420, 0.882730, 0.570390, 0.799170, -0.549840, 0.375240, -0.940910,

        0.756660, 0.202780, -0.987840, 0.381710, 0.514260, 0.009670, 0.763380, -0.013680, -0.112280, -0.470960,
        -0.251700, -0.458050, -0.669500, 0.579680, -0.287040, -0.175540, -0.731600, -0.137650, 0.614930, 0.617410,
        -0.117130, 0.867600, 0.056510, 0.881030, -0.768050, 0.644120, -0.573920, 0.626270, 0.618900, -0.045840,
        -0.871080, 0.209750, 0.630390, -0.529200, 0.761200, 0.453150, 0.466330, -0.287910, -0.231970, -0.609150,

        -0.447330, -1.496980, -0.161840, -0.812310, -0.627630, -0.991000, 1.185690, -0.601700, 0.888420, -0.051270,
        0.767730, -0.829930, -1.208920, -0.019240, -0.956420, -0.043970, -0.944760, -0.156690, 0.719340, 0.983390,
        0.977580, -0.072500, 0.253490, -1.162820, 0.378830, 0.967530, -1.042000, 0.634840, -1.163570, -1.044050,
        0.912500, 0.617020, 1.150980, 0.665780, -0.269050, 0.600310, -0.434220, -0.360820, -0.542680, -0.689720,

        0.860710, 0.216900, 0.404070, -0.082730, 0.728780, 0.671190, 0.235170, 0.357780, 0.906630, -1.006230,
        0.830850, 0.807940, 0.105390, 0.629190, -0.890010, -0.117240, 0.458200, -0.513400, -0.860570, 0.809600,
        0.771690, 0.335380, -0.854490, -0.099370, 0.290220, 0.727870, -0.821540, 0.106380, -1.030180, -0.566090,
        -0.057900, -0.440370, -0.403410, -0.340460, 0.480760, 0.531740, 0.274730, -1.073700, -0.613110, -0.224670,

        0.635540, 0.204030, 0.368400, -0.361580, 0.251340, -0.293530, -0.754050, -0.707250, 0.178510, -0.777420,
        0.280230, -0.495920, -0.583920, -0.408070, -0.988740, -0.703220, -0.653860, -0.876220, -0.241080, 0.178710,
        -0.061780, -0.628170, 0.336790, -0.757990, 0.173930, -0.834820, 0.346100, 0.663420, -0.074740, 0.583530,
        0.694420, -0.033900, -0.285430, -0.413220, -0.930400, -0.251680, 0.614250, 0.609880, -0.652710, -0.116890,

        -0.470620, 0.443890, 0.775140, 0.083720, -0.892600, -0.789760, 0.977270, 0.004010, -0.456290, -0.915440,
        -0.767960, 0.890240, 0.749760, 0.832050, -1.121610, 0.242500, -0.430580, 0.834070, 0.783740, 0.051750,
        -0.589140, 0.003650, 0.849240, 0.001070, -0.754360, 0.780110, 0.218490, 0.640350, 0.903500, 0.943210,
        0.123250, -0.022410, -0.342570, 0.444240, -0.660700, -0.165320, 0.642910, 0.080700, 0.505340, -0.100120,

        -0.843060, -0.008750, -0.431720, 1.057020, -0.879770, 0.439420, -0.872330, -0.032180, 0.374640, -1.116490,
        -0.384850, 0.292680, -0.501570, -0.536980, -0.878440, 0.369560, -0.479750, 0.661610, -0.876500, 0.802490,
        -0.876950, 0.124850, -0.738720, -1.012880, 0.629560, -0.738910, 0.511370, -0.902440, -0.394230, 0.484030,
        0.842120, 0.754320, 0.019510, 0.113070, -0.468960, -0.779540, -0.701100, -0.099930, -0.566540, 0.259310,

        0.674710, 0.329050, 0.957070, 0.599560, -0.908930, -0.168720, 0.912030, 0.062350, 0.300050, 0.071720,
        0.450350, 0.221290, 0.856380, 0.510000, 0.983570, 0.705150, 0.209850, 0.688910, 0.422290, 0.714470,
        0.020400, 0.821350, 0.231930, -0.708620, 0.532440, 0.589830, -0.643150, 0.360240, 0.223660, -0.023260,
        0.626450, -0.398600, 0.503070, 0.324520, -0.714840, -0.361210, 0.273430, -0.737090, -0.546310, -0.161880,

        0.327950, 1.207030, -0.201000, -0.381040, 0.511180, -0.253290, 0.516420, -0.536310, -1.004720, -0.019510,
        0.014060, -0.234290, -0.812180, -0.682900, -1.032740, 0.598750, 0.423860, 0.573780, 0.630590, 0.817420,
        -0.420070, -0.090910, 0.108310, 0.486210, -0.190990, 0.250580, 1.476370, -0.190730, -0.531130, 0.442710,
        -0.475920, -0.686870, 0.482030, -0.014180, -0.723700, -0.216330, -1.053160, -1.141590, 0.882900, -0.406800,

        -0.994870, 1.163510, 0.231180, -0.179350, 0.594540, -1.216170, 0.433280, 0.024800, 0.560000, -0.805990,
        0.530400, -0.614480, -1.096640, -0.679070, -0.933930, 0.180730, 1.175520, 0.255660, -0.200760, -0.321260,
        0.838890, 0.745140, -0.001860, -0.489450, -1.116000, 0.395520, 0.713690, 0.420390, 0.662410, 0.404320,
        0.116040, 0.016770, -0.785360, 0.099070, -0.343190, -0.738000, -0.949620, -0.256740, 0.180320, 1.026280,

        -0.850980, 1.003340, 0.296600, -0.824440, 0.004840, -0.580030, -0.062850, -0.146300, -0.810630, 0.816950,
        -0.358180, 0.801220, 0.661570, 0.859060, 0.471930, -0.695450, -0.616340, 0.794460, 0.512950, -0.038630,
        -0.689340, 0.934270, -0.618630, 0.021570, 0.859970, -0.332640, -0.563410, -0.221420, 0.953630, 0.978210,
        -0.951530, 0.642100, -0.940400, -0.375170, -0.217730, 0.455520, 0.025840, -0.045090, 0.675900, 0.578600,

        0.811500, 0.317000, 0.631050, 0.281800, 0.510120, -0.200520, 0.619080, -0.478920, -0.130730, 0.330560,
        -0.118790, 0.896210, -1.010130, -0.897510, -0.262780, 0.193110, 0.340960, -0.452330, -0.290960, -0.852710,
        -0.837550, -0.127730, -0.663950, -0.711090, 0.713280, -0.224740, 0.311220, -0.997390, -0.483910, -0.162680,
        -0.251360, -0.434780, -0.331990, -0.222890, -0.616380, -0.257810, -0.733250, -0.018910, -0.722930, -0.243940,

        -0.408410, 0.647580, 0.152890, 0.953050, -0.390740, 0.682360, -0.574630, -0.224780, -0.285550, 0.411220,
        -0.071730, 0.544460, 0.761090, -0.280130, -0.339930, 0.277140, 0.955840, 0.415390, 0.213290, 0.874390,
        -0.944110, 0.723900, 0.047250, -0.321090, 0.414770, 0.013650, 0.101110, 0.222570, -0.736260, 0.841170,
        -0.679760, 0.351520, 0.666200, -0.624120, 0.978100, -0.823600, -0.479180, 0.475070, -0.305790, 0.922380,

        1.303160, -1.103270, 0.734140, 0.538280, -0.671050, -0.835080, 0.171170, -1.550700, 0.504880, 0.213820,
        1.258400, -0.865520, -0.044090, 0.082990, 0.018230, 0.387850, 0.243030, -0.868680, 1.255530, 1.376900,
        1.270160, -0.438290, 0.455330, 0.938490, 0.697390, -0.079510, -0.629120, 0.857420, 0.078070, -0.428920,
        -0.929460, 0.794450, -0.343160, 0.372200, 0.118020, 0.289490, -1.140230, -0.995220, -0.597780, 0.205180,

        -0.323120, 0.572100, 0.035800, 0.241680, -0.083110, -0.053850, 0.948770, -0.469450, 1.080180, 0.446070,
        -0.316790, 0.513470, -0.428860, -0.379170, 1.693050, 0.649250, 0.979530, -0.957260, 0.370060, -0.631030,
        -0.390310, -0.556820, -0.325360, -0.804320, -0.073830, -0.562150, 0.263880, -0.590410, -1.121280, -1.062260,
        1.412340, 0.256900, -0.652130, 0.395350, 0.827910, -0.885220, -0.165550, 0.502830, -0.502050, -0.647440,

        -0.153790, 0.137880, 0.989800, 0.822040, 0.122140, -0.832830, 0.035610, -0.336110, 0.196130, 0.181270,
        -0.050780, -1.052210, -0.904550, -0.177110, 0.975960, -0.447590, -0.335150, 0.945880, 0.316480, -0.192090,
        -0.721680, 0.759740, 0.803360, -0.375650, 0.867510, 0.355000, -0.203710, -0.789560, -0.087270, -0.121580,
        0.037270, 0.229480, 0.649290, 0.372870, 0.581650, -0.176900, -1.040260, 0.455970, 0.341870, 0.483270,

        0.691940, -0.537750, -0.771730, 0.193110, -0.995530, 0.271820, -1.230180, -0.926020, -0.401990, 0.185750,
        -0.589420, 0.375730, 0.478510, -0.247620, -0.436450, -0.846190, 1.171880, -0.049000, 0.085430, 0.713450,
        -0.437120, 0.046250, -0.715670, 0.365960, -0.400830, -0.265070, -1.056280, 0.619080, 1.000920, -0.089870,
        -0.839000, -0.955370, 0.574640, -0.326940, -0.524610, -0.487950, -0.781780, 0.544470, 0.705180, 0.570980,

        -0.404130, 1.464240, 0.785210, 0.490400, -0.221350, 2.708800, -0.740210, -0.216180, -0.783010, -1.074170,
        0.242370, -1.217670, -1.776110, -0.279950, 0.497860, 0.539480, -2.155290, 1.192540, 0.390210, 1.582510,


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
        0.0, -0.200980, 27,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 29 (Old: 29) */
        0.0, 0.001260, 27,
        &Sources[27],
        &Weights[27],
    },
    { /* unit 30 (Old: 30) */
        0.0, -0.777970, 27,
        &Sources[54],
        &Weights[54],
    },
    { /* unit 31 (Old: 31) */
        0.0, 0.552800, 27,
        &Sources[81],
        &Weights[81],
    },
    { /* unit 32 (Old: 32) */
        0.0, -0.751730, 27,
        &Sources[108],
        &Weights[108],
    },
    { /* unit 33 (Old: 33) */
        0.0, 0.531470, 27,
        &Sources[135],
        &Weights[135],
    },
    { /* unit 34 (Old: 34) */
        0.0, 0.658360, 27,
        &Sources[162],
        &Weights[162],
    },
    { /* unit 35 (Old: 35) */
        0.0, -0.287630, 27,
        &Sources[189],
        &Weights[189],
    },
    { /* unit 36 (Old: 36) */
        0.0, 0.020990, 27,
        &Sources[216],
        &Weights[216],
    },
    { /* unit 37 (Old: 37) */
        0.0, -0.308900, 27,
        &Sources[243],
        &Weights[243],
    },
    { /* unit 38 (Old: 38) */
        0.0, -0.707740, 27,
        &Sources[270],
        &Weights[270],
    },
    { /* unit 39 (Old: 39) */
        0.0, -0.771820, 27,
        &Sources[297],
        &Weights[297],
    },
    { /* unit 40 (Old: 40) */
        0.0, -0.914240, 27,
        &Sources[324],
        &Weights[324],
    },
    { /* unit 41 (Old: 41) */
        0.0, 0.869450, 27,
        &Sources[351],
        &Weights[351],
    },
    { /* unit 42 (Old: 42) */
        0.0, 0.011770, 27,
        &Sources[378],
        &Weights[378],
    },
    { /* unit 43 (Old: 43) */
        0.0, -0.971390, 27,
        &Sources[405],
        &Weights[405],
    },
    { /* unit 44 (Old: 44) */
        0.0, 0.063710, 27,
        &Sources[432],
        &Weights[432],
    },
    { /* unit 45 (Old: 45) */
        0.0, -1.354000, 27,
        &Sources[459],
        &Weights[459],
    },
    { /* unit 46 (Old: 46) */
        0.0, -0.723540, 27,
        &Sources[486],
        &Weights[486],
    },
    { /* unit 47 (Old: 47) */
        0.0, -0.654310, 27,
        &Sources[513],
        &Weights[513],
    },
    { /* unit 48 (Old: 48) */
        0.0, -0.301590, 27,
        &Sources[540],
        &Weights[540],
    },
    { /* unit 49 (Old: 49) */
        0.0, -0.153620, 27,
        &Sources[567],
        &Weights[567],
    },
    { /* unit 50 (Old: 50) */
        0.0, -0.089340, 27,
        &Sources[594],
        &Weights[594],
    },
    { /* unit 51 (Old: 51) */
        0.0, 0.217310, 27,
        &Sources[621],
        &Weights[621],
    },
    { /* unit 52 (Old: 52) */
        0.0, 0.094180, 27,
        &Sources[648],
        &Weights[648],
    },
    { /* unit 53 (Old: 53) */
        0.0, -0.985130, 27,
        &Sources[675],
        &Weights[675],
    },
    { /* unit 54 (Old: 54) */
        0.0, -0.650880, 27,
        &Sources[702],
        &Weights[702],
    },
    { /* unit 55 (Old: 55) */
        0.0, 0.527030, 27,
        &Sources[729],
        &Weights[729],
    },
    { /* unit 56 (Old: 56) */
        0.0, -0.374290, 27,
        &Sources[756],
        &Weights[756],
    },
    { /* unit 57 (Old: 57) */
        0.0, -0.766140, 27,
        &Sources[783],
        &Weights[783],
    },
    { /* unit 58 (Old: 58) */
        0.0, 0.707090, 27,
        &Sources[810],
        &Weights[810],
    },
    { /* unit 59 (Old: 59) */
        0.0, 0.938030, 27,
        &Sources[837],
        &Weights[837],
    },
    { /* unit 60 (Old: 60) */
        0.0, -0.282840, 27,
        &Sources[864],
        &Weights[864],
    },
    { /* unit 61 (Old: 61) */
        0.0, 0.392920, 27,
        &Sources[891],
        &Weights[891],
    },
    { /* unit 62 (Old: 62) */
        0.0, 0.387500, 27,
        &Sources[918],
        &Weights[918],
    },
    { /* unit 63 (Old: 63) */
        0.0, -1.024170, 27,
        &Sources[945],
        &Weights[945],
    },
    { /* unit 64 (Old: 64) */
        0.0, -0.912810, 27,
        &Sources[972],
        &Weights[972],
    },
    { /* unit 65 (Old: 65) */
        0.0, -0.735400, 27,
        &Sources[999],
        &Weights[999],
    },
    { /* unit 66 (Old: 66) */
        0.0, -0.429340, 27,
        &Sources[1026],
        &Weights[1026],
    },
    { /* unit 67 (Old: 67) */
        0.0, -0.298840, 27,
        &Sources[1053],
        &Weights[1053],
    },
    { /* unit 68 (Old: 68) */
        0.0, -0.941680, 40,
        &Sources[1080],
        &Weights[1080],
    },
    { /* unit 69 (Old: 69) */
        0.0, 0.285890, 40,
        &Sources[1120],
        &Weights[1120],
    },
    { /* unit 70 (Old: 70) */
        0.0, -0.756080, 40,
        &Sources[1160],
        &Weights[1160],
    },
    { /* unit 71 (Old: 71) */
        0.0, 0.147420, 40,
        &Sources[1200],
        &Weights[1200],
    },
    { /* unit 72 (Old: 72) */
        0.0, -0.112260, 40,
        &Sources[1240],
        &Weights[1240],
    },
    { /* unit 73 (Old: 73) */
        0.0, -0.851430, 40,
        &Sources[1280],
        &Weights[1280],
    },
    { /* unit 74 (Old: 74) */
        0.0, 0.581260, 40,
        &Sources[1320],
        &Weights[1320],
    },
    { /* unit 75 (Old: 75) */
        0.0, -0.875310, 40,
        &Sources[1360],
        &Weights[1360],
    },
    { /* unit 76 (Old: 76) */
        0.0, -0.854720, 40,
        &Sources[1400],
        &Weights[1400],
    },
    { /* unit 77 (Old: 77) */
        0.0, -0.504020, 40,
        &Sources[1440],
        &Weights[1440],
    },
    { /* unit 78 (Old: 78) */
        0.0, 0.651910, 40,
        &Sources[1480],
        &Weights[1480],
    },
    { /* unit 79 (Old: 79) */
        0.0, 0.550610, 40,
        &Sources[1520],
        &Weights[1520],
    },
    { /* unit 80 (Old: 80) */
        0.0, -0.162870, 40,
        &Sources[1560],
        &Weights[1560],
    },
    { /* unit 81 (Old: 81) */
        0.0, 0.770710, 40,
        &Sources[1600],
        &Weights[1600],
    },
    { /* unit 82 (Old: 82) */
        0.0, -0.977970, 40,
        &Sources[1640],
        &Weights[1640],
    },
    { /* unit 83 (Old: 83) */
        0.0, 0.257960, 40,
        &Sources[1680],
        &Weights[1680],
    },
    { /* unit 84 (Old: 84) */
        0.0, -0.022530, 40,
        &Sources[1720],
        &Weights[1720],
    },
    { /* unit 85 (Old: 85) */
        0.0, -0.646490, 40,
        &Sources[1760],
        &Weights[1760],
    },
    { /* unit 86 (Old: 86) */
        0.0, 0.663080, 40,
        &Sources[1800],
        &Weights[1800],
    },
    { /* unit 87 (Old: 87) */
        0.0, -0.138630, 40,
        &Sources[1840],
        &Weights[1840],
    },
    { /* unit 88 (Old: 88) */
        0.0, 0.146600, 20,
        &Sources[1880],
        &Weights[1880],
    }

};



int vokr(float* in, float* out, int init)
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
