#include <iostream>
#include "ConsoleUtil.h"
#include"Account.h"
#include "MenuInterface.h"
#include"AccountManager.h"

int main()
{
	AccountManager bankMasterDatabase;

	MenuInterface bank_Application(bankMasterDatabase);
	bank_Application.Run();
}