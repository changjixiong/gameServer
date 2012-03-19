#ifndef BASICLIBTYPES_HEAD
#define BASICLIBTYPES_HEAD

namespace BasicLib
{
	#ifdef __GNUC__		
		#define GOODCOMPILER
		typedef long long int sint64;
		typedef unsigned long long int uint64;
	#endif

	#ifdef WIN32
		#if _MSC_VER >= 1300
			#define GOODCOMPILER
		#else
			#define CRAPPYCOMPILER
		#endif
		
		typedef __int64 sint64;
		typedef unsigned __int64 uint64;

	#endif

	typedef signed long int sint32;
	typedef unsigned long int uint32;
	typedef signed short int sint16;
	typedef unsigned short int uint16;
	typedef signed char sint8;
	typedef unsigned char uint8;

	const double pi = 3.1415926535897932384626433832795;
}
#endif