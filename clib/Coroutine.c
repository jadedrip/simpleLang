#include "stdafx.h"
#include <malloc.h>
#include "Coroutine.h"
#include "DispatchBind.h"

Coroutine* CreateCoroutine(long size)
{
	Coroutine* p=(Coroutine*)malloc(sizeof(Coroutine));
	memset(p, 0, sizeof(Coroutine));
	if (size > 0) {
		p->parameterSize = size;
		p->params = (int64_t*)malloc(2 * size * sizeof(int64_t));
	}
	p->status = COROUTINE_READY;
	return p;
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
