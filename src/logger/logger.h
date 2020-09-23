#pragma once
#include <string>
#include <sstream>
#include <fstream>
#include <boost/thread/mutex.hpp>
#include <boost/thread.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <tbb/concurrent_queue.h>

namespace lugce{ namespace log{
	enum severity_level
	{
		debug=0,
		normal,
		info,
		notification,
		warning,
		error,
		critical,
		deadly,
		unknow
	};

	inline std::ostream& operator<< ( std::ostream& strm, severity_level lvl )
	{
		static const char* const str[] =
		{
			"debug",
			"normal",
			"info",
			"notification",
			"warning",
			"error",
			"critical",
			"deadly",
			"unknow"
		};
		if ( static_cast< std::size_t >(lvl) < (sizeof(str) / sizeof(*str)) ) 
			strm << str[lvl];
		else
			strm << static_cast< int >(lvl);
		return strm;
	}

	/// 重置日志，开始一个新文件
	void reset();

	boost::thread* initialize( const std::string& filename, int lvl, bool to_terminal=false );

	void set_auto_reset( size_t sec );

	/// 输出日志
	class logger : boost::noncopyable
	{
	public:
		logger(severity_level level );

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
}; };
