#include "stdafx.h"
#include <memory>
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
		if (filter(filename, extension)) {
			unique_ptr<IFile> ptr(new DiskFile(path));
			callback(move(ptr));
		}
	}
}
