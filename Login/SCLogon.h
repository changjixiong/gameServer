// MUD Programming
// Ron Penton
// (C)2003
// SCLogon.h - A simple chat server's logon handler.
// 


#ifndef SCLOGON_H
#define SCLOGON_H


#include "../SocketLib/SocketLib.h"
#include "../UserDB/SCUserDB.h"
#include <string>

using SocketLib::Connection;
using SocketLib::Telnet;
using std::string;


// ------------------------------------------------------------------------
//  This is the logon handler; it will manage all users who are logging
//  on to the server by getting and validating their usernames.
// ------------------------------------------------------------------------
class SCLogon : public Telnet::handler
{
    typedef Telnet::handler thandler;
public:
    
    SCLogon( Connection<Telnet>& p_conn )
        : thandler( p_conn ) {};

    // ------------------------------------------------------------------------
    //  This handles incomming commands. Anything passed into this function
    //  is assumed to be a complete command from a client.
    // ------------------------------------------------------------------------
    void Handle( string p_data );

    // ------------------------------------------------------------------------
    //  This tells a connection that there is no room for the connection and
    //  that it will be terminated.
    // ------------------------------------------------------------------------
    static void NoRoom( Connection<Telnet>& p_connection )
    {
        static string msg = "Sorry, there is no more room on this server.\r\n";
        try
        {
            p_connection.Send( msg.c_str(), (int)msg.size() );
        }
        catch( SocketLib::Exception )
        {
            // do nothing here; probably an exploiter if sending that data
            // causes an exception.
        }
    }

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection is entering the state
    // ------------------------------------------------------------------------
    void Enter();

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection is leaving the state.
    // ------------------------------------------------------------------------
    void Leave() {};

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection has unexpectedly hung up.
    // ------------------------------------------------------------------------
    void Hungup() {};

    // ------------------------------------------------------------------------
    //  This notifies the handler that a connection is being kicked due to 
    //  flooding the server.
    // ------------------------------------------------------------------------
    void Flooded() {};
};




#endif
