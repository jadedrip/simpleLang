#include "CodeGen.h"

class GenList : public CodeGen {	
public:
	virtual llvm::Value* generateCode(llvm::Module *m, llvm::Function *func, llvm::IRBuilder<>& builder) {
		llvm::Value *v = nullptr;
		for (auto *i : generates) {
			v=i->generate(m, func, builder);
		}
		return v;
	};
public:
	std::vector<CodeGen*> generates;
};
