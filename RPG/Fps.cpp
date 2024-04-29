#include"Fps.h"

const static int LIST_LEN_MAX = 120;
const static int FPS = 60;
const static int UPINTVL = 60;

Fps::Fps() :_fps(0.0), _counter(0)
{

}

void Fps::wait()
{
	_counter++;
	Sleep(getWaitTime());
	regist();
	if (_counter == UPINTVL)
	{
		updateAverage();
		_counter = 0;
	}
}

void Fps::draw()const
{
	if (_fps != 0)
		DrawFormatString(0, 0, 0xff0000, "%04.1fFPS", _fps);
}

void Fps::regist()
{
	_list.push_back(GetNowCount());
	if (_list.size() > LIST_LEN_MAX)
		_list.pop_front();
}

unsigned Fps::getWaitTime()const
{
	int len = (int)_list.size();

	if (len == 0)
		return 0;

	int shouldTookTime = (int)(1000 / (float)FPS * (len));
	int actuallyTookTime = GetNowCount() - _list.front();
	int waitTime = shouldTookTime - actuallyTookTime;
	waitTime = (waitTime > 0) ? waitTime : 0;
	return (unsigned)(waitTime);
}

void Fps::updateAverage()
{
	int len = (int)_list.size();
	if (len < LIST_LEN_MAX)
		return;

	int tookTime = _list.back() - _list.front();
	float average = (float)tookTime / (len - 1);
	if (average == 0)
		return;

	_fps = CalcUtils::roundPoint(1000 / average, 2);
}