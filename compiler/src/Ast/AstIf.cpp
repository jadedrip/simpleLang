#include "stdafx.h"
#include "AstIf.h"
#include "utility.h"
#include "CodeGenerate/BlockGen.h"
#include "CodeGenerate/IfGen.h"
#include "CodeGenerate/StaticGen.h"

using namespace llvm;

void AstIf::draw(std::ostream & os) {
	dotLable(os, "if ", "diamond");

	std::string n = nodeId;
	os << n << " -> " << condition->nodeId << "[label=\"condition\"];" << std::endl;
	condition->draw(os);
}

CodeGen * AstIf::makeGen(AstContext * parent){
	auto g = condition->makeGen(parent);
	
	// 判断是否静态if
	auto *st=dynamic_cast<StaticGen*>(g);
	if (st) {
		if (st->isTrue) {
			return makeCodeGenList(parent, thenBlock);
		} else {
			if (elseBlock.empty()) return nullptr;
			return makeCodeGenList(parent, elseBlock);
		}
	}

	auto *p = new IfGen();
	p->condition = g;
	p->thenBlock = makeCodeGenList(parent, thenBlock);
	if (!elseBlock.empty()) {
		p->elseBlock = makeCodeGenList(parent, elseBlock);
	}
	return p;
}
