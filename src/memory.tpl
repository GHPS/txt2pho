
#if !defined(MEMORY_TEMPLATE)
#define MEMORY_TEMPLATE


#include <limits.h>


template <class T> Memory<T>::Memory () :
	data(NULL),
	size(0),
	refcount(0)
{
}


template <class T> Memory<T>::Memory (T *pT) :
	data(pT),
	size(LONG_MAX),                  // wie bestimmt man die Groesse eines Blocks
	refcount(1)
{
}


template <class T> Memory<T>::~Memory ()
{
}


template <class T> T *Memory<T>::Data ()
{
	return data;
}


template <class T> int Memory<T>::RefCount ()
{
	return refcount;
}


template <class T> long Memory<T>::Size ()
{
	return size;
}


template <class T> void Memory<T>::IncRefCount ()
{
	refcount++;
}


template <class T> void Memory<T>::DecRefCount ()
{
	refcount--;
}


#endif

