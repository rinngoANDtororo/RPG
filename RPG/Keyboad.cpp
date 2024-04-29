#include"Keyboad.h"

bool Keyboad::update()
{
	char nowHitKey[KEY_NUM];
	GetHitKeyStateAll(nowHitKey);

	for (int i = 0; i < KEY_NUM; i++)
	{
		if (nowHitKey[i] != 0)
		{
			if (_ReleasingCount[i] > 0)
				_ReleasingCount[i] = 0;

			_PressingCount[i]++;
		}
		else
		{
			if (_PressingCount[i] > 0)
				_PressingCount[i] = 0;

			_ReleasingCount[i]++;
		}
	}
	return true;
}

bool Keyboad::isAvilableCode(int KeyCode)
{
	if ((0 <= KeyCode && KeyCode < KEY_NUM) == false)
		return false;

	return true;
}

int Keyboad::getPressingCount(int KeyCode)
{
	if (isAvilableCode(KeyCode) == false)
		return -1;

	return _PressingCount[KeyCode];
}

int Keyboad::getReleasingCount(int KeyCode)
{
	if (isAvilableCode(KeyCode) == false)
		return -1;

	return _ReleasingCount[KeyCode];
}

bool Keyboad::getRepeatedInput(int KeyCode)
{
	if (isAvilableCode(KeyCode) == false)
		return false;

	if (_PressingCount[KeyCode] == 1 || (_PressingCount[KeyCode] >= 30 && _PressingCount[KeyCode] % 10 == 0))
		return true;
	else
		return false;
}