#ifndef __DATE_H
#define __DATE_H

class Date 
{
    int day, month, year;

public:
    Date();
    Date(int day, int month, int year);

    int getDay()   const { return day; }
    int getMonth() const { return month; }
    int getYear()  const { return year; }

    bool setDay(int day);
    bool setMonth(int month);
    bool setYear(int year);

    void show() const;
};

#endif // __DATE_H