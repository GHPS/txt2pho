
#if !defined(__DAC_H__) 
#define __DAC_H__


#if !defined(__HARRAY_H__)
#include "harray.h"
#endif
#if !defined(__LIST_H__)
#include "list.h"
#endif

#include "dares.h"


#ifndef _Windows
typedef struct waveformat_tag {
	 short    wFormatTag;        /* format type */
	 short    nChannels;         /* number of channels (i.e. mono, stereo, etc.) */
	 long     nSamplesPerSec;    /* sample rate */
	 long     nAvgBytesPerSec;   /* for buffer estimation */
	 short     nBlockAlign;       /* block size of data */
} WAVEFORMAT;

/* specific waveform format structure for PCM data */
typedef struct pcmwaveformat_tag {
	 WAVEFORMAT  wf;
	 short        wBitsPerSample;
} PCMWAVEFORMAT;
#endif


class DAC {

	int dacmod ;
	long wlength ;
	int sf ;
	PCMWAVEFORMAT pwf ;
#ifdef _WIN32
	WAVEFORMATEX wwf ;
#endif

#ifdef WINDAC
	WAVEHDR wh ;
	HWAVEOUT devhandle ;
	HWND hWnd;
#endif

public:

	DAC(FILE* synfile, int modus, int sf, int dares, int mulaw) ;  // wav header
	DAC(FILE* synfile, long sf, int dares, int mulaw) ; // au header
	void write_voc_header(FILE* synfile, long sf) ; // au header

#ifdef _Windows
	DAC(HWND __hWnd, int sfr) ;
   DAC(int sfr) ;
#endif

	~DAC() ;

#ifdef _Windows
	int init(HugeArray<DATYPE>*) ;
#endif

	int play_file(char*) ;

	int play_data(char*,long) ;

	void send_signal(short* buf,int length) ;

	void close(FILE* fil) ;
	void close_au(FILE*) ;
	void close_voc(FILE*) ;
	void close(char* huge, long) ;

	void stop() ;

	int paused() ;

	int go_on() ;

	int running() ;

	long get_time() ;
    long get_sample() ;

	void play_buffer() ; } ;

#endif

