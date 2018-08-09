
#if !defined(__RELP_H__)
#define __RELP_H__

#if !defined(__SYNDATA_H__)
#include "syndata.h"
#endif

typedef struct {
	int length ;
	float* rc ;
	short* residual ; } Relpframe ;


class Relplist:public List<Relpframe> {

		int lpc_grade  ;
		float mu  ;
      float* pastbuf ;
      float* emvzg ;

		int synchronize(Relpframe& frame, int length) ;

	public:

		Relplist(int lpc_grade, float mu) ;

		~Relplist() ;

		void list() ;

		void write_last_frame() ;

		int analyze_window(short* window, int length, int shift, int DELAY = 0) ;

		short* synthesize(int first, int last, long& length) ;

		Relpframe get_frame(long startpoint, int length) ;

		short* get_residual(long startpoint, int length) ;

		short* synthesize_frame(Relpframe frame) ;

		int interpolate(int first, int last, int frames) ; } ;

#endif

