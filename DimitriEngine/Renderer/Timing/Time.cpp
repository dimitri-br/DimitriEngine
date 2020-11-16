#include "Time.h"
using DimitriEngine::Time;

Time* Time::instance = 0;


DimitriEngine::Time* DimitriEngine::Time::GetInstance()
{
	if (instance == 0) {
		instance = new Time();
	}

	return instance;
}
