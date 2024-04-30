#include "GameScene.h"
#include "DxLib.h"
#include "Keyboad.h"

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	AbstractScene(impl, parameter)
{
}

void GameScene::update()
{
	if (Keyboad::getIns()->getPressingCount(KEY_INPUT_SPACE) == 1)
	{
		_implSceneChanged->onSceneChanged(Title, Parameter(), false);
	}
}

void GameScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Game Scene");
}