#pragma once

#include "Singleton.h"
#include <vector>

class BGM : public Singleton<BGM>
{
public:
	BGM();
	~BGM() = default;
	void load();
	void release();

private:
	int myLoadSoundMem(const char* filename);

	std::vector<int> _bgms;
};