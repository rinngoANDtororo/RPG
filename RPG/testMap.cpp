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
	DrawFormatString(0, 30, 0xff00ff, "testmap");
}