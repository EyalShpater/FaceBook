#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"
#include "userException.h"

#include <iostream>
using namespace std;

/********* Destructor **********/

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
		throw ExistException(name);

	myMemberRealloc();
	allMembers.push_back(new Member(name, date));
}

void Admin::addFansPage(const string& name) noexcept(false)
{
	bool isValid = findFansPageByName(name, allPages) == nullptr;
	
	if (!isValid)
		throw ExistException(name);

	myFansPageRealloc();
	allPages.push_back(new FansPage(name));
}

void Admin::addNewStatusToMember(const string& name, const string& newStatus, int type, const string& filePath) noexcept(false)
{
	Member* curr = findMemberByName(name, allMembers);

	if (curr == nullptr)
		throw NotExistException(name);

	curr->addStatusToBillboard(newStatus, type, filePath);
}

void Admin::addNewStatusToFansPage(const string& name, const string& newStatus, int type, const string& filePath) noexcept(false)
{
	FansPage* curr = findFansPageByName(name, allPages);

	if (curr == nullptr)
		throw NotExistException(name);

	curr->addStatus(newStatus, type, filePath); 
}

void Admin::makeFriendship(const string& nameFirst, const string& nameSecond) noexcept(false)
{
	Member* member1 = findMemberByName(nameFirst, allMembers);
	Member* member2 = findMemberByName(nameSecond, allMembers);

	if (member1 == nullptr) 
		throw NotExistException(nameFirst);

	if (member2 == nullptr)
		throw NotExistException(nameSecond);

	*member1 += *member2;
}

void Admin::addFanToPage(const string& member, const string& page) noexcept(false)
{
	Member* mCurr = findMemberByName(member, allMembers);
	FansPage* pCurr = findFansPageByName(page, allPages);

	if(mCurr == nullptr)
		throw NotExistException(member);
	if(pCurr == nullptr)
		throw NotExistException(page);
	
	*pCurr += *mCurr;
}

/********* Disconnect functions *********/

void Admin::removeFanFromPage(const string& member, const string& page) noexcept(false)
{
	Member* mCurr = findMemberByName(member, allMembers);
	FansPage* pCurr = findFansPageByName(page, allPages);

	if (mCurr == nullptr) 
		throw NotExistException(member);

	if (pCurr == nullptr)
		throw NotExistException(page);

	mCurr->dislikePage(*pCurr);
}

void Admin::cancelFriendship(const string& nameFirst, const string& nameSecond) noexcept(false)
{
	Member* member1 = findMemberByName(nameFirst, allMembers);
	Member* member2 = findMemberByName(nameSecond, allMembers);

	if (member1 == nullptr) 
		throw NotExistException(nameFirst);

	if (member2 == nullptr)
		throw NotExistException(nameSecond);

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

void Admin::showAllMemberFriends(const string& name) const noexcept(false)
{
	const Member* member = findMemberByName(name, allMembers);

	if (member == nullptr)
		throw NotExistException(name);

	member->showAllFriends();
}

void Admin::showAllFansPageFans(const string& name) const noexcept(false)
{
	const FansPage* fansPage = findFansPageByName(name, allPages);

	if (fansPage == nullptr)
		throw NotExistException(name);

	fansPage->showAllFans();
}

void Admin::showAllMemberStatuses(const string& name) const noexcept(false)
{
	const Member* member = findMemberByName(name, allMembers);

	if (member == nullptr)
		throw NotExistException(name);

	member->showAllStatus();
}

void Admin::showAllFansPageStatuses(const string& name) const
{
	const FansPage* fansPage = findFansPageByName(name, allPages);

	if (fansPage == nullptr)
		throw NotExistException(name);

	fansPage->showAllStatus();
}

void Admin::showUpdatedFriendsStatuses(const string& name) const noexcept(false)
{
	const Member* member = findMemberByName(name, allMembers);

	if (member == nullptr)
		throw NotExistException(name);

	member->showUpdatedFriendsStatuses();
}

/********* Utilities functions *********/

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