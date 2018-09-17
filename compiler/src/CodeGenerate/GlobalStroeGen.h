#pragma once
#include "CodeGen.h"

/// 全局字符串
class GlobalStroeGen : public CodeGen
{
public:
	GlobalStroeGen(const std::string&n, CodeGen* v) : _val(v), name(n) {
		type = v->type;
	}

	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder) {
		auto v = _val->generate(m, func, builder);
		v = load(builder, v);

		auto ptr = m->getOrInsertGlobal(name, v->getType()); // Is pointer ?
		return builder.CreateStore(ptr, v);
	}
private:
	CodeGen * _val;
	std::string name;
};

