#pragma warning (disable:4996)

#include "fansPage.h"
#include "member.h"

#include <iostream>
using namespace std;

const int NOT_FOUND = -1;

FansPage::FansPage(const char* name)
{
	this->name = strdup(name);
}

FansPage::~FansPage() 
{
	delete[]name;
}

void FansPage::addStatus(const char* newStatus)
{
	theBillboard.push(newStatus);
}

void FansPage::addFriend(Member& newFriend)
{
	if (members.findMemberByName(newFriend.getName()) == /*MemberArray::*/NOT_FOUND)
	{
		members.push(newFriend);
		newFriend.likePage(*this);
	}
}

void FansPage::deleteFriend(Member& other)
{
	if (members.findMemberByName(other.getName()) != /*MemberArray::*/NOT_FOUND)
	{
		members.pop(other);
		other.dislikePage(*this);
	}
}

void FansPage::showAllStatus() const
{
	theBillboard.showAllStatus();
}

void FansPage::showAllFans() const
{
	members.showAllMembers();
}

void FansPage::show() const
{
	cout << "The fans page name: " << name;
}