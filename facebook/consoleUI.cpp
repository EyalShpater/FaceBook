#include "consoleUI.h"
#include "admin.h"
#include "memberArray.h"
#include "member.h"
#include "fansPage.h"
#include "fansPageArray.h"

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
	faceBook.addFansPage("MTA College");
	faceBook.addFansPage("Computer Science");
	faceBook.addFansPage("We All Love CPP");
	
	faceBook.addFriend("Nitzan Sde Or", Date(24, 8, 1998));
	faceBook.addFriend("Eyal Shpater", Date(26, 10, 1998));
	faceBook.addFriend("Noa Kirel", Date(10, 4, 2001));

	Member& nitzan = faceBook.getMemberArray().getMemberByIndex(0);
	Member& eyal = faceBook.getMemberArray().getMemberByIndex(1);
	Member& noa = faceBook.getMemberArray().getMemberByIndex(2);

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
	enum eChoice {
		ADD_MEMBER = 1, ADD_PAGE, ADD_STATUS_TO_MEMBER, ADD_STATUS_TO_PAGE,
		PRINT_STATUSES_MEMBER, PRINT_STATUSES_PAGE, PRINT_TEN_STATUSES,
		FRIENDSHIP, CANCAL_FRIENDSHIP, ADD_FAN_TO_PAGE, REMOVE_FAN_FROM_PAGE,
		PRINT_FACEBOOK_MEMBERS, PRINT_FRIENDS_OF_MEMBER, PRINT_FRIENDS_OF_PAGE, EXIT
	};
	
	int choice=printMenu();

	switch (choice)
	{
	case ADD_MEMBER:
	{
		addFriend();
		break;
	}
	case ADD_PAGE:
	{
		addFansPage();
		break;
	}
	case ADD_STATUS_TO_MEMBER:
	{
		int indexMember = askForMemberDetails;
		faceBook.getMemberArray().getMemberByIndex(indexMember).addStatusToBillboard(/*createStatus*/);
		break;
	}
	case ADD_STATUS_TO_PAGE:
	{
		int indexFansPage = askForFansPageDetails();
		faceBook.getFansPageArrary().getPageByIndex(indexFansPage).addStatus(/*createStatus*/);
	}
	case PRINT_STATUSES_MEMBER:
	{
		int indexMember = askForMemberDetails;
		faceBook.getMemberArray().getMemberByIndex(indexMember).showAllStatus();

		break;
	}
	case PRINT_STATUSES_PAGE:
	{
		int indexFansPage = askForFansPageDetails();
		faceBook.getFansPageArrary().getPageByIndex(indexFansPage).showAllStatus;

		break;
	}
	case PRINT_TEN_STATUSES:
	{
		int indexMember = askForMemberDetails;
		faceBook.getMemberArray().getMemberByIndex(indexMember).showLatest10thStatus();

		break;
	}
	case FRIENDSHIP:
	{

	}
	case CANCAL_FRIENDSHIP:
	{

	}
	case ADD_FAN_TO_PAGE:
	{
		int indexMember = askForMemberDetails();
		int indexFansPage = askForFansPageDetails();

		faceBook.getFansPageArrary().getPageByIndex(indexFansPage).addFriend(faceBook.getMemberArray().getMemberByIndex(indexMember)); //מכניס את השם הנבחר לפונקציה הוסף חבר בדף אוהדים

		break;
	}
	case REMOVE_FAN_FROM_PAGE:
	{
		int indexMember = askForMemberDetails();
		int indexFansPage = askForFansPageDetails();

		faceBook.getFansPageArrary().getPageByIndex(indexFansPage).deleteFriend(memberName);

		//לבדוק למה בפונקציה מחיקה בדף אוהדים מקבלים שם ובפונקציית הוספת חבר מקבלים ממבר
		break;
	}
	case PRINT_FACEBOOK_MEMBERS:
	{
		faceBook.getMemberArray().showAllMembers();
		break;
	}

	case PRINT_FRIENDS_OF_MEMBER:
	{
		int indexMember = askForMemberDetails();
		faceBook.getMemberArray().getMemberByIndex(indexMember).showAllFriend();

		break;
	}
	case PRINT_FRIENDS_OF_PAGE:
	{
		int indexFansPage = askForFansPageDetails();
		faceBook.getFansPageArrary().getPageByIndex(indexFansPage).showAllFriends();

		break;
	}
	case EXIT:
	{

	}
	}

}

int ConsoleUI::printMenu()
{
	int choice;

	cout << "Please enter your choice from the menu:" << endl
	//	<< "1- Add member" << endl
	//	<< "2- Add fans page" << endl
	//להוסיף	<< "3- Add status to member" << endl
	//להוסיף	<< "4- Add status to fans page" << endl
	//	<< "5- Displaying all the statuses of a member" << endl
	//	<< "6- Displaying all the statuses of a fan page" << endl
	//	<< "7- Displaying the 10 most recent statuses of a certain member's friends" << endl
		<< "8- Friendship link between two friends" << endl
		<< "9- Cancellation of membership between two members" << endl
	//	<< "10- Adding a fan to the page" << endl
	//	<< "11- Removing a fan from page" << endl
	//	<< "12- Displaying all members registered to faceBook" << endl
	//	<< "13- Showing all the friends of a certain member" << endl
	//	<< "14- Showing all the the fans of a certain page" << endl
		<< "15-Exit" << endl;

	cin >> choice;
	return choice;
}

int ConsoleUI::askForMemberDetails()
{
	char* memberName;

	cout << "Enter the member's name: ";
	cin.getline() >> memberName >> endl;

	return (faceBook.getMemberArray().findMemberByName(memberName));
}

int ConsoleUI::askForFansPageDetails()
{
	char* fansPageName;

	cout << "Enter the fansPage's name: ";
	cin.getline() >> fansPageName >> endl;

	return (faceBook.getFansPageArrary().findPage(fansPageName));
}
