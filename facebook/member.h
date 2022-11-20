#ifndef __MEMBER_H
#define __MEMBER_H

#include "date.h"
#include "billboard.h"

class fansPage;

class Member
{
	char* name;
	const Date dateOfBirth;
	Billboard theBillboard;
	Member** friends;
	int numOfFriends;
	int maxFriends;
	fansPage** fansPageArray;
	int numOfFansPage;
	int maxFansPage;

public:
	Member(const char* name, const Date& birthDate);
	~Member();

	const char* getName() const { return name; }
	const Date& getDateOfBirth() const { return dateOfBirth; }
	Member** getFriends() const { return friends; }
	int getNumOfFriends() const { return numOfFriends; }
	fansPage** getFansPage() const { return fansPageArray; }
	int getNumOfFansPage() const { return numOfFansPage; }




private:
	Member(const Member&);
};


#endif // __MEMBER_H