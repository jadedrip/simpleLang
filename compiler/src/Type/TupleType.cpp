#include "stdafx.h"
#include "TupleType.h"
#include "utility.h"

using namespace std;
using namespace llvm;

map<string, StructType*> structs;
hash<string> stringHasher;

llvm::Type * TupleType::create(llvm::LLVMContext& c, const std::vector<llvm::Type*>& types)
{
	if (types.empty())
		return llvm::Type::getVoidTy(c);
	if (types.size() == 1)
		return types.front();

	return makeStruct(c, types);
}

llvm::StructType * makeStruct(llvm::LLVMContext& c, const std::vector<llvm::Type*>& types)
{
	string n;
	for (auto i : types) {
		n += toShort(i); // 每个类型生成一个唯一名称
	}
	if (n.size() > 30) { // 名字太长就截短
		n = "H" + i2hexString(stringHasher(n));
	}

	n = "struct." + n;
	StructType* type = structs[n];
	if (!type) {
		type = StructType::create(c, types, n);
		structs[n] = type;
	}
	return type;
}
