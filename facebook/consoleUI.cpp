#include "consoleUI.h"
#include "admin.h"
#include "memberArray.h"
#include "member.h"

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

	Member& nitzan = faceBook.getMemberArray().getIndexMember(0);
	Member& eyal = faceBook.getMemberArray().getIndexMember(1);
	Member& noa = faceBook.getMemberArray().getIndexMember(2);

	FansPage& mta = faceBook.getFansPageArrary().getPageByIndex(0);
	FansPage& cs = faceBook.getFansPageArrary().getPageByIndex(1);
	FansPage& cpp = faceBook.getFansPageArrary().getPageByIndex(2);
	
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
	cout << "\n-----------\n";
}

void ConsoleUI::menu()
{
	enum eChoice { ONE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGTH, NINE, TEN, ELEVEN, TWELVE };
	int choice;

	cout << "Please enter your choice from the menu:" << endl
		<< "1- Add member" << endl
		<< "2- Add fans page" << endl
		<< "3- Add status to member/fans page" << endl
		<< "4- Displaying all the statuses of a member / fan page" << endl
		<< "5- Displaying the 10 most recent statuses of a certain member's friends" << endl
		<< "6- Friendship link between two friends" << endl
		<< "7- Cancellation of membership between two members" << endl
		<< "8- Adding a fan to the page" << endl
		<< "9- Removing a fan from page" << endl
		<< "10- Displaying all members registered to faceBook" << endl
		<< "11- Showing all the friends of a certain member / the fans of a certain page" << endl
		<< "12-Exit" << endl;

	cin >> choice;

	switch (choice)
	{
	case ONE:
	{
		addFriend();
		break;
	}
	case TWO:
	{
		addFansPage();
		break;
	}
	case THREE:
	{
		break;
	}
	case FOUR:
	{
		break;
	}
	case FIVE:
	{
		break;
	}
	case SIX:
	{
		break;
	}
	case SEVEN:
	{
		break;
	}
	case EIGTH:
	{
		break;
	}
	case NINE:
	{
		break;
	}
	case TEN:
	{
		break;
	}
	case ELEVEN:
	{
		break;
	}
	case TWELVE:
	{
		break;
	}

	}

}

bool ConsoleUI::addStatusToUser()
{
	int type;

	cout << "Press:\n" << (int)eUserType::MEMBER << " - to add status to member" << endl
		<< (int)eUserType::FANS_PAGE << " - to add status to fans page" << endl;

	cin >> type;

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
	int ind;
	char text[MAX_STATUS_LEN];
	char name[MAX_NAME_LEN];

	cout << "Enter the member's name" << endl;
	cin >> name;

	cout << "Enter your status" << endl;
	cin >> text;

	ind = faceBook.getMemberArray().findMemberByName(name);
	Member& theMember = faceBook.getMemberArray().getIndexMember(ind);

	faceBook.addNewStatus(theMember, text);
}

void ConsoleUI::addStatusToFansPage()
{
	int ind;
	char text[MAX_STATUS_LEN];
	char name[MAX_NAME_LEN];

	cout << "Enter the fans page's name" << endl;
	cin >> name;

	cout << "Enter your status" << endl;
	cin >> text;

	ind = faceBook.getFansPageArrary().findPage(name);
	FansPage& thePage = faceBook.getFansPageArrary().getPageByIndex(ind);

	faceBook.addNewStatus(thePage, text);
}