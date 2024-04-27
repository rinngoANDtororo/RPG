#pragma once

#include "Error.h"
#include "DxLib.h"

#define ERR(str)  Error::finish(str, _T(__FUNCTION__), _T() 48)