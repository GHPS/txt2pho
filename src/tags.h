#ifndef __TAGS_H__
#define __TAGS_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class Taglist {

  char*** voices ;
  int voicealiases ;

 public:
  
  Taglist(char* path) ;
  ~Taglist() ;
  int change(char* in) ; } ;
  
#endif
