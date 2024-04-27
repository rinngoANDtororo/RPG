#include "SystemMain.h"
#include "DxLib.h"
#include "Define.h"
#include "Looper.h"

bool SystemMain::initialize() const
{
	SetAlwaysRunFlag(TRUE);
	SetWindowSizeChangeEnableFlag(TRUE);
	SetOutApplicationLogValidFlag(FALSE);
	SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_DESKTOP);
	SetWindowText("RPG");
	ChangeWindowMode(TRUE);
	SetWindowSizeExtendRate(1.0);
	const int  COLOR_BIT = 32;
	SetGraphMode(Define::WIN_W, Define::WIN_H, COLOR_BIT);
	if (DxLib_Init())
	{
		return false;
	}
	SetDrawScreen(DX_SCREEN_BACK);
	return true;
}

void SystemMain::finalize() const
{
	DxLib_End();
}

void SystemMain::main() const
{
	Looper looper;
	while (!ScreenFlip() && !ProcessMessage() && !ClearDrawScreen())
	{
		if (!looper.loop())
		{
			break;
		}
	}
}