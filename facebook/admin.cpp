#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"

Admin::~Admin()
{
	for (int i = 0; i < allMembers.getLogSize(); i++)
		delete &(allMembers.getMemberByIndex(i));

	for (int i = 0; i < allPages.getLogSize(); i++)
		delete &(allPages.getPageByIndex(i));
}

/*
void Admin::menu()
{

}*/
Member* Admin::getMemberByName(const char* name) 
{
	int index = allMembers.findMemberByName(name);
	return &(allMembers.getMemberByIndex(index));
}

FansPage* Admin::getPageByName(const char* name)
{
	int index = allPages.findPage(name);
	return &(allPages.getPageByIndex(index));
}



void Admin::addFriend(const char* name, const Date& date)
{
	Member* newMember = new Member(name, date);
	allMembers.push(*newMember);
}

void Admin::addFansPage(const char* name)
{
	FansPage* newFansPage = new FansPage(name);
	allPages.push(*newFansPage);
}

void Admin::showAllUsers() const
{
	allMembers.showAllMembers();
	allPages.showAllPages();
}

void Admin::showAllMembers() const
{
	allMembers.showAllMembers();
}

void Admin::showAllFansPages() const
{
	allPages.showAllPages();
}

void Admin::addNewStatus(Member& theMember, const char* newStatus)
{
	theMember.addStatusToBillboard(newStatus);
}

void Admin::addNewStatus(FansPage& theFansPage, const char* newStatus)
{
	theFansPage.addStatus(newStatus);
}

bool Admin::addFanToPage(Member* member,FansPage* page)
{
	bool isValid = (member != nullptr && page != nullptr);

	if (isValid)
		page->addFriend(*member);

	return isValid;
}
bool Admin::removeFanFromPage(Member* member, FansPage* page)
{
	bool isValid = (member != nullptr && page != nullptr);

	if (isValid)
		page->deleteFriend(*member);

	return isValid;
}

void Admin::showAllMemberFriends(Member* theMember) const
{
	theMember->showAllFriends();
}

void Admin::showAllFansPageFans(FansPage* theFansPage) const
{
	theFansPage->showAllFans();
}