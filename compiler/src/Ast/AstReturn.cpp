#include "stdafx.h"
#include "AstReturn.h"
#include "CodeGenerate\ReturnGen.h"

void AstReturn::draw(std::ostream & os) {
	os << nodeId << "[label=\"Return\" sharp=box style=filled]" << std::endl;
}

CodeGen * AstReturn::makeGen(AstContext * parent)
{
	auto *p=new ReturnGen();
	for (auto &i : returnValues) {
		auto *x=i->makeGen(parent);
		p->returnValues.push_back(x);

	}
	return p;
}
