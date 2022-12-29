#ifndef __TIME_H
#define __TIME_H

#include <iostream>

class Time 
{
    int hour, minutes, seconds;

public:
    Time(int hour, int minutes, int seconds) noexcept(false);
    Time();

    int getHour() const { return hour; }
    int getMinutes() const { return minutes; }
    int getSeconds() const { return seconds; }

    void setHour(int hour) noexcept(false);
    void setMinutes(int minutes) noexcept(false);
    void setSeconds(int seconds) noexcept(false);

    friend std::ostream& operator<<(std::ostream& os, const Time& t);
};

#endif // __TIME_H