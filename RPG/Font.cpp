#include "Font.h"
#include "DxLib.h"

Font::Font()
{
}

void Font::load()
{
}

void Font::release()
{
	int size = _fonts.size();
	for (int i = 0; i < size; ++i)
	{
		DeleteFontToHandle(_fonts[i]);
	}
	_fonts.clear();
}

int Font::myLoadFontDataToHandle(const char* filename, int edgesize)
{
	int ret = LoadFontDataToHandle(filename, edgesize);
	_fonts.push_back(ret);
	return ret;
}