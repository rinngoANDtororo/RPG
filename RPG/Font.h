#pragma once

#include "Singleton.h"
#include <vector>

class Font final : public Singleton<Font>
{
public:
	Font();
	~Font() = default;

	void release();

	void load();

private:
	int myLoadFontDataToHandle(const char* filename, int edgesize);

	std::vector<int> _fonts;
};