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
	void loadCModule(llvm::Module * m);
	virtual void draw(std::ostream& os) {
		std::string n = nodeId;
		os << n << " -> ";
		for (auto i : identifiers) {
			os << i << '.';
		}
		os << std::endl;
	}
private:
	void loadClassFromModule(AstClass* cls, AstAnnotation* annotation, AstContext* context, llvm::Module* m);
};
