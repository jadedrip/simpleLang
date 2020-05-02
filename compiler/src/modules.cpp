#include "stdafx.h"
#include "modules.h"
#include "cparser.h"
#include "Ast/AstModule.h"
#include "Ast/AstPackage.h"

#include <map>
#include <vector>
#include <memory>
#include <algorithm>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/DynamicLibrary.h>
#include <CompilerOptions.h>

using namespace std;
using namespace llvm;
namespace stdfs = filesystem;

map<string, unique_ptr<Module> > _modules;
map<string, string> funcs;	// 被使用的函数
map<string, StructType* > _structs;
map<string, Function*> _functions;
map<string, AstPackage*> _packages;

Module* _clib;

extern unique_ptr<Module> module;
extern llvm::LLVMContext llvmContext;

std::string _triple;
void CLangModule::initialize(const std::string& triple)
{
	// 读取核心库
	//enumDirectory("lib", [](const string& relativePath, stdfs::path& file) {
	//	auto filename = file.string();
	//	if (file.extension() == ".dll") {
	//		// TODO: 编译是不需要读取 dll 的，未来通过参数控制
	//		string err;
	//		if (sys::DynamicLibrary::LoadLibraryPermanently(filename.c_str(), &err)) {
	//			cerr << "读取 " + filename + " 失败：" << err << endl;
	//		}
	//	}
	//	});
	_triple = triple;

	string err;
	string clib = "lib/si/platform/" + triple + "/share/clib.dll";
	if (sys::DynamicLibrary::LoadLibraryPermanently(clib.c_str(), &err)) {
		cerr << "读取 clib.dll 失败：" << err << endl;
	}
	_clib = loadCHeader("si", "lib/si/export.h");
	for (auto i : _clib->getIdentifiedStructTypes()) {
		_structs[i->getStructName()] = i;
	}

	// CLangModule::loadPackage("si");
	// CLangModule::loadLLFile("clib/si.ll");
}

llvm::Function* CLangModule::getFunction(const string& name) {
	//string packageName, name;
	//auto i = full_name.find_last_of('.');
	//if (i == string::npos) {
	//	packageName = "c";
	//	name = "c_" + full_name;
	//} else {
	//	packageName = full_name.substr(0, i);
	//	name = full_name.substr(i + 1);
	//}

	auto* f = module->getFunction(name);
	if (f) return f;

	f = _clib->getFunction(name);
	if (f) {
		return Function::Create(f->getFunctionType(), Function::ExternalLinkage, f->getName(), module.get());
	}

	//for (auto& iter : _modules) {
	//	auto f = iter.second->getFunction(name);
	//	if (f) {
	//		// 不同的模块之间是不能直接调用的，因此在本模块创建一个声明
	//		return Function::Create(f->getFunctionType(), Function::ExternalLinkage, f->getName(), module.get());
	//	}
	//}
	//auto iter = _functions.find(name);
	//return iter == _functions.end() ? nullptr : iter->second;
	return nullptr;
}

llvm::Function* CLangModule::getFunction(const string& package, const string& name) {
	auto iter = _modules.find(package);
	if (iter != _modules.end()) {
		auto func = iter->second->getFunction(name);
		return Function::Create(func->getFunctionType(), Function::ExternalLinkage, name, module.get());
	}
	return nullptr;
}

extern unique_ptr<Module> module;

void CLangModule::moveAll(llvm::ExecutionEngine* engine) {
	for (auto& i : _modules) {
		auto& v = i.second;

		clog << "Load module:" << v->getName().str() << endl;

		//for (auto &i : v->getFunctionList()) {
		//	auto n = i.getName();
		//	clog << "Find function: " << n.str() << endl;

		//	// auto p=engine->getFunctionAddress(n);
		//}	    
		engine->addModule(move(v));
	}
	_modules.clear();
}

