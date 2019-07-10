/*

    This file is part of the project txt2pho.
    The project is released under the AGPL 3.0 license.
    For details concerning the resulting rights and
    conditions of this license see file License.txt.

*/

#include "synthese.h"


#include "ascii.h"

//#define DEBUG3 0

#define ABSOLUTELY_NO_FILES

#define LOGFILE

int instcnt = 0 ;
FILE* errfile = NULL ;
char fnamtmp[256] ;
char jnamtmp[256] ;
ofstream debugstr ;
int debuglevel = 0 ;
int language = 0 ;


#ifdef UNIX
    #include <fcntl.h>
    #include <unistd.h>
#endif




extern long bt4(long) ;


extern int sampa2ipa (string &out, char* in) ;

#ifndef NGIMMICKS
    extern int make_dialect(TLexem &lexem, char* dialect) ;
#endif

extern int PPmain(char*, char*, char*, char*) ;

extern int change_rhythm(string &out, char* r) ;

Synthese::Synthese(char* __hWnd, char* path, char* logprefix, int db, int pip)
{
    language = 0 ;
    skip_it = 1;
    alles_gelesen = 0 ;
    talknow = 0 ;
    char temp[256] ;
    int rcfile_present=1 ;
    bwl = 0 ;
    if (getenv("HOME")==NULL)
        strcpy(temp, ".txt2phorc") ;
    else
        strcat(strcpy(temp, getenv("HOME")), "/.config/txt2phorc") ;
    FILE* rcfile=fopen(temp, "r") ;
    if (rcfile == NULL)
    {
        strcpy(temp, "/etc/txt2pho") ;
        rcfile=fopen(temp, "r") ;
        if (rcfile == NULL)
        {
            rcenv = NULL ;
            rcfile_present = 0 ;
        }
    }
    if (rcfile_present != 0)
    {
        fclose(rcfile) ;
        errfile = stderr ;
        rcenv = new Environment("", temp) ;
        if (strlen(path) == 0 && strlen(rcenv->get_value("DATAPATH")) > 0)
            path=rcenv->get_value("DATAPATH") ;
        if (db == -1 && strlen(rcenv->get_value("DEBUGLEVEL")) > 0)
            db = atoi(rcenv->get_value("DEBUGLEVEL")) ;
        if (strlen(logprefix) == 0 && strlen (rcenv->get_value("TEMPPATH")) > 0)
            logprefix = rcenv->get_value("TEMPPATH") ;
        errfile = NULL ;
    }
    if (strlen(logprefix) == 0)
        logprefix = (char*) "/tmp/" ;
    strcat(strcpy(pid, logprefix), "hadifix.") ;
    strcat(pid, __hWnd) ;
    piping = pip ;
    nopreproc = pip ;
    debuglevel = db ;
    if (strlen(path) == 0)
    {
        path = (char*) "/usr/local/share/txt2pho/data/" ;
    }
    strcpy(szProgramPath, path) ;
    #ifdef DEBUG3
    f0fil=fopen(strcat(strcpy(temp, pid), ".hadi.f0"), "w") ;
    #endif
    errfile = fopen(strcat(strcpy(temp, pid), ".error.log"), "w") ;
    if (errfile == NULL)
        printf("ERROR CAN'T OPEN LOGFILE\n") ;
    if (debuglevel > 2)
    {
        strcat(strcpy(temp, pid), ".debug.log") ;
        debugstr.open(temp) ;
    }
    fprintf(errfile, "Debuglevel %d\n", debuglevel) ;
    env = new Environment(szProgramPath, "hadifix.cfg") ;
    inventname = strdup(env->get_value("INVENTORY")) ;
    inventpath = strdup(env->get_value("INVPATH")) ;
    def_use_net = atoi(env->get_value("USENET")) ;
    use_wagonprom = atoi(env->get_value("PROMCOMP")) ;
    if (rcfile_present)
    {
        if (strlen(rcenv->get_value("INVENTORY")) > 0)
            inventname = strdup(rcenv->get_value("INVENTORY")) ;
        if (strlen(rcenv->get_value("INVPATH")) > 0)
            inventpath = strdup(rcenv->get_value("INVPATH")) ;
        if (strlen(rcenv->get_value("USENET")) > 0)
            def_use_net = atoi(rcenv->get_value("USENET")) ;
        if (strlen(rcenv->get_value("PROMCOMP")) > 0)
            use_wagonprom = atoi(rcenv->get_value("PROMCOMP")) ;
    }
    fprintf(errfile, "INVENTORY %s\n", inventname) ;
    fprintf(errfile, "INVPASTH %s\n", inventpath) ;
    defaultspeechrate = 1.0 ;
    if (strlen(env->get_value("SPEECHRATE")) > 1)
        defaultspeechrate = atof(env->get_value("SPEECHRATE")) ;
    reduction_level = atoi(env->get_value("REDUCTION")) ;
    strcpy(treename, inventname) ;
    if (strlen(env->get_value("NEWTREE")) > 1)
        strcpy(treename, env->get_value("NEWTREE")) ;
    if (rcfile_present)
    {
        if (strlen(rcenv->get_value("NEWTREE")) > 0)
            strcpy(treename, rcenv->get_value("NEWTREE")) ;
        if (strlen(rcenv->get_value("REDUCTION")) > 0)
            reduction_level = atoi(rcenv->get_value("REDUCTION")) ;
        if (strlen(rcenv->get_value("SPEECHRATE")) > 0)
            defaultspeechrate = atof(rcenv->get_value("SPEECHRATE")) ;
    }
    interpunction = 0 ;
    dares = 16 ;
    mulaw = 1 ;
    d = new Duration_Model(inventname, inventpath, bwl) ;
    i = new Intonation_Model(inventname, inventpath) ;
    a = new Intensity_Control(inventname, inventpath) ;
    if (debuglevel > 0)
    {
        fprintf(errfile, "BEFORE TREE\n") ;
        fflush(errfile) ;
    }
    n = new NNProsody(inventname, inventpath) ;
    #ifdef NOTREE
    b = NULL ;
    if (debuglevel > 0)
    {
        fprintf(errfile, "NOTREE defined\n") ;
        fflush(errfile) ;
    }
    #else
    if (debuglevel == 0)
        b = new Baum(treename, inventpath, 0, errfile) ;
    else
        b = new Baum(treename, inventpath, 1, errfile) ;
    if (debuglevel > 0)
    {
        fprintf(errfile, "TREE READ\n") ;
        fflush(errfile) ;
    }
    #endif
    d->set_speech_rate(defaultspeechrate) ;
    fprintf(errfile, "Program Path %s\n", szProgramPath) ;
    #ifdef UNIX
    strcpy(lexemfilnam, pid) ;
    #else
    strcpy(lexemfilnam, "") ;
    #endif
    strcat(lexemfilnam, ".hadivv.tmp") ;
    #ifdef Windows
    GetTempFileName(temppath, "hvv", 0, lexemfilnam) ;
    #endif
    #ifdef UNIX
    strcpy(ppfilnam, pid) ;
    #else
    strcpy(ppfilnam, "") ;
    #endif
    strcat(ppfilnam, "hadipp.tmp") ;
    #ifdef Windows
    GetTempFileName(temppath, "hpp", 0, ppfilnam) ;
    #endif
    #ifdef UNIX
    strcpy(tbuffer, pid) ;
    #else
    strcpy(tbuffer, "") ;
    #endif
    strcat(tbuffer, "haditt.tmp") ;
    #ifdef Windows
    GetTempFileName(temppath, "htt", 0, tbuffer) ;
    #endif
    vvv = new VV(szProgramPath) ;
    stop = 0 ;
    finish = 0 ;
    if (debuglevel > 0)
    {
        fprintf(errfile, "Vor Lexikon\n") ;
        fflush(errfile) ;
    }
    lexicon = new TLexicon(szProgramPath) ;
    #ifndef NETPARPATH
#define NETPARPATH szProgramPath
    #endif
    #ifdef DURNETNAME
    durnet = new Netz((char*)DURNETPARNAME, NETPARPATH) ;
    #endif
    #ifdef INTNETNAME
    intnet = new Netz((char*)INTNETPARNAME, NETPARPATH) ;
    #endif
    #ifdef PHONDURNET
    fprintf(errfile, "Vor PDN\n") ;
    fflush(errfile) ;
    phondurnet = new PhonNetz("vokal.par", "kons.par", szProgramPath) ;
    #endif
    if (debuglevel > 0)
    {
        fprintf(errfile, "INIT passed\n\n") ;
        fflush(errfile) ;
    }
    fprintf(errfile, "HADIFIX SUCCESSFULLY INITIALIZED\n") ;
}

