#pragma once

#include<vector>
#include<string>

#include"eMapNames.h"
#include"MapCell.h"
#include"Macro.h"

using namespace std;

class LoadCsv final
{
public:
	LoadCsv() = default;
	~LoadCsv() = default;

	static void getMapCsv(eMapNames mname, vector<vector<MapCell>>& mapdata);

private:
	static string getMapCsvFilepass(eMapNames mname);
	static bool isCharactor(int ch);
	static bool ConvertPassageFlag(int val) { return (val >= 1) ? false : true; }
};