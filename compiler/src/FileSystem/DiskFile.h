#pragma once
#include "IFile.h"
#include <filesystem>

/*
 * 直接位于磁盘上的文件
 */
class DiskFile :	public IFile
{
public:
	DiskFile(const std::filesystem::path& path);
	virtual void loadDynamicLibrary();
private:
	std::filesystem::path _path;
};

