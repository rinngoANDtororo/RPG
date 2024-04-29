#pragma once

#include<list>
#include<DxLib.h>
#include"CalcUtils.h"

using namespace std;

class Fps final
{
public:
	Fps();
	void wait();
	void draw()const;

private:
	list<int> _list;
	float _fps;
	unsigned _counter;

	void updateAverage();
	void regist();
	unsigned getWaitTime()const;
};