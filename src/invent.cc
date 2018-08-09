             
#include "lisatalk.h"
#if !defined(__INVENT_H__)
#include "invent.h"
#endif

#ifdef UNIX
#ifndef SUN
#include<sys/stat.h>
#include<sys/time.h>
#endif
#endif

//#define DEBUG2

const int MAX_UNITS=5000 ;

int method ;
char* invp ;
short bt2(short inval) {
	short outval = inval ;
	char* point = (char*)&outval ;
	char buff ;
	buff = point[0] ;
	point[0] = point[1] ;
	point[1] = buff ;
	return(outval) ; }

long bt4(long inval) {
	long outval = inval ;
	char* point = (char*)&outval ;
	char buff[2] ;
	buff[0] = point[0] ;
	buff[1] = point[1] ;
	point[0] = point[3] ;
	point[1] = point[2] ;
	point[2] = buff[1] ;
	point[3] = buff[0] ;
	return(outval) ; }


void inventory_error(char* origin, char* message, int level) {
if (debuglevel > 0) {
	fprintf(errfile,"Error during inventory handling (%s) : %s\n",origin,message) ;
	fflush(errfile) ;
//	switch (level) {
//		case 0:
//		case 1: exit(1) ; } 
}
	}


char* invpath(char* s, char* invp) {
	return(strcat(strcpy(new char[80],invp),s)) ; } ;


Signal::~Signal() { ; }

long Signal::get_signal_length() {
	return(length) ; }

Timesignal::Timesignal(FILE* sigfile, long start, long len, int mulw) {
	if (mulw)
		startpoint = start / 2L ;
	else
		startpoint = start ;
	mulaw = mulw ;
   fil = sigfile ;
   length = len; }

inline Timesignal::~Timesignal() { ;}

Relpsignal::Relpsignal(FILE* sigfile, long start, int number, char* ipath) {
	fil = sigfile ;
	char dummy[24] ;
	fread(dummy,24,1,sigfile) ;
	char dummy4[4] ;
#ifdef SUN
	memcpy(dummy4,&dummy[0],4) ;
	grade = (int)bt4(*(long*)(dummy4)) ;
	memcpy(dummy4,&dummy[4],4) ;
	mu = bt4(*(float*)(dummy4)) ;
#else
	memcpy(dummy4,&dummy[0],4) ;
	grade = (int)(*(long*)(dummy4)) ;
	memcpy(dummy4,&dummy[4],4) ;
	mu = (*(float*)(dummy4)) ;
#endif
	residualname = new char[strlen(ipath)+20] ;
	strcpy(residualname,ipath) ;
	strcat(residualname,&dummy[12]) ;
	startpoint = start ;
	length = number ; }

Relpsignal::~Relpsignal() {
	delete(residualname) ; }				


static int ulaw_table[128] = {
	 32124,  31100,  30076,  29052,  28028,  27004,  25980,  24956,
	 23932,  22908,  21884,  20860,  19836,  18812,  17788,  16764,
	 15996,  15484,  14972,  14460,  13948,  13436,  12924,  12412,
	 11900,  11388,  10876,  10364,   9852,   9340,   8828,   8316,
	  7932,   7676,   7420,   7164,   6908,   6652,   6396,   6140,
	  5884,   5628,   5372,   5116,   4860,   4604,   4348,   4092,
	  3900,   3772,   3644,   3516,   3388,   3260,   3132,   3004,
	  2876,   2748,   2620,   2492,   2364,   2236,   2108,   1980,
	  1884,   1820,   1756,   1692,   1628,   1564,   1500,   1436,
      1372,   1308,   1244,   1180,   1116,   1052,    988,    924,
       876,    844,    812,    780,    748,    716,    684,    652,
	   620,    588,    556,    524,    492,    460,    428,    396,
       372,    356,    340,    324,    308,    292,    276,    260,
       244,    228,    212,    196,    180,    164,    148,    132,
       120,    112,    104,     96,     88,     80,     72,     64,
        56,     48,     40,     32,     24,     16,      8,      0 };


