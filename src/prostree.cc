#include "lisatalk.h"
#if !defined(__PROSTREE_H__)
#include "prostree.h"
#endif

#if !defined(__PROSODY_H__)
#include "prosody.h"
#endif
#ifndef NOTREE

#include <string.h>

int isspace(char c) {
	if (c == '\n' || c == '\t' || c == ' ' || c == '\0')
		return(1) ;
	return(0) ; }

Variable* Varlist::find_entry(Variable i, int cval) {
	reset() ;

	while (act != NULL) {
		if (cval) {
			if (strcmp((act->i).name,"CONSTANT") == 0 && (act->i).value == i.value)
				return(&(act->i)) ; }
		else {
			if (strcmp((act->i).name,i.name) == 0)
				return(&(act->i)) ; }
		act = act->after ; }
	return(NULL) ; }

Variable* Varlist::conc_and_get_pointer(Variable i, int cval) {
	Variable* j = find_entry(i,cval) ;
	if (j != NULL)
		return(j) ;
	else
		return(xappend(i)) ; }

int Varlist::set_value(const char* name, float value) {
	Variable i ;

	strcpy(i.name, name) ;
	i.value = value ;
	Variable* j = find_entry(i,0) ;
	if (j == NULL)
		return(0) ;
	j->value = value ;
	return(1) ; }

float Varlist::get_value(const char* name) {
	Variable i ;
	strcpy(i.name, name) ;
	Variable* j = find_entry(i,0) ;
	if (j == NULL)
		return(0.0) ;
	return(j->value) ; }


//----------------------------------------------------------------

Faktor::Faktor(Variable* v, int neg) {
	f = NULL ;
	negation = neg ;
	val = v ; }

Faktor::Faktor(Formel* fo, int neg) {
	f = fo ;
	val = NULL ;
	negation = neg ; }

Faktor::~Faktor() {
	if (f != NULL)
		delete(f) ; }

float Faktor::return_value() {
	if (val == NULL)
		return(negation*f->return_value()) ;
	else
		return(negation*val->value) ; }

Term::Term(Faktor* fa, Faktor* fb, int op) {
	f1 = fa ;
	f2 = fb ;
	operand = op ; }

//------------------------------------------------------

Term::~Term() {
	if (f1 != NULL)
		delete(f1) ;
	if (f2 != NULL)
		delete(f2) ; }

float Term::return_value() {
	if (f2 == NULL)
		return(f1->return_value()) ;
	if (operand == 0)
		return(f1->return_value() * f2->return_value()) ;
	else
		return(f1->return_value() / f2->return_value()) ; }

//--------------------------------------------------------


Formel::Formel(Term* ta, Term* tb, int op) {
	t1 = ta ;
	t2 = tb ;
	operand = op ; }

Formel::~Formel() {
	if (t1 != NULL)
		delete(t1) ;
	if (t2 != NULL)
		delete(t2) ; }

float Formel::return_value() {
	if (t2 == NULL)
		return(t1->return_value()) ;
	if (operand == 0) 
		return(t1->return_value() + t2->return_value()) ;
	else
		return(t1->return_value() - t2->return_value()) ; }

//---------------------------------------------------------

Aktion::Aktion(Variable* var, Formel* fo) {
	v = var ;
	f = fo ; }

Aktion::~Aktion() {
	if (f != NULL)
		delete(f) ; }

int Aktion::doit() {
	v->value = f->return_value() ;
if (debuglevel > 1) {
	fprintf(errfile,"%s : %f\n\n",v->name,v->value) ;
}
	return((int)v->value) ; }

//----------------------------------------------------

Bedingung::Bedingung(Variable* var, Formel* fo, int o, Bedingung* ba, Bedingung* bb) {
	v = var ;
	f = fo ;
	operand = o ;
	b1 = ba ;
	b2 = bb ;
	a = NULL ; }

Bedingung::Bedingung(Aktion* aa) {
	v = NULL ;
	f = NULL ;
	operand = -1 ;
	b1 = NULL ;
	b2 = NULL ;
	a = aa ; }

Bedingung::~Bedingung() {
	if (f != NULL)
		delete(f) ;
	if (b1 != NULL)
		delete(b1) ;
	if (b2 != NULL)
		delete(b2) ;
	if (a != NULL)
		delete(a) ; }

