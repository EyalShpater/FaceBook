#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"
#include "userException.h"

#include <iostream>
using namespace std;

const char* DEFAULT_SYSTEM_FILE_NAME = "system.bin";

/********* Constructor **********/

Admin::Admin()
{
	ifstream inFile(DEFAULT_SYSTEM_FILE_NAME, ios::binary);

	if (inFile.is_open())
	{
		load(inFile);
		inFile.close();
	}
	else
	{
		addDefaultMembers();
	}
}

Admin::~Admin()
{
	vector<Member*>::iterator mItr = allMembers.begin();
	vector<Member*>::iterator mItrEnd = allMembers.end();
	vector<FansPage*>::iterator pItr = allPages.begin();
	vector<FansPage*>::iterator pItrEnd = allPages.end();

	ofstream outFile(DEFAULT_SYSTEM_FILE_NAME, ios::binary);
	save(outFile);
	outFile.close();

	for (; mItr != mItrEnd; ++mItr)
		delete *mItr;
	
	for (; pItr != pItrEnd; ++pItr)
		delete *pItr;
}

/********* Add and Connect functions *********/

void Admin::addFriend(const string& name, const Date& date) noexcept(false)
{
	bool isValid = findUserByName(name, allMembers) == nullptr;
	
	if(!isValid)
		throw ExistException(name);

	myMemberRealloc();
	allMembers.push_back(new Member(name, date));
}

void Admin::addFansPage(const string& name) noexcept(false)
{
	bool isValid = findUserByName(name, allPages) == nullptr;
	
	if (!isValid)
		throw ExistException(name);

	myFansPageRealloc();
	allPages.push_back(new FansPage(name));
}

void Admin::addNewStatusToMember(const string& name, const string& newStatus, int type, const string& filePath) noexcept(false)
{
	Member* curr = (Member*)findUserByName(name, allMembers);

	if (curr == nullptr)
		throw NotExistException(name);

	curr->addStatus(newStatus, type, filePath);
}

void Admin::addNewStatusToFansPage(const string& name, const string& newStatus, int type, const string& filePath) noexcept(false)
{
	FansPage* curr = (FansPage*)findUserByName(name, allPages);

	if (curr == nullptr)
		throw NotExistException(name);

	curr->addStatus(newStatus, type, filePath); 
}

void Admin::makeFriendship(const string& nameFirst, const string& nameSecond) noexcept(false)
{
	Member* member1 = (Member*)findUserByName(nameFirst, allMembers);
	Member* member2 = (Member*)findUserByName(nameSecond, allMembers);

	if (member1 == nullptr) 
		throw NotExistException(nameFirst);

	if (member2 == nullptr)
		throw NotExistException(nameSecond);

	*member1 += *member2;
}

void Admin::addFanToPage(const string& member, const string& page) noexcept(false)
{
	Member* mCurr = (Member*)findUserByName(member, allMembers);
	FansPage* pCurr = (FansPage*)findUserByName(page, allPages);

	if(mCurr == nullptr)
		throw NotExistException(member);
	if(pCurr == nullptr)
		throw NotExistException(page);
	
	*pCurr += *mCurr;
}

/********* Disconnect functions *********/

void Admin::removeFanFromPage(const string& member, const string& page) noexcept(false)
{
	Member* mCurr = (Member*)findUserByName(member, allMembers);
	FansPage* pCurr = (FansPage*)findUserByName(page, allPages);

	if (mCurr == nullptr) 
		throw NotExistException(member);

	if (pCurr == nullptr)
		throw NotExistException(page);

	mCurr->dislikePage(*pCurr);
}

void Admin::cancelFriendship(const string& nameFirst, const string& nameSecond) noexcept(false)
{
	Member* member1 = (Member*)findUserByName(nameFirst, allMembers);
	Member* member2 = (Member*)findUserByName(nameSecond, allMembers);

	if (member1 == nullptr) 
		throw NotExistException(nameFirst);

	if (member2 == nullptr)
		throw NotExistException(nameSecond);

	member1->cancelFriendship(*member2);
}

/********* Show functions *********/

void Admin::showAllUsers() const
{
	showAllMembers();
	cout << endl;
	showAllFansPages();
}

void Admin::showAllMembers() const 
{
	vector<Member*>::const_iterator itr = allMembers.begin();
	vector<Member*>::const_iterator itrEnd = allMembers.end();

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
}

