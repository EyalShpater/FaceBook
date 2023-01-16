#ifndef __USER_H
#define __USER_H

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

#include "userException.h"

class Status;
class Member;

class User // abstract class
{
protected:
    std::string name;
    std::vector<Status*> theBillboard;
    std::vector<Member*> connectedMembers;

public:
    virtual ~User();

    const std::string& getName() const { return name; }
    int getNumOfConnectedMembers() const { return connectedMembers.size(); }

    friend std::ostream& operator<<(std::ostream& os, const User& u);

    void save(std::ofstream& outFile);
    void saveBillBoard(std::ofstream& outFile);
    void saveConnectedMembers(std::ofstream& outFile);

    void readBillBoard(std::ifstream& inFile);

    void addStatus(const std::string& newStatus, int type, const std::string& filePath = "") noexcept(false);

    void showAllStatus() const;
    void showAllConnectedMembers() const;

/*protected:*/ public:
    User(const std::string& name) noexcept(false); // make User abstract class
    User(std::ifstream& inFile);
    User(const User&); // block cpoy c'tor
    User& operator=(const User&); // block operator =

    virtual void toOs(std::ostream& os) const {}
    void myMembersRealloc();
    void myStatusRealloc();

public: // template friend functions (must be implement inside the class)

    /*
        T should have the following:
        iteraot, const_iterator, methods 'begin', 'end',
        the type inside should be a pointer of object that has 'getName' function.
    */
    template<class T>
    friend auto findUserIteratorByName(const std::string& name, T& allUsers) noexcept(false)
    {
        bool isFound = false;
        auto itr = allUsers.begin();
        auto itrEnd = allUsers.end();

        while (itr != itrEnd && !isFound)
        {
            if ((*itr)->getName() == name)
                isFound = true;
            else
                ++itr;
        }

        if (!isFound)
            throw NotExistException(name);

        return itr;
    }

    /*
        T should have the following:
        iteraot, const_iterator, methods 'begin', 'end',
        the type inside should be a pointer of object that has 'getName' function.
    */
    template <class T>
    friend void* findUserByName(const std::string& name, T& allUsers)
    {
        try
        {
            auto res = findUserIteratorByName(name, allUsers);
            return *res;
        }
        catch (NotExistException&)
        {
            return nullptr;
        }
    }
};

#endif // __USER_H