int Synthese::change_voice(char* path, const char* name)
{
    if (talknow)
        return (0) ;
    delete (d) ;
    delete (i) ;
    delete (a) ;
    if (debuglevel > 2)
    {
        fprintf(errfile, "In ChangeVoice\n") ;
        fflush(errfile) ;
    }
    fflush(errfile) ;
    #ifndef NOTREE
    delete (b) ;
    #endif
    fprintf(errfile, "1\n") ;
    fflush(errfile) ;
    if (path != NULL)
    {
        delete (inventpath) ;
        inventpath = strdup(path) ;
    }
    delete (inventname) ;
    inventname = strdup(name) ;
    d = new Duration_Model(inventname, inventpath, bwl) ;
    i = new Intonation_Model(inventname, inventpath) ;
    a = new Intensity_Control(inventname, inventpath) ;
    d->set_speech_rate(defaultspeechrate) ;
    fflush(errfile) ;
    #ifdef NOTREE
    b = NULL ;
    #else
    if (debuglevel > 1)
    {
        b = new Baum(treename, inventpath, debuglevel, errfile) ;
    }
    else
    {
        b = new Baum(treename, inventpath, 0, errfile) ;
    }
    #endif
    fflush(errfile) ;
    fflush(errfile) ;
    return (1) ;
}



