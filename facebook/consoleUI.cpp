#include "consoleUI.h"
#include "admin.h"

#include <iostream>
using namespace std;

const int MAX_NAME_LEN = 50;

void ConsoleUI::addFriend()
{
	char name[MAX_NAME_LEN];
	cout << "Please enter the friend's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	cout << "Please enter the friend's birthday: " << endl;

	

}