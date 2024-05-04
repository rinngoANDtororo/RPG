#include "MapScene.h"

MapScene::MapScene(IOnSceneChangedListener* impl, const Parameter& parameter) :
	AbstractScene(impl, parameter)
{
	//本来ここでセーブデータに基づいた初期マップを決める。
	const auto pcallback = bind(&MapScene::onMapChanged, this, placeholders::_1, placeholders::_2, placeholders::_3);
	_WorldMap[eMapNames::testMap] = make_shared<testMap>(pcallback);

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

void MapScene::onMapChanged(const eMapNames nextmap, const Parameter& parameter, bool isMapClear)
{
	_CurrentMap = nextmap;

	if (_WorldMap.find(nextmap) == _WorldMap.end())
		CreateNextMap(nextmap);//存在しないなら
}

void MapScene::CreateNextMap(eMapNames nextmap, const Parameter& parameter)
{
	const auto pcallback = bind(&MapScene::onMapChanged, this, placeholders::_1, placeholders::_2, placeholders::_3);

	switch (nextmap)
	{
	case eMapNames::testMap:
		_WorldMap[nextmap] = make_shared<testMap>(pcallback,parameter);
		break;

	case eMapNames::testMap2:
		_WorldMap[nextmap] = make_shared<testMap2>(pcallback, parameter);
		break;

	default:
		ERR("存在しないマップです");
		break;
	}
}