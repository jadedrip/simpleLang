#include "stdafx.h"
#include <memory>
#include <boost/algorithm/string.hpp>
#include <llvm/Support/DynamicLibrary.h>
#include "SLangPackage.h"
#include "CompilerOptions.h"

using namespace std;

SLangPackage::SLangPackage(const std::string& packageName)
	: _packageName(packageName)
{
	_triple = llvm::sys::getProcessTriple();
	filesystem::path path("lib/" + packageName);
	if (CompilerOptions::instance().directlyExecute)
		loadDynamicLibrary(path);

	loadSiFiles(path);
}

AstClass* SLangPackage::importClass(const std::string& name)
{
	string path = "lib/" + _packageName;
	return nullptr;
}


void SLangPackage::loadDynamicLibrary(const std::filesystem::path& base)
{
	auto dllptr = base / "platform" / _triple / "share";
	for (auto i : std::filesystem::directory_iterator(dllptr)) {
		if (i.is_directory()) continue;	// 先不递归查找
		auto& path = i.path();
		std::string extension = path.extension().string();
		// to_lower
		std::for_each(extension.begin(), extension.end(), tolower);
		if (extension == "dll" || extension == "so") {
			std::string err;
			std::string filename = path.string();
			if (llvm::sys::DynamicLibrary::LoadLibraryPermanently(filename.c_str(), &err)) {
				cerr << "读取 " << filename << "失败：" << err << endl;
			}
		}
	}
}

void SLangPackage::loadSiFiles(const std::filesystem::path& base)
{
}
