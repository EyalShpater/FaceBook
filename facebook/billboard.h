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

    void push(Status& newStatus);
    void showAllStatus() const; 
    void showLatest10thStatus() const;
   
private:
    Billboard(const Billboard&);
    void reserve();
    void myRealloc(int newSize);
};


#endif // __BILLBOARD_H