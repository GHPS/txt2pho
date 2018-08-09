
#if !defined(PTREXCPT_HEADER)
#define PTREXCPT_HEADER


#if !defined NDEBUG
#define Assert(assertion, exception)  \
	if (assertion)                    \
		;                             \
	else                              \
		throw exception()
#else
#define Assert(assertion, exception)  \
	((void)0)
#endif


class XPointerException
{
};


class XOutOfRange : XPointerException
{
};


class XNullPointerAccess : XPointerException
{
};


#endif
