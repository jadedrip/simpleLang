#include "stdafx.h"
#include "AstForeach.h"

void AstForeach::draw(std::ostream & os) {
	dotLable(os, "foreach ");

	std::string n = nodeId;
	os << n << " -> " << nodeId << std::endl;
	for (auto i : block) {
		dotPointTo(os, i);
	}
}


