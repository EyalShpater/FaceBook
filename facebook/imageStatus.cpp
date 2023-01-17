#pragma warning (disable:4996)
#include "imageStatus.h"

#include <iostream>
#include <string>
using namespace std;

/**********/

ImageStatus::ImageStatus(const string& text, const string& filePath) noexcept(false)
	: filePath(filePath), Status(text, eColor::COLORS, eSoftware::PLAYBACK)
{
	if (filePath == "") throw EmptyTextException();
}

ImageStatus::ImageStatus(ifstream& inFile) : Status(inFile)
{
	readString(inFile, filePath);
}

/********* Show *********/

void ImageStatus::toOs(ostream& os) const
{
	string command = "start " + filePath;

	system(command.c_str());
}

/******/

void ImageStatus::save(std::ofstream& outFile) const
{
	Status::save(outFile);
	saveString(outFile, filePath);
}

/******** Operators *******/

bool ImageStatus::operator==(const Status& other) const
{
	if (Status::operator!=(other))
		return false;

	const ImageStatus* temp = dynamic_cast<const ImageStatus*>(&other);
	if (temp)
		return filePath == temp->filePath;
	return false;
}

bool ImageStatus::operator!=(const Status& other) const
{
	return !(*this == other);
}