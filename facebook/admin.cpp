#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"

const int NOT_FOUND = -1;

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

}
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
*/


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

void Admin::addNewStatusToMember(const char* name, const char* newStatus)
{
	int index;

	index = allMembers.findMemberByName(name);
	allMembers.getMemberByIndex(index).addStatusToBillboard(newStatus);
}

void Admin::addNewStatusToFansPage(const char* name, const char* newStatus)
{
	int index;

	index = allPages.findPage(name);
	allPages.getPageByIndex(index).addStatus(newStatus);
}

bool Admin::addFanToPage(const char* member,const char* page)
{
	int mIndex, pIndex;
	bool isValid;

	mIndex = allMembers.findMemberByName(member);
	pIndex = allPages.findPage(page);
	isValid = (mIndex != NOT_FOUND && pIndex != NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(mIndex).likePage(allPages.getPageByIndex(pIndex));

	return isValid;
}
bool Admin::removeFanFromPage(const char* member, const char* page)
{
	int mIndex, pIndex;
	bool isValid;

	mIndex = allMembers.findMemberByName(member);
	pIndex = allPages.findPage(page);
	isValid = (mIndex != NOT_FOUND && pIndex != NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(mIndex).dislikePage(allPages.getPageByIndex(pIndex));

	return isValid;
}

bool Admin::showAllMemberFriends(const char* name) const
{
	int index;
	bool isValid;

	index = allMembers.findMemberByName(name);
	isValid = (index != NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).showAllFriends();

	return isValid;
}

bool Admin::showAllFansPageFans(const char* name) const
{
	int index;
	bool isValid;

	index = allPages.findPage(name);
	isValid = (index != NOT_FOUND);
	
	if(isValid)
		allPages.getPageByIndex(index).showAllFans();

	return isValid;
}

bool Admin::showAllMemberStatuses(const char* name) const
{
	bool isValid;
	int index;
	
	index = allMembers.findMemberByName(name);
	isValid = (index != NOT_FOUND);
	if (isValid)
		allMembers.getMemberByIndex(index).showAllStatus();

	return isValid;
}

bool Admin::showAllFansPageStatuses(const char* name) const
{
	bool isValid;
	int index;
	
	index = allPages.findPage(name);
	isValid = (index != NOT_FOUND);
	if (isValid)
		allPages.getPageByIndex(index).showAllStatus();

	return isValid;
}

bool Admin::showUpdatedFriendsStatuses(const char* name) const
{
	bool isValid;
	int index = allMembers.findMemberByName(name);

	isValid = (index != NOT_FOUND);
	if(isValid)
		allMembers.getMemberByIndex(index).showUpdatedFriendsStatuses();

	return isValid;
}