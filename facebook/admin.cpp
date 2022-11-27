#include "admin.h"
#include "member.h"
#include "fansPage.h"

Admin::Admin()
{

}

Admin::~Admin()
{

}

void Admin::menu()
{

}

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

