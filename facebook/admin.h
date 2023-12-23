#ifndef __ADMIN_H
#define __ADMIN_H

#include <vector>
#include <string>
#include <fstream>

#include "member.h"
#include "fansPage.h"

class Date;

class Admin
{
	std::vector<Member*> allMembers;
	std::vector<FansPage*> allPages;

public:
	Admin();
	~Admin();

	void addFriend(const std::string& name, const Date& date) noexcept(false);
	void addFansPage(const std::string& name) noexcept(false);
	void addNewStatusToMember(const std::string& name, const std::string& newStatus, int type, const std::string& filePath = "") noexcept(false);
	void addNewStatusToFansPage(const std::string& name, const std::string& newStatus, int type, const std::string& filePath = "") noexcept(false);
	void makeFriendship(const std::string& nameFirst, const std::string& nameSecond) noexcept(false);
	void addFanToPage(const std::string& member, const std::string& page) noexcept(false);

	void removeFanFromPage(const std::string& member, const std::string& page) noexcept(false);
	void cancelFriendship(const std::string& nameFirst, const std::string& nameSecond) noexcept(false);

	void showAllUsers() const;
	void showAllMembers() const;
	void showAllFansPages() const;
	void showAllMemberFriends(const std::string& name) const noexcept(false);
	void showAllFansPageFans(const std::string& name) const noexcept(false);
	void showAllMemberStatuses(const std::string& name) const noexcept(false);
	void showAllFansPageStatuses(const std::string& name) const noexcept(false);
	void showUpdatedFriendsStatuses(const std::string& name) const noexcept(false);

private:
	Admin(const Admin&);
	Admin& operator=(const Admin&);

	void save(std::ofstream& outFile) const;
	void saveAllMembers(std::ofstream& outFile) const;
	void saveAllPages(std::ofstream& outFile) const;

	void load(std::ifstream& inFile);
	void readAllMembers(std::ifstream& inFile);
	void readConnectedMembers(std::ifstream& inFile, User& member);
	void readAllFansPagesToMember(std::ifstream& inFile, Member& member);
	void readAllPages(std::ifstream& inFile);
	
	void addDefaultMembers();
	void myMemberRealloc();
	void myFansPageRealloc();
};

#endif // __ADMIN_H