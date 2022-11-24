#ifndef __CONSOLE_UI_H
#define __CONSOLE_UI_H

#include "admin.h"

class ConsoleUI
{
	Admin faceBook;
public:
	void menu();
	void addFriend();
	void addFansPage();
	void show() const;
};

#endif// __CONSOLE_UI_H

