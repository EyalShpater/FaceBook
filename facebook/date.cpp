#include "date.h"

#include <iostream>
using namespace std;

const int MIN_DAY = 1;
const int MAX_DAY = 31;
const int MIN_MONTH = 1;
const int MAX_MONTH = 31;
const int MIN_YEAR = 1000;
const int MAX_YEAR = 3000;

Date::Date(int d, int m, int y)
{
    setDay(d);
    setMonth(m);
    setYear(y);
}

bool Date::setDay(int d)
{
    if (d < MIN_DAY || d > MAX_DAY)
        return false;

    day = d;
    return true;
}

bool Date::setMonth(int m)
{
    if (m < MIN_MONTH || m > MAX_MONTH)
        return false;

    month = m;
    return true;
}

bool Date::setYear(int y)
{
    if (y < MIN_YEAR || y > MAX_YEAR)
        return false;

    year = y;
    return true;
}

void Date::show() const
{
    cout << day << "/" << month << "/" << year << endl;
}