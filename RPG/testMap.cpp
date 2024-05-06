#include"testMap.h"

testMap::testMap(CallbackMapScene impl, const Parameter& parameter):AbstractMap(impl,parameter)
{
	
}

testMap::~testMap()
{

}

void testMap::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN) == 1)
	{
		Parameter param;
		_onMapChanged(eMapNames::testMap2, param, false);
	}
}

void testMap::draw()const
{
	for (int i = 0; i < _mapdata.size(); i++)
		for (int j = 0; j < _mapdata[0].size(); j++)
			DrawExtendGraph(64 * j, 64 * i, 64 + 64 * j, 64 + 64 * i, Image::getIns()->getMapChip(_mapdata[i][j]._layer1), TRUE);

	DrawFormatString(0, 30, 0xff00ff, "testmap");
}