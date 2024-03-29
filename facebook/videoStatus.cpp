#include "videoStatus.h"

#include <iostream>
#include <string>
using namespace std;

/********* Constructors *********/

VideoStatus::VideoStatus(const string& text, const string& filePath) noexcept(false)
	: filePath(filePath), Status(text, eColor::COLORS, eSoftware::PLAYBACK)
{
	if (filePath == "") throw EmptyTextException();
}

VideoStatus::VideoStatus(ifstream& inFile) : Status(inFile)
{
	readString(inFile, filePath);
}

/********* Show *********/

void VideoStatus::toOs(ostream& os) const
{
	string command = "start " + filePath;

	system(command.c_str());
}

/********* File Functions *********/

void VideoStatus::save(std::ofstream& outFile) const
{
	Status::save(outFile);
	saveString(outFile, filePath);
}

/******** Operators *******/

bool VideoStatus::operator==(const Status& other) const
{
	if (Status::operator!=(other))
		return false;

	const VideoStatus* temp = dynamic_cast<const VideoStatus*>(&other);
	if (temp)
		return filePath == temp->filePath;
	return false;
}

bool VideoStatus::operator!=(const Status& other) const
{
	return !(*this == other);
}