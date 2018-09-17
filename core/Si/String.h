#pragma once

struct String{
	long length;
	long encode;
	char *data;
};

unsigned int si_String_at(struct String*, int idx);