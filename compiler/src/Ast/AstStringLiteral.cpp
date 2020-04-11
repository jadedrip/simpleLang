#include "stdafx.h"
#include "AstStringLiteral.h"
#include "AstModule.h"
#include "../CodeGenerate/StringLiteGen.h"

AstStringLiteral::AstStringLiteral(const char * v) {
	if (v[0] == '"') {
		name.assign(v + 1);
		// 去除首尾双引号
		name.erase(name.end() - 1);
	}
	else {
		name.assign(v);
	}
	escape();
}

CodeGen * AstStringLiteral::makeGen(AstContext * parent)
{
	return new StringLiteGen(parent->context(), name);
}

void AstStringLiteral::escape() {
	size_t pos = 0;
	while (true) {
		pos = name.find('\\', pos);
		if (pos == std::string::npos) break;
		if (pos == name.size() - 1) throw std::runtime_error("非法字符串");
		char c = name[pos + 1];
		switch (c) {
		case 'a':	// \a 响铃(BEL) 007
			name.replace(pos++, 2, "\a");
			break;
		case 'b':	//	\b 退格(BS) 008
			name.replace(pos++, 2, "\b");
			break;
		case 'f':	//	\f 换页(FF) 012
			name.replace(pos++, 2, "\f");
			break;
		case 'n':	//	\n 换行(LF) 010
			name.replace(pos++, 2, "\n");
			break;
		case 'r':	//	\r 回车(CR) 013
			name.replace(pos++, 2, "\r");
			break;
		case 't':	//	\t 水平制表(HT) 009
			name.replace(pos++, 2, "\t");
			break;
		case 'v':	//	\v 垂直制表(VT) 011
			name.replace(pos++, 2, "\v");
			break;
		case '\\':	//	\\ 反斜杠 092
			name.replace(pos++, 2, "\\");
			break;
		case '\'':	//	\' 单引号字符 039
			name.replace(pos++, 2, "\'");
			break;
		case '\"':	//	\" 双引号字符 034
			name.replace(pos++, 2, "\"");
			break;
		case '\0':	//	\0 空字符(NULL) 000
			name.replace(pos++, 2, "\0");
			break;
		case 'x':	//  \xhh 任意字符 二位十六进制
			if (name.size() - 1 < pos + 3)	// 如果字符不足
				throw std::runtime_error("非法的转义字符");
			{
				unsigned char v = hex(name[pos + 2]);
				v = v << 4 | hex(name[pos + 3]);
				name.erase(pos, 3);
				name[pos++] = (char)v;
			}
		default:
			if (c >= '0' && c <= '7') {	// 0 ~ 7
				if (name.size() - 1 == pos + 1) {	// 如果是最后一个字符
					name.erase(pos);
					name[pos] = 0;
					return;
				}

				unsigned char v = c - '0';
				c = name[pos + 2];
				if (c >= '0' && c <= '7') {	// 下一个字符仍然是 0~7, 那么认为是 3字节8进制
					v = v << 3 | (c - '0');
					if (name.size() < pos + 4)	throw std::runtime_error("非法的转义字符");
					c = name[pos + 3];
					if (c >= '0' && c <= '7') {
						v = v << 3 | (c - '0');
						name.erase(pos, 3);
						name[pos] = (char)v;
					}
					else {
						throw std::runtime_error("非法的转义字符");
					}
				}
				else {
					name.erase(pos);
					name[pos++] = 0;
				}
			}
			break;
		}
	}
}

unsigned char AstStringLiteral::hex(char c) {
	if (c >= '0' && c <= '9') {
		return c - '0';
	}
	else if (c >= 'a' && c <= 'f') {
		return c - 'a';
	}
	else if (c >= 'A' && c <= 'F') {
		return c - 'A';
	}
	else {
		throw std::runtime_error("非法的转义字符");
	}
}

void AstStringLiteral::replaceAll(std::string & orignStr, const std::string & findStr, const std::string & newStr) {
	size_t pos = 0;
	auto l = findStr.size();
	auto newStrLen = newStr.size();
	while (true) {
		pos = orignStr.find(findStr, pos);
		if (pos == std::string::npos) break;

		orignStr.replace(pos, l, newStr);
		pos += newStrLen;
	}
}
