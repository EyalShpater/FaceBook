#include "user.h"
#include "member.h"
#include "status.h"
#include "imageStatus.h"
#include "videoStatus.h"
#include "userException.h"

#include <iostream>
using namespace std;

const int DELETE_CALSS = 6;

/********* Contructors *********/
User::User(const string& name) : name(name)
{
	if (name == "") throw EmptyNameException();
}

User::~User()
{
	vector<Status*>::iterator itr = theBillboard.begin();
	vector<Status*>::iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		delete* itr;
}

ostream& operator<<(std::ostream& os, const User& u)
{
	os << "The " << typeid(u).name() + DELETE_CALSS << " name is: " << u.name;
	u.toOs(os);
	return os;
}

void User::addStatus(const string& newStatus, int type, const string& filePath) noexcept(false)
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

/********* Show functions *********/

void User::showAllStatus() const
{
	vector<Status*>::const_iterator itr = theBillboard.begin();
	vector<Status*>::const_iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
}

void User::showAllConnectedMembers() const 
{
	auto itr = connectedMembers.begin();
	auto itrEnd = connectedMembers.end();

	cout << "**********" << name << "'s connectd members **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;

	cout << "********************" << endl;
}

/********* Utilities functions *********/

void User::myMembersRealloc() 
{
	int logSize = connectedMembers.size();
	int physSize = connectedMembers.capacity();

	if (logSize == physSize)
		connectedMembers.reserve(physSize * 2);
}

void User::myStatusRealloc()
{
	int logSize = theBillboard.size();
	int physSize = theBillboard.capacity();

	if (logSize == physSize)
		theBillboard.reserve(physSize * 2);
}
