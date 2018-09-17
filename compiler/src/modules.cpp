#include "stdafx.h"
#include "modules.h"
#include "Ast/AstPackage.h"

#include <map>
#include <memory>
#include <algorithm>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/DynamicLibrary.h>

using namespace std;
using namespace llvm;
namespace stdfs = std::experimental::filesystem;

std::map<std::string, std::unique_ptr<Module> > _modules;
std::map<std::string, std::string> funcs;	// 被使用的函数
std::map<string, StructType* > _structs;
std::map<string, AstContext* > _packages;

extern std::unique_ptr<Module> module;
extern llvm::LLVMContext llvmContext;

llvm::Function * CLangModule::getFunction(const std::string & name) {
	//std::string packageName, name;
	//auto i = full_name.find_last_of('.');
	//if (i == std::string::npos) {
	//	packageName = "c";
	//	name = "c_" + full_name;
	//} else {
	//	packageName = full_name.substr(0, i);
	//	name = full_name.substr(i + 1);
	//}

	auto *f = module->getFunction(name);
	if (f) return f;

	for (auto& iter : _modules) {
		auto f = iter.second->getFunction(name);
		if (f) {
			return Function::Create(f->getFunctionType(), Function::ExternalLinkage, name, module.get());
		}
	}

	return nullptr;
}

llvm::Function * CLangModule::getFunction(const std::string& package, const std::string & name) {
	auto iter=_modules.find(package);
	if (iter !=_modules.end()) {
		auto f = iter->second->getFunction(name);
		if (f) {
			return Function::Create(f->getFunctionType(), Function::ExternalLinkage, name, module.get() );
		}
	}
	return nullptr;
}

extern std::unique_ptr<Module> module;

void CLangModule::moveAll(llvm::ExecutionEngine * engine) {
	for (auto &i : _modules) {
		auto &v=i.second;

		std::clog << "Load module:" << v ->getName().str() << std::endl;

		for (auto &i : v->getFunctionList()) {
			auto &n = i.getName();
			std::clog << "Find function: " << n.str() << std::endl;

			// auto p=engine->getFunctionAddress(n);
		}	    
		engine->addModule(std::move(v));
	}
	_modules.clear();
}

std::string getPackageName(const std::string& filename) {
	std::string n = filename.substr(4);// 去除 "lib/"
	std::replace(n.begin(), n.end(), '/', '.');
	std::replace(n.begin(), n.end(), '\\', '.');
	// 去除文件名
	size_t i=n.find_last_of('.');
	return n.substr(0, i);
}

// 在 packages.cpp 中实现
void addModule(const std::string& InputFile, Module* Mod);
extern std::unique_ptr<Module> module;
Module* CLangModule::loadLLFile(const std::string& filename) {
	auto i=_modules.find(filename);
	if (i != _modules.end())
		return i->second.get();

	std::cout << "Try to load:" << filename << std::endl;
	llvm::SMDiagnostic error;

	auto m = parseIRFile(filename+".ll", error, llvmContext);
	if (!m) {
		std::clog << "Can't load file: " << filename << std::endl;
		return nullptr;
	}

	for (auto &i : m->getFunctionList()) {
		std::clog << "\tLoad function: " << i.getName().str() << std::endl;
	}

	for (auto &i : m->getIdentifiedStructTypes() ){
		std::clog << "\tLoad struct: " << i->getStructName().str() << std::endl;
		_structs[i->getStructName()] = i;
	}

	std::string dll = filename + ".dll";
	if (stdfs::exists(stdfs::path(dll))) {
		std::string err;
		if (sys::DynamicLibrary::LoadLibraryPermanently(dll.c_str(), &err)) {
			std::cerr << "读取 " + dll + " 失败：" << err << std::endl;
		}
	}

	auto *p = m.get();
	_modules.insert(std::make_pair(filename, std::move(m)));
	return p;
}

extern int yyparse(void);
extern FILE *yyin;
extern AstPackage* currentPackage;
AstContext* CLangModule::loadSiFile(const stdfs::path& file) {
	std::string fname = file.string();
	auto i=_packages.find(fname);
	if (i != _packages.end())
		return i->second;

	auto *old = currentPackage;

	currentPackage = new AstPackage();

	yyin = fopen(fname.c_str(), "r"); /* 首先打开要被处理的文件（参数1）yyin是lex默认的文件输入指针，设置了则不处理控制台输入 */
	if (!yyin) {
		throw std::runtime_error("无法打开文件：" + fname);
	}
	if (0 != yyparse()) {
		throw new std::runtime_error("解析" + fname + "异常");
	}
	fclose(yyin);

	auto* importedPackage = currentPackage;
	currentPackage = old;

	return _packages[fname] = importedPackage->preprocessor(module.get());
}

void CLangModule::shutdown() {
	_modules.clear();
}

llvm::StructType * CLangModule::getStruct(const std::string& path, const std::string & name) {
	auto* p= _structs["struct." + path + "_" + name];
	return p ? p : _structs[path + "_" + name];
}
