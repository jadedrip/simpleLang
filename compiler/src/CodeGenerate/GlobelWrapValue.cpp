#include "stdafx.h"
#include "GlobelWrapValue.h"
#include "CallGen.h"

GoWrapValue::GoWrapValue(size_t index, llvm::Type* type) : _index(index) {
	this->type = type;
}

llvm::Value* GoWrapValue::generateCode(const Generater& generater)
{
	auto* m = generater.module;
	auto& builder = generater.builder();

	//llvm::raw_os_ostream os(std::clog);
	//os << "GlobelWrapValue " << _uname << " :";
	//v->print(os);
	//os << "\r\n";
	//os.flush();
	auto* v = CallGen::call(builder, "GetCoroutineParams", _index);
	if (!type->isStructTy()) {
		return builder.CreateLoad(v);
	}
	else {
		return v;
	}
}
