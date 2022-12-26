#pragma warning (disable:4996)

#include "time.h"

#include <ctime>
#include <iostream>
using namespace std;

/********* Const variables declaration *********/

const int MIN_HOUR = 0;
const int MAX_HOUR = 23;
const int MIN_MIN = 0;
const int MAX_MIN = 59;
const int MIN_SEC = 0;
const int MAX_SEC = 59;

/********* Constructors *********/

Time::Time(int hour, int minutes, int seconds) noexcept(false)
{
    setHour(hour);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time::Time() 
{
    time_t now = time(nullptr);
    tm* temp = localtime(&now);

    hour = temp->tm_hour;
    minutes = temp->tm_min;
    seconds = temp->tm_sec;
}

/********* Setters *********/

void Time::setHour(int hour) noexcept(false)
{
    if (hour < MIN_HOUR || hour > MAX_HOUR)
        throw WrongHourException();

    this->hour = hour;
}

void Time::setMinutes(int minutes) noexcept(false)
{
    if (minutes < MIN_MIN || minutes > MAX_MIN)
        throw WrongMinuteException();

    this->minutes = minutes;
}

void Time::setSeconds(int seconds) noexcept(false) 
{
    if (seconds < MIN_SEC || seconds > MAX_SEC)
        throw WrongSecondException();

    this->seconds = seconds;
}

/********* Show *********/

ostream& operator<<(ostream& os, const Time& t)
{
    os << (t.hour < 10 ? "0" : "")
        << t.hour << ":"
        << (t.minutes < 10 ? "0" : "")
        << t.minutes << ":"
        << (t.seconds < 10 ? "0" : "")
        << t.seconds;

    return os;
}