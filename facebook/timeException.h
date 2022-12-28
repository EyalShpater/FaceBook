#ifndef __TIME_EXCEPTION_H
#define __TIME_EXCEPTION_H

#include <exception>
#include <iostream>

class TimeException : public std::exception
{
public:
	void show() const { std::cout << "General Error creating a date\n"; }
};

class WrongHourException : public TimeException
{
	int hour;
public:
	WrongHourException(int hour) : hour(hour) {}
	void show() const { std::cout << hour << " is invalid hour value!\n"; }
};

class WrongMinuteException : public TimeException
{
	int min;
public:
	WrongMinuteException(int min) : min(min) {}
	void show() const { std::cout << min << " is invalid minute value!\n"; }
};

class WrongSecondException : public TimeException
{
	int sec;
public:
	WrongSecondException(int sec) :sec(sec) {}
	void show() const { std::cout << sec << " is invalid second value!\n"; }
};

class WrongDayException : public TimeException
{
	int day;
public:
	WrongDayException(int day) :day(day) {}
	void show() const { std::cout << day << " is invalid day value!\n"; }
};

class WrongMonthException : public TimeException
{
	int month;
public:
	WrongMonthException(int month) :month(month) {}
	void show() const { std::cout << month << "invalid month value!\n"; }
};

class WrongYearException : public TimeException
{
	int year;
public:
	WrongYearException(int year) :year(year) {}
	void show() const { std::cout << year << "invalid year value!\n"; }
};

#endif // __TIME_EXCEPTION_H



