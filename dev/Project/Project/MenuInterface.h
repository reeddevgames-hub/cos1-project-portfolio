#pragma once
#include "Account.h"
#include<cstdlib>
#include"ConsoleUtil.h"
#include"AccountManager.h"

class MenuInterface
{
public:

	// This makes The options that will be in the menu an enum which can be easier to call later.
	enum MenuOption
	{
		Deposit,
		Withdraw,
		Transfer,
		Exit
	};

private:
	bool is_Running = true;
	AccountManager& acc_Reference;

	void DisplayMainMenu();

	void HandleSelection(MenuOption option);

public:

	MenuInterface(AccountManager& _reference);

	void Run();
};

