#include "fansPageArray.h"
#include "fansPage.h"

const int DEFAULT_PHYS_SIZE = 2;
const int DEFAULT_LOG_SIZE = 0;

FansPageArray::FansPageArray()
{
	physSize = DEFAULT_PHYS_SIZE;
	logSize = DEFAULT_LOG_SIZE;
	theFansPageArray = new FansPage* [physSize];
}

