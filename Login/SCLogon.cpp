// MUD Programming
// Ron Penton
// (C)2003
// SCLogon.cpp - A simple chat server's logon handler.
// 

#include "SCLogon.h"
#include "../Logic/SCChat.h"
#include "../UserDB/SCUserDB.h"

using namespace SocketLib;

// ------------------------------------------------------------------------
//  This handles incomming commands. Anything passed into this function
//  is assumed to be a complete command from a client.
// ------------------------------------------------------------------------
void SCLogon::Handle( string p_data )
{
    // record the connection pointer for future reference.
    Connection<Telnet>* conn = m_connection;

	
	printf(p_data.c_str());
	printf("\r\n");
    // make sure name is valid
    if( !UserDatabase::IsValidName( p_data ) )
    {
        conn->Protocol().SendString( *conn, "[invalid username]");
        return;
    }

    // make sure name doesn't exist already
    if( UserDatabase::HasUser( p_data ) )
    {
        conn->Protocol().SendString( *conn, "[user is existence");
        return;
    }

    // add the user
    UserDatabase::AddUser( conn, p_data );
    conn->Protocol().SendString( *conn, "[" +p_data+" is logining]");

    // set the new state machine
    conn->RemoveHandler();
    conn->AddHandler( new SCChat( *conn ) );
}



// ------------------------------------------------------------------------
//  This notifies the handler that a connection is entering the state
// ------------------------------------------------------------------------
void SCLogon::Enter()
{
    // welcome the new user
    m_connection->Protocol().SendString( *m_connection, "[user name]");
}



