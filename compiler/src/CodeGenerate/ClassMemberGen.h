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
	llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&);
	
	ClassMemberGen* clone(CodeGen* thisGen);
	virtual llvm::Value* generate(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>&builder){
		return generateCode(m, func, builder);
	}
};

