#include "BGM.h"
#include "DxLib.h"

BGM::BGM()
{
}

void BGM::load()
{

}

void BGM::release()
{
	const int size = _bgms.size();
	for (int i = 0; i < size; ++i)
	{
		DeleteSoundMem(_bgms[i]);
	}
	_bgms.clear();
}

int BGM::myLoadSoundMem(const char* filename)
{
	int ret = LoadSoundMem(filename);
	_bgms.push_back(ret);
	return ret;
}