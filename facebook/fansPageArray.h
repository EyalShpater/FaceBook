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

	void push(const Status& status);
	void showAllStatus() const;
	void showLatest10thStatus() const;
	void pop(const char* name);
	int findPage(const char* name);

private:
	FansPageArray(const FansPageArray&);
	void reserve();
};

#endif // __FANSPAGEARRAY_H