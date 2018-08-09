/*********************************************************
  vokal7.c
  --------------------------------------------------------
  generated at Sun Sep  6 13:29:25 1998
  by snns2c ( Bernward Kett 1995 ) 
*********************************************************/

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
  static UnitType Units[27];
  /* Sources definition section */
  static pUnit Sources[] =  {
Units + 6, 
Units + 6, 
Units + 1, Units + 2, Units + 6, 
Units + 3, Units + 4, Units + 5, Units + 6, Units + 7, 
Units + 2, Units + 3, Units + 4, Units + 7, 
Units + 1, Units + 3, Units + 4, Units + 5, Units + 7, 
Units + 1, Units + 2, Units + 5, Units + 7, 
Units + 2, Units + 3, Units + 6, Units + 7, 
Units + 2, Units + 3, Units + 4, Units + 6, Units + 7, 
Units + 3, Units + 5, 
Units + 4, Units + 5, Units + 6, 
Units + 2, Units + 4, Units + 5, Units + 7, 
Units + 1, Units + 3, Units + 6, 
Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, 
Units + 2, Units + 3, Units + 7, 
Units + 8, Units + 9, Units + 12, Units + 13, Units + 14, Units + 16, Units + 17, Units + 18, Units + 19, Units + 20, 
Units + 21, 
Units + 8, Units + 9, Units + 10, Units + 11, Units + 13, Units + 14, Units + 15, Units + 16, Units + 17, Units + 18, 
Units + 19, Units + 21, Units + 22, 
Units + 8, Units + 9, Units + 10, Units + 12, Units + 15, Units + 16, Units + 17, Units + 18, Units + 20, 
Units + 23, Units + 24, Units + 25, 

  };

  /* Weigths definition section */
  static float Weights[] =  {
-3.795060, 
4.659390, 
-0.154410, 1.586420, -1.813190, 
-0.517940, 1.180260, 0.437420, 3.021090, 1.111620, 
4.231740, -1.221330, 0.345280, 0.493680, 
0.858640, -1.827400, -0.860820, 3.417210, -1.375440, 
-0.293370, -0.962830, 1.008290, 0.290690, 
-5.388260, 1.451810, -3.869300, 0.383570, 
-0.779880, -0.334740, -2.106580, -3.294190, 1.061150, 
-3.264530, 5.134450, 
-2.718630, -3.835870, 1.445080, 
1.801060, -3.560660, 2.561930, -2.342670, 
1.637990, -1.005410, -1.538620, 
-1.213450, 0.947260, -0.714750, 1.921000, 1.346450, 
-2.452800, 0.620500, -1.289450, 
-1.044550, -1.091760, 1.577930, 0.881350, 0.154200, 0.362190, 0.940570, 2.779460, 0.913310, -1.415720, 
-2.006960, 
-2.541530, 3.143020, -1.996780, 1.625150, 1.828990, 0.231100, -4.128040, -2.481060, 1.703540, 3.246510, 
3.183880, -1.381520, -1.435080, 
-1.705540, 2.357170, 0.634900, -1.469130, 0.849480, -2.150430, -2.303450, -1.780170, 1.114570, 
-1.305970, -2.517170, 2.518160, 

  };

  /* unit definition section (see also UnitType) */
  static UnitType Units[27] = 
  {
    { 0.0, 0.0, 0, NULL , NULL },
    { /* unit 1 (Old: 1) */
      0.0, 0.761800, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 2 (Old: 2) */
      0.0, 0.552220, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 3 (Old: 3) */
      0.0, -0.894510, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 4 (Old: 4) */
      0.0, -0.478100, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 5 (Old: 5) */
      0.0, -0.642710, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 6 (Old: 6) */
      0.0, -0.652260, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 7 (Old: 7) */
      0.0, 0.498040, 0,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 8 (Old: 8) */
      0.0, -0.382520, 1,
       &Sources[0] , 
       &Weights[0] , 
      },
    { /* unit 9 (Old: 9) */
      0.0, -0.265510, 1,
       &Sources[1] , 
       &Weights[1] , 
      },
    { /* unit 10 (Old: 10) */
      0.0, -0.828680, 3,
       &Sources[2] , 
       &Weights[2] , 
      },
    { /* unit 11 (Old: 11) */
      0.0, -0.320820, 5,
       &Sources[5] , 
       &Weights[5] , 
      },
    { /* unit 12 (Old: 12) */
      0.0, 0.305540, 4,
       &Sources[10] , 
       &Weights[10] , 
      },
    { /* unit 13 (Old: 13) */
      0.0, -0.873980, 5,
       &Sources[14] , 
       &Weights[14] , 
      },
    { /* unit 14 (Old: 14) */
      0.0, -1.303200, 4,
       &Sources[19] , 
       &Weights[19] , 
      },
    { /* unit 15 (Old: 15) */
      0.0, -0.536580, 4,
       &Sources[23] , 
       &Weights[23] , 
      },
    { /* unit 16 (Old: 16) */
      0.0, 0.522770, 5,
       &Sources[27] , 
       &Weights[27] , 
      },
    { /* unit 17 (Old: 17) */
      0.0, -0.472610, 2,
       &Sources[32] , 
       &Weights[32] , 
      },
    { /* unit 18 (Old: 18) */
      0.0, 0.776550, 3,
       &Sources[34] , 
       &Weights[34] , 
      },
    { /* unit 19 (Old: 19) */
      0.0, -1.466060, 4,
       &Sources[37] , 
       &Weights[37] , 
      },
    { /* unit 20 (Old: 20) */
      0.0, -0.662470, 3,
       &Sources[41] , 
       &Weights[41] , 
      },
    { /* unit 21 (Old: 21) */
      0.0, 0.536270, 5,
       &Sources[44] , 
       &Weights[44] , 
      },
    { /* unit 22 (Old: 22) */
      0.0, -0.335450, 3,
       &Sources[49] , 
       &Weights[49] , 
      },
    { /* unit 23 (Old: 23) */
      0.0, -1.136450, 11,
       &Sources[52] , 
       &Weights[52] , 
      },
    { /* unit 24 (Old: 24) */
      0.0, -0.261710, 13,
       &Sources[63] , 
       &Weights[63] , 
      },
    { /* unit 25 (Old: 25) */
      0.0, -0.503790, 9,
       &Sources[76] , 
       &Weights[76] , 
      },
    { /* unit 26 (Old: 26) */
      0.0, 0.386110, 3,
       &Sources[85] , 
       &Weights[85] , 
      }

  };



