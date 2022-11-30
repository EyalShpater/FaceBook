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

	getchar(); // clear buffer

	cout << "Please enter the friend's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	cout << "Please enter the friend's birthday: " << endl;
	cin >> day >> month >> year;
	
	faceBook.addFriend(name, Date(day, month, year));
}

void ConsoleUI::addFansPage()
{
	char name[MAX_NAME_LEN];

	getchar(); // clear buffer

	cout << "Please enter the fans page's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	
	faceBook.addFansPage(name);
}

void ConsoleUI::addDefaultMembersToFacebook()
{
	faceBook.addFansPage("MTA College");
	faceBook.addFansPage("Computer Science");
	faceBook.addFansPage("We All Love CPP");
	faceBook.addFansPage("Comeing From Love");
	
	faceBook.addFriend("Nitzan Sde Or", Date(24, 8, 1998));
	faceBook.addFriend("Eyal Shpater", Date(26, 10, 1998));
	faceBook.addFriend("Noa Kirel", Date(10, 4, 2001));
	faceBook.addFriend("Yehudit Ravitz", Date(29, 12, 1956));
	
	
	faceBook.makeFriendship("Eyal Shpater", "Nitzan Sde Or");
	faceBook.makeFriendship("Noa Kirel", "Nitzan Sde Or");
	faceBook.makeFriendship("Noa Kirel", "Nitzan Sde Or");
	faceBook.makeFriendship("Yehudit Ravitz", "Eyal Shpater");

	faceBook.addFanToPage("Eyal Shpater", "MTA College");
	faceBook.addFanToPage("Nitzan Sde Or", "MTA College");
	faceBook.addFanToPage("Noa Kirel", "We All Love CPP");
	faceBook.addFanToPage("Nitzan Sde Or", "Computer Science");
	faceBook.addFanToPage("Yehudit Ravitz", "Comeing From Love");

	faceBook.addNewStatusToMember("Nitzan Sde Or", "N for Nadir");
	faceBook.addNewStatusToMember("Nitzan Sde Or", "Hello World!");
	faceBook.addNewStatusToMember("Nitzan Sde Or", "1 2 3 check 1 2 3");

	faceBook.addNewStatusToMember("Eyal Shpater", "Hello it's me.");
	faceBook.addNewStatusToMember("Eyal Shpater", "I was wondering...");
	faceBook.addNewStatusToMember("Eyal Shpater", "If after all these years you'd like to meet?");

	faceBook.addNewStatusToMember("Noa Kirel", "la la la la la");
	faceBook.addNewStatusToMember("Noa Kirel", "Noa Kila keep it reala");
	
	faceBook.addNewStatusToMember("Yehudit Ravitz", "I don't want to sing on stage again.");
	faceBook.addNewStatusToMember("Yehudit Ravitz", "Do you know any song include black gold?");
	faceBook.addNewStatusToMember("Yehudit Ravitz", "I don't understand how you can be sad, when you are the most beautiful girl");
	

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

int ConsoleUI::printMenu() const
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

const char* ConsoleUI::askForMemberDetails() const
{
	char memberName[MAX_NAME_LEN];

	cout << "Enter the member's name: " << endl;
	cin.getline(memberName, MAX_NAME_LEN);

	return memberName;
}

const char* ConsoleUI::askForFansPageDetails() const
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

	getchar(); // clear buffer

	strcpy (name, askForFansPageDetails());

	cout << "Enter your status" << endl;
	cin.getline(text, MAX_STATUS_LEN);

	faceBook.addNewStatusToFansPage(name, text);
}

bool ConsoleUI::showAllUserStatuses() const
{
	int type = askForUserType();

	getchar(); // clear buffer

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

bool ConsoleUI::showAllMemberStatuses() const
{
	char name[MAX_NAME_LEN];

	strcpy(name, askForMemberDetails());

	return faceBook.showAllMemberStatuses(name);
}

bool ConsoleUI::showAllFansPageStatuses() const
{
	char name[MAX_NAME_LEN];

	strcpy(name, askForFansPageDetails());

	return faceBook.showAllFansPageStatuses(name);
}

bool ConsoleUI::showUpdatedFriendsStatuses() const
{
	char name[MAX_NAME_LEN];
	
	strcpy(name, askForMemberDetails());

	getchar(); // clear buffer

	return faceBook.showUpdatedFriendsStatuses(name);
}

void ConsoleUI::showAllUsers() const
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

bool ConsoleUI::showUserFriends() const
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

bool ConsoleUI::showMemberFriends() const
{	
	return faceBook.showAllMemberFriends(askForMemberDetails());
}

bool ConsoleUI::showFansPageFans() const
{
	return faceBook.showAllFansPageFans(askForFansPageDetails());
}

int ConsoleUI::askForUserType() const
{
	int type;

	cout << "Press:\n" << (int)eUserType::MEMBER << " - to member" << endl
		<< (int)eUserType::FANS_PAGE << " - to fans page" << endl;
	cin >> type;

	return type;
}

bool ConsoleUI::friendshipBetweenTwoMembers() 
{
    char firstMemberName[MAX_NAME_LEN];
	strcpy(firstMemberName, askForMemberDetails());

    char secondMemberName[MAX_NAME_LEN];
	strcpy(secondMemberName, askForMemberDetails());

	return faceBook.makeFriendship(firstMemberName, secondMemberName);
}

bool ConsoleUI::cancelFriendshipBetweenTwoMembers() 
{
	char firstMemberName[MAX_NAME_LEN];
	strcpy(firstMemberName, askForMemberDetails());

	//getchar(); // clear buffer

	char secondMemberName[MAX_NAME_LEN];
	strcpy(secondMemberName, askForMemberDetails());

	return faceBook.cancelFriendship(firstMemberName, secondMemberName);
}