#include <iostream>
#include "ConsoleUtil.h"
#include"Account.h"
#include "MenuInterface.h"
#include"AccountManager.h"

int main()
{
	AccountManager bank_master_database;

	MenuInterface bank_application(bank_master_database);
	bank_application.Run();
}