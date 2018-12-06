/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include<stdio.h>
#include <string.h>
#include "sdb.h"
extern FILE* errfile;
extern int debuglevel ;

float sdb2_wagon_comp(sdb2_struct &st)
{
    float result;
    if (debuglevel > 1)
    {
        fprintf(errfile, "Is KONS_ART = 3? ");
    }
    if (strcmp(st.KONS_ART, "3") == 0)
    {
        if (debuglevel > 1)
        {
            fprintf(errfile, "Yes");
        }
        if (debuglevel > 1)
        {
            fprintf(errfile, "Is SH_SL = 0? ");
        }
        if (strcmp(st.SH_SL, "0") == 0)
        {
            if (debuglevel > 1)
            {
                fprintf(errfile, "Yes");
            }
            if (debuglevel > 1)
            {
                fprintf(errfile, "Is PHR_POS = -2? ");
            }
            if (strcmp(st.PHR_POS, "-2") == 0)
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Yes");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is PLDISVH < 1.500000? ");
                }
                if (st.PLDISVH < 1.500000)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is ACAT < 21.900000? ");
                    }
                    if (st.ACAT < 21.900000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        result = 70.084702 ;
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        result = 77.239998 ;
                    }
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "No");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is ACAT < 12.000000? ");
                    }
                    if (st.ACAT < 12.000000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is ACAT < 5.500000? ");
                        }
                        if (st.ACAT < 5.500000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is SONR < 3.500000? ");
                            }
                            if (st.SONR < 3.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 31.500000 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 26.840000 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 34.250000 ;
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        result = 42.587002 ;
                    }
                }
            }
            else
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "No");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is SONR < 3.400000? ");
                }
                if (st.SONR < 3.400000)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is ACAT < 12.000000? ");
                    }
                    if (st.ACAT < 12.000000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is ACAT < 2.200000? ");
                        }
                        if (st.ACAT < 2.200000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            result = 27.475599 ;
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 31.037500 ;
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PHR_POS = 0? ");
                        }
                        if (strcmp(st.PHR_POS, "0") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            result = 47.868900 ;
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 52.529400 ;
                        }
                    }
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "No");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is ACAT < 6.200000? ");
                    }
                    if (st.ACAT < 6.200000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PLDISVH < 3.000000? ");
                        }
                        if (st.PLDISVH < 3.000000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 4.200000? ");
                            }
                            if (st.ACAT < 4.200000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FOSO = 0? ");
                                }
                                if (strcmp(st.FOSO, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 23.275400 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 25.310301 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 28.047600 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 19.180000 ;
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PLIDS < 2.600000? ");
                        }
                        if (st.PLIDS < 2.600000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 11.800000? ");
                            }
                            if (st.ACAT < 11.800000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 28.791201 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PLDISVH < 3.400000? ");
                                }
                                if (st.PLDISVH < 3.400000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 19.600000? ");
                                    }
                                    if (st.ACAT < 19.600000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 36.660999 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 41.790298 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is LANGKURZ = 2? ");
                                    }
                                    if (strcmp(st.LANGKURZ, "2") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 36.000000 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 28.782101 ;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLDISVH < 1.400000? ");
                            }
                            if (st.PLDISVH < 1.400000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is LANGKURZ = 2? ");
                                }
                                if (strcmp(st.LANGKURZ, "2") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 34.343300 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 16.200001? ");
                                    }
                                    if (st.ACAT < 16.200001)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 10.600000? ");
                                        }
                                        if (st.ACAT < 10.600000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 27.863600 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is PHR_POS = 0? ");
                                            }
                                            if (strcmp(st.PHR_POS, "0") == 0)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 22.647100 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                result = 25.921600 ;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is PHR_POS = 0? ");
                                        }
                                        if (strcmp(st.PHR_POS, "0") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 30.654301 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 26.372900 ;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 19.000000? ");
                                }
                                if (st.ACAT < 19.000000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 23.712601 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 19.740700 ;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (debuglevel > 1)
            {
                fprintf(errfile, "No");
            }
            if (debuglevel > 1)
            {
                fprintf(errfile, "Is LANGKURZ = 4? ");
            }
            if (strcmp(st.LANGKURZ, "4") == 0)
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Yes");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is PHR_POS = -2? ");
                }
                if (strcmp(st.PHR_POS, "-2") == 0)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Yes");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Yes");
                    }
                    result = 20.078899 ;
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is FOSO = 0? ");
                    }
                    if (strcmp(st.FOSO, "0") == 0)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PHR_POS = 0? ");
                        }
                        if (strcmp(st.PHR_POS, "0") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            result = 16.767700 ;
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 18.276300 ;
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        result = 14.067400 ;
                    }
                }
            }
            else
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "No");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is SONR < 2.700000? ");
                }
                if (st.SONR < 2.700000)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Yes");
                    }
                    result = 25.013500 ;
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is ACAT < 12.400000? ");
                    }
                    if (st.ACAT < 12.400000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PHR_POS = 2? ");
                        }
                        if (strcmp(st.PHR_POS, "2") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 6.500000? ");
                            }
                            if (st.ACAT < 6.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 19.454500 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 21.533300 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is FOSO = 0? ");
                            }
                            if (strcmp(st.FOSO, "0") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PHR_POS = 1? ");
                                }
                                if (strcmp(st.PHR_POS, "1") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 17.120001 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is LANGKURZ = 2? ");
                                    }
                                    if (strcmp(st.LANGKURZ, "2") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 18.909700 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 7.200000? ");
                                        }
                                        if (st.ACAT < 7.200000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 18.175900 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 16.872999 ;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 20.289200 ;
                            }
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is LANGKURZ = 3? ");
                        }
                        if (strcmp(st.LANGKURZ, "3") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is SONR < 3.600000? ");
                            }
                            if (st.SONR < 3.600000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 17.018900 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FOSO = 0? ");
                                }
                                if (strcmp(st.FOSO, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 20.250000 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 18.138901 ;
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PHR_POS = 0? ");
                            }
                            if (strcmp(st.PHR_POS, "0") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 20.557899 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is SONR < 3.300000? ");
                                }
                                if (st.SONR < 3.300000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 21.703100 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 25.828600 ;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    else
    {
        if (debuglevel > 1)
        {
            fprintf(errfile, "No");
        }
        if (debuglevel > 1)
        {
            fprintf(errfile, "Is KONS_ART = 4? ");
        }
        if (strcmp(st.KONS_ART, "4") == 0)
        {
            if (debuglevel > 1)
            {
                fprintf(errfile, "Yes");
            }
            if (debuglevel > 1)
            {
                fprintf(errfile, "Is ACAT < 9.300000? ");
            }
            if (st.ACAT < 9.300000)
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is SH_SL = 0? ");
                }
                if (strcmp(st.SH_SL, "0") == 0)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Yes");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is PHR_POS = -2? ");
                    }
                    if (strcmp(st.PHR_POS, "-2") == 0)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is LANGKURZ = 4? ");
                        }
                        if (strcmp(st.LANGKURZ, "4") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            result = 60.851898 ;
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 46.228298 ;
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is LANGKURZ = 3? ");
                        }
                        if (strcmp(st.LANGKURZ, "3") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLDISVH < 1.500000? ");
                            }
                            if (st.PLDISVH < 1.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 48.164200 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 4.500000? ");
                                }
                                if (st.ACAT < 4.500000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is SONR < 3.500000? ");
                                    }
                                    if (st.SONR < 3.500000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 24.263201 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 28.674999 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is SONR < 4.000000? ");
                                    }
                                    if (st.SONR < 4.000000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is SONR < 3.000000? ");
                                        }
                                        if (st.SONR < 3.000000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 32.012798 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 40.555599 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 29.011801 ;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLDISVH < 3.000000? ");
                            }
                            if (st.PLDISVH < 3.000000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 5.400000? ");
                                }
                                if (st.ACAT < 5.400000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is PLIDS < 1.400000? ");
                                    }
                                    if (st.PLIDS < 1.400000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is FOSO = 0? ");
                                        }
                                        if (strcmp(st.FOSO, "0") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 43.743099 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 52.112701 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 41.333302 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 40.080601 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 3.600000? ");
                                }
                                if (st.ACAT < 3.600000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 33.153801 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 40.500000 ;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "No");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is PHR_POS = 2? ");
                    }
                    if (strcmp(st.PHR_POS, "2") == 0)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        result = 54.819302 ;
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PLDISVH < 3.500000? ");
                        }
                        if (st.PLDISVH < 3.500000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is LANGKURZ = 2? ");
                            }
                            if (strcmp(st.LANGKURZ, "2") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 4.500000? ");
                                }
                                if (st.ACAT < 4.500000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 30.132500 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 27.554199 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FOSO = 0? ");
                                }
                                if (strcmp(st.FOSO, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 37.759300 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 28.802299 ;
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is LANGKURZ = 3? ");
                            }
                            if (strcmp(st.LANGKURZ, "3") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 33.279999 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 2.700000? ");
                                }
                                if (st.ACAT < 2.700000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 21.921600 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 4.200000? ");
                                    }
                                    if (st.ACAT < 4.200000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 26.235300 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 28.936501 ;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "No");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is ACAT < 18.400000? ");
                }
                if (st.ACAT < 18.400000)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is PLDISVH < 1.800000? ");
                    }
                    if (st.PLDISVH < 1.800000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        result = 60.723202 ;
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is PHR_POS = -2? ");
                        }
                        if (strcmp(st.PHR_POS, "-2") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLIDS < 2.200000? ");
                            }
                            if (st.PLIDS < 2.200000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 48.924702 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 58.422199 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is FOSO = 0? ");
                            }
                            if (strcmp(st.FOSO, "0") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PHR_POS = 2? ");
                                }
                                if (strcmp(st.PHR_POS, "2") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is LANGKURZ = 2? ");
                                    }
                                    if (strcmp(st.LANGKURZ, "2") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 45.309898 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 35.738701 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is LANGKURZ = 1? ");
                                    }
                                    if (strcmp(st.LANGKURZ, "1") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 14.000000? ");
                                        }
                                        if (st.ACAT < 14.000000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 38.260899 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 46.171398 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 10.800000? ");
                                        }
                                        if (st.ACAT < 10.800000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 43.012798 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is SONR < 3.500000? ");
                                            }
                                            if (st.SONR < 3.500000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 50.245499 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is ACAT < 15.200000? ");
                                                }
                                                if (st.ACAT < 15.200000)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Is PLIDS < 2.500000? ");
                                                    }
                                                    if (st.PLIDS < 2.500000)
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "Yes");
                                                        }
                                                        result = 47.088200 ;
                                                    }
                                                    else
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "No");
                                                        }
                                                        result = 51.000000 ;
                                                    }
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "No");
                                                    }
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "No");
                                                    }
                                                    result = 44.492500 ;
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FACCE = 0? ");
                                }
                                if (strcmp(st.FACCE, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 43.819401 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is SONR < 4.100000? ");
                                    }
                                    if (st.SONR < 4.100000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 38.827999 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 13.200000? ");
                                        }
                                        if (st.ACAT < 13.200000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 30.939400 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 35.101700 ;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "No");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is FOSO = 1? ");
                    }
                    if (strcmp(st.FOSO, "1") == 0)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is SONR < 5.500000? ");
                        }
                        if (st.SONR < 5.500000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 22.600000? ");
                            }
                            if (st.ACAT < 22.600000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 46.512501 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 51.115398 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 42.325802 ;
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is LANGKURZ = 2? ");
                        }
                        if (strcmp(st.LANGKURZ, "2") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 20.100000? ");
                            }
                            if (st.ACAT < 20.100000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 56.631599 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 25.500000? ");
                                }
                                if (st.ACAT < 25.500000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 67.148903 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 57.065601 ;
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLDISVH < 3.400000? ");
                            }
                            if (st.PLDISVH < 3.400000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is SONR < 4.500000? ");
                                }
                                if (st.SONR < 4.500000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is PLDISVH < 2.000000? ");
                                    }
                                    if (st.PLDISVH < 2.000000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 65.057999 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 56.742901 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is FACCE = 0? ");
                                    }
                                    if (strcmp(st.FACCE, "0") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 56.258598 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 51.470600 ;
                                    }
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FACCE = 0? ");
                                }
                                if (strcmp(st.FACCE, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 54.750000 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 47.036701 ;
                                }
                            }
                        }
                    }
                }
            }
        }
        else
        {
            if (debuglevel > 1)
            {
                fprintf(errfile, "No");
            }
            if (debuglevel > 1)
            {
                fprintf(errfile, "Is PHR_POS = -2? ");
            }
            if (strcmp(st.PHR_POS, "-2") == 0)
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Yes");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is PLDISVH < 1.700000? ");
                }
                if (st.PLDISVH < 1.700000)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is PLIDS < 4.500000? ");
                    }
                    if (st.PLIDS < 4.500000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is ACAT < 6.000000? ");
                        }
                        if (st.ACAT < 6.000000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 2.500000? ");
                            }
                            if (st.ACAT < 2.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 132.240997 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 149.850006 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 15.600000? ");
                            }
                            if (st.ACAT < 15.600000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is LANGKURZ = 3? ");
                                }
                                if (strcmp(st.LANGKURZ, "3") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 152.542007 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 168.311005 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 175.352005 ;
                            }
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        result = 124.842003 ;
                    }
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "No");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is SH_SL = 0? ");
                    }
                    if (strcmp(st.SH_SL, "0") == 0)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Yes");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is SONR < 3.200000? ");
                        }
                        if (st.SONR < 3.200000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            result = 113.649002 ;
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 16.000000? ");
                            }
                            if (st.ACAT < 16.000000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 74.448700 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 97.156898 ;
                            }
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is FOSO = 1? ");
                        }
                        if (strcmp(st.FOSO, "1") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLIDS < 1.500000? ");
                            }
                            if (st.PLIDS < 1.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 79.500000 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 91.970596 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 18.400000? ");
                            }
                            if (st.ACAT < 18.400000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 6.100000? ");
                                }
                                if (st.ACAT < 6.100000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 61.172401 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 68.465103 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 77.413803 ;
                            }
                        }
                    }
                }
            }
            else
            {
                if (debuglevel > 1)
                {
                    fprintf(errfile, "No");
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Is SH_SL = 0? ");
                }
                if (strcmp(st.SH_SL, "0") == 0)
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Yes");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is ACAT < 18.000000? ");
                    }
                    if (st.ACAT < 18.000000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is SONR < 4.100000? ");
                        }
                        if (st.SONR < 4.100000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is KONS_ART = 1? ");
                            }
                            if (strcmp(st.KONS_ART, "1") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PLIDS < 1.300000? ");
                                }
                                if (st.PLIDS < 1.300000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 8.500000? ");
                                    }
                                    if (st.ACAT < 8.500000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is PLDISVH < 2.200000? ");
                                        }
                                        if (st.PLDISVH < 2.200000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 88.568398 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is ACAT < 3.200000? ");
                                            }
                                            if (st.ACAT < 3.200000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 68.788498 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                result = 80.038498 ;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 14.600000? ");
                                        }
                                        if (st.ACAT < 14.600000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 90.213097 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 102.345001 ;
                                        }
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is PLDISVH < 1.200000? ");
                                    }
                                    if (st.PLDISVH < 1.200000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is PHR_POS = -1? ");
                                        }
                                        if (strcmp(st.PHR_POS, "-1") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 79.050003 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is FACCE = 0? ");
                                            }
                                            if (strcmp(st.FACCE, "0") == 0)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 66.018501 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                result = 71.057198 ;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 8.500000? ");
                                        }
                                        if (st.ACAT < 8.500000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 57.320400 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 64.173302 ;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 13.600000? ");
                                }
                                if (st.ACAT < 13.600000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 49.442902 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 57.065601 ;
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is ACAT < 8.500000? ");
                            }
                            if (st.ACAT < 8.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FACCE = 0? ");
                                }
                                if (strcmp(st.FACCE, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 35.279400 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 52.988400 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FOSO = 0? ");
                                }
                                if (strcmp(st.FOSO, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 66.736397 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 54.875000 ;
                                }
                            }
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is KONS_ART = 1? ");
                        }
                        if (strcmp(st.KONS_ART, "1") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLIDS < 2.200000? ");
                            }
                            if (st.PLIDS < 2.200000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is SONR < 4.500000? ");
                                }
                                if (st.SONR < 4.500000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 21.600000? ");
                                    }
                                    if (st.ACAT < 21.600000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 95.569000 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 105.977997 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 86.132103 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PLDISVH < 1.400000? ");
                                }
                                if (st.PLDISVH < 1.400000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 22.799999? ");
                                    }
                                    if (st.ACAT < 22.799999)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 80.402397 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 94.097801 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 22.799999? ");
                                    }
                                    if (st.ACAT < 22.799999)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 62.226398 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 68.606598 ;
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            result = 67.833298 ;
                        }
                    }
                }
                else
                {
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "No");
                    }
                    if (debuglevel > 1)
                    {
                        fprintf(errfile, "Is PLDISVH < 1.700000? ");
                    }
                    if (st.PLDISVH < 1.700000)
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is LANGKURZ = 1? ");
                        }
                        if (strcmp(st.LANGKURZ, "1") == 0)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Yes");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PHR_POS = 0? ");
                            }
                            if (strcmp(st.PHR_POS, "0") == 0)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Yes");
                                }
                                result = 50.151798 ;
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                result = 54.028999 ;
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLIDS < 3.500000? ");
                            }
                            if (st.PLIDS < 3.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 24.000000? ");
                                }
                                if (st.ACAT < 24.000000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is FACCE = 0? ");
                                    }
                                    if (strcmp(st.FACCE, "0") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 18.400000? ");
                                        }
                                        if (st.ACAT < 18.400000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 57.205399 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 64.269203 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is LANGKURZ = 4? ");
                                        }
                                        if (strcmp(st.LANGKURZ, "4") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is ACAT < 0.900000? ");
                                            }
                                            if (st.ACAT < 0.900000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 61.102901 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is PLIDS < 2.100000? ");
                                                }
                                                if (st.PLIDS < 2.100000)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    result = 83.381798 ;
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Is ACAT < 3.400000? ");
                                                    }
                                                    if (st.ACAT < 3.400000)
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "Yes");
                                                        }
                                                        result = 71.205902 ;
                                                    }
                                                    else
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "No");
                                                        }
                                                        result = 79.987801 ;
                                                    }
                                                }
                                            }
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is PLIDS < 2.000000? ");
                                            }
                                            if (st.PLIDS < 2.000000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 62.151199 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is ACAT < 11.500000? ");
                                                }
                                                if (st.ACAT < 11.500000)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    result = 71.887604 ;
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "No");
                                                    }
                                                    result = 65.944397 ;
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 78.325302 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PHR_POS = -1? ");
                                }
                                if (strcmp(st.PHR_POS, "-1") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 76.411797 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 9.000000? ");
                                    }
                                    if (st.ACAT < 9.000000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 2.400000? ");
                                        }
                                        if (st.ACAT < 2.400000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 55.666698 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 69.035400 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is FACCE = 0? ");
                                        }
                                        if (strcmp(st.FACCE, "0") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 62.776299 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 51.264702 ;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "No");
                        }
                        if (debuglevel > 1)
                        {
                            fprintf(errfile, "Is ACAT < 15.500000? ");
                        }
                        if (st.ACAT < 15.500000)
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is SONR < 2.600000? ");
                            }
                            if (st.SONR < 2.600000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is FOSO = 0? ");
                                }
                                if (strcmp(st.FOSO, "0") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 10.500000? ");
                                    }
                                    if (st.ACAT < 10.500000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 9.000000? ");
                                        }
                                        if (st.ACAT < 9.000000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is ACAT < 6.400000? ");
                                            }
                                            if (st.ACAT < 6.400000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is KONS_ART = 1? ");
                                                }
                                                if (strcmp(st.KONS_ART, "1") == 0)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    result = 56.860802 ;
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Is ACAT < 4.200000? ");
                                                    }
                                                    if (st.ACAT < 4.200000)
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "Yes");
                                                        }
                                                        result = 52.007702 ;
                                                    }
                                                    else
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "No");
                                                        }
                                                        result = 56.453098 ;
                                                    }
                                                }
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                result = 50.653801 ;
                                            }
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 56.968300 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 62.629398 ;
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 81.271400 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is LANGKURZ = 3? ");
                                }
                                if (strcmp(st.LANGKURZ, "3") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is PLDISVH < 3.200000? ");
                                    }
                                    if (st.PLDISVH < 3.200000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 4.500000? ");
                                        }
                                        if (st.ACAT < 4.500000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 41.658798 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is ACAT < 10.000000? ");
                                            }
                                            if (st.ACAT < 10.000000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is PHR_POS = 0? ");
                                                }
                                                if (strcmp(st.PHR_POS, "0") == 0)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    result = 48.444401 ;
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "No");
                                                    }
                                                    result = 43.788502 ;
                                                }
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is KONS_ART = 1? ");
                                                }
                                                if (strcmp(st.KONS_ART, "1") == 0)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    result = 47.546501 ;
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Is SONR < 4.200000? ");
                                                    }
                                                    if (st.SONR < 4.200000)
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "Yes");
                                                        }
                                                        result = 55.468800 ;
                                                    }
                                                    else
                                                    {
                                                        if (debuglevel > 1)
                                                        {
                                                            fprintf(errfile, "No");
                                                        }
                                                        result = 51.551701 ;
                                                    }
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is FOSO = 0? ");
                                        }
                                        if (strcmp(st.FOSO, "0") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 58.099998 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 51.773300 ;
                                        }
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is KONS_ART = 1? ");
                                    }
                                    if (strcmp(st.KONS_ART, "1") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        result = 50.531200 ;
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is ACAT < 7.500000? ");
                                        }
                                        if (st.ACAT < 7.500000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is ACAT < 3.500000? ");
                                            }
                                            if (st.ACAT < 3.500000)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 55.400002 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                result = 51.164398 ;
                                            }
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 59.979801 ;
                                        }
                                    }
                                }
                            }
                        }
                        else
                        {
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "No");
                            }
                            if (debuglevel > 1)
                            {
                                fprintf(errfile, "Is PLIDS < 1.500000? ");
                            }
                            if (st.PLIDS < 1.500000)
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is ACAT < 26.500000? ");
                                }
                                if (st.ACAT < 26.500000)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is LANGKURZ = 3? ");
                                    }
                                    if (strcmp(st.LANGKURZ, "3") == 0)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Yes");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is PLDISVH < 2.500000? ");
                                        }
                                        if (st.PLDISVH < 2.500000)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 67.681801 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is FOSO = 0? ");
                                            }
                                            if (strcmp(st.FOSO, "0") == 0)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 57.183300 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Is KONS_ART = 1? ");
                                                }
                                                if (strcmp(st.KONS_ART, "1") == 0)
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "Yes");
                                                    }
                                                    result = 62.444401 ;
                                                }
                                                else
                                                {
                                                    if (debuglevel > 1)
                                                    {
                                                        fprintf(errfile, "No");
                                                    }
                                                    result = 68.075500 ;
                                                }
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is PHR_POS = 0? ");
                                        }
                                        if (strcmp(st.PHR_POS, "0") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 72.357903 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Is FACCE = 0? ");
                                            }
                                            if (strcmp(st.FACCE, "0") == 0)
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "Yes");
                                                }
                                                result = 71.935501 ;
                                            }
                                            else
                                            {
                                                if (debuglevel > 1)
                                                {
                                                    fprintf(errfile, "No");
                                                }
                                                result = 63.881599 ;
                                            }
                                        }
                                    }
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "No");
                                    }
                                    result = 75.416702 ;
                                }
                            }
                            else
                            {
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "No");
                                }
                                if (debuglevel > 1)
                                {
                                    fprintf(errfile, "Is PHR_POS = -1? ");
                                }
                                if (strcmp(st.PHR_POS, "-1") == 0)
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Yes");
                                    }
                                    result = 63.470600 ;
                                }
                                else
                                {
                                    if (debuglevel > 1)
                                    {
                                        fprintf(errfile, "Is ACAT < 23.500000? ");
                                    }
                                    if (st.ACAT < 23.500000)
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "Is FOSO = 0? ");
                                        }
                                        if (strcmp(st.FOSO, "0") == 0)
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "Yes");
                                            }
                                            result = 49.700001 ;
                                        }
                                        else
                                        {
                                            if (debuglevel > 1)
                                            {
                                                fprintf(errfile, "No");
                                            }
                                            result = 54.817101 ;
                                        }
                                    }
                                    else
                                    {
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        if (debuglevel > 1)
                                        {
                                            fprintf(errfile, "No");
                                        }
                                        result = 58.596298 ;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return (result) ;
}
