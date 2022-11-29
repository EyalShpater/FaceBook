#pragma warning (disable:4996)

#include "consoleUI.h"
#include "admin.h"
#include "memberArray.h"
#include "member.h"
#include "fansPage.h"
#include "fansPageArray.h"

#include <iostream>
using namespace std;

const int MAX_NAME_LEN = 50;
const int MAX_STATUS_LEN = 300;

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
	faceBook.addFansPage("MTA College");
	faceBook.addFansPage("Computer Science");
	faceBook.addFansPage("We All Love CPP");
	
	faceBook.addFriend("Nitzan Sde Or", Date(24, 8, 1998));
	faceBook.addFriend("Eyal Shpater", Date(26, 10, 1998));
	faceBook.addFriend("Noa Kirel", Date(10, 4, 2001));
	
	/*
	eyal.addFriend(nitzan);
	nitzan.addFriend(noa);
	eyal.showAllFriend();
	cout << "\n-----------\n";
	eyal.likePage(mta);
	noa.likePage(cpp);
	eyal.addFriend(noa);
	eyal.showAllFriend();
	cout << "\n-----------\n";
	eyal.cancelFriendship(noa);
	cout << "\n-----------\n";
	cout << "Eyal:" << endl;
	eyal.showAllFriend();
	cout << "Noa: " << endl;
	noa.showAllFriend();
	cout << "Nitzan: " << endl;
	nitzan.showAllFriend();
	cout << "\n-----------\n";  */
}

void ConsoleUI::menu()
{	
	int choice;
	do
	{
		choice = printMenu();

		switch (choice)
		{
		case ADD_MEMBER:
			addFriend();
			break;
		case ADD_PAGE:
			addFansPage();
			break;
		case ADD_STATUS:
			addStatusToUser();
			break;
		case PRINT_STATUSES:
			showAllUserStatuses();
			break;
		case PRINT_TEN_STATUSES:
			showUpdatedFriendsStatuses();
			break;
		case FRIENDSHIP:
			friendshipBetweenTwoMembers();
			break;
		case CANCAL_FRIENDSHIP:
			cancelFriendshipBetweenTwoMembers();
			break;
		case ADD_FAN_TO_PAGE:
			addFanToPage();
			break;
		case REMOVE_FAN_FROM_PAGE:
			removeFanFromPage();
			break;
		case PRINT_FACEBOOK_USERS:
			showAllUsers();
			break;
		case PRINT_FRIENDS_OF_USER:
			showUserFriends();
			break;
		case EXIT:
			break;
		}

	} while (choice != eChoice::EXIT);

}

int ConsoleUI::printMenu()
{
	int choice;

	cout << "Please enter your choice from the menu:" << endl
		<< "1- Add member" << endl
		<< "2- Add fans page" << endl
		<< "3- Add status to member/fans page" << endl
		<< "4- Displaying all the statuses of a member/fans page" << endl
		<< "5- Displaying the 10 most recent statuses of a certain member's friends" << endl
		<< "6- Friendship link between two friends" << endl
		<< "7- Cancellation of membership between two members" << endl
		<< "8- Adding a fan to the page" << endl
		<< "9- Removing a fan from page" << endl
		<< "10- Displaying all members registered to faceBook" << endl
		<< "11- Showing all the friends of a certain member/page" << endl
		<< "12-Exit" << endl;

	cin >> choice;

	return choice;
}

const char* ConsoleUI::askForMemberDetails() 
{
	char memberName[MAX_NAME_LEN];

	cout << "Enter the member's name: " << endl;
	cin.getline(memberName, MAX_NAME_LEN);

	return memberName;
}

const char* ConsoleUI::askForFansPageDetails() 
{
	char fansPageName[MAX_NAME_LEN];

	cout << "Enter the fansPage's name: " << endl;
	cin.getline(fansPageName, MAX_NAME_LEN);

	return fansPageName;
}

