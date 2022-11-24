#ifndef __ADMIN_H
#define __ADMIN_H

#include "memberArray.h"
#include "fansPageArray.h"
#include "date.h"

class Admin
{
	MemberArray allMembers;
	FansPageArray allPgaes;

public:
	Admin();

	const MemberArray& getMemberArray() const { return allMembers; }
	const FansPageArray& getFansPageArrary() const { return allPgaes; }

	void menu();
	void addFriend(const char* name, const Date& date);
	void addFansPage();
	void show() const;

private:
	Admin(const Admin&);
};

#endif // __ADMIN_H