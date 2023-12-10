// common.cpp : 定义静态库的函数。
//

#include "pch.h"
#include "framework.h"

using namespace std;
template<class T>
class Factroy;
// TODO: 这是一个库函数示例
template<class T>
void fncommon( )
{
	const string name = Factroy<AstGet>::name;

	switch (Factory<T>::hash) {
	case Factory<AstGet>:
		return new ScriptGet()
	}
}
