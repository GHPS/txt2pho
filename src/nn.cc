/*

  This file is part of the project txt2pho.
  The project is released under the AGPL 3.0 license.
  For details concerning the resulting rights and
  conditions of this license see file License.txt.

*/

#ifdef NET
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "nn.h"
#include "lisatalk.h"
#include "prosody.h"

const int INPARS = 32 ;
const int OUTPARS = 5 ;
char* indatanames[INPARS] = {"TYP","ACAT","PACCE","FACCE","STRESS","BODI","RIFA",
							"SYLNR","PDISS","FDISS","TOBO","SONR","BEATP","BEATC",
							"ONSEC","ONFR","ONPL","ONSO","CODAC","COFR","COPL",
							"COSO","HILO","PRIFA","PTOBO","SILGRE","FACATBO",
							"PACATBO","NUCTYP","MAXACC","ACCE","FOSO"} ;
int indatapos[INPARS] = {16,18,21,23,25,27,30,32,35,38,41,43,46,49,52,54,56,58,60,62,64,66,68,70,72,74,83,87,76,78,81,66} ;
char* outdatanames[OUTPARS] = {"SYLDUR","DELAY","AMPLI","BETALI","BETARE"} ;

int get_value(DBSyll* d, int i) {
	switch (i) {
		case 0 : return(d->typ) ; break ;
		case 1 : return(d->acce) ; break ;
		case 2 : return(d->acat) ; break ;
		case 3 : return(d->pacce) ; break ;
		case 4 : return(d->facce) ; break ;
		case 5 : return(d->stress) ; break ;
		case 6 : return(d->bodi) ; break ;
		case 7 : return(d->rifa) ; break ;
		case 8 : return(d->sylnr) ; break ;
		case 9 : return(d->pdiss) ; break ;
		case 10 : return(d->fdiss) ; break ;
		case 11 : return(d->tobo) ; break ;
		case 12 : return(d->sonr) ; break ;
		case 13 : return(d->beatp) ; break ;
		case 14 : return(d->beatc) ; break ;
		case 15 : return(d->onsec) ; break ;
		case 16 : return(d->onfr) ; break ;
		case 17 : return(d->onpl) ; break ;
		case 18 : return(d->onso) ; break ;
		case 19 : return(d->codac) ; break ;
		case 20 : return(d->cofr) ; break ;
		case 21 : return(d->copl) ; break ;
		case 22 : return(d->coso) ; break ;
		case 23 : return(d->hilo) ; break ;
		case 24 : return(d->prifa) ; break ;
		case 25 : return(d->ptobo) ; break ;
		case 26 : return(d->silgre) ; break ;
		case 27 : return(d->facatbo) ; break ;
		case 28 : return(d->pacatbo) ; break ;
		case 29 : return(d->nuctyp) ; break ;
		case 30 : return(d->maxacc) ; break ;
		case 31 : return(d->acce) ; break ;
		case 32 : return(d->coso) ; break ; }
	return(0) ; }

int put_value(Prosinfo* d, int i, float f) {
	switch (i) {
		case 0 : d->syldur = f ; return 1 ;
		case 1 : d->delay = f ; return 1 ;
		case 2 : d->ampli = f ; return 1 ;
		case 3 : d->betali = f ; return 1 ;
		case 4 : d->betare = f ; return 1 ; }
	return(0) ; }



int findname(char** liste, int listlen, char* key) {
	int i ;
	for (i = 0 ; i < listlen ; i++) {
		if (strcmp(liste[i],key) == 0)
			return(i) ; }
	return(-1) ; }

float adjust(float value, float minval, float maxval){
	if (maxval == minval)
		return(0.0) ;
	if (value > maxval)
		value = maxval ;
	if (value < minval)
		value = minval ;
	return((value-minval)/(maxval-minval)) ; }

float readjust(float value, float minval, float maxval){
	return(value*(maxval-minval)+minval) ; }

