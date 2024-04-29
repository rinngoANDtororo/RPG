#include"Parameter.h"

void Parameter::set(string key, int val)
{
	_map[key] = val;
}

int Parameter::get(string key)const
{
	auto it = _map.find(key);
	
	if (it == _map.end())
		return Error;
	else
		return it->second;
}