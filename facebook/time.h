#ifndef __TIME_H
#define __TIME_H

class Time {
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

    void show() const;
};


#endif // __TIME_H