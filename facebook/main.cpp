#pragma warning (disable:4996)

#include "consoleUI.h"

#include <iostream>
using namespace std;

int main()
{
    try 
    {
        ConsoleUI out;
        out.addDefaultMembersToFacebook();
        out.menu();

        return 0;
    }

    catch (...)
    {
        cout << "General error occured!" << endl;
    }

    
    
}