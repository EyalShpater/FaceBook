#pragma warning (disable:4996)

#include "fansPage.h"

FansPage::FansPage(const char* name)
{
	this->name = strdup(name);
}

FansPage::~FansPage()
{
	delete[]name;
}

void FansPage::addStatus(Status& newStatus)
{
	theBillboard.push(newStatus);
}

void FansPage::addFriend(Member& newFriend)
{
	members.push(newFriend);
}

void FansPage::deleteFriend(const char* name)
{
	members.pop(name);
}

void FansPage::showAllStatus() const
{
	theBillboard.showAllStatus();
}

void FansPage::showAllFriends() const
{
	members.showAllMembers();
}