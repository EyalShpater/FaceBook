#ifndef __ADMIN_H
#define __ADMIN_H

#include "memberArray.h"
#include "fansPageArray.h"

class Admin
{
	MemberArray allMembers;
	FansPageArray allPgaes;

public:
	Admin();

	const MemberArray& getMemberArray() { return allMembers; }
	const FansPageArray& getFansPageArrary() { return allPgaes; }

	void menu();
	void addFriend();
	void addFansPage();
	void show() const;

private:
	Admin(const Admin&);
};

#endif // __ADMIN_H