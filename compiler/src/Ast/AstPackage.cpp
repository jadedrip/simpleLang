#include "stdafx.h"
#include "AstPackage.h"
#include "AstModule.h"
#include "cparser.h"
#include "modules.h"
#include "CompilerOptions.h"
#include <llvm/Support/DynamicLibrary.h>

using namespace std;
using namespace llvm;
namespace stdfs = filesystem;

extern llvm::LLVMContext llvmContext;
void AstPackage::importDll(const std::filesystem::path& base)
{
	string& triple = CompilerOptions::instance().triple;
	auto dllptr = base / "platform" / triple / "share";
	for (auto i : std::filesystem::directory_iterator(dllptr)) {
		if (i.is_directory()) continue;	// 先不递归查找
		auto& path = i.path();
		std::string extension = path.extension().string();
		// to_lower
		std::for_each(extension.begin(), extension.end(), tolower);
		if (extension == ".dll" || extension == ".so") {
			std::string err;
			std::string filename = path.string();
			if (llvm::sys::DynamicLibrary::LoadLibraryPermanently(filename.c_str(), &err)) {
				cerr << "读取 " << filename << "失败：" << err << endl;
			}
		}
	}
}

AstPackage::AstPackage(const std::string& packageName) : _name(packageName) {
	// TODO: 多种匹配查找目录
	auto base = "lib/" + packageName;
	stdfs::path packageDir = stdfs::path(base);
	if (CompilerOptions::instance().directlyExecute) {
		importDll(packageDir);
	}
	auto src = packageDir / "src";
	recurvePath("", src);

	auto export_h = stdfs::path(base) / "export.h";
	if (stdfs::exists(export_h)) {
		_llvmModule = loadCHeader(_name, export_h.string());
		for (auto i : _llvmModule->getIdentifiedStructTypes()) {
			_structs[i->getStructName()] = i;
		}
	}
	else {
		_llvmModule = new Module(_name, llvmContext);
	}
}

void AstPackage::recurvePath(const string& base, const stdfs::path& path)
{
	for (auto& i : stdfs::directory_iterator(path)) {
		if (i.is_directory()) {
			recurvePath( base + "." + i.path().string(), i.path());
			continue;
		}
		auto& file = i.path();
		string ex = file.extension().string();
		std::for_each(ex.begin(), ex.end(), tolower);
		if (ex == ".si") {
			auto* p = CLangModule::loadSiFile(file, base);
			string filename = file.filename().string();
			if (!base.empty())
				filename = base + "." + filename;
			addModule(filename.substr(0, filename.length() - 3), p);
		}
	}
}

void AstPackage::addModule(const std::string& name, AstModule* module) {
	_modules[name] = module;
}

AstClass* AstPackage::findClass(const std::string& name)
{
	auto *m=_modules[name];
	if (m) {
		m->generateCode(_llvmModule);
	}
	return nullptr;
}
