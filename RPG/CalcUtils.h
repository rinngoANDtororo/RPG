#pragma once

class CalcUtils final
{
public:
	CalcUtils() = default;

	static float roundPoint(float val, int point);//[val]の小数点第[point]位を四捨五入する
};