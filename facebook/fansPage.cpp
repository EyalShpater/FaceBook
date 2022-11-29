#pragma warning (disable:4996)

#include "fansPage.h"
#include "member.h"

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
	if (members.findMemberByName(newFriend.getName()) == NOT_FOUND)
		members.push(newFriend); // Assmption: FansPage can't add member to like it.
}

void FansPage::deleteFriend(Member& other)
{
	members.pop(other); // Assmption: FansPage can't remove member from like it.
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