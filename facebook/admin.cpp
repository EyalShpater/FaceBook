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
	Member* curr;
	bool isValid;

	curr = findMemberByName(name, allMembers);
	isValid = (curr != nullptr);

	if (isValid)
		curr->addStatusToBillboard(newStatus);

	return isValid;
}

bool Admin::addNewStatusToFansPage(const string& name, const string& newStatus)
{
	FansPage* curr;
	bool isValid;

	curr = findFansPageByName(name, allPages);
	isValid = (curr != nullptr);

	if (isValid)
		curr->addStatus(newStatus);

	return isValid;
}

bool Admin::makeFriendship(const string& nameFirst, const string& nameSecond)
{
	bool isValid;

	Member* member1 = findMemberByName(nameFirst, allMembers);
	Member* member2 = findMemberByName(nameSecond, allMembers);

	isValid = (member1 != nullptr && member2 != nullptr);
	if (isValid)
		*member1 += *member2;

	return isValid;
}

bool Admin::addFanToPage(const string& member, const string& page)
{
	
	Member* mCurr;
	FansPage* pCurr;
	bool isValid;

	mCurr = findMemberByName(member, allMembers);
	pCurr = findFansPageByName(page, allPages);
	isValid = (mCurr != nullptr && pCurr != nullptr);

	if (isValid)
		mCurr->likePage(*pCurr);

	return isValid;
}

/********* Disconnect functions *********/

bool Admin::removeFanFromPage(const string& member, const string& page)
{
	Member* mCurr;
	FansPage* pCurr;
	bool isValid;

	mCurr = findMemberByName(member, allMembers);
	pCurr = findFansPageByName(page, allPages);
	isValid = (mCurr != nullptr && pCurr != nullptr);

	if (isValid)
		mCurr->dislikePage(*pCurr);

	return isValid;
}

bool Admin::cancelFriendship(const string& nameFirst, const string& nameSecond)
{
	bool isValid;

	Member* member1 = findMemberByName(nameFirst, allMembers);
	Member* member2 = findMemberByName(nameSecond, allMembers);

	isValid = (member1 != nullptr && member2 != nullptr);
	if (isValid)
		member1->cancelFriendship(*member2);

	return isValid;
}

/********* Show functions *********/

void Admin::showAllUsers() const
{
	showAllMembers();
	showAllFansPages();
}

void Admin::showAllMembers() const
{
	list<Member>::const_iterator mItr = allMembers.begin();
	list<Member>::const_iterator mItrEnd = allMembers.end();

	for (; mItr != mItrEnd; ++mItr)
		cout << *mItr << endl;
}

void Admin::showAllFansPages() const
{
	list<FansPage>::const_iterator pItr = allPages.begin();
	list<FansPage>::const_iterator pItrEnd = allPages.end();

	for (; pItr != pItrEnd; ++pItr)
		cout << *pItr << endl;
}

bool Admin::showAllMemberFriends(const string& name) const
{
	bool isValid = false;
	const Member* member = findMemberByName(name, allMembers);

	if (member != nullptr)
	{
		member->showAllFriends();
		isValid = true;
	}
		
	return isValid;
}

bool Admin::showAllFansPageFans(const string& name) const
{
	bool isValid = false;
	const FansPage* fansPage = findFansPageByName(name, allPages);
	
	if (fansPage != nullptr)
	{
		fansPage->showAllFans();
		isValid = true;
	}
		
	return isValid;
}

bool Admin::showAllMemberStatuses(const string& name) const
{
	bool isValid = false;
	const Member* member = findMemberByName(name, allMembers);

	if (member != nullptr)
	{
		member->showAllStatus();
		isValid = true;
	}

	return isValid;
}

bool Admin::showAllFansPageStatuses(const string& name) const
{
	bool isValid = false;
	const FansPage* fansPage = findFansPageByName(name, allPages);

	if (fansPage != nullptr)
	{
		fansPage->showAllStatus();
		isValid = true;
	}

	return isValid;
}

bool Admin::showUpdatedFriendsStatuses(const string& name) const
{
	bool isValid = false;
	const Member* member = findMemberByName(name, allMembers);

	if (member != nullptr)
	{
		member->showUpdatedFriendsStatuses();
		isValid = true;
	}

	return isValid;
}