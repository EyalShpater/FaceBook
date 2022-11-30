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

void Member::addFriend(Member& newFriend) // bool?
{
	if (&newFriend != this)
	{
		if (members.findMemberByName(newFriend.getName()) == NOT_FOUND)
			members.push(newFriend);

		if (newFriend.members.findMemberByName(name) == NOT_FOUND)
			newFriend.members.push(*this);
	}
	
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
	if (fansPages.findPageByName(newPage.getName()) == NOT_FOUND)
	{
		fansPages.push(newPage);
		newPage.addFriend(*this);
	}
}

void Member::dislikePage(FansPage& other)
{
	if (fansPages.findPageByName(other.getName()) != NOT_FOUND)
	{
		fansPages.push(other);
		other.deleteFriend(*this);
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

void Member::showUpdatedFriendsStatuses() const
{
	for (int i = 0; i < members.getLogSize(); i++)
		members.getMemberByIndex(i).showLatest10thStatus();
}

void Member::showAllFriends() const
{
	cout << "**********" << name << " Friends: **********" << endl;
	members.showAllMembers();
}