#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "memberArray.h"
#include "billboard.h"


class FansPage {
    char* name;
    Billboard theBillboard; 
    MemberArray members;
   
public:
    FansPage(const char* name);
    ~FansPage();

    const char* getName() const { return name; }

    void addStatus(const Status& newStatus);
    void addFriend(const Member& newFriend);
    void deleteFriend(const char* name);
    void showAllStatus() const;
    void showAllFriends() const;
    
private:
    FansPage(const FansPage&);
};


#endif // __FANSPAGE_H