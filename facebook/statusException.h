#ifndef __STATUS_EXCEPTION_H
#define __STATUS_EXCEPTION_H

#include <exception>
#include <iostream>

class StatusException : public std::exception
{
public:
	virtual void show() const { std::cout << "General Error creating a Status\n"; }
};

class EmptyTextException : public StatusException
{
public:
	virtual void show() const override { std::cout << "status can not be empty!\n"; }
};

#endif

