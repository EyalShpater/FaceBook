#include "memberArray.h"

#include <iostream>
using namespace std;

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;

MemberArray::MemberArray()
{
	maxFriends = DEFAULT_PHYS_SIZE;
	numOfFriends = DEFAULT_LOG_SIZE;
	friends = new Member* [maxFriends];
}

