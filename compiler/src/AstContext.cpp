#include "stdafx.h"
#include "Ast/AstFunction.h"
#include "Ast/AstClass.h"
#include "Ast/AstPackage.h"
#include "AstContext.h"
#include "Type/AutoType.h"
#include "FunctionInstance.h"
#include "Type/ClassInstanceType.h"
#include "CodeGenerate/CallGen.h"
#include "CodeGenerate/ValueGen.h"
#include "CodeGenerate/GlobalStroeGen.h"
#include "utility.h"

AstContext::AstContext(AstContext * p) : parent(p)
{
	if(p)	pathName = p->pathName;
	module = p->module;
}

AstContext::AstContext(llvm::Module* m)
{
	parent = nullptr;
	module = m;
}

llvm::LLVMContext & AstContext::context() {
	return module->getContext();
}

CodeGen * AstContext::findSymbolValue(const std::string & name, bool recursive) {
	auto *v=module->getGlobalVariable(name);
	if (v) return new ValueGen(v);
	auto *p=getMapValue(_symbols, name);
	if (p) return p;
	if (recursive && parent) return parent->findSymbolValue(name, recursive);
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
	auto i=_functions.find(name);
	if (i!=_functions.end()) {
		throw std::runtime_error("Duplicate function: " + name);
	}
	_functions.insert(std::make_pair(name, f));
}

void AstContext::setClass(const std::string & name, AstClass * cls) {
	auto o = _class.insert(std::make_pair(name, cls));
	if (!o.second) throw std::runtime_error("类名字冲突:" + name);
}

AstClass * AstContext::findClass(const std::string & name) {
	auto i = _class.find(name); 
	if (i != _class.end()) return i->second;
	if (parent) return parent->findClass(name);
	return nullptr;
}

ClassInstanceType * AstContext::findCompiledClass(const std::string & name)
{
	auto i = _compiledClass.find(name);
	if (i == _compiledClass.end())
		i = _compiledClass.find("struct." + name);
	return i == _compiledClass.end() ? nullptr : i->second;
}

CodeGen * AstContext::makeCall(llvm::LLVMContext& c, const std::string & name, std::vector<std::pair<std::string, CodeGen*>>& arguments)
{
	auto it = _functions.find(name);
	if (it != _functions.end()) {
		auto *f = it->second;
		return f->makeCall(c, arguments);
	}
	if (parent) return parent->makeCall(c, name, arguments);

	// Find C function
	auto *func=module->getFunction(name);
	if (func) {
		auto * p=new CallGen();
		p->llvmFunction = func;
		for (auto i : arguments) {
			p->params.push_back(i.second);
		}
		return p;
	}
	return nullptr;
}
