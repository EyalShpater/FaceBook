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
	
	void addStatusToBillboard(const Status& newStatus);
	// showAllStatus
	//showLatest10thStatus
	


private:
	Member(const Member&);
};


#endif // __MEMBER_H