#pragma once

#include"Fps.h"
#include "IOnSceneChangedListener.h"
#include "eScene.h"
#include "Parameter.h"
#include <memory>
#include <stack>

class Looper final : public IOnSceneChangedListener
{
public:
	Looper();
	~Looper();
	bool loop();

	void onSceneChanged(const eScene scene, const Parameter& parameter, bool isStackClear) override;

private:
	Fps _fps;

	std::stack<std::shared_ptr<AbstractScene>> _sceneStack;
};