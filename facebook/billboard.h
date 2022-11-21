#ifndef __BILLBOARD_H
#define __BILLBOARD_H

class Status;

class Billboard {
    Status** theStatus; 
    int logSize;
    int physSize;

public:
    Billboard();
    ~Billboard();
   
    int getLogSize() const { return logSize; }
    int getPhysSize() const { return physSize; }

    void push(const Status& status);
    void showAllStatus() const; 
    void showLatest10thStatus() const;
   

private:
    Billboard(const Billboard&);
    void reserve();
};


#endif // __BILLBOARD_H