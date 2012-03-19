#ifndef SOCKETLIBTYPES_HEAD
#define SOCKETLIBTYPES_HEAD

#ifdef WIN32
	#pragma comment(lib,"ws2_32.lib")
	#include <WINSOCK2.H>
	#include <WS2TCPIP.H>

	#ifndef socklen_t
		typedef int socklen_t;
	#endif

#else
	#include <sys/types.h>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <unistd.h>
	#include <netdb.h>
	#include <arpa/inet.h>
	#include <errno.h>
	#include <fcntl.h>
#endif


namespace SocketLib
{
	#ifdef WIN32
		typedef SOCKET sock;
	#else
		typedef int sock;
	#endif

	typedef unsigned short int port;
	typedef unsigned long int ipaddress;
}

#endif