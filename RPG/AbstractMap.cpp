#include"AbstractMap.h"

AbstractMap::AbstractMap(CallbackMapScene impl, const Parameter& parameter):
	_onMapChanged(impl)
{
	
}