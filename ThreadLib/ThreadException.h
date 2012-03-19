#ifndef THREADEXCEPTION_HEAD
#define THREADEXCEPTION_HEAD
#include <exception>

#ifdef WIN32
	#include <windows.h>
#else
	#include <pthread.h>
#endif

namespace ThreadLib
{
	enum Error
	{
		Unspecified,
		InitFailure,
		CreationFailure
	};

	class Exception : public exception
	{
	public:
		Exception( Error p_error = Unspecified)
		{
			m_error = p_error;
		}
		Error GetError() const
		{
			return m_error;
		}
	protected:
		Error m_error;
	
	};
}



#endif