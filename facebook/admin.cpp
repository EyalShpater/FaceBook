#include "admin.h"
#include "member.h"
#include "fansPage.h"
#include "date.h"
#include "status.h"

Admin::~Admin()
{
	for (int i = 0; i < allMembers.getLogSize(); i++)
		delete &(allMembers.getIndexMember(i));

	for (int i = 0; i < allPages.getLogSize(); i++)
		delete &(allPages.getPageByIndex(i));
}

/*
void Admin::menu()
{

}*/

void Admin::addFriend(const char* name, const Date& date)
{
	Member* newMember = new Member(name, date);
	allMembers.push(*newMember);
}

void Admin::addFansPage(const char* name)
{
	FansPage* newFansPage = new FansPage(name);
	allPages.push(*newFansPage);
}

void Admin::showAllMembers() const
{
	allMembers.showAllMembers();
}

void Admin::showAllFansPages() const
{
	allPages.showAllPages();
}

void Admin::addNewStatus(Member& theMember, const char* newStatus)
{
	theMember.addStatusToBillboard(newStatus);
}

void Admin::addNewStatus(FansPage& theFansPage, const char* newStatus)
{
	theFansPage.addStatus(newStatus);
}