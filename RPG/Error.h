#pragma once

#include <Windows.h>

class Error final
{
public:
	static void finish(const char* errormsg, LPCTSTR lpszFuncName, int nline);
};