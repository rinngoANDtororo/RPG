#pragma once

#include"AbstractMap.h"

class testMap2 final :public AbstractMap
{
public:
	testMap2(CallBack impl);
	~testMap2();

	void update()override;
	void draw()const override;
};