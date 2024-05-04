#pragma once

#include"AbstractMap.h"

class testMap final :public AbstractMap
{
public:
	testMap(CallbackMapScene impl, const Parameter& parameter);
	~testMap();

	void update()override;
	void draw()const override;
};