#pragma once
#include <string>

static std::string ptrstr( void* p ) {
	static const char* hex = "0123456789abcdef";
	int32_t v = (int32_t)(intptr_t)p;
	std::string x = "dot";
	for (int i = 28; i > 0; i -= 4)
		x.push_back( hex[(v >> i) & 0xf] );
	return x;
}
