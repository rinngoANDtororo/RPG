#include "TitleScene.h"
#include "DxLib.h"
#include "Keyboard.h"

TitleScene::TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	AbstractScene(impl, parameter)
{
}

void TitleScene::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) == 1)
	{
		Parameter parameter;
		_implSceneChanged->onSceneChanged(eScene::Map, parameter, false);
	}
}

void TitleScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Title Scene");
}