#ifndef __ADMIN_H
#define __ADMIN_H

#include "memberArray.h"
#include "fansPageArray.h"
#include "date.h"

class Admin
{
	MemberArray allMembers;
	FansPageArray allPages;

public:
	Admin();
	~Admin();

	MemberArray& getMemberArray() { return allMembers; } // do we need it?
	FansPageArray& getFansPageArrary() { return allPages; } // do we need it?

	void menu();
	void addFriend(const char* name, const Date& date);
	void addFansPage(const char* name);
	void show() const; // do we need it?

private:
	Admin(const Admin&);
};

#endif // __ADMIN_H