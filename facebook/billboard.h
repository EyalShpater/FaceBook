#ifndef __BILLBOARD_H
#define __BILLBOARD_H

class Status;

class Billboard {
    Status** theStatus; 
    int logSize;
    int physSize;

public:
    Billboard();
    // add d'tor

    /*****  functions  ******/

    /* 
    push() //add Status to last place
    showAllStatus()
    showLatest10thStatus()
    size() //return logSize
    capacity() //return physSize
    reserve(int n) //make the array bigger ig log=phys
    */

    //we need to delete copy c'tor

};


#endif // __BILLBOARD_H