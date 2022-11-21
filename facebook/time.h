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

    bool setHour(int h);
    bool setMinutes(int m);
    bool setSeconds(int s);

    void show() const;
};


#endif // __TIME_H