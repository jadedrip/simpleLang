#pragma once
#include "AstNode.h"
#include "AstClass.h"
#include "AstAnnotation.h"

class CodeGen;
/// 用来导入包
/// 例子：	import org.silang.*
class AstImport : public AstNode {
public:
	std::vector<std::string> identifiers;
	bool isFunction = false;
public:
	virtual CodeGen* makeGen(AstContext* parent);
	// void loadCModule(llvm::Module * m);
	virtual void draw(std::ostream& os);
private:
	void loadPackage(const std::string& package);
	void loadClassFromModule(AstClass* cls, AstAnnotation* annotation, AstContext* context, llvm::Module* m);
};
