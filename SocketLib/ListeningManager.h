#ifndef LISTENINGMANAGER_HEAD
#define LISTENINGMANAGER_HEAD

#include "SocketLibTypes.h"
#include "SocketLibSocket.h"
#include "SocketSet.h"
#include "SocketLibErrors.h"
#include "ConnectionManager.h"
#include <vector>

namespace SocketLib
{
	template< typename protocol, typename defaulthandler>
	class ConnectionManager;

	template< typename protocol, typename defaulthandler>
	class ListeningManager
	{
		public:
			ListeningManager();
			~ListeningManager();
			void AddPort( port p_port );

			void SetConnectionManager( ConnectionManager<protocol,defaulthandler>* p_manager);

			void Listen();
		protected:

			std::vector<ListeningSocket> m_sockets;
			SocketSet m_set;

			ConnectionManager<protocol,defaulthandler>* m_manager;
	};

	template< typename protocol, typename defaulthandler>
	ListeningManager<protocol,defaulthandler>::ListeningManager()
	{
		m_manager=0;
	}

	template< typename protocol, typename defaulthandler>
	ListeningManager<protocol,defaulthandler>::~ListeningManager()
	{
		for (size_t i=0; i<m_sockets.size();i++)
		{
			m_sockets[i].Close();
		}
		
	}

	template< typename protocol, typename defaulthandler>
	void ListeningManager<protocol,defaulthandler>::AddPort( port p_port )
	{
		if (m_sockets.size() == MAX)
		{
			Exception e(ESocketLimitReached);
			throw(e);
		}

		ListeningSocket lsock;

		lsock.Listen(p_port);

		lsock.SetBlocking(false);
		
		m_sockets.push_back( lsock );
		m_set.AddSocket( lsock);
	}

	template< typename protocol, typename defaulthandler>
	void ListeningManager<protocol,defaulthandler>::
	SetConnectionManager(ConnectionManager<protocol,defaulthandler>* p_manager)
	{
		m_manager = p_manager;
	}

	template< typename protocol, typename defaulthandler>
	void ListeningManager<protocol,defaulthandler>::Listen()
	{
		DataSocket datasock;

		if (m_set.Poll()>0)
		{
			for (size_t s=0;s<m_sockets.size();s++)
			{
				if (m_set.HasActivity(m_sockets[s]))
				{
					try
					{
						datasock =m_sockets[s].Accept();
						m_manager->NewConnection(datasock);
					}
					catch (Exception& e)
					{
						if (e.ErrorCode()!=EOperationWouldBlock)
						{
							throw(e);
						}
					}
				}
			}
		}
	}
}



#endif