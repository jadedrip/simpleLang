#pragma once
#include "CodeGen.h"

class ThisGen : public CodeGen
{
public:
	ThisGen(llvm::Type* tp = nullptr)
	{
		type = tp;
	}

	virtual llvm::Value* generateCode(const Generater& generater)
	{
		auto func = generater.func;

		llvm::raw_os_ostream os(std::clog);
		std::clog << "Get this: ";
		func->print(os);
	
		auto begin = func->args().begin();
		auto end = func->args().end();
		if (!begin || begin == end)
			throw std::runtime_error("Function do not have 'this'.");
		llvm::Argument* v = begin;
		type = v->getType();

		os << " ";
		v->print(os, true);
		os.flush();
		std::clog << std::endl;
		return v;
	}
};
