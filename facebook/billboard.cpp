#include "billboard.h"
#include "status.h"

#include <iostream>
using namespace std;

/********* Static variables declaration *********/

const int Billboard::DEFAULT_PHYS_SIZE = 2;
const int Billboard::DEFAULT_LOG_SIZE = 0;

/********* Constructors *********/

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

/********* Array functions *********/

void Billboard::push(const char* text)
{
	reserve();
	theStatus[logSize] = new Status(text);
	logSize++;
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
	const Status** temp = new const Status * [newSize];

	for (int i = 0; i < logSize; i++) // Assumption: logSize < newSize
		temp[i] = theStatus[i];

	delete[]theStatus;

	theStatus = temp;
}

/********* Show *********/

void Billboard::showAllStatus() const
{
	for (int i = logSize - 1; i >= 0; i--)
	{
		theStatus[i]->show();
		cout << endl;
	}
}

void Billboard::showLatestNumOfStatus(int num) const
{
	for (int i = 1; i <= logSize && i <= num; i++)
	{
		theStatus[logSize - i]->show();
		cout << endl;
	}
}