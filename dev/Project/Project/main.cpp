#include <iostream>
#include "ConsoleUtil.h"
#include"Account.h"
#include "MenuInterface.h"

int main()
{
	Account accObject(0001, "", 0.0);

	MenuInterface bank_Application(accObject);
	bank_Application.Run();
}