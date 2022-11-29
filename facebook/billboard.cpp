#include "billboard.h"
#include "status.h"

#include <iostream>
using namespace std;

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;

Billboard::Billboard()
{
	physSize = DEFAULT_PHYS_SIZE;
	logSize = DEFAULT_LOG_SIZE;
	theStatus = new const Status*[physSize];
}

Billboard::~Billboard()
{
	for (int i = 0; i < logSize; i++)
		delete theStatus[i];

	delete[]theStatus;
}

void Billboard::push(const char* text)
{
	reserve();
	theStatus[logSize] = new Status(text);
	logSize++;
}

void Billboard::showAllStatus() const
{
	for (int i = 0; i < logSize; i++)
		theStatus[i]->show();
}

void Billboard::showLatestNumOfStatus(int num) const
{
	for (int i = 1; i <= logSize && i <= num; i++)
		theStatus[logSize - i]->show();
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
	const Status** temp = new const Status*[newSize];

	for (int i = 0; i < logSize; i++) // assumption: logSize < newSize
		temp[i] = theStatus[i];

	delete[]theStatus;

	theStatus = temp;
}