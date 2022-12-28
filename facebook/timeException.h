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
	void show() const { std::cout << hour << " invalid hour value!\n"; }
};

class WrongMinuteException : public TimeException
{
	int min;
public:
	WrongMinuteException(int min) : min(min) {}
	void show() const { std::cout << min << "invalid minute value!\n"; }
};

class WrongSecondException : public TimeException
{
public:
	 void show() const { std::cout << "invalid second value!\n"; }
};

class WrongDayException : public TimeException
{
public:
	void show() const { std::cout << "invalid day value!\n"; }
};

class WrongMonthException : public TimeException
{
public:
	void show() const { std::cout << "invalid month value!\n"; }
};

class WrongYearException : public TimeException
{
public:
	void show() const { std::cout << "invalid year value!\n"; }
};

#endif // __TIME_EXCEPTION_H



