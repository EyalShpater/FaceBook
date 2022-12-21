#ifndef __ADMIN_H
#define __ADMIN_H

#include <list>
#include "member.h"
#include "fansPage.h"

class Date;

class Admin
{
	std::list<Member> allMembers;
	std::list<FansPage> allPages;

public:
	Admin() = default;

	bool addFriend(const char* name, const Date& date);
	bool addFansPage(const char* name);
	bool addNewStatusToMember(const char* name, const char* newStatus);
	bool addNewStatusToFansPage(const char* name, const char* newStatus);
	bool makeFriendship(const char* nameFirst, const char* nameSecond);
	bool addFanToPage(const char* member, const char* page);

	bool removeFanFromPage(const char* member,const char* page);
	bool cancelFriendship(const char* nameFirst, const char* nameSecond);

	void showAllUsers() const;
	void showAllMembers() const;
	void showAllFansPages() const;
	bool showAllMemberFriends(const char* name) const;
	bool showAllFansPageFans(const char* name) const;
	bool showAllMemberStatuses(const char* name) const;
	bool showAllFansPageStatuses(const char* name) const;
	bool showUpdatedFriendsStatuses(const char* name) const;

private:
	Admin(const Admin&);
};

#endif // __ADMIN_H