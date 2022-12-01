#pragma warning (disable:4996)

#include "consoleUI.h"
#include "admin.h"
#include "memberArray.h"
#include "member.h"
#include "fansPage.h"
#include "fansPageArray.h"

#include <iostream>
using namespace std;

/********* Const variables declaration *********/

const int MAX_NAME_LEN = 50;
const int MAX_STATUS_LEN = 300;

/********* Main functions *********/

void ConsoleUI::addDefaultMembersToFacebook()
{
	faceBook.addFansPage("MTA College");
	faceBook.addFansPage("Computer Science");
	faceBook.addFansPage("Coming From Love");

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
	faceBook.addFanToPage("Noa Kirel", "Coming From Love");
	faceBook.addFanToPage("Nitzan Sde Or", "Computer Science");
	faceBook.addFanToPage("Yehudit Ravitz", "Coming From Love");

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

	faceBook.addNewStatusToFansPage("MTA College", "Welcome all new students!");
	faceBook.addNewStatusToFansPage("MTA College", "If you want to pass you have to get at least 60 points.");

	faceBook.addNewStatusToFansPage("Coming From Love", "Peace and Love");
	faceBook.addNewStatusToFansPage("Coming From Love", "Maybe one day she would taste the taste of love...");

	faceBook.addNewStatusToFansPage("Computer Science", "C Plus Plus");
	faceBook.addNewStatusToFansPage("Computer Science", "Java Script");
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
		case CANCEL_FRIENDSHIP:
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
			cout << "\nbye!\n";
			break;
		}

	} while (choice != eChoice::EXIT);

}

/********* Utilities functions *********/

int ConsoleUI::printMenu() const
{
	int choice;

	cout << "~~~~~~~~~~~~~~~~~~~~ Menu ~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter your choice from the menu:" << endl
		<< ADD_MEMBER << "- Add member" << endl
		<< ADD_PAGE << "- Add fans page" << endl
		<< ADD_STATUS << "- Add status to member/fans page" << endl
		<< PRINT_STATUSES << "- Display all the statuses of a member/fans page" << endl
		<< PRINT_TEN_STATUSES << "- Display the 10 most recent statuses of a certain member's friends" << endl
		<< FRIENDSHIP << "- Friendship link between two friends" << endl
		<< CANCEL_FRIENDSHIP << "- Cancellation of membership between two members" << endl
		<< ADD_FAN_TO_PAGE << "- Add a fan to a fans-page" << endl
		<< REMOVE_FAN_FROM_PAGE << "- Remove a fan from a page" << endl
		<< PRINT_FACEBOOK_USERS << "- Display all members registered to faceBook" << endl
		<< PRINT_FRIENDS_OF_USER << "- Show all the friends of a certain member/page" << endl
		<< EXIT << "- Exit" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cin >> choice;

	return choice;
}

void ConsoleUI::askForMemberDetails(char name[]) const
{
	cout << "Enter the member's name: " << endl;

	cin.getline(name, MAX_NAME_LEN);
}

void ConsoleUI::askForFansPageDetails(char name[]) const
{
	cout << "Enter the fansPage's name: " << endl;

	cin.getline(name, MAX_NAME_LEN);
}

int ConsoleUI::askForUserType() const
{
	int type;
	bool flag = false;

	do
	{
		if (flag)
			cout << "Invalid input! try again" << endl;

		cout << "Press:\n" << (int)eUserType::MEMBER << " - to member" << endl
			<< (int)eUserType::FANS_PAGE << " - to fans page" << endl;
		cin >> type;

		flag = true;
	} while (type != eUserType::MEMBER && type != eUserType::FANS_PAGE);

	return type;
}

/********* Add and Connect functions *********/

