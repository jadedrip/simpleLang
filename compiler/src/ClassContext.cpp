#include "stdafx.h"
#include "ClassContext.h"
#include "Type/ClassInstanceType.h"
#include "Ast/AstFunction.h"
#include "CodeGenerate/ClassMemberGen.h"
#include "utility.h"

using namespace llvm;
ClassContext::ClassContext(AstContext * parent, CodeGen * gen) : AstContext(parent)
{
	auto *type = llvm::dyn_cast<StructType>(gen->type);
	value = gen;
	std::string name = type->getName();
	std::for_each(name.begin(), name.end(), [](char&c) { if (c == '_') c = '.'; });
	_type = ClassInstanceType::findByName(name);
}

CodeGen * ClassContext::findSymbolValue(const std::string & name, bool recursive)
{				   
	assert(_type);

	{	// 先查找本地参数
		auto v = getMapValue(_symbols, name);
		if (v) return v;
	}

	auto p=_type->getMember(value, name);
	if (p) return p;

	if(parent && recursive)
		return parent->findSymbolValue(name, recursive);
	return nullptr;
}

CodeGen * ClassContext::makeCall(llvm::LLVMContext& c, const std::string & name, std::vector<std::pair<std::string, CodeGen*>>& arguments)
{
	auto x=_type->makeCall(c, name, arguments, value);
	if (x) {
		return x;
	}
	if (parent) return parent->makeCall(c, name, arguments);
	return nullptr;
}
