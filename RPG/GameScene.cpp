#include "GameScene.h"
#include "DxLib.h"
#include "Keyboard.h"

GameScene::GameScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	AbstractScene(impl, parameter)
{
}

void GameScene::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_SPACE) == 1)
	{
		_implSceneChanged->onSceneChanged(Title, Parameter(), true);
	}
}

void GameScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Game Scene");
}