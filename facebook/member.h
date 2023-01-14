#ifndef __MEMBER_H
#define __MEMBER_H

#include "status.h"
#include "date.h"
#include "user.h"

#include <vector>
#include <string>
#include <iostream>

class FansPage;

class Member : public User
{
	const Date dateOfBirth;
	std::vector<FansPage*> fansPages;

public:
	Member(const std::string& name, const Date& birthDate) noexcept(false);
	
	const Date& getDateOfBirth() const { return dateOfBirth; }

	const Member& operator+= (Member& newFriend);
	bool operator>(const Member& other) const;
	bool operator>(const FansPage& other) const;

	void cancelFriendship(Member& other) noexcept(false);
	void likePage(FansPage& newPage); 
	void dislikePage(FansPage& other) noexcept(false);

	void showLatest10thStatus() const;
	void showUpdatedFriendsStatuses() const;
	void showAllFansPage() const;
	
private:
	Member(const Member&);
	const Member& operator=(const Member&);

	virtual void toOs(std::ostream& os) const override;
	void myFansPageRealloc();
};

#endif // __MEMBER_H