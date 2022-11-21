#ifndef __FANSPAGEARRAY_H
#define __FANSPAGEARRAY_H

class FansPage;

class FansPageArray
{
	const FansPage** theFansPageArray;
	int logSize;
	int physSize;

public:
	FansPageArray();
	~FansPageArray();

	int getLogSize() const { return logSize; }
	int getPhysSize() const { return physSize; }

	void push(const FansPage& newFansPage);
	void pop(const char* name);
	int findPage(const char* name);

private:
	FansPageArray(const FansPageArray&);
	void reserve();
	void myRealoc(int newSize);
};

#endif // __FANSPAGEARRAY_H