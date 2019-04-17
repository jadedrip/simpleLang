#include "CodeGen.h"

class GenList : public CodeGen {	
public:
	virtual llvm::Value* generateCode(const Generater& generater) {
		llvm::Value *v = nullptr;
		for (auto *i : generates) {
			v=i->generate(generater);
		}
		return v;
	};
public:
	std::vector<CodeGen*> generates;
};
