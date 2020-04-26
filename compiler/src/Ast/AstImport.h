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
public:
	virtual CodeGen* makeGen(AstContext* parent);
	// void loadCModule(llvm::Module * m);
	virtual void draw(std::ostream& os);

	static AstClass* loadClass(const std::string& path, const std::string& name);
private:
	static void loadPackage(const std::string& package);
};
