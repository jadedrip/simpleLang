#pragma once
#include <string>
#include <cstdint>
#include <ostream>
#include <functional>
#include <llvm/IR/Constants.h>
#include <llvm/IR/IRBuilder.h>

class AstType;
class AstContext;
class CodeGen;

/// 这个是 AST 语法树的一个节点基类
class AstNode {
public:
	AstNode(const std::string& n = std::string());
	virtual ~AstNode() {}
public:
	std::string name;
	int lineNo;

	/// 用来进行模板推导及生成代码
	virtual CodeGen* makeGen(AstContext* parent);

	/// 进行一次优化扫描
	virtual void reverseOptimalize(AstContext* parent, int part){ }
public:
	/**
	*	输出 dot 语言的绘制信息
	*/
	virtual void draw(std::ostream& os);

	void dotLable(std::ostream& os, const std::string& v, const std::string& shape = std::string());

	/// 绘制从本节点到指定节点的连接箭头
	void dotPointTo(std::ostream& os, AstNode* node, bool array = true);
	void dotPointTo(std::ostream& os, const std::vector<AstNode*>& nodes, bool array = true);

	const std::string nodeId = ptrstr(this);
private:
	std::string ptrstr(void* p) {
		static const char* hex = "0123456789abcdef";
		int32_t v = (int32_t)(intptr_t)p;
		std::string x = "dot";
		for (int i = 28; i > 0; i -= 4)
			x.push_back(hex[(v >> i) & 0xf]);
		return x;
	}
};
