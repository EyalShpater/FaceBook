#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include "admin.h"

class ConsoleUI
{
	Admin faceBook;
public:

	ConsoleUI() = default;

	void menu();
	void addFriend();
	void addFansPage();
	Member* askForMemberDetails();
	FansPage* askForFansPageDetails();
	void addDefaultMembersToFacebook();
	bool addStatusToUser();
	void addStatusToMember();
	void addStatusToFansPage();
	bool addFanToPage();
	bool removeFanFromPage();


	enum eUserType { MEMBER, FANS_PAGE };

	enum eChoice 
	{
		ADD_MEMBER = 1, ADD_PAGE, ADD_STATUS, PRINT_STATUSES, PRINT_TEN_STATUSES, 
		FRIENDSHIP, CANCAL_FRIENDSHIP, ADD_FAN_TO_PAGE, REMOVE_FAN_FROM_PAGE,
		PRINT_FACEBOOK_USERS, PRINT_FRIENDS_OF_USER, EXIT
	};

private:
	ConsoleUI(const ConsoleUI&);

	int printMenu();
	bool showAllUserStatuses();
	bool showAllMemberStatuses();
	bool showAllFansPageStatuses();
	bool showUpdatedStatuses();
	void showAllUsers();
	void showUserFriends();
	void showMemberFriends();
	void showFansPageFriends();
};

#endif// __CONSOLE_UI_H

