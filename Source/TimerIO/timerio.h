#ifndef _TIMERIO_
#define _TIMERIO_

#include <string>
#include <time.h>

namespace timerio
{
    class Timer
    {
    public:
        timespec start_time;
    public:
        Timer();
        void            Reset();
        double          GetTime();
        std::string     GetTimeString();
        timespec        GetDifference(timespec start, timespec end);
    };
}
#endif // TIMERIO_H