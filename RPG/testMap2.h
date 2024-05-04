#pragma once

#include"AbstractMap.h"

class testMap2 final :public AbstractMap
{
public:
	testMap2(CallbackMapScene impl, const Parameter& parameter);
	~testMap2();

	void update()override;
	void draw()const override;
};