short* Timesignal::get_signal(long leftborder, long rightborder) {
	if (leftborder < 0 || rightborder > length || leftborder >= rightborder) {
		inventory_error("Timesignal_get_signal","leftborder or rightborder wrong value",2) ;
		return(NULL) ; }
	unsigned char* mulawsigpart = new unsigned char[rightborder-leftborder+1] ;
	short* sigpart = new short[rightborder-leftborder+1] ;
	nulltest(sigpart) ;
	nulltest(mulawsigpart) ;
	if (mulaw) {
		fseek(fil,startpoint+(leftborder),SEEK_SET) ;
		fread(mulawsigpart,1,(rightborder-leftborder+1),fil) ;
		for (int i = 0 ; i < (rightborder-leftborder+1); i++) {
			sigpart[i] = ulaw_table[mulawsigpart[i] & 0x7f] ;
			if ((mulawsigpart[i] & 0x80) == 0)
				sigpart[i] = -sigpart[i] ; } }
	else {
		fseek(fil,startpoint+(leftborder*2L),SEEK_SET) ;
		fread(sigpart,2,(rightborder-leftborder+1),fil) ;
#ifdef SUN
		for (int i = 0 ; i < rightborder-leftborder+1; i++) {
			sigpart[i] = bt2(sigpart[i]) ; } }
#else
			}
#endif


	delete[](mulawsigpart) ;
	return(sigpart) ; }

LPC_Frame* Relpsignal::get_signal(long leftborder, long rightborder, int& number) {
	if (leftborder < 0 || rightborder > length || leftborder >= rightborder) {
		inventory_error("Relpsignal_get_signal","leftborder or rightborder wrong value",2) ;
		return(NULL) ; }
	LPC_Frame* result = (LPC_Frame*)malloc(sizeof(LPC_Frame)) ; 
	char* dummy = new char[4+4+4*grade] ;
	char dummy4[4] ;
	fseek(fil,startpoint,SEEK_SET) ;
	long aktlen = 0L ;
	long respos ;
	FILE* resfile = fopen(residualname,"rb") ;
	while (aktlen < leftborder) {
		fread(dummy,1,44,fil) ;
#ifdef SUN
		memcpy(dummy4,&dummy[0],4) ;
		aktlen += bt4(*(long*)(dummy4)) ;
#else
		memcpy(dummy4,&dummy[0],4) ;
		aktlen += (*(long*)(dummy4)) ;
#endif	
		}
	number = 0 ;
	do {
#ifdef SUN
		memcpy(dummy4,&dummy[0],4) ;
		result[number].length = bt4(*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[4],4) ;
		respos = bt4(*(long*)(dummy4)) ;
#else
		memcpy(dummy4,&dummy[0],4) ;
		result[number].length = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[4],4) ;
		respos = (*(long*)(dummy4)) ;
#endif	
		result[number].grade = grade ;
		result[number].mu = mu ;
		result[number].type = 0 ;
		result[number].amplitude = 0.0 ;
		result[number].rc = new float[grade] ;
		result[number].residual = new short[result[number].length] ;
		fseek(resfile,respos,SEEK_SET) ;
		fread(result[number].residual,2,result[number].length,resfile) ;		
#ifdef SUN
                unsigned int i ;
		for (i = 0 ; i < result[number].length; i++) {
			result[number].residual[i] = bt2(result[number].residual[i]) ; }
#endif
		memcpy(result[number].rc,&dummy[8],4*result[number].grade) ;		
#ifdef SUN
		for (i = 0 ; i < result[number].grade; i++) {
			result[number].rc[i] = bt4(result[number].rc[i]) ; } 
#endif
		aktlen += result[number].length ;
		number++ ;
		result = (LPC_Frame*)realloc(result,sizeof(LPC_Frame)*number) ; }
	while (aktlen < rightborder) ;
	fclose(resfile) ;
	delete(dummy) ;
	return(result) ; }