void Admin::showAllFansPages() const
{
	vector<FansPage*>::const_iterator itr = allPages.begin();
	vector<FansPage*>::const_iterator itrEnd = allPages.end();

	for (; itr != itrEnd; ++itr)
		cout << *(*itr) << endl << endl;
}

void Admin::showAllMemberFriends(const string& name) const noexcept(false)
{
	const Member* member = (const Member*)findUserByName(name, allMembers);

	if (member == nullptr)
		throw NotExistException(name);
	
	member->showAllConnectedMembers();
}

void Admin::showAllFansPageFans(const string& name) const noexcept(false)
{
	const FansPage* fansPage = (const FansPage*)findUserByName(name, allPages);

	if (fansPage == nullptr)
		throw NotExistException(name);

	fansPage->showAllConnectedMembers();
}

void Admin::showAllMemberStatuses(const string& name) const noexcept(false)
{
	const Member* member = (const Member*)findUserByName(name, allMembers);

	if (member == nullptr)
		throw NotExistException(name);

	member->showAllStatus();
}

void Admin::showAllFansPageStatuses(const string& name) const
{
	const FansPage* fansPage = (const FansPage*)findUserByName(name, allPages);

	if (fansPage == nullptr)
		throw NotExistException(name);

	fansPage->showAllStatus();
}

void Admin::showUpdatedFriendsStatuses(const string& name) const noexcept(false)
{
	const Member* member = (const Member*)findUserByName(name, allMembers);

	if (member == nullptr)
		throw NotExistException(name);

	member->showUpdatedFriendsStatuses();
}

/********* File Functions *********/

void Admin::save(std::ofstream& outFile) const
{
	auto itr = allMembers.begin();
	auto itrEnd = allMembers.end();

	saveAllMembers(outFile);
	saveAllPages(outFile);

	for (; itr != itrEnd; ++itr)
		(*itr)->saveAllFansPages(outFile);
}

void Admin::saveAllMembers(ofstream& outFile) const // doesn't save the fansPages array.
{
	auto itr = allMembers.begin();
	auto itrEnd = allMembers.end();
	int size = allMembers.size();

	outFile.write((const char*)&size, sizeof(size));
	for (; itr != itrEnd; ++itr) 
	{
		(*itr)->save(outFile);
		(*itr)->saveBillBoard(outFile);
	}

	for (itr = allMembers.begin(); itr != itrEnd; ++itr)
		(*itr)->saveConnectedMembers(outFile);

}

// Assumption: Members are saved before this function.
void Admin::saveAllPages(ofstream& outFile) const
{
	auto itr = allPages.begin();
	auto itrEnd = allPages.end();
	int size = allPages.size();

	outFile.write((const char*)&size, sizeof(size));
	for (; itr != itrEnd; ++itr)
	{
		(*itr)->save(outFile);
		(*itr)->saveBillBoard(outFile);
		(*itr)->saveConnectedMembers(outFile);
	}
}

void Admin::load(ifstream& inFile) 
{
	auto itr = allMembers.begin();
	auto itrEnd = allMembers.end();

	readAllMembers(inFile);
	readAllPages(inFile);

	for (; itr != itrEnd; ++itr)
		readAllFansPagesToMember(inFile, *(*itr));
}

void Admin::readAllMembers(ifstream& inFile) 
{
	int allMembersSize;
	inFile.read((char*)&allMembersSize, sizeof(allMembersSize));

	allMembers.reserve(allMembersSize);

	for (int i = 0; i < allMembersSize; i++)
	{
		allMembers.push_back(new Member(inFile));
		allMembers[i]->readBillBoard(inFile);
	}

	for (int i = 0; i < allMembersSize; i++)
		readConnectedMembers(inFile, *(allMembers[i]));

}

void Admin::readConnectedMembers(ifstream& inFile, User& member)
{
	int size;
	string name;
	inFile.read((char*)&size, sizeof(size));
	member.connectedMembers.reserve(size);

	for (int i = 0; i < size; i++)
	{
		Status::readString(inFile, name);
		member.connectedMembers.push_back((Member*)findUserByName(name, allMembers));
	}
}

