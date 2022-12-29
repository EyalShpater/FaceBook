#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "status.h"
#include "userException.h"

#include <vector>
#include <string>

class Member;

class FansPage 
{
    std::string name;
    std::vector<Status*> theBillboard;
    std::vector<Member*> members;

public:
    FansPage(const std::string& name) noexcept(false)
        : name(name) { if (name == "") throw EmptyNameException(); }
    ~FansPage();
   
    const std::string& getName() const { return name; }
    int getNumOfFans() const { return members.size(); }

    bool operator>(const FansPage& other)const;
    bool operator>(const Member& other) const;
    const FansPage& operator+=(Member& newFriend);
    friend std::ostream& operator<<(std::ostream& os, const FansPage& f);

    void addStatus(const std::string& newStatus) noexcept(false);
    void deleteFriend(Member& other) noexcept(false); 

    void showAllStatus() const;
    void showAllFans() const;

    friend std::vector<FansPage*>::iterator findFansPageIteratorByName(const std::string& name, std::vector<FansPage*>& allFansPage) noexcept(false);
    friend std::vector<FansPage*>::const_iterator findFansPageIteratorByName(const std::string& name, const std::vector<FansPage*>& allFansPage) noexcept(false);
    friend FansPage* findFansPageByName(const std::string& name, std::vector<FansPage*>& allFansPage);
    friend const FansPage* findFansPageByName(const std::string& name, const std::vector<FansPage*>& allFansPage);
    
private:
    FansPage(const FansPage&);
    const FansPage& operator=(const FansPage&);

    void myMembersRealloc();
    void myStatusRealloc();
};

#endif // __FANSPAGE_H