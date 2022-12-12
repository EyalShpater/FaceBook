#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "memberArray.h"
#include "billboard.h"


class FansPage 
{
    const char* name;
    Billboard theBillboard; 
    MemberArray members;

public:
    FansPage(const char* name);
    ~FansPage();

    const char* getName() const { return name; }

    bool operator>(const FansPage& other)const;
    const FansPage& operator+=(Member& newFriend);

    void addStatus(const char* newStatus);
    void deleteFriend(Member& other);

    void showAllStatus() const;
    void showAllFans() const;
    void show() const;

private:
    FansPage(const FansPage&);
};

#endif // __FANSPAGE_H