bool ConsoleUI::addStatusToUser()
{
	int type = askForUserType();

	switch (type)
	{
	case (int)eUserType::MEMBER :
		addStatusToMember();
		return true;
	case (int)eUserType::FANS_PAGE :
		addStatusToFansPage();
		return true;
	default:
		return false;
	}
}

void ConsoleUI::addStatusToMember() // add input check
{
	char text[MAX_STATUS_LEN];
	char name[MAX_NAME_LEN];

	getchar(); // clear buffer

	strcpy(name, askForMemberDetails());

	cout << "Enter your status" << endl;
	cin.getline(text, MAX_STATUS_LEN);

	faceBook.addNewStatusToMember(name, text);
}

void ConsoleUI::addStatusToFansPage()
{
	char text[MAX_STATUS_LEN];
	char name[MAX_NAME_LEN];

	strcpy (name, askForFansPageDetails());

	cout << "Enter your status" << endl;
	cin.getline(text, MAX_STATUS_LEN);

	faceBook.addNewStatusToFansPage(name, text);
}

bool ConsoleUI::showAllUserStatuses() 
{
	int type = askForUserType();

	switch (type)
	{
	case (int)eUserType::MEMBER:
		return showAllMemberStatuses();
	case (int)eUserType::FANS_PAGE:
		return showAllFansPageStatuses();
	default:
		return false;
	}
}

bool ConsoleUI::showAllMemberStatuses() 
{
	char name[MAX_NAME_LEN];

	strcpy(name, askForMemberDetails());

	return faceBook.showAllMemberStatuses(name);
}

bool ConsoleUI::showAllFansPageStatuses() 
{
	char name[MAX_NAME_LEN];

	strcpy(name, askForFansPageDetails());

	return faceBook.showAllFansPageStatuses(name);
}

bool ConsoleUI::showUpdatedFriendsStatuses()
{
	char name[MAX_NAME_LEN];
	
	strcpy(name, askForMemberDetails());

	return faceBook.showUpdatedFriendsStatuses(name);
}

void ConsoleUI::showAllUsers()
{
	faceBook.showAllUsers();
}


bool ConsoleUI::addFanToPage()
{
	char memberName[MAX_NAME_LEN];
	char fansPageName[MAX_NAME_LEN];

	strcpy(memberName, askForMemberDetails());
	strcpy(fansPageName, askForFansPageDetails());

	return faceBook.addFanToPage(memberName, fansPageName);
}

bool ConsoleUI::removeFanFromPage()
{
	char memberName[MAX_NAME_LEN];
	char fansPageName[MAX_NAME_LEN];

	strcpy(memberName, askForMemberDetails());
	strcpy(fansPageName, askForFansPageDetails());

	return faceBook.removeFanFromPage(memberName, fansPageName);
}

bool ConsoleUI::showUserFriends()
{
	int type = askForUserType();

	switch (type)
	{
	case (int)eUserType::MEMBER:
		return showMemberFriends();
	case (int)eUserType::FANS_PAGE:
		return showFansPageFans();
	default:
		return false;
	}
}

bool ConsoleUI::showMemberFriends()
{	
	return faceBook.showAllMemberFriends(askForMemberDetails());
}
bool ConsoleUI::showFansPageFans()
{
	return faceBook.showAllFansPageFans(askForFansPageDetails());
}

int ConsoleUI::askForUserType()
{
	int type;

	cout << "Press:\n" << (int)eUserType::MEMBER << " - to add status to member" << endl
		<< (int)eUserType::FANS_PAGE << " - to add status to fans page" << endl;
	cin >> type;

	return type;
}

bool ConsoleUI::friendshipBetweenTwoMembers() 
{
	const char* firstMemberName = askForMemberDetails();
	const char* secondMemberName = askForMemberDetails();
	return faceBook.makeFriendship(firstMemberName, secondMemberName);
}

bool ConsoleUI::cancelFriendshipBetweenTwoMembers() 
{
	const char* firstMemberName = askForMemberDetails();
	const char* secondMemberName = askForMemberDetails();
	return faceBook.cancelFriendship(firstMemberName, secondMemberName);
}