#ifndef __STATUS_EXCEPTION_H
#define __STATUS_EXCEPTION_H

#include <exception>

class StatusException : public std::exception
{
	const char* what() { return "General Error creating a Status\n"; }
};

class EmptyTextException : public StatusException
{
	const char* what() { return "status can not be empty!\n"; }
};

#endif

