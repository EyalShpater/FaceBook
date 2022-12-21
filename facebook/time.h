#ifndef __TIME_H
#define __TIME_H

#include <iostream>

class Time 
{
    int hour, minutes, seconds;

public:
    Time(int hour, int minutes, int seconds);
    Time();

    int getHour() const { return hour; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    bool setHour(int hour);
    bool setMinutes(int minutes);
    bool setSeconds(int seconds);

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif // __TIME_H