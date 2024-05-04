#pragma once

#include "AbstractScene.h"
#include "Parameter.h"
#include "DxLib.h"
#include "Keyboard.h"
#include "Macro.h"
#include <map>
#include <memory>

#include "eMapNames.h"
#include "testMap.h"
#include "testMap2.h"

using namespace std;

class MapScene final : public AbstractScene
{
public:
	MapScene(IOnSceneChangedListener* impl, const Parameter& parameter);
	virtual ~MapScene() = default;

	void update() override;
	void draw() override;

	void onMapChanged(const eMapNames nextmap, const Parameter& parameter, bool isMapClear);

private:
	void CreateNextMap(eMapNames nextmap, const Parameter& parameter);

	eMapNames _CurrentMap;
	map<eMapNames,shared_ptr<AbstractMap>> _WorldMap;
};