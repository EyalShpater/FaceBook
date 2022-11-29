#ifndef __BILLBOARD_H
#define __BILLBOARD_H

class Status;

class Billboard 
{
    const Status** theStatus; 
    int logSize;
    int physSize;

public:
    Billboard();
    ~Billboard();
   
    int getLogSize() const { return logSize; }
    int getPhysSize() const { return physSize; }

    void push(const char* text);
    void showAllStatus() const; 
    void showLatestNumOfStatus(int num) const; 
   
private:
    Billboard(const Billboard&);
    void reserve();
    void myRealloc(int newSize);
};


#endif // __BILLBOARD_H