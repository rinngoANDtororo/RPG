#pragma once

#include"Singleton.h"
#include<DxLib.h>
#include<array>

using namespace std;

class Keyboard :public Singleton<Keyboard>
{
	Keyboard() = default;
	~Keyboard() = default;
	friend Singleton<Keyboard>;

public:
	bool update();
	
	int getPressingCount(int KeyCode);
	int getReleasingCount(int KeyCode);
	bool getRepeatedInput(int KeyCode);

private:
	static const int KEY_NUM = 256;

	array<int, KEY_NUM> _PressingCount{ 0 };
	array<int, KEY_NUM> _ReleasingCount{ 0 };

	bool isAvailableCode(int KeyCode);
};