#pragma warning (disable:4996)

#include "member.h"

#include <iostream>
using namespace std;

Member::Member(const char* name, const Date& birthDate) : dateOfBirth(birthDate)
{
	this->name = strdup(name);
}

Member::~Member()
{
	delete[]name;
}

void Member::addStatusToBillboard(const Status& newStatus)
{

}

void Member::addFriend(const Member& newFriend)
{

}

void Member::cancelFriendship(const char* name)
{

}

void Member::likePage(const char* name)
{

}

void Member::showAllStatus() const
{

}

void Member::showLatest10thStatus() const
{

}

void Member::showAllFriend() const
{

}