short hash(char* name, short hashtablesize) {
	static short list[11] = { 17,3,23,29,31,37,41,43,47,53,59 } ;
	unsigned long sum = 1 ;
	for (unsigned int i = 0 ; i < strlen(name) ; i++)
		sum += (name[i]-32)*(list[i>10?10:i]) ;
	sum %= (unsigned long)hashtablesize ;
	return(short(sum)) ; }


Unitindexlist::Unitindexlist(char* indexfilename,Inventoryinfo& header, char*hashfilename) {
	strcpy(errorvalue.name,"") ;
	errorvalue.type = 'x' ;
	char dummy[60] ;
	char dummy4[4] ;


#ifdef UNIX
#ifndef SUN
        struct stat stst ;
        time_t lastmod ;
#endif
#endif

	freehashtableentries = NULL ;

	FILE* hashfile ;
	hashfile = FOPEN(hashfilename,"rb") ;
	if (hashfile == NULL) {
		fprintf(errfile,"CANNOT OPEN %s\n",hashfilename) ;
#ifdef SUN
		return ; }
#else
           	build_hashtable(indexfilename,hashfilename) ;
           	hashfile = FOPEN(hashfilename,"rb") ; }
#endif
#ifdef UNIX
#ifndef SUN

        if (stat(hashfilename,&stst),lastmod = stst.st_mtime, stat(indexfilename,&stst), lastmod < stst.st_mtime) {
           fclose(hashfile) ;
           if (build_hashtable(indexfilename,hashfilename) == -1)
	     return ;
           hashfile = FOPEN(hashfilename,"rb") ; }

#endif
#endif

	fseek(hashfile,0L,SEEK_END) ;
	int freehashtablenr = (ftell(hashfile)-1) / 2 ;
	freehashtableentries = new short[freehashtablenr] ;
	rewind(hashfile) ;
	fread(&hashtablesize,2,1,hashfile) ;
#ifdef SUN
	hashtablesize = bt2(hashtablesize) ;
#endif
	if (debuglevel > 1) {
		fprintf(errfile,"%d %d\n",hashtablesize, freehashtablenr) ;
      fflush(errfile) ; }
	fread(freehashtableentries,sizeof(short),freehashtablenr,hashfile) ;
	FCLOSE(hashfile) ;
#ifdef SUN
	for (int i = 0 ; i < freehashtablenr; i++)
		freehashtableentries[i] = bt2(freehashtableentries[i]) ;
#endif
	if (debuglevel > 10) {
	for (int i = 0 ; i < freehashtablenr; i++)
		fprintf(errfile,"%d ",freehashtableentries[i]) ;
	fprintf(errfile,"\n") ; fflush(errfile) ; }

	int i,j ;
	hashtable = new Hashtableentry[hashtablesize] ;
	nulltest(hashtable) ;

	for (i = 0 ; i < hashtablesize ; i++) {
		hashtable[i].pointer = NULL ;
		hashtable[i].collision = -1 ; }
	FILE* indexfile = FOPEN(indexfilename,"rb") ;
	Unitindex* inf ;
	if (indexfile == NULL) {
		inventory_error("Unitindexlist_constructor","cannot open indexfile",1) ;
		return ; }
	fread(dummy,1,14,indexfile) ;
        memcpy(invheader,dummy,14) ;
	memcpy(header.name,dummy,10) ;
	header.bytes = 16 ;
	if(dummy[11] == (int)2)
		header.voice = (int)dummy[11] ;
	else
		header.voice = 1 ;
	method = header.voice ;
#ifdef SUN
	header.sampling_frequency = bt2(*(short*)(&dummy[12])) ;
#else
	header.sampling_frequency = *((short*)(&dummy[12])) ;
