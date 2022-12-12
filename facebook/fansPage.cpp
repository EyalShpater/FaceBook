#pragma warning (disable:4996)

#include "fansPage.h"
#include "member.h"

#include <iostream>
using namespace std;

/********* Constructors *********/

FansPage::FansPage(const char* name)
{
	this->name = strdup(name);
}

FansPage::~FansPage() 
{
	delete[]name;
}

/********* Fans-Page's functions *********/

void FansPage::addStatus(const char* newStatus)
{
	theBillboard.push(newStatus);
}

const FansPage& FansPage::operator+=(Member& newFriend)
{
	if (members.findMemberByName(newFriend.getName()) == MemberArray::NOT_FOUND)
	{
		members.push(newFriend);
		newFriend.likePage(*this);
	}

	return *this;
}

void FansPage::deleteFriend(Member& other)
{
	if (members.findMemberByName(other.getName()) != MemberArray::NOT_FOUND)
	{
		members.pop(other);
		other.dislikePage(*this);
	}
}

/********* Show functions *********/

void FansPage::showAllStatus() const
{
	theBillboard.showAllStatus();
}

void FansPage::showAllFans() const
{
	cout << "**********" << name << "'s Fans **********" << endl << endl;
	members.showAllMembers();
	cout << "********************" << endl;
}

void FansPage::show() const
{
	cout << "The fans page name: " << name;
}