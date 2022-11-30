#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include "admin.h"

class ConsoleUI
{
public:
	enum eUserType { MEMBER, FANS_PAGE };
	enum eChoice
	{
		ADD_MEMBER = 1, ADD_PAGE, ADD_STATUS, PRINT_STATUSES, PRINT_TEN_STATUSES,
		FRIENDSHIP, CANCAL_FRIENDSHIP, ADD_FAN_TO_PAGE, REMOVE_FAN_FROM_PAGE,
		PRINT_FACEBOOK_USERS, PRINT_FRIENDS_OF_USER, EXIT
	};

private:
	Admin faceBook;

public:
	ConsoleUI() = default;

	void menu();
	void addDefaultMembersToFacebook();

private:
	ConsoleUI(const ConsoleUI&);

	int printMenu() const;
	const char* askForMemberDetails() const;
	const char* askForFansPageDetails() const;
	int askForUserType() const;

	void addFriend();
	void addFansPage();
	bool addStatusToUser();
	void addStatusToMember();
	void addStatusToFansPage();
	bool addFanToPage();
	bool friendshipBetweenTwoMembers();

	bool cancelFriendshipBetweenTwoMembers();
	bool removeFanFromPage();

	bool showAllUserStatuses() const;
	bool showAllMemberStatuses() const;
	bool showAllFansPageStatuses() const;
	bool showUpdatedFriendsStatuses() const;
	void showAllUsers() const;
	bool showUserFriends() const;
	bool showMemberFriends() const;
	bool showFansPageFans() const;
};

#endif// __CONSOLE_UI_H

