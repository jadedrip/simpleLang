#pragma once
#include "CodeGen.h"

class ClassInterface;
class ClassMemberGen : public CodeGen
{
public:
	ClassMemberGen(CodeGen* o = nullptr, int i = -1) : object(o), index(i) {}
	CodeGen *object = nullptr;	// ∂‘œÛ
	int index = -1;
	std::string name;
	// llvm::StructType * classType = nullptr;
	bool isProtected = false;
	llvm::Function* setFunction = nullptr;
	llvm::Function* getFunction = nullptr;
	llvm::Value* generateCode(const Generater& generater);
	
	ClassMemberGen* clone(CodeGen* thisGen);
	virtual llvm::Value* generate(const Generater& generater){
		return generateCode(generater);
	}
};

