#ifndef _PRETTYPRINT_H_
#define _PRETTYPRINT_H_

#ifdef _WIN32
#include <Windows.h>
#endif

#include <stdio.h>
#include <stdlib.h>

namespace pp
{
	extern size_t Success(const char* format, ...);
	extern size_t Info(const char* format, ...);
	extern size_t Warning(const char* format, ...);
	extern size_t Error(const char* format, ...);
	extern size_t Fatal(const char* format, ...);
	extern size_t Hexdump(const unsigned char* base, size_t len);
}

#endif // _PRETTYPRINT_H_
