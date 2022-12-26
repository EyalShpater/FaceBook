#ifndef __MEMBER_H
#define __MEMBER_H

#include "status.h"
#include "date.h"

#include <vector>
#include <list>
#include <string>

class FansPage;

class Member
{
	std::string name;
	const Date dateOfBirth;
	std::vector<Status*> theBillboard;
	std::vector<Member*> members;
	std::vector<FansPage*> fansPages;

public:
	Member(const std::string& name, const Date& birthDate) noexcept(false);
	~Member();
	
	const std::string& getName() const { return name; }
	const Date& getDateOfBirth() const { return dateOfBirth; }
	int getNumOfFriends() const { return members.size(); }

	const Member& operator+= (Member& newFriend);
	bool operator>(const Member& other) const;
	bool operator>(const FansPage& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Member& s);
	
	friend std::vector<Member*>::iterator findMemberIteratorByName(const std::string& name, std::vector<Member*>& allMembers) noexcept(false);
	friend std::vector<Member*>::const_iterator findMemberIteratorByName(const std::string& name, const std::vector<Member*>& allMembers) noexcept(false);
	friend Member* findMemberByName(const std::string& name, std::vector<Member*> &allMembers);
	friend const Member* findMemberByName(const std::string& name, const std::vector<Member*>& allMembers);

	void addStatusToBillboard(const std::string& text) noexcept(false);
	void cancelFriendship(Member& other) noexcept(false); // throw?
	void likePage(FansPage& newPage); 
	void dislikePage(FansPage& other) noexcept(false); // throw?

	void showAllStatus() const; 
	void showLatest10thStatus() const;
	void showUpdatedFriendsStatuses() const;
	void showAllFriends() const;
	void showAllFansPage() const;
	
private:
	Member(const Member&);
	const Member& operator=(const Member&);

	void myMemberRealloc();
	void myFansPageRealloc();
	void myStatusRealloc();
};

#endif // __MEMBER_H