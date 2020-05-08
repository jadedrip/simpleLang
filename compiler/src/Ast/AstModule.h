#pragma once
#include <vector>
#include "AstContext.h"

class AstImport;
class AstNode;
class AstContext;

/// 定义一个 si 文件
class AstModule 
{
public:
	std::vector<std::string> names;
	std::vector<AstImport*> imports;
	std::vector<AstNode*> lines;
public:
	virtual void draw(std::ostream& os);
	void preprocessor(AstContext* context);
	void generateCode(llvm::Module* m);
	llvm::Function* getFunc() { return _func;  }

	std::string name;
private:
	llvm::Function* _func = nullptr;
	std::vector<CodeGen* > _gens;
};
