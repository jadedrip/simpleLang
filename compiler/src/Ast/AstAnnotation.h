#pragma once

#include "AstNode.h"

/**
 * @brief 注解
 */
class AstAnnotation : public AstNode {
public:
	AstNode * defaultValue = nullptr;		// 注解默认值
	std::map<std::string, AstNode*> attrs;	// 注解参数
};
