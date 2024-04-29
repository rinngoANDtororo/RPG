#include "Looper.h"
#include "Macro.h"
#include "Font.h"

Looper::Looper()
{
}

Looper::~Looper()
{
}

bool Looper::loop()
{
	_fps.draw();
	_fps.wait();

	return true;
}