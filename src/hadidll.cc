#include "synthese.h"
#include "sigman.h"


#include "ascii.h"

//#define DEBUG3 0

#define ABSOLUTELY_NO_FILES

#define LOGFILE
#ifndef UNIX
#undef DEBUG3
#endif

//#define NPR

#ifdef STATISTICS
#ifndef LOGFILE
#define LOGFILE
#endif
#endif

//#undef LOGFILE

#ifdef NET
#include "netzhead.h"
#endif

int instcnt = 0 ;
FILE*errfile = NULL ;
char fnamtmp[256] ;
char jnamtmp[256] ;
ofstream debugstr ;
int debuglevel = 0 ;
int language = 0 ;

#ifdef NN
extern void transhin (FILE* infil, FILE* outfil) ;
extern void transbak (FILE* infil, FILE* outfil) ;
#endif

#ifdef UNIX
#ifdef SOLARIS
#include <sys/audioio.h>
#endif
#include <fcntl.h>
#include <unistd.h>
#endif




extern long bt4(long) ;


extern int sampa2ipa (string &out, char* in) ;

#ifndef NGIMMICKS
extern int make_dialect(TLexem& lexem, char* dialect) ;
#endif

#ifdef UNIX
extern int PPmain(char*,char*,char*,char*) ;
#else
#include "ppdll.h"
#endif

extern int change_rhythm(string &out, char* r) ;

