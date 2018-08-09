class String {

	friend String operator+(String& a, String& b) ;
	friend int operator==(String& a, String& b) ;
	friend int operator!=(String& a, String& b) ;
	friend String operator<<(String& a, float x) ;
	friend String operator>>(String& a, float x) ;

public:
	char* v ;

//	~String() ;
	String() ;
	String(char* ini) ;
	String(int inlength) ; } ;

