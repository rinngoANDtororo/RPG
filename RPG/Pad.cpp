#include"Pad.h"

Pad::Pad()
{
	_idArray[ePad::down] = 0;
	_idArray[ePad::left] = 1;
	_idArray[ePad::right] = 2;
	_idArray[ePad::up] = 3;
}

void Pad::update()
{
	int padInput;

	padInput = GetJoypadInputState(DX_INPUT_PAD1);
	
	for (int i = 0; i < PAD_KEY_NUM; i++)
	{
		if (padInput & (1 << i))
			_pad[i]++;
		else
			_pad[i] = 0;
	}
	merge();
}

int Pad::get(ePad eID)const
{
	return _pad[_idArray[eID]];
}

void Pad::merge()
{
	_pad[_idArray[ePad::down]] = max(_pad[_idArray[ePad::down]], Keyboard::getIns()->getPressingCount(KEY_INPUT_DOWN));
	_pad[_idArray[ePad::left]] = max(_pad[_idArray[ePad::left]], Keyboard::getIns()->getPressingCount(KEY_INPUT_LEFT));
	_pad[_idArray[ePad::right]] = max(_pad[_idArray[ePad::right]], Keyboard::getIns()->getPressingCount(KEY_INPUT_RIGHT));
	_pad[_idArray[ePad::up]] = max(_pad[_idArray[ePad::up]], Keyboard::getIns()->getPressingCount(KEY_INPUT_UP));
}