#include "Image.h"
#include "DxLib.h"

Image::Image()
{
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
	for (int i = 0; i < n; +i)
	{
		_images.push_back(buf[i]);
	}
	return ret;
}