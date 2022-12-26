#pragma warning (disable:4996)

#include "status.h"

#include <iostream>
#include <string>
using namespace std;

/********* Show *********/

std::ostream& operator<<(std::ostream& os, const Status& s)
{
	os << s.text << endl;
	os << "published on: " << s.theDate << ", " << s.theTime;

	return os;
}

/***************/

bool Status::operator==(const Status& other)const
{
	return text == other.text;
}

bool Status::operator!=(const Status& other)const
{
	return !(*this == other);
}