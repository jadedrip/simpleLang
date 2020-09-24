#pragma once
#include <string>

struct ClassType;
struct Field {
private:
	std::string _name;
	ClassType* _classType;	// 类的类型
	ClassType* _fieldType;		// 字段类型

	intptr_t* _getFunction = nullptr;
	intptr_t* _setFunction = nullptr;
};
