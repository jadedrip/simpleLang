#include "stdafx.h"
#include "ClassInstanceType.h"
#include "../Ast/AstClass.h"
#include "../Ast/AstFunction.h"
#include "FunctionInstance.h"
#include "AstContext.h"
#include "utility.h"
#include "ClassContext.h"
#include "../CodeGenerate/ClassMemberGen.h"
#include "../CodeGenerate/NewGen.h"
#include "../CodeGenerate/CallGen.h"
#include "../CodeGenerate/ThisGen.h"
#include "utility.h"
#include "../modules.h"

int ClassInstanceType::serial = 0;

using namespace llvm;
std::map<std::string, ClassInstanceType*> classTypes;
std::map<uintptr_t, ClassInstanceType*> llvmClassTypes;

ClassInstanceType * ClassInstanceType::findByName(const std::string & name) {
	return getMapValue(classTypes, name);
}

ClassInstanceType::ClassInstanceType(AstContext* c, const std::string& path, const std::string& n)
	: AstContext(c)
{
	this->name = n;
	this->path = path;
	//classTypes[path + "." + name] = this;
	//llvmClassTypes[(uintptr_t)ty] = this;
}

std::string ClassInstanceType::uniqueName()
{
	if (_type) {
		std::string v= _type->getName();
		return (v.substr(0, 7) == "struct.") ? v.substr(7) : v;
	}
	return path + "." + name;
}

using namespace llvm;
Type * ClassInstanceType::llvmType(LLVMContext & context)
{
	return _type;
}

ClassMemberGen * ClassInstanceType::getMember(CodeGen* value, const std::string & name) {
	auto *p=getMapValue(memberGens, name);
	if (p) return p->clone(value);
	return nullptr;
}

CodeGen * ClassInstanceType::newObject(AstContext* c, std::vector<std::pair<std::string, CodeGen*>>& v)
{
	auto *p = new NewGen();
	p->type = llvmType(c->context());
	for (auto i : creators) {
		auto* call = i->makeCall(c, v, p, this);
		if (call) {
			p->construstor = call;
			return p;
		}
	}
	if (!v.empty())
		throw std::runtime_error("没有匹配的构造函数");
	return p;
}

AstType* ClassInstanceType::findType(const std::string& name)
{
	auto i = templateTypes.find(name);
	if (i != templateTypes.end())
		return i->second;
	return parent ? parent->findType(name) : nullptr;
}

//CodeGen * ClassInstanceType::thisGen()
//{
//	if (_thisGen) return _thisGen;
//	assert(_type);
//	_thisGen = new ThisGen(_type);
//	return _thisGen;
//}

CodeGen* ClassInstanceType::findSymbolValue(const std::string& name, bool recursive)
{
	// 先查找本地参数
	auto v = getMapValue(_symbols, name);
	if (v) return v;

	auto p = getMapValue(memberGens, name);
	if (p) return p;

	if (parent && recursive)
		return parent->findSymbolValue(name, recursive);
	return nullptr;
}

CodeGen* ClassInstanceType::makeCall(
	llvm::LLVMContext& c,
	const std::string& name,
	std::vector<std::pair<std::string, CodeGen*>>& arguments,
	CodeGen* object
)
{
	auto it = methds.equal_range(name);
	if (it.first != it.second) { // 如果找到
		// 成员函数，先找非模板的
		for (auto i = it.first; i != it.second; i++) {
			if (i->second->isTemplate()) continue;
			auto* p = i->second->makeCall(this, arguments, object, this);
			if (p) {
				//p->object = object;
				return p;
			}
		}

		// 成员函数，找模板的
		for (auto i = it.first; i != it.second; i++) {
			if (!i->second->isTemplate()) continue;
			auto* p = i->second->makeCall(this, arguments, object, this);
			//p->object = object;
			if (p) return p;
		}

		throw std::runtime_error("成员函数 " + name + "参数不匹配");
	}

	auto* v = getMapValue(memberGens, name);
	if (v) { // 成员变量
		if (!v->type->isPointerTy()
			|| !v->type->getPointerElementType()->isFunctionTy())
			throw std::runtime_error("成员变量 " + name + "不是函数");

		std::vector<CodeGen*> gens;
		// assert(value);
		// gens.push_back(object);
		for (auto i : arguments) {
			gens.push_back(i.second);
		}
		v->object = object;
		auto ft = dyn_cast<FunctionType>(v->type->getPointerElementType());
		auto* p = new CallGen(v, ft, std::move(gens));
		p->object = object;
		return p;
	}

	if (parent)
		return parent->makeCall(c, name, arguments);

	throw new std::runtime_error("Can't find:" + name);
}
