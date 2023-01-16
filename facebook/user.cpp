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

User::User(ifstream& inFile)
{
	Status::readString(inFile, name);
}

User::~User()
{
	vector<Status*>::iterator itr = theBillboard.begin();
	vector<Status*>::iterator itrEnd = theBillboard.end();

	for (; itr != itrEnd; ++itr)
		delete* itr;
}

ostream& operator<<(ostream& os, const User& u)
{
	os << "The " << typeid(u).name() + DELETE_CALSS << " name is: " << u.name;
	u.toOs(os);
	return os;
}

void User::save(ofstream& outFile) const
{
	Status::saveString(outFile, name);
}

void User::saveBillBoard(ofstream& outFile) const
{
	int size = theBillboard.size();
	outFile.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		theBillboard[i]->saveType(outFile);
		theBillboard[i]->save(outFile);
	}
}

void User::saveConnectedMembers(ofstream& outFile) const
{
	int size = connectedMembers.size();
	outFile.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
		Status::saveString(outFile, connectedMembers[i]->getName());
}

void User::readBillBoard(std::ifstream& inFile)
{
	char type;
	int size;
	inFile.read((char*)&size, sizeof(size));

	theBillboard.reserve(size);

	for (int i = 0; i < size; i++)
	{
		inFile.read((char*)&type, sizeof(type));

		switch (type)
		{
		case (char)Status::eStatusType::TEXT:
			theBillboard.push_back(new Status(inFile));
			break;
		case (char)Status::eStatusType::IMAGE:
			theBillboard.push_back(new ImageStatus(inFile));
			break;
		case (char)Status::eStatusType::VIDEO:
			theBillboard.push_back(new VideoStatus(inFile));
			break;
		default:
			break;
		}
	}
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
