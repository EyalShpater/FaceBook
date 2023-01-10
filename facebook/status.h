#ifndef __STATUS_H
#define __STATUS_H

#include "date.h"
#include "time.h"
#include "statusException.h"

#include <iostream>
#include <string>

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
    std::string text;

public:
    Status(const std::string& text, eColor color = eColor::BLACK_AND_WHITE, eSoftware software = eSoftware::SIMPLE) noexcept(false);
    virtual ~Status() {} // support polymorphism

    const char* openWith() const { return (software == Status::eSoftware::SIMPLE ? "simple" : "playback"); }

    virtual bool operator==(const Status& other) const;
    virtual bool operator!=(const Status& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Status& s);

protected:
    virtual void toOs(std::ostream& os) const {}
};

#endif //__STATUS_H