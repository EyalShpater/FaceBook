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

	void addFriend(const std::string& name, const Date& date) noexcept(false);
	void addFansPage(const std::string& name) noexcept(false);
	void addNewStatusToMember(const std::string& name, const std::string& newStatus) noexcept(false);
	void addNewStatusToFansPage(const std::string& name, const std::string& newStatus) noexcept(false);
	void makeFriendship(const std::string& nameFirst, const std::string& nameSecond) noexcept(false);
	void addFanToPage(const std::string& member, const std::string& page) noexcept(false);

	void removeFanFromPage(const std::string& member, const std::string& page) noexcept(false);
	void cancelFriendship(const std::string& nameFirst, const std::string& nameSecond) noexcept(false);

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

	void myMemberRealloc();
	void myFansPageRealloc();
};

#endif // __ADMIN_H