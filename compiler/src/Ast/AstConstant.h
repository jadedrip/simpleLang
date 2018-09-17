#pragma once
#include "AstNode.h"

class AstContext;

/**
 * 这个类用来保存常量
 */
class AstConstant : public AstNode {
public:
	AstConstant(const std::string& text) { name = text; }

	void set_value(bool v);
	void set_value(int32_t v);
	void set_value(int64_t v);

	virtual CodeGen* makeGen(AstContext* parent);
public:
	virtual void draw(std::ostream& os) {
		dotLable(os, name);
	}
private:
	int64_t _value;
	int _bits = 0;
};
