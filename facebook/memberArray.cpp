#include "memberArray.h"
#include "member.h"

#include <iostream>
using namespace std;

/********* Static variables declaration *********/

const int MemberArray::DEFAULT_PHYS_SIZE = 2;
const int MemberArray::DEFAULT_LOG_SIZE = 0;
const int MemberArray::NOT_FOUND = -1;
const int MemberArray::EQUAL = 0;

/********* Constructors *********/

MemberArray::MemberArray()
{
	physSize = DEFAULT_PHYS_SIZE;
	logSize = DEFAULT_LOG_SIZE;
	friends = new Member*[physSize];
}

MemberArray::~MemberArray()
{	
	delete[]friends;
}

/********* Array functions *********/

void MemberArray::push(Member& newMember)
{
	reserve();
	friends[logSize] = &newMember;
	logSize++;
}

void MemberArray::pop(Member& other)
{
	int index = findMemberByName(other.getName());

	if (index != NOT_FOUND)
	{
		friends[index] = friends[logSize - 1];
		logSize--;
	}
}

int MemberArray::findMemberByName(const char* name) const
{
	int index = NOT_FOUND;

	for (int i = 0; i < logSize && index == NOT_FOUND; i++)
		if (strcmp(friends[i]->getName(), name) == EQUAL)
			index = i;

	return index;
}

void MemberArray::reserve()
{
	if (physSize == logSize)
	{
		physSize *= 2;
		myRealloc(physSize);
	}
}

void MemberArray::myRealloc(int newSize)
{
	Member** temp = new Member * [newSize];
	for (int i = 0; i < logSize; i++) // Assumption: logSize < newSize
		temp[i] = friends[i];

	delete[]friends;

	friends = temp;
}

/********* Show *********/

void MemberArray::showAllMembers()const
{
	
	for (int i = 0; i < logSize; i++)
	{
		cout << "Member's name: " << friends[i]->getName() << endl;
		cout << "Member's birthday: ";
		friends[i]->getDateOfBirth().show();
		cout << endl << endl;
	}
}
