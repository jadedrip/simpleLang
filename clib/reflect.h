#pragma once

extern "C" {
	struct ClassType;
	struct Field;

	ClassType* createClass(char* packageName, char* className);
	Field* createField(ClassType* clz, char* fieldName);

};
