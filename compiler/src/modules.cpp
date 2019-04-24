#include "stdafx.h"
#include "modules.h"
#include "cparser.h"
#include "Ast/AstPackage.h"

#include <map>
#include <memory>
#include <algorithm>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>
#include <llvm/Support/DynamicLibrary.h>

using namespace std;
using namespace llvm;
namespace stdfs = std::filesystem;

std::map<std::string, std::unique_ptr<Module> > _modules;
std::map<std::string, std::string> funcs;	// 被使用的函数
std::map<string, StructType* > _structs;
std::map<string, AstContext* > _packages;
std::map<string, Function*> _functions;
// 包中的函数
std::multimap<string, Function*> _packageFuncs;

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
			// 不同的模块之间是不能直接调用的，因此在本模块创建一个声明
			return Function::Create(f->getFunctionType(), Function::ExternalLinkage, f->getName(), module.get());
		}
	}
	auto iter = _functions.find(name);
	return iter==_functions.end() ? nullptr : iter->second;
}

llvm::Function * CLangModule::getFunction(const std::string& package, const std::string & name) {
	auto iter=_modules.find(package);
	if (iter !=_modules.end()) {
		return iter->second->getFunction(name);
	}
	return nullptr;
}

extern std::unique_ptr<Module> module;

void CLangModule::moveAll(llvm::ExecutionEngine * engine) {
	for (auto &i : _modules) {
		auto &v=i.second;

		std::clog << "Load module:" << v ->getName().str() << std::endl;

		//for (auto &i : v->getFunctionList()) {
		//	auto n = i.getName();
		//	std::clog << "Find function: " << n.str() << std::endl;

		//	// auto p=engine->getFunctionAddress(n);
		//}	    
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

	auto m = parseIRFile(filename, error, llvmContext);
	if (!m) {
		std::clog << "Can't load file: " << filename << std::endl;
		return nullptr;
	}

	//for (auto &i : m->getFunctionList()) {
	//	std::clog << "\tLoad function: " << i.getName().str() << std::endl;
	//}

	for (auto &i : m->getIdentifiedStructTypes() ){
		// std::clog << "\tLoad struct: " << i->getStructName().str() << std::endl;
		_structs[i->getStructName()] = i;
	}

	//std::string dll = filename + ".dll";
	//if (stdfs::exists(stdfs::path(dll))) {
	//	std::string err;
	//	if (sys::DynamicLibrary::LoadLibraryPermanently(dll.c_str(), &err)) {
	//		std::cerr << "读取 " + dll + " 失败：" << err << std::endl;
	//	}
	//}

	auto *p = m.get();
	_modules.insert(std::make_pair(filename, std::move(m)));
	return p;
}

extern int yyparse(void);
extern FILE *yyin;
extern AstPackage* currentPackage;
extern int yylineno;
AstContext* CLangModule::loadSiFile(const stdfs::path& file, const std::string& packageName, llvm::Module* m) {
	std::string fname = file.string();
	auto i=_packages.find(fname);
	if (i != _packages.end())
		return i->second;

	auto *old = currentPackage;

	currentPackage = new AstPackage();
	currentPackage->name = packageName;
	int ono=yylineno;
	yylineno = 0;
	yyin = fopen(fname.c_str(), "r"); /* 首先打开要被处理的文件（参数1）yyin是lex默认的文件输入指针，设置了则不处理控制台输入 */
	if (!yyin) {
		throw std::runtime_error("无法打开文件：" + fname);
	}
	if (0 != yyparse()) {
		throw new std::runtime_error("解析" + fname + "异常");
	}
	yylineno = ono;
	fclose(yyin);

	auto* importedPackage = currentPackage;
	currentPackage = old;

	return _packages[fname] = importedPackage->preprocessor(m);
}

void CLangModule::shutdown() {
	_modules.clear();
}

llvm::StructType * CLangModule::getStruct(const std::string& path, const std::string & name) {
	return getStruct(path + "_" + name);
}

llvm::StructType * CLangModule::getStruct(const std::string & name)
{
	auto* p = _structs["struct." + name];
	return p ? p : _structs[name];
}

set<string> packages;
map<string, AstClass*> classes;
map<string, AstFunction*> functions;
 void CLangModule::loadPackage(const std::string & packageName)
{
	 // 避免重复读入
	 if (packages.find(packageName) != packages.end())
		 return;
	 packages.insert(packageName);

	 auto name = packageName;
	 for (char &i : name) 
		 if (i == '.') i = '/';
	 
	auto base = "lib/" + name;

	for (auto&fe : stdfs::directory_iterator(base)) {
		auto fp = fe.path();
		//std::wcout << fp.filename().wstring() << std::endl;
		auto si = fp.filename();
		auto ex = fp.extension().string();
		if (ex == ".dll") {
			string err;
			string dll = si.string();
			if (sys::DynamicLibrary::LoadLibraryPermanently(dll.c_str(), &err)) {
				std::cerr << "读取 " + dll + " 失败：" << err << std::endl;
			} else {
				std::clog << "读取 dll：" << dll << std::endl;
			}
			continue;
		}
		if (ex == ".h" || ex == ".hpp") {
			auto *m=loadCHeader(name, fp.string());
			auto x = std::unique_ptr<llvm::Module>(m);
			_modules.insert(make_pair(name, std::move(x)));
		}

		if (ex == ".si") {
			auto osi = base / si;
			si.replace_extension(".ll");
			auto llo = base / si;

			llvm::Module* m;
			if (stdfs::exists(llo)) {
				m = CLangModule::loadLLFile(llo.string());
			} else {
				m = new llvm::Module(packageName, llvmContext);
			}

			AstContext* x = CLangModule::loadSiFile(osi, packageName, m);
			for (auto i : x->_class) {
				auto full = packageName + "." + i.second->name;
				classes[full] = i.second;
			};

			for (auto i : x->_functions) {
				auto full = packageName + "." + i.second->name;
				functions[full] = i.second;
			}
		}
		//replace_extension替换扩展名
		//stem去掉扩展名
	}
}

 AstClass * CLangModule::findClass(const std::string & fullName)
 {
	 auto i = classes.find(fullName);
	 if (i != classes.end()) {
		 return i->second;
	 }
	 return nullptr;
 }

 AstFunction * CLangModule::findFunction(const std::string & fullName)
 {
	 std::clog << "Find function :" << fullName << std::endl;
	 auto i = functions.find(fullName);
	 if (i != functions.end()) {
		 return i->second;
	 }
	 return nullptr;
 }

 std::vector<llvm::StructType*> CLangModule::allClass(const std::string& fullName)
 {
	 static std::vector<llvm::StructType*> empty;
	 auto iter=_modules.find(fullName);
	 if (iter == _modules.end()) return empty;
	 return iter->second->getIdentifiedStructTypes();
 }

 SymbolTableList<Function>& CLangModule::allFunction(const std::string& fullName)
 {
	 static SymbolTableList<Function> empty;
	 auto iter = _modules.find(fullName);
	 if (iter == _modules.end()) return empty;
	 return iter->second->getFunctionList();
 }
