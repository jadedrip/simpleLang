#pragma once
#include <vector>
#include "AstContext.h"
#include "CodeGenerate/FileGen.h"

class AstImport;
class AstNode;
class AstContext;

/// 定义一个 sl 文件
class AstModule 
{
public:
	std::vector<std::string> names;
	std::vector<AstImport*> imports;
	std::vector<AstNode*> lines;
public:
	virtual void draw(std::ostream& os);
	FileGen* preprocessor(AstContext* context);
	llvm::Function* getFunc() { return _func;  }

	std::string name;
private:
	llvm::Function* _func = nullptr;
};
