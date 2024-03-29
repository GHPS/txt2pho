/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#define version "0.97"

#include "synthese.h"
#include <unistd.h>
#ifndef SUN
    #include <getopt.h>
#endif


extern int optind, opterr, optopt ;

extern char* optarg ;

const char* synopsis =
    "txt2pho " version "\n"
    "Usage: \"txt2pho -pfmdvioh\"\n"
    "Txt2pho reads text from stdin (if no filename is given with the -i option)\n"
    "and writes MBROLA input to stdout (if no filename is given with the -o option)\n"
    "Txt2pho reads its global settings from a file \"hadifix.cfg\" located in\n"
    "a directory specified by the -p option. If the file \"~/.config/txt2phorc\" is found,\n"
    "its values overwrite those settings, and command line options overwrite the rest.\n"
    "Valid options are:\n"
    "  -p path      - This option specifies the path to the txt2pho files. Default\n"
    "                 value is /usr/local/share/txt2pho/data/. The path must end with a separator '/'.\n"
    "  -m | -f      - This variable specifies the voice: m is male, f ist female\n"
    "  -d level     - Level specifies the amount of debugging information (default is 0, maximum is 11).\n"
    "                 The higher the number, the more information is given. The debug info\n"
    "                 is written into files located in /tmp.\n"
    "  -v           - Gives the version number and exits.\n"
    "  -i name      - Specifies an input file name or an input text, depending on the mode.\n"
    "  -o name      - Specifies an output file.\n"
    "  -h           - Prints this information.\n" ;



int main (int argc, char** argv)
{
    int modus = 8 ;
    char path[2048] ;
    char inname[2048] ;
    char outname[2048] ;
    strcpy(path, "") ;
    strcpy(inname, "-") ;
    strcpy(outname, "-") ;
    int debuglevel = 0 ;
    char pid[64] ;
    const char* voices[2] = {"male", "female"} ;
    int voicenr = 255 ;
    int piping = 1;
    sprintf(pid, "%d", getpid()) ;
    setvbuf(stdin, NULL, _IOLBF, BUFSIZ);
    setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
    char optc ;
    optarg = NULL ;
    while ((optc = getopt(argc, argv, "p:mfd:vi:o:h")) != EOF)
    {
        switch (optc)
        {
            case 'p':
                if (optarg != NULL) strcpy(path, optarg) ;
                break;
            case 'm':
                voicenr = 0 ;
                break ;
            case 'f':
                voicenr = 1 ;
                break ;
            case 'd':
                if (optarg != NULL) debuglevel = atoi(optarg) ;
                break ;
            case 'i':
                if (optarg != NULL) strcpy(inname, optarg) ;
                piping = 0 ;
                break ;
            case 'o':
                if (optarg != NULL) strcpy(outname, optarg) ;
                break ;
            case 'v':
                printf("txt2pho " version "\n") ;
                return (0) ;
            case 'h':
                printf("%s\n", synopsis) ;
                return (0) ;
        }
    }
    Synthese* s ;
    s = new Synthese(pid, path, (char*)"/tmp/", debuglevel, piping) ;
    if (voicenr!=255)
        s->change_voice(NULL, voices[voicenr]) ;
    s->talk(outname, modus, inname) ;
    delete (s) ;
    return (0) ;
}
