#include <algorithm>
#include "SocketSet.h"

namespace SocketLib
{
	SocketSet::SocketSet()
	{
		FD_ZERO( &m_set );
		FD_ZERO( &m_activityset );
	}

	void SocketSet::AddSocket( const Socket& p_sock )
	{
		FD_SET( p_sock.GetSock(), &m_set );
		#ifndef WIN32
			m_socketdescs.insert( p_sock.GetSock() );
		#endif
	}

	void SocketSet::RemoveSocket( const Socket& p_sock )
	{
		FD_CLR( p_sock.GetSock(), &m_set );

		#ifndef WIN32
			m_socketdescs.erase( p_sock.GetSock() );
		#endif
	}
}