
#include "lisatalk.h"

#if !defined(__DAC_H__)
#include "dac.h"
#endif

extern long bt4(long) ;
extern short bt2(short) ;

DAC::DAC(FILE* synfile, long sf, int dares, int mulaw) {
	fprintf(errfile,"au header\n") ;
	fprintf(synfile,"%csnd",0x2E) ;
	long hsize = 32L ;
	long length = -1L ;
	long encoding ;
	if (dares == 16)
		encoding = 3L ;
	else
		encoding = 2L ;
	if (mulaw)
		encoding = 1L ;
	long channels = 1L ;
	long null = 0L ;
	sf = sf *1000L ;
# ifndef SUN
	fprintf(errfile,"byteturned header\n") ;
	hsize=bt4(hsize) ;
	length=bt4(length) ;
	encoding=bt4(encoding) ;
	null = bt4(null) ;
	channels= bt4(channels) ;
	sf = bt4(sf) ;
# endif
	fwrite(&hsize,4,1,synfile) ;
	fwrite(&length,4,1,synfile) ;
	fwrite(&encoding,4,1,synfile) ;
	fwrite(&sf,4,1,synfile) ;
	fwrite(&channels,4,1,synfile) ;
	fwrite(&null,4,1,synfile) ;
	fwrite(&null,4,1,synfile) ; }


void DAC::close_au(FILE* synfile) {
	long len ;
	fseek(synfile,0L,2) ;
	len = ftell(synfile) ;
	len -= 32L;
	fseek(synfile,8L,0) ;
# ifndef SUN
	len = bt4(len);
#endif
	fwrite(&len,4,1,synfile) ;
	FCLOSE(synfile) ; }



DAC::DAC(FILE* synfile,int modus,int sf, int dares, int mulaw) {

	const char* name = "RIFF" ;
	const char* type = "WAVE" ;
	const char* fmt = "fmt " ;
	const char* data = "data" ;
#ifdef _Windows
	long length = sizeof(PCMWAVEFORMAT) ;
#else
	long length = 16L ;
#endif
#ifdef WINDAC
	wh.lpData = NULL ;
	devhandle = NULL ;
#endif
//	printf("wav header\n") ;
	pwf.wf.wFormatTag = 1 ;
	pwf.wf.nChannels = 1 ;
	pwf.wf.nSamplesPerSec = (long)(sf*1000L) ;
	pwf.wf.nAvgBytesPerSec = (long)((sf*1000L)*(dares/8L)) ;
	pwf.wf.nBlockAlign = dares/8 ;
	pwf.wBitsPerSample = dares ;
#ifdef _WIN32
	wwf.wFormatTag = pwf.wf.wFormatTag ;
	wwf.nChannels = pwf.wf.nChannels ;
	wwf.nSamplesPerSec = pwf.wf.nSamplesPerSec ;
	wwf.nAvgBytesPerSec = pwf.wf.nAvgBytesPerSec ;
	wwf.nBlockAlign = pwf.wf.nBlockAlign ;
	wwf.wBitsPerSample = pwf.wBitsPerSample ;
	wwf.cbSize = 0 ;
#endif
#ifdef SUN
//	fprintf(errfile,"byteturned\n") ;
	length=bt4(length);
	pwf.wf.wFormatTag = bt2(pwf.wf.wFormatTag) ;
	pwf.wf.nChannels = bt2(pwf.wf.nChannels) ;
	pwf.wf.nSamplesPerSec = bt4(pwf.wf.nSamplesPerSec) ;
	pwf.wf.nAvgBytesPerSec = bt4(pwf.wf.nAvgBytesPerSec) ;
	pwf.wf.nBlockAlign = bt2(pwf.wf.nBlockAlign) ;
	pwf.wBitsPerSample = bt2(pwf.wBitsPerSample) ;
#endif
	fwrite(name,4,1,synfile) ;
	fwrite(&length,4,1,synfile) ;
	fwrite(type,4,1,synfile) ;
	fwrite(fmt,4,1,synfile) ;
	fwrite(&length,4,1,synfile) ;
#ifndef _Windows
	fwrite(&pwf.wf.wFormatTag,2,1,synfile) ;
	fwrite(&pwf.wf.nChannels,2,1,synfile) ;
	fwrite(&pwf.wf.nSamplesPerSec,4,1,synfile) ;
	fwrite(&pwf.wf.nAvgBytesPerSec,4,1,synfile) ;
	fwrite(&pwf.wf.nBlockAlign,2,1,synfile) ;
	fwrite(&pwf.wBitsPerSample,2,1,synfile) ;
#else
	fwrite(&pwf,sizeof(PCMWAVEFORMAT),1,synfile) ;
#endif
	fwrite(data,4,1,synfile) ;
	fwrite(&length,4,1,synfile) ;
    }


DAC::~DAC() {

#ifdef WINDAC
	if (devhandle != NULL)
		waveOutClose(devhandle) ;
#endif
}

