/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#define version "0.97"

#include "PPRullst.h"
#include "PPInput.h"
#include "PPAbblst.h"
#include "PPFnclst.h"
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

FILE* errfile ;

extern char* optarg ;

const char* synopsis =
    "preproc " version "\n"
    "Usage: preproc -r Rules-File <-a Abbreviations-File> | read from stdin, write to stdout\n"
    "Valid options are:\n"
    "  -r filename      - Specifies the Rules-File.\n"
    "  -a filename      - Specifies an optional Abbreviations-File.\n"
    "  -d level         - Level specifies the amount of debugging information (default is 0, maximum is 1).\n"
    "                     The higher the number, the more information is given. The debug info\n"
    "                     is written into a preproc*.log file located in /tmp.\n"
    "  -v               - Gives the version number and exits.\n"
    "  -h               - Prints this information.\n" ;

int main(int argc, char** argv)
{
    PPFunctionlist fl ;
    PPRulelist* rl ;
    PPAbbreviationlist* al ;
    char rname[2048] ;
    char aname[2048] ;
    strcpy(rname, "-") ;
    strcpy(aname, "-") ;
    char* xinput ;
    char* output ;
    int g ;
    int debuglevel = 0 ;
    char pid[32] ;
    sprintf(pid, "%d", getpid()) ;
    char errfilename[512] ;
    strcat(strcat(strcpy(errfilename, "/tmp/preproc."), pid), ".log") ;
    PPInput ip("-", "()&\%") ;
    FILE* abbfile = NULL ;
    al = NULL ;
    char optc ;
    optarg = NULL ;
    while ((optc = getopt(argc, argv, "r:a:d:vh")) != EOF)
    {
        switch (optc)
        {
            case 'r':
                if (optarg != NULL) strcpy(rname, optarg) ;
                break ;
            case 'a':
                if (optarg != NULL) strcpy(aname, optarg) ;
                break ;
            case 'd':
                if (optarg != NULL) debuglevel=std::atoi(optarg) ;
                break ;
            case 'v':
                printf("preproc " version "\n") ;
                return (0) ;
            case 'h':
                printf("%s\n", synopsis) ;
                return (0) ;
        }
    }
    if (strcmp(rname, "-")==0)
    {
        fprintf(stdout, "Usage: preproc -r Rules-File <-a Abbreviations-File> | read from stdin, write to stdout\n") ;
        return (1) ;
    }
    FILE* rlfile = fopen(rname, "r") ;
    if (rlfile == NULL)
    {
        fprintf(stderr, "Cannot open Rules-File %s\n", rname) ;
        return (2) ;
    }
    if (strcmp(aname, "-")!=0)
    {
        abbfile = fopen(aname, "r") ;
        if (abbfile == NULL)
        {
            fprintf(stderr, "Cannot open Abbreviations-File %s\n", aname) ;
            return (2) ;
        }
    }
    char p ;
    char* n ;
    rl = new PPRulelist(rlfile) ;
    fclose(rlfile) ;
    if (debuglevel>0)
    {
        errfile = fopen(errfilename, "w") ;
    }
    if (abbfile != NULL)
    {
        al = new PPAbbreviationlist(abbfile) ;
        fclose(abbfile) ;
    }
    while ((xinput = ip.get_next_token_with_lookahead(g)) != NULL)
    {
        if (strncmp(&xinput[g], "{UsePrepocRules:", 16) == 0)
        {
            n = strchr(&xinput[g], '}') ;
            if (n != NULL)
            {
                p = *n ;
                n[0] = '\0' ;
                rlfile = fopen(&xinput[g+16], "r") ;
                if (rlfile != NULL)
                {
                    delete (rl) ;
                    rl = new PPRulelist(rlfile) ;
                    rl->list(errfile) ;
                    fclose(rlfile) ;
                }
            }
        }
        if (strncmp(&xinput[g], "{UseAbbreviationList:", 21) == 0)
        {
            n = strchr(&xinput[g], '}') ;
            if (n != NULL)
            {
                p = *n ;
                n[0] = '\0' ;
                abbfile = fopen(&xinput[g+21], "r") ;
                if (abbfile != NULL)
                {
                    if (al != NULL)
                        delete (al) ;
                    al = new PPAbbreviationlist(abbfile) ;
                    fclose(abbfile) ;
                }
            }
        }
        if (debuglevel>0)
        {
            fprintf(errfile, "%s", &xinput[g]) ;
            fflush(errfile) ;
        }
        output = rl->apply(xinput, g) ;
        if (debuglevel>0)
        {
            fprintf(errfile, " (%s/", output) ;
            fflush(errfile) ;
        }
        if (al != NULL)
            output = al->apply(output) ;
        if (debuglevel>0)
        {
            fprintf(errfile, "%s/", output) ;
            fflush(errfile) ;
        }
        output = fl.call(output) ;
        if (debuglevel>0)
        {
            fprintf(errfile, "%s/", output) ;
            fflush(errfile) ;
        }
        if (strlen(output) < 1)
        {
            delete (output) ;
            continue ;
        }
        if (debuglevel>0)
        {
            fprintf(errfile, "%s)\n", output) ;
            fflush(errfile) ;
        }
        p = output[strlen(output)-1] ;
        output[strlen(output)-1] = '\0' ;
        fprintf(stdout, "%s", output) ;
        if (strchr(",.;:?!", p) != NULL)
            fprintf(stdout, " ") ;
        fprintf(stdout, "%c ", p) ;
        if (strchr(".:?!", p) != NULL)
            fprintf(stdout, "\n") ;
        delete (output) ;
    }
    if (al != NULL)
        delete (al) ;
    delete (rl) ;
    if (debuglevel>0)
    {
        fclose(errfile) ;
    }
    //unlink(errfilename) ;
    return (0) ;
}
