#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include <vector>
#include <string>
#include <list>
#include "status.h"

class Member;

class FansPage 
{
    std::string name;
    std::vector<Status> theBillboard;
    std::vector<Member*> members;

public:
    FansPage(const std::string& name) : name(name) {}
   
    const std::string& getName() const { return name; }
    int getNumOfFans() const { return members.size(); }

    bool operator>(const FansPage& other)const;
    bool operator>(const Member& other) const;
    const FansPage& operator+=(Member& newFriend);
    friend std::ostream& operator<<(std::ostream& os, const FansPage& f);

    void addStatus(const std::string& newStatus);
    void deleteFriend(Member& other);

    void showAllStatus() const;
    void showAllFans() const;

    // This function returns iterator to the FansPage adress in allMembers if found, 
    // else returns the last place in the vector.
    friend std::vector<FansPage*>::iterator findFansPageIteratorByName(const std::string& name, std::vector<FansPage*>& allFansPage);
    friend std::list<FansPage>::iterator findFansPageIteratorByName(const std::string& name, std::list<FansPage>& allFansPage);
    friend std::vector<FansPage*>::const_iterator findFansPageIteratorByName(const std::string& name, const std::vector<FansPage*>& allFansPage);

    friend FansPage* findFansPageByName(const std::string& name, std::vector<FansPage*>& allFansPage);
    friend FansPage* findFansPageByName(const std::string& name, std::list<FansPage>& allFansPage);
    friend const FansPage* findFansPageByName(const std::string& name, const std::vector<FansPage*>& allFansPage);
    
private:
    FansPage(const FansPage&);
};

#endif // __FANSPAGE_H