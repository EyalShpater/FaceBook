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
		<< (int)eChoice::ADD_MEMBER << "- Add member" << endl
		<< (int)eChoice::ADD_PAGE << "- Add fans page" << endl
		<< (int)eChoice::ADD_STATUS << "- Add status to member/fans page" << endl
		<< (int)eChoice::PRINT_STATUSES << "- Display all the statuses of a member/fans page" << endl
		<< (int)eChoice::PRINT_TEN_STATUSES << "- Display the 10 most recent statuses of a certain member's friends" << endl
		<< (int)eChoice::FRIENDSHIP << "- Friendship link between two friends" << endl
		<< (int)eChoice::CANCEL_FRIENDSHIP << "- Cancellation of membership between two members" << endl
		<< (int)eChoice::ADD_FAN_TO_PAGE << "- Add a fan to a fans-page" << endl
		<< (int)eChoice::REMOVE_FAN_FROM_PAGE << "- Remove a fan from a page" << endl
		<< (int)eChoice::PRINT_FACEBOOK_USERS << "- Display all members registered to faceBook" << endl
		<< (int)eChoice::PRINT_FRIENDS_OF_USER << "- Show all the friends of a certain member/page" << endl
		<< (int)eChoice::EXIT << "- Exit" << endl;
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
	catch (EmptyNameException& n)
	{
		n.show();
	}
	catch (ExistException& e)
	{
		e.show();
	}
	catch (WrongDayException& d)
	{
		d.show();
	}
	catch (WrongMonthException& m)
	{
		m.show();
	}
	catch (WrongYearException& y)
	{
		y.show();
	}
	catch (UserException& u)
	{
		u.show();
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
	catch (EmptyNameException& n)
	{
		n.show();
	}
	catch (ExistException& e)
	{
		e.show();
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
	catch (NotExistException& e)
	{
		e.show();
	}
	catch (EmptyTextException& e)
	{
		e.show();
	}
	catch (EmptyNameException& e)
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
	string text;
	string name;

	getchar(); // clear buffer

	askForMemberDetails(name);

	cout << "Enter your status" << endl;
	getline(cin, text);

	faceBook.addNewStatusToMember(name, text);
}

void ConsoleUI::addStatusToFansPage() noexcept(false)
{
	string text;
	string name;

	getchar(); // clear buffer

	askForFansPageDetails(name);

	cout << "Enter your status" << endl;
	getline(cin, text);

	faceBook.addNewStatusToFansPage(name, text);
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
	catch (EmptyNameException& n)
	{
		n.show();
	}
	catch (NotExistException& u)
	{
		u.show();
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

	catch (EmptyNameException& n)
	{
		n.show();
	}
	catch (NotExistException& u)
	{
		u.show();
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

	catch (EmptyNameException& n)
	{
		n.show();
	}
	catch (NotExistException& u)
	{
		u.show();
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

	catch (EmptyNameException& n)
	{
		n.show();
	}
	catch (NotExistException& u)
	{
		u.show();
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
	catch (NotExistException& n)
	{
		n.show();
	}
	catch (EmptyNameException& e)
	{
		e.show();
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
	catch (NotExistException& n)
	{
		n.show();
	}
	catch (EmptyNameException& e)
	{
		e.show();
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
	catch (NotExistException& n)
	{
		n.show();
	}
	catch (EmptyNameException& e)
	{
		e.show();
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