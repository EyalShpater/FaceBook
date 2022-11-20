#ifndef __BILLBOARD_H
#define __BILLBOARD_H

class Status;

class Billboard {
    Status** theStatus; 
    int logSize;
    int physSize;

public:
    Billboard();
};


#endif // __BILLBOARD_H