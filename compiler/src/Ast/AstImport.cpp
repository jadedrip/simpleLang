#include "stdafx.h"
#include <filesystem>
#include "AstImport.h"
#include "AstModule.h"
#include "AstContext.h"
#include "AstClass.h"
#include "AstDef.h"
#include "modules.h"
#include "../CodeGenerate/ClassMemberGen.h"
#include "../Type/ClassInstanceType.h"
#include "../FunctionInstance.h"
#include <llvm/Support/DynamicLibrary.h>

extern AstModule* currentPackage;

using namespace std;
using namespace llvm;

namespace stdfs = std::filesystem;

inline void replaceToSlash(std::string& x)
{
	std::for_each(x.begin(), x.end(), [](char &c) { if (c == '.') c = '/'; });
}

CodeGen * AstImport::makeGen(AstContext * parent)
{
	std::string dir;
	for (auto i : identifiers) {
		dir += i + ".";
	}
	if (!dir.empty()) // 去除最后的 .
		dir.pop_back();

	std::clog << "import " << dir << std::endl;

	// 导入包
	auto* package = CLangModule::loadPackage(dir);
	parent->addImport(name, package);
	return nullptr;
}

std::regex baseRegex("([a-z][a-zA-Z_\\d]+)_([A-Z][a-z\\d]+)_(([GS]ET_)?[a-z][A-Za-z\\d]+)$");
std::regex classRegex("([a-z][a-zA-Z_\\d]+)_([A-Z][a-z\\d]+)$");

void AstImport::draw(std::ostream & os)
{
	std::string n = nodeId;
	os << n << " -> ";
	for (auto i : identifiers) {
		os << i << '.';
	}
	os << std::endl;
}

void def(ClassInstanceType* instance, int& index, AstContext* context, AstDef* x, Module* m)
{
	string cname = instance->uniqueName();
	for (auto i : x->vars) {
		string name = i.first;
		AstNode* v = i.second;

		auto *p = new ClassMemberGen();
		p->index = index++;
		auto *get= m->getFunction(cname + "_GET_" + name);
		if(get)
			p->getFunction = Function::Create(get->getFunctionType(), Function::ExternalLinkage, get->getName(), context->module);
		auto *set = m->getFunction(cname + "_SET_" + name);
		p->setFunction = Function::Create(set->getFunctionType(), Function::ExternalLinkage, set->getName(), context->module);
		instance->memberGens[name] = p;
		if (v) instance->defaultValues[p->index]=v->makeGen(context);
	}
}

FunctionInstance* func(ClassInstanceType* instance, AstContext* context, AstFunction* x, Module* m)
{
	string cname = instance->uniqueName();
	auto* f=m->getFunction(cname + "_" + x->name);
	if (!f) 
		throw std::runtime_error("Can't find " + x->name + " function in ll file.");
	auto *fun = new FunctionInstance(f);
	std::vector< std::pair<std::string, const llvm::Type*> > parameters;		// 参数表
	auto *ft=f->getFunctionType();
	size_t idx = 0;
	auto i = ft->param_begin();// 跳过 class 指针
	for ( i++; i != ft->param_end(); i++, idx++) {
		auto a=x->paremeters.at(idx);
		parameters.push_back(std::make_pair(a.name, *i));
	}
	fun->parameters = std::move(parameters);
	fun->func=Function::Create(ft, Function::ExternalLinkage, f->getName(), context->module);
	return fun;
}

