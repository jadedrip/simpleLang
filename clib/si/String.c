#include "Windows.h"
#include "String.h"

int toUNICODE(struct si_String* str)
{
	char* old = str->data;
	int length=MultiByteToWideChar(str->encode, 0, (LPCCH)old, 0, 0, 0);
	if (length > 0) {
		wchar_t* n = (wchar_t*)malloc(length);
		str->length = MultiByteToWideChar(str->encode, 0, (LPCCH)old, 0, n, length);
		str->data = (char*)n;
		str->encode = CP_WINUNICODE;
		str->alloc = 1;
	}
	return length;
}

void si_String_init(struct si_String * str, uint16_t encode, char* data, size_t length, struct si_String * source)
{
	str->data = data;
	str->length = length;
	str->encode = encode;
	str->source = source;
	str->alloc = 0;
	//if (!source && length>0 && encode != CP_WINUNICODE) {
	//	toUNICODE(str);
	//}
}

uint64_t si_String_GET_size(struct si_String* s) {
	return s->length;
}

wchar_t si_String_at(struct si_String *str, uint64_t index)
{
	if (index >= str->length)
		return -1;

	wchar_t *d = (wchar_t*)str->data;
	return d[index];
}

char * si_String_Cast_i8_ptr(struct si_String *str)
{
	return str->data;
}
