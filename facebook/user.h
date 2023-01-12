#ifndef __USER_H
#define __USER_H

#include <vector>
#include <string>
#include <iostream>

class Status;
class Member;

class User
{
protected:
    std::string name;
    std::vector<Status*> theBillboard;
    std::vector<Member*> connectedMembers;

public:
    User(const std::string& name) noexcept(false); 
    virtual ~User() {}

    const std::string& getName() const { return name; }
    int getNumOfConnectedMembers() const { return connectedMembers.size(); }

    friend std::ostream& operator<<(std::ostream& os, const User& u);

    void addStatus(const std::string& newStatus, int type, const std::string& filePath = "") noexcept(false);

    void showAllStatus() const;
    void showAllConnectedMembers() const;

    friend std::vector<User*>::iterator findUserIteratorByName(const std::string& name, std::vector<User*>& allUsers) noexcept(false);
    friend std::vector<User*>::const_iterator findUserIteratorByName(const std::string& name, const std::vector<User*>& allUsers) noexcept(false);
    friend User* findUserByName(const std::string& name, std::vector<User*>& allUsers);
    friend const User* findUserByName(const std::string& name, const std::vector<User*>& allUsers);

protected:
    User(const User&); // block cpoy c'tor
    User& operator=(const User&); // block operator =

    virtual void toOs(std::ostream& os) const {}
    void myMembersRealloc();
    void myStatusRealloc();
};

#endif // __USER_H
