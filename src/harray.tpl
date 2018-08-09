
#if !defined(__HARRAY_TPL__) && defined(_Windows)
#define __HARRAY_TPL__

#include "dos.h"

template <class T> T *HugeArray<T>::getPtr (T *ptr, unsigned long offset) const
{
#if !defined(__WIN32__)
	offset += FP_OFF(ptr);
	FP_SEG(ptr) += HIWORD(offset) * __SegIncr;
	FP_OFF(ptr) = LOWORD(offset);
	return ptr;
#else
	return ptr + (offset / sizeof(T));
#endif
}


template <class T> HugeArray<T>::HugeArray (unsigned long count)
{
	__hGlobal   = GlobalAlloc(GMEM_MOVEABLE | GMEM_NODISCARD | GMEM_SHARE, count * sizeof(T));
	__Size      = (__hGlobal != NULL) ? count * sizeof(T) : 0;
	__Offset    = 0;
	__Locked    = FALSE;
	__LockedPtr = NULL;
}


template <class T> HugeArray<T>::~HugeArray ()
{
	while (__Locked)
		__Locked = GlobalUnlock(__hGlobal);
	GlobalFree(__hGlobal);
}


template <class T> BOOL HugeArray<T>::Append (const T *block, unsigned long count)
{
	T *buffer, *ptr;

	if (__Offset + count * sizeof(T) > __Size)
		return FALSE;
	buffer = Lock();
	if (__Offset % 0x10000L + count * sizeof(T) <= 0x10000L)
	{
		ptr = getPtr(buffer, __Offset);
		memcpy(ptr, block, count * sizeof(T));
		__Offset += count * sizeof(T);
	}
	else
	{
		unsigned long part1 = (0x10000L - (__Offset % 0x10000L)) / sizeof(T);
		unsigned long part2 = count - part1;

		ptr = getPtr(buffer, __Offset);
		memcpy(ptr, block, part1 * sizeof(T));
		__Offset += part1 * sizeof(T);
		ptr = getPtr(buffer, __Offset);
		memcpy(ptr, block + part1, part2 * sizeof(T));
		__Offset += part2 * sizeof(T);
	}
	Unlock();
	return TRUE;
}


template <class T> unsigned long HugeArray<T>::Used () const
{
	return __Offset / sizeof(T);
}


template <class T> T *HugeArray<T>::Lock ()
{
	if (!__Locked)
	{
		__Locked = TRUE;
		__LockedPtr = (T *) GlobalLock(__hGlobal);
	}
	return __LockedPtr;
}


template <class T> BOOL HugeArray<T>::Unlock ()
{
	if (__Locked)
	{
		__Locked = GlobalUnlock(__hGlobal);
		if (!__Locked)
			__LockedPtr = NULL;
	}
	return __Locked;
}


template <class T> BOOL HugeArray<T>::Dump (FILE *file)
{
	T *ptr = Lock();
	int complete_blocks = __Offset / 0x8000;
   int i ;

	for (i = 0; i < complete_blocks; i++)
		fwrite(getPtr(ptr, (unsigned long) i * 0x8000), 0x8000, 1, file);
	fwrite(getPtr(ptr, (unsigned long) i * 0x8000), __Offset % 0x8000, 1, file);
	Unlock();
	return TRUE ;
}


template <class T> T &HugeArray<T>::operator[] (unsigned long index)
{
	T *buffer, *ptr;

	buffer = Lock();
	ptr = getPtr(buffer, index * sizeof(T));
	return *ptr;
}


template <class T> HugeArray<T>::operator HGLOBAL () const
{
	return __hGlobal;
}


#endif