#ifdef WINDAC
int DAC::play_file(char* name ) {
//	int result ;
//	MSG msg ;
//	while (1) {
//		result = sndPlaySound(NULL,SND_NOSTOP) ;
//		printf("%d %s ",result,name) ;
//		if (result == TRUE)
//			break ; }
//	PlaySound(name,NULL,SND_FILENAME | SND_ASYNC);
	if (devhandle != NULL) {
		while (running()) ;
		fprintf(errfile,"WOC %d\n",waveOutClose(devhandle)) ; }
//	char buffer[80] ;
//	sprintf(buffer,"vplay /q %s",name) ;
//	WinExec(buffer,SW_HIDE) ;
	fprintf(errfile,"SPL %s %d\n",name,sndPlaySound(name, SND_SYNC | SND_NODEFAULT | SND_NOSTOP)) ;
#ifdef _WIN32
	wwf.wFormatTag = pwf.wf.wFormatTag ;
	wwf.nChannels = pwf.wf.nChannels ;
	wwf.nSamplesPerSec = pwf.wf.nSamplesPerSec ;
	wwf.nAvgBytesPerSec = pwf.wf.nAvgBytesPerSec ;
	wwf.nBlockAlign = pwf.wf.nBlockAlign ;
	wwf.wBitsPerSample = pwf.wBitsPerSample ;
	wwf.cbSize = 0 ;
	waveOutOpen(&devhandle,WAVE_MAPPER,&(wwf),NULL,NULL,WAVE_ALLOWSYNC) ;
#else
	waveOutOpen(&devhandle,WAVE_MAPPER,&(pwf.wf),NULL,NULL,WAVE_ALLOWSYNC) ;
#endif
	return(1) ; }

#endif

void DAC::close(FILE* fil) {
	long len ;
	long x ;
	fseek(fil,0L,SEEK_END) ;
	len = ftell(fil) ;
	len -= 8L;
	fseek(fil,4L,SEEK_SET) ;
#ifdef SUN
	x = bt4(len) ;
#else
	x=len;
#endif
	fwrite(&x,4,1,fil) ;
	len -= 36L ;
	fseek(fil,40L,SEEK_SET) ;
#ifdef SUN
	x = bt4(len) ;
#else
	x=len;
#endif
	fwrite(&x,4,1,fil) ;
	FCLOSE(fil) ; }

#ifdef WINDAC

DAC::DAC(HWND __hWnd, int sfr) {
	int flag = 0 ;
	hWnd = __hWnd;
	sf = sfr ;
	wh.lpData = NULL ;
	pwf.wf.wFormatTag = 1 ;
	pwf.wf.nChannels = 1 ;
	pwf.wf.nSamplesPerSec = (long)sf*1000L ;
	pwf.wf.nAvgBytesPerSec = (long)sf*1000L*sizeof(DATYPE) ;
	pwf.wf.nBlockAlign = sizeof(DATYPE) ;
	pwf.wBitsPerSample = DARES ;
#ifdef _WIN32
	wwf.wFormatTag = pwf.wf.wFormatTag ;
	wwf.nChannels = pwf.wf.nChannels ;
	wwf.nSamplesPerSec = pwf.wf.nSamplesPerSec ;
	wwf.nAvgBytesPerSec = pwf.wf.nAvgBytesPerSec ;
	wwf.nBlockAlign = pwf.wf.nBlockAlign ;
	wwf.wBitsPerSample = pwf.wBitsPerSample ;
	wwf.cbSize = 0 ;
	flag = waveOutOpen(&devhandle,WAVE_MAPPER,&(wwf),NULL,NULL,WAVE_ALLOWSYNC) ;
#else
	flag = waveOutOpen(&devhandle,WAVE_MAPPER,&(pwf.wf),NULL,NULL,WAVE_ALLOWSYNC) ;
#endif
//	if (flag != 0)
//		fprintf(errfile,"WaveOutOpen returns %d\n",flag) ;
	}

DAC::DAC(int sfr) {
	int flag ;
	sf = sfr ;
	wh.lpData = NULL ;
	pwf.wf.wFormatTag = 1 ;
	pwf.wf.nChannels = 1 ;
	pwf.wf.nSamplesPerSec = (long)sf*1000L ;
	pwf.wf.nAvgBytesPerSec = (long)sf*1000L*sizeof(DATYPE) ;
	pwf.wf.nBlockAlign = sizeof(DATYPE) ;
	pwf.wBitsPerSample = DARES ;
#ifdef _WIN32
	wwf.wFormatTag = pwf.wf.wFormatTag ;
	wwf.nChannels = pwf.wf.nChannels ;
	wwf.nSamplesPerSec = pwf.wf.nSamplesPerSec ;
	wwf.nAvgBytesPerSec = pwf.wf.nAvgBytesPerSec ;
	wwf.nBlockAlign = pwf.wf.nBlockAlign ;
	wwf.wBitsPerSample = pwf.wBitsPerSample ;
	wwf.cbSize = 0 ;
	flag = waveOutOpen(&devhandle,WAVE_MAPPER,&(wwf),NULL,NULL,WAVE_ALLOWSYNC) ;
#else
	flag = waveOutOpen(&devhandle,WAVE_MAPPER,&(pwf.wf),NULL,NULL,WAVE_ALLOWSYNC) ;
#endif
	fprintf(errfile,"%d\n",devhandle) ;
	if (flag != 0)
		fprintf(errfile,"WaveOutOpen returns %d\n",flag) ;
	}

