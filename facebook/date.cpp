#pragma warning (disable:4996)

#include "date.h"

#include <ctime>
#include <iostream>
using namespace std;

const int MIN_DAY = 1;
const int MAX_DAY = 31;
const int MIN_MONTH = 1;
const int MAX_MONTH = 31;
const int MIN_YEAR = 1000;
const int MAX_YEAR = 3000;
const int CTIME_START_YEAR_COUNT = 1900;
const int CTIME_START_MONTH_COUNT = 1;

Date::Date()
{
    time_t now = time(0);
    tm* temp = localtime(&now);

    year = temp->tm_year + CTIME_START_YEAR_COUNT;
    month = temp->tm_mon + CTIME_START_MONTH_COUNT;
    day = temp->tm_mday;
}

Date::Date(int day, int month, int year)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

bool Date::setDay(int day)
{
    if (day < MIN_DAY || day > MAX_DAY)
        return false;

    this->day = day;
    return true;
}

bool Date::setMonth(int month)
{
    if (month < MIN_MONTH || month > MAX_MONTH)
        return false;

    this->month = month;
    return true;
}

bool Date::setYear(int year)
{
    if (year < MIN_YEAR || year > MAX_YEAR)
        return false;

    this->year = year;
    return true;
}

void Date::show() const
{
    cout << day << "/" << month << "/" << year;
}