#endif
	if (header.sampling_frequency > 1000)
		header.sampling_frequency /= 1000 ;
	i = 0 ;
	int maxcol = 0 ;

	while (!feof(indexfile)) {
		inf = new Unitindex ;
		nulltest(inf) ;
		if (fread(dummy,1,31,indexfile) < 31)  {
      	delete(inf) ;
      	break ; }
		memcpy(inf->name,dummy,7) ;
		j = (int)hash(inf->name,hashtablesize) ;
		inf->type = dummy[10] ;

if (debuglevel > 10) {
fprintf(errfile,"%s %c %d\n",inf->name,inf->type,j) ; fflush(errfile) ; }


#ifdef SUN
		memcpy(dummy4,&dummy[11],4) ;
		inf->signal_start = bt4(*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[15],4) ;
		inf->signal_length = bt4(*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[19],4) ;
		inf->period_start = bt4(*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[23],4) ;
		inf->period_length = bt2(*(short*)(dummy4)) ;
		memcpy(dummy4,&dummy[25],4) ;
		inf->marker_start = bt4(*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[29],4) ;
		inf->marker_length = bt2(*(short*)(dummy4)) ;
#else
		memcpy(dummy4,&dummy[11],4) ;
		inf->signal_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[15],4) ;
		inf->signal_length = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[19],4) ;
		inf->period_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[23],4) ;
		inf->period_length = (*(short*)(dummy4)) ;
		memcpy(dummy4,&dummy[25],4) ;
		inf->marker_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[29],4) ;
		inf->marker_length = (*(short*)(dummy4)) ;
#endif
//		j = hash(inf->name,hashtablesize) ;
		while (hashtable[j].pointer != NULL) {
			if (hashtable[j].collision == -1) {
         	if (debuglevel>10) {
				fprintf(errfile,"MAXCOL %d %d\n",maxcol,freehashtableentries[maxcol]) ; fflush(errfile) ; }
				hashtable[j].collision = freehashtableentries[maxcol] ;

				j = freehashtableentries[maxcol++] ;
				break ; }
			j = hashtable[j].collision ; }
		hashtable[j].pointer = inf ; }
	if (debuglevel > 10) {
	for (i=0 ; i < hashtablesize ; i++) {
   	if (hashtable[i].pointer == NULL)
      	fprintf(errfile,"%4d   NULL\n",i) ;
      else
			fprintf(errfile,"%4d  %5d - %s %c\n",i,hashtable[i].collision,hashtable[i].pointer->name,hashtable[i].pointer->type) ; } }
	FCLOSE(indexfile) ; }



Unitindexlist::~Unitindexlist() {
	int i ;

   if (debuglevel > 10) {
   	fprintf(errfile,"Starting to delete Unitindexlist\n") ; fflush(errfile) ; }

	if (freehashtableentries != NULL) {
          delete[](freehashtableentries) ;
          for (i = 0 ; i < hashtablesize ; i++)  {
				if (hashtable[i].pointer != NULL) {
					delete(hashtable[i].pointer) ;
               hashtable[i].pointer = NULL ; } }
          delete[](hashtable) ; }
   if (debuglevel > 10) {
   	fprintf(errfile,"Unitindexlist deleted\n") ; fflush(errfile) ; }

          }

int Unitindexlist::build_hashtable(char* iname, char* hname) {
        Unitindex i[MAX_UNITS] ;

        int unitnr = 0 ;
        char dummy[40] ;
        char dummy4[4] ;

        FILE* indexfile= fopen(iname,"rb") ;
        if (indexfile == NULL) {
          fprintf(errfile,"Error: Cannot Open %s for Reading\n",iname) ;
	  return(-1) ; }
	fread(dummy,1,14,indexfile) ;
	while (!feof(indexfile)) {
		if (fread(dummy,1,31,indexfile) != 31)
                 	break  ;
		memcpy(i[unitnr].name,dummy,7) ;
		i[unitnr].type = dummy[10] ;
		memcpy(dummy4,&dummy[11],4) ;
		i[unitnr].signal_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[15],4) ;
		i[unitnr].signal_length = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[19],4) ;
		i[unitnr].period_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[23],4) ;
		i[unitnr].period_length = (*(short*)(dummy4)) ;
		memcpy(dummy4,&dummy[25],4) ;
		i[unitnr].marker_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[29],4) ;
		i[unitnr].marker_length = (*(short*)(dummy4)) ;
                unitnr++ ; }
        fclose(indexfile) ;



        FILE* hf = fopen(hname,"wb") ;
        if (hf == NULL) {
          fprintf(errfile,"Error: Cannot Open %s for Writing\n",hname) ;
	  return(-1) ; }
        short d ;
        d = unitnr ;
        fwrite(&d,1,2,hf) ;
        short* cl = new short[unitnr+1] ;

        int j,k ;
        for (k=0 ; k < unitnr ; k++) {
           cl[k] = 0 ; }

        for (k=0 ; k < unitnr ; k++) {
           j = (int)hash(i[k].name,unitnr) ;
           cl[j] = 1 ; }

        j=0 ;
        for (k=0 ; k < unitnr ; k++) {
           if (cl[k] == 0 ) {

              d = k ;
              fwrite(&d,1,2,hf) ; } 
           else j++ ; }