#endif

void DAC::write_voc_header(FILE* synfile,long sf) {
  //	const char* title = "Creative Voice File" ;
	char a[24] ;
		  unsigned short* p = (unsigned short*)&a[11] ;
		  a[0]=a[1]='\x1A' ;
		  a[2]=a[8]=a[9]=a[10]=a[13]=a[14]=a[18]=a[19]=a[20]=a[21]=a[22]=a[23]='\x00' ;
        a[3]='\x14' ;
        a[4]=a[16]='\x01' ;
        a[5]='\x1F' ;
        a[6]='\x11' ;
        a[7]='\x09' ;
		  a[15]='\x10' ;
        a[17]='\x04' ;
        *p = (unsigned short)(sf*1000) ;
		  fprintf(synfile,"Creative Voice File") ;
		  fwrite(a,23,1,synfile) ; }



void DAC::close_voc(FILE* fil) {
	const char ende = '\x00' ;

		  fwrite(&ende,1,1,fil) ;
		  long lenall = (ftell(fil)-31L) ;
		  fseek(fil,27L,SEEK_SET) ;
		  fwrite(&lenall,1,3,fil) ;
		  FCLOSE(fil) ; }

#ifdef WINDAC

int DAC::init(HugeArray<DATYPE>* h) { return(1); }
/*	char header[44] ;
	for (int i = 0 ; i < 44 ; i++)
		header[i] = '\0' ;
	int syndatapos = 0 ;
	char* name = "RIFF" ;
	char* type = "WAVE" ;
	char* fmt = "fmt " ;
	char* data = "data" ;
	long length = sizeof(PCMWAVEFORMAT) ;
//	memcpy(&header[0],name,4) ;
//	memcpy(&header[8],type,4) ;
//	memcpy(&header[12],fmt,4) ;
//	memcpy(&header[16],&length,4) ;
//	memcpy(&header[20],&pwf,sizeof(PCMWAVEFORMAT)) ;
//	memcpy(&header[36],data,4) ;
	h->Append(header,44) ; } */

int DAC::running() {
	if (wh.lpData != NULL)
		return(waveOutUnprepareHeader(devhandle,&wh,sizeof(wh)) == WAVERR_STILLPLAYING) ;
	else
		return(0) ; }

int DAC::paused() {
	if (wh.lpData != NULL)
		return(waveOutPause(devhandle)) ;
	else
		return(0) ; }

 int DAC::go_on() {
	if (wh.lpData != NULL)
		return(waveOutRestart(devhandle)) ;
	else
		return(0) ; }


long DAC::get_time() {
	if (!running())
		return(-1) ;
	MMTIME timeval ;
	waveOutGetPosition(devhandle,&timeval,sizeof(timeval)) ;
	return(timeval.u.cb/((float)sf*sizeof(DATYPE))) ; }

long DAC::get_sample() {
	MMTIME timeval ;
	waveOutGetPosition(devhandle,&timeval,sizeof(timeval)) ;
	return(timeval.u.cb/sizeof(DATYPE)) ; }

int DAC::play_data(char* name, long length ) {
	int flag ;
//   fprintf(errfile,"%d\n",devhandle) ;
	while (running()) ;
	wh.lpData = name ;
	wh.dwBufferLength = length ;
	wh.dwLoops = 0 ;
	wh.dwFlags = 0 ;
	flag = waveOutReset(devhandle) ;
	if (flag != 0)
		fprintf(errfile,"WaveOutReset returns %d\n",flag) ;
	if ((flag = waveOutPrepareHeader(devhandle,&wh,sizeof(wh))) != 0) {
		if (flag != 0)
			fprintf(errfile,"WaveOutPrepareHeader returns %d\n",flag) ;
		return(0)  ; }
	if ((flag = waveOutWrite(devhandle,&wh,sizeof(wh))) != 0) {
		if (flag != 0)
			fprintf(errfile,"WaveOutWrite returns %d\n",flag) ;
		return(0) ; }
	return(1) ; }
//	return(sndPlaySound(name,SND_ASYNC + SND_MEMORY)) ; }

#endif

void DAC::close(char* data, long len) {
	wlength = len ;
	len -= 8L;
//	memcpy(&data[4],&len,4) ;
	len -= 36L ;
//	memcpy(&data[40],&len,4) ;
	}

//	FILE* tf = fopen("tf.wav","wb") ;
//	for (long i=0; i < len ; i++) {
//		if (i % 100 == 0)
//		printf("%ld %lp",i,&data[i]) ;
//		fwrite(&data[i],1,1,tf) ; }
//	FCLOSE(tf) ; }

void DAC::send_signal(short* buf,int len) { ; }

void DAC::play_buffer() { ; }

#ifdef WINDAC

void DAC::stop() {
	waveOutReset(devhandle) ; }

#endif

//	sndPlaySound(NULL,SND_NODEFAULT) ; }
