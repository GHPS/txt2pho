
#if !defined(POINTER_HEADER)
#define POINTER_HEADER


#include <stdlib.h>


#include "memory.h"


////////////////////////////////////////////////////////////////////////////////////////

template <class T> class Pointer
{
		Memory<T> *mem;
		long offset;

	public:
		Pointer ();
		Pointer (const Pointer<T> &p);
		Pointer (T *pT);

		~Pointer ();

		void Delete ();

		Pointer<T> &operator= (const Pointer<T> &p);
		Pointer<T> &operator= (const T *pT);

		Pointer<T> &operator+= (long i);
		Pointer<T> &operator-= (long i);

		Pointer<T> operator++ ();
		Pointer<T> operator++ (int /* dummy */);
		Pointer<T> operator-- ();
		Pointer<T> operator-- (int /* dummy */);

		T &operator* ();
		T operator* () const;

		T &operator[] (long i);
		T operator[] (long i) const;

//      T *operator-> ();
//      T *operator-> () const;

		// Cast-Operatoren
		operator T * () const;
//      operator const T * () const;

	friend Pointer<T> operator+ (const Pointer<T> &p, long i);
	friend Pointer<T> operator- (const Pointer<T> &p, long i);
	friend long operator- (const Pointer<T> &p1, const Pointer<T> &p2);

/*
	friend Pointer<T> calloc (size_t nitems, size_t size);
	friend void free (Pointer<T> block);
	friend Pointer<T> malloc (size_t size);
	friend Pointer<T> realloc (Pointer<T> block, size_t size);
*/
};


#include "pointer.tpl"


#endif