void Admin::readAllFansPagesToMember(ifstream& inFile, Member& member)
{
	int size;
	string name;

	inFile.read((char*)&size, sizeof(size));
	member.fansPages.reserve(size);

	for (int i = 1; i <= size; ++i)
	{
		Status::readString(inFile, name);
		member.fansPages.push_back((FansPage*)findUserByName(name, allMembers));
	}
}

void Admin::readAllPages(ifstream& inFile) 
{
	int size;
	string name;

	inFile.read((char*)&size, sizeof(size));
	allPages.reserve(size);

	for (int i = 0; i < size; i++)
	{
		allPages.push_back(new FansPage(inFile));
		allPages[i]->readBillBoard(inFile);
		readConnectedMembers(inFile, *(allPages[i]));
	}
}

/********* Utilities functions *********/

void Admin::addDefaultMembers()
{
	addFansPage("MTA College");
	addFansPage("Computer Science");
	addFansPage("Coming From Love");

	addFriend("Nitzan Sde Or", Date(24, 8, 1998));
	addFriend("Eyal Shpater", Date(26, 10, 1998));
	addFriend("Noa Kirel", Date(10, 4, 2001));
	addFriend("Yehudit Ravitz", Date(29, 12, 1956));

	makeFriendship("Eyal Shpater", "Nitzan Sde Or");
	makeFriendship("Noa Kirel", "Nitzan Sde Or");
	makeFriendship("Noa Kirel", "Nitzan Sde Or");
	makeFriendship("Yehudit Ravitz", "Eyal Shpater");

	addFanToPage("Eyal Shpater", "MTA College");
	addFanToPage("Nitzan Sde Or", "MTA College");
	addFanToPage("Noa Kirel", "Coming From Love");
	addFanToPage("Nitzan Sde Or", "Computer Science");
	addFanToPage("Yehudit Ravitz", "Coming From Love");

	addNewStatusToMember("Nitzan Sde Or", "N for Nadir", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Nitzan Sde Or", "Hello World!", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Nitzan Sde Or", "1 2 3 check 1 2 3", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Nitzan Sde Or", "lol :)))", (int)Status::eStatusType::IMAGE, "media\\status1.jpg");

	addNewStatusToMember("Eyal Shpater", "Hello it's me.", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Eyal Shpater", "I was wondering...", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Eyal Shpater", "If after all these years you'd like to meet?", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Eyal Shpater", "lol :)))", (int)Status::eStatusType::VIDEO, "media\\status4.mp4");

	addNewStatusToMember("Noa Kirel", "la la la la la", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Noa Kirel", "Noa Kila keep it reala", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Noa Kirel", "The funniest picture!", (int)Status::eStatusType::IMAGE, "media\\status2.jpeg");
	addNewStatusToMember("Noa Kirel", "so cute!", (int)Status::eStatusType::IMAGE, "media\\status3.png");

	addNewStatusToMember("Yehudit Ravitz", "I don't want to sing on stage again.", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Yehudit Ravitz", "Do you know any song include black gold?", (int)Status::eStatusType::TEXT);
	addNewStatusToMember("Yehudit Ravitz", "I don't understand how you can be sad, when you are the most beautiful girl", (int)Status::eStatusType::TEXT);

	addNewStatusToFansPage("MTA College", "Welcome all new students!", (int)Status::eStatusType::TEXT);
	addNewStatusToFansPage("MTA College", "If you want to pass you have to get at least 60 points.", (int)Status::eStatusType::TEXT);

	addNewStatusToFansPage("Coming From Love", "Peace and Love", (int)Status::eStatusType::TEXT);
	addNewStatusToFansPage("Coming From Love", "Maybe one day she would taste the taste of love...", (int)Status::eStatusType::TEXT);

	addNewStatusToFansPage("Computer Science", "C Plus Plus", (int)Status::eStatusType::TEXT);
	addNewStatusToFansPage("Computer Science", "Java Script", (int)Status::eStatusType::TEXT);
}

void Admin::myMemberRealloc()
{
	int logSize = allMembers.size();
	int physSize = allMembers.capacity();

	if (logSize == physSize)
		allMembers.reserve(physSize * 2);
}

void Admin::myFansPageRealloc()
{
	int logSize = allPages.size();
	int physSize = allPages.capacity();

	if (logSize == physSize)
		allPages.reserve(physSize * 2);
}