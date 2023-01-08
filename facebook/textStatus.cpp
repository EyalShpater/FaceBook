#pragma warning (disable:4996)

#include "textStatus.h"

#include <iostream>
#include <string>
using namespace std;

/********* Show *********/

void TextStatus::toOs(ostream& os) const
{
	os << text << endl << endl;
}

/******** Operators *******/

bool TextStatus::operator==(const TextStatus& other)const
{
	return text == other.text;
}

bool TextStatus::operator!=(const TextStatus& other)const
{
	return !(text == other.text);
}

bool TextStatus::operator==(const Status& other) const
{
	const TextStatus* temp = dynamic_cast<const TextStatus*>(&other);

	if (temp)
		return text == temp->text;
	
	return false;
}

bool TextStatus::operator!=(const Status& other) const
{
	return !(*this == other);
}