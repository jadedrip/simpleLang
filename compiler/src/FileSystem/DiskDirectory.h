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
	virtual std::unique_ptr<IDirectory> path(const std::string& path);
private:
	std::filesystem::path _path;
};

