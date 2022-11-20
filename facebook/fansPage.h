#ifndef __FANSPAGE_H
#define __FANSPAGE_H

class Member;
class Billboard;

class FansPage {
    char* name;
    Member** theMember; 
    int numOfMembers;
    int maxMembers;
    Billboard* theBillboard; 
   
};


#endif // __FANSPAGE_H