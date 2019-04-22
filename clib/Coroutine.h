#pragma once
#ifndef __COROUTINE__H__
#define __COROUTINE__H__
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif
	enum CoroutineStatus {
		COROUTINE_DEAD = 0,
		COROUTINE_READY = 1,
		COROUTINE_RUNNING = 2,
		COROUTINE_SUSPEND = 3,
		COROUTINE_TIMEOUT = 4
	};

	struct si_Coroutine;
	struct si_Chan {
		void* data;
		volatile char setted;
	};
	typedef struct si_Chan Chan;

	struct si_Coroutine {
		int64_t timeout;		// 超时时间（超时检测用）
		short status;			// 状态 CoroutineStatus
		void* data;				// 返回值
		struct si_Chan* chan;	// 当前等待的通道
		void* lpFiber;			// 协程句柄
		long parameterCount;	// 闭包变量数量
		int64_t* params;		// 闭包传递的变量一个变量，一个析构函数(如果是对象）
	};

	typedef void* (SiGoFunction)();
	typedef struct si_Coroutine Coroutine;

	int64_t GetCoroutineParams(uint32_t index);

	// 创建协程对象
	Coroutine* CreateCoroutine(uint32_t size);
	void SetCoroutineParams(Coroutine*, size_t index, int64_t v, int64_t func);

	// 创建一个协程
	void si_CoroutineCreate(Coroutine*, SiGoFunction*);

	/// 当前协程主动切换 
	void si_YieldCoroutine();

	/// 析构
	void si_CoroutineFinalize(Coroutine*);

	/// 设置管道
	/// waiting 为0永久等待，否则等待指定时间后将状态改为 timeout
	void* si_AwaitCoroutine(Chan*, int64_t waiting);

	void* si_Coroutine_getData(Coroutine* co);
	void* si_GetCurrentCoroutineData();

	void si_Chan_Init(Chan*);
	/// 通过管道唤醒一个协程
	void si_Chan_BRACKETS(Chan*, void* data);
#ifdef __cplusplus
}
#endif
#endif
