#pragma once

#include "eScene.h"
#include "Parameter.h"
#include "AbstractScene.h"

class IOnSceneChangedListener
{
public:
	IOnSceneChangedListener() = default;
	virtual ~IOnSceneChangedListener() = default;
	virtual void onSceneChanged(const eScene scene, const Parameter& parameter, bool isStackClear) = 0;
};