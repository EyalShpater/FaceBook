#ifndef __MEMBER_H
#define __MEMBER_H

#include "date.h"
#include "billboard.h"
#include "memberArray.h"
#include "fansPageArray.h"

class Status;

class Member
{
	char* name;
	const Date dateOfBirth;
	Billboard theBillboard;
	MemberArray members;
	FansPageArray fansPages;

public:
	Member(const char* name, const Date& birthDate);
	~Member();

	const char* getName() const { return name; }
	const Date& getDateOfBirth() const { return dateOfBirth; }
	
	void addStatusToBillboard(const char* text);
	bool addFriend(Member& newFriend); 
	void cancelFriendship(Member& other); //bool?
	void likePage(FansPage& newPage); //bool?
	void dislikePage(FansPage& other); // bool?

	void showAllStatus() const; 
	void showLatest10thStatus() const;
	void showUpdatedFriendsStatuses() const;
	void showAllFriends() const;
	void showAllFansPage() const;
	
private:
	Member(const Member&); 
};

#endif // __MEMBER_H