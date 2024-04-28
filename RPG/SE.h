#pragma once

#include "Singleton.h"
#include <vector>

class SE : public Singleton<SE>
{
public:
	SE();
	~SE() = default;
	void load();
	void release();

	int getSE();

private:
	int myLoadSoundMem(const char* filename);

	std::vector<int> _ses;
};