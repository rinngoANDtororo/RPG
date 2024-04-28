#pragma once

#include "Singleton.h"
#include <vector>

class Image : public Singleton<Image>
{
public:
	Image();
	~Image() = default;
	void load();
	void release();

private:
	int myLoadGraph(const char* finlename);
	int myLoadDivGraph(const char* filename, int n, int xn, int yn, int w, int h, int* buf);

	std::vector<int> _images;
};