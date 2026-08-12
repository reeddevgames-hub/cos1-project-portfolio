#pragma once
#include "Account.h"
#include<cstdlib>
#include"ConsoleUtil.h"

class MenuInterface
{
public:
	enum MenuOption

		// This makes The options that will be in the menu an enum which can be easier to call later.
	{
		Deposit,
		Withdraw,
		Transfer,
		Exit
	};

private:
	bool is_Running = true;
	Account& acc_Reference;

	void DisplayMainMenu();

	void HandleSelection(MenuOption option);

public:

	MenuInterface(Account& _reference);

	void Run();
};

