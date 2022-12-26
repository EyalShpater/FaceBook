#ifndef __TIME_EXCEPTION_H
#define __TIME_EXCEPTION_H

#include <exception>

class TimeException : public std::exception
{
public:
	const char* what() const { return "General Error creating a date\n"; }
};

class WrongHourException : public TimeException
{
public:
	const char* what() const { return "invalid hour value!\n"; }
};

class WrongMinuteException : public TimeException
{
public:
	const char* what() const { return "invalid minute value!\n"; }
};

class WrongSecondException : public TimeException
{
public:
	const char* what() const { return "invalid second value!\n"; }
};

class WrongDayException : public TimeException
{
public:
	const char* what() const { return "invalid day value!\n"; }
};

class WrongMonthException : public TimeException
{
public:
	const char* what() const { return "invalid month value!\n"; }
};

class WrongYearException : public TimeException
{
public:
	const char* what() const { return "invalid year value!\n"; }
};

#endif // __TIME_EXCEPTION_H



