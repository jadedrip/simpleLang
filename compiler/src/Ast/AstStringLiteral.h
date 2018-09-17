#pragma once
#include <cstdint>
#include <string>
#include <iostream>
#include <sstream>
#include <typeindex>
#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>

#include "AstNode.h"

/**
* 这个类用来保存字符串常量
*/
class AstStringLiteral : public AstNode {
public:
	AstStringLiteral(const char* v);

	virtual CodeGen* makeGen(AstContext* parent);
public:
	void escape();

	unsigned char hex(char c);

	void replaceAll(std::string& orignStr, const std::string& findStr, const std::string& newStr);
};
