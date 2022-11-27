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
	//void show() const;
	void addDefaultMembersToFacebook();
};

#endif// __CONSOLE_UI_H

