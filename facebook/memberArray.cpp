#include "memberArray.h"
#include "member.h"

#include <iostream>
using namespace std;

const int DEFAULT_PHYS_SIZE = 2; // make all of this static in the h file
const int DEFAULT_LOG_SIZE = 0;
const int NOT_FOUND = -1;
const int EQUAL = 0;

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

void MemberArray::push(Member& newMember) //cancle const
{
	reserve();
	friends[logSize] = &newMember;
	logSize++;
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
	for (int i = 0; i < logSize; i++) // assumption: logSize < newSize
		temp[i] = friends[i];

	delete[]friends;

	friends = temp;
}

void MemberArray::pop(Member& other) // bool?
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
	{
		if (strcmp(friends[i]->getName(), name) == EQUAL)
			index = i;
	}

	return index;
}

void MemberArray::showAllMembers()const
{
	
	for (int i = 0; i < logSize; i++)
	{
		cout << "Member's name: " << friends[i]->getName() << endl;
		cout << "Member's birthday: ";
		friends[i]->getDateOfBirth().show();
		cout << endl;
	}
}