//        d = unitnr ;
//        fwrite(&d,1,2,hf) ;

        fclose(hf) ;
        delete[](cl) ;
        return(unitnr) ; }

int Unitindexlist::write(char* name) {
        FILE* f = fopen(name,"wb") ;
        if (f == NULL) {
           fprintf(errfile,"Cannot open %s\n",name) ;
           return(0) ; }

        char dummy[31] ;
        long l ;
        short s ;
        Unitindex* k ;

        fwrite(invheader,1,14,f) ;
        for (unsigned i=0 ; i < hashtablesize; i++) {
            k = hashtable[i].pointer ;
            if (k== NULL)
	      continue ;
            memcpy(dummy,k->name,10) ;
            dummy[10] = k->type ;
            memcpy(&dummy[11],&(k->signal_start),4) ;
            memcpy(&dummy[15],&(k->signal_length),4) ;
            memcpy(&dummy[19],&(k->period_start),4) ;
            memcpy(&dummy[23],&(k->period_length),2) ;
            memcpy(&dummy[25],&(k->marker_start),4) ;
            memcpy(&dummy[29],&(k->marker_length),2) ;
            fwrite(dummy,1,31,f) ; }

         fclose(f) ; 
         return(hashtablesize) ; }

int Unitindexlist::add(Unitindex* k) {
        char dummy[31] ;
        write("/tmp/scratch.ind") ;

        FILE* f = fopen("/tmp/scratch.ind","ab") ;

        if (f==NULL) {
            fprintf(errfile,"Cannot open scratch file for appending\n") ;
             return(-1) ; }
            memcpy(dummy,k->name,10) ;
            dummy[10] = k->type ;
            memcpy(&dummy[11],&(k->signal_start),4) ;
            memcpy(&dummy[15],&(k->signal_length),4) ;
            memcpy(&dummy[19],&(k->period_start),4) ;
            memcpy(&dummy[23],&(k->period_length),2) ;
            memcpy(&dummy[25],&(k->marker_start),4) ;
            memcpy(&dummy[29],&(k->marker_length),2) ;
            fwrite(dummy,1,31,f) ; 
        fclose(f) ;
        build_hashtable("/tmp/scratch.ind","/tmp/scratch.hsh") ;
        read("/tmp/scratch.ind","/tmp/scratch.hsh") ;
        return(0) ; }

int Unitindexlist::size() {
        return(hashtablesize) ; }

Unitindex* Unitindexlist::get_index_by_number(int i) {
        return(hashtable[i].pointer) ; }

int Unitindexlist::del(char* name, char type) {
   	Unitindex pos=errorvalue ;
//	int hashtablesize ;
	int len = strlen(name) ;
        int j ;

if (debuglevel > 1) {
	fprintf(errfile,"Looking for Unit %s %c\n",name,type) ;
}

	j = hash(name,hashtablesize) ;
        if (hashtable[j].pointer == NULL) {
          return(-1) ; }
	while ((hashtable[j].pointer)->type != type || strcmp((hashtable[j].pointer)->name,name) != 0) {
		j = hashtable[j].collision ;
		if (j == -1)
			return(-1) ; }
	delete(hashtable[j].pointer) ; 
        hashtable[j].pointer = NULL ;
        write("/tmp/scratch.ind") ;
        build_hashtable("/tmp/scratch.ind","/tmp/scratch.hsh") ;
        read("/tmp/scratch.ind","/tmp/scratch.hsh") ;
        return(0) ; }

