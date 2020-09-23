#include <sstream>
#include <iostream>
#include <boost/bind.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <tbb/concurrent_queue.h>
#include <tbb/concurrent_hash_map.h>
#include "logger.h"

namespace lugce{ namespace log{
	severity_level _filter;
	bool _to_terminal;
	tbb::concurrent_queue<std::string> _queue;

	size_t sustain;
	time_t laset_reset;
	std::string log_filename;
	boost::shared_ptr< std::ostream > logfile;

	boost::mutex _mutex;
	std::map< uint32_t, std::string > _delay_routines;

	typedef std::vector< std::pair< severity_level, std::string > > routine_data;
	typedef tbb::concurrent_hash_map< std::string, routine_data* > routines_type;
	extern routines_type _routines;

	static void log_work();

	static void do_nothing( std::ostream* ){}

	void routine_timeout( const std::string& key )
	{
		routines_type::accessor a;
		if( _routines.find(a,key) ){
			routine_data* p=a->second;
			_routines.erase(a);

			for( std::pair< severity_level, std::string >& v : *p ){
				_queue.push( v.second );
			}
			delete p;
		}
	}

	void log_work()
	{
		using namespace boost;
		using namespace boost::posix_time;
		std::string log_info;

		int x=0; // 防止队列始终满的情况下无法进入超时保护
		while(!boost::this_thread::interruption_requested()){
			if( (x++ < 10000) && _queue.try_pop(log_info) ){
				boost::shared_ptr< std::ostream > f=logfile;
				if( f ){
					if( !f->good() ){ reset(); f->clear(); }
					*f << log_info << std::endl;
				}
			}else{
				x=0;
				if( laset_reset > 0 ){
					if( sustain>0 && (time(NULL)-laset_reset) > sustain )
						reset();
				}

				boost::mutex::scoped_try_lock lock( _mutex );
				if( lock && !_delay_routines.empty() ){
					auto i=_delay_routines.begin();
					if( i->first > uint32_t(time(NULL)) ){
						std::string s=i->second;
						_delay_routines.erase(i);
						lock.unlock();
						routine_timeout(s);
					}
				}else{
					boost::this_thread::sleep( boost::posix_time::milliseconds(4) );
				}
			}
		}
	}

	void print_line( const std::string& str )
	{
		if( _to_terminal ){ // 输出到控制台（低效）
			static boost::mutex mtx;
			boost::mutex::scoped_lock lock( mtx );	// 尝试加入锁，防止 local_time 非线程安全
			std::cout << str << std::endl;
		}

		if( _queue.unsafe_size() < 10000 )
			_queue.push( str );
	}

	void reset()
	{
		using namespace std;
		using namespace boost::posix_time;

		std::cout << "\t日志等级：" << _filter << std::endl;

		time_facet* lif2=new time_facet("%Y.%m.%d %H:%M:%S");
		if( !log_filename.empty() ){
			std::stringstream ss;
			ss.imbue(std::locale(ss.getloc(), new time_facet("_%Y%m%d_%H_%M_%S")));
			ss << boost::posix_time::second_clock::local_time();

			string filename=log_filename;
			string::size_type i=filename.find_last_of('.');
			if( i==string::npos ){
				filename+=ss.str() + ".log";
			}else{
				string base=filename.substr( 0, i );
				string ex=filename.substr(i);
				filename=base + ss.str() + ex;
			}

			std::cout << "初始化日志，日志文件名：" << filename << std::endl;

			std::ofstream* p=new std::ofstream(filename.c_str());
			if( p->is_open() ){
				p->imbue(std::locale( p->getloc(), lif2));
				logfile.reset( p );
			}else{
				std::cerr << "警告：无法写入日志文件：" << filename << std::endl;
				std::clog.imbue(std::locale( p->getloc(), lif2));
				logfile.reset( &std::clog, &do_nothing );
			}
			time(&laset_reset);
		}else{
			std::clog.imbue(std::locale( std::clog.getloc(), lif2));
			logfile.reset( &std::clog, &do_nothing );
			laset_reset=0;
		}
	}

	boost::thread* initialize( const std::string& filename, int lvl, bool to_terminal/*=false */ )
	{
		log_filename=filename;
		_to_terminal=to_terminal;
		_filter=severity_level(lvl);
		reset();
		return new boost::thread( &log_work );
	}

	void set_auto_reset( size_t sec )
	{
		sustain=sec;
	}

	logger::logger( severity_level level ) : _end(false)
	{
		if( level >= _filter ){
			_active=true;
			boost::posix_time::ptime ptime=boost::posix_time::microsec_clock::local_time();
			_ss << "<" << level << " - " << ptime << ">";
		}else{
			_active=false;
		}
	}

	logger::~logger()
	{
		if( _active ) print_line( _ss.str() );
	}

} };
