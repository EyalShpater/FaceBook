#ifndef __STATUS_H
#define __STATUS_H

#include <iostream>
#include <string>

#include "date.h"
#include "time.h"
#include "statusException.h"

class Status 
{
    const Date theDate;
    const Time theTime;
    std::string text;

public:
    Status(const std::string& text) : text(text) { if (text == "") throw EmptyTextException(); }

    friend std::ostream& operator<<(std::ostream& os, const Status& s);

    bool operator==(const Status& other)const;
    bool operator!=(const Status& other)const;

private:
    Status(const Status& other);
    const Status& operator=(const Status&);
};

#endif //__STATUS_H