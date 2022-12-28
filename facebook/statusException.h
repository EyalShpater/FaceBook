#ifndef __STATUS_EXCEPTION_H
#define __STATUS_EXCEPTION_H

#include <exception>
#include <iostream>

class StatusException : public std::exception
{
public:
	void show() const { std::cout << "General Error creating a Status\n"; }
};

class EmptyTextException : public StatusException
{
public:
	void show() const { std::cout << "status can not be empty!\n"; }
};

#endif

