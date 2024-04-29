#pragma once

#include"Singleton.h"
#include<array>
#include<DxLib.h>
#include<algorithm>
#include"Keyboad.h"

using namespace std;

enum ePad {
	left,up,right,down
};

class Pad final :public Singleton<Pad>
{
public:
	Pad();
	~Pad() = default;

	void update();
	int get(ePad eID)const;

private:
	void merge();

	const static int PAD_KEY_NUM = 16;
	array<int, PAD_KEY_NUM> _idArray = { 0 };
	array<int, PAD_KEY_NUM> _pad = { 0 };
};