#ifndef __STATUS_H
#define __STATUS_H

#include "date.h"
#include "time.h"
#include "statusException.h"

#include <iostream>

class Status 
{
public:
    enum class eColor { BLACK_AND_WHITE, COLORS };
    enum class eSoftware { SIMPLE, PLAYBACK };
    enum class eStatusType { TEXT, IMAGE, VIDEO };

protected:
    const Date theDate;
    const Time theTime;
    eColor color;
    eSoftware software;

public:
    Status(eColor color, eSoftware software) : color(color), software(software) {}
    ~Status() {}

    const char* openWith() const { return (software == Status::eSoftware::SIMPLE ? "simple" : "playback"); }

    virtual bool operator==(const Status& other) const = 0;
    virtual bool operator!=(const Status& other)const = 0;

    friend std::ostream& operator<<(std::ostream& os, const Status& s);

protected:
    virtual void toOs(std::ostream& os) const {}
};

#endif //__STATUS_H