int Bedingung::doit() {
	float v1,v2 ;
	if (v == NULL)
		return(a->doit()) ;
	v1 = v->value ;
	v2 = f->return_value() ;
if (debuglevel > 1) {
	char opval = ' ' ;
	switch (operand) {
		case 0 : opval = '=' ; break ;
		case 1 : opval = '|' ; break ;
		case 2 : opval = '<' ; break ;
		case 3 : opval = '>' ; break ; }
	fprintf(errfile,"%s (%f) %c %f ?\n",v->name,v1,opval,v2) ;
}

	switch (operand) {

		case -1:
			return(a->doit()) ;
		case 0:
			if (v1 == v2)
				return(b1->doit()) ;
			else
				return(b2->doit()) ;
		case 1:
			if (v1 != v2)
				return(b1->doit()) ;
			else
				return(b2->doit()) ;
		case 2:
			if (v1 < v2)
				return(b1->doit()) ;
			else
				 return(b2->doit()) ;
		case 3:
			if (v1 > v2)
				return(b1->doit()) ;
			else
				return(b2->doit()) ; }
	return(-1) ; }

//----------------------------------------------------------------

void Baum::errore(int number, char* v = NULL) {
        if (dbfil == NULL)
	  dbfil = errfile ;
	fprintf(dbfil,"-----ERROR %d: ",number) ;
	errcount++ ;
	switch(number) {
		case 0: fprintf(dbfil,"unrecognized error") ; break ;
		case 1: fprintf(dbfil,"null pointer returned") ; break ;
		case 2: fprintf(dbfil,"unrecognized token") ; break ;
		case 3: fprintf(dbfil,"problem with variable") ; break ;
		case 4: fprintf(dbfil,"variable name expected") ; break ;
		case 5: fprintf(dbfil,"operand '=|<>' expected") ; break ;
		case 6: fprintf(dbfil,"'?' expected") ; break ;
		case 7: fprintf(dbfil,"';' expected") ; break ;
		case 8: fprintf(dbfil,"')' expected") ; break ;
		case 9: fprintf(dbfil,"unexpected symbol") ; break;
		case 10: fprintf(dbfil,"symbol expected") ; break ;

		default : fprintf(dbfil,"internal error - starting self destruction") ; break ; }
	if (v != NULL){
		fprintf(dbfil," (%s)",v) ;
		fprintf(dbfil,"\n") ; } }


char Baum::gc(FILE* in) {

	if (in == NULL) {
		bc = 300 ;
		return('a') ; }
	if (feof(in))
		return(EOF) ;
	while (bc == 300 || buffer[bc] == '\n' || buffer[bc] == '\0' || buffer[bc] == '#') {
		if (fgets(buffer,299,in) == NULL)
        	return(EOF) ;
		if (debug)
			fprintf(dbfil,"%s",buffer) ;
		bc = 0 ; }
	return(buffer[bc++]) ; }

char* Baum::get_next_token(int& tokentype) {
	char* retbuffer = new char[20] ;
	const char* namen="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz" ;
	const char* zahl="1234567890.," ;
	const char* sign="+-/*()=|<>:?;" ;
	int bufind = 0 ;
	if (retbuffer == NULL) {
		errore(1) ;
		return(NULL) ; }

	while (isspace(nextc))
		nextc = gc(treefile) ;

	if (strchr(sign,nextc) != NULL) {
		retbuffer[0] = nextc ;
		retbuffer[1] = '\0' ;
		tokentype = 0 ;
		nextc = gc(treefile) ;
		return(retbuffer) ; }
	if (strchr(zahl,nextc) != NULL) {
		while (strchr(zahl,nextc) != NULL) {
			if (nextc == ',')
         	nextc = '.' ;
			retbuffer[bufind++] = nextc ;
			nextc = gc(treefile) ; }
		retbuffer[bufind] = '\0' ;
		tokentype = 1 ;
		return(retbuffer) ; }
	if (strchr(namen,nextc) != NULL) {
		while (strchr(namen,nextc) != NULL) {
			retbuffer[bufind++] = nextc ;
			nextc = gc(treefile) ; }
		retbuffer[bufind] = '\0' ;
		tokentype = 2 ;
		return(retbuffer) ; }
	if (nextc != EOF) {
		retbuffer[0] = nextc ;
		retbuffer[1] = '\0' ;
		errore(2,retbuffer) ;
      delete[](retbuffer) ; }
   tokentype = -1 ;
	return(NULL) ; }

void Baum::treecheck(const char* function, int inout) {
	
	if (inout == 1)
		blanks += 3 ;
	for(int i =0 ; i < blanks ; i++)
		fprintf(dbfil," ") ;
	fprintf(dbfil,"%s ",function) ;
	if (inout == 1) {
		fprintf(dbfil," entered\n") ; }
	else {
		fprintf(dbfil," left\n") ;
		blanks -= 3 ; } }

