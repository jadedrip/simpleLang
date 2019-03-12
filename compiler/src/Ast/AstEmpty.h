#pragma once
#include "AstNode.h"
#include "CodeGenerate/TypeOnlyGen.h"

/// 什么东西都没有的节点(数组定义时用)
class AstEmpty : public AstNode {
	CodeGen * makeGen(AstContext * parent)
	{
		return new TypeOnlyGen(nullptr);
	}
};
