#pragma warning (disable:4996)

#include "member.h"
#include "fansPage.h"
#include "status.h"

#include <iostream>
using namespace std;

/********* Const variables declaration *********/

const int DEFAULT_NUM_OF_STATUS_TO_SHOW = 10;

/********* Constructors *********/

Member::Member(const char* name, const Date& birthDate) : dateOfBirth(birthDate)
{
	this->name = strdup(name);
}

Member::~Member()
{
	delete[]name;
}

/**********************/
const Member& Member::operator+=(Member& newFriend)
{
	if (&newFriend != this)
	{
		if (members.findMemberByName(newFriend.getName()) == MemberArray::NOT_FOUND)
			members.push(newFriend);

		if (newFriend.members.findMemberByName(name) == MemberArray::NOT_FOUND)
			newFriend.members.push(*this);
	}

	return *this;
}

bool Member::operator>(const Member& other)const
{
	return (members.getLogSize() > other.members.getLogSize());
}

/********* Member's functions *********/

void Member::addStatusToBillboard(const char* text)
{
	theBillboard.push(text);
}

void Member::cancelFriendship(Member& other)
{
	if (members.findMemberByName(other.getName()) != MemberArray::NOT_FOUND)
		members.pop(other);

	if (other.members.findMemberByName(name) != MemberArray::NOT_FOUND)
		other.members.pop(*this);
}

void Member::likePage(FansPage& newPage)
{
	if (fansPages.findPageByName(newPage.getName()) == FansPageArray::NOT_FOUND)
	{
		fansPages.push(newPage);
		newPage += *this;
	}
}

void Member::dislikePage(FansPage& other)
{
	if (fansPages.findPageByName(other.getName()) != FansPageArray::NOT_FOUND)
	{
		fansPages.push(other);
		other.deleteFriend(*this);
	}
}

/********* Show functions *********/

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
	{
		cout << "..................................." << endl;
		cout << members.getMemberByIndex(i).getName() << "'s statuses:" << endl;
		cout << "..................................." << endl << endl;
		members.getMemberByIndex(i).showLatest10thStatus();
	}
}

void Member::showAllFriends() const
{
	cout << "**********" << name << "'s Friends **********" << endl << endl;
	members.showAllMembers();
	cout << "********************" << endl;
}

void Member::showAllFansPage() const
{
	cout << "**********" << name << "'s Fans-Pages **********" << endl << endl;
	fansPages.showAllPages();
	cout << "********************" << endl;
}