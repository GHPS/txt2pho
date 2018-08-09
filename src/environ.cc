
#include "lisatalk.h"
#if !defined(__ENVIRON_H__)
#include "environ.h"
#endif

Environment::Environment(char* path, char* filename) {
	list = NULL ;
	char name[512] ;
	strcat(strcpy(name,path),filename) ;
	number = 0 ;
	FILE* env = FOPEN(name,"r") ;

	char* hostname = getenv("HOST") ;
	int host_fits = 1 ;

	if (env == NULL) {
		fprintf(errfile,"environment file %s not found\n",name) ;
		exit(1) ; }
	char buffer[512] ;
	while (fgets(buffer,511,env) != NULL) {
	        if (buffer[0] == '#' || strlen(buffer) < 2)
		  continue ;
		if (strncmp(buffer,"Hosts:",6) == 0) {
		  if (strchr(buffer,'*') != NULL)
		    host_fits = 1 ;
		  else
		    if (strstr(&buffer[6],hostname) != NULL)
		      host_fits=1 ;
		    else
		      host_fits = 0 ; }
		if (host_fits == 0)
		  continue ;
		if (list == NULL)
			list = (char**)malloc(1) ;
		list = (char**)realloc(list,(number+1)*sizeof(char*)) ;
		if (list == NULL) {
			exit(1) ; }
		list[number] = new char[strlen(buffer)] ;
		if (list[number] == NULL) {
			exit(1) ; }
		buffer[strlen(buffer)-1] = '\0' ;
		strcpy(list[number],buffer) ;
		number++ ; }
	FCLOSE(env) ; }

Environment::~Environment() {
	for (int i = 0 ; i < number ; i++)
		delete[](list[i]) ;
	free(list) ; }

char* Environment::get_value(char* key) {
	int i ;
	int ln = strlen(key) ;
	for (i=0 ; i < number ; i++)
		if ((list[i][ln] == '=') && (strncmp(key,list[i],ln-1) == 0))
			return(&(list[i][ln+1])) ;
	return("") ; }

int Environment::put_value(char* key, char* value) {
	int i ;
	int ln = strlen(key) ;
	for (i=0 ; i < number ; i++)
		if ((list[i][ln] == '=') && (strncmp(key,list[i],ln-1) == 0)) {
			delete(list[i]) ;
			list[i] = new char[strlen(key)+strlen(value)+2] ;
			sprintf(list[i],"%s=%s",key,value) ;
			break ; }
	return(1) ; }

void Environment::writex(char* filename) {
	FILE* env = FOPEN(filename,"w") ;
	int i ;
	for (i=0 ; i < number ; i++)
		fprintf(env,"%s\n",list[i]) ;
	FCLOSE(env) ; }

