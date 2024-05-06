#include "Image.h"
#include "DxLib.h"
#include "Macro.h"

Image::Image()
{
	myLoadDivGraph("src/Images/mapchip.png", 11040, 32, 345, 32, 32, _mapchip);
}

void Image::load()
{
}

void Image::release()
{
	const int size = _images.size();
	for (int i = 0; i < size; ++i)
	{
		DeleteGraph(_images[i]);
	}
	_images.clear();
}

int Image::myLoadGraph(const char* filename)
{
	int ret = LoadGraph(filename);
	_images.push_back(ret);
	return ret;
}

int Image::myLoadDivGraph(const char* filename, int n, int nx, int ny, int w, int h, int* buf)
{
	int ret = LoadDivGraph(filename, n, nx, ny, w, h, buf);
	for (int i = 0; i < n; ++i)
	{
		_images.push_back(buf[i]);
	}
	return ret;
}

const int Image::getMapChip(int chipnum)const
{
	if (chipnum >= MAPCHIP_NUMBER)
	{
		ERR("マップチップの配列範囲外です");
		return -1;
	}
	return _mapchip[chipnum];
}