int Synthese::talk(const char* rf, int modus, const char* filename)
{
    if (talknow)
        return (-1) ;
    talknow = 1 ;
    finish = 0 ;
    char* resultfilename ;
    if (rf == NULL)
        resultfilename = NULL ;
    else
        resultfilename = (char*)rf ;
    if (debuglevel > 0)
    {
        fprintf(errfile, "MODUS %d\n", modus) ;
        if (resultfilename != NULL && filename != NULL)
            fprintf(errfile, "\nFILENAME %s RESULTFILENAME %s\n", filename, resultfilename) ;
        fflush(errfile) ;
    }
    char buffer[256] ;
    infi = NULL ;
    int filetype = 0 ;
    FILE* outfile  = NULL ;
    if (resultfilename[0]=='-')
    {
        outfile = stdout ;
    }
    else
    {
        if (resultfilename == NULL)
        {
            modus += 100 ;
        }
        if (resultfilename != NULL)
        {
            if (strstr(resultfilename, ".wav") != NULL)
                filetype = 1 ;
            if (strstr(resultfilename, ".au") != NULL)
                filetype = 2 ;
            if (strstr(resultfilename, ".voc") != NULL)
                filetype = 3 ;
            outfile = FOPEN((char*)resultfilename, "w+b") ;
        }
    }
    int error = 0 ;
    TLexem lexem;
    long int cnt_lexem = 0L;
    long cnt_real_lexem = 0L;
    FILE* lexemfile = NULL ;
    char* result ;
    #ifdef NPR
    FILE* nlabfile = FOPEN("hadi.lab", "w") ;
    #else
    FILE* nlabfile = NULL ;
    #endif
    Syllablelist* s = NULL;
    Proslist* p = NULL ;
    DBSyllist* dbs = NULL ;
    Soundlist* soli = NULL ;
    char* dialect= NULL ;
    char* transcription = NULL ;
    char* rhythm = NULL ;
    int onlystress = 0 ;
    float preemp = 0.4 ;
    int use_net = def_use_net ;
    char temp[290] ;
    char** lexemlist = NULL ;
    int lexcount = 0 ;
    long implen = -1L ;
    FILE* impfile = NULL ;
    char* impbuffer = NULL ;
    if (modus%10 == 8)
    {
        strcpy(temp, szProgramPath) ;
        strcat(temp, "imppairs.lst") ;
        impfile = fopen(temp, "rb") ;
        if (impfile != NULL)
        {
            fseek(impfile, 0L, SEEK_END) ;
            implen = ftell(impfile) ;
            rewind(impfile) ;
            impbuffer = new char[implen+1] ;
            fread(impbuffer, 1, implen, impfile) ;
            impbuffer[implen]='\0' ;
            fclose(impfile) ;
        }
    }
    if (finish)
        goto ganz_am_ende ;
    do
    {
        if (debuglevel > 0)
        {
            fprintf(errfile, "VOR LEXEMFILE Modus %d NPP %d\n\n\n", modus, nopreproc) ;
            fflush(errfile) ;
        }
        lexemfile = vvv->next_input("", (char*)filename, piping, pid, lexemfilnam) ;
        if (lexemfile == NULL)
        {
            if (debuglevel > 0)
            {
                fprintf(errfile, "LEXEMFILE NULL\n\n\n") ;
                fflush(errfile) ;
            }
            error = 1 ;
            goto hinter_ganz_am_ende ;
        }
        modus %= 10 ;
        cnt_lexem=0 ;
        cnt_real_lexem = 0 ;
        skip_it = 1 ;
        rewind(lexemfile);
        while (1)
        {
            while (skip_it--)
            {
                lexcount = 0 ;
                lexemlist = (char**)malloc(1) ;
                if (debuglevel > 0)
                {
                    fprintf(errfile, "\n\nOutput Transcription Module:\n\n") ;
                    fflush(errfile) ;
                }
                cnt_lexem = 0;
                cnt_real_lexem = 0 ;
                while (lexemfile != NULL && !feof(lexemfile))
                {
                    fread_lexem(lexemfile, lexem);
                    fflush(errfile) ;
                    if (cnt_lexem == 0 && (lexem.Type() != TLexem::wordform && lexem.Type() != TLexem::comment))
                        continue ;
                    if (lexem.Type() != TLexem::nothing)
                    {
                        cnt_lexem++;
                        #ifdef EMAIL
                        lexicon->transcribe(lexem, 1);
                        #else
                        lexicon->transcribe(lexem, 0);
                        #endif
                        if (lexem.Type() == TLexem::wordform)
                            cnt_real_lexem++ ;
                        if (lexem.Type() == TLexem::comment)
                        {
                            #ifndef NGIMMICKS
                            if (strncmp(lexem.Chars().c_str(), "{Accent:", 8) == 0)
                            {
                                if (dialect != NULL)
                                    delete (dialect) ;
                                dialect = strdup(&(lexem.Chars().c_str())[8]) ;
                                dialect[strlen(dialect)-1] = '\0' ;
                                if (strcmp(dialect, "Hochdeutsch") == 0 || strcmp(dialect, "") == 0)
                                {
                                    delete (dialect) ;
                                    dialect = NULL ;
                                }
                            }
                            #endif
                            if (strncmp(lexem.Chars().c_str(), "{Language:", 10) == 0)
                            {
                                if (strncmp(&lexem.Chars().c_str()[10], "Englisch", 8) == 0)
                                    language = 1 ;
                                else
                                    language = 0 	;
                                fprintf(errfile, "Language changed to %d\n", language) ;
                            }
                            if (strncmp(lexem.Chars().c_str(), "{Transcription:", 15) == 0)
                            {
                                transcription = strdup(&(lexem.Chars().c_str())[15]) ;
                                transcription[strlen(transcription)-1] = '\0' ;
                            }
                            if (strncmp(lexem.Chars().c_str(), "{WordRhythm:", 12) == 0)
                            {
                                rhythm = strdup(&(lexem.Chars().c_str())[12]) ;
                                rhythm[strlen(rhythm)-1] = '\0' ;
                            }
                        }
                        #ifndef NGIMMICKS
                        if (lexem.Type() == TLexem::wordform && dialect != NULL)
                            make_dialect(lexem, dialect) ;
                        #endif
                        if (lexem.Type() == TLexem::wordform && rhythm != NULL)
                        {
                            change_rhythm(lexem.transcription, rhythm) ;
                            delete (rhythm) ;
                            rhythm = NULL ;
                        }
                        if (lexem.Type() == TLexem::wordform && transcription != NULL)
                        {
                            sampa2ipa(lexem.transcription, transcription) ;
                            delete (transcription) ;
                            transcription = NULL ;
                        }
                        if (debuglevel > 0)
                        {
                            fwrite_lexem(errfile, lexem) ;
                            fflush(errfile) ;
                        }
                        lexcount++ ;
                        lexemlist = (char**)realloc(lexemlist, sizeof(char*)*lexcount) ;
                        put_lexem(lexemlist, lexcount, lexem) ;
                    }
                    if (lexem.Type() == TLexem::point || lexem.Type() == TLexem::exclamation || lexem.Type() == TLexem::question)
                        break;
                }
                if (lexemfile != NULL)
                    alles_gelesen = feof(lexemfile);
                if (alles_gelesen && lexemfile != NULL)
                {
                    FCLOSE(lexemfile) ;
                    unlink(lexemfilnam) ;
                    if (nopreproc == 0)
                        unlink(ppfilnam) ;
                    lexemfile = NULL ;
                }
                if (cnt_lexem > 1)
                {
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "Building syllablelist\n") ;
                        fflush(errfile) ;
                    }
                    s = new Syllablelist() ;
                    prosogenx(lexemlist, s, lexcount, (modus==3?outfile:(FILE*)NULL)) ;
                }
                #ifdef ABSOLUTELY_NO_FILES
                for (int iii=0 ; iii < lexcount ; iii++)
                    free(lexemlist[iii]) ;
                free(lexemlist) ;
                #endif
            }
            skip_it = 1;
            if (debuglevel > 0)
            {
                fprintf(errfile, "Linguistic part finished %ld %ld\n", cnt_lexem, cnt_real_lexem) ;
                fflush(errfile) ;
            }
            if (finish)
                goto ganz_am_ende ;
            if (cnt_lexem == 0)
            {
                if (s != NULL)
                    delete (s) ;
                s = NULL ;
                break ;
            }
            if (cnt_real_lexem == 0)
                goto hinter_ganz_am_ende ;
            if (modus == 3 || modus == 4)
            {
                if (s != NULL)
                    delete (s) ;
                s = NULL ;
            }
            else
            {
                if (s == NULL)
                    break ;
                if (s->length() < 3)
                {
                    delete (s) ;
                    break ;
                }
                result = s->new_voice() ;
                if (result != NULL)
                {
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "Changing Voice %s %s\n", inventpath, result) ;
                        fflush(errfile) ;
                    }
                    strcpy(buffer, inventpath) ;
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "Changing Voice %s %s\n", buffer, result) ;
                        fflush(errfile) ;
                    }
                    talknow = 0 ;
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "Changing Voice %s %s\n", buffer, result) ;
                        fflush(errfile) ;
                    }
                    change_voice(buffer, result) ;
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "Voice changed\n") ;
                        fflush(errfile) ;
                    }
                    talknow = 1 ;
                }
                #ifndef NOTREE
                result = s->find_command("Tree") ;
                if (result != NULL)
                {
                    delete (b) ;
                    strcpy(treename, result) ;
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "Tree %s%s loaded\n", inventpath, result) ;
                        fflush(errfile) ;
                    }
                    b = new Baum(treename, inventpath, 0, NULL) ;
                }
                #endif
                soli = new Soundlist ;
                nulltest(soli) ;
                result = s->find_command("UseCARTProminence") ;
                if (result != NULL)
                    use_wagonprom = atoi(result) ;
                if (use_wagonprom == 1)
                {
                    s->wagonprom() ;
                }
                if (interpunction == 0)
                    if (s->no_interpunction() == 0)
                    {
                        delete (s) ;
                        delete (soli) ;
                        continue ;
                    }
                s->pauses() ;
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Before Reduction\n") ;
                    fflush(errfile) ;
                }
                reduction_level = s->reduce(reduction_level) ;
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Before Intonation_Features\n") ;
                    fflush(errfile) ;
                }
                s->compute_intonation_features() ;
                if (debuglevel > 0)
                {
                    fprintf(errfile, "\n\nOutput Syllable Module:\n\n") ;
                    s->print(errfile) ;
                    fflush(errfile) ;
                }
                if (s->make_soundlist(soli) < 1)
                {
                    error = 1 ;
                    syndata_error("main", "Lautliste kann nicht erstellt werden", 2) ;
                    continue ;
                }
                result = s->find_command("Preemphasis") ;
                if (result != NULL)
                {
                    preemp=atof(result) ;
                    if (preemp < 0.0 || preemp > 1.0)
                    {
                        preemp = 0.0 ;
                    }
                }
                result = s->find_command("UseNet") ;
                if (result != NULL)
                {
                    use_net = atoi(result) ;
                }
                result = NULL ;
                #ifndef NO_FILES
                result = s->find_command("DBS") ;
                if (result == NULL)
                #ifdef UNIX
                    xbs = FOPEN(strcat(strcpy(temp, pid), "xbs.lst"), "w+") ;
                #else
                    xbs = FOPEN("xbs.lst", "w+") ;
                #endif
                else
                    xbs = FOPEN(result, "r") ;
                #ifdef UNIX
                kbs = FOPEN(strcat(strcpy(temp, pid), "kbs.lst"), "w+") ;
                #else
                kbs = FOPEN("kbs.lst", "w+") ;
                #endif
                #endif        // NO FILES
                if (n->build(s, soli) < 1 && result == NULL)
                {
                    if (debuglevel > 0)
                    {
                        fprintf(errfile, "\n\nOutput Prosody Preparation Module:\n\n") ;
                        n->list_DBS(errfile) ;
                        fflush(errfile) ;
                    }
                    #ifndef NO_FILES
                    n->list_DBS(xbs) ;
                }
                    #else
                    dbs = n->get_DBS() ;
                }
                    #endif
                #ifndef NO_FILES
                #ifndef NOTREE
                if (b->compute_from_file_to_file(xbs, kbs) == 0)
                {
                    if (debuglevel > 0)
                    {
                        syndata_error("main", "Baum konnte nicht berechnet werden.", 2) ;
                    }
                    FCLOSE(kbs) ;
                    kbs = NULL ;
                }
                #else
                FCLOSE(kbs) ;
                kbs = NULL ;
                #endif
                #else
                #ifndef NOTREE
                p = new Proslist() ;
                if (b->compute_from_list_to_list(dbs, p) == 0)
                {
                    if (debuglevel > 0)
                    {
                        syndata_error("main", "Baum konnte nicht berechnet werden.", 2) ;
                    }
                    delete (p) ;
                    p = NULL ;
                }
                #endif
                #endif 		// NO_FILES
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Syllable duration computed\n") ;
                    fflush(errfile) ;
                }
                #ifndef NO_FILES
                #ifdef DURNETNAME
                if (kbs != NULL)
                    FCLOSE(kbs) ;
                #ifdef UNIX
                kbs = FOPEN(strcat(strcpy(temp, pid), "kbs.lst"), "w+") ;
                #else
                kbs = FOPEN("kbs.lst", "w+") ;
                #endif
                rewind(xbs) ;
                durnet->compute(xbs, kbs, (nefu)DURNETNAME) ;
                #endif
                #else		// NO_FILES
                #ifdef DURNETNAME
                durnet->compute(n, proslist, (nefu)DURNETNAME) ;
                #endif
                #endif
