#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"

/********* Destructor *********/

Admin::~Admin()
{
	for (int i = 0; i < allMembers.getLogSize(); i++)
		delete &(allMembers.getMemberByIndex(i));

	for (int i = 0; i < allPages.getLogSize(); i++)
		delete &(allPages.getPageByIndex(i));
}

/********* Add and Connect functions *********/

bool Admin::addFriend(const char* name, const Date& date)
{
	bool isValid = allMembers.findMemberByName(name) == MemberArray::NOT_FOUND;

	if (isValid)
	{
		Member* newMember = new Member(name, date);
		allMembers.push(*newMember);
	}

	return isValid;
}

bool Admin::addFansPage(const char* name)
{
	bool isValid = (allPages.findPageByName(name) == FansPageArray::NOT_FOUND);

	if (isValid)
	{
		FansPage* newFansPage = new FansPage(name);
		allPages.push(*newFansPage);
	}

	return isValid;
}

bool Admin::addNewStatusToMember(const char* name, const char* newStatus)
{
	int index;
	bool isValid;

	index = allMembers.findMemberByName(name);
	isValid = (index != MemberArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).addStatusToBillboard(newStatus);

	return isValid;
}

bool Admin::addNewStatusToFansPage(const char* name, const char* newStatus)
{
	int index;
	bool isValid;

	index = allPages.findPageByName(name);
	isValid = (index != FansPageArray::NOT_FOUND);

	if (isValid)
		allPages.getPageByIndex(index).addStatus(newStatus);

	return isValid;
}

bool Admin::makeFriendship(const char* nameFirst, const char* nameSecond)
{
	bool isValid;

	int index1 = allMembers.findMemberByName(nameFirst);
	int index2 = allMembers.findMemberByName(nameSecond);

	isValid = (index1 != MemberArray::NOT_FOUND && index2 != MemberArray::NOT_FOUND);
	if (isValid)
	{
		Member& firstMember = allMembers.getMemberByIndex(index1);
		Member& secondMember = allMembers.getMemberByIndex(index2);
		/*isValid = */firstMember += secondMember;
	}

	return isValid;
}

bool Admin::addFanToPage(const char* member, const char* page)
{
	int mIndex, pIndex;
	bool isValid;

	mIndex = allMembers.findMemberByName(member);
	pIndex = allPages.findPageByName(page);
	isValid = (mIndex != MemberArray::NOT_FOUND && pIndex != FansPageArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(mIndex).likePage(allPages.getPageByIndex(pIndex));

	return isValid;
}

/********* Disconnect functions *********/

bool Admin::removeFanFromPage(const char* member, const char* page)
{
	int mIndex, pIndex;
	bool isValid;

	mIndex = allMembers.findMemberByName(member);
	pIndex = allPages.findPageByName(page);
	isValid = (mIndex != MemberArray::NOT_FOUND && pIndex != FansPageArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(mIndex).dislikePage(allPages.getPageByIndex(pIndex));

	return isValid;
}

bool Admin::cancelFriendship(const char* nameFirst, const char* nameSecond)
{
	bool isValid;

	int index1 = allMembers.findMemberByName(nameFirst);
	int index2 = allMembers.findMemberByName(nameSecond);

	isValid = (index1 != MemberArray::NOT_FOUND && index2 != MemberArray::NOT_FOUND);
	if (isValid)
	{
		Member& firstMember = allMembers.getMemberByIndex(index1);
		Member& secondMember = allMembers.getMemberByIndex(index2);
		firstMember.cancelFriendship(secondMember);
	}

	return isValid;
}

/********* Show functions *********/

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

bool Admin::showAllMemberFriends(const char* name) const
{
	int index;
	bool isValid;

	index = allMembers.findMemberByName(name);
	isValid = (index != MemberArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).showAllFriends();

	return isValid;
}

bool Admin::showAllFansPageFans(const char* name) const
{
	int index;
	bool isValid;

	index = allPages.findPageByName(name);
	isValid = (index != FansPageArray::NOT_FOUND);
	
	if(isValid)
		allPages.getPageByIndex(index).showAllFans();

	return isValid;
}

bool Admin::showAllMemberStatuses(const char* name) const
{
	bool isValid;
	int index;
	
	index = allMembers.findMemberByName(name);
	isValid = (index != MemberArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).showAllStatus();

	return isValid;
}

bool Admin::showAllFansPageStatuses(const char* name) const
{
	bool isValid;
	int index;
	
	index = allPages.findPageByName(name);
	isValid = (index != FansPageArray::NOT_FOUND);
	if (isValid)
		allPages.getPageByIndex(index).showAllStatus();

	return isValid;
}

bool Admin::showUpdatedFriendsStatuses(const char* name) const
{
	bool isValid;
	int index = allMembers.findMemberByName(name);

	isValid = (index != MemberArray::NOT_FOUND);
	if(isValid)
		allMembers.getMemberByIndex(index).showUpdatedFriendsStatuses();

	return isValid;
}