int Unitindexlist::read(char* indexfilename, char* hashfilename) {
 	char dummy[60] ;
	char dummy4[4] ;
        unsigned i ;

	if (freehashtableentries != NULL) {
          delete(freehashtableentries) ;
          for (i = 0 ; i < hashtablesize ; i++)  {
				if (hashtable[i].pointer != NULL) {
					delete(hashtable[i].pointer) ;
               hashtable[i].pointer = NULL ; } }
          delete(hashtable) ; }

	freehashtableentries = NULL ;

	FILE* hashfile ;
	hashfile = FOPEN(hashfilename,"rb") ;
	if (hashfile == NULL) {
		fprintf(errfile,"CANNOT OPEN %s\n",hashfilename) ;
                return(-1) ; }

	fseek(hashfile,0L,SEEK_END) ;
	int freehashtablenr = (ftell(hashfile)-1) / 2 ;
	freehashtableentries = new short[freehashtablenr] ;
	rewind(hashfile) ;
	fread(&hashtablesize,2,1,hashfile) ;


	fread(freehashtableentries,2,freehashtablenr,hashfile) ;
	FCLOSE(hashfile) ;

	int j ;
	hashtable = new Hashtableentry[hashtablesize] ;
	nulltest(hashtable) ;

	for (i = 0 ; i < hashtablesize ; i++) {
		hashtable[i].pointer = NULL ;
		hashtable[i].collision = -1 ; }
	FILE* indexfile = FOPEN(indexfilename,"rb") ;
	Unitindex* inf ;
	if (indexfile == NULL) {
		inventory_error("Unitindexlist_constructor","cannot open indexfile",1) ;
		return(-1) ; }
	fread(dummy,1,14,indexfile) ;
	i = 0 ;
	int maxcol = 0 ;

	while (!feof(indexfile)) {
		inf = new Unitindex ;
		nulltest(inf) ;
		if (fread(dummy,1,31,indexfile) < 31)  {
      	delete(inf) ;
      	break ; }
		memcpy(inf->name,dummy,7) ;
		j = (int)hash(inf->name,hashtablesize) ;
		inf->type = dummy[10] ;

if (debuglevel > 10) {
fprintf(errfile,"%s %c %d\n",inf->name,inf->type,j) ; fflush(errfile) ; }


		memcpy(dummy4,&dummy[11],4) ;
		inf->signal_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[15],4) ;
		inf->signal_length = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[19],4) ;
		inf->period_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[23],4) ;
		inf->period_length = (*(short*)(dummy4)) ;
		memcpy(dummy4,&dummy[25],4) ;
		inf->marker_start = (*(long*)(dummy4)) ;
		memcpy(dummy4,&dummy[29],4) ;
		inf->marker_length = (*(short*)(dummy4)) ;
//		j = hash(inf->name,hashtablesize) ;
		while (hashtable[j].pointer != NULL) {

		if (hashtable[j].collision == -1) {
         	if (debuglevel>10) {
				fprintf(errfile,"MAXCOL %d %d\n",maxcol,freehashtableentries[maxcol]) ; fflush(errfile) ; }
				hashtable[j].collision = freehashtableentries[maxcol] ;

				j = freehashtableentries[maxcol++] ;
				break ; }
			j = hashtable[j].collision ; }
		hashtable[j].pointer = inf ; }
	if (debuglevel > 10) {
	for (i=0 ; i < hashtablesize ; i++) {
   	if (hashtable[i].pointer == NULL)
      	fprintf(errfile,"%4d   NULL\n",i) ;
      else
			fprintf(errfile,"%4d  %5d - %s %c\n",i,hashtable[i].collision,hashtable[i].pointer->name,hashtable[i].pointer->type) ; } }
	FCLOSE(indexfile) ;
        return(hashtablesize) ; }



