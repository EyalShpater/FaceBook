#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "user.h"
#include "status.h"
#include "userException.h"

#include <vector>
#include <string>

class Member;

class FansPage : public User 
{
public:
    const std::string& getName() const { return name; }
    int getNumOfFans() const { return getNumOfConnectedMembers(); }

    bool operator>(const FansPage& other)const;
    bool operator>(const Member& other) const;
    const FansPage& operator+=(Member& newFriend);

    void addStatus(const std::string& newStatus, int type, const std::string& filePath = "") noexcept(false);
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