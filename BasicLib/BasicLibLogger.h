#ifndef BASICLIBLOGGER_HEAD
#define BASICLIBLOGGER_HEAD

#include <string>
#include <fstream>
#include "BasicLibTime.h"

namespace BasicLib
{
	class TextDecorator
	{
	public:
		static std::string FileHeader( const std::string& p_title )
		{
			return "==================================================\n" +
				p_title + "\n" +
                   "==================================================\n\n";

		}

		static std::string SessionOpen()
		{
			return "\n";
		}

		static std::string SessionClose()
		{
			return "\n";
		}

		static std::string Decorate( const std::string& p_string )
		{
			return p_string + "\n";
		}
	
	};

	template<typename decorator>
	class Logger
	{
	public:
		Logger( const std::string& p_filename,
				const std::string& p_logtitle,
				bool p_timestamp = false,
				bool p_datestamp = false);
		~Logger();
		void Log( const std::string& p_entry );
	protected:
		std::fstream m_logfile;
		bool m_timestamp;
		bool m_datestamp;
	
	};

	typedef Logger<TextDecorator> TextLog;

	template<typename decorator>
	Logger<decorator>::Logger( const std::string& p_filename,
								const std::string& p_logtitle,
								bool p_timestamp,
								bool p_datestamp)
	{
		std::fstream filetester( p_filename.c_str(), std::ios::in );

		if ( filetester.is_open() )
		{
			filetester.close();
			m_logfile.open( p_filename.c_str(), std::ios::out | std::ios::app );
		}
		else
		{
			m_logfile.open( p_filename.c_str(), std::ios::out );
			m_logfile << decorator::FileHeader( p_logtitle );
		}

		m_timestamp = true;
		m_datestamp = true;
		m_logfile << decorator::SessionOpen();
		Log( "Session opened." );
		m_timestamp = p_timestamp;
		m_datestamp = p_datestamp;

	}

	template<typename decorator>
	Logger<decorator>::~Logger()
	{
		m_timestamp = true;
		m_datestamp = true;
		Log( "Session closed." );
		m_logfile << decorator::SessionClose();
	}

	template<typename decorator>
	void Logger<decorator>::Log( const std::string& p_entry )
	{
		std::string message;
		
		message += m_datestamp ? "[" + DateStamp() + "] " : "";
		message += m_timestamp ? "[" + TimeStamp() + "] " : "";
		
		message += p_entry;
		m_logfile << decorator::Decorate( message );
		m_logfile.flush();		
	}

}

#endif