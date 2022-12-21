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
	std::vector<Status> theBillboard;
	std::vector<Member*> members;
	std::vector<FansPage*> fansPages;

public:
	Member(const std::string& name, const Date& birthDate);
	
	const std::string& getName() const { return name; }
	const Date& getDateOfBirth() const { return dateOfBirth; }
	int getNumOfFriends() const { return members.size(); }

	const Member& operator+= (Member& newFriend);
	bool operator>(const Member& other) const;
	bool operator>(const FansPage& other) const;
	friend std::ostream& operator<<(std::ostream& os, const Member& s);
	
	// This function returns iterator to the Member adress in allMembers if found, 
	// else returns the last place in the vector.
	friend std::vector<Member*>::iterator findMemberIteratorByName(const std::string& name, std::vector<Member*>& allMembers);
	friend std::list<Member>::iterator findMemberIteratorByName(const std::string& name, std::list<Member>& allMembers);

	friend Member* findMemberByName(const std::string& name, std::vector<Member*> &allMembers);
	friend Member* findMemberByName(const std::string& name, std::list<Member>& allMembers);

	void addStatusToBillboard(const std::string& text);
	void cancelFriendship(Member& other); 
	void likePage(FansPage& newPage); 
	void dislikePage(FansPage& other);

	void showAllStatus() const; 
	void showLatest10thStatus() const;
	void showUpdatedFriendsStatuses() const;
	void showAllFriends() const;
	void showAllFansPage() const;
	
private:
	Member(const Member&); 
};

#endif // __MEMBER_H