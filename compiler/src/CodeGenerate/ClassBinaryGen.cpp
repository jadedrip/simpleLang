#include "stdafx.h"
#include "ClassBinaryGen.h"
#include "utility.h"

using namespace std;
ClassBinaryGen::ClassBinaryGen(int op, CodeGen * l, CodeGen * r)
{
	this->op = op;
	left = l;
	right = r;			  

	type = l->type;
}

llvm::Value * ClassBinaryGen::generateCode(const Generater& generater)
{
	auto *o=left->generate(generater);
	auto *r = right->generate(generater);
	string word = operator_to_word(op);
	string n = getReadable(left->type) + "_" + word + "_" + getReadable(right->type);

	return nullptr;
}
