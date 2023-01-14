#pragma warning (disable:4996)

#include "fansPage.h"
#include "member.h"
#include "status.h"
#include "imageStatus.h"
#include "videoStatus.h"

#include <iostream>
using namespace std;

/********* Operators *********/

bool FansPage::operator>(const FansPage& other)const
{
	return (connectedMembers.size() > other.connectedMembers.size());
}

bool FansPage::operator>(const Member& other) const
{
	return connectedMembers.size() > other.getNumOfConnectedMembers();
}

const FansPage& FansPage::operator+=(Member& newFriend)
{
	if (findUserByName(newFriend.getName(), connectedMembers) == nullptr)
	{
		myMembersRealloc();
		connectedMembers.push_back(&newFriend);
		newFriend.likePage(*this);
	}

	return *this;
}

/********* Fans-Page's functions *********/

void FansPage::deleteFriend(Member& other) noexcept(false)
{
	try
	{
		vector<User*>::iterator itrMy = findUserIteratorByName(other.getName(), (vector<User*>&)connectedMembers);

		connectedMembers.erase((vector<Member*>::iterator&) itrMy);
		other.dislikePage(*this);
	}
	catch (NotExistException&)
	{
		return;
	}
}