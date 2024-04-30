#pragma once

#include "AbstractScene.h"
#include "Parameter.h"

class GameScene final : public AbstractScene
{
public:
	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() override;
};