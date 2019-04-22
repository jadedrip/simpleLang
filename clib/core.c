#include "stdafx.h"
#include <stdio.h>
#include <stdint.h>
#include <malloc.h>
#include <assert.h>
#include "core.h"

// core.cpp : 定义 DLL 应用程序的导出函数。
//

/**
	对象( Object ) 存储结构
		4 字节引用计数
		4 字节类型信息引用
		对象数据

	返回时指针指向对象数据，可以直接操作。
*/
void* createObject(uint64_t size, uint32_t typeId) {
	//assert(sizeof(LONG) == 4);
	//return malloc(size);
	printf("createObject %lld, %x\r\n", size, typeId);
	LONG* p = (LONG*)malloc(size + 8);
	if (!p) return NULL;
	*p++ = 1L;		// 引用计数
	*p++ = typeId;
	return p;
}

void freeObject(void* object, destructor func)
{
	assert(sizeof(LONG) == 4);

	LONG* p = (LONG*)object;
	p -= 2;
	LONG v = InterlockedDecrement((LONG*)p);	// TODO: 跨平台

	printf("freeObject with: %ld %llx\r\n", v, (uint64_t)func);
	if (v == 0) {
		if(func) (*func)(object);
		printf("freeObject end\r\n");
		free(p);
	}
}

const uint32_t arrayMark = 1 << 31;
void * createArray(uint32_t objectSize, uint32_t typeId, uint32_t length) {
	return createObject(objectSize * length, arrayMark | typeId);
}

long referenceIncrease(void * object) {
	assert(sizeof(LONG) == 4);
	LONG* p = (LONG*)object;
	p -= 2;
	return InterlockedIncrement((LONG*)p);	// TODO: 跨平台
}

