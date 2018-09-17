#pragma once
#include "BlockGen.h"

/*
	CaseGen is not a Gen
*/
struct CaseGen {
	std::vector<CodeGen*> conditions;	// 条件
	BlockGen* codes;
};