Unitindex* Unitindexlist::get_unit_index_pointer(char* name, char type) {
	Unitindex pos=errorvalue ;
//	int hashtablesize ;
	int len = strlen(name) ;
        int j ;

if (debuglevel > 1) {
	fprintf(errfile,"Looking for Unit %s %c\n",name,type) ;
}

	j = hash(name,hashtablesize) ;
        if (hashtable[j].pointer == NULL) {
          return(NULL) ; }
	while ((hashtable[j].pointer)->type != type || strcmp((hashtable[j].pointer)->name,name) != 0) {
		j = hashtable[j].collision ;
		if (j == -1)
			return(NULL) ; }
	return(hashtable[j].pointer) ; }

Unitindex Unitindexlist::get_unit_index(char* name, char type) {
	Unitindex pos=errorvalue ;
//	int hashtablesize ;
	int len = strlen(name) ;
	char* h = new char[len+1] ;
	nulltest(h) ;
	strcpy(h,name) ;
	int j ;


if (debuglevel > 1) {
	fprintf(errfile,"Looking for Unit %s %c\n",name,type) ;
}


	for(;len > 0 ; len--) {
		j = hash(h,hashtablesize) ;
		if (hashtable[j].pointer == NULL)
	goto net ;
		while ((hashtable[j].pointer)->type != type || strcmp((hashtable[j].pointer)->name,h) != 0) {
			j = hashtable[j].collision ;
			if (j == -1)
				goto net ; }
		goto found ;
net:
		h[len-1] = '\0' ; }
	delete[](h) ;

if (debuglevel > 1) {
	fprintf(errfile,"In vain\n") ;
   fflush(errfile) ;
}

	return(pos) ;


found:
	delete[](h) ;
if (debuglevel > 1) {
	fprintf(errfile,"Success\n")  ;
   fflush(errfile) ;
}


	return(*(hashtable[j].pointer)) ; }

Inventory::Inventory(char* inventory_name,char* inventory_path, int mulw) {
	char* pdummy ;
	char* dummy ;
	mulaw = mulw ;
	invp = inventory_path ;
	char* indexfilename = new char[80] ;
	char* pmfilename = new char[80] ;
	char* tsfilename = new char[80] ;
	char* mrkfilename = new char[80] ;
	char* hashfilename = new char[80] ;
	strcat(strcpy(indexfilename,inventory_name),".ind") ;
	strcat(strcpy(hashfilename,inventory_name),".hsh") ;
	strcat(strcpy(pmfilename,inventory_name),".pm") ;
	if (mulaw)
		strcat(strcpy(tsfilename,inventory_name),"ml.ts") ;
	else
		strcat(strcpy(tsfilename,inventory_name),".ts") ;
	strcat(strcpy(mrkfilename,inventory_name),".mrk") ;
   dummy = invpath(indexfilename,invp) ;
   pdummy = invpath(hashfilename,invp) ;
	uilist = new Unitindexlist(dummy,header,pdummy) ;
   delete[] dummy ;
   delete[] pdummy ;
	nulltest(uilist) ;
	if (method == 2) {
		strcat(strcpy(tsfilename,inventory_name),".fr") ; }
   dummy = invpath(pmfilename,invp) ;
	pmfile = FOPEN(dummy,"rb") ;
	delete[] dummy ;
	if (pmfile == NULL)
		inventory_error("Inventory_constructor","cannot open pmfile",1) ;
   dummy = invpath(mrkfilename,invp) ;
	markerfile = FOPEN(dummy,"rb") ;
	delete[] dummy ;
	if (markerfile == NULL)
		inventory_error("Inventory_constructor","cannot open markerfile",1) ;
   dummy = invpath(tsfilename,invp) ;
	tsfile = FOPEN(dummy,"rb") ;
	delete[] dummy ;
	if (mulaw && tsfile == NULL) {
		strcat(strcpy(tsfilename,inventory_name),".ts") ;
		tsfile = FOPEN(invpath(tsfilename,invp),"rb") ;
		mulaw = 0 ; }
	if (tsfile == NULL)
		inventory_error("Inventory_constructor","cannot open tsfile",1) ;
	delete[](indexfilename) ;
	delete[](tsfilename) ;
	delete[](hashfilename) ;
	delete[](mrkfilename) ;
	delete[](pmfilename) ; }

