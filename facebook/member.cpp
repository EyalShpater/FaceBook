#pragma warning (disable:4996)

#include "member.h"
#include "fansPage.h"
#include "status.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include "userException.h"

#include <iostream>
using namespace std;


/********* Const variables declaration *********/

const int DEFAULT_NUM_OF_STATUS_TO_SHOW = 10;

/********* Constructors *********/

Member::Member(const string& name, const Date& birthDate) noexcept(false) : dateOfBirth(birthDate)
{
	if (name == "")
		throw EmptyNameException();

	this->name = name;
}

Member::~Member()
{
	vector<Status*>::iterator itr = theBillboard.begin();
	vector<Status*>::iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		delete* itr;
}

/********* Operators *********/
const Member& Member::operator+=(Member& newFriend)
{
	if (&newFriend != this)
	{
		if (findMemberByName(newFriend.getName(), members) == nullptr)
		{
			myMemberRealloc();
			members.push_back(&newFriend);
		}

		if (findMemberByName(name, newFriend.members) == nullptr)
		{
			newFriend.myMemberRealloc();
			newFriend.members.push_back(this);
		}
	}

	return *this;
}

bool Member::operator>(const Member& other)const
{
	return (members.size() > other.members.size());
}

bool Member::operator>(const FansPage& other) const
{
	return members.size() > other.getNumOfFans();
}

ostream& operator<<(ostream& os, const Member& s)
{
	os << "Member's name: " << s.name << endl;
	os << "Member's birthday: " << s.dateOfBirth;

	return os;
}

/********* Find functions *********/
vector<Member*>::iterator findMemberIteratorByName(const string& name, vector<Member*>& allMembers) noexcept(false)
{
	bool isFound = false;
	vector<Member*>::iterator itr = allMembers.begin();
	vector<Member*>::iterator itrEnd = allMembers.end();

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

vector<Member*>::const_iterator findMemberIteratorByName(const string& name, const vector<Member*>& allMembers) noexcept(false)
{
	bool isFound = false;
	vector<Member*>::const_iterator itr = allMembers.begin();
	vector<Member*>::const_iterator itrEnd = allMembers.end();

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

Member* findMemberByName(const string& name, vector<Member*>& allMembers)
{
	try
	{
		vector<Member*>::iterator res = findMemberIteratorByName(name, allMembers);
		return *res;
	}
	catch (NotExistException&)
	{
		return nullptr;
	}
}

const Member* findMemberByName(const std::string& name, const std::vector<Member*>& allMembers) 
{
	try
	{
		vector<Member*>::const_iterator res = findMemberIteratorByName(name, allMembers);

		return *res;
	}
	catch (NotExistException&)
	{
		return nullptr;
	}
}

/********* Member's functions *********/

void Member::addStatusToBillboard(const string& newStatus, int type, const string& filePath) noexcept(false)
{
	myStatusRealloc();

	switch (type)
	{
	case (int)Status::eStatusType::TEXT:
		theBillboard.push_back(new Status(newStatus));
		break;
	case (int)Status::eStatusType::IMAGE:
		theBillboard.push_back(new ImageStatus(newStatus, filePath));
		break;
	case (int)Status::eStatusType::VIDEO:
		theBillboard.push_back(new VideoStatus(newStatus, filePath));
		break;
	default:
		throw StatusException();
	}
}

void Member::cancelFriendship(Member& other) noexcept(false)
{
	try
	{
		vector<Member*>::iterator itrMy = findMemberIteratorByName(other.getName(), members);
		vector<Member*>::iterator itrOther = findMemberIteratorByName(name, other.members);

		if ((*itrMy)->getName() == other.getName())
			members.erase(itrMy);

		if ((*itrOther)->getName() == name)
			other.members.erase(itrOther);
	}
	catch (NotExistException&)
	{
		return;
	}
}

void Member::likePage(FansPage& newPage)
{
	if (findFansPageByName(newPage.getName(), fansPages) == nullptr)
	{
		myFansPageRealloc();
		fansPages.push_back(&newPage);
		newPage += *this;
	}
}

void Member::dislikePage(FansPage& other) noexcept(false)
{
	try
	{
		vector<FansPage*>::iterator itr = findFansPageIteratorByName(other.getName(), fansPages);

		if (itr != fansPages.end())
		{
			fansPages.erase(itr);
			other.deleteFriend(*this);
		}
	}
	catch (NotExistException&)
	{
		return;
	}
}

/********* Show functions *********/

void Member::showAllStatus() const
{
	vector<Status*>::const_iterator itr = theBillboard.begin();
	vector<Status*>::const_iterator itrEnd = theBillboard.end();
	
	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
}

void Member::showLatest10thStatus() const
{
	vector<Status*>::const_iterator itr = theBillboard.begin();
	vector<Status*>::const_iterator itrEnd = --theBillboard.end();

	for (int i = 1; i <= DEFAULT_NUM_OF_STATUS_TO_SHOW && itrEnd != itr; i++, --itrEnd)
		cout << *(*itrEnd) << endl << endl;
	cout << *(*itrEnd) << endl << endl;
}

void Member::showUpdatedFriendsStatuses() const
{
	vector<Member*>::const_iterator itr = members.begin();
	vector<Member*>::const_iterator itrEnd = members.end();

	for (;itr!=itrEnd; ++itr)
	{
		cout << "..................................." << endl;
		cout <<(*itr)->name << "'s statuses:" << endl;
		cout << "..................................." << endl << endl;
		(*itr)->showLatest10thStatus();
	}
}

void Member::showAllFriends() const
{
	vector<Member*>::const_iterator itr = members.begin();
	vector<Member*>::const_iterator itrEnd = members.end();

	cout << "********** " << name << "'s Friends **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;

	cout << "********************" << endl;
}

void Member::showAllFansPage() const
{
	vector<FansPage*>::const_iterator itr = fansPages.begin();
	vector<FansPage*>::const_iterator itrEnd = fansPages.end();

	cout << "**********" << name << "'s Fans-Pages **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
	cout << "********************" << endl;
}

/********* Utilites functions *********/
void Member::myMemberRealloc()
{
	int logSize = members.size();
	int physSize = members.capacity();

	if (logSize == physSize)
		members.reserve(physSize * 2);
}

void Member::myFansPageRealloc()
{
	int logSize = fansPages.size();
	int physSize = fansPages.capacity();

	if (logSize == physSize)
		fansPages.reserve(physSize * 2);
}

void Member::myStatusRealloc()
{
	int logSize = theBillboard.size();
	int physSize = theBillboard.capacity();

	if (logSize == physSize)
		theBillboard.reserve(physSize * 2);
}