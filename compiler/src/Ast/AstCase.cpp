#include "stdafx.h"
#include "AstCase.h"
#include "AstContext.h"

void AstCase::draw(std::ostream & os)
{
	dotLable(os, "case ");
	dotPointTo(os, block);
}

void AstCase::reverseOptimalize(AstContext * parent, int part)
{
	for (auto i = block.rbegin(); i != block.rend(); i++) {
		(*i)->reverseOptimalize(_context, part);
	}
}


