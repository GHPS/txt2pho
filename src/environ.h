
#if !defined(__ENVIRON_H__)
#define __ENVIRON_H__


class Environment {

	char** list ;
	int number ;

public:
	Environment(char* path, char* filename) ;
	~Environment() ;
	void writex(char* filename) ;
	int put_value(char* key, char* value) ;
	char* get_value(char* key) ; } ;


#endif

