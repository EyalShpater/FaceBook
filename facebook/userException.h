#ifndef __USER_EXCEPTION_H
#define __USER_EXCEPTION_H

#include <exception>
#include <iostream>


class UserException : public std::exception
{
public:
	void show() { std::cout << "User general error\n"; }
};

class EmptyNameException : public UserException
{
public:
	void show() { std::cout << "User name can not be empty\n"; }
};

class NotExistException : public UserException
{
public:
	void show() { std::cout << "User not exist\n"; }
};

class ExistException : public UserException
{
public:
	void show() { std::cout << "User is already exist!\n"; }
};

#endif //USER_EXCEPTION