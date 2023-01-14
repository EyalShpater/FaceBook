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
	/*vector<Member*>::const_iterator*/auto itr = connectedMembers.begin();
	/*vector<Member*>::const_iterator*/auto itrEnd = connectedMembers.end();

	cout << "**********" << name << "'s connectd members **********" << endl << endl;

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;

	cout << "********************" << endl;
}

/********* Find functions *********/
/*
vector<User*>::iterator findUserIteratorByName(const string& name, vector<User*>& allUsers) noexcept(false)
{
	bool isFound = false;
	vector<User*>::iterator itr = allUsers.begin();
	vector<User*>::iterator itrEnd = allUsers.end();

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

vector<User*>::const_iterator findUserIteratorByName(const std::string& name, const std::vector<User*>& allUsers) noexcept(false)
{
	bool isFound = false;
	vector<User*>::const_iterator itr = allUsers.begin();
	vector<User*>::const_iterator itrEnd = allUsers.end();

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

User* findUserByName(const string& name, vector<User*>& allUsers)
{
	try
	{
		vector<User*>::iterator res = findUserIteratorByName(name, allUsers);
		return *res;
	}
	catch (NotExistException&)
	{
		return nullptr;
	}
}

const User* findUserByName(const std::string& name, const std::vector<User*>& allUsers)
{
	try
	{
		vector<User*>::const_iterator res = findUserIteratorByName(name, allUsers);
		return *res;
	}
	catch (NotExistException&)
	{
		return nullptr;
	}
}
*/

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