Inventory::~Inventory() {
        if (tsfile != NULL)
	  FCLOSE(tsfile) ;
	if (pmfile != NULL)
	  FCLOSE(pmfile) ;
	if (markerfile != NULL)
	  FCLOSE(markerfile) ;
	delete(uilist) ; }

int Inventory::get_sf() {
	if (header.sampling_frequency > 100)
		return(header.sampling_frequency/1000) ;
	return(header.sampling_frequency) ; }

char Inventory::get_bytes() {
	return(header.bytes) ; }



Unit Inventory::get_unit(char* name, char type) {
	Unitindex unitind = uilist->get_unit_index(name,type) ;
	Unit result ;
	strncpy(result.name,unitind.name,7) ;
	result.type = unitind.type ;
	if (result.type == 'x') {
		inventory_error("Inventory_get_unit","Unit not found",2) ;
		return(result) ; }
	result.sig = new Timesignal(tsfile,unitind.signal_start,unitind.signal_length,mulaw) ;
	nulltest(result.sig) ;
	result.pitchmarks = new Periodlist(pmfile,unitind.period_start,unitind.period_length) ;
	nulltest(result.pitchmarks) ;
	result.borders = new Marklist(markerfile,unitind.marker_start,unitind.marker_length) ;
	nulltest(result.borders) ;
	return(result) ; }

Unit Inventory::get_unit_info(char* name, char type) {
	Unitindex unitind = uilist->get_unit_index(name,type) ;
	Unit result ;
	strcpy(result.name,unitind.name) ;
	result.type = unitind.type ;
	if (result.type == 'x') {
		inventory_error("Inventory_get_unit","Unit not found",2) ;
		return(result) ; }
	result.sig = NULL ;
	result.lp = NULL ;

if (debuglevel > 1) {
	fprintf(errfile,"Fetching Pitchmarks %ld %d\n",unitind.period_start,unitind.period_length) ;
   fflush(errfile) ;
}

	result.pitchmarks = new Periodlist(pmfile,unitind.period_start,unitind.period_length) ;
	nulltest(result.pitchmarks) ;

if (debuglevel > 1) {
	fprintf(errfile,"Fetching Marks %ld %d\n",unitind.marker_start,unitind.marker_length) ;
   fflush(errfile) ;
}


	result.borders = new Marklist(markerfile,unitind.marker_start,unitind.marker_length) ;
	nulltest(result.borders) ;

if (debuglevel > 1) {
	fprintf(errfile,"Returning from get_unit_info\n") ;
   fflush(errfile) ;
}


	return(result) ; }



Unit Inventory::get_unit_signal(char* name, char type) {
	Unitindex unitind = uilist->get_unit_index(name,type) ;
	Unit result ;
	strncpy(result.name,unitind.name,7) ;
	result.type = unitind.type ;
	if (result.type == 'x') {
		inventory_error("Inventory_get_unit","Unit not found",2) ;
		return(result) ; }
	if (method == 1) {
		result.sig = new Timesignal(tsfile,unitind.signal_start,unitind.signal_length,mulaw) ;
		nulltest(result.sig) ;
		result.lp = NULL ; }
	if (method == 2) {
		result.lp = new Relpsignal(tsfile,unitind.signal_start,unitind.signal_length,invp) ;
		nulltest(result.lp) ;
		result.sig = NULL ; }
	result.pitchmarks = NULL ;
	result.borders = NULL ;
	return(result) ; }















