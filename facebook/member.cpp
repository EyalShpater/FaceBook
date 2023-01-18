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

Member::Member(const string& name, const Date& birthDate) noexcept(false) : User(name), dateOfBirth(birthDate)
{
	if (name == "")
		throw EmptyNameException();

	this->name = name;
}

/********* File Functions *********/

void Member::save(ofstream& outFile) const
{
	User::save(outFile);
	dateOfBirth.save(outFile);
}

void Member::saveName(std::ofstream& outFile) const
{
	User::save(outFile);
}

void Member::saveAllFansPages(ofstream& outFile) const
{
	auto itr = fansPages.begin();
	auto itrEnd = fansPages.end();
	int size = fansPages.size();

	outFile.write((const char*)&size, sizeof(size));

	for (; itr != itrEnd; ++itr)
		(*itr)->save(outFile);
}

/********* Operators *********/

const Member& Member::operator+=(Member& newFriend)
{
	if (&newFriend != this)
	{
		if (findUserByName(newFriend.getName(), (vector<User*>&)connectedMembers) == nullptr)
		{
			myMembersRealloc();
			connectedMembers.push_back(&newFriend);
		}

		if (findUserByName(name, (vector<User*>&)newFriend.connectedMembers) == nullptr)
		{
			newFriend.myMembersRealloc();
			newFriend.connectedMembers.push_back(this);
		}
	}

	return *this;
}

bool Member::operator>(const Member& other)const
{
	return (connectedMembers.size() > other.connectedMembers.size());
}

bool Member::operator>(const FansPage& other) const
{
	return connectedMembers.size() > other.getNumOfConnectedMembers();
}

/********* Member's functions *********/

void Member::cancelFriendship(Member& other) noexcept(false)
{
	try
	{
		vector<Member*>::iterator itrMy = findUserIteratorByName(other.getName(), connectedMembers);
		vector<Member*>::iterator itrOther = findUserIteratorByName(name, other.connectedMembers);

		if ((*itrMy)->getName() == other.getName())
			connectedMembers.erase(itrMy);
		  
		if ((*itrOther)->getName() == name)
			other.connectedMembers.erase(itrOther);
	}
	catch (NotExistException&)
	{
		return;
	}
}

void Member::likePage(FansPage& newPage)
{
	if (findUserByName(newPage.getName(), fansPages) == nullptr)
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
		auto itr = findUserIteratorByName(other.getName(), fansPages);

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

void Member::showLatest10thStatus() const
{
	if (!theBillboard.empty())
	{
		vector<Status*>::const_iterator itr = theBillboard.begin();
		vector<Status*>::const_iterator itrEnd = --theBillboard.end();

		for (int i = 1; i <= DEFAULT_NUM_OF_STATUS_TO_SHOW && itrEnd != itr; i++, --itrEnd)
			cout << *(*itrEnd) << endl << endl;
		cout << *(*itrEnd) << endl << endl;
	}
}

void Member::showUpdatedFriendsStatuses() const
{
	vector<Member*>::const_iterator itr = connectedMembers.begin();
	vector<Member*>::const_iterator itrEnd = connectedMembers.end();

	for (;itr!=itrEnd; ++itr)
	{
		cout << "..................................." << endl;
		cout <<(*itr)->name << "'s statuses:" << endl;
		cout << "..................................." << endl << endl;
		(*itr)->showLatest10thStatus();
	}
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
void Member::toOs(std::ostream& os) const
{
	os << endl << "Member's birthday: " << dateOfBirth;
}

void Member::myFansPageRealloc()
{
	int logSize = fansPages.size();
	int physSize = fansPages.capacity();

	if (logSize == physSize)
		fansPages.reserve(physSize * 2);
}