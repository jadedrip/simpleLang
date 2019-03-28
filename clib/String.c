#include "stdio.h"
#include "Windows.h"
#include "String.h"
#include "core.h"

//int toUNICODE(struct si_String* str)
//{
//	char* old = str->data;
//	int length=MultiByteToWideChar(str->encode, 0, (LPCCH)old, 0, 0, 0);
//	if (length > 0) {
//		wchar_t* n = (wchar_t*)malloc(length);
//		str->length = MultiByteToWideChar(str->encode, 0, (LPCCH)old, 0, n, length);
//		str->data = (char*)n;
//		str->encode = CP_WINUNICODE;
//		str->alloc = 1;
//	}
//	return length;
//}

void si_Charset_Init(struct si_Charset * ptr, uint16_t code)
{
	ptr->code = code;
}

void si_String_Init(String * str, char * data, uint64_t length, uint16_t encode)
{
	str->data = (wchar_t*)data;
	str->length = length;
	// str->encode = encode;
	str->alloc = 0;
	//if (!source && length>0 && encode != CP_WINUNICODE) {
	//	toUNICODE(str);
	//}

	// wsprintfW(data);
	// wprintf(L"\r\nCall String(data, %lld, %d): %.*ls\r\n", length, encode, (int)length, str->data);
}

void si_String_Finalize(struct si_String * str)
{
	if (str->alloc)
		free(str->data);
}

String* si_String_Splice(String * str, int64_t index, int64_t length)
{
	if (!str) {
		printf("Spilce failed: String is null");
		return NULL;
	}

	if (str->length == 0 || (index < 0 && length < 0))
		return str;

	LONG* p = (LONG*)str;
	String* n = (String*)createObject(sizeof(String), *(p - 1));
	n->alloc = 0;

	if (index < 0) {
		index = str->length - length;
		if (index < 0) index = 0;
	}

	if (index >= str->length) {
		n->length = 0;
		n->data = NULL;
	} else {
		size_t sz = str->length - index;
		if (length < 0L)
			n->length = sz;
		else
			n->length = min(sz, length);
		n->data = str->data + index;
	}

	return n;
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
	return (char*)str->data;
}

void si_print(String * str)
{
	if (!str || !str->data) return;
	wchar_t* data = (wchar_t*)str->data;
	size_t len = str->length;

	// wprintf(L"\r\nCall print : %ls, %lld\r\n", data, len);
	wprintf(L"%.*ls", (int)len, data);
}

void si_println(String* str)
{
	if (!str || !str->data) return;

	wchar_t* data = (wchar_t*)str->data;
	size_t len = str->length;

	// wprintf(L"\r\nCall print : %ls, %lld\r\n", data, len);
	wprintf(L"%.*ls\r\n", (int)len, data);
}

String * si_String_PLUS_si_String(String * str, String * right)
{
	if (!str) {
		printf("si_String_PLUS_si_String's str is null!\r\n");
		return str;
	} else if(!right){
		printf("si_String_PLUS_si_String's right is null!\r\n");
		return str;
	}
	LONG* p = (LONG*)str;
	String* n = (String*)createObject(sizeof(String), *(p - 1));
	n->alloc = 1;
	n->length = str->length + right->length;
	n->data = (wchar_t*)malloc(sizeof(wchar_t)* (n->length+1));
	memcpy(n->data, str->data, sizeof (wchar_t)*(str->length));
	memcpy(n->data + str->length, right->data, sizeof(wchar_t)*right->length);
	n->data[n->length] = 0;
	return n;
}

void si_String_Init_I32(String *n, int32_t v)
{
	// printf("Call Init I32 %d\r\n", v);
	wchar_t *buf = n->data = (wchar_t*)malloc(30);
	_itow_s(v, buf, 15, 10);
	n->length = lstrlenW(buf);
	n->alloc = 1;
}

void si_String_Init_I64(String * n, int64_t v)
{
	// printf("Call Init I64 %lld: \r\n", v);
	wchar_t *buf = n->data = (wchar_t*)malloc(50);
	_i64tow_s(v, buf, 25, 10);
	n->length = lstrlenW(buf);
	n->alloc = 1;
}

void si_String_Init_M(String * str, float v)
{
	si_String_Init_N(str, v);
}

void si_String_Init_N(String * n, double v)
{
	// printf("Call Init float %f: \r\n", v);
	wchar_t *buf = n->data = (wchar_t*)malloc(50);
	swprintf(buf, 25, L"%f", v);
	n->length = lstrlenW(buf);
	n->alloc = 1;
}

void si_String_Init_si_String(String * str, String * v)
{
	str->data = v->data;
	str->alloc = 0;
	str->length = v->length;
}
