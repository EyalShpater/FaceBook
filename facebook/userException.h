#ifndef __USER_EXCEPTION_H
#define __USER_EXCEPTION_H

#include <exception>
#include <iostream>
#include <string>

class UserException : public std::exception
{
public:
	virtual void show() const { std::cout << "User general error\n"; }
};

class EmptyNameException : public UserException
{
public:
	virtual void show() const override { std::cout << "User name can not be empty!\n"; }
};

class NotExistException : public UserException
{
	std::string name;
public:
	NotExistException(const std::string& name): name(name) {}
	virtual void show() const override { std::cout << name << " is not exist!\n"; }
};

class ExistException : public UserException
{
	std::string name;
public:
	ExistException(const std::string& name) : name(name) {}
	virtual void show() const override { std::cout << name << " is already exist!\n"; }
};

#endif //USER_EXCEPTION