Netz::Netz(char* name, char* path) {


	char temp[1024] ;

	inputvalues = NULL ;
	outputvalues = NULL ;
	strcat(strcpy(temp,path),name) ;

	FILE* parfile = FOPEN(temp,"r") ;
	if (parfile == NULL) {
		fprintf(errfile,"Error while opening file %s\n",temp) ;
      fflush(errfile) ;
		return ; }

	int i,j ;
	char* pos, *actpos ;

	inputvalues = new Condition[20] ;
	outputvalues = new Condition[5] ;
	inputvaluenr = 0 ;
	outputvaluenr = 0;

	while (fgets(temp,1023,parfile) != NULL) {
		if (strstr(temp,"Eingabeparameter:") != NULL) {
			pos = strstr(temp,"Eingabeparameter:")+ 18 ;
			while (*pos != '\n' && *pos != '\0') {
				while (*pos == ' ' || *pos == '\t')
					pos++ ;
				actpos = pos ;
				while(*pos != '\n' && *pos != '\t' && *pos != ' ')
					pos++ ;
				pos[0] = '\0' ;
				pos++ ;
				j = findname(indatanames,INPARS,actpos) ;
				if (j == -1) {
					fprintf(errfile,"Variable %s nicht gefunden\n",actpos) ;
					fflush(errfile) ; }
				else {
					inputvalues[inputvaluenr].column = j ; }
				while (*pos != '(')
					pos++ ;
				pos++ ;
				inputvalues[inputvaluenr].minval = atof(pos) ;
				while(*pos != ',')
					pos ++ ;
				pos++ ;
				inputvalues[inputvaluenr++].maxval = atof(pos) ;
				while(*pos != ')')
					pos ++ ;
				pos++ ; } }
		if (strstr(temp,"Ausgabeparameter:") != NULL) {
			pos = strstr(temp,"Ausgabeparameter:")+ 18 ;
			while (*pos != '\n' && *pos != '\0') {
				while (*pos == ' ' || *pos == '\t')
					pos++ ;
				actpos = pos ;
				while(*pos != '\n' && *pos != '\t' && *pos != ' ')
					pos++ ;
				pos[0] = '\0' ;
				pos++ ;
				j = findname(outdatanames,OUTPARS,actpos) ;
				if (j == -1) {
					fprintf(errfile,"Variable %s nicht gefunden\n",actpos) ;
					fflush(errfile) ; }
				else {
					outputvalues[outputvaluenr].column = j ; }
				while (*pos != '(')
					pos++ ;
				pos++ ;
				outputvalues[outputvaluenr].minval = atof(pos) ;
				while(*pos != ',')
					pos ++ ;
				pos++ ;
				outputvalues[outputvaluenr++].maxval = atof(pos) ;
				while(*pos != ')')
					pos ++ ;
				pos++ ; } } }

if (debuglevel > 0) {
	fprintf(errfile,"Eingabeparameter: ") ;
	for (i=0 ; i < inputvaluenr ; i++)
		fprintf(errfile,"%s(%f - %f %d) ",indatanames[inputvalues[i].column],inputvalues[i].minval,inputvalues[i].maxval,indatapos[inputvalues[i].column]) ;
	fprintf(errfile,"\n") ;
	fprintf(errfile,"Ausgabeparameter: ") ;
	for (i=0 ; i < outputvaluenr ; i++)
		fprintf(errfile,"%s(%f - %f) ",outdatanames[outputvalues[i].column],outputvalues[i].minval,outputvalues[i].maxval) ;
	fprintf(errfile,"\n") ;
	fflush(errfile) ;
}

	FCLOSE(parfile) ; }

Netz::~Netz() {
	if (inputvalues != NULL) {
		delete(inputvalues) ;
		delete(outputvalues) ; } }

int Netz::compute(FILE* infile, FILE* outfile, int (*netzfkt)(float*,float*,int)) {

	if (inputvalues == NULL)
		return(-1) ;

	char temp[1024] ;
	char* akt ;
	int i ;
	float* inputvals = new float[inputvaluenr] ;
	float* outputvals = new float[outputvaluenr] ;

	fgets(temp,1023,infile) ;


	while (fgets(temp,1023,infile) != NULL) {
if (debuglevel > 0) {
		fprintf(errfile,"%s",temp) ;
}
		for (i = 0 ; i < inputvaluenr ; i++) {
			inputvals[i] = adjust(atof(&temp[indatapos[inputvalues[i].column]]),inputvalues[i].minval,inputvalues[i].maxval) ;
if (debuglevel > 0) {
			fprintf(errfile,"%f ",readjust(inputvals[i],inputvalues[i].minval,inputvalues[i].maxval)) ;
}
			}

		netzfkt(inputvals,outputvals,0) ;
		for (i=0 ; i < outputvaluenr ; i++) {
			fprintf(outfile,"%f ",readjust(outputvals[i],outputvalues[i].minval,outputvalues[i].maxval));
if (debuglevel > 0) {
			fprintf(errfile,"%f ",readjust(outputvals[i],outputvalues[i].minval,outputvalues[i].maxval)); }
			fprintf(errfile,"\n") ;
			}
}
		fflush(errfile) ;
		fprintf(outfile,"\n") ; }

	delete(inputvals) ;
	delete(outputvals) ;
	return(1) ; }

int Netz::compute(DBSyllist* dbs, Proslist* p, int (*netzfkt)(float*,float*,int)) {

	if (inputvalues == NULL)
		return(-1) ;

	int i ;
	float* inputvals = new float[inputvaluenr] ;
	float* outputvals = new float[outputvaluenr] ;

	p->reset() ;
	dbs->reset() ;
	DBSyll d* ;
	Prosinfo* pr ;

	do {
		d = dbs->get_dbs_pointer() ;
		pr = p->get_pr_pointer() ;

		for (i = 0 ; i < inputvaluenr ; i++) {
			inputvals[i] = adjust(get_value(d,inputvalues[j].column),inputvalues[i].minval,inputvalues[i].maxval) ;
			}

		netzfkt(inputvals,outputvals,0) ;
		for (i=0 ; i < outputvaluenr ; i++) {
			put_value(pr,inputvalues[j].column,readjust(outputvals[i],outputvalues[i].minval,outputvalues[i].maxval))
			}

		p->advance() ;
		fflush(errfile) ; }

	while (dbs->advance()!= -1) ;

	delete(inputvals) ;
	delete(outputvals) ;
	return(1) ; }

#endif
