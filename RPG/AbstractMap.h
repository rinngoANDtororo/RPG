#pragma once

#include"Parameter.h"
#include"eMapNames.h"
#include"Keyboard.h"
#include<functional>

using namespace std;

typedef function<void(const eMapNames, const Parameter&, bool)> CallBack;

class AbstractMap
{
protected:
	CallBack _impl;

public:
	AbstractMap(CallBack impl);
	virtual ~AbstractMap() = default;
	virtual void update() = 0;
	virtual void draw()const = 0;
};