void ConsoleUI::addFriend()
{
	int day, month, year;
	char name[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	system("cls");
	cout << "******************** Add A Friend To The System ********************" << endl;

	cout << "Please enter the friend's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	cout << "Please enter the friend's birthday: " << endl;
	cin >> day >> month >> year;
	
	isValid = faceBook.addFriend(name, Date(day, month, year));

	if (!isValid)
		cout << "\nName already exist!" << endl << endl;
}

void ConsoleUI::addFansPage()
{
	char name[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	system("cls");
	cout << "******************** Add A Fans-Page To The System ********************" << endl;

	cout << "Please enter the fans page's name: " << endl;
	cin.getline(name, MAX_NAME_LEN);
	
	isValid = faceBook.addFansPage(name);

	if (!isValid)
		cout << "\nName already exist!" << endl << endl;
}

void ConsoleUI::addStatusToUser()
{
	int type;

	system("cls");
	cout << "******************** Add Status To User ********************" << endl;

	type = askForUserType();

	switch (type)
	{
	case (int)eUserType::MEMBER:
		addStatusToMember();
		cout << endl;
		break;
	case (int)eUserType::FANS_PAGE:
		addStatusToFansPage();
		cout << endl;
		break;
	default:
		break;
	}
}

void ConsoleUI::addStatusToMember() // add input check
{
	char text[MAX_STATUS_LEN];
	char name[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	askForMemberDetails(name);

	cout << "Enter your status" << endl;
	cin.getline(text, MAX_STATUS_LEN);

	isValid = faceBook.addNewStatusToMember(name, text);

	if (!isValid)
		cout << endl << name << " not found!" << endl;
}

void ConsoleUI::addStatusToFansPage()
{
	char text[MAX_STATUS_LEN];
	char name[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	askForFansPageDetails(name);

	cout << "Enter your status" << endl;
	cin.getline(text, MAX_STATUS_LEN);

	isValid = faceBook.addNewStatusToFansPage(name, text);

	if (!isValid)
		cout << endl << name << " not found!" << endl;
}

void ConsoleUI::addFanToPage()
{
	char memberName[MAX_NAME_LEN];
	char fansPageName[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer
	system("cls");
	cout << "******************** Add Fan To Like A Page ********************" << endl;

	askForMemberDetails(memberName);
	askForFansPageDetails(fansPageName);

	isValid = faceBook.addFanToPage(memberName, fansPageName);

	if (!isValid)
		cout << endl << "Unable to add " << memberName << " to " << fansPageName << endl << endl;
}

void ConsoleUI::friendshipBetweenTwoMembers()
{
	char firstMemberName[MAX_NAME_LEN];
	char secondMemberName[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	system("cls");
	cout << "******************** Friendship Link ********************" << endl;

	askForMemberDetails(firstMemberName);
	askForMemberDetails(secondMemberName);

	isValid = faceBook.makeFriendship(firstMemberName, secondMemberName);

	if (!isValid)
		cout << "\nUnable to make " << firstMemberName << " and "
		<< secondMemberName << " friends :(" << endl << endl;
}

/********* Disconncet functions *********/

void ConsoleUI::cancelFriendshipBetweenTwoMembers()
{
	char firstMemberName[MAX_NAME_LEN];
	char secondMemberName[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	system("cls");
	cout << "******************** Cancel Friendship ********************" << endl;

	askForMemberDetails(firstMemberName);
	askForMemberDetails(secondMemberName);

	isValid = faceBook.cancelFriendship(firstMemberName, secondMemberName);

	if (!isValid)
		cout << "\nUnable to cancel friendship between " << firstMemberName << " and "
		<< secondMemberName << endl << endl;

}

void ConsoleUI::removeFanFromPage()
{
	char memberName[MAX_NAME_LEN];
	char fansPageName[MAX_NAME_LEN];
	bool isValid;

	getchar(); // clear buffer

	system("cls");
	cout << "******************** Remove A Friend From A Page ********************" << endl;

	askForMemberDetails(memberName);
	askForFansPageDetails(fansPageName);

	isValid = faceBook.removeFanFromPage(memberName, fansPageName);

	if (!isValid)
		cout << endl << "Unable to remove " << memberName << " from " << fansPageName << endl << endl;
}

/********* Show functions *********/

void ConsoleUI::showAllUserStatuses() const
{
	int type;
	
	system("cls");
	cout << "******************** Display All The Statuses Of A User ********************" << endl;

	type = askForUserType();

	getchar(); // clear buffer

	switch (type)
	{
	case (int)eUserType::MEMBER:
		showAllMemberStatuses();
		break;
	case (int)eUserType::FANS_PAGE:
		showAllFansPageStatuses();
		break;
	default:
		break;
	}
}

void ConsoleUI::showAllMemberStatuses() const
{
	char name[MAX_NAME_LEN];
	bool isValid;

	askForMemberDetails(name);
	
	cout << endl;

	isValid = faceBook.showAllMemberStatuses(name);

	if (!isValid)
		cout << endl << name << " not found!" << endl << endl;
}

void ConsoleUI::showAllFansPageStatuses() const
{
	char name[MAX_NAME_LEN];
	bool isValid;

	askForFansPageDetails(name);

	cout << endl;

	isValid = faceBook.showAllFansPageStatuses(name);

	if (!isValid)
		cout << endl << name << " not found!" << endl << endl;
}

void ConsoleUI::showUpdatedFriendsStatuses() const
{
	char name[MAX_NAME_LEN];
	bool isValid;
	
	getchar(); // clear buffer

	system("cls");
	cout << "******************** Display The 10 Most Recent Statuses ********************" << endl;

	askForMemberDetails(name);

	cout << endl;
	isValid = faceBook.showUpdatedFriendsStatuses(name);

	if (!isValid)
		cout << endl << name << " not found!" << endl << endl;
}

void ConsoleUI::showAllUsers() const
{
	system("cls");
	cout << "******************** All Users Registed To The System ********************" << endl;
	cout << endl;

	faceBook.showAllUsers();
}

void ConsoleUI::showUserFriends() const
{
	int type;

	system("cls");
	cout << "******************** Show All User's Friends ********************" << endl;
	
	type = askForUserType();

	getchar(); // clear buffer

	switch (type)
	{
	case (int)eUserType::MEMBER:
		showMemberFriends();
		break;
	case (int)eUserType::FANS_PAGE:
		showFansPageFans();
		break;
	default:
		break;
	}
}

void ConsoleUI::showMemberFriends() const
{	
	char name[MAX_NAME_LEN];
	bool isValid;

	askForMemberDetails(name);

	cout << endl;

	isValid = faceBook.showAllMemberFriends(name);

	if (!isValid)
		cout << endl << name << " not found!" << endl << endl;

}

void ConsoleUI::showFansPageFans() const
{
	char name[MAX_NAME_LEN];
	bool isValid;

	askForFansPageDetails(name);

	cout << endl;

	isValid = faceBook.showAllFansPageFans(name);

	if (!isValid)
		cout << endl << name << " not found!" << endl << endl;
}