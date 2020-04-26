#include "stdafx.h"
#include <memory>
#include <boost/tokenizer.hpp>
#include "DiskFile.h"
#include "DiskDirectory.h"

using namespace std;
using namespace std::filesystem;

DiskDirectory::DiskDirectory(const std::filesystem::path& path)
	: _path(path)
{
}

void DiskDirectory::doEach(const Callback& callback,
	const FilterFunction& filter, bool recursive)
{
	for (auto& iter : directory_iterator(_path)) {
		auto &path = iter.path();
		auto filename = path.string();
		auto extension = path.extension().string();
		if (!filter || filter(filename, extension)) {
			unique_ptr<IFile> ptr(new DiskFile(path));
			callback(move(ptr));
		}
	}
}

std::unique_ptr<IDirectory> DiskDirectory::path(const std::string& path)
{
	using namespace boost;
	char_separator<char> separator("\\/");
	tokenizer<char_separator<char>> tokenizer(path, separator);
	auto x = _path;
	for (auto i : tokenizer) {
		x = x / i;
	}
	return std::unique_ptr<IDirectory>(new DiskDirectory(x));
}
