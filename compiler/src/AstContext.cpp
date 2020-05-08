#include "stdafx.h"
#include "Ast/AstFunction.h"
#include "Ast/AstClass.h"
#include "Ast/AstModule.h"
#include "AstContext.h"
#include "Type/AutoType.h"
#include "FunctionInstance.h"
#include "Type/ClassInstanceType.h"
#include "CodeGenerate/CallGen.h"
#include "CodeGenerate/ValueGen.h"
#include "utility.h"

using namespace std;
std::map<std::string, ClassInstanceType* > AstContext::_compiledClass;
AstContext::AstContext(AstContext * p) : parent(p)
{
	if (p) {
		pathName = p->pathName;
		module = p->module;
	}
}

AstContext::AstContext(llvm::Module* m)
{
	parent = nullptr;
	module = m;
}

llvm::LLVMContext & AstContext::context() {
	return module ? module->getContext() : parent->context();
}

CodeGen * AstContext::findSymbolValue(const std::string & name, bool recursive) {
	auto *p=getMapValue(_symbols, name);
	if (p) return p;

	if (recursive && parent) return parent->findSymbolValue(name, recursive);
	auto *v = module->getGlobalVariable(name);
	if (v) return new ValueGen(v);
	return nullptr;
}

void AstContext::setSymbolValue(const std::string & name, CodeGen * v) {
	auto i = _symbols.find(name);
	if (i != _symbols.end()) {
		auto* type = i->second->type;
		if (!type) // 只是给占位符
			throw std::runtime_error("Duplicate variable: " + name);
		delete i->second;
	}
	_symbols[name] = v;
}

void AstContext::defineFunction(const std::string & name, AstFunction *f)
{
	_functions.insert(std::make_pair(name, f));
}

void AstContext::setClass(const std::string & name, AstClass * cls)
{
	if (name == "String" &&	_class.find(name) != _class.end()) 
		return;
	auto o = _class.insert(std::make_pair(name, cls));
	if (!o.second) throw std::runtime_error("类名字冲突:" + name);
}

AstClass * AstContext::findClass(const std::string & name) {
	auto i = _class.find(name); 
	if (i != _class.end()) return i->second;

	for (auto& i : _anonymousModules) {
	 	auto *c = i->findClass(name);
		if (c) return c;
	}

	if (parent) return parent->findClass(name);
	return nullptr;
}

ClassInstanceType * AstContext::findCompiledClass(const std::string & name)
{
	if (auto i = _compiledClass.find(name); i != _compiledClass.end())
		return i->second;

	if (name.substr(0, 7) != "struct.") {
		if (auto i = _compiledClass.find("struct." + name); i != _compiledClass.end()) 
			return i->second;

		std::string n = pathName + "_" + name;
		std::for_each(n.begin(), n.end(), [](char &c) {if (c == '.') c = '_'; });
		
		if (auto i = _compiledClass.find(n); i != _compiledClass.end()) 
			return i->second;
		if (auto i = _compiledClass.find("struct." + n); i != _compiledClass.end()) 
			return i->second;
	}
	return parent ? parent->findCompiledClass(name) : nullptr;
}

ClassInstanceType* AstContext::findCompiledClassByLLVMType(const llvm::Type* type)
{
	auto i= _compiledClass.find(type->getStructName());
	return i != _compiledClass.end() ? i->second : nullptr;
}

map<std::string, AstClass*> loadClassCache;
AstClass * AstContext::loadClass(const std::string & path, const std::string & name)
{
	string n = path + "." + name;
	
	if (auto iter = loadClassCache.find(n); iter != loadClassCache.end())
		return iter->second;

	return nullptr;
}

CodeGen * AstContext::makeCall(
	llvm::LLVMContext& c, 
	const std::string & name, 
	std::vector<std::pair<std::string, CodeGen*>>& arguments, 
	CodeGen* object)
{
	if (auto it = _functions.equal_range(name); it.first != it.second) {
		// 优先非模板
		for (auto i = it.first; i != it.second; i++) {
			auto *f = i->second;
			if (f->isTemplate()) continue;
			auto *p = f->makeCall(this, arguments);
			if (p) return p;
		}

		// for (auto &i : std::range(it)) {
		for (auto i = it.first; i != it.second; i++) {
			auto *f = i->second;
			if (!f->isTemplate()) continue;
			auto *p = f->makeCall(this, arguments);
			if (p) return p;
		}
	}

	for (auto& i : _anonymousModules) {
		auto pair=i->findFunction(name);
		for( auto f : pair ){
			auto* p = f->makeCall(this, arguments);
			if (p) return p;
		}
	}
	

	return parent ? parent->makeCall(c, name, arguments, object) : nullptr;
}

AstType * AstContext::findType(const std::string & name)
{
	return parent ? parent->findType(name) : nullptr;
}
