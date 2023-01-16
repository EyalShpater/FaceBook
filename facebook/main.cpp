#pragma warning (disable:4996)

#include "consoleUI.h"
#include "user.h"
#include <fstream>//
using namespace std;//

int main()
{
    /*
    ConsoleUI out;
    out.addDefaultMembersToFacebook();
    out.menu();
    */
    /*
    ImageStatus s("Goodbye!", "C:\\Users\\Eyal\\Pictures\\Screenshots\\TEST.png");
    ofstream outFile("test.bin", ios::binary);
    s.save(outFile);
    outFile.close();
    
    
    ifstream inFile("test.bin", ios::binary);
    ImageStatus amen(inFile);
    inFile.close();

    cout << s << endl << endl;
    cout << amen;
    */
    /*
    User m("momo");
    User g("gogo");
    User y("yoy");
    User k("koko");

    m.addStatus("Hello My name is momo", (int)Status::eStatusType::TEXT);
    m.addStatus("bkslbsls", (int)Status::eStatusType::IMAGE, "C:\\Users\\Eyal\\Pictures\\Screenshots\\TEST.png");

    ofstream outFile("test.bin", ios::binary);
    m.save(outFile);
    m.saveBillBoard(outFile);
    g.save(outFile);
    y.save(outFile);
    y.saveBillBoard(outFile);
    outFile.close();
    */
    ifstream in("test.bin", ios::binary);
    User t(in);
    t.readBillBoard(in);
    User x(in);
    User z(in);
    z.readBillBoard(in);
    in.close();

    cout << t << endl;
    cout << "\n------------" << endl;
    t.showAllStatus();
    cout << "\n------------" << endl;
    cout << x << endl;
    cout << "\n------------" << endl;
    x.showAllStatus();
    cout << "\n------------" << endl;
    cout << z << endl;
    cout << "\n------------" << endl;
    z.showAllStatus();
    cout << "\n------------" << endl;


    return 0;
}