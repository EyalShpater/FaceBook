#ifndef __USER_EXCEPTION_H
#define __USER_EXCEPTION_H

#include <exception>

class UserException : public std::exception
{
public:
	const char* what() { return "User general error\n"; }
};

class EmptyNameException : public UserException
{
public:
	const char* what() { return "User can not be empty\n"; }
};

class NotExistException : public UserException
{
public:
	const char* what() { return "User not exist\n"; }
};
#endif //USER_EXCEPTION
