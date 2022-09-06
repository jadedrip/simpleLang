#include "CodeGen.h"

class FileGen : public CodeGen {
public:
	virtual llvm::Value* generateCode(const Generater& generater) {
		llvm::Value* v = nullptr;
		for (auto* i : generates) {
			v = i->generate(generater);
		}
		return v;
	};

	virtual void run(GenContent& content) {
		for (auto* i : generates) {
			i->run(content);
		}
	}

	llvm::Function* generateCode(llvm::Module* m);
public:
	std::vector<CodeGen*> generates;
};
