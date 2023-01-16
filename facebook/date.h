#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <fstream>

class Date 
{
    int day, month, year;

public:
    Date();
    Date(int day, int month, int year) noexcept(false);
    Date(std::ifstream& in);

    int getDay()   const { return day; }
    int getMonth() const { return month; }
    int getYear()  const { return year; }

    void setDay(int day) noexcept(false);
    void setMonth(int month) noexcept(false);
    void setYear(int year) noexcept(false);

    void save(std::ofstream& out) const;

    friend std::ostream& operator<<(std::ostream& os, const Date& d);
};

#endif // __DATE_H