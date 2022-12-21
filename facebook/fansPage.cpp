#pragma warning (disable:4996)

#include "fansPage.h"
#include "member.h"

#include <iostream>
using namespace std;

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
		members.push_back(&newFriend);
		newFriend.likePage(*this);
	}

	return *this;
}

/********* Fans-Page's functions *********/

void FansPage::addStatus(const string& newStatus)
{
	theBillboard.push_back(newStatus);
}

void FansPage::deleteFriend(Member& other)
{
	vector<Member*>::iterator itrMy = findMemberIteratorByName(other.getName(), members);
	//vector<Member*>::iterator itrOther = findMemberIteratorByName(name, other.members);

	if ((*itrMy)->getName() == other.getName())
	{
		members.erase(itrMy);
		other.dislikePage(*this);
	}
}

/********* Show functions *********/

void FansPage::showAllStatus() const
{
	vector<Status>::const_iterator itr = theBillboard.begin();
	vector<Status>::const_iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		cout << *itr;
}

void FansPage::showAllFans() const
{
	vector<Member*>::const_iterator itr = members.begin();
	vector<Member*>::const_iterator itrEnd = members.end();

	cout << "**********" << name << "'s Fans **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *itr << endl << endl;

	cout << "********************" << endl;
	cout << "********************" << endl;
}
ostream& operator<<(ostream& os, const FansPage& f)
{
	os << "The fans page name: " << f.name;

	return os;
}

vector<FansPage*>::iterator findFansPageIteratorByName(const string& name, vector<FansPage*>& allFansPage)
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

	return itr;
}

FansPage* findFansPageByName(const string& name, vector<FansPage*>& allFansPage)
{
	vector<FansPage*>::iterator res = findFansPageIteratorByName(name, allFansPage);

	if (res == allFansPage.end() && (*res)->getName() != name) //not found
		return nullptr;

	return *res;
}