#ifdef _Windows
Synthese::Synthese(HINSTANCE __hWnd, char* path, int db, int bw, int txt2pho)
#else
Synthese::Synthese(char* __hWnd, char* path, char* logprefix, int db, int pip, int npp, int txt2pho)
#endif
{
  language = 0 ;
       skip_it = 1;
       alles_gelesen = 0 ;
       talknow = 0 ;

	char temp[256] ;

#ifdef _Windows
	hWnd = __hWnd;
   GetTempPath(256,temppath) ;

#endif
#ifdef UNIX
	int rcfile_present=1 ;
	bwl = 0 ;


	if (getenv("HOME")==NULL)
	  if (npp == 0)
	    strcpy(temp,".hadifixrc") ;
	  else
	    strcpy(temp,".txt2phorc") ;
	else    
	  if (npp == 0)
	    strcat(strcpy(temp,getenv("HOME")),"/.hadifixrc") ;
	  else
	    strcat(strcpy(temp,getenv("HOME")),"/.txt2phorc") ;
        FILE* rcfile=fopen(temp,"r") ;
        if (rcfile == NULL) {
	  if (npp == 0)
	    strcpy(temp,"/etc/hadifix") ;
	  else
	    strcpy(temp,"/etc/txt2pho") ;
	  rcfile=fopen(temp,"r") ;
	  if (rcfile == NULL)
	    {
	      rcenv = NULL ;
	      rcfile_present = 0 ; } }
        if (rcfile_present != 0) {
	  fclose(rcfile) ;
	  errfile = stderr ;
	  rcenv = new Environment("",temp) ;
	  if (strlen(path) == 0 && strlen(rcenv->get_value("DATAPATH")) > 0)
	    path=rcenv->get_value("DATAPATH") ;
	  if (db == -1 && strlen(rcenv->get_value("DEBUGLEVEL")) > 0)
	    db = atoi(rcenv->get_value("DEBUGLEVEL")) ;
	  if (strlen(logprefix) == 0 && strlen (rcenv->get_value("TEMPPATH")) > 0)
	    logprefix = rcenv->get_value("TEMPPATH") ;
	  errfile = NULL ; }


	if (strlen(logprefix) == 0)
	  logprefix = "/tmp/" ;
	strcat(strcpy(pid,logprefix), __hWnd) ;
	piping = pip ;
	nopreproc = pip ;
	tx2ph = txt2pho ;





#else
	bwl = bw ;
	tx2ph = txt2pho ;
	nopreproc = 0 ;
	piping = 0 ;
	strcpy(pid,"") ;
#endif

	debuglevel = db ;

#ifdef Windows
//    debuglevel = 0 ;
 #endif

#ifdef UNIX
	if (strlen(path) == 0) {
	  if (npp == 0)
	    path = "/usr/local/hadifix/data/" ;
	  else
	    path = "/usr/local/txt2pho/data/" ; }
#endif

	strcpy(szProgramPath,path) ;


#ifdef UNIX
#ifdef DEBUG3
	f0fil=fopen(strcat(strcpy(temp,pid),".hadi.f0"),"w") ;
#endif
	errfile = fopen(strcat(strcpy(temp,pid),".hadi.log"),"w") ;
//	errfil = stderr ;
#else

	if (instcnt == 0) {
		GetTempFileName(temppath,"had",0,fnamtmp) ;
	//	if (errfile == NULL)
		errfile = fopen(fnamtmp,"w") ; }
	if (instcnt == 0 && debuglevel > 2) {
		GetTempFileName(temppath,"had",0,jnamtmp) ;
	//	if (errfile == NULL)
		debugstr.open(jnamtmp) ; }
		ppindex = instcnt ;
      instcnt++ ;

#endif
	if (errfile == NULL)
		printf("ERROR CAN'T OPEN LOGFILE\n") ;


#ifdef UNIX
	if (debuglevel > 2) {
	  strcat(strcpy(temp,pid),".juergen.log") ;
	  debugstr.open(temp) ; }
#endif

	fprintf(errfile,"Debuglevel %d\n",debuglevel) ;

	env = new Environment(szProgramPath,"hadifix.cfg") ;
	inventname = strdup(env->get_value("INVENTORY")) ;
	inventpath = strdup(env->get_value("INVPATH")) ;
	def_use_net = atoi(env->get_value("USENET")) ;
        use_wagonprom = atoi(env->get_value("PROMCOMP")) ;

#ifdef UNIX
        if (rcfile_present) {
          if (strlen(rcenv->get_value("INVENTORY")) > 0)
	    inventname = strdup(rcenv->get_value("INVENTORY")) ;
          if (strlen(rcenv->get_value("INVPATH")) > 0)
	    inventpath = strdup(rcenv->get_value("INVPATH")) ;
	   if (strlen(rcenv->get_value("USENET")) > 0)
	     def_use_net = atoi(rcenv->get_value("USENET")) ;
	   if (strlen(rcenv->get_value("PROMCOMP")) > 0)
	     use_wagonprom = atoi(rcenv->get_value("PROMCOMP")) ; }
#endif

	fprintf(errfile,"INVENTORY %s\n",inventname) ;
	fprintf(errfile,"INVPASTH %s\n",inventpath) ;
	defaultspeechrate = 1.0 ;
	if (strlen(env->get_value("SPEECHRATE")) > 1)
	  defaultspeechrate = atof(env->get_value("SPEECHRATE")) ;

	reduction_level = atoi(env->get_value("REDUCTION")) ;
	strcpy(treename,inventname) ;
	if (strlen(env->get_value("NEWTREE")) > 1)
		strcpy(treename,env->get_value("NEWTREE")) ; 

#ifdef UNIX
        if (rcfile_present) {
          if (strlen(rcenv->get_value("NEWTREE")) > 0)
	    strcpy(treename,rcenv->get_value("NEWTREE")) ;
	   if (strlen(rcenv->get_value("REDUCTION")) > 0)
	     reduction_level = atoi(rcenv->get_value("REDUCTION")) ;
	   if (strlen(rcenv->get_value("SPEECHRATE")) > 0)
	     defaultspeechrate = atof(rcenv->get_value("SPEECHRATE")) ; }
#endif

	
	interpunction = 0 ;
	dares = 16 ;
#if (DARES==8)
	dares = 8 ;
#endif
	mulaw = 1 ;

	fprintf(errfile,"INVENTORY %s blabla\n",inventname) ;
	fprintf(errfile,"INVPASTH %s blabla\n",inventpath) ;
	d = new Duration_Model(inventname,inventpath,bwl) ;
	i = new Intonation_Model(inventname,inventpath) ;
	a = new Intensity_Control(inventname,inventpath) ;
if (debuglevel > 0) {
	fprintf(errfile,"BEFORE TREE\n") ;
	fflush(errfile) ;
}
	n = new NNProsody(inventname,inventpath) ;
#ifdef NOTREE
	b = NULL ;
if (debuglevel > 0) {
	fprintf(errfile,"NOTREE defined\n") ;
	fflush(errfile) ;
}
#else
        if (debuglevel == 0)
	b = new Baum(treename,inventpath,0,errfile) ;
	else
	b = new Baum(treename,inventpath,1,errfile) ;

if (debuglevel > 0) {
	fprintf(errfile,"TREE READ\n") ;
	fflush(errfile) ;
}
#endif

 if (tx2ph == 0) { 
	invent = new Inventory(inventname,inventpath,0) ;
if (debuglevel > 0) {
	fprintf(errfile,"INVENTORY READ\n") ;
	fflush(errfile) ;
}
 }
	d->set_speech_rate(defaultspeechrate) ;

	fprintf(errfile,"Program Path %s\n",szProgramPath) ;


#ifdef UNIX
	strcpy(lexemfilnam,pid) ;
#else
	strcpy(lexemfilnam,"") ;
#endif
	strcat(lexemfilnam,"hadivv.tmp") ;
#ifdef Windows
	GetTempFileName(temppath,"hvv",0,lexemfilnam) ;
#endif

#ifdef UNIX
	strcpy(ppfilnam,pid) ;
#else
	strcpy(ppfilnam,"") ;
#endif
	strcat(ppfilnam,"hadipp.tmp") ;
#ifdef Windows
	GetTempFileName(temppath,"hpp",0,ppfilnam) ;
#endif

#ifdef UNIX
	strcpy(tbuffer,pid) ;
#else
	strcpy(tbuffer,"") ;
#endif
	strcat(tbuffer,"haditt.tmp") ;
#ifdef Windows
	GetTempFileName(temppath,"htt",0,tbuffer) ;
#endif

	vvv = new VV(szProgramPath) ;

	stop = 0 ;
	finish = 0 ;

if (debuglevel > 0) {
   fprintf(errfile,"Vor Lexikon\n") ;
   fflush(errfile) ;
}

	lexicon = new TLexicon(szProgramPath) ;


#ifndef NETPARPATH
#define NETPARPATH szProgramPath
#endif

#ifdef DURNETNAME
	durnet = new Netz((char*)DURNETPARNAME,NETPARPATH) ;
#endif

#ifdef INTNETNAME
	intnet = new Netz((char*)INTNETPARNAME,NETPARPATH) ;
#endif

#ifdef PHONDURNET

fprintf(errfile,"Vor PDN\n") ;
fflush(errfile) ;

	phondurnet = new PhonNetz("vokal.par","kons.par",szProgramPath) ;
#endif

if (debuglevel > 0) {
	fprintf(errfile,"INIT passed\n\n") ;
	fflush(errfile) ;
}


#ifdef NN
	FehlerTyp ErrorCode = 0 ;

	NNetz = new NeuronalesNetz();
	IFile = new InputFile(NNetz);
	DFile = new DataFile();
	RFile = new RecallFile();

#ifdef BORDERPROS
	strcat(strcpy(&In_File[0], szProgramPath),"u313in.net") ;
#else
	strcat(strcpy(&In_File[0], szProgramPath),"u2rin.net");
#endif
#ifdef UNIX
	strcpy(Dat_File, strcat(strcpy(temp,pid),"nnin.dat");
	strcpy(Rec_File, strcat(strcpy(temp,pid),"nnout.dat");
#else
	strcpy(&Dat_File[0], "nnin.dat");
	strcpy(&Rec_File[0], "nnout.dat");
#endif

if (debuglevel > 0) {
	fprintf(errfile,"NET USES %s AS DEFINITION, %s AS INPUT AND %s AS OUTPUT\n",In_File,Dat_File,Rec_File) ;
	fflush(errfile) ;
}

	ErrorCode = IFile->GetInputFile(In_File, TRUE, NNetz);

	if (ErrorCode != 0)
		fprintf(errfile,"NetError %d at IF->GIF\n",ErrorCode) ;

	ErrorCode = DFile->SetDataInParameters(NNetz->GetE_NeuronList()    ,
										  NNetz->GetAnzInputNeurons() ,
										  NNetz->GetAnzOutputNeurons(),
										  NNetz->GetWindowBreite()    ,
										  TRUE                        ,
										  TRUE                        ,
										  FALSE                       ,
										  FALSE                         );

	if (ErrorCode != 0)
		fprintf(errfile,"NetError %d at DF->SDIP\n",ErrorCode) ;
	fprintf(errfile,"NET USES %s AS DEFINITION, %s AS INPUT AND %s AS OUTPUT\n",In_File,Dat_File,Rec_File) ;
#endif

	fprintf(errfile,"HADIFIX SUCCESSFULLY INITIALIZED\n") ;

}

char* Synthese::get_voice() {
	char* result = new char[_MAX_PATH] ;
	strcat(strcat(strcpy(result,inventpath),inventname),".ind") ;
	return(result) ; }

char* Synthese::get_invent() {

	char* result = new char[_MAX_PATH] ;
	strcat(strcpy(result,inventpath),inventname) ;
	return(result) ; }

long* Synthese::get_word_position_list(long* wpl) {
	return(d->get_word_list(wpl)) ; }


void Synthese::change_dares(int value) {
	dares = value ; }

void Synthese::set_mulaw(int value) {
	mulaw = value ; }


int Synthese::change_voice(char* path, char* name) {
	if (talknow)
		return(0) ;
	delete(d) ;
	delete(i) ;
	delete(a) ;

   if (debuglevel > 2) {
   fprintf(errfile,"In ChangeVoice\n") ;
	fflush(errfile) ; }

	if (tx2ph == 0)
	  delete(invent) ;
	fflush(errfile) ;
#ifndef NOTREE
	delete(b) ;
#endif
	fprintf(errfile,"1") ;
	fflush(errfile) ;
	if (path != NULL) {
	  delete(inventpath) ;
	  inventpath = strdup(path) ; }
	delete(inventname) ;
	inventname = strdup(name) ;
	d = new Duration_Model(inventname,inventpath,bwl) ;
	i = new Intonation_Model(inventname,inventpath) ;
	a = new Intensity_Control(inventname,inventpath) ;
	d->set_speech_rate(defaultspeechrate) ;
	fflush(errfile) ;
#ifdef NOTREE
	b = NULL ;
#else
if (debuglevel > 1) {
  b = new Baum(treename,inventpath,debuglevel,errfile) ; }
 else {
	b = new Baum(treename,inventpath,0,errfile) ;
}
#endif
	fflush(errfile) ;
	if (tx2ph == 0)
	  invent = new Inventory(inventname,inventpath) ;
	fflush(errfile) ;
	return(1) ; }

float Synthese::get_speechrate() {
	return(d->get_speech_rate()) ; }

int Synthese::change_speechrate(float value) {
	d->set_speech_rate(value) ;
	return(1); }

int Synthese::set_reduction_level(int value) {
	reduction_level = value ;
   return(1) ; }

int Synthese::add_abbreviation(char* abb, char* text) {
	return(vvv->add_abbreviation(abb,text)) ; }

int Synthese::change_abbreviation_list(char* filename) {
	return(vvv->change_abbreviation_list(filename)) ; }

int Synthese::change_SI_abbreviation_list(char* filename) {
	return(vvv->change_SI_abbreviation_list(filename)) ; }

float Synthese::get_pitch() {
	return(i->get_pitch()) ; }

int Synthese::change_pitch(float value) {
	i->set_pitch(value) ;
	return(1) ; }

float Synthese::get_speechraterange() {
	return(d->get_speech_rate_range()) ; }

int Synthese::change_speechraterange(float value) {
	d->set_speech_rate_range(value) ;
	return(1); }


float Synthese::get_accentlength() {
	return(d->get_accentlength()) ; }

int Synthese::change_accentlength(float value) {
	d->set_accentlength(value) ;
	return(1); }

float Synthese::get_finallengthening() {
	return(d->get_final_lengthening()) ; }

int Synthese::change_finallengthening(float value) {
	d->set_final_lengthening(value) ;
	return(1); }

float Synthese::get_pitchrange() {
	return(i->get_pitchrange()) ; }

int Synthese::change_pitchrange(float value) {
	i->set_pitchrange(value) ;
	return(1) ; }

float Synthese::get_declination() {
	return(i->get_declination()) ; }

int Synthese::change_declination(float value) {
	i->set_declination(value) ;
	return(1) ; }

int Synthese::preprocess(char* infilename, char* outfilename) {

	char temp[256] ;
	char buffer[256] ;
	char* filename = infilename ;


#ifdef Windows
	FILE* ppoutfile ;
	char r[8192] ;

	if (nopreproc==0) {
	strcpy(temp,szProgramPath) ;
	strcat(temp,"hadifix.ppr") ;
	strcpy(buffer,szProgramPath) ;
	strcat(buffer,"hadifix.ppa") ;
	PPInit((char*)filename,temp,buffer,ppindex) ;
	ppoutfile = fopen(ppfilnam,"w") ;
	while (PPnextpart(r,8191,ppindex) != NULL) {
		fprintf(ppoutfile,"%s",r) ; }
	fclose(ppoutfile) ;
	PPClose(ppindex) ;
	filename = ppfilnam ; }
#else
	if (nopreproc==0) {
	strcpy(temp,szProgramPath) ;
	strcat(temp,"hadifix.ppr") ;
	strcpy(buffer,szProgramPath) ;
	strcat(buffer,"hadifix.ppa") ;
	int result = PPmain(temp,buffer,(char*)filename,ppfilnam) ;
	if (result == 0)
	  filename = ppfilnam ; }
#endif
	FCLOSE(vvv->next_input((char*)outfilename,(char*)filename,piping,pid)) ;
	unlink(ppfilnam) ;
	free(ppfilnam) ;
	return(1) ; }

int Synthese::set_interpunction(int value) {
	interpunction = value ;
	return(1) ; }


int Synthese::talk(const char* rf, int modus, const char* filename, int preproc, int (*Call)(), int* wordnr , char*** wordlist, char* rvfilename)
{

	if (talknow)
		return(-1) ;
	talknow = 1 ;
	finish = 0 ;

   char* resultfilename ;
   if (rf == NULL)
   	resultfilename = NULL ;
   else
   	resultfilename = (char*)rf ;



//	fprintf(errfile,"%s\n",filename) ;
if (debuglevel > 0) {
	fprintf(errfile,"MODUS %d\n",modus) ;
	if (resultfilename != NULL && filename != NULL)
		fprintf(errfile,"\nFILENAME %s RESULTFILENAME %s\n",filename,resultfilename) ;
	fflush(errfile) ;
}




	infi = NULL ;
	int filetype = 0 ;
	FILE* outfile  = NULL ;
	int danow = 0 ;


#ifdef UNIX
#ifdef SOLARIS
	audio_info_t infoo ;
	int audio_fd = -1 ;
	if (modus == -1) {
		modus = 0 ;
		audio_fd = open("/dev/audio",O_WRONLY) ;
		AUDIO_INITINFO(&infoo) ;
		infoo.play.sample_rate = invent->get_sf()*1000 ;
		infoo.play.channels = 1 ;
		infoo.play.precision = 16 ;
		infoo.play.encoding = 3 ;
		ioctl(audio_fd,AUDIO_SETINFO,&infoo) ;
		danow=audio_fd ;
		outfile = NULL ; }
	else
#endif
	if (resultfilename[0]=='-') {
		outfile = stdout ; }
	else
#endif
	{
		if (resultfilename == NULL) {
#ifdef NPR
			resultfilename = "hadi.voc" ;
#else
//			resultfilename = "hadi.pcm" ;
#endif

			modus += 100 ; }

		if (resultfilename != NULL) {
			if (strstr(resultfilename,".wav") != NULL)
				filetype = 1 ;
			if (strstr(resultfilename,".au") != NULL)
				filetype = 2 ;
			if (strstr(resultfilename,".voc") != NULL)
				filetype = 3 ;
			outfile = FOPEN((char*)resultfilename,"w+b") ; } }


	int error = 0 ;

#ifdef _Windows
	FILE* synfile = NULL ;
	int hnr = 0 ;
	HugeArray<DATYPE>* h[2] = {NULL,NULL} ;
#endif

	TLexem lexem;
	long int cnt_lexem = 0L;
	long cnt_real_lexem = 0L;

	FILE *lexemfile = NULL ;
	//	FILE* transfile = NULL ;
	//	 FILE* resultfile = NULL ;


	char* result ;
	//	long geton ;
	//	long getoff ;

	//	FILE* synfile = NULL ;
#ifdef NPR
	FILE* nperfile = FOPEN("hadi.npr","w") ;
	FILE* nmrkfile = FOPEN("hadi.nmk","w") ;
	FILE* nlabfile = FOPEN("hadi.lab","w") ;
	FILE* nmrk2file = FOPEN("hadi2.nmk","w") ;
#else
	FILE* nlabfile = NULL ;
	FILE* nperfile = NULL ;
	FILE* nmrkfile = NULL ;
   FILE* nmrk2file = NULL ;
#endif

        int sf = 16000 ; 

	if (tx2ph == 0)
	  sf = invent->get_sf() ;
	

	Syllablelist* s = NULL;
	Unitlist* u = NULL ;
	Periodlist* pl = NULL ;
	Marklist* ml = NULL;
	Proslist* p = NULL ;
	DBSyllist* dbs = NULL ;
	Markerinfo m ;
	Soundlist* soli = NULL ;
	char* dialect= NULL ;
	char* transcription = NULL ;
	char* rhythm = NULL ;
	FILE* rvfile ;

	Sigman ssmm ;

	char optimethod[80] ;
	optimethod[0] = '\0' ;

	int onlystress = 0 ;

   float preemp = 0.4 ;

#ifdef _Windows
	if (modus >= 100) {
		modus = modus - 100 ;
		danow = 1 ; }
#else
	if (modus >= 100) {
		modus = modus - 100 ;
		danow = 0 ; }
#endif


#ifdef WINDAC
	if (danow == 0) {
		if (filetype == 1)
			dac = new DAC(outfile,0,sf,dares, mulaw) ;
		else if (filetype == 2)
			dac = new DAC(outfile,sf,dares,mulaw) ;
      else
      	dac = new DAC(NULL,sf) ; }
	else
		dac = new DAC(NULL,sf) ;
#else
	if (filetype == 1)
		dac = new DAC(outfile,0,sf,dares,mulaw) ;
	else if (filetype == 2)
		dac = new DAC(outfile,sf,dares,mulaw) ;
#endif


	int psola_method = 0 ;
	int lpc_grade = sf* 2 + 3 ;
	float mu = 0.5 ;
	int relpdelay = 0 ;

	int reset,lastpl,preset ;
	short* sigpart ;
	int lastlastpl ;
	long sigpos,lastsigpos,lastlastsigpos,lsigpos ;
	int siglen,j ;
	int use_net = def_use_net ;
	Duration* dd ;
	float position = 0.4 ;
	char buffer[256] ;
	char xbuffer[256] ;

#ifdef NN
	FehlerTyp ErrorCode = 0 ;
	FILE* nnfile ;
	FILE* nnout ;
#endif
	char temp[290] ;
	//	FILE* treef ;
	//	FILE* xbs ;
	//	FILE* kbs ;
	FILE* solifile ;
	char** lexemlist = NULL ;
	int lexcount = 0 ;

	long implen = -1L ;
	FILE* impfile = NULL ;
	char* impbuffer = NULL ;
	if (modus%10 == 8) {
		strcpy(temp,szProgramPath) ;
		strcat(temp,"imppairs.xxx") ;
		impfile = fopen(temp,"rb") ;
		if (impfile != NULL) {
			fseek(impfile,0L,SEEK_END) ;
			implen = ftell(impfile) ;
			rewind(impfile) ;
			impbuffer = new char[implen+1] ;
			fread(impbuffer,1,implen,impfile) ;
			impbuffer[implen]='\0' ;
			fclose(impfile) ; } }


	if (modus == 5)
		goto modus5 ;

	if (debuglevel > 3) {
   	fprintf(errfile,"Before the Call %p\n",Call) ;
      fflush(errfile) ; }

	if (Call != NULL)
		Call() ;

	if (debuglevel > 3) {
   	fprintf(errfile,"After the Call - Finish %d\n",finish) ;
      fflush(errfile) ; }

	if (finish)
		goto ganz_am_ende ;



	do {
//	fprintf(errfile,"AAA\n") ; fflush(errfile) ;

if (debuglevel > 0) {
	fprintf(errfile,"VOR LEXEMFILE Modus %d NPP %d  PP %d\n\n\n",modus,nopreproc,preproc) ;
	fflush(errfile) ;
}
	int ppresult ;

	if (preproc == 1) {
		if (modus < 10)
			lexemfile = FOPEN((char*)filename,"r") ;
		else {
			lexemfile = FOPEN(lexemfilnam,"w") ;
			fprintf(lexemfile,"%s",filename) ;
         FCLOSE(lexemfile) ;
			lexemfile = FOPEN(lexemfilnam,"r") ; } }
	else {
	  if (modus >= 10) {
	    FILE* scratch=fopen(tbuffer,"w") ;
	    if (scratch == NULL) {
	      fprintf(errfile,"Cannot open %s\n",tbuffer) ;
	      goto ganz_am_ende; }
	    fprintf(scratch,"%s",(char*)filename) ;
	    fclose(scratch) ;
	    strcpy(xbuffer,tbuffer) ; }


#ifdef Windows
  			char r[8192] ;
   		FILE* ppoutfile ;
			if (nopreproc==0) {
			strcpy(temp,szProgramPath) ;
			strcat(temp,"hadifix.ppr") ;
			strcpy(buffer,szProgramPath) ;
			strcat(buffer,"hadifix.ppa") ;
			if (modus < 10)
			  PPInit((char*)filename,temp,buffer,ppindex) ;
			else
			  PPInit(tbuffer,temp,buffer,ppindex) ;

     		ppoutfile = fopen(ppfilnam,"w") ;
     		while (PPnextpart(r,8191,ppindex) != NULL) {
   			fprintf(ppoutfile,"%s",r) ; }
     		fclose(ppoutfile) ;
    		PPClose(ppindex) ;
  			if (modus < 10)
			  filename = ppfilnam ;
			else {
			  unlink(tbuffer) ;
			  strcpy(xbuffer,ppfilnam) ; } }

#else

			if (nopreproc==0) {
			strcpy(temp,szProgramPath) ;
			strcat(temp,"hadifix.ppr") ;
			strcpy(buffer,szProgramPath) ;
			strcat(buffer,"hadifix.ppa") ;
			if (modus < 10)
			  ppresult = PPmain(temp,buffer,(char*)filename,ppfilnam) ;
			else
			  ppresult = PPmain(temp,buffer,tbuffer,ppfilnam) ;

			if (ppresult == 0) {
			  if (modus < 10)
				filename = ppfilnam ;
			  else {
			if (modus >= 10)
			  unlink(tbuffer) ;
			strcpy(xbuffer,ppfilnam) ; } } }

#endif
		if (modus < 10) {
			lexemfile = vvv->next_input("",(char*)filename,piping,pid,lexemfilnam) ; }
		else {
			lexemfile = vvv->next_input("",xbuffer,piping,pid,lexemfilnam) ;
		} }


	if (lexemfile == NULL) {
if (debuglevel > 0) {
		fprintf(errfile,"LEXEMFILE NULL\n\n\n") ;
		fflush(errfile) ;
}
		error = 1 ;
		goto hinter_ganz_am_ende ; }


   modus %= 10 ;
	cnt_lexem=0 ;
	cnt_real_lexem = 0 ;
#ifndef ABSOLUTELY_NO_FILES
#ifdef UNIX
	transfile = FOPEN(strcat(strcpy(temp,pid),"hadi.tra"),"w") ;
#else
	transfile = FOPEN("hadi.tra", "w");
#endif
	fprintf(transfile, "%10ld\n", cnt_lexem);
	FCLOSE(transfile);
#else
#endif

#ifndef ABSOLUTELY_NO_FILES
#ifdef UNIX
	infi = new Infilehandler(strcat(strcpy(temp,pid),"hadi.phn")) ;
#else
	infi = new Infilehandler("hadi.phn") ;
#endif
#endif
	skip_it = 1 ;

#ifndef ABSOLUTELY_NO_FILES
#ifdef UNIX
	FCLOSE(FOPEN(strcat(strcpy(temp,pid),"hadi.phn"),"w")) ;
#else
	FCLOSE(FOPEN("hadi.phn","w")) ;
#endif
#endif
	rewind(lexemfile);



	if (wordnr != NULL) {
		*wordnr = 0 ; }
	while (1)
	{

	 
		while (skip_it--)

		{

#ifndef ABSOLUTELY_NO_FILES
#ifdef UNIX
			transfile = FOPEN(strcat(strcpy(temp,pid),"hadi.tra"),"a") ;
#else
			transfile = FOPEN("hadi.tra", "a");
#endif
			fseek(transfile,0L,SEEK_END) ;
			long start = ftell(transfile);
#else
			lexcount = 0 ;
			lexemlist = (char**)malloc(1) ;
#endif

if (debuglevel > 0) {
			fprintf(errfile,"\n\nOutput Transcription Module:\n\n") ;
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
					lexicon->transcribe(lexem,1);
					if (modus == 4 && lexem.Type() == TLexem::wordform) {
					  fwrite_lexem(outfile,lexem) ; }
					if (lexem.Type() == TLexem::wordform)
					  cnt_real_lexem++ ;
				if (lexem.Type() == TLexem::wordform && wordlist != NULL && wordnr != NULL) {
					wordlist[0] = (char**)realloc((void*)wordlist[0],(wordnr[0]+1) * sizeof(char*)) ;
					wordlist[0][wordnr[0]] = strdup(lexem.Chars().c_str()) ;
					(wordnr[0])++ ; }
				if (lexem.Type() == TLexem::comment) {
#ifndef NGIMMICKS
					if (strncmp(lexem.Chars().c_str(),"{Accent:",8) == 0) {
						if (dialect != NULL)
							delete(dialect) ;
						dialect = strdup(&(lexem.Chars().c_str())[8]) ;
						dialect[strlen(dialect)-1] = '\0' ;
						if (strcmp(dialect,"Hochdeutsch") == 0 || strcmp(dialect,"") == 0) {
							delete(dialect) ;
							dialect = NULL ; } }
#endif
#ifdef WINDAC
					if (strncmp(lexem.Chars().c_str(),"{Play:",6) == 0) {
						transcription = strdup(&(lexem.Chars().c_str())[6]) ;
						transcription[strlen(transcription)-1] = '\0' ;
						dac->play_file(transcription) ;
						delete (transcription) ;
						transcription = NULL ;  }
#endif
					if (strncmp(lexem.Chars().c_str(),"{Language:",10) == 0) {
				               	if (strncmp(&lexem.Chars().c_str()[10],"Englisch",8) == 0)
          				        	language = 1 ;
              				    	else
      					            	language = 0 	;
						fprintf(errfile,"Language changed to %d\n",language) ; }
					if (strncmp(lexem.Chars().c_str(),"{Transcription:",15) == 0) {
						transcription = strdup(&(lexem.Chars().c_str())[15]) ;
						transcription[strlen(transcription)-1] = '\0' ; }
					if (strncmp(lexem.Chars().c_str(),"{WordRhythm:",12) == 0) {
						rhythm = strdup(&(lexem.Chars().c_str())[12]) ;
						rhythm[strlen(rhythm)-1] = '\0' ; } }
#ifndef NGIMMICKS
				if (lexem.Type() == TLexem::wordform && dialect != NULL)
					make_dialect(lexem,dialect) ;
#endif
				if (lexem.Type() == TLexem::wordform && rhythm != NULL) {
					change_rhythm(lexem.transcription,rhythm) ;
					delete (rhythm) ;
					rhythm = NULL ; }
				if (lexem.Type() == TLexem::wordform && transcription != NULL) {
					sampa2ipa(lexem.transcription,transcription) ;
					delete (transcription) ;
					transcription = NULL ; }
if (debuglevel > 0) {
				fwrite_lexem(errfile,lexem) ;
				fflush(errfile) ;
}

#ifndef ABSOLUTELY_NO_FILES
				fprintf(errfile,"Hier soll man gar nicht sein\n") ;
				fflush(erfile) ;
				fwrite_lexem(transfile, lexem) ;
#else
				lexcount++ ;
				lexemlist = (char**)realloc(lexemlist,sizeof(char*)*lexcount) ;
				put_lexem(lexemlist,lexcount,lexem) ;

#endif

				}
				if (lexem.Type() == TLexem::point || lexem.Type() == TLexem::exclamation || lexem.Type() == TLexem::question)
					break;
			}

			if (lexemfile != NULL)
				alles_gelesen = feof(lexemfile);
			if (alles_gelesen && lexemfile != NULL) {
				FCLOSE(lexemfile) ;
				unlink(lexemfilnam) ;
				if (nopreproc == 0)
				  unlink(ppfilnam) ;
//            free(lexemfilnam) ;
				lexemfile = NULL ; }
//			rewind(transfile);
//			fprintf(transfile, "%10ld\n", cnt_lexem);
#ifndef ABSOLUTELY_NO_FILES
			FCLOSE(transfile);
#endif
			if (cnt_lexem > 1) {

#ifndef ABSOLUTELY_NO_FILES
#ifdef UNIX
				TFile trafile(strcat(strcpy(temp,pid),"hadi.tra"));
#else
				TFile trafile("hadi.tra");
#endif
				trafile.Open('t');

				trafile.SeekFromStart(start) ;

				TFile phnfile(trafile.Drive() + trafile.Path() + trafile.Name() + ".phn");


				prosogen(trafile, phnfile, cnt_lexem);

				infi->next_sentence() ;

#else
if (debuglevel > 0) {
				fprintf(errfile,"Building syllablelist\n") ;
            fflush(errfile) ;
}
				s = new Syllablelist() ;
				prosogenx(lexemlist,s, lexcount, (modus==3?outfile:(FILE*)NULL)) ;


#endif
				}

#ifdef ABSOLUTELY_NO_FILES
			for (int iii=0 ; iii < lexcount ; iii++)
				free(lexemlist[iii]) ;
			free(lexemlist) ;
#endif




		}
		skip_it = 1;
if (debuglevel > 0) {
	fprintf(errfile,"Linguistic part finished %ld %ld\n",cnt_lexem, cnt_real_lexem) ;
   fflush(errfile) ;
}



	if (Call != NULL)
		Call() ;
	if (finish)
		goto ganz_am_ende ;


	if (cnt_lexem == 0) {
	  if (s != NULL)
	    delete(s) ;
	  s = NULL ;
	  break ; }

	if (cnt_real_lexem == 0)
	  goto hinter_ganz_am_ende ;
//     if (cnt_lexem == 0)
//     	goto hinter_ganz_am_ende ;

	  if (modus == 3 || modus == 4) {
	    if (s != NULL)
	    delete(s) ;
	    s = NULL ; }
	  else { 
	    


#ifndef ABSOLUTELY_NO_FILES
			s = new Syllablelist(infi->get_infile()) ;
			infi->close() ;
#else
			if (s == NULL)
				break ;
#endif


			if (s->length() < 3) {
				delete(s) ;
				break ; }


			result = s->new_voice() ;

			if (result != NULL) {
if (debuglevel > 0) {
				fprintf(errfile,"Changing Voice %s %s\n",inventpath,result) ;
            fflush(errfile) ;
}
				strcpy(buffer,inventpath) ;
if (debuglevel > 0) {
				fprintf(errfile,"Changing Voice %s %s\n",buffer,result) ;
            fflush(errfile) ;
}
#ifdef _Windows
#ifdef WINDAC
				if (modus < 2)
					while (dac->running()) ;
#endif
if (debuglevel > 0) {
				fprintf(errfile,"%d\n",1-hnr) ;
            fflush(errfile) ;
}
				if(h[1-hnr] != NULL)
					delete(h[1-hnr]) ;
				h[1-hnr] = NULL ;
#endif
				talknow = 0 ;
if (debuglevel > 0) {
				fprintf(errfile,"Changing Voice %s %s\n",buffer,result) ;
            fflush(errfile) ;
}
				change_voice(buffer,result) ;
if (debuglevel > 0) {
				fprintf(errfile,"Voice changed\n") ;
            fflush(errfile) ;
}
			    talknow = 1 ; }

#ifndef NOTREE
			result = s->find_command("Tree") ;

			if (result != NULL) {
				delete(b) ;
				strcpy(treename,result) ;
if (debuglevel > 0) {
				fprintf(errfile,"Tree %s%s loaded\n",inventpath,result) ;
				fflush(errfile) ;
}
				b = new Baum(treename,inventpath,0,NULL) ;}
#endif


			soli = new Soundlist ;
			nulltest(soli) ;

                        result = s->find_command("UseCARTProminence") ;
                        if (result != NULL)
                           use_wagonprom = atoi(result) ;
			 
                        if (use_wagonprom == 1) {
                           s->wagonprom() ; }
			



			if (interpunction == 0)
				if (s->no_interpunction() == 0) {
					delete(s) ;
					delete(soli) ;
					continue ; }
			s->pauses() ;
			if (debuglevel > 1) {
			  fprintf(errfile,"Before Reduction\n") ; fflush(errfile) ; }
			reduction_level = s->reduce(reduction_level) ;
			if (debuglevel > 1) {
			  fprintf(errfile,"Before Intonation_Features\n") ; fflush(errfile) ; }
			s->compute_intonation_features() ;
if (debuglevel > 0) {
			fprintf(errfile,"\n\nOutput Syllable Module:\n\n") ;
			s->print(errfile) ;
			fflush(errfile) ;
}

			if (s->make_soundlist(soli) < 1) {
				error = 1 ;
				syndata_error("main","Lautliste kann nicht erstellt werden",2) ;
				continue ; }



			result = s->find_command("SynthesisMethod") ;
			if (result != NULL) {
				psola_method = atoi(result) ;
				if (psola_method < -1 || psola_method > 2) {
					syndata_error("main","Falsche Synthese-Methode",5) ;
						  psola_method = 0 ; } }

				result = s->find_command("DurationCorrection") ;
				if (result != NULL) {
						  psola_method %= 10 ;
						  psola_method += (atoi(result)+1) * 10 ; }




			result = s->find_command("Preemphasis") ;
			if (result != NULL) {
				preemp=atof(result) ;
				if (preemp < 0.0 || preemp > 1.0) {
					 preemp = 0.0 ; } }


			result = s->find_command("UseNet") ;
			if (result != NULL) {
				use_net = atoi(result) ; }
			result = s->find_command("RelpOffset") ;
			if (result != NULL) {
				relpdelay=atoi(result) ;
				if (relpdelay < 0 || relpdelay > 50) {
					 relpdelay = 0 ; } }

			result = NULL ;
#ifndef NO_FILES
			result = s->find_command("DBS") ;
			if (result == NULL)
#ifdef UNIX
				xbs = FOPEN(strcat(strcpy(temp,pid),"xbs.lst"),"w+") ;
#else
				xbs = FOPEN("xbs.lst","w+") ;
#endif
			else
				xbs = FOPEN(result,"r") ;


#ifdef UNIX
			kbs = FOPEN(strcat(strcpy(temp,pid),"kbs.lst"),"w+") ;
#else
			kbs = FOPEN("kbs.lst","w+") ;
#endif


#endif        // NO FILES





			if (n->build(s,soli) < 1 && result == NULL) {

if (debuglevel > 0) {
				fprintf(errfile,"\n\nOutput Prosody Preparation Module:\n\n") ;
				n->list_DBS(errfile) ;
				fflush(errfile) ;
}


#ifndef NO_FILES
				n->list_DBS(xbs) ; }
#else

				dbs = n->get_DBS() ; }
#endif




#ifndef NO_FILES

#ifndef NOTREE

			if (b->compute_from_file_to_file(xbs,kbs) == 0) {
if (debuglevel > 0) {
				syndata_error("main","Baum konnte nicht berechnet werden.",2) ;
}
				FCLOSE(kbs) ;
				kbs = NULL ; }
#else
			FCLOSE(kbs) ;
			kbs = NULL ;
#endif

#else
#ifndef NOTREE

			p = new Proslist() ;

         if (b->compute_from_list_to_list(dbs,p) == 0) {
if (debuglevel > 0) {
				syndata_error("main","Baum konnte nicht berechnet werden.",2) ;
}
				delete(p) ;
            p = NULL ; }

#endif


#endif 		// NO_FILES

if (debuglevel > 1) {
				fprintf(errfile,"Syllable duration computed\n") ;
				fflush(errfile) ;
}
#undef NN
#ifdef NN
			if (use_net == 1) {
#ifdef UNIX
				nnfile = FOPEN(strcat(strcpy(temp,pid),"nnin.dat"),"w+") ;
#else
				nnfile = FOPEN("nnin.dat","w+") ;
#endif
				if (kbs != NULL)
					FCLOSE(kbs) ;
#ifdef UNIX
				kbs = FOPEN(strcat(strcpy(temp,pid),"kbs.lst"),"w+") ;
#else
				kbs = FOPEN("kbs.lst","w+") ;
#endif
				fprintf(errfile,"using the net for prosody prediction\n") ;
				fflush(errfile) ;
				rewind(xbs) ;
				transhin(xbs,nnfile) ;
				FCLOSE(nnfile) ;
				FCLOSE(xbs) ;
				fprintf(errfile,"NET USES %s AS DEFINITION, %s AS INPUT AND %s AS OUTPUT\n",In_File,Dat_File,Rec_File) ;

				ErrorCode = DFile->OpenNetDataFile(Dat_File) ;
				if (ErrorCode != 0)
					fprintf(errfile,"NetError %d at DF->ONDF\n",ErrorCode) ;

				ErrorCode = RFile->SetRecallParameters(Rec_File,NNetz,DFile,"#") ;
				if (ErrorCode != 0)
					fprintf(errfile,"NetError %d at RF->SRP\n",ErrorCode) ;

				ErrorCode = RFile->NetzRecall() ;
				if (ErrorCode != 0)
					fprintf(errfile,"NetError %d at RF->NR\n",ErrorCode) ;

				ErrorCode = DFile->CloseNetDataFile() ;
				if (ErrorCode != 0)
					fprintf(errfile,"NetError %d at DF->CNDF\n",ErrorCode) ;
#ifdef UNIX
				nnout = FOPEN(strcat(strcpy(temp,pid),"nnout.dat"),"r") ;
#else
				nnout = FOPEN("nnout.dat","r") ;
#endif
				rewind(kbs) ;
				transbak(nnout,kbs) ;
				rewind(kbs) ;
				FCLOSE(nnout) ; }
#endif


#ifndef NO_FILES
#ifdef DURNETNAME
			if (kbs != NULL)
				FCLOSE(kbs) ;
#ifdef UNIX
			kbs = FOPEN(strcat(strcpy(temp,pid),"kbs.lst"),"w+") ;
#else
			kbs = FOPEN("kbs.lst","w+") ;
#endif
			rewind(xbs) ;
			durnet->compute(xbs,kbs,(nefu)DURNETNAME) ;
#endif

#else		// NO_FILES

#ifdef DURNETNAME
			durnet->compute(n,proslist,(nefu)DURNETNAME) ;
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

			if (d->compute_duration(*s,soli,kbs,0L) < 1) {
#else
#ifdef PHONDURNET
			if (d->compute_duration(*s,soli,NULL,0L,p,use_net,phondurnet,dbs) < 1) {
#else
			if (d->compute_duration(*s,soli,NULL,0L,p) < 1) {
#endif			  
#endif

//#endif
				error = 1 ;
				syndata_error("main","Silbendauer kann nicht erstellt werden",2) ;
				continue ; }



if (debuglevel > 1) {
			fprintf(errfile,"Duration computed\n") ;
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
			kbs = FOPEN(strcat(strcpy(temp,pid),"kbs.lst"),"w+") ;
#else
			kbs = FOPEN("kbs.lst","w+") ;
#endif
			rewind(xbs) ;
			intnet->compute(xbs,kbs,(nefu)INTNETNAME) ;
			onlystress = 1 ;
#endif




			if (i->compute_f0(*s,soli,modus,kbs,0L,pid,onlystress) < 1) {
#else
#ifdef INTNETNAME
			intnet->compute(n,p,(nefu)INTNETNAME) ;
#endif
			
			if (i->compute_f0(*s,soli,modus,NULL,0L,pid,onlystress,p) < 1) {
#endif
				error = 1 ;
				syndata_error("main","Intonation kann nicht erstellt werden",2) ;
				continue ; }

#ifndef NO_FILES
			if (kbs != NULL)
				FCLOSE(kbs) ;

			FCLOSE(xbs) ;
#endif

if (debuglevel > 1) {
			fprintf(errfile,"Intonation computed\n") ;
			fflush(errfile) ;
}



			if (a->compute_intensities(soli) < 1) {
				error = 1 ;
				syndata_error("main","Intensities kann nicht erstellt werden",2) ;
				continue ; }

if (debuglevel > 1) {
			fprintf(errfile,"Intensities computed\n") ;
			fflush(errfile) ;
}


			if (p != NULL) {
				delete(p) ;
				p = NULL ; }

			i->clear() ;
			n->clear() ;


			//			delete(soli) ;
			//			delete(s) ;
			//			break ;

modus5:

			if (modus == 5) {
				delete(vvv) ;
				vvv = NULL ;
				infi = NULL ;
				soli = new Soundlist ;
				nulltest(soli) ;
				if (filename[0] == '-')
					solifile = stdin ;
				else
					solifile = FOPEN((char*)filename,"r") ;
				soli->input(solifile) ; }


			/*
if (debuglevel > 1) {
			fprintf(errfile,"Clearing Soundlist\n") ;
			fflush(errfile) ;
}
			soli->clear_zero_dur() ;
if (debuglevel > 1) {
			fprintf(errfile,"ZeroDuration\n") ;
			fflush(errfile) ;
}

			soli->clear_doubles() ;
if (debuglevel > 1) {
			fprintf(errfile,"DoubleSounds\n") ;
			fflush(errfile) ;
}
			*/
#ifdef DEBUG3
			soli->printf0(f0fil) ;
#endif

			if (Call != NULL)
				Call() ;

			if (finish) {
				delete(soli) ;
				delete(s) ;
				goto ganz_am_ende ; }

#ifdef UNIX
			if (modus == 7) {
				solifile = outfile ;
				soli->print(solifile) ;
				if (s != NULL)
					delete(s) ;
				s = NULL ;
				if (soli != NULL)
					delete(soli) ;
				soli = NULL ;
				continue ; }
#endif

			if (nlabfile != NULL)
			        s->printkalle(soli,nlabfile) ;

#ifdef UNIX
			if (rvfilename != NULL) {
				rvfile = fopen(rvfilename,"w") ;
				s->printretivox(soli,rvfile) ;
				fclose(rvfile) ; }
#endif


			if (modus == 8) {
#ifdef UNIX
				s->printmbrola(soli,outfile,impbuffer) ;
#else
				if (outfile == NULL) {
			            	fprintf(errfile,"OUTFILE NULL\n") ;
               				fflush(errfile) ;
               				continue ; }
				soli->printmbrola(outfile,impbuffer) ;
#endif
				if (s != NULL)
					delete(s) ;
				s = NULL ;
				if (soli != NULL)
					delete(soli) ;
				soli = NULL ;
				continue ; }



			u = new Unitlist() ;
			nulltest(u) ;
			dd = new Duration(sf) ;
			nulltest(dd) ;


			if (u->build(soli,*invent) < 1) {
				error = 1 ;
				syndata_error("main","Bausteinliste kann nicht erstellt werden",2) ;
				continue ; }

#ifndef NO_FILES
			if (modus == 2)
#ifdef UNIX
				solifile = FOPEN(strcat(strcpy(temp,pid),"hadi.sol"),"r") ;
#else
				solifile = FOPEN("hadi.sol","r") ;
#endif
			else
#ifdef UNIX
				solifile = FOPEN(strcat(strcpy(temp,pid),"hadi.sol"),"w") ;
#else
				solifile = FOPEN("hadi.sol","w+") ;
#endif
#ifdef SOLILIST
			if (solifile != NULL)
				FCLOSE(solifile) ;
			solifile = FOPEN("sounds.lst","w") ;
#endif

			if (solifile != NULL) {
				if (modus == 2) {
					soli->input_prosody(solifile) ; }
				else
					soli->print(solifile) ;
				FCLOSE(solifile) ; }
#endif		// NO_FILES


if (debuglevel > 0) {
			fprintf(errfile,"\n\nOutput Sound Prosody Module:\n\n") ;
			soli->print(errfile) ;
			fprintf(errfile,"\n\nOutput Unit Selection Module:\n\n") ;
			u->print(errfile) ;
			fflush(errfile) ;
}


#ifndef NGIMMICKS
			if (modus != 5) {
			result = s->find_command("Optimize") ;
			if (result != NULL) {
				strcpy(optimethod,result) ; }
			if (strlen(optimethod) > 1) {
				fprintf(errfile,"Optimethod: %s\n",optimethod) ;
				fflush(errfile) ;
				u->optimize(soli,*invent,optimethod) ; } }
#endif
			u->reset() ;

			if (modus != 5) {
			result = s->find_command("DiphoneOffset") ;
			if (result != NULL)
				position = atof(result) ; }

     		if (modus != 5 && s != NULL)
				delete(s) ;
         s = NULL ;

			if (debuglevel > 2) {
			  fprintf(errfile,"Generating M- and PLists\n") ;
			  fflush(errfile) ; }


			ml = new Marklist() ;
			nulltest(ml) ;
			pl = new Periodlist() ;
			nulltest(pl) ;

#ifdef _Windows
			h[hnr] = new HugeArray<DATYPE>(sf*2*d->get_total_length()) ;
#endif

			if (debuglevel > 2) {
			  fprintf(errfile,"Input duration starting\n") ;
			  fflush(errfile) ; }

			dd->input_duration(soli) ;

			if (debuglevel > 2) {
			  fprintf(errfile,"Input duration finished\n") ;
			  fflush(errfile) ; }

			sigpos = 0L ;
			lastsigpos = sigpos ;
			lastlastsigpos = lastsigpos ;
			ssmm.get_next_mark_and_pm(*invent,u,soli,*pl,*ml,sigpos,position) ;
			lastsigpos = sigpos ;
			ssmm.get_next_mark_and_pm(*invent,u,soli,*pl,*ml,sigpos,position) ;
			lsigpos = sigpos ;

			reset = 1 ;
			lastpl = 1 ;
			lastlastpl = 1 ;

			if (debuglevel > 2) {
			  fprintf(errfile,"Starting Main Loop\n") ;
			  fflush(errfile) ; }

			while (ssmm.get_next_mark_and_pm(*invent,u,soli,*pl,*ml,sigpos,position) > 0) {


if (debuglevel > 1) {
				fprintf(errfile,"VOR WSD\n") ;
            fflush(errfile) ;
}

				dd->write_sentence_duration(*pl,*ml,lastlastsigpos,lastsigpos,nmrkfile) ;

if (debuglevel > 1) {
				fprintf(errfile,"NACH WSD\n") ;
            fflush(errfile) ;
}

				if (Call != NULL)
					Call() ;
				if (finish) {
				        delete(dd) ;
					delete(u) ;
					delete(soli) ;
					delete(pl) ;
					delete(ml) ;
#ifdef _Windows
					delete(h[hnr]) ;
#endif
					goto ganz_am_ende ; }

if (debuglevel > 4 ) {
  ml->print(errfile) ; fflush(errfile) ; }
 if (debuglevel > 7) {			
	pl->print(errfile);  fflush(errfile)  ;
}
				ml->reset() ;
				pl->reset() ;


				preset = reset ;
				sigpart = ssmm.get_next_signal_part(*invent,*pl,*ml,&siglen,preset) ;
	    ml->reset() ;
#ifdef _Windows
				lastpl = ssmm.psola(h[hnr], sigpart,siglen,*pl,lastpl,*ml,synfile,nperfile,nmrk2file,reset,invent->get_sf(),dares,mulaw,danow,filetype,psola_method,preemp,lpc_grade,mu,relpdelay) ;
#else
				lastpl = ssmm.psola(NULL,sigpart,siglen,*pl,lastpl,*ml,outfile,nperfile,nmrk2file,reset,invent->get_sf(),dares,mulaw,danow,filetype,psola_method,preemp,lpc_grade,mu,relpdelay) ;
#endif

			if (reset != 1) {
					ml->reset() ;
					m = ml->get() ;
					do
						m = ml->exclude_and_advance_and_get() ;
					while (strcmp(m.key,"---") != 0) ;
					ml->exclude_and_advance_and_get() ; }
				reset = 0 ;
				j = lastlastpl ;
				pl->reset() ;
				while (++j < lastpl)
					pl->exclude_and_advance_and_get() ;
				lastlastpl = lastpl ;
				lastlastsigpos = lastsigpos ;
				lastsigpos = lsigpos ;
				lsigpos = sigpos ;

				if (preset)
					preset = 0 ; }


			dd->write_sentence_duration(*pl,*ml,lastlastsigpos,lastsigpos,nmrkfile) ;
			ml->reset() ;
			sigpart = ssmm.get_next_signal_part(*invent,*pl,*ml,&siglen,reset) ;
			preset = 0 ;
	 ml->reset() ;


#ifdef _Windows
			lastpl = ssmm.psola(h[hnr],sigpart,siglen,*pl,lastpl,*ml,synfile,nperfile,nmrk2file,preset,invent->get_sf(),dares,mulaw,danow,filetype,psola_method,preemp,lpc_grade,mu,relpdelay) ;
#else
			lastpl = ssmm.psola(NULL,sigpart,siglen,*pl,lastpl,*ml,outfile,nperfile,nmrk2file,preset,invent->get_sf(),dares,mulaw,danow,filetype,psola_method,preemp,lpc_grade,mu,relpdelay) ;
#endif
			ml->reset() ;
			m = ml->get() ;
			do
				m = ml->exclude_and_advance_and_get() ;
			while (strcmp(m.key,"---") != 0) ;
			ml->exclude_and_advance_and_get() ;
			lastlastsigpos = lastsigpos ;
			lastsigpos = sigpos ;

			dd->write_sentence_duration(*pl,*ml,lastlastsigpos,lastsigpos,nmrkfile) ;
			ml->reset() ;
			sigpart = ssmm.get_next_signal_part(*invent,*pl,*ml,&siglen,reset) ;
			preset = 0 ;
	 ml->reset() ;





#ifdef _Windows
			lastpl = ssmm.psola(h[hnr],sigpart,siglen,*pl,lastpl,*ml,synfile,nperfile,nmrk2file,preset,invent->get_sf(),dares,mulaw,danow,filetype,psola_method,preemp,lpc_grade,mu,relpdelay) ;
#else
			lastpl = ssmm.psola(NULL,sigpart,siglen,*pl,lastpl,*ml,outfile,nperfile,nmrk2file,preset,invent->get_sf(),dares,mulaw,danow,filetype,psola_method,preemp,lpc_grade,mu,relpdelay) ;
#endif
			ml->reset() ;
			m = ml->get() ;
			do
				m = ml->exclude_and_advance_and_get() ;
			while (strcmp(m.key,"---") != 0) ;
			ml->exclude_and_advance_and_get() ;


			delete(pl) ;
			delete(ml) ;


#ifdef _Windows


			if (danow > 0) {
#ifdef WINDAC
				while (dac->running())
					if (Call != NULL)
						Call() ;
				while (stop) {
					if (Call != NULL)
						Call() ; }
#endif
			if (finish) {
				delete(soli) ;
				delete(u) ;
				goto ganz_am_ende ; }

#ifdef NPR
				dac->write_voc_header(outfile,(long)invent->get_sf()) ;
				h[hnr]->Dump(outfile) ;
#endif
#ifdef WINDAC
				fprintf(errfile,"Playing %d\n",dac->play_data((char*)h[hnr]->Lock(),h[hnr]->Used()*sizeof(DATYPE))) ;				}
#else
				}
#endif
			else
				h[hnr]->Dump(outfile) ;


			hnr = 1-hnr ;
			if (h[hnr] != NULL)
				delete(h[hnr]) ;
			h[hnr] = NULL ;
#endif

			if (u != NULL)
				delete(u) ;
			u = NULL ;
			if (dd != NULL)
				delete(dd) ;
			dd = NULL ;
			if (soli != NULL)
				delete(soli) ;
			soli = NULL ; }
			if (modus == 5)
			  break ; }



			if (piping){
			  if (infi != NULL)
			    delete(infi) ;
			  infi = NULL ; }
	}
	while (piping) ;
	goto hinter_ganz_am_ende ;

ganz_am_ende:

#ifdef WINDAC
  	if (dac->running())
		dac->stop() ;
#endif

hinter_ganz_am_ende :

   fflush(errfile) ;
	if (infi != NULL)
		delete(infi) ;
   fflush(errfile) ;
	if (danow == 0 && filetype==1) {
		dac->close(outfile) ; }
	else if (danow == 0 && filetype==2)
		dac->close_au(outfile) ;
	else if (danow == 0 && filetype == 3)
			dac->close_voc(outfile) ;
	else
#ifdef UNIX
			if (outfile != stdout)
#endif
	if (outfile != NULL)
		FCLOSE(outfile) ;
	if (modus != 5 && dialect != NULL)
		delete(dialect) ;
	if (modus != 5 && lexemfile != NULL) {
		FCLOSE(lexemfile) ;
		unlink(lexemfilnam) ;
		if (nopreproc == 0)
			unlink(ppfilnam) ;
		}
	unlink(ppfilnam) ;
	//	free(ppfilnam) ;
	unlink(lexemfilnam) ;
	//	free(lexemfilnam) ;
	//	lexemfilnam = NULL ;


#ifdef NPR
		FCLOSE(nmrk2file) ;
		FCLOSE(nmrkfile) ;
		FCLOSE(nperfile) ;
#endif
#ifdef _Windows
		if (danow == 1)
#ifdef WINDAC
		  while (dac->running()) {
			if (Call != NULL)
				Call() ;
			if (finish == 1) {
				dac->stop() ;
                                break ; } }
#endif
		if(h[1-hnr] != NULL)
			delete(h[1-hnr]) ;
		if (impbuffer != NULL)
			delete(impbuffer) ;
#endif
		talknow = 0 ;
		if (danow > 0 || filetype > 0)
			delete(dac) ;
		finish = 0 ;
		return(error) ; }


Synthese::~Synthese() {

  char temp[256] ;

	fprintf(errfile,"Starting to delete Hadifix\n") ;
   fflush(errfile) ;
	delete(env) ;
#ifdef UNIX
        if (rcenv != NULL)
	  delete(rcenv) ;
#endif
	delete[](inventname) ;
	delete[](inventpath) ;
	if (tx2ph == 0)
	  delete(invent) ;
#ifndef NOTREE
	delete(b) ;
#endif
	delete(n) ;
	delete(a) ;
	delete(d) ;
	delete(i) ;
	fprintf(errfile,"Starting to delete the Lexicon\n") ;
   fflush(errfile) ;

	delete(lexicon) ;
	delete(vvv) ;

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
if (debuglevel > 0) {
	fprintf(errfile,"END OF SYNTHESIS\n_______________________________________________________\n") ;
	fflush(errfile) ;
}
#ifdef DEBUG3
	fclose(f0fil) ;
#endif

	fprintf(errfile,"Leaving HADIFIX %d\n",instcnt) ;
	fflush(errfile) ;
#ifndef UNIX
	instcnt-- ;
   if (instcnt == 0) {
		fclose(errfile) ;
		unlink(fnamtmp) ; }
	if (instcnt == 0 && debuglevel > 2) {
   	debugstr.close() ;
		unlink(jnamtmp) ; }
#else
	strcat(strcpy(temp,pid),".hadi.log") ;

	if (debuglevel == 0)
	  unlink(temp) ;
#endif
#ifdef UNIX
	if (debuglevel > 2)
	  debugstr.close() ;
#endif
#ifdef Windows
	strcat(strcpy(temp,temppath),"\\preproc.log") ;
	unlink(temp) ;
#endif
}




