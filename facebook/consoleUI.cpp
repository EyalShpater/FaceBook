#pragma warning (disable:4996)

#include "consoleUI.h"
#include "member.h"
#include "fansPage.h"

#include "statusException.h"
#include "timeException.h"

#include <string>
#include <iostream>
using namespace std;

/********* Main functions *********/

void ConsoleUI::menu()
{
	int choice;
	do
	{
		choice = printMenu();

		switch (choice)
		{
		case (int)eChoice::ADD_MEMBER:
			addFriend();
			break;
		case (int)eChoice::ADD_PAGE:
			addFansPage();
			break;
		case (int)eChoice::ADD_STATUS:
			addStatusToUser();
			break;
		case (int)eChoice::PRINT_STATUSES:
			showAllUserStatuses();
			break;
		case (int)eChoice::PRINT_TEN_STATUSES:
			showUpdatedFriendsStatuses();
			break;
		case (int)eChoice::FRIENDSHIP:
			friendshipBetweenTwoMembers();
			break;
		case (int)eChoice::CANCEL_FRIENDSHIP:
			cancelFriendshipBetweenTwoMembers();
			break;
		case (int)eChoice::ADD_FAN_TO_PAGE:
			addFanToPage();
			break;
		case (int)eChoice::REMOVE_FAN_FROM_PAGE:
			removeFanFromPage();
			break;
		case (int)eChoice::PRINT_FACEBOOK_USERS:
			showAllUsers();
			break;
		case (int)eChoice::PRINT_FRIENDS_OF_USER:
			showUserFriends();
			break;
		case (int)eChoice::EXIT:
			cout << "\nbye!\n";
			break;
		default:
			cout << "Choice is not valid!" << endl;
			break;
		}

	} while (choice != (int)eChoice::EXIT);

}

/********* Utilities functions *********/

int ConsoleUI::printMenu() const
{
	int choice;

	cout << "~~~~~~~~~~~~~~~~~~~~ Menu ~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "Please enter your choice from the menu:" << endl
		<< (int)eChoice::ADD_MEMBER << "- Add a New Member" << endl
		<< (int)eChoice::ADD_PAGE << "- Add a New Fan Page" << endl
		<< (int)eChoice::ADD_STATUS << "- Add a Status to a Member / Fan Page" << endl
		<< (int)eChoice::PRINT_STATUSES << "- Show All Statuses of a Member / Fan Page" << endl
		<< (int)eChoice::PRINT_TEN_STATUSES << "- Show 10 of the Most Recent Statuses of a Member / Fan Page" << endl
		<< (int)eChoice::FRIENDSHIP << "- Connect Two Members - Add a Friendship" << endl
		<< (int)eChoice::CANCEL_FRIENDSHIP << "- Disconnect Two Members - Remove a Friendship" << endl
		<< (int)eChoice::ADD_FAN_TO_PAGE << "- Add a Member as a Fan of a Fan Page" << endl
		<< (int)eChoice::REMOVE_FAN_FROM_PAGE << "- Remove a Member (a Fan) of a Fan Page" << endl
		<< (int)eChoice::PRINT_FACEBOOK_USERS << "- Show All Members and Fan Pages in the system" << endl
		<< (int)eChoice::PRINT_FRIENDS_OF_USER << "- Show All Fans / Friends of a Fan Page / Member" << endl
		<< (int)eChoice::EXIT << "- Finish and Quit" << endl;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

	cin >> choice;

	return choice;
}

void ConsoleUI::askForMemberDetails(string& name) const noexcept(false)
{
	cout << "Enter the member's name: " << endl;
	
	getline(cin, name);
	
	if (name == "")
		throw EmptyNameException();
}

void ConsoleUI::askForFansPageDetails(string& name) const noexcept(false)
{
	cout << "Enter the fansPage's name: " << endl;

	getline(cin, name);

	if (name == "")
		throw EmptyNameException();
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
	} while (type != (int)eUserType::MEMBER && type != (int)eUserType::FANS_PAGE);

	return type;
}

int ConsoleUI::askForStatusType() const
{
	int type; 
	
	bool flag = false;

	do
	{
		if (flag)
			cout << "Invalid input! try again" << endl;

		cout << "Press:\n" << "0 - to add a text status" << endl
			<< "1 - to add an image" << endl
			<< "2 - to add a video" << endl;
		cin >> type;

		flag = true;
	} while (type != 0 && type != 1 && type != 2);

	switch (type)
	{
	case 0: type = (int)Status::eStatusType::TEXT; break;
	case 1: type = (int)Status::eStatusType::IMAGE; break;
	case 2: type = (int)Status::eStatusType::VIDEO; break;
	}

	return type;
}

/********* Add and Connect functions *********/

