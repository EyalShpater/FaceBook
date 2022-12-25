#pragma warning (disable:4996)

#include "consoleUI.h"

int main()
{
    ConsoleUI out;

    out.addDefaultMembersToFacebook();
    out.menu();
    
    return 0;
}