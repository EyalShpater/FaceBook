#pragma warning (disable:4996)

#include <iostream>
#include <ctime>

#include "time.h"
#include "date.h"

#include "admin.h"

using namespace std;

int main()
{
    /*cout << "hello" << endl;
    Time t(22, 00, 32);
    Date d(19, 11, 2021);

    time_t t1;

    t.show();
    d.show();
    t1 = time(nullptr);

    cout << asctime(localtime(&t1));

    cout << "ver 2" << endl;
    cout << "ver3" << endl;
    cout << "ver4" << endl;
    */

    //Admin a;

   // a.menu();

    time_t now = time(0);
    struct tm* st = localtime(&now);
    //cout << ctime(&now);

    Date d(st->tm_mday, st->tm_mon + 1, st->tm_year + 1900);
    Time t(st->tm_hour, st->tm_min, st->tm_sec);
    Time t1(t);


    d.show();
    t.show();

    system("pause");

    return 0;
}