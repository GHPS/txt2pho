/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

/*********************************************************
    kons7.c
    --------------------------------------------------------
    generated at Sun Sep  6 14:23:38 1998
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
static UnitType Units[14];
/* Sources definition section */
static pUnit Sources[] =
{
    Units + 1, Units + 7,
    Units + 2, Units + 3,
    Units + 5,
    Units + 7,
    Units + 8, Units + 9, Units + 10, Units + 11,
    Units + 12,

};

/* Weigths definition section */
static float Weights[] =
{
    1.880900, -1.204710,
    -0.642470, -7.597120,
    6.494190,
    0.370430,
    -3.084830, -5.957740, 3.983360, 2.057690,
    -1.638540,

};

/* unit definition section (see also UnitType) */
static UnitType Units[14] =
{
    { 0.0, 0.0, 0, NULL, NULL },
    { /* unit 1 (Old: 1) */
        0.0, -0.622740, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 2 (Old: 2) */
        0.0, -0.760870, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 3 (Old: 3) */
        0.0, 0.997740, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 4 (Old: 4) */
        0.0, 0.785800, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 5 (Old: 5) */
        0.0, 0.453500, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 6 (Old: 6) */
        0.0, -0.967970, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 7 (Old: 7) */
        0.0, 0.277750, 0,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 8 (Old: 8) */
        0.0, 0.656220, 2,
        &Sources[0],
        &Weights[0],
    },
    { /* unit 9 (Old: 9) */
        0.0, 4.993680, 2,
        &Sources[2],
        &Weights[2],
    },
    { /* unit 10 (Old: 10) */
        0.0, 1.253340, 1,
        &Sources[4],
        &Weights[4],
    },
    { /* unit 11 (Old: 11) */
        0.0, 0.795300, 1,
        &Sources[5],
        &Weights[5],
    },
    { /* unit 12 (Old: 12) */
        0.0, 1.865020, 4,
        &Sources[6],
        &Weights[6],
    },
    { /* unit 13 (Old: 13) */
        0.0, -0.542680, 1,
        &Sources[10],
        &Weights[10],
    }

};



int kons7(float* in, float* out, int init)
{
    int member, source;
    float sum;
    enum {OK, Error, Not_Valid};
    pUnit unit;
    /* layer definition section (names & member units) */
    static pUnit Input[5] = {Units + 1, Units + 2, Units + 3, Units + 5, Units + 7}; /* members */
    static pUnit Special1[2] = {Units + 4, Units + 6}; /* members */
    static pUnit Hidden1[1] = {Units + 8}; /* members */
    static pUnit Hidden2[1] = {Units + 9}; /* members */
    static pUnit Hidden3[1] = {Units + 10}; /* members */
    static pUnit Hidden4[1] = {Units + 11}; /* members */
    static pUnit Hidden5[1] = {Units + 12}; /* members */
    static pUnit Output1[1] = {Units + 13}; /* members */
    static int Output[1] = {13};
    for (member = 0; member < 5; member++)
    {
        Input[member]->act = in[member];
    }
    for (member = 0; member < 1; member++)
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
    for (member = 0; member < 1; member++)
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
        unit = Hidden3[member];
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
        unit = Hidden4[member];
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
        unit = Hidden5[member];
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
    for (member = 0; member < 2; member++)
    {
        unit = Special1[member];
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
