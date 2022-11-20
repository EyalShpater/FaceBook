#include "time.h"
#include <iostream>
using namespace std;

const int MIN_HOUR = 0;
const int MAX_HOUR = 23;
const int MIN_MIN = 0;
const int MAX_MIN = 59;
const int MIN_SEC = 0;
const int MAX_SEC = 59;

Time::Time(int h, int m, int s)
{
    setHour(h);
    setMinutes(m);
    setSeconds(s);
}
bool Time::setHour(int h)
{
    if (h < MIN_HOUR || h > MAX_HOUR)
        return false;

    hour = h;
    return true;
}
bool Time::setMinutes(int m)
{
    if (m < MIN_MIN || m > MAX_MIN)
        return false;

    minutes = m;
    return true;
}
bool Time::setSeconds(int s)
{
    if (s < MIN_SEC || s > MAX_SEC)
        return false;

    seconds = s;
    return true;
}

void Time::show() const
{
    cout << (hour < 10 ? "0" : "")
        << hour << ":"
        << (minutes < 10 ? "0" : "")
        << minutes << ":"
        << (seconds < 10 ? "0" : "")
        << seconds << endl;
}