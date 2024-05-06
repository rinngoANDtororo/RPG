#pragma once

#include"eEvent.h"

struct MapCell
{
	int _x;
	int _y;
	int _layer1;//地面とか
	int _layer2;//その上のレイヤー
	int _layer3;//予備？
	bool _canpass;
	eEvent _event;
};