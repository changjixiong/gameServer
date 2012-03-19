#include "Telnet.h"

using namespace std;

namespace SocketLib
{
	void Telnet::Translate(Connection<Telnet>& p_conn, char *p_buffer, int p_size)
	{
		for (int i=0;i<p_size;i++)
		{
			char c=p_buffer[i];

			if (c>=32 && c!=127 && m_buffersize<BUFFERSIZE)
			{
				m_buffer[m_buffersize]=c;
				m_buffersize++;
			}
			else if ( c== 8 && m_buffersize>0)
			{
				m_buffersize--;
			}
			else if (c=='\n'|| c== '\r')
			{
				if (m_buffersize>0 && p_conn.Handler()!=0)
				{
					p_conn.Handler()->Handle( string( m_buffer,m_buffersize));
				}

				m_buffersize=0;
			}
			
		}
	}

	void Telnet::SendString( Connection<Telnet>& p_conn, std::string p_string )
	{
		p_conn.BufferData(p_string.data(),(int)p_string.size());
	}


}