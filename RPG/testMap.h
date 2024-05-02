#pragma once

#include"AbstractMap.h"

class testMap final :public AbstractMap
{
public:
	testMap(CallBack impl);
	~testMap();

	void update()override;
	void draw()const override;
};