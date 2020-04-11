#pragma once
#include <filesystem>
#include "IDirectory.h"

class DiskDirectory : public IDirectory
{
public:
	DiskDirectory(const std::filesystem::path& path);
protected:
	virtual void doEach(
		const Callback& callback,
		const FilterFunction& filter,
		bool recursive = false);
private:
	std::filesystem::path _path;
};

