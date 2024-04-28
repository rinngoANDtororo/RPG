#include "Looper.h"
#include "Macro.h"
#include "Image.h"

Looper::Looper()
{
	Image::getIns()->load();
}

Looper::~Looper()
{
}

bool Looper::loop() const
{
	return true;
}