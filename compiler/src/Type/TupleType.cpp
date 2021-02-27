#include "stdafx.h"
#include "TupleType.h"
#include "utility.h"

using namespace std;
using namespace llvm;

map<string, StructType*> structs;
hash<string> stringHasher;

inline Type* withPointer(Type* type)
{
	if (type->isStructTy()) {
		return PointerType::get(type, 0);
	}
	return type;
}

llvm::Type * TupleType::create(llvm::LLVMContext& c, const std::vector<llvm::Type*>& types)
{
	if (types.empty())
		return llvm::Type::getVoidTy(c);
	if (types.size() == 1) {
		return withPointer(types.front());
	}

	return makeStruct(c, types);
}

llvm::StructType * makeStruct(llvm::LLVMContext& c, const std::vector<llvm::Type*>& types)
{
	string n;
	for (auto i : types) {
		n += getCompression(i); // 每个类型生成一个唯一名称
	}

	n = "struct." + n;
	StructType* type = structs[n];
	if (!type) {
		// 类型保存指针
		std::vector<Type*> v;
		for (auto i : types) {
			v.push_back(withPointer(i));
		}
		type = StructType::create(c, v, n);
		structs[n] = type;
	}
	return type;
}
