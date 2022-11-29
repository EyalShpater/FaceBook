#ifndef __FANSPAGEARRAY_H
#define __FANSPAGEARRAY_H

class FansPage;

class FansPageArray
{
	FansPage** theFansPageArray; 
	int logSize;
	int physSize;

public:
	FansPageArray();
	~FansPageArray();

	int getLogSize() const { return logSize; }
	int getPhysSize() const { return physSize; }
	FansPage& getPageByIndex(int index) const { return *(theFansPageArray[index]); }

	void push(FansPage& newFansPage);
	void pop(FansPage& other);
	int findPage(const char* name) const;
	void showAllPages() const;

private:
	FansPageArray(const FansPageArray&);
	void reserve();
	void myRealloc(int newSize);
};

#endif // __FANSPAGEARRAY_H