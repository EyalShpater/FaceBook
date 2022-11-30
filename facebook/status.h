#ifndef __STATUS_H
#define __STATUS_H

#include <iostream>
using namespace std;

#include "date.h"
#include "time.h"

class Status 
{
    const Date theDate;
    const Time theTime;
    char* text;

public:
    Status(const char* text);
    ~Status();

    void show() const;

private:
    Status(const Status& other);
};


#endif //__STATUS_H