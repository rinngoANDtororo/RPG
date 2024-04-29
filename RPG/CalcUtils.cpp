#include"CalcUtils.h"

#include<DxLib.h>
#include<cmath>

float CalcUtils::roundPoint(float val, int point)
{
	float ret = 0.0;

	ret = (float)val * (float)pow(10.f, point - 1);
	ret = (float)(int)(ret+ 0.5f);

	return ret * (float)pow(10.f, -point + 1);
}