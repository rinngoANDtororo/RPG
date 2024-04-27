#include "Error.h"
#include "string.h"
#include "DxLib.h"
#include "Define.h"

using namespace std;

void Error::finish(const char* errormsg, LPCTSTR lpszFuncName, int nline)
{
	char funcname[1024];
	wsprintf(funcname, "%s", lpszFuncName);
	printfDx("異常が発生しました。\n%s\n%s(%d)\n", errormsg, funcname, nline);
	while (!ProcessMessage())
	{
		ClearDrawScreen();
		ScreenFlip();
	}

	DxLib_End();
	exit(99);
}