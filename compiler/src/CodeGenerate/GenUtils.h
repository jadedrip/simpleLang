#pragma once
#include "FloatPointerGen.h"

inline double getDouble(CodeGen* gen) {
	auto p=dynamic_cast<FloatPointerGen*>(gen);
	if (!p) throw std::runtime_error("Not float pointer type.");
	return p->value;
}

