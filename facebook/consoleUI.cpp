#include "consoleUI.h"
#include "admin.h"
#include "memberArray.h"
#include "member.h"

#include <iostream>
using namespace std;

const int MAX_NAME_LEN = 50;

void ConsoleUI::addFriend()
{
	int day, month, year;
	char name[MAX_NAME_LEN];

	cout << "Please enter the friend's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	cout << "Please enter the friend's birthday: " << endl;
	cin >> day >> month >> year;
	
	faceBook.addFriend(name, Date(day, month, year));
}

void ConsoleUI::addFansPage()
{
	char name[MAX_NAME_LEN];

	cout << "Please enter the fans page's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	
	faceBook.addFansPage(name);
}

void ConsoleUI::addDefaultMembersToFacebook()
{
	//Member& 

	faceBook.addFansPage("MTA College");
	faceBook.addFansPage("Computer Science");
	faceBook.addFansPage("We All Love CPP");
	
	faceBook.addFriend("Nitzan Sde Or", Date(24, 8, 1998));
	faceBook.addFriend("Eyal Shpater", Date(26, 10, 1998));
	faceBook.addFriend("Noa Kirel", Date(10, 4, 2001));

	//faceBook.getMemberArray().getIndexMember(0)->addFriend(faceBook.getMemberArray().getIndexMember(1))
}