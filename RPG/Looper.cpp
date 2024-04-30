#include "Looper.h"
#include "Macro.h"
#include "Font.h"
#include "Keyboard.h"
#include "TitleScene.h"
#include "GameScene.h"

Looper::Looper()
{
	Parameter parameter;
	_sceneStack.push(std::make_shared<TitleScene>(this, parameter));
}

Looper::~Looper()
{
}

bool Looper::loop()
{
	Keyboard::getIns()->update();

	_fps.draw();
	_fps.wait();

	_sceneStack.top()->draw();
	_sceneStack.top()->update();

	return true;
}

void Looper::onSceneChanged(const eScene scene, const Parameter& parameter, bool isStackClear)
{
	if (isStackClear)
	{
		while (!_sceneStack.empty())
			_sceneStack.pop();
	}

	switch (scene)
	{
	case Title:
		_sceneStack.push(std::make_shared<TitleScene>(this, parameter));
		break;

	case Game:
		_sceneStack.push(std::make_shared<GameScene>(this, parameter));
		break;
	}
}