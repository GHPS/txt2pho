/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

extern int _stdcall _import PPInit(char* infilename, char* rulefilename, char* abkfilename, int i) ;
extern int _stdcall _import PPClose(int i) ;
extern char* _stdcall _import PPnextpart(char* result, int length, int i) ;