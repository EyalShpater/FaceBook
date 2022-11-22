#include "memberArray.h"
#include "member.h"

#include <iostream>
using namespace std;

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;

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
		physSize *= 2;
	myRealloc(physSize);
}

void MemberArray::myRealloc(int newSize)
{
	Member** temp = new Member * [newSize];
	for (int i = 0; i < logSize; i++) // assumption: logSize < newSize
		temp[i] = friends[i];

	delete[]friends;

	friends = temp;
}
