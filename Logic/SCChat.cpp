// MUD Programming
// Ron Penton
// (C)2003
// SCChat.cpp - this is a simple chatter handler

#include "SCChat.h"
#include <exception>

using namespace SocketLib;

// ------------------------------------------------------------------------
//  This handles incomming commands. Anything passed into this function
//  is assumed to be a complete command from a client.
// ------------------------------------------------------------------------
void SCChat::Handle( string p_data )
{
    // get the users name
    string name = UserDatabase::find( m_connection )->name;

	printf(p_data.c_str());
	printf("\r\n");

    // message is a command
    if( p_data[0] == '/' )
    {
        string command = BasicLib::ParseWord( p_data, 0 );
        string data = BasicLib::RemoveWord( p_data, 0 );

        if( command == "/who" )
        {
            string wholist = magenta + bold + "Who is in the room: ";

            UserDatabase::iterator itr = UserDatabase::begin();
            while( itr != UserDatabase::end() )
            {
                wholist += (*itr).name;

                ++itr;
                if( itr != UserDatabase::end() )
                {
                    wholist += ", ";
                }
            }
            wholist += newline;

            m_connection->Protocol().SendString( *m_connection, wholist );
        }

        else if( command == "/quit" )
        {
            CloseConnection( "has quit. Message: " + data );
            m_connection->Close();
        }
    }

    // else it's just regular text.
    else
    {
        if( BasicLib::TrimWhitespace( p_data ).size() > 0 )
        {
            SendAll( green + bold + "<" + name + "> " + reset + p_data );
        }
    }

}


// ------------------------------------------------------------------------
//  This notifies the handler that a connection is entering the state
// ------------------------------------------------------------------------
void SCChat::Enter()
{
//     SendAll( bold + yellow + UserDatabase::find( m_connection )->name +
//              " has entered the room." );
	SendAll( UserDatabase::find( m_connection )->name +
             " has entered the room." );
}


// ------------------------------------------------------------------------
//  This notifies the handler that a connection is leaving the state.
// ------------------------------------------------------------------------
void SCChat::Leave()
{
    UserDatabase::DeleteUser( m_connection );
}


// ------------------------------------------------------------------------
//  This notifies the handler that a connection has unexpectedly hung up.
// ------------------------------------------------------------------------
void SCChat::Hungup()
{
    CloseConnection( "has hung up!" );
}

// ------------------------------------------------------------------------
//  This notifies the handler that a connection is being kicked due to 
//  flooding the server.
// ------------------------------------------------------------------------
void SCChat::Flooded()
{
    CloseConnection( "has been kicked for flooding!" );
}

// ------------------------------------------------------------------------
//  Closes a connection, using a specified closing message
// ------------------------------------------------------------------------
void SCChat::CloseConnection( const string& p_reason )
{
//     SendAll( bold + red + UserDatabase::find( m_connection )->name +
//         " " + p_reason );
	SendAll( UserDatabase::find( m_connection )->name +
        " " + p_reason );
}


// ------------------------------------------------------------------------
//  Sends a message to all connections
// ------------------------------------------------------------------------
void SCChat::SendAll( const string& p_message )
{
    UserDatabase::iterator itr = UserDatabase::begin();

    // loop through every connection and send the message.
    while( itr != UserDatabase::end() )
    {
        //itr->connection->Protocol().SendString( *itr->connection, p_message + newline );
		itr->connection->Protocol().SendString( *itr->connection, p_message);
        ++itr;
    }
}

