#ifndef __STATUS_H
#define __STATUS_H

#include "date.h"
#include "time.h"
#include "statusException.h"

#include <iostream>
#include <string>
#include <fstream>

class Status 
{
public:
    enum class eColor { BLACK_AND_WHITE, COLORS };
    enum class eSoftware { SIMPLE, PLAYBACK };
    enum class eStatusType { TEXT = 'S', IMAGE = 'I', VIDEO = 'V' };

protected:
    const Date theDate;
    const Time theTime;
    eColor color;
    eSoftware software;
    std::string text;

public:
    Status(const std::string& text, eColor color = eColor::BLACK_AND_WHITE, eSoftware software = eSoftware::SIMPLE) noexcept(false);
    Status(std::ifstream& in);
    virtual ~Status() {} // support polymorphism

    const char* openWith() const { return (software == Status::eSoftware::SIMPLE ? "simple" : "playback"); }

    virtual void save(std::ofstream& out) const;
    virtual void saveType(std::ofstream& out) const;

    virtual bool operator==(const Status& other) const;
    virtual bool operator!=(const Status& other) const;

    friend std::ostream& operator<<(std::ostream& os, const Status& s);

    static void saveString(std::ofstream& out, const std::string& str);
    static void readString(std::ifstream& in, std::string& str);

protected:
    virtual void toOs(std::ostream& os) const {}
};

#endif //__STATUS_H