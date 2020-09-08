#include "stdafx.h"
#include "AstPackage.h"
#include "AstModule.h"
#include "cparser.h"
#include "modules.h"
#include "CompilerOptions.h"
#include <vector>
#include <llvm/Support/DynamicLibrary.h>

using namespace std;
using namespace llvm;
namespace stdfs = filesystem;

extern llvm::LLVMContext llvmContext;
void AstPackage::importDll(const std::filesystem::path& base)
{
	string& triple = CompilerOptions::instance().triple;
	auto dllptr = base / "platform" / triple / "share";
	if (!stdfs::exists(dllptr)) return;
	for (auto i : std::filesystem::directory_iterator(dllptr)) {
		if (i.is_directory()) continue;	// 先不递归查找
		auto path = i.path();
		std::string extension = path.extension().string();

		if (extension == ".link") {
			std::string fname;
			std::ifstream fs(path);
			fs >> fname;
			path = stdfs::path(fname);
			if (!stdfs::exists(path)) continue;
			extension = path.extension().string();
		}

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
	auto base = stdfs::path("lib") / packageName;
	if (CompilerOptions::instance().directlyExecute) {
		importDll(base);
	}
	auto src = base / "src";
	recurvePath("", src);

	auto export_h = base / "export.h";
	if (stdfs::exists(export_h)) {
		stdfs::path includePath = base / "include";
		std::vector<string> includes;
		if (stdfs::exists(includePath))
			includes.push_back(includePath.string());
		_llvmModule = loadCHeader(_name, export_h.string(), includes);
		for (auto i : _llvmModule->getIdentifiedStructTypes()) {
			_structs[i->getStructName()] = i;
		}
	}
	else {
		_llvmModule = new Module(_name, llvmContext);
	}

	_contexts = new AstContext(_llvmModule);
	_contexts->pathName = packageName;

	for (auto i : _modules) {
		i.second->preprocessor(_contexts);
	}
}

std::vector<AstFunction*> AstPackage::findFunction(const std::string& name) {
	std::vector<AstFunction*> vec;
	auto x = _contexts->_functions.equal_range(name);
	for (auto iter = x.first; iter != x.second; iter++) {
		vec.push_back(iter->second);
	}
	return vec;
}

void AstPackage::recurvePath(const string& base, const stdfs::path& path)
{
	for (auto& i : stdfs::directory_iterator(path)) {
		if (i.is_directory()) {
			recurvePath(base + "." + i.path().string(), i.path());
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
	// TODO: 定位
	auto* m = _contexts->findClass(name);
	return m;
}
