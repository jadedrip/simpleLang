#pragma once
#include "AstContext.h"
#include "Type/ClassInstanceType.h"
#include "CodeGenerate/ValueGen.h"
#include "CodeGenerate/GlobelWrapValue.h"

// Go 上下文，仅用于 go { .. } 这样的环境
class GoContext : public AstContext
{
public:
	// 对象成员操作模式
	GoContext(AstContext *parent) : AstContext(parent) {};
	// 通过变量名称查找
	virtual CodeGen* findSymbolValue(const std::string& name, bool recursive)
	{
		auto *p = getMapValue(_symbols, name);
		if (p) return p;

		assert(recursive);
		assert(parent);
		
		// 从外界获取的，需要闭包
		p=parent->findSymbolValue(name, recursive);
		if (!p) return nullptr;
		// 标记为逃逸
		p->escape = true;

		if (dynamic_cast<ValueGen*>(p))
			return p;
		
		std::string n = name + std::to_string((intptr_t)p);
		globels[n] = p;

		auto x=new GlobelWrapValue(std::move(n), p->type);
		_symbols[name] = x;
		return x;
	}
	std::map<std::string, CodeGen*> globels;
};
