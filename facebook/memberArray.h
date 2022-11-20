#ifndef __MEMBERARRAY_H
#define __MEMBERARRAY_H

#include <iostream>
using namespace std;

#include "member.h"

class MemberArray
{
	Member** friends;
	int numOfFriends;
	int maxFriends;

public:
	MemberArray();
	Member** getFriends() const { return friends; }
	int getNumOfFriends() const { return numOfFriends; }
};

#endif //__MEMBERARRAY_H