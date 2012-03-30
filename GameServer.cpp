#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <iostream>

#include "ThreadLib/ThreadLib.h"
#include "SocketLib/SocketLib.h"

#include "UserDB/SCUserDB.h"
#include "Login/SCLogon.h"
#include "Chat/SCChat.h"

//由于windows.h和winsock2.h的关系
//"SocketLib/SocketLib.h"必须先包含
//或者ifndef WIN32_LEAN_AND_MEAN define WIN32_LEAN_AND_MEAN

using namespace std;

int main()
{
	using SocketLib::Telnet;
	
	SocketLib::ListeningManager<Telnet, SCLogon> lm;
	SocketLib::ConnectionManager<Telnet, SCLogon> cm( 128 );
	
	lm.SetConnectionManager( &cm );
	lm.AddPort( 5099 );
	
	while( 1 )
	{
		lm.Listen();
		cm.Manage();
		ThreadLib::YieldThread();
	}
	
}