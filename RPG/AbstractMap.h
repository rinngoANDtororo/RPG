#pragma once

#include"Parameter.h"
#include"eMapNames.h"
#include"Keyboard.h"
#include"Image.h"
#include<functional>
#include<vector>
#include"MapCell.h"
#include"Define.h"
#include"LoadCsv.h"

using namespace std;

typedef function<void(const eMapNames, const Parameter&, bool)> CallbackMapScene;

class AbstractMap
{
protected:
	CallbackMapScene _onMapChanged;

	vector<vector<MapCell>> _mapdata;

public:
	AbstractMap(CallbackMapScene impl, const Parameter& parameter);
	virtual ~AbstractMap() = default;
	virtual void update() = 0;
	virtual void draw()const = 0;

	void LoadMapData(eMapNames mname) { LoadCsv::getMapCsv(mname, _mapdata); }
};