#ifndef __DATE_H
#define __DATE_H

class Date {
    int day, month, year;
public:
    Date(int d, int m, int y);

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);

    void show() const;
};

#endif // __DATE_H