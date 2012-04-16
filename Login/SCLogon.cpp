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

    // make sure name is valid
    if( !UserDatabase::IsValidName( p_data ) )
    {
        conn->Protocol().SendString( *conn, //red + bold + 
            "Sorry, that is an invalid username.\r\n" +
            string("Please enter another username: "));// + reset + bold );
        return;
    }

    // make sure name doesn't exist already
    if( UserDatabase::HasUser( p_data ) )
    {
        conn->Protocol().SendString( *conn, //red + bold + 
            "Sorry, that name is already in use.\r\n" +
            string("Please enter another username: "));// + reset );
        return;
    }

    // add the user
    UserDatabase::AddUser( conn, p_data );
    conn->Protocol().SendString( *conn, "Thank you for joining us, " + 
                                 p_data);// + newline );

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
    m_connection->Protocol().SendString( *m_connection, //green + bold + 
		"Welcome To SimpleChat!\r\n" + 
        string("Please enter your username: "));// + reset + bold );
}



