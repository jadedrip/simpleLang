#include "stdafx.h"
#include "utility.h"
#include "AstTryCatch.h"

void AstTryCatch::draw(std::ostream & os) {
	std::string n = nodeId;
	dotLable(os, "catch");
	dotPointTo(os, block);
}

