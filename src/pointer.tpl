
#if !defined(POINTER_TEMPLATE)
#define POINTER_TEMPLATE


template <class T> Pointer<T>::Pointer () :
	mem(NULL),
	offset(0)
{
}


template <class T> Pointer<T>::Pointer (const Pointer<T> &p) :
	mem(p.mem),
	offset(p.offset)
{
	if (mem)
		mem->IncRefCount();
}


template <class T> Pointer<T>::Pointer (T *pT) :
	mem(pT ? new Memory(pT) : NULL),
	offset(0)
{
}


template <class T> Pointer<T>::~Pointer ()
{
	if (mem != NULL)
		mem->DecRefCount();
}


template <class T> Pointer<T> &Pointer<T>::operator= (const Pointer<T> &p)
{
	if (&p != this)
	{
		if (mem != NULL)
			mem->DecRefCount();

		mem = p.mem;
		offset = p.offset;

		if (mem != NULL)
			mem->IncRefCount();
	}
	return *this;
}


template <class T> Pointer<T> &Pointer<T>::operator+= (long i)
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset + i <= mem->Size(), XOutOfRange);

	offset += i;
	return *this;
}


template <class T> Pointer<T> &Pointer<T>::operator-= (long i)
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset - i >= 0, XOutOfRange);

	offset -= i;
	return *this;
}


template <class T> Pointer<T> Pointer<T>::operator++ ()
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset <= mem->Size(), XOutOfRange);

	++offset;
	return *this;
}


template <class T> Pointer<T> Pointer<T>::operator++ (int /* dummy */)
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset <= mem->Size(), XOutOfRange);

	Pointer<T> result = *this;
	offset++;
	return result;
}


template <class T> Pointer<T> Pointer<T>::operator-- ()
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset >= 0, XOutOfRange);

	--offset;
	return *this;
}


template <class T> Pointer<T> Pointer<T>::operator-- (int /* dummy */)
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset >= 0, XOutOfRange);

	Pointer<T> result = *this;
	offset--;
	return result;
}


template <class T> T &Pointer<T>::operator* ()
{
	Assert(mem != NULL, XNullPointerAccess);

	return *(mem->Data() + offset);
}


template <class T> T Pointer<T>::operator* () const
{
	Assert(mem != NULL, XNullPointerAccess);

	return *(mem->Data() + offset);
}


template <class T> T &Pointer<T>::operator[] (long i)
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset + i >= 0 && offset + i < mem->Size(), XOutOfRange);

	return *(mem->Data() + offset + i);
}


template <class T> T Pointer<T>::operator[] (long i) const
{
	Assert(mem != NULL, XNullPointerAccess);
	Assert(offset + i >= 0 && offset + i < mem->Size(), XOutOfRange);

	return *(mem->Data() + offset + i);
}


template <class T> Pointer<T>::operator T * ()
{
	if (!mem)
		return NULL;
	else
		return mem->Data() + offset;
}


template <class T> bool operator== (const Pointer<T> &p1, const Pointer<T> &p2)
{
	return (p1.mem + p1.offset == p2.mem + p2.offset) ? true : false;
}


template <class T> bool operator!= (const Pointer<T> &p1, const Pointer<T> &p2)
{
	return !(p1 == p2);
}


template <class T> bool operator< (const Pointer<T> &p1, const Pointer<T> &p2)
{
}


template <class T> bool operator> (const Pointer<T> &p1, const Pointer<T> &p2)
{
}


template <class T> bool operator<= (const Pointer<T> &p1, const Pointer<T> &p2)
{
	return p1 < p2 || p1 == p2;
}


template <class T> bool operator>= (const Pointer<T> &p1, const Pointer<T> &p2)
{
	return p1 > p2 || p1 == p2;
}


template <class T> Pointer<T> operator+ (const Pointer<T> &p, long i)
{
	Pointer<T> result = p;

	result += i;
	return result;
}


/*
template <class T> Pointer<T>::Memory::Memory () :
	data(NULL),
	size(0),
	refcount(0)
{
}


template <class T> Pointer<T>::Memory::Memory (T *pT) :
	data(pT),
	size(LONG_MAX),                  // wie bestimmt man die Groesse eines Blocks
	refcount(1)
{
}


template <class T> Pointer<T>::Memory::~Memory ()
{
}


template <class T> T *Pointer<T>::Memory::Data ()
{
	return data;
}


template <class T> int Pointer<T>::Memory::RefCount ()
{
	return refcount;
}


template <class T> long Pointer<T>::Memory::Size ()
{
	return size;
}


template <class T> void Pointer<T>::Memory::IncRefCount ()
{
	refcount++;
}


template <class T> void Pointer<T>::Memory::DecRefCount ()
{
	refcount--;
}
*/


#endif

