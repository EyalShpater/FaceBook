#ifndef __FANSPAGEARRAY_H
#define __FANSPAGEARRAY_H

class FansPage;

class FansPageArray
{
public:
	static const int NOT_FOUND;
	static const int DEFAULT_PHYS_SIZE;
	static const int DEFAULT_LOG_SIZE;
	static const int EQUAL;

private:
	FansPage** theFansPageArray; 
	int logSize;
	int physSize;

public:
	FansPageArray();
	~FansPageArray();

	int getLogSize() const { return logSize; }
	int getPhysSize() const { return physSize; }
	FansPage& getPageByIndex(int index) { return *(theFansPageArray[index]); }
	const FansPage& getPageByIndex(int index) const { return *(theFansPageArray[index]); }

	void push(FansPage& newFansPage);
	void pop(FansPage& other);
	int findPageByName(const char* name) const;

	void showAllPages() const;

private:
	FansPageArray(const FansPageArray&);

	void reserve();
	void myRealloc(int newSize);
};

#endif // __FANSPAGEARRAY_H