//      The Net is NOT used for duration calculation
//      as long as the following preprocessor alternative
//      is there
                //Hier Nicht
//#ifdef NN
//                      if (d->compute_duration(*s,soli,NULL,0L) < 1) {
//#else
                #ifndef NO_FILES
                if (d->compute_duration(*s, soli, kbs, 0L) < 1)
                {
                #else
                #ifdef PHONDURNET
                if (d->compute_duration(*s, soli, NULL, 0L, p, use_net, phondurnet, dbs) < 1)
                {
                #else
                if (d->compute_duration(*s, soli, NULL, 0L, p) < 1)
                {
                #endif
                #endif
//#endif
                    error = 1 ;
                    syndata_error("main", "Silbendauer kann nicht erstellt werden", 2) ;
                    continue ;
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Duration computed\n") ;
                    fflush(errfile) ;
                }
                #ifndef NO_FILES
                #ifdef DURNETNAME
                if (kbs != NULL)
                    FCLOSE(kbs) ;
                kbs = NULL ;
                #endif
                #endif
                //HIER SCHON
                #ifndef NO_FILES
                #ifdef INTNETNAME
                #ifdef UNIX
                kbs = FOPEN(strcat(strcpy(temp, pid), "kbs.lst"), "w+") ;
                #else
                kbs = FOPEN("kbs.lst", "w+") ;
                #endif
                rewind(xbs) ;
                intnet->compute(xbs, kbs, (nefu)INTNETNAME) ;
                onlystress = 1 ;
                #endif
                if (i->compute_f0(*s, soli, modus, kbs, 0L, pid, onlystress) < 1)
                {
                #else
                #ifdef INTNETNAME
                intnet->compute(n, p, (nefu)INTNETNAME) ;
                #endif
                if (i->compute_f0(*s, soli, modus, NULL, 0L, pid, onlystress, p) < 1)
                {
                #endif
                    error = 1 ;
                    syndata_error("main", "Intonation kann nicht erstellt werden", 2) ;
                    continue ;
                }
                #ifndef NO_FILES
                if (kbs != NULL)
                    FCLOSE(kbs) ;
                FCLOSE(xbs) ;
                #endif
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Intonation computed\n") ;
                    fflush(errfile) ;
                }
                if (a->compute_intensities(soli) < 1)
                {
                    error = 1 ;
                    syndata_error("main", "Intensities kann nicht erstellt werden", 2) ;
                    continue ;
                }
                if (debuglevel > 1)
                {
                    fprintf(errfile, "Intensities computed\n") ;
                    fflush(errfile) ;
                }
                if (p != NULL)
                {
                    delete (p) ;
                    p = NULL ;
                }
                i->clear() ;
                n->clear() ;
                //			delete(soli) ;
                //			delete(s) ;
                //			break ;
                #ifdef DEBUG3
                soli->printf0(f0fil) ;
                #endif
                if (finish)
                {
                    delete (soli) ;
                    delete (s) ;
                    goto ganz_am_ende ;
                }
                if (nlabfile != NULL)
                    s->printkalle(soli, nlabfile) ;
                if (modus == 8)
                {
                    s->printmbrola(soli, outfile, impbuffer) ;
                    if (s != NULL)
                        delete (s) ;
                    s = NULL ;
                    if (soli != NULL)
                        delete (soli) ;
                    soli = NULL ;
                    continue ;
                }
            }
        }
    }
    while (piping) ;
    goto hinter_ganz_am_ende ;

