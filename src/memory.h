
#if !defined(MEMORY_HEADER)
#define MEMORY_HEADER


////////////////////////////////////////////////////////////////////////////////////////

template <class T> class Memory
{
		T *data;
		long size;
		int refcount;

	public:
		Memory ();
		~Memory ();

	friend class Pointer<T>;
};


#if !defined(__MEMORY_TPL_)


#endif

