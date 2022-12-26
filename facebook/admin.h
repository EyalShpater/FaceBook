#ifndef __ADMIN_H
#define __ADMIN_H

#include <vector>
#include <string>

#include "member.h"
#include "fansPage.h"

class Date;

class Admin
{
	std::vector<Member*> allMembers;
	std::vector<FansPage*> allPages;

public:
	Admin() = default;
	~Admin();

	bool addFriend(const std::string& name, const Date& date);
	bool addFansPage(const std::string& name);
	bool addNewStatusToMember(const std::string& name, const std::string& newStatus);
	bool addNewStatusToFansPage(const std::string& name, const std::string& newStatus);
	bool makeFriendship(const std::string& nameFirst, const std::string& nameSecond);
	bool addFanToPage(const std::string& member, const std::string& page);

	bool removeFanFromPage(const std::string& member, const std::string& page);
	bool cancelFriendship(const std::string& nameFirst, const std::string& nameSecond);

	void showAllUsers() const;
	void showAllMembers() const;
	void showAllFansPages() const;
	bool showAllMemberFriends(const std::string& name) const;
	bool showAllFansPageFans(const std::string& name) const;
	bool showAllMemberStatuses(const std::string& name) const;
	bool showAllFansPageStatuses(const std::string& name) const;
	bool showUpdatedFriendsStatuses(const std::string& name) const;

private:
	Admin(const Admin&);
	const Admin& operator=(const Admin&);
};

#endif // __ADMIN_H