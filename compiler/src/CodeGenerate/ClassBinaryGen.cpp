#include "stdafx.h"
#include "ClassBinaryGen.h"

ClassBinaryGen::ClassBinaryGen(int op, CodeGen * l, CodeGen * r)
{
	this->op = op;
	left = l;
	right = r;			  

	type = l->type;
}
