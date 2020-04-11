#pragma once
#include <exception>
#include <string>

class LoadFileException : public std::exception
{
public:
	LoadFileException( const std::string& filename, 
		const std::string& err) : _filename(filename), _error(err),
		std::exception(makeMessage(filename,err)) {}
public:
	const std::string& filename() const { return _filename; }
	const std::string& error() const { return _error;  }
private:
	std::string _filename;
	std::string _error;
private:
	static const char* makeMessage(const std::string& filename, const std::string& err) {
		std::string msg = "Load file " + filename + " failed: " + err;
		return msg.c_str();
	}
};