#include "stdafx.h"
#include <llvm/ADT/ArrayRef.h>
#include "AstTupleSpread.h"
#include "AstContext.h"
#include "CodeGenerate/DefGen.h"
#include "CodeGenerate/TupleSpreadGen.h"
#include "../utility.h"
#include "../Type/TupleType.h"

void AstTupleSpread::draw(std::ostream & os) {
	std::string x = "tuple resolve: ";
	for (auto i : vars) {
		x += i + ",";
	}
	x.erase(x.size() - 1);
	dotLable(os, x);

	std::string n = nodeId;
	os << n << " -> " << tuple->nodeId << std::endl;
	tuple->draw(os);
}

using namespace llvm;
CodeGen * AstTupleSpread::makeGen(AstContext * parent)
{
	auto *o = tuple->makeGen(parent);
	if (!o) return nullptr;

	auto *p = dyn_cast<StructType>(o->type);

	//if (vars.size() > p->elements.size()) {
	//	throw std::runtime_error("Tuple spread need more member.");
	//}

	auto iterator = p->element_begin();
	auto *g = new TupleSpreadGen(o);
	for (size_t i = 0; i < vars.size(); ++i) {
		std::string& s = vars[i];
		if (iterator == p->element_end())
			throw std::runtime_error("Tuple spread need more member.");

		Type* type = *iterator++;	// 元组内的类型
		CodeGen* v;

		if (def) {
			v = new DefGen(s, type);
		}
		else {
			v= parent->findSymbolValue(s);
			if (!v) {
				throw std::runtime_error("Tuple spread can't find: " + s); // 解耦找不到变量
			}
			else if (!instanceOf(type,v->type)) {
				throw std::runtime_error("Tuple type not match:" + s); // 解耦变量不匹配
			}
		}
		g->vars.push_back(v);
	}
	return g;
}

