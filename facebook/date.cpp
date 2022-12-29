#pragma warning (disable:4996)

#include "date.h"
#include "timeException.h"

#include <ctime>
#include <iostream>
using namespace std;

/********* Const variables declaration *********/

const int MIN_DAY = 1;
const int MAX_DAY = 31;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_YEAR = 1900;
const int MAX_YEAR = 2022;
const int CTIME_START_YEAR_COUNT = 1900;
const int CTIME_START_MONTH_COUNT = 1;

/********* Constructors *********/

Date::Date()
{
    time_t now = time(nullptr);
    tm* temp = localtime(&now);

    year = temp->tm_year + CTIME_START_YEAR_COUNT;
    month = temp->tm_mon + CTIME_START_MONTH_COUNT;
    day = temp->tm_mday;
}

Date::Date(int day, int month, int year) noexcept(false)
{
    setDay(day);
    setMonth(month);
    setYear(year);
}

/********* Setters *********/

void Date::setDay(int day) noexcept(false)
{
    if (day < MIN_DAY || day > MAX_DAY)
        throw WrongDayException(day);

    this->day = day;
}

void Date::setMonth(int month) noexcept(false)
{
    if (month < MIN_MONTH || month > MAX_MONTH)
        throw WrongMonthException(month);

    this->month = month;
}

void Date::setYear(int year) noexcept(false)
{
    if (year < MIN_YEAR || year > MAX_YEAR)
        throw WrongYearException(year, MIN_YEAR, MAX_YEAR);

    this->year = year;
}


/********* Show *********/

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.day << "/" << d.month << "/" << d.year;

    return os;
}