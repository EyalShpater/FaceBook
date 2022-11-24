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

void Member::addStatusToBillboard(Status& newStatus)
{
	theBillboard.push(newStatus);
}

void Member::addFriend(Member& newFriend)
{
	members.push(newFriend);
}

void Member::cancelFriendship(const char* name)
{
	members.pop(name);
}

void Member::likePage(const char* name)
{
	fansPages.pop(name);
}

void Member::showAllStatus() const
{
	theBillboard.showAllStatus();
}

void Member::showLatest10thStatus() const
{
	theBillboard.showLatest10thStatus();
}

void Member::showAllFriend() const
{
	members.showAllMembers();
}