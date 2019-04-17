#pragma once
#include "CodeGen.h"

class GlobelWrapValue : public CodeGen
{
public:
	GlobelWrapValue(std::string&& uname, llvm::Type* type) : _uname(uname) {
		this->type = type;
	}

	virtual llvm::Value* generateCode(const Generater& generater)
	{
		auto* m = generater.module;
		auto& builder = generater.builder();

		//llvm::raw_os_ostream os(std::clog);
		//os << "GlobelWrapValue " << _uname << " :";
		//v->print(os);
		//os << "\r\n";
		//os.flush();
		if (!type->isStructTy()) {
			auto* v = m->getOrInsertGlobal(_uname, type);
			return builder.CreateLoad(v);
		}
		else {
			auto ty = llvm::PointerType::get(type, 0);
			auto* v = m->getOrInsertGlobal(_uname, ty);
			return v;
		}
	}
private:
	std::string _uname;
};
