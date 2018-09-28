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
#include "utility.h"
#include "../modules.h"

int ClassInstanceType::serial = 0;

using namespace llvm;
std::map<std::string, ClassInstanceType*> classTypes;
std::map<uintptr_t, ClassInstanceType*> llvmClassTypes;

ClassInstanceType * ClassInstanceType::findByName(const std::string & name) {
	return getMapValue(classTypes, name);
}

ClassInstanceType * ClassInstanceType::findByStruct(llvm::Type * type) {
	StructType* p = dyn_cast<StructType>(type);
	if (!p) throw std::runtime_error("Not struct");;
	return getMapValue(llvmClassTypes, (uintptr_t)p);
}

ClassInstanceType::ClassInstanceType(const std::string& path, const std::string& n, llvm::StructType* ty)
{
	this->name = n;
	this->path = path;
	this->_type = ty;
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
	if (_type) return _type;
	return _type;
}

AstContext * ClassInstanceType::makeContext(AstContext * parent)
{
	return new ClassContext(parent, this);
}

ClassMemberGen * ClassInstanceType::getMember(CodeGen* value, const std::string & name) {
	return getMapValue(memberGens, name);
}

CodeGen * ClassInstanceType::makeCall(llvm::LLVMContext& c, CodeGen* value, const std::string & name, const std::vector<std::pair<std::string, CodeGen*>>& arguments) {
	auto it = methds.find(name);
	if (it == methds.end()) {
		auto *func=funcCache[name];
		if (func) {
			return new CallGen(func, arguments, value); //TODO:
		}
		throw std::runtime_error("Can't find function: " + name); // 找不到函数
	}
	return it->second->makeCall(c, arguments, value);
}

CodeGen * ClassInstanceType::newObject(llvm::LLVMContext& c, std::vector<std::pair<std::string, CodeGen*>>& v)
{
	auto *p = new NewGen();
	p->type = llvmType(c);
	if (creator) {
		auto* call = new CallGen(creator, v);
		for (auto &i : v) {
			call->params.push_back(i.second);
		}
		p->construstor = call;
	}
	return p;
}
