/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

#if !defined(__PROSTREE_H__)
#define __PROSTREE_H__

#if !defined(__PROSODY_H__)
#include "prosody.h"
#endif




typedef struct {
	char name[10] ;
	float value ; } Variable ;

class Varlist: public List<Variable> {

		Variable* find_entry(Variable i, int cval) ;

	public:

		int set_value(const char* name, float value) ;
      float get_value(const char* name) ;
		Variable* conc_and_get_pointer(Variable i, int cval) ; } ;

class Formel ;

class Faktor {

		Variable* val ;
		int negation ;
		Formel* f ;

	public:

		Faktor(Variable* v , int neg ) ;
		Faktor(Formel* f, int neg) ;
		~Faktor() ;
		float return_value() ; } ;

class Term {

		Faktor* f1 ;
		Faktor* f2 ;
		int operand ;

	public:

		Term(Faktor* fa, Faktor* fb, int operand) ;
		~Term() ;
		float return_value() ; } ;

class Formel {

		Term* t1 ;
		Term* t2 ;
		int operand ;

	public:

		Formel(Term* ta, Term* tb, int operand) ;
		~Formel() ;
		float return_value() ; } ;

class Aktion {

		Variable* v ;
		Formel* f ;

	public:

		Aktion(Variable* var, Formel* fo) ;
		~Aktion() ;
		int doit() ; } ;

class Bedingung {

		Variable* v ;
		Formel* f ;
		int operand ;
		Bedingung* b1 ;
		Bedingung* b2 ;
		Aktion* a ;

	public:

		Bedingung(Variable* var, Formel* fo, int o, Bedingung* ba, Bedingung* bb) ;
		Bedingung(Aktion* aa) ;
		~Bedingung() ;
		int doit() ; } ;

class Baum {

		char nextc ;
		Varlist* in ;
		char buffer[300] ;
		int bc ;
		int blanks ;

		Bedingung** liste ;
		int bedcount ;

		FILE* treefile ;
		int debug ;
		FILE* dbfil ;
      int errcount ;

		void errore(int, char*) ;
		void treecheck(const char*,int) ;
		char gc(FILE*) ;
		char* get_next_token(int&) ;

		Variable* varbuild(char*&,int) ;
		Faktor* factor(char*&,int&) ;
		Term* term(char*&,int&) ;
		Formel* formula(char*&,int&) ;
		Aktion* action(Variable*,char*&,int&) ;
		Bedingung* condition(char*&,int&) ;








	public:

		Baum(char* treefilename, char* path, int debg, FILE* dbfile) ;
		~Baum() ;
		int compute() ;
      int compute_from_file_to_file(FILE* in, FILE* out) ;
      int compute_from_list_to_list(DBSyllist* dbs, Proslist* p) ;
		int set_value(const char* name, float value) ;
		float get_value(const char* name) ; } ;

#endif










