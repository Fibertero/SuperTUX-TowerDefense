#include"raylib.h"
#include"timer.hpp"

void StartTimer(Timer& timer, double lifetime)
{
    timer.startTime = GetTime();
    timer.lifeTime = lifetime;
}

bool TimerDone(Timer timer)
{
    return GetTime() - timer.startTime >= timer.lifeTime;
}

double GetElapsed(Timer timer)
{
    return GetTime() - timer.startTime;
}