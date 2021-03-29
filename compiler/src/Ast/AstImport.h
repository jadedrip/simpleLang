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
	virtual void draw(std::ostream& os);
};
