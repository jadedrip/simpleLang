#include "stdafx.h"
#include "CompilerOptions.h"

CompilerOptions g_compilerOptions;
CompilerOptions& CompilerOptions::instance()
{
	return g_compilerOptions;
}
