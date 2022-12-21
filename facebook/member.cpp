#pragma warning (disable:4996)

#include "member.h"
#include "fansPage.h"
#include "status.h"

#include <iostream>
using namespace std;

/********* Const variables declaration *********/

const int DEFAULT_NUM_OF_STATUS_TO_SHOW = 10;

/********* Constructors *********/

Member::Member(const string& name, const Date& birthDate) : dateOfBirth(birthDate)
{
	this->name = name;
}

/**********************/
const Member& Member::operator+=(Member& newFriend)
{
	if (&newFriend != this)
	{
		if (findMemberByName(newFriend.getName(), members) == nullptr)
			members.push_back(&newFriend);

		if (findMemberByName(name,newFriend.members) == nullptr)
			newFriend.members.push_back(this);
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

/***********/
vector<Member*>::iterator findMemberIteratorByName(const string& name, vector<Member*>& allMembers)
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

	return itr;
}

Member* findMemberByName(const string& name, vector<Member*>& allMembers)
{
	vector<Member*>::iterator res = findMemberIteratorByName(name, allMembers);

	if (res == allMembers.end() && (*res)->getName() != name) //not found
		return nullptr;

	return *res;
}


/********* Member's functions *********/

void Member::addStatusToBillboard(const string& text)
{
	theBillboard.push_back(Status(text));
}

void Member::cancelFriendship(Member& other)
{
	vector<Member*>::iterator itrMy = findMemberIteratorByName(other.getName(), members);
	vector<Member*>::iterator itrOther = findMemberIteratorByName(name, other.members);


	if ((*itrMy)->getName() == other.getName())
		members.erase(itrMy);

	if ((*itrOther)->getName() == name)
		other.members.erase(itrOther);
}

void Member::likePage(FansPage& newPage)
{
	if (findFansPageByName(newPage.getName(), fansPages) == nullptr)
	{
		fansPages.push_back(&newPage);
		newPage += *this;
	}
}

void Member::dislikePage(FansPage& other)
{
	if (findFansPageByName(other.getName(), fansPages) != nullptr)
	{
		fansPages.push_back(&other);
		other.deleteFriend(*this);
	}
}

/********* Show functions *********/

void Member::showAllStatus() const
{
	vector<Status>::const_iterator itr = theBillboard.begin();
	vector<Status>::const_iterator itrEnd = theBillboard.end();
	
	for (; itr != itrEnd; ++itr)
		cout << *itr;
}

void Member::showLatest10thStatus() const
{
	vector<Status>::const_iterator itr = theBillboard.begin();
	vector<Status>::const_iterator itrEnd = theBillboard.end();

	for (int i = 0; i < DEFAULT_NUM_OF_STATUS_TO_SHOW && itr != itrEnd; i++, --itrEnd)
		cout << *itrEnd;
	

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

	cout << "**********" << name << "'s Friends **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *itr << endl << endl;

	cout << "********************" << endl;
}

void Member::showAllFansPage() const
{
	vector<FansPage*>::const_iterator itr = fansPages.begin();
	vector<FansPage*>::const_iterator itrEnd = fansPages.end();

	cout << "**********" << name << "'s Fans-Pages **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *itr << endl << endl;
	cout << "********************" << endl;
}