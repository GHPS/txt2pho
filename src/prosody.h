
#if !defined(__PROSODY_H__)
#define __PROSODY_H__

#if !defined(__SYLLABLE_H__)
#include "syllable.h"
#endif

typedef struct {
	char* name ;
	char* type ;
	char nucl[4] ;
	int nuctyp ;
    int nuchilo ;
	int firstsound ;
	int typ ;
	int acat ;
	int acce ;
	int maxacc ;
	int pacce ;
	int facce ;
	int stress ;
	int stressmax ;
	int stresslate ;
	int stressearly ;
	int stressslope ;
	int bodi ;
	int prifa ;
	int rifa ;
	int sylnr ;
	int onsec ;
	int cosec ;
	int onfr ;
	int cofr ;
	int onpl ;
	int copl ;
	int sylpos ;
	int onso ;
	int coso ;
	int pdiss ;
	int fdiss ;
	int beatp ;
	int beatc ;
	int silgrz ;
	int pacatbo ;
   int facatbo ;
	int phraspos ;
	int ptobo ;
	int tobo ;
	int sonr ; } DBSyll ;

typedef struct {
	char* name ;
	char* type ;
	int firstsound ;
	int soundnr ;
	int syldur ;
	float amplitude ;
	float delay ;
	float betali ;
	float betare ; } NNSyll ;


class DBSyllist: public List<DBSyll> {
	public:
		DBSyllist() ;
		~DBSyllist() ;
		void clearx() ;
		DBSyll* get_db_pointer(int indexnr) ;
		DBSyll* get_db_pointer() ;
		int conc(DBSyll i) ; } ;


class NNProsody {

		class NNSyllist: public List<NNSyll> {
			public:
				NNSyllist() ;
				~NNSyllist() ;
				int conc(NNSyll i) ; } ;

		int generate_DBS(Syllablelist* syll, Soundlist* soli) ;
		int compute_NNS() ;

		int prifa ;
		int ptobo ;
		int pacatbo ;
		int facatbo ;
	NNSyllist nsl ;
		DBSyllist dbs ;

	public:
		NNProsody(char* drmfilnam,char* drmfilpath) ;
		~NNProsody() ;

		DBSyllist* get_DBS() ;
		int build(Syllablelist* syll, Soundlist* soli) ;
		NNSyll get_next_NSL() ;
		void list_DBS(FILE* out) ;
		void clear() ;
		void NSL_reset() ; } ;


#ifndef __PHDURNN_H__
#include "phdurnn.h"
#endif

class Intensity_Control {

		int* intensity_values ;
		char** sounds ;
		int soundnr ;
		float db_decrease ;

	public:

		Intensity_Control(char* intname, char* intpath) ;
		~Intensity_Control() ;
		int compute_intensities(Soundlist* s) ; } ;

typedef struct {
	float syldur ;
	float delay ;
	float ampli ;
	float betali ;
	float betare ; } Prosinfo ;

class	Proslist: public List<Prosinfo> {
public:
	Proslist() ;
	int print(FILE*) ; 
	int get_pr_pointer() ;
	int conc(Prosinfo pr) ; } ;





typedef struct {
	char name[4] ;
	float logmean ;
	float logsd ; } D_Sound ;

class Duration_Model {

		class D_Soundlist: public List<D_Sound> {
			public:
				D_Soundlist() ;
				~D_Soundlist() ;

				int conc(D_Sound i) ;
				D_Sound find_sound(char* s) ; } ;

		int sf ;
		float speechrate ;
		float plosfac ;
		float finalfac ;
		float sonrfac ;
		float acatfac ;
		float acatplus ;
		float divisor ;
		float summand ;
		float diphthongfac ;
		float kvfac ;
		float varia ;
		float actdur ;
		int actword ;
		
		int wordnr ;
		long* wordlist ;
		long total_length ;
		int lastwordnr ;
		long* lastwordlist ;
		long last_total_length ;
		int bwl ;

		D_Soundlist dsl ;

		float fit(D_Soundlist* syll,int lautzahl,float sylldur,int phraspos) ;
		float sildur(float k,D_Soundlist* syll, int lautzahl) ;
		void compute_syllable_duration(Syllableinfo s, int,int,Soundlist*,float&,int,int) ;

	public:
		Duration_Model(char* drmfilnam,char* drmfilpath, int build_word_list = 0) ;
		~Duration_Model() ;

		int prepare_for_last_sentence() ;
		void change_speech_rate(float offset) ;
		void set_speech_rate(float rate) ;
		float get_speech_rate() ;
		void set_accentlength(float rate) ;
		float get_accentlength() ;
		void set_final_lengthening(float rate) ;
		float get_final_lengthening() ;
		void set_speech_rate_range(float rate) ;
		float get_speech_rate_range() ;
		int get_word_index(long ms) ;
		long get_total_length() ;
		long* get_word_list(long* wpl = NULL) ;
		void clear() ;
		int compute_duration(Syllablelist& syll, Soundlist*, FILE* nnfile = NULL, long start = 0L, Proslist* p = NULL, int use_net=0, PhonNetz* phondurnet = NULL,DBSyllist* dbs = NULL) ; } ;


typedef struct {
	long t0 ;          	// begin of the command in ms
	float delay ;
	double betali ;
	double betare ;
	double amplitude ; } I_Command ;



class Intonation_Model {

		class I_Commandlist: public List<I_Command> {
			public:
				I_Commandlist() ;
				I_Command* get_i_command_pointer(int index) ;
				int conc(I_Command i) ; } ;

		int sf ;
		float toplinestart ;
		float toplineend ;
		float baselinestart ;
		float baselineend ;
		int f0changeval ;
		int sollf0 ;

		float compute_f0_value(long sample, long totalms) ;

		I_Commandlist dsl ;

	public:
		Intonation_Model(char* drmfilnam,char* drmfilpath) ;
		~Intonation_Model() ;

		void clear() ;
		void print(FILE*,long) ;
		long input(FILE*) ;

		float get_pitch() ;
		int set_pitch(float value) ;
		float get_pitchrange() ;
		int set_pitchrange(float value) ;
		float get_declination() ;
		int set_declination(float value) ;

		int compute_f0(Syllablelist& syll, Soundlist* firstsound, int modus, FILE* nnfile = NULL, long start = 0L, char* pid = "", int onlystress = 0, Proslist* p = NULL) ; } ;





#endif

