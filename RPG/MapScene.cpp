#include "MapScene.h"

MapScene::MapScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	AbstractScene(impl, parameter)
{
	//本来ここでセーブデータに基づいた初期マップを決める。
	auto p = bind(&MapScene::onMapChanged, this, placeholders::_1, placeholders::_2, placeholders::_3);
	_WorldMap[eMapNames::testMap] = make_shared<testMap>(p);
	_WorldMap[eMapNames::testMap2] = make_shared<testMap2>(p);

	_CurrentMap = eMapNames::testMap;
}

void MapScene::update()
{
	_WorldMap[_CurrentMap]->update();
}

void MapScene::draw()
{
	DrawFormatString(100, 100, GetColor(255, 255, 255), "Map Scene");
	_WorldMap[_CurrentMap]->draw();
}

void MapScene::onMapChanged(const eMapNames emapn, const Parameter& parameter, bool isMapClear)
{
	if (_WorldMap.find(emapn) != _WorldMap.end())
		_CurrentMap = emapn;
}