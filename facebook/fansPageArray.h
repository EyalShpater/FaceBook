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
	FansPage** getFansPage() const { return theFansPageArray; }
	int getNumOfFansPage() const { return logSize; }
};

#endif // __FANSPAGEARRAY_H