const int lpc_grade = 18 ;				// number of lp coefficients - grade
const float mu = 0.9 ;					// preemphasis
// const int length = 256 ;				// windowlength

//=============================================================================

	typedef float lpc_coeffs[lpc_grade+1] ;	// defines a set of lp coefficients

	typedef struct {
			lpc_coeffs b ; } Ref_frame ;

	typedef struct {
			float real, imag ; } COMPLEX ;

	Ref_frame get_ref_frame(int* window) ;

	int window_length() ;

	float get_distance(int* window, Ref_frame frame) ;

	float* get_lpc_spectrum(int*window,int resolution, int kHz = 8) ;

	float* get_fft_spectrum(int*window, int twopow) ;

	float euklid(float* a, float* b, int len) ;

	float* get_lpc_cepstrum(Ref_frame a) ;

	float* get_mel_cepstrum(float* spectrum, int speclen, float topfreq, int cepsnr) ;

	float* get_mel_filterbank(float* spectrum, int speclen, float topfreq, int& number) ;

	float* get_fft_cepstrum(float* spectrum, int speclen, int cepsnr) ;

	float* get_pse(int* window, int length, int shift, int speclen, int number) ;



