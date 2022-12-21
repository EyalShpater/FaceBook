#ifndef __MEMBER_H
#define __MEMBER_H

#include "date.h"
#include "billboard.h"
#include "memberArray.h"
#include "fansPageArray.h"

class Status;

class Member
{
	const char* name;
	const Date dateOfBirth;
	Billboard theBillboard;
	MemberArray members;
	FansPageArray fansPages;

public:
	Member(const char* name, const Date& birthDate);
	~Member();

	const char* getName() const { return name; }
	const Date& getDateOfBirth() const { return dateOfBirth; }
	int getNumOfFriends() const { return members.getLogSize(); }

	const Member& operator+= (Member& newFriend);
	bool operator>(const Member& other) const;
	bool operator>(const FansPage& other) const;
	
	void addStatusToBillboard(const char* text);
	void cancelFriendship(Member& other); 
	void likePage(FansPage& newPage); 
	void dislikePage(FansPage& other);

	void showAllStatus() const; 
	void showLatest10thStatus() const;
	void showUpdatedFriendsStatuses() const;
	void showAllFriends() const;
	void showAllFansPage() const;
	
private:
	Member(const Member&); 
};

#endif // __MEMBER_H