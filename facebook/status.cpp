#pragma warning (disable:4996)

#include "status.h"

#include <iostream>
using namespace std;

Status::Status(const char* text)
{
	this->text = strdup(text);
}


Status::~Status()
{
	delete[]text;
}

void Status::show() const
{
	cout << text << endl;
	cout << "published on: ";
	theDate.show();
	theTime.show();
}