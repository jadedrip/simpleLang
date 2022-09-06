#pragma once
#include <string>
#include <sstream>
#include <fstream>

#include <boost/lexical_cast.hpp>

#include <boost/date_time/posix_time/posix_time.hpp>

enum severity_level
{
	debug=0,
	info,
	warning,
	error,
	critical
};

inline std::ostream& operator<< ( std::ostream& strm, severity_level lvl )
{
	static const char* const str[] = {
		"debug",
		"info",
		"warning",
		"error",
		"critical"		
	};
	if ( static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)) ) 
		strm << str[lvl];
	else
		strm << static_cast< int >(lvl);
	return strm;
}

std::thread* initializeLog( const std::string& filename, int lvl, bool to_terminal=false );

void set_auto_reset( size_t sec );

/// 输出日志
class logger : boost::noncopyable
{
public:
	logger(severity_level level = severity_level::info);

	~logger();

	template< typename T >
	logger& operator()( const std::string& key, const T& value )
	{
		assert( !_end );
		if( _active )
			_ss << key << " : " << value << " | ";
		return *this;
	}

	template< typename T >
	logger& operator << ( const T& v )
	{
		if( _active )	// 忽略被过滤的数据，以提高效率
			_ss << v;
		_end=true;
		return *this;
	}
private:
	bool _end;
	bool _active;
	std::ostringstream _ss;
};
