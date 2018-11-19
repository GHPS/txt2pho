
#if !defined(__ENVIRON_H__)
#define __ENVIRON_H__


class Environment {

	char** list ;
	int number ;

public:
	Environment(const char* path, const char* filename) ;
	~Environment() ;
	void writex(const char* filename) ;
	int put_value(char* key, char* value) ;
	char* get_value(const char* key) ; } ;


#endif

