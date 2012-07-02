// MUD Programming
// Ron Penton
// (C)2003
// SCChat.h - this is a simple chatter handler


#ifndef SCCHAT_H
#define SCCHAT_H

#include "../SocketLib/SocketLib.h"
#include "../UserDB/SCUserDB.h"
#include <string>

using SocketLib::Connection;
using SocketLib::Telnet;
using std::string;


class SCChat : public Telnet::handler
{
    typedef Telnet::handler thandler;
public:

    SCChat( Connection<Telnet>& p_conn )
        : thandler( p_conn ) {};

    // ------------------------------------------------------------------------
    //  This handles incomming commands. Anything passed into this function
    //  is assumed to be a complete command from a client.
    // ------------------------------------------------------------------------
    void Handle( string p_data );

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection is entering the state
    // ------------------------------------------------------------------------
    void Enter();

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection is leaving the state.
    // ------------------------------------------------------------------------
    void Leave();

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection has unexpectedly hung up.
    // ------------------------------------------------------------------------
    void Hungup();

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection is being kicked due to 
    //  flooding the server.
    // ------------------------------------------------------------------------
    void Flooded();

    // ------------------------------------------------------------------------
    //  Closes a connection, using a specified closing message
    // ------------------------------------------------------------------------
    void CloseConnection( const string& p_reason );

    // ------------------------------------------------------------------------
    //  Sends a message to all connections
    // ------------------------------------------------------------------------
    void SendAll( const string& p_message );

};

#endif