//-----------------------------------------------------------

Variable* Baum::varbuild(char*& input, int typ) {
	Variable i ;
	if (debug > 1)
		treecheck("varbuild",1) ;

	if (typ == 2) {
		i.value = 0.0 ;
		strncpy(i.name,input,10) ;
		delete[](input) ;
		if (debug > 1)
			treecheck("varbuild",0) ;
		return(in->conc_and_get_pointer(i,0)) ; }
	if (typ == 1) {
		i.value = atof(input) ;
		strcpy(i.name,"CONSTANT") ;
		delete[](input) ;
		if (debug > 1)
			treecheck("varbuild",0) ;
		return(in->conc_and_get_pointer(i,1)) ; }
	errore(3,input) ;
	delete[](input) ;
	if (debug > 1)
		treecheck("varbuild",0) ;
	return(NULL) ; }

Faktor* Baum::factor(char*& nextone, int& typ) {
	Formel* f  ;
	Variable* v  ;
	if (debug > 1)
		treecheck("factor",1) ;

	int negit = 1 ;
	if (nextone[0] == '-') {
		negit = -1 ;
		delete[](nextone) ;
		nextone = get_next_token(typ) ; }
	if (nextone == NULL)
		return(NULL) ;

	if (nextone[0] == '(') {
		delete[](nextone) ;
		nextone = get_next_token(typ) ;
		if (nextone == NULL)
			return(NULL) ;
		f = formula(nextone,typ) ;
		if (nextone[0] != ')')
			errore(8) ;
		else {
			delete[](nextone) ;
			if (nextone == NULL)
				return(NULL) ;
			nextone = get_next_token(typ) ; }
		if (debug > 1)
			treecheck("factor",0) ;
		return(new Faktor(f,negit)) ; }

	if (typ > 0) {
		v = varbuild(nextone,typ) ;
		nextone = get_next_token(typ) ;
		if (nextone == NULL)
			return(NULL) ;
		if (debug > 1)
			treecheck("factor",0) ;
		return(new Faktor(v,negit)) ; }

	errore(9) ;
	if (debug > 1)
		treecheck("factor",0) ;
	return(NULL) ; }

Term* Baum::term(char*& nextone, int& typ) {
	if (debug > 1)
		treecheck("term",1) ;

	Faktor* f1 = factor(nextone,typ) ;
	Faktor* f2 = NULL ;
	int operand = 0 ;
	if (typ != 0)
		errore(10) ;

	if (nextone[0] == '*' || nextone[0] == '/') {
		if (nextone[0] == '/')
			operand = 1 ;
		delete[](nextone) ;
		nextone = get_next_token(typ) ;
		if (nextone == NULL)
			return(NULL) ;
		f2 = factor(nextone,typ) ; }

	if (debug > 1)
		treecheck("term",0) ;
	return(new Term(f1,f2,operand)) ; }

Formel* Baum::formula(char*& nextone, int& typ) {
	if (debug > 1)
		treecheck("formula",1) ;
	Term* t1 = term(nextone,typ) ;
	Term* t2 = NULL ;
	int operand = 0 ;

	if (typ != 0)
		errore(10) ;

	if (nextone[0] == '+' || nextone[0] == '-') {
		if (nextone[0] == '-')
			operand = 1 ;
		delete[](nextone) ;
		nextone = get_next_token(typ) ;
		if (nextone == NULL)
			return(NULL) ;
		t2 = term(nextone,typ) ; }

	if (debug > 1)
		treecheck("formula",0) ;
	return(new Formel(t1,t2,operand)) ; }


Aktion* Baum::action(Variable* var, char*& nextone, int& tt) {
	Variable* v = var ;
	Formel* f ;
	if (debug > 1)
		treecheck("action",1) ;
	nextone = get_next_token(tt) ;
	if (nextone == NULL)
		return(NULL) ;
	f = formula(nextone,tt) ;
	if (nextone[0] != ';') {
		errore(7,nextone) ; }
	delete[](nextone) ;

	if (debug > 1)
		treecheck("action",0) ;
	return(new Aktion(v,f)) ; }


