#include "stdafx.h"
#include "AstNode.h"

/**
*	输出 dot 语言的绘制信息
*/

void AstNode::draw(std::ostream & os) {
	dotLable(os, name);
}

void AstNode::dotLable(std::ostream & os, const std::string & v, const std::string & shape)
{
	std::string sz = v;
	while (sz.find('\r') != -1)
		sz.erase(sz.find('\r'));
	while (sz.find('\n') != -1)
		sz.erase(sz.find('\n'));
	while (sz.find('\0') != -1)
		sz.erase(sz.find('\0'));

	// if (type) sz += " [" + type->name + "]";
	os << nodeId << "[label=\"" + sz + "\" ";
	if (!shape.empty())
		os << "shape=" << shape;
	os << "]" << std::endl;
}

/// 绘制从本节点到指定节点的连接箭头

void AstNode::dotPointTo(std::ostream & os, AstNode * node, bool array) {
	if (node) {
		os << nodeId << (array ? " -> " : " -> ") << node->nodeId << std::endl;
		node->draw(os);
	}
}

void AstNode::dotPointTo(std::ostream & os, const std::vector<AstNode*>& nodes, bool array)
{
	for (auto i : nodes) {
		dotPointTo(os, i, array);
	}
}
