
#if !defined(__HARRAY_H__) && defined(_Windows)
#define __HARRAY_H__


template <class T> class HugeArray
{
		HGLOBAL __hGlobal;
		unsigned long __Size, __Offset;
		BOOL __Locked;
		T *__LockedPtr;

		T *getPtr (T *, unsigned long offset) const;

	public:
		HugeArray (unsigned long count);
		~HugeArray ();

		BOOL Append (const T *block, unsigned long count);
		unsigned long Used () const;
		T *Lock ();
		BOOL Unlock ();
		BOOL Dump (FILE *file);
		void Reset() ;

		T &operator[] (unsigned long count);
		operator HGLOBAL () const;
} ;


#include "harray.tpl"


#endif

