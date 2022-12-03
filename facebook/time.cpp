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

Time::Time(int hour, int minutes, int seconds)
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

bool Time::setHour(int hour)
{
    if (hour < MIN_HOUR || hour > MAX_HOUR)
        return false;

    this->hour = hour;
    return true;
}

bool Time::setMinutes(int minutes)
{
    if (minutes < MIN_MIN || minutes > MAX_MIN)
        return false;

    this->minutes = minutes;
    return true;
}

bool Time::setSeconds(int seconds)
{
    if (seconds < MIN_SEC || seconds > MAX_SEC)
        return false;

    this->seconds = seconds;
    return true;
}

/********* Show *********/

void Time::show() const
{
    cout << (hour < 10 ? "0" : "")
        << hour << ":"
        << (minutes < 10 ? "0" : "")
        << minutes << ":"
        << (seconds < 10 ? "0" : "")
        << seconds;
}