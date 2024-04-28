#include "SE.h"
#include "DxLib.h"

SE::SE()
{
}

void SE::load()
{
}

void SE::release()
{
	const int size = _ses.size();
	for (int i = 0; i < size; ++i)
	{
		DeleteSoundMem(_ses[i]);
	}
	_ses.clear();
}

int SE::myLoadSoundMem(const char* filename)
{
	int ret = LoadSoundMem(filename);
	_ses.push_back(ret);
	return ret;
}