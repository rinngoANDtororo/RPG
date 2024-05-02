#pragma once

#include "AbstractScene.h"
#include "Parameter.h"

#include "testMap.h"
#include "eMapNames.h"
#include <memory>
#include <map>

class GameScene final : public AbstractScene
{
public:
	GameScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~GameScene() = default;

	void update() override;
	void draw() override;
private:
	map<eMapNames,shared_ptr<AbstractMap>> _WorldMap2;
};