string getPackageName(const string& filename) {
	string n = filename.substr(4);// 去除 "lib/"
	replace(n.begin(), n.end(), '/', '.');
	replace(n.begin(), n.end(), '\\', '.');
	// 去除文件名
	size_t i = n.find_last_of('.');
	return n.substr(0, i);
}

// 在 packages.cpp 中实现
void addModule(const string& InputFile, Module* Mod);
extern unique_ptr<Module> module;
Module* CLangModule::loadLLFile(const string& filename) {
	auto i = _modules.find(filename);
	if (i != _modules.end())
		return i->second.get();

	cout << "Try to load:" << filename << endl;
	llvm::SMDiagnostic error;

	auto m = parseIRFile(filename, error, llvmContext);
	if (!m) {
		clog << "Can't load file: " << filename << endl;
		return nullptr;
	}

	for (auto& i : m->getIdentifiedStructTypes()) {
		_structs[i->getStructName()] = i;
	}

	auto* p = m.get();
	_modules.insert(make_pair(filename, move(m)));
	return p;
}

extern int yyparse(void);
extern FILE* yyin;
extern AstModule* currentPackage;
extern int yylineno;
AstModule* CLangModule::loadSiFile(const stdfs::path& file, const string& packageName) {
	string fname = file.string();
	auto* old = currentPackage;

	currentPackage = new AstModule();
	currentPackage->name = packageName;
	int ono = yylineno;
	yylineno = 0;
	yyin = fopen(fname.c_str(), "r"); /* 首先打开要被处理的文件（参数1）yyin是lex默认的文件输入指针，设置了则不处理控制台输入 */
	if (!yyin) {
		throw runtime_error("无法打开文件：" + fname);
	}
	if (0 != yyparse()) {
		throw new runtime_error("解析" + fname + "异常");
	}
	yylineno = ono;
	fclose(yyin);

	auto* importedPackage = currentPackage;
	currentPackage = old;

	return importedPackage;
}

void CLangModule::shutdown() {
	_modules.clear();
}

llvm::StructType* CLangModule::getStruct(const string& path, const string& name) {
	return getStruct(path + "_" + name);
}

llvm::StructType* CLangModule::getStruct(const string& name)
{
	auto* p = _structs["struct." + name];
	auto v = p ? p : _structs[name];
	assert(v && "Can't find struct");
	return v;
}

map<string, AstClass*> classes;
map<string, AstFunction*> functions;

using namespace std::filesystem;

void CLangModule::recurvePath(AstPackage& package, const string& base, const path& path) {
	for (auto& i : stdfs::directory_iterator(path)) {
		if (i.is_directory()) {
			recurvePath(package, base + "." + i.path().string(), i.path());
			continue;
		}
		auto& file = i.path();
		string ex = file.extension().string();
		std::for_each(ex.begin(), ex.end(), tolower);
		if (ex == ".si") {
			auto* p = loadSiFile(file, base);
			string filename = file.string();
			package.addModule(base + "." + filename.substr(0, filename.length() - 3), p);
		}
	}
}

AstPackage* CLangModule::loadPackage(const string& packageName)
{
	if (_packages.contains(packageName))
		return;

	// TODO: 多种匹配查找目录
	auto base = "lib/" + packageName;
	path packageDir = path(base);
	if (CompilerOptions::instance().directlyExecute) {
		CLangModule::importDll(packageDir);
	}

	auto package = new AstPackage(packageName);
	_packages[packageName] = package;

	auto src = packageDir / "src";
	recurvePath(*package, "", src);
	return package;
}

AstClass* CLangModule::findClass(const string& fullName)
{
	auto i = classes.find(fullName);
	if (i != classes.end()) {
		return i->second;
	}
	return nullptr;
}

AstFunction* CLangModule::findFunction(const string& fullName)
{
	clog << "Find function :" << fullName << endl;
	auto i = functions.find(fullName);
	if (i != functions.end()) {
		return i->second;
	}
	return nullptr;
}

void CLangModule::importDll(const std::filesystem::path& base)
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
