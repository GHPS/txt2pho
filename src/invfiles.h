
#if !defined(__INVFILES_H__)
#define __INVFILES_H__

typedef struct  {
	long adress ;
	short info ;
	short rms ; } Periodrecord;

typedef struct {
	char name[10] ;
	char type ;
	long start_adress ;
	long samples ;
	long pm_start_adress ;
	short pm_number ;
	long marker_start_adress ;
	short marker_number ; } Unitindexrecord ;

typedef struct  {
	long adress ;
	char text[10] ; } Markerrecord;

#endif

