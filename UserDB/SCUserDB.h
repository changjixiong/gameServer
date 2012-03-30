// MUD Programming
// Ron Penton
// (C)2003
// SCUserDB.h - A simple chat server's user database.
// 


#ifndef SCUSERDB_H
#define SCUSERDB_H


#include "../SocketLib/SocketLib.h"
#include <string>
#include <list>


using std::string;
using SocketLib::Connection;
using SocketLib::Telnet;



class User
{
public:

    // default constructor
    User() { connection = 0; };

    // initialization constructor
    User( Connection<Telnet>* c, string& n )
        : connection( c ),
          name( n )
    {
        // no code
    }

    string name;
    Connection<Telnet>* connection;
};



class UserDatabase
{
public:

    // The following typedefs make the program easier to read.
    typedef std::list<User> users;
    typedef std::list<User>::iterator iterator;


    // --------------------------------------------------------------------
    //  returns an iterator pointing to the first connection
    // --------------------------------------------------------------------
    static iterator begin() { return m_users.begin(); }

    // --------------------------------------------------------------------
    //  returns the "invalid" iterator, the iterator that points one 
    //  past the end of the DB. Used for comparisons.
    // --------------------------------------------------------------------
    static iterator end() { return m_users.end(); }

    // --------------------------------------------------------------------
    //  finds an iterator based on its connection
    // --------------------------------------------------------------------
    static iterator find( Connection<Telnet>* p_connection );

    // --------------------------------------------------------------------
    //  adds a new user to the database; returns true on success.
    // --------------------------------------------------------------------
    static bool AddUser( Connection<Telnet>* p_connection, string p_name );

    // --------------------------------------------------------------------
    //  Deletes a user based on his connection
    // --------------------------------------------------------------------
    static void DeleteUser( Connection<Telnet>* p_connection );

    // --------------------------------------------------------------------
    //  deternimes if the database has a specified username
    // --------------------------------------------------------------------
    static bool HasUser( string& p_name );

    // --------------------------------------------------------------------
    //  determines if a username is valid or not.
    // --------------------------------------------------------------------
    static bool IsValidName( const string& p_name );



protected:

    static users m_users;
};


#endif