void ConsoleUI::addFriend()
{
	try
	{
		int day, month, year;
		string name;

		getchar(); // clear buffer

		system("cls");
		cout << "******************** Add A Friend To The System ********************" << endl;

		cout << "Please enter the friend's name: " << endl;
		getline(cin, name);
		cout << "Please enter the friend's birthday: " << endl;
		cin >> day >> month >> year;

		faceBook.addFriend(name, Date(day, month, year));
	}

	catch (UserException& e)
	{
		e.show();
	}
	catch (TimeException& t)
	{
		t.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::addFansPage()
{
	try 
	{
		string name;

		getchar(); // clear buffer

		system("cls");
		cout << "******************** Add A Fans-Page To The System ********************" << endl;

		cout << "Please enter the fans page's name: " << endl;
		getline(cin, name);

		faceBook.addFansPage(name);
	}

	catch (UserException& u)
	{
		u.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::addStatusToUser()
{
	try 
	{
		int userType;

		system("cls");
		cout << "******************** Add Status To User ********************" << endl;

		userType = askForUserType();

		switch (userType)
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

	catch (StatusException& e)
	{
		e.show();
	}
	catch (UserException& e)
	{
		e.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::addStatusToMember() noexcept(false)
{
	int statusType;
	string text;
	string filePath = "";
	string name;

	getchar(); // clear buffer

	askForMemberDetails(name);
	statusType = askForStatusType();

	getchar(); // clear buffer

	cout << "Enter your status" << endl;
	getline(cin, text);

	if (statusType != (int)Status::eStatusType::TEXT)
	{
		cout << "Enter the  " << (statusType == (int)Status::eStatusType::IMAGE ? "image" : "video") << " name" << endl;
		getline(cin, filePath);
	}
	faceBook.addNewStatusToMember(name, text, statusType, filePath);
}

void ConsoleUI::addStatusToFansPage() noexcept(false)
{
	int statusType;
	string text;
	string filePath = "";
	string name;

	getchar(); // clear buffer

	askForFansPageDetails(name);
	statusType = askForStatusType();
	
	getchar(); // clear buffer

	cout << "Enter your status" << endl;
	getline(cin, text);

	if (statusType != (int)Status::eStatusType::TEXT)
	{
		cout << "Enter the  " << (statusType == (int)Status::eStatusType::IMAGE ? "image" : "video") << " name" << endl;
		getline(cin, filePath);
	}

	faceBook.addNewStatusToFansPage(name, text, statusType, filePath);
}

void ConsoleUI::addFanToPage()
{
	try 
	{
		string memberName;
		string fansPageName;

		getchar(); // clear buffer
		system("cls");
		cout << "******************** Add Fan To Like A Page ********************" << endl;

		askForMemberDetails(memberName);
		askForFansPageDetails(fansPageName);

		faceBook.addFanToPage(memberName, fansPageName);
	}
	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::friendshipBetweenTwoMembers()
{
	try 
	{
		string firstMemberName;
		string secondMemberName;

		getchar(); // clear buffer

		system("cls");
		cout << "******************** Friendship Link ********************" << endl;

		askForMemberDetails(firstMemberName);
		askForMemberDetails(secondMemberName);

		faceBook.makeFriendship(firstMemberName, secondMemberName);
	}

	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

/********* Disconnect functions *********/

void ConsoleUI::cancelFriendshipBetweenTwoMembers()
{
	try 
	{
		string firstMemberName;
		string secondMemberName;

		getchar(); // clear buffer

		system("cls");
		cout << "******************** Cancel Friendship ********************" << endl;

		askForMemberDetails(firstMemberName);
		askForMemberDetails(secondMemberName);

		faceBook.cancelFriendship(firstMemberName, secondMemberName);
	}

	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::removeFanFromPage()
{
	try {
		string memberName;
		string fansPageName;

		getchar(); // clear buffer

		system("cls");
		cout << "******************** Remove A Friend From A Page ********************" << endl;

		askForMemberDetails(memberName);
		askForFansPageDetails(fansPageName);

		faceBook.removeFanFromPage(memberName, fansPageName);
	}

	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

/********* Show functions *********/

void ConsoleUI::showAllUserStatuses() const
{
	try 
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
	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::showAllMemberStatuses() const noexcept(false)
{
	string name;

	askForMemberDetails(name);
	cout << endl;

	faceBook.showAllMemberStatuses(name);
}

void ConsoleUI::showAllFansPageStatuses() const noexcept(false)
{
	string name;

	askForFansPageDetails(name);
	cout << endl;

	faceBook.showAllFansPageStatuses(name);
}

void ConsoleUI::showUpdatedFriendsStatuses() const
{
	try 
	{
		string name;

		getchar(); // clear buffer

		system("cls");
		cout << "******************** Display The 10 Most Recent Statuses ********************" << endl;

		askForMemberDetails(name);
		cout << endl;

		faceBook.showUpdatedFriendsStatuses(name);
	}
	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::showAllUsers() const
{
	system("cls");
	cout << "******************** All Users Registered To The System ********************" << endl;
	cout << endl;

	faceBook.showAllUsers();
}

void ConsoleUI::showUserFriends() const
{
	try
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
	catch (UserException& n)
	{
		n.show();
	}
	catch (...)
	{
		cout << "General Error" << endl;
	}
}

void ConsoleUI::showMemberFriends() const
{	
	string name;

	askForMemberDetails(name);
	cout << endl;

	faceBook.showAllMemberFriends(name);
}

void ConsoleUI::showFansPageFans() const
{
	string name;

	askForFansPageDetails(name);
	cout << endl;

	faceBook.showAllFansPageFans(name);
}