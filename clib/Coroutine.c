#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "Coroutine.h"
#include "DispatchBind.h"
#include "core.h"


Coroutine* CreateCoroutine(uint32_t size)
{
	Coroutine* p = (Coroutine*)createObject(sizeof(Coroutine), 14);
	if (size > 0) {
		p->parameterCount = size;
		p->params = (int64_t*)malloc(2 * size * sizeof(int64_t));
	}
	p->status = COROUTINE_READY;
	printf("CreateCoroutine with size %d\r\n", size);
	return p;
}

void SetCoroutineParams(Coroutine* c, size_t index, int64_t v, int64_t func)
{
	printf("SetCoroutineParams(index=%zu, v=%llx, func=%llx\r\n", index, v, (intptr_t)func);

	assert(index <= c->parameterCount);
	int64_t* p = c->params;
	p += index * 2;
	*p++ = v;
	*p = (int64_t)func;
}

int64_t GetCoroutineParams(uint32_t index)
{
	int64_t v = DispatchGetCoroutineParam(index);
	printf("Load coroutine param by index %d: %llx\r\n", index, v);
	return v;
}

void si_CoroutineCreate(Coroutine* co, SiGoFunction *func)
{
	DispatchCreateCoroutine(co, func);
}

void si_YieldCoroutine()
{
	DispatchYield();
}

void* si_AwaitCoroutine(Chan *chan, int64_t waiting)
{
	DispatchSetSuspend(chan, waiting);
	DispatchYield();
	return chan->data;
}

void* si_Coroutine_getData(Coroutine* co)
{
	return co->data;
}

void* si_GetCurrentCoroutineData()
{
	return DispatchGetCurrent()->data;
}

void si_Chan_Init(Chan *chan)
{
	chan->data = 0;
	chan->setted = 0;
}

void si_Chan_BRACKETS(Chan* chan, void* data)
{
	chan->data = data;
	chan->setted = 1;
}
