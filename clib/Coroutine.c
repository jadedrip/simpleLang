#include "stdafx.h"
#include "Coroutine.h"
#include "DispatchBind.h"

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
