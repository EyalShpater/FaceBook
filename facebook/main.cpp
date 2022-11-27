#pragma warning (disable:4996)

#include "consoleUI.h"

int main()
{
    ConsoleUI out;
   // out.menu();

    return 0;
}


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

    
    /*
    time_t now = time(0);
    tm* st = localtime(&now);
    //cout << ctime(&now);

    Date d(st->tm_mday, st->tm_mon + 1, st->tm_year + 1900);
    Time t(st->tm_hour, st->tm_min, st->tm_sec);
    Time t1(t);
    

    d.show();
    t.show();
    t1.show();
    Time t2;
    Date d2;
    d2.show();
    t2.show();
    */
