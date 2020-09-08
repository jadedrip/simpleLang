#include "pch.h"
#include <iostream>
#include "core.h"
#include "String.h"
#include "Coroutine.h"

Chan* chan = new Chan;;
void* test()
{
	printf("Hello, coroutine.\r\n");
	int data=(int)si_AwaitCoroutine(chan, 100);
	printf("I am back: %d\r\n", data);
	return 0;
}

void* test2()
{
	printf("Hello, Co2.\r\n");
	si_YieldCoroutine();
	Sleep(100);
	printf("Co2 am back\r\n");
	return 0;
}

int main(char* argv[])
{
	Coroutine* co1 = new Coroutine();
	si_CoroutineCreate(co1, &test);
	Coroutine* co2 = new Coroutine();
	si_CoroutineCreate(co2, &test2);

	Sleep(50);
	si_Chan_BRACKETS(chan, (void*)18);

	printf("%d,%d \r\n", co1->status, co2->status);


	//String* obj = (String*)createObject(sizeof(String), 887130976);
	//si_String_Init_I32(obj, 156);

	//String* obj2 = (String*)createObject(sizeof(String), 887130976);
	//si_String_Init_M(obj2, 29.0f);

	//String* s=si_String_PLUS_si_String(obj, obj2);
	//si_print(s);
	int i;
	std::cin >> i;
	// si_DestroyCoroutine();
	return 0;
}
