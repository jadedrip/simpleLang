#include "stdafx.h"
#include "AstTry.h"

void AstTry::draw(std::ostream & os) {
	std::string n = nodeId;
	dotLable(os, name, "try");
}

AstNode * AstTry::clone()
{
	return nullptr;
}