int vokal7(float *in, float *out, int init)
{
  int member, source;
  float sum;
  enum{OK, Error, Not_Valid};
  pUnit unit;


  /* layer definition section (names & member units) */

  static pUnit Input[7] = {Units + 1, Units + 2, Units + 3, Units + 4, Units + 5, Units + 6, Units + 7}; /* members */

  static pUnit Hidden1[2] = {Units + 8, Units + 9}; /* members */

  static pUnit Hidden2[1] = {Units + 10}; /* members */

  static pUnit Hidden3[1] = {Units + 11}; /* members */

  static pUnit Hidden4[1] = {Units + 12}; /* members */

  static pUnit Hidden5[1] = {Units + 13}; /* members */

  static pUnit Hidden6[1] = {Units + 14}; /* members */

  static pUnit Hidden7[1] = {Units + 15}; /* members */

  static pUnit Hidden8[1] = {Units + 16}; /* members */

  static pUnit Hidden9[1] = {Units + 17}; /* members */

  static pUnit Hidden10[1] = {Units + 18}; /* members */

  static pUnit Hidden11[1] = {Units + 19}; /* members */

  static pUnit Hidden12[1] = {Units + 20}; /* members */

  static pUnit Hidden13[1] = {Units + 21}; /* members */

  static pUnit Hidden14[1] = {Units + 22}; /* members */

  static pUnit Hidden15[1] = {Units + 23}; /* members */

  static pUnit Hidden16[1] = {Units + 24}; /* members */

  static pUnit Hidden17[1] = {Units + 25}; /* members */

  static pUnit Output1[1] = {Units + 26}; /* members */

  static int Output[1] = {26};

  for(member = 0; member < 7; member++) {
    Input[member]->act = in[member];
  }

  for (member = 0; member < 2; member++) {
    unit = Hidden1[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden2[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden3[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden4[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden5[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden6[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden7[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden8[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden9[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden10[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden11[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden12[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden13[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden14[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden15[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden16[member];
    sum = 0.0;
    for (source = 0; source < unit->NoOfSources; source++) {
      sum += unit->sources[source]->act
             * unit->weights[source];
    }
    unit->act = Act_Logistic(sum, unit->Bias);
  };

  for (member = 0; member < 1; member++) {
    unit = Hidden17[member];
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
