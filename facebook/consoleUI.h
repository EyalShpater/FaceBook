#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include "admin.h"

class ConsoleUI
{
	Admin faceBook;
public:

	//ConsoleUI() = default;
	void menu();
	void addFriend();
	void addFansPage();
	int askForMemberDetails();
	int askForFansPageDetails();
	//void show() const;
	void addDefaultMembersToFacebook();

private:
	int printMenu();
};

#endif// __CONSOLE_UI_H

