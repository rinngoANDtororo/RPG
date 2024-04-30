#pragma once

#include "AbstractScene.h"

class TitleScene final : public AbstractScene
{
public:
	TitleScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~TitleScene() = default;

	void update() override;
	void draw() override;
};