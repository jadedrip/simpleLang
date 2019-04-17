#include "stdafx.h"
#include "TupleGen.h"
#include <llvm/IR/Function.h>
#include "../Type/TupleType.h"

using namespace std;
using namespace llvm;
llvm::Value * TupleGen::generateCode(const Generater& generater)
{
	auto func = generater.func;
	auto& builder = generater.builder();

	std::vector< Value* > values;
	std::vector< Type* > types;
	for (auto i : elements) {
		Value* v = i->generate(generater);
		v = load(builder, v);
		values.push_back(v);
		types.push_back(v->getType());
	}
	type = makeStruct(builder.getContext(), types);

	IRBuilder<> allocBuilder(&func->getEntryBlock());
	Value* tuple = allocBuilder.CreateAlloca(type, nullptr, "tuple");

	for (size_t i = 0; i < values.size(); i++) {
		Value* v = values.at(i);
		Value* ptr = builder.CreateConstInBoundsGEP2_32(type, tuple, 0, (unsigned int)i);
		builder.CreateStore(v, ptr);
	}

	return tuple;
}
