#pragma warning (disable:4996)

#include "fansPage.h"
#include "member.h"

#include <iostream>
using namespace std;

/**********************************************/
FansPage::~FansPage()
{
	vector<Status*>::iterator itr = theBillboard.begin();
	vector<Status*>::iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		delete *itr;
}

/**********************************************/

bool FansPage::operator>(const FansPage& other)const
{
	return (members.size() > other.members.size());
}

bool FansPage::operator>(const Member& other) const
{
	return members.size() > other.getNumOfFriends();
}

const FansPage& FansPage::operator+=(Member& newFriend)
{
	if (findMemberByName(newFriend.getName(), members) == nullptr)
	{
		myMembersRealloc();
		members.push_back(&newFriend);
		newFriend.likePage(*this);
	}

	return *this;
}

/********* Fans-Page's functions *********/

void FansPage::addStatus(const string& newStatus) noexcept(false)
{
	if (newStatus == "")
		throw EmptyTextException();

	myStatusRealloc();
	theBillboard.push_back(new Status(newStatus));
}

void FansPage::deleteFriend(Member& other) noexcept(false)
{
	vector<Member*>::iterator itrMy = findMemberIteratorByName(other.getName(), members);

	members.erase(itrMy);
	other.dislikePage(*this);
}

/********* Show functions *********/

void FansPage::showAllStatus() const
{
	vector<Status*>::const_iterator itr = theBillboard.begin();
	vector<Status*>::const_iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
}

void FansPage::showAllFans() const
{
	vector<Member*>::const_iterator itr = members.begin();
	vector<Member*>::const_iterator itrEnd = members.end();

	cout << "**********" << name << "'s Fans **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;

	cout << "********************" << endl;
}
ostream& operator<<(ostream& os, const FansPage& f)
{
	os << "The fans page name: " << f.name;

	return os;
}

vector<FansPage*>::iterator findFansPageIteratorByName(const string& name, vector<FansPage*>& allFansPage) noexcept(false)
{
	bool isFound = false;
	vector<FansPage*>::iterator itr = allFansPage.begin();
	vector<FansPage*>::iterator itrEnd = allFansPage.end();

	while (itr != itrEnd && !isFound)
	{
		if ((*itr)->getName() == name)
			isFound = true;
		else
			++itr;
	}

	if (!isFound)
		throw NotExistException(name);

	return itr;
}

vector<FansPage*>::const_iterator findFansPageIteratorByName(const std::string& name, const std::vector<FansPage*>& allFansPage) noexcept(false)
{
	bool isFound = false;
	vector<FansPage*>::const_iterator itr = allFansPage.begin();
	vector<FansPage*>::const_iterator itrEnd = allFansPage.end();

	while (itr != itrEnd && !isFound)
	{
		if ((*itr)->getName() == name)
			isFound = true;
		else
			++itr;
	}

	if (!isFound)
		throw NotExistException(name);

	return itr;
}

FansPage* findFansPageByName(const string& name, vector<FansPage*>& allFansPage)
{
	try
	{
		vector<FansPage*>::iterator res = findFansPageIteratorByName(name, allFansPage);
		return *res;
	}
	catch (NotExistException&)
	{
		return nullptr;
	}

}

const FansPage* findFansPageByName(const std::string& name, const std::vector<FansPage*>& allFansPage)
{
	try
	{
		vector<FansPage*>::const_iterator res = findFansPageIteratorByName(name, allFansPage);
		return *res;
	}
	catch (NotExistException&)
	{
		return nullptr;
	}	
}

/**********************/

void FansPage::myMembersRealloc()
{
	int logSize = members.size();
	int physSize = members.capacity();

	if (logSize == physSize)
		members.reserve(physSize * 2);
}

void FansPage::myStatusRealloc()
{
	int logSize = theBillboard.size();
	int physSize = theBillboard.capacity();

	if (logSize == physSize)
		theBillboard.reserve(physSize * 2);
}