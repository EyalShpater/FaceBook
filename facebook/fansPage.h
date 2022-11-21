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

    void addStatus(const Status& newStatus);
    void showAllStatus() const;
    void addFriend(const Member& newFriend);
    
private:
    FansPage(const FansPage&);
};


#endif // __FANSPAGE_H