#include "status.h"

#include <iostream>
using namespace std;

Status::Status(const char* text)
{
	this->text = strdup(text);
}

Status::Status(const Status& other)
{
	text = other.text;
}

Status::~Status()
{
	delete[]text;
}

void Status::show()
{
	cout << text << endl;
	cout << "published on:";
	theDate.show();
	theTime.show();
}