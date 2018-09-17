#include "stdafx.h"
#include <filesystem>
#include "AstImport.h"
#include "AstPackage.h"
#include "AstContext.h"
#include "AstClass.h"
#include "AstDef.h"
#include "modules.h"
#include "../CodeGenerate/ClassMemberGen.h"
#include "../Type/ClassInstanceType.h"
#include "../FunctionInstance.h"

extern AstPackage* currentPackage;
//std::map<std::string, AstPackage*> packages;

using namespace std;
using namespace llvm;

namespace stdfs = std::experimental::filesystem;
map<string/*package name*/, map<string/*struct*/, ClassInstanceType*> > classesMap;

inline void replaceToDot(std::string& x)
{
	std::for_each(x.begin(), x.end(), [](char &c) { if (c == '/') c = '.'; });
}

CodeGen * AstImport::makeGen(AstContext * parent)
{
	std::string className = identifiers.back();
	std::string n;
	string packageName;
	for (auto i : identifiers) {
		n += i + "/";
	}
	if(!n.empty())
		n.pop_back();

	if( isupper( className[0] )) // 如果是类
		packageName = n.substr(0, n.find_last_of('/'));
	else {
		packageName = n;
		className.clear();
	}

	replaceToDot(packageName);

	if (!className.empty())
		parent->setAlias(className, packageName + '.' + className);

	std::string fname = "lib/" + n;
	std::string si = fname +".si";
	AstClass *cls = nullptr;
	if (stdfs::exists(si)) {
		AstContext* x=CLangModule::loadSiFile(si);
		cls = x->findClass(className);
	}

	std::string ll = fname + ".ll";
	if (stdfs::exists(ll)) {
		auto* m=CLangModule::loadLLFile(fname);
		if (cls) {
			auto* annotation = cls->annotations["CLang"];
			if (annotation) {
				loadClassFromModule(cls, annotation, parent, m);
				cls = nullptr;
			}
		}
		
		// loadCModule(m);
	}

	if(cls) parent->setClass(className, cls);

	if (!className.empty()) {
		auto &map = classesMap[packageName];
		auto *p=map[className];
		if (p) {
			parent->setCompiledClass(className, p);
			parent->setCompiledClass(p->uniqueName(), p);
		}
	}

	return nullptr;
}

std::regex baseRegex("([a-z][a-zA-Z_\\d]+)_([A-Z][a-z\\d]+)_(([GS]ET_)?[a-z][A-Za-z\\d]+)$");
std::regex classRegex("([a-z][a-zA-Z_\\d]+)_([A-Z][a-z\\d]+)$");
void AstImport::loadCModule(llvm::Module* m)
{
	// 导入符合命名规则的类
	for (auto *i : m->getIdentifiedStructTypes()) {
		string x = i->getName().str();
		if (x.find("struct.") == 0)
			x = x.substr(7);
		if (x.at(0) == '_') continue;
		std::smatch classMatch;
		if (std::regex_match(x, classMatch, classRegex)) {
			string packageName = classMatch[1].str();
			replaceToDot(packageName);

			auto &map = classesMap[packageName];

			string className = classMatch[2].str();
			map[className] = new ClassInstanceType(packageName, className, i);
		}
	}

	// packageName _ [大写开头]className _ GET _ fieldName
	auto &funs = m->getFunctionList();
	for_each(funs.begin(), funs.end(), [](Function& func) {
		string x = func.getName();
		std::smatch baseMatch;
		if (std::regex_match(x, baseMatch, baseRegex)) {
			std::ssub_match packageMatch = baseMatch[1];
			auto &map = classesMap[packageMatch.str()];
			std::ssub_match classNameMatch = baseMatch[2];
			auto *p = map[classNameMatch.str()];
			std::string name = baseMatch[3].str();
			if (p) {
				p->funcCache[name] = new FunctionInstance(&func);
				for (auto &i : func.getAttributes()) {
					i.dump();
				}
			}
		}
	});
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
		if (v) instance->defaultValues[name]=v->makeGen(context);
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

void AstImport::loadClassFromModule(AstClass * cls, AstAnnotation * annotation, AstContext* context, llvm::Module * m)
{
	AstNode* n=annotation->defaultValue;
	if (!n) n = annotation->attrs["name"];
	if (!n) 
		throw std::runtime_error("No name in CLang annotation.");
	string name = n->name;
	StructType* s = m->getTypeByName(name);
	if (!s) s = m->getTypeByName("struct." + name);
	if (!s) throw std::runtime_error("Can't find " + name + " struct in ll file.");

	ClassInstanceType* instance = new ClassInstanceType(context->pathName, cls->name, s);
	int index = 0;
	for (auto *i : cls->block) {
		auto *x=dynamic_cast<AstDef*>(i);
		if (x) {
			def(instance, index, context, x, m);
		}

		auto *f = dynamic_cast<AstFunction*>(i);
		if (f) {
			auto *x = func(instance, context, f, m);
			instance->funcCache[f->name] = x;
		}
	}
	string sn=instance->_type->getName();
	context->setCompiledClass(sn, instance);
	context->setCompiledClass(cls->name, instance);
}
