#include "stdafx.h"
#include "AstLoop.h"
#include "AstContext.h"
#include "CodeGenerate/LoopGen.h"

using namespace llvm;

CodeGen * AstLoop::makeGen(AstContext * parent)
{
	LoopGen *gen = new LoopGen();
	auto context = new AstContext(parent);
	if(let) gen->let=let->makeGen(context);
	if (cond) gen->cond=cond->makeGen(context);
	if (inc) gen->inc=inc->makeGen(context);

	for (auto i : block) {
		auto p = i->makeGen(context);
		gen->block.push_back(p);
	}
	return gen;
}

void AstLoop::draw(std::ostream & os) {
	dotLable(os, "while ");
	os << nodeId << " -> " << cond->nodeId << "[label=\"condition\"];" << std::endl;
	cond->draw(os);
	dotPointTo(os, block);
}