Bedingung* Baum::condition(char*& nextone, int&tt) {
	Variable* v ;
	int operand = 0 ;
	Formel* f ;
	Bedingung* b1 ;
	Bedingung* b2 ;
	Aktion* a ;

	if (debug > 1)
		treecheck("condition",1) ;

	nextone = get_next_token(tt) ;
	if (nextone == NULL)
		return(NULL) ;
	if (tt != 2) {
		errore(4,nextone) ;
		delete[](nextone) ;
		v = NULL ; }
	else
		v = varbuild(nextone,tt) ;

	nextone = get_next_token(tt) ;
	if (nextone == NULL)
		return(NULL) ;
	if (nextone[0] == ':') {
		delete[](nextone) ;
		a = action(v,nextone,tt) ;
		if (debug > 1)
			treecheck("condition",0) ;
		return(new Bedingung(a)) ; }

	if (strchr("=|<>",nextone[0]) == NULL) {
		errore(5,nextone) ;
		operand = 0 ; }
	else
		switch (nextone[0]) {
			case '=': operand = 0 ; break ;
			case '|': operand = 1 ; break ;
			case '<': operand = 2 ; break ;
			case '>': operand = 3 ; break ; }
	delete[](nextone) ;

	nextone = get_next_token(tt) ;
	if (nextone == NULL)
		return(NULL) ;
	f = formula(nextone,tt) ;

	if (nextone[0] != '?') {
		errore(6,nextone) ; }
	delete[](nextone) ;

	b1 = condition(nextone,tt) ;
	b2 = condition(nextone,tt) ;

	if (debug > 1)
		treecheck("condition",0) ;

	return(new Bedingung(v,f,operand,b1,b2)) ; }

//----------------------------------------------------------

Baum::Baum(char* treefilename, char* path, int debg = 0, FILE* dbfile = NULL) {
	liste = (Bedingung**)malloc(1) ;
	in = NULL ;
	blanks = 0 ;
	bc = 0 ;
	bedcount = 0 ;
	char* dummy = NULL ;
	int dummy2 = 0 ;
	char fullname[200] ;
	strcat(strcat(strcpy(fullname,path),treefilename),".prt") ;
	errcount = 0 ;
	treefile = FOPEN(fullname,"r") ;
	if (treefile == NULL) {
		free(liste) ;
		liste = NULL ;
if (debuglevel > 0) {
		fprintf(errfile,"Tree %s not loaded\n",fullname) ;
}
		return ; }
	debug = debg ;
	dbfil = dbfile ;
	if (dbfil == NULL)
		debug = 0 ;

	in = new Varlist() ;
	gc(NULL) ;
	nextc = '\0' ;

	while (!feof(treefile)) {
		liste = (Bedingung**)realloc(liste,++bedcount*sizeof(Bedingung*)) ;
		if (liste == NULL) {
			FCLOSE(treefile) ;
			errore(1) ;
			return ; }
		liste[bedcount-1] = condition(dummy,dummy2) ;
		if (liste[bedcount-1] == NULL)
			break ; }
	FCLOSE(treefile) ;
	treefile = NULL ;
	if (errcount > 0) {
		if (in != NULL)
			delete(in) ;
		if (liste != NULL) {
			for (int i = 0 ; i < bedcount ; i++)
				if (liste[i] != NULL)
					delete(liste[i]) ;
			delete(liste) ; }
		in = NULL ;
		liste = NULL ;} }

Baum::~Baum() {
	int i ;
	if (in != NULL)
		delete(in) ;
	if (liste != NULL) {
		for (i = 0 ; i < bedcount ; i++)
			if (liste[i] != NULL)
				delete(liste[i]) ;
		free(liste) ; } }

int Baum::compute() {
	int i ;
	if (liste==NULL)
		return(0) ;
	for (i = 0 ; i < bedcount ; i++)
		if (liste[i] != NULL)
			liste[i]->doit() ;
	return(i) ; }


