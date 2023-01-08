#pragma warning (disable:4996)

#include "status.h"

#include <iostream>
#include <string>
using namespace std;

/********* Show *********/

ostream& operator<<(ostream& os, const Status& s)
{
	s.toOs(os);

	os << "published on: " << s.theDate << ", " << s.theTime << endl;
	os << "This status is printed in " 
		<< (s.color == Status::eColor::BLACK_AND_WHITE ? "Black & White" : "Coloful") << endl;
	os << "This status is shown using a "
		<< s.openWith() << " program";

	return os;
}