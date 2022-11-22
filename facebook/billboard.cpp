#include "billboard.h"
#include "status.h"

#include <iostream>
using namespace std;

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;
const int DEFAULT_NUM_OF_STATUS_TO_SHOW = 10;

Billboard::Billboard()
{
	physSize = DEFAULT_PHYS_SIZE;
	logSize = DEFAULT_LOG_SIZE;
	theStatus = new Status*[physSize];
}

Billboard::~Billboard()
{
	delete[]theStatus;
}

void Billboard::push(Status& newStatus)
{
	reserve();
	theStatus[logSize] = &newStatus;
	logSize++;
}

void Billboard::showAllStatus() const
{
	for (int i = 0; i < logSize; i++)
		theStatus[i]->show();
}

void Billboard::showLatest10thStatus() const
{
	for (int i = 1; i <= DEFAULT_NUM_OF_STATUS_TO_SHOW && i < logSize; i++)
		theStatus[DEFAULT_NUM_OF_STATUS_TO_SHOW - i]->show();
}

void Billboard::reserve()
{
	if (logSize == physSize)
	{
		physSize *= 2;
		myRealloc(physSize);
	}
}

void Billboard::myRealloc(int newSize)
{
	Status** temp = new Status*[newSize];

	for (int i = 0; i < logSize; i++) // assumption: logSize < newSize
		temp[i] = theStatus[i];

	delete[]theStatus;

	theStatus = temp;
}