int Baum::compute_from_file_to_file(FILE* infile, FILE* outfile) {
	int i ;
	if (liste == NULL)
		return(0) ;
	char buffer[200] ;
	rewind(infile) ;
	fgets(buffer,199,infile) ;
	while (fgets(buffer,199,infile) != NULL) {
		set_value("typ",atof(&buffer[16])) ;
		set_value("acat",atof(&buffer[18])) ;
		set_value("pacce",atof(&buffer[21])) ;
		set_value("facce",atof(&buffer[23])) ;
		set_value("stress",atof(&buffer[25])) ;
		set_value("bodi",atof(&buffer[27])) ;
		set_value("rifa",atof(&buffer[30])) ;
		set_value("sylnr",atof(&buffer[32])) ;
		set_value("pdiss",atof(&buffer[35])) ;
		set_value("fdiss",atof(&buffer[38])) ;
		set_value("tobo",atof(&buffer[41])) ;
		set_value("sonr",atof(&buffer[43])) ;
		set_value("beatp",atof(&buffer[46])) ;
		set_value("beatc",atof(&buffer[49])) ;
		set_value("onsec",atof(&buffer[52])) ;
		set_value("onfr",atof(&buffer[54])) ;
		set_value("onpl",atof(&buffer[56])) ;
		set_value("onso",atof(&buffer[58])) ;
		set_value("cosec",atof(&buffer[60])) ;
		set_value("cofr",atof(&buffer[62])) ;
		set_value("copl",atof(&buffer[64])) ;
		set_value("coso",atof(&buffer[66])) ;
		set_value("hilo",atof(&buffer[68])) ;
		set_value("prifa",atof(&buffer[70])) ;
		set_value("ptobo",atof(&buffer[72])) ;
		set_value("silgre",atof(&buffer[74])) ;
		set_value("facatbo",atof(&buffer[83])) ;
		set_value("pacatbo",atof(&buffer[87])) ;
		set_value("nuctyp",atof(&buffer[76])) ;
		set_value("maxacc",atof(&buffer[78])) ;
		set_value("acce",atof(&buffer[81])) ;
		for (i = 0 ; i < bedcount ; i++)
			if (liste[i] != NULL)
				liste[i]->doit() ;

		if (buffer[26] == '1')
			fprintf(outfile,"%f %f %f %f %f\n",get_value("syldur"),get_value("delay"),get_value("amplitude"),get_value("betali"),get_value("betare")) ;
		else
			fprintf(outfile,"%f\n",get_value("syldur")) ; }
	return(1) ; }

int Baum::compute_from_list_to_list(DBSyllist* dbs, Proslist* p) {


	int i ;
	if (liste == NULL)
		return(0) ;
	DBSyll di ;
	Prosinfo pr ;

	dbs->reset() ;

	while ((di = dbs->get_and_advance()).sonr != -1) {
		set_value("typ",di.typ) ;
		set_value("acat",di.acat) ;
		set_value("pacce",di.pacce) ;
		set_value("facce",di.facce) ;
		set_value("stress",di.stress) ;
		set_value("bodi",di.bodi) ;
		set_value("rifa",di.rifa) ;
		set_value("sylnr",di.sylnr) ;
		set_value("pdiss",di.pdiss) ;
		set_value("fdiss",di.fdiss) ;
		set_value("tobo",di.tobo) ;
		set_value("sonr",di.sonr) ;
		set_value("beatp",di.beatp) ;
		set_value("beatc",di.beatc) ;
		set_value("onsec",di.onsec) ;
		set_value("onfr",di.onfr) ;
		set_value("onpl",di.onpl) ;
		set_value("onso",di.onso) ;
		set_value("cosec",di.cosec) ;
		set_value("cofr",di.cofr) ;
		set_value("copl",di.copl) ;
		set_value("coso",di.coso) ;
		set_value("hilo",di.nuchilo) ;
		set_value("prifa",di.prifa) ;
		set_value("ptobo",di.ptobo) ;
		set_value("silgre",di.silgrz) ;
		set_value("facatbo",di.facatbo) ;
		set_value("pacatbo",di.pacatbo) ;
		set_value("nuctyp",di.nuctyp) ;
		set_value("maxacc",di.maxacc) ;
		set_value("acce",di.acce) ;
		set_value("sylpos",di.sylpos) ;
		set_value("smax",di.stressmax) ;
		set_value("searly",di.stressearly) ;
		set_value("slate",di.stresslate) ;
		set_value("sslope",di.stressslope) ;




		for (i = 0 ; i < bedcount ; i++)
			if (liste[i] != NULL)
				liste[i]->doit() ;

		pr.ampli = 0.0 ;
		pr.delay = 0.0 ;
		pr.betali = 0.0 ;
		pr.betare = 0.0 ;
		pr.syldur = 0.0 ;


		if (di.stress == 1) {
			pr.syldur = get_value("syldur") ;
			pr.delay = get_value("delay") ;
			pr.ampli = get_value("amplitude") ;
			pr.betali = get_value("betali") ;
			pr.betare = get_value("betare") ; }
		else
			pr.syldur = get_value("syldur") ;
		p->conc(pr) ; }
	return(1) ; }



int Baum::set_value(const char* name, float value) {
	if (in == NULL)
		return(0) ;
	return(in->set_value(name,value)) ; }

float Baum::get_value(const char* name) {
	if (in == NULL)
   	return(0.0) ;
	return(in->get_value(name)) ; }














#endif
