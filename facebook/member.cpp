#pragma warning (disable:4996)

#include "member.h"
#include "fansPage.h"
#include "status.h"

#include <iostream>
using namespace std;

const int NOT_FOUND = -1;
const int DEFAULT_NUM_OF_STATUS_TO_SHOW = 10;

Member::Member(const char* name, const Date& birthDate) : dateOfBirth(birthDate)
{
	this->name = strdup(name);
}

Member::~Member()
{
	delete[]name;
}

void Member::addStatusToBillboard(const char* text)
{
	theBillboard.push(text);
}

void Member::addFriend(Member& newFriend)
{
	if (members.findMemberByName(newFriend.getName()) == NOT_FOUND)
			members.push(newFriend);

	if (newFriend.members.findMemberByName(name) == NOT_FOUND)
			newFriend.members.push(*this);
	
}

void Member::cancelFriendship(Member& other)
{
	if (members.findMemberByName(other.getName()) != NOT_FOUND)
		members.pop(other);

	if (other.members.findMemberByName(name) != NOT_FOUND)
		other.members.pop(*this);
}

void Member::likePage(FansPage& newPage)
{
	if (fansPages.findPage(newPage.getName()) == NOT_FOUND)
	{
		fansPages.push(newPage);
		newPage.addFriend(*this);
	}
}

void Member::showAllStatus() const
{
	theBillboard.showAllStatus();
}

void Member::showLatest10thStatus() const
{
	theBillboard.showLatestNumOfStatus(DEFAULT_NUM_OF_STATUS_TO_SHOW);
}

void Member::showAllFriends() const
{
	members.showAllMembers();
}