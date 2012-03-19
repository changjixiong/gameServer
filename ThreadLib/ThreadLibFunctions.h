#ifndef THREADLIBFUNCTIONS_HEAD
#define THREADLIBFUNCTIONS_HEAD


#ifdef WIN32		
	#include <windows.h>
	#include <atlbase.h>
	#include <map>
#else
	#include <pthread.h>
#endif

#include "ThreadException.h"

namespace ThreadLib
{
	#ifdef WIN32
		typedef DWORD ThreadID;
		extern std::map< DWORD, HANDLE > g_handlemap;
	#else		
		typedef pthread_t ThreadID;		
	#endif

 

	typedef void (*ThreadFunc)(void *);
	class DummyData
	{
	public:
		ThreadFunc m_func;
		void * m_data;
	};

    #ifdef WIN32
        DWORD WINAPI DummyRun( void* p_data );
    #else
        void* DummyRun( void* p_data );
    #endif

	inline ThreadID Create(ThreadFunc p_func, void * p_param)
	{
		ThreadID t;
		DummyData * pdata=new DummyData;
		pdata->m_func=p_func;
		pdata->m_data=p_param;
		#ifdef WIN32
			HANDLE h;
			h=CreateThread(NULL, 0, DummyRun, pdata, 0, &t);
			if ( h != 0)
			{
				g_handlemap[t]=h;
			}
		#else
			pthread_create( &t, 0, DummyRun, pdata );			
		#endif
			if ( t == 0 )
			{
				delete pdata;
				pdata=NULL;
				throw Exception( CreationFailure);
			}

		return t;
	}

	inline ThreadID GetID()
	{
		#ifdef WIN32
			return GetCurrentThreadId();
		#else
			return pthread_self();
		#endif
	}

	inline void WaitForFinish( ThreadID p_thread)
	{
		#ifdef WIN32
			WaitForSingleObject( g_handlemap[p_thread], INFINITE );
			CloseHandle( g_handlemap[p_thread] );
			g_handlemap.erase( p_thread );
		#else
			pthread_join( p_thread, NULL );
		#endif
	}

	inline void Kill( ThreadID p_thread)
	{
		#ifdef WIN32
			TerminateThread( g_handlemap[p_thread], 0 );
			CloseHandle( g_handlemap[p_thread] );
			g_handlemap.erase( p_thread );
		#else
			pthread_cancle( p_thread );
		#endif
	}

	inline void YieldThread( int p_milliseconds = 1)
	{
		#ifdef WIN32
			Sleep( p_milliseconds );
		#else
			usleep( p_milliseconds*1000 );
		#endif
	}	
	
}

#endif