#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"
#include "userException.h"

#include <iostream>
using namespace std;

/********* Distructor **********/

Admin::~Admin()
{
	vector<Member*>::iterator mItr = allMembers.begin();
	vector<Member*>::iterator mItrEnd = allMembers.end();
	vector<FansPage*>::iterator pItr = allPages.begin();
	vector<FansPage*>::iterator pItrEnd = allPages.end();

	for (; mItr != mItrEnd; ++mItr)
		delete *mItr;

	for (; pItr != pItrEnd; ++pItr)
		delete *pItr;
}

/********* Add and Connect functions *********/

void Admin::addFriend(const string& name, const Date& date) noexcept(false)
{
	bool isValid = findMemberByName(name, allMembers) == nullptr;
	
	if(!isValid)
		throw ExistException();

	myMemberRealloc();
	allMembers.push_back(new Member(name, date));
}

void Admin::addFansPage(const string& name) noexcept(false)
{
	bool isValid = findFansPageByName(name, allPages) == nullptr;
	
	if (!isValid)
		throw ExistException();

	myFansPageRealloc();
	allPages.push_back(new FansPage(name));
}

void Admin::addNewStatusToMember(const string& name, const string& newStatus) noexcept(false)
{
	Member* curr = findMemberByName(name, allMembers);

	if (curr == nullptr)
		throw NotExistException();

	curr->addStatusToBillboard(newStatus);

}

void Admin::addNewStatusToFansPage(const string& name, const string& newStatus) noexcept(false)
{
	FansPage* curr = findFansPageByName(name, allPages);

	if (curr == nullptr)
		throw NotExistException();

	curr->addStatus(newStatus);
}

void Admin::makeFriendship(const string& nameFirst, const string& nameSecond) noexcept(false)
{
	Member* member1 = findMemberByName(nameFirst, allMembers);
	Member* member2 = findMemberByName(nameSecond, allMembers);

	if (member1 == nullptr || member2 == nullptr)
		throw NotExistException();

	*member1 += *member2;
}

void Admin::addFanToPage(const string& member, const string& page) noexcept(false)
{
	Member* mCurr = findMemberByName(member, allMembers);
	FansPage* pCurr = findFansPageByName(page, allPages);

	if(mCurr == nullptr || pCurr == nullptr)
		throw NotExistException();
	
	*pCurr += *mCurr;
}

/********* Disconnect functions *********/

void Admin::removeFanFromPage(const string& member, const string& page) noexcept(false)
{
	Member* mCurr = findMemberByName(member, allMembers);
	FansPage* pCurr = findFansPageByName(page, allPages);

	if (mCurr == nullptr || pCurr == nullptr)
		throw NotExistException();

	mCurr->dislikePage(*pCurr);
}

void Admin::cancelFriendship(const string& nameFirst, const string& nameSecond) noexcept(false)
{
	Member* member1 = findMemberByName(nameFirst, allMembers);
	Member* member2 = findMemberByName(nameSecond, allMembers);

	if (member1 == nullptr || member2 == nullptr)
		throw NotExistException();

	member1->cancelFriendship(*member2);
}

/********* Show functions *********/

void Admin::showAllUsers() const
{
	showAllMembers();
	cout << endl;
	showAllFansPages();
}

void Admin::showAllMembers() const
{
	vector<Member*>::const_iterator itr = allMembers.begin();
	vector<Member*>::const_iterator itrEnd = allMembers.end();

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
}

void Admin::showAllFansPages() const
{
	vector<FansPage*>::const_iterator itr = allPages.begin();
	vector<FansPage*>::const_iterator itrEnd = allPages.end();

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
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

void Admin::myMemberRealloc()
{
	int logSize = allMembers.size();
	int physSize = allMembers.capacity();

	if (logSize == physSize)
		allMembers.reserve(physSize * 2);
}

void Admin::myFansPageRealloc()
{
	int logSize = allPages.size();
	int physSize = allPages.capacity();

	if (logSize == physSize)
		allPages.reserve(physSize * 2);
}