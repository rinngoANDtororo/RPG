#pragma once

#include"Parameter.h"
#include"eMapNames.h"
#include"Keyboard.h"
#include<functional>

using namespace std;

typedef function<void(const eMapNames, const Parameter&, bool)> CallbackMapScene;

class AbstractMap
{
protected:
	CallbackMapScene _onMapChanged;

public:
	AbstractMap(CallbackMapScene impl, const Parameter& parameter);
	virtual ~AbstractMap() = default;
	virtual void update() = 0;
	virtual void draw()const = 0;
};