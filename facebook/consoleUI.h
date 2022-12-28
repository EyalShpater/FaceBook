#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include "admin.h"
#include <string>
class ConsoleUI
{
public:
	enum eUserType { MEMBER, FANS_PAGE };
	enum eChoice
	{
		ADD_MEMBER = 1, ADD_PAGE, ADD_STATUS, PRINT_STATUSES, PRINT_TEN_STATUSES,
		FRIENDSHIP, CANCEL_FRIENDSHIP, ADD_FAN_TO_PAGE, REMOVE_FAN_FROM_PAGE,
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
	const ConsoleUI& operator=(const ConsoleUI&);

	int printMenu() const;
	void askForMemberDetails(std::string& name) const noexcept(false);
	void askForFansPageDetails(std::string& name) const noexcept(false);
	int askForUserType() const;

	void addFriend();
	void addFansPage();
	void addStatusToUser();
	void addStatusToMember();
	void addStatusToFansPage() noexcept(false);
	void addFanToPage();
	void friendshipBetweenTwoMembers();

	void cancelFriendshipBetweenTwoMembers();
	void removeFanFromPage();

	void showAllUserStatuses() const;
	void showAllMemberStatuses() const noexcept(false);
	void showAllFansPageStatuses() const noexcept(false);
	void showUpdatedFriendsStatuses() const;
	void showAllUsers() const;
	void showUserFriends() const;
	void showMemberFriends() const;
	void showFansPageFans() const;
};

#endif// __CONSOLE_UI_H

