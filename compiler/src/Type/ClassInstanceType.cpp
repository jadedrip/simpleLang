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

ClassInstanceType::ClassInstanceType(const std::string& path, const std::string& n)
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

ClassContext * ClassInstanceType::makeContext(AstContext * parent)
{
	return new ClassContext(parent, this);
}

ClassMemberGen * ClassInstanceType::getMember(CodeGen* value, const std::string & name) {
	return getMapValue(memberGens, name);
}

CallGen * ClassInstanceType::makeCall(AstContext* c, CodeGen* value, const std::string & name, std::vector<std::pair<std::string, CodeGen*>>& arguments) {
	auto it = methds.equal_range(name);
	if (it.first==it.second) { // 如果没找到
		auto *v=getMember(value, name);
		if (v) { // 成员变量
			if (!v->type->isPointerTy() 
				|| !v->type->getPointerElementType()->isFunctionTy())
				throw std::runtime_error("成员变量 " + name + "不是函数");

			std::vector<CodeGen*> gens;
			assert(value);
			gens.push_back(value);
			for (auto i : arguments) {
				gens.push_back(i.second);
			}
			v->object = value;
			auto ft=dyn_cast<FunctionType>(v->type->getPointerElementType());
			auto* p=new CallGen(v, ft, std::move(gens));
			return p;
		}

		return nullptr;
	}
	for (auto i = it.first; i != it.second; i++) {
		if (i->second->isTemplate()) continue;
		auto *p= i->second->makeCall(c, arguments, value, this);
		if (p) return p;
	}
	for (auto i = it.first; i != it.second; i++) {
		if (!i->second->isTemplate()) continue;
		auto *p = i->second->makeCall(c, arguments, value, this);
		if (p) return p;
	}
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

CodeGen * ClassInstanceType::thisGen()
{
	if (_thisGen) return _thisGen;
	assert(_type);
	_thisGen = new ThisGen(_type);
	return _thisGen;
}
