#ifndef _SIGMAN_H_
#define _SIGMAN_H_

#include "relp.h"
#include "dares.h"
#include "harray.h"

class Sigman{

  

short* smoothwindow ;
long smoothlength ;
int s2length ;
int smoothper ;
long smoothadr  ;
short leftval ;
Relplist* rl ;
Relplist* psolarl ;
Markerinfo* m ;
Periodinfo p, xp ;
short* interbuf ;
short* rightbuffer ;
Relpframe frame ;
short* signal ;
short* interbufL ;
int iblen  ;
long oldsiglen ;
short lastval ;
int xpl ;
int last ;
short* lastshortbuffer ;
int lastshortlength ;
int durshift ;                                           // duration shift
int synwin;
long sample ;                                            // number of synthesized samples
long actsample ;
long insp   ;
long osm  ;
char lastlab[12] ;
int conc_smoothlength ;
int conc_periods ;
int conc_lastindex ;


 public:


 Sigman() {
   
   lastshortbuffer = NULL ;
   smoothwindow = 0 ;
   smoothlength = 0  ;
   s2length = 0 ;
   smoothper = 0 ;
   smoothadr = 0 ;
   rl = NULL ;
   psolarl = NULL ;
   signal = NULL ;
   interbuf = NULL ;
   iblen = 0 ;
   lastval = 0 ;
   insp  = 0L ;
   osm = 0L ;
   conc_smoothlength = 0 ;
   conc_periods = 0 ;
   conc_lastindex = 0 ;
   xpl = 1 ; }

  int get_next_mark_and_pm(Inventory& invent,Unitlist* u, Soundlist* soli,  Periodlist& pl, Marklist& ml,long& sigpos, float position) ;
  short* get_next_signal_part(Inventory& invent, Periodlist& pl, Marklist& ml, int* sl, int& reset) ;

#ifdef _Windows
  int psola(HugeArray<DATYPE>* h, short* sigpart,int siglen, Periodlist& pl, int lastpl, Marklist& ml, FILE* synfile, FILE* perfile, FILE* mrkfile, int reset, int sf, int dares, int mulaw, int danow = 0, int filetype = 0, int method = 0, float preemp = 0.0, int lpc_grade = 0, float mu = 0.0, int DELAY = 0) ;
#else
  int psola(void* h, short* sigpart,int siglen, Periodlist& pl, int lastpl, Marklist& ml, FILE* synfile, FILE* perfile, FILE* mrkfile, int reset, int sf, int dares, int mulaw, int danow = 0, int filetype = 0, int method = 0, float preemp = 0.0, int lpc_grade = 0, float mu = 0.0, int DELAY = 0) ;
#endif
 } ;

#endif


