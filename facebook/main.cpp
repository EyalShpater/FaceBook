#pragma warning (disable:4996)

#include "consoleUI.h"

#include <crtdbg.h>
int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    ConsoleUI out;
    out.addDefaultMembersToFacebook();
    out.menu();

    return 0;
}