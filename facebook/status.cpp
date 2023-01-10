#pragma warning (disable:4996)

#include "status.h"
#include "statusException.h"

#include <iostream>
#include <string>
using namespace std;

Status::Status(const string& text, Status::eColor color, Status::eSoftware software) noexcept(false)
{
	if (text == "")
		throw EmptyTextException();

	this->color = color;
	this->software = software;
	this->text = text;
}

/********* Operators *********/

ostream& operator<<(ostream& os, const Status& s)
{
	s.toOs(os);

	os << s.text << endl << endl;
	os << "published on: " << s.theDate << ", " << s.theTime << endl;
	os << "This status is printed in " 
		<< (s.color == Status::eColor::BLACK_AND_WHITE ? "Black & White" : "Coloful") << endl;
	os << "This status is shown using a "
		<< s.openWith() << " program";

	return os;
}

bool Status::operator==(const Status& other) const
{
	return text == other.text;
}

bool Status::operator!=(const Status& other) const
{
	return !(*this == other);
}