ganz_am_ende:

hinter_ganz_am_ende :

    fflush(errfile) ;
    if (infi != NULL)
        delete (infi) ;
    fflush(errfile) ;
    if (outfile != stdout)

        if (outfile != NULL)
            FCLOSE(outfile) ;
    if (modus != 5 && dialect != NULL)
        delete (dialect) ;
    if (modus != 5 && lexemfile != NULL)
    {
        FCLOSE(lexemfile) ;
        unlink(lexemfilnam) ;
        if (nopreproc == 0)
            unlink(ppfilnam) ;
    }
    unlink(ppfilnam) ;
    unlink(lexemfilnam) ;


    talknow = 0 ;
    finish = 0 ;
    return (error) ;
}


Synthese::~Synthese()
{
    char temp[256] ;
    fprintf(errfile, "Starting to delete Hadifix\n") ;
    fflush(errfile) ;
    delete (env) ;
    #ifdef UNIX
    if (rcenv != NULL)
        delete (rcenv) ;
    #endif
    delete[](inventname) ;
    delete[](inventpath) ;
    #ifndef NOTREE
    delete (b) ;
    #endif
    delete (n) ;
    delete (a) ;
    delete (d) ;
    delete (i) ;
    fprintf(errfile, "Starting to delete the Lexicon\n") ;
    fflush(errfile) ;
    delete (lexicon) ;
    delete (vvv) ;
    #ifdef NN
    delete NNetz;
    delete IFile;
    delete DFile;
    delete RFile;
    #endif
    #ifdef DURNETNAME
    delete durnet ;
    #endif
    #ifdef INTNETNAME
    delete intnet ;
    #endif
    #ifdef PHONDURNET
    delete phondurnet ;
    #endif
    if (debuglevel > 0)
    {
        fprintf(errfile, "END OF SYNTHESIS\n_______________________________________________________\n") ;
        fflush(errfile) ;
    }
    #ifdef DEBUG3
    fclose(f0fil) ;
    #endif
    fprintf(errfile, "Leaving HADIFIX %d\n", instcnt) ;
    fflush(errfile) ;
    strcat(strcpy(temp, pid), ".hadi.log") ;
    if (debuglevel == 0)
        unlink(temp) ;
    if (debuglevel > 2)
        debugstr.close() ;
}




