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
	~MemberArray();

	int getLogSize() const { return logSize; }
	int getPhysSize() const { return physSize; }

	void push(Member& newMember);
	void pop(const char* name);
	int findMemberByName(const char* name);
	void showAllMembers() const;
	
	
private:
	MemberArray(const MemberArray&);
	void reserve();
	void myRealloc(int newSize);

};

#endif //__MEMBERARRAY_H