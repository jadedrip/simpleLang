#pragma once
#include "AstType.h"
#include "AstContext.h"
#include "../CodeGenerate/ClassMemberGen.h"

class FunctionInstance;
													
class ClassInstanceType
{
	friend class AstClass;
public:
	static ClassInstanceType* findByName(const std::string& name);
	static ClassInstanceType* findByStruct(llvm::Type* type);
public:
	ClassInstanceType* inherit = nullptr;	// 继承

	ClassInstanceType(const std::string& path, const std::string& name, llvm::StructType* type = nullptr);
public:
	virtual std::string uniqueName();
	virtual llvm::Type* llvmType(llvm::LLVMContext& context);
	AstContext* makeContext(AstContext* parent);
	/// 查询成员对象
	virtual ClassMemberGen* getMember(CodeGen* object, const std::string& name);
	virtual CodeGen * makeCall(llvm::LLVMContext& c, CodeGen * value, const std::string & name, const std::vector<std::pair<std::string, CodeGen*>>& arguments);
	CodeGen* newObject(llvm::LLVMContext& c, std::vector<std::pair<std::string, CodeGen*> >& );
public:
	std::string path;
	std::string name;
	static int serial;
public:
	llvm::StructType* _type = nullptr;
	FunctionInstance* creator = nullptr;
	std::map<std::string, CodeGen*> defaultValues;      // 成员变量默认值
	std::map<std::string, AstFunction*>		methds;		// 模板方法
	std::map<std::string, FunctionInstance*> funcCache;
	std::map<std::string, ClassMemberGen*> memberGens;
};
