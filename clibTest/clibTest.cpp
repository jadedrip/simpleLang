#include "pch.h"
#include <iostream>
#include "core.h"
#include "si/String.h"
int main(char* argv[])
{
	String* obj = (String*)createObject(sizeof(String), 887130976);
	si_String_Init_I32(obj, 156);

	String* obj2 = (String*)createObject(sizeof(String), 887130976);
	si_String_Init_M(obj2, 29.0f);

	String* s=si_String_PLUS_si_String(obj, obj2);
	si_print(s);

	return 0;
}