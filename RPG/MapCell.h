#pragma once

#include"eEvent.h"

struct MapCell
{
	int _x;
	int _y;
	int _layer1;//�n�ʂƂ�
	int _layer2;//���̏�̃��C���[
	int _layer3;//�\���H
	bool _canpass;
	eEvent _event;
};