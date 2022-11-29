#include "fansPageArray.h"
#include "fansPage.h"

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;
const int NOT_FOUND = -1;
const int EQUAL = 0;

FansPageArray::FansPageArray()
{
	physSize = DEFAULT_PHYS_SIZE;
	logSize = DEFAULT_LOG_SIZE;
	theFansPageArray = new FansPage* [physSize];
}

FansPageArray::~FansPageArray()
{
	delete[]theFansPageArray;
}

void FansPageArray::push(FansPage& newFansPage)
{
	reserve();
	theFansPageArray[logSize] = &newFansPage;
	logSize++;
}

void FansPageArray::pop(FansPage& other)
{
	int index = findPage(other.getName());
	
	if (index != NOT_FOUND)
	{
		theFansPageArray[index] = theFansPageArray[logSize - 1];
		--logSize;
	}
}

int FansPageArray::findPage(const char* name) const
{
	int index = NOT_FOUND;

	for (int i = 0; i < logSize; i++)
		if (strcmp(theFansPageArray[i]->getName(), name) == EQUAL)
			index = i;

	return index;
}


void FansPageArray::reserve()
{
	if (logSize == physSize)
	{
		physSize *= 2;
		myRealloc(physSize);
	}
}

void FansPageArray::myRealloc(int newSize)
{
	FansPage** temp = new FansPage*[newSize];

	for (int i = 0; i < logSize; i++) // assumption: logSize < newSize
		temp[i] = theFansPageArray[i];  

	delete[]theFansPageArray;

	theFansPageArray = temp;
}

void FansPageArray::showAllPages() const
{
	for (int i = 0; i < logSize; i++)
	{
		theFansPageArray[i]->show();
		cout << endl;
	}
}
