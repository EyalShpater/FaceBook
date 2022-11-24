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
	
	void addStatusToBillboard(Status& newStatus);
	void addFriend(Member& newFriend);
	void cancelFriendship(const char* name);
	void likePage(const char* name);
	void showAllStatus() const;
	void showLatest10thStatus() const;
	void showAllFriend() const;
	
private:
	Member(const Member&); 
};


#endif // __MEMBER_H