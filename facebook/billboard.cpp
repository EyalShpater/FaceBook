#include "billboard.h"

#include <iostream>
using namespace std;

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;

Billboard::Billboard()
{
	physSize = DEFAULT_PHYS_SIZE;
	logSize = DEFAULT_LOG_SIZE;
	theStatus = new Status*[physSize];
}

Billboard::~Billboard()
{

}

void Billboard::push(const Status& status)
{

}

void Billboard::showAllStatus() const
{

}

void Billboard::showLatest10thStatus() const
{

}