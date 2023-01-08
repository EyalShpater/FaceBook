#pragma warning (disable:4996)
#include "imageStatus.h"

#include <iostream>
#include <string>
using namespace std;

/********* Show *********/

void ImageStatus::toOs(ostream& os) const
{
	string command = "start " + filePath;

	system(command.c_str());
}

/******** Operators *******/

bool ImageStatus::operator==(const ImageStatus& other)const
{
	return filePath == other.filePath;
}

bool ImageStatus::operator!=(const ImageStatus& other)const
{
	return !(filePath == other.filePath);
}

bool ImageStatus::operator==(const Status& other) const
{
	const ImageStatus* temp = dynamic_cast<const ImageStatus*>(&other);

	if (temp)
		return filePath == temp->filePath;

	return false;
}

bool ImageStatus::operator!=(const Status& other) const
{
	return !(*this == other);
}