#ifndef __MEMBERARRAY_H
#define __MEMBERARRAY_H

#include <iostream>
using namespace std;

class Member;

class MemberArray
{
	Member** friends;
	int logSize;
	int physSize;

public:
	MemberArray();
	Member** getFriends() const { return friends; }
	int getNumOfFriends() const { return numOfFriends; }

	int getLogSize() const { return logSize; }
	int getPhysSize() const { return physSize; }

	void push(const Member& newMember);
	void showAllMembers() const;
	
private:
	MemberArray(const MemberArray&);
	void reserve();
};

#endif //__MEMBERARRAY_H