#ifndef __FANSPAGE_H
#define __FANSPAGE_H

#include "user.h"
#include "status.h"
#include "userException.h"

#include <string>

class Member;

class FansPage : public User 
{
public:
    FansPage(const std::string& name) noexcept(false) : User(name) {}

    bool operator>(const FansPage& other)const;
    bool operator>(const Member& other) const;
    const FansPage& operator+=(Member& newFriend);

    void deleteFriend(Member& other) noexcept(false); 
    
private:
    FansPage(const FansPage&);
    const FansPage& operator=(const FansPage&);
};

#endif // __FANSPAGE_H