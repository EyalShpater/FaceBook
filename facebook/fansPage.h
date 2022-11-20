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

    /**** functions ******/

    //c'tor, d'tor
    // delete copy c'tor

    //addStatus 
    // showAllStatus
    //showLatest10thStatus
   
};


#endif // __FANSPAGE_H