/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "tsr.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

extern FILE* errfile ;

TSR::TSR(const char* tsrfilename, const char* path)
{
    parameters=NULL ;
    coeffnr = 0 ;
    nodenr = 0 ;
    splitcoeffs = NULL ;
    splitvals = NULL ;
    sons = NULL ;
    char buffer[512] ;
    char s[128] ;
    FILE* tsrfile;
    int i, j, k ;
    float r ;
    strcat(strcpy(buffer, path), tsrfilename) ;
    tsrfile=fopen(buffer, "r") ;
    if (tsrfile == NULL)
    {
        fprintf(errfile, "Cannot Open %s\n", buffer) ;
        return ;
    }
    fgets(buffer, 511, tsrfile) ;
    nodenr = atoi(buffer) ;
    parameters = new float*[nodenr] ;
    sons = new int* [nodenr] ;
    splitcoeffs = new int[nodenr] ;
    splitvals = new float[nodenr] ;
    fgets(buffer, 511, tsrfile) ;
    coeffnr = atoi(buffer) ;
    for (i=0 ; i < nodenr ; i++)
    {
        sons[i] = new int[2] ;
        parameters[i] = new float[coeffnr + 1] ;
    }
    fgets(buffer, 511, tsrfile) ;
    fgets(buffer, 511, tsrfile) ;
    if (strstr(buffer, "Nodes:") == NULL)
    {
        fprintf(errfile, "TSR: Keyword 'Nodes:' missed\n") ;
    }
    for (i=0 ; i < nodenr ; i++)
    {
        fgets(buffer, 511, tsrfile) ;
        sscanf(buffer, "%d %d %f", &j, &k, &r) ;
        if (j != i+1)
        {
            fprintf(errfile, "TSR: Node number mismatch %d %d\n", j, i+1) ;
        }
        splitcoeffs[i] = k ;
        splitvals[i] = r ;
        sons[i][0] = 2*(i+1)-1 ;
        sons[i][1] = 2*(i+1) ;
    }
    fgets(buffer, 511, tsrfile) ;
    fgets(buffer, 511, tsrfile) ;
    if (strstr(buffer, "Regression:") == NULL)
    {
        fprintf(errfile, "TSR: Keyword 'Regression:' missed\n") ;
    }
    for (i=0 ; i < nodenr ; i++)
    {
        for (j=0 ; j < coeffnr+1 ; j++)
        {
            fgets(buffer, 511, tsrfile) ;
            sscanf(buffer, "%d %s %f", &k, s, &r) ;
            parameters[i][j] = r ;
        }
        fgets(buffer, 511, tsrfile) ;
    }
    fclose(tsrfile) ;
}

TSR::~TSR()
{
    int i ;
    if (parameters != NULL)
    {
        for (i=0 ; i < nodenr ; i++)
        {
            delete[](parameters [i]) ;
            delete[](sons[i]) ;
        }
        delete[](parameters) ;
        delete[](sons) ;
        delete[](splitcoeffs) ;
        delete[](splitvals) ;
    }
}

int TSR::get_coeffnr()
{
    return (coeffnr) ;
}

float TSR::compute(float* invals, int actnode)
{
    float sum ;
    int i ;
    if (splitcoeffs[actnode] == 0)
    {
        sum = parameters[actnode][0] ;
        for (i=0 ; i < coeffnr ; i++)
            sum += invals[i]*parameters[actnode][i+1] ;
        return (sum) ;
    }
    return (compute(invals, sons[actnode][invals[splitcoeffs[actnode]-1]<=splitvals[actnode]?0:1])) ;
}




