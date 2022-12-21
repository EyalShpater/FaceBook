#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"

#include <iostream>
using namespace std;

/********* Add and Connect functions *********/

bool Admin::addFriend(const string& name, const Date& date)
{
	bool isValid = findMemberByName(name, allMembers) == nullptr;

	if (isValid)
		allMembers.push_back(Member(name, date));

	return isValid;
}

bool Admin::addFansPage(const string& name)
{
	bool isValid = findFansPageByName(name, allPages) == nullptr;

	if (isValid)
		allPages.push_back(FansPage(name));

	return isValid;
}

bool Admin::addNewStatusToMember(const string& name, const string& newStatus)
{
	int index;
	bool isValid;

	index = allMembers.findMemberByName(name);
	isValid = (index != MemberArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).addStatusToBillboard(newStatus);

	return isValid;
}

bool Admin::addNewStatusToFansPage(const string& name, const string& newStatus)
{
	int index;
	bool isValid;

	index = allPages.findPageByName(name);
	isValid = (index != FansPageArray::NOT_FOUND);

	if (isValid)
		allPages.getPageByIndex(index).addStatus(newStatus);

	return isValid;
}

bool Admin::makeFriendship(const string& nameFirst, const string& nameSecond)
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

bool Admin::addFanToPage(const string& member, const string& page)
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

bool Admin::removeFanFromPage(const string& member, const string& page)
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

bool Admin::cancelFriendship(const string& nameFirst, const string& nameSecond)
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

bool Admin::showAllMemberFriends(const string& name) const
{
	int index;
	bool isValid;

	index = allMembers.findMemberByName(name);
	isValid = (index != MemberArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).showAllFriends();

	return isValid;
}

bool Admin::showAllFansPageFans(const string& name) const
{
	int index;
	bool isValid;

	index = allPages.findPageByName(name);
	isValid = (index != FansPageArray::NOT_FOUND);
	
	if(isValid)
		allPages.getPageByIndex(index).showAllFans();

	return isValid;
}

bool Admin::showAllMemberStatuses(const string& name) const
{
	bool isValid;
	int index;
	
	index = allMembers.findMemberByName(name);
	isValid = (index != MemberArray::NOT_FOUND);

	if (isValid)
		allMembers.getMemberByIndex(index).showAllStatus();

	return isValid;
}

bool Admin::showAllFansPageStatuses(const string& name) const
{
	bool isValid;
	int index;
	
	index = allPages.findPageByName(name);
	isValid = (index != FansPageArray::NOT_FOUND);
	if (isValid)
		allPages.getPageByIndex(index).showAllStatus();

	return isValid;
}

bool Admin::showUpdatedFriendsStatuses(const string& name) const
{
	bool isValid;
	int index = allMembers.findMemberByName(name);

	isValid = (index != MemberArray::NOT_FOUND);
	if(isValid)
		allMembers.getMemberByIndex(index).showUpdatedFriendsStatuses();

	return isValid;
}