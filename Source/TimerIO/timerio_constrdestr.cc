#include "timerio.h"

timerio::Timer::Timer()
{
    clock_gettime(CLOCK_MONOTONIC, &this->start_time);
}