/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    j.h
    --------------------------------------------------------
    generated at Tue Jun 23 14:56:23 1998
    by snns2c ( Bernward Kett 1995 )
*********************************************************/

extern "C" int j(float* in, float* out, int init);

static struct
{
    int NoOfInput;    /* Number of Input Units  */
    int NoOfOutput;   /* Number of Output Units */
    int(* propFunc)(float*, float*, int);
} jREC = {27, 1, j};
