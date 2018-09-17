#include "stdafx.h"
#include "AstSequence.h"
#include "CodeGenerate/SequenceGen.h"

/// 用来进行模板推导

AstSequence::AstSequence(AstNode * node) {
	auto list = dynamic_cast<AstList*>(node);
	if (list) {
		this->lines = std::move(list->lines);
	}
	else {
		this->lines.push_back(node);
	}
}

CodeGen * AstSequence::makeGen(AstContext * parent) {
	auto p = new SequenceGen();
	for (auto &i : lines) {
		auto *v=i->makeGen(parent);
		p->values.push_back(v);
		p->type = v->type;
	}
	return p;
}
