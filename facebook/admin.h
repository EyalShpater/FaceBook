#ifndef __ADMIN_H
#define __ADMIN_H

#include "memberArray.h"
#include "fansPageArray.h"
#include "date.h"
#include "status.h"

class Admin
{
	MemberArray allMembers;
	FansPageArray allPages;

public:
	Admin() = default;
	~Admin();

	bool addFriend(const char* name, const Date& date);
	bool addFansPage(const char* name);
	void showAllUsers() const;
	void showAllMembers() const; 
	void showAllFansPages() const; 
	void addNewStatusToMember(const char* name, const char* newStatus);
	void addNewStatusToFansPage(const char* name, const char* newStatus);
	bool addFanToPage(const char* member, const char* page);
	bool removeFanFromPage(const char* member,const char* page);
	bool showAllMemberFriends(const char* name) const;
	bool showAllFansPageFans(const char* name) const;
	bool showAllMemberStatuses(const char* name) const;
	bool showAllFansPageStatuses(const char* name) const;
	bool showUpdatedFriendsStatuses(const char* name) const;
	bool makeFriendship(const char* nameFirst, const char* nameSecond);
	bool cancelFriendship(const char* nameFirst, const char* nameSecond);

private:
	Admin(const Admin&);
};

#endif // __ADMIN_H