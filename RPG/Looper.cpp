#include "Looper.h"
#include "Macro.h"
#include "Font.h"
#include "Keyboad.h"

Looper::Looper()
{
}

Looper::~Looper()
{
}

bool Looper::loop()
{
	Keyboad::getIns()->update();

	_fps.draw();
	_fps.wait();

	return true;
}