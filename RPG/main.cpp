#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	DxLib_Init();
	ChangeWindowMode(TRUE);

	WaitKey();

	DxLib_End();

	return 0;
}