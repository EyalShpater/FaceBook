#pragma warning (disable:4996)

#include "status.h"
#include "statusException.h"

#include <iostream>
#include <string>
using namespace std;

/********* Constructors *********/

Status::Status(const string& text, Status::eColor color, Status::eSoftware software) noexcept(false)
{
	if (text == "")
		throw EmptyTextException();

	this->color = color;
	this->software = software;
	this->text = text;
}

Status::Status(ifstream& in) : theDate(in), theTime(in)
{
	in.read((char*)&color, sizeof(color));
	in.read((char*)&software, sizeof(software));
	readString(in, text);
}

/********* File Functions *********/

void Status::save(ofstream& out) const
{
	theDate.save(out);
	theTime.save(out);
	out.write((const char*)&color, sizeof(color));
	out.write((const char*)&software, sizeof(software));
	saveString(out, text);
}

void Status::saveType(std::ofstream& out) const
{
	char type;
	type = typeid(*this).name()[6]; //get the first character of the class name.
	out.write((const char*)&type, sizeof(type));
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

/********* Utility Functions *********/

void Status::saveString(ofstream& out, const string& str)
{
	int sizeOfString = str.size();

	out.write((const char*)&sizeOfString, sizeof(sizeOfString));
	out.write(str.c_str(), str.size());
}

void Status::readString(ifstream& in, string& str)
{
	int size;
	in.read((char*)&size, sizeof(size));
	
	char* temp = new char[size + 1]; // for '\0'
	in.read(temp, size);
	temp[size] = '\0';
	str = temp;

	delete[]temp;
}
