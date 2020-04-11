#include "stdafx.h"
#include <memory>
#include <boost/algorithm/string.hpp>
#include "SLangPackage.h"
#include "CompilerOptions.h"
#include "FileSystem/DiskDirectory.h"

using namespace std;


void SLangPackage::load(const string& name)
{	
	string path = "lib/" + name;
	loadDynamicLibrary(path);
	
}

void SLangPackage::loadDynamicLibrary(const string& path)
{
	string dllPath = path + "/platform/" + CompilerOptions::instance().triple + "/share";
	// 先读取所有动态链接库
	DiskDirectory dir(dllPath);
	dir.forEach().filter(
		[](const string& filename, const string& extension) {
			if (extension == "so") return true;
			std::string ex = boost::to_lower_copy(extension);
			return ex == "dll";
		}
	).recusive(true).loop(
		[](unique_ptr<IFile>&& file) {
			try {
				file->loadDynamicLibrary();
			}
			catch (exception& e) {
				std::cerr << e.what() << std::endl;
			}
		}
		);
}
