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

    /*****  functions  ******/

  /*
  push() //add Status to last place
  showAllStatus()
  showLatest10thStatus()
  size() //return logSize
  capacity() //return physSize
  reserve(int n) //make the array bigger ig log=phys
  */
};

#endif // __FANSPAGEARRAY_H