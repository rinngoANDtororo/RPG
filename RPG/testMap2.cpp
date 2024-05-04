#include"testMap2.h"

testMap2::testMap2(CallbackMapScene impl, const Parameter& parameter):AbstractMap(impl,parameter)
{

}

testMap2::~testMap2()
{

}

void testMap2::update()
{
	if (Keyboard::getIns()->getPressingCount(KEY_INPUT_RETURN) == 1)
	{
		Parameter param;
		_onMapChanged(eMapNames::testMap, param, false);
	}
}

void testMap2::draw()const
{
	DrawFormatString(0, 60, 0xff00ff, "testmap2");
}