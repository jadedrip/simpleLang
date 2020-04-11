#pragma once
#include <functional>
#include <memory>
#include "FileSystem\IFile.h"

struct IDirectory {
	typedef std::function<void(std::unique_ptr<IFile>&&)> Callback;
	typedef std::function<bool(const std::string&/*filename*/, const std::string&/*extension*/)> FilterFunction;

	class ForeachStreams {
		friend struct IDirectory;
	private:
		ForeachStreams(IDirectory* dir) {
			_dir = dir;
		}
	public:
		ForeachStreams& filter(const FilterFunction& filterFunc) {
			_filterFunc = filterFunc;
			return *this;
		}
		ForeachStreams& recusive(bool recusive) {
			_recusive = recusive;
			return *this;
		}
		void loop(const Callback& callback) {
			_dir->doEach(callback, _filterFunc, _recusive); 
		}
	private:
		bool _recusive = false;
		FilterFunction _filterFunc;
		IDirectory* _dir;
	};

	ForeachStreams& forEach() {
		return ForeachStreams(this);
	}
protected:
	virtual void doEach(
		const Callback& callback,
		const FilterFunction& filter,
		bool recursive=false
	) = 0;
};
