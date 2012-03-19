#ifndef SOCKETLIBSYSTEM_HEAD
#define SOCKETLIBSYSTEM_HEAD

#include <string>
#include "SocketLibTypes.h"

namespace SocketLib
{
	ipaddress GetIPAddress( const std::string p_address );
	
	std::string GetIPString( ipaddress p_address );
	
	std::string GetHostNameString( ipaddress p_address );

	// ========================================================================
    // Function:    IsIPAddress
    // Purpose:     determines if a string contains a pure numerical IP address
    //              (returns true) or a DNS'able address (returns false)
    // ========================================================================
	bool IsIPAddress( const std::string p_address );
}

#endif