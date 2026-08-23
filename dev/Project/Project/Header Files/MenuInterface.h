#pragma once
#include "Account.h"
#include <cstdlib>
#include "ConsoleUtil.h"
#include "AccountManager.h"
#include "StorageManager.h"

class MenuInterface
{
public:
	enum MenuOption
	{
		Deposit,
		Withdraw,
		Transfer,
		CreateSubAccount,
		Exit
	};

private:
	bool is_running = true;
	AccountManager& acc_reference;
	StorageManager storage_manager;

	void DisplayMainMenu();

	void HandleSelection(MenuOption option);

	void HandleAccountCreation();

	void HandleLogin(bool& is_authenticated);

public:

	MenuInterface(AccountManager& reference);

	void Run();
};

