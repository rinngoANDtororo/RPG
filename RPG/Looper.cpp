#include "Looper.h"
#include "Macro.h"
#include "Font.h"
<<<<<<< HEAD
=======
#include "Keyboad.h"
>>>>>>> 9bd0eaf058b471a74fb7ba6134797b693ba7f8f6

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