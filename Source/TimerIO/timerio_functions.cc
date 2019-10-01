#include "timerio.h"

#include <cmath>

void timerio::Timer::Reset()
{
    clock_gettime(CLOCK_MONOTONIC,&this->start_time);
}


double timerio::Timer::GetTime()
{
    timespec  new_time{};
    clock_gettime(CLOCK_MONOTONIC, &new_time);
    timespec diff = this->GetDifference(this->start_time, new_time);
    double diffTime = diff.tv_sec * 1000.0 + diff.tv_nsec / 1000000.0;

    return diffTime;
}


std::string timerio::Timer::GetTimeString()
{
    double time_sec = this->GetTime() / 1000.0;
    auto   hours    = (int)std::floor(time_sec / 60 / 60);
    auto   minutes  = (int)std::floor((time_sec - 60 * 60 * hours) / 60);
    auto   seconds  = (int)time_sec - 3600 * hours - 60 * minutes;

    char buff[100];
    sprintf(buff,"%02d:%02d:%02d", hours, minutes, seconds);

    return std::string(buff);
}


timespec timerio::Timer::GetDifference(timespec start, timespec end)
{

    timespec temp{};
    if ((end.tv_nsec - start.tv_nsec) < 0)
    {
        temp.tv_sec = end.tv_sec - start.tv_sec - 1;
        temp.tv_nsec = 1000000000 + end.tv_nsec - start.tv_nsec;
    }
    else
        {
        temp.tv_sec = end.tv_sec - start.tv_sec;
        temp.tv_nsec = end.tv_nsec - start.tv_nsec;
    }
    return temp;
}