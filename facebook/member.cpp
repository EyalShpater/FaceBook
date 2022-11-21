#pragma warning (disable:4996)

#include "member.h"

#include <iostream>
using namespace std;

Member::Member(const char* name, const Date& birthDate) : dateOfBirth(birthDate)
{
	this->name = strdup(name);
}

Member::~Member()
{
	delete[]name;
}