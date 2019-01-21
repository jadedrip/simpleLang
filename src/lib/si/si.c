#include "stdio.h"

__declspec(dllexport) void si_hello()
{
	printf("Si: Hello world!\r\n");
}
