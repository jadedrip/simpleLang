#pragma once
#include "AstContext.h"
#include "Type/ClassInstanceType.h"

class CodeGen;
class ClassInterface;

// 类上下文
class ClassContext : public AstContext
{
public:
	// 类定义工作模式
	ClassContext(AstContext *parent, ClassInstanceType* type);
	// 对象成员操作模式
	ClassContext(AstContext *parent, CodeGen* gen);
	// 通过变量名称查找
	virtual CodeGen* findSymbolValue(const std::string& name, bool recursive);
	CodeGen* value = nullptr;
	virtual CodeGen* makeCall(llvm::LLVMContext& c, const std::string& name, std::vector<std::pair<std::string, CodeGen*>>& arguments);

	ClassInstanceType* getClassType() const { return _type; }
private:
	ClassInstanceType* _type = nullptr;
	CodeGen * _codeGen = nullptr;
};
