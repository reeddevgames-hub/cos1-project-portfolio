#pragma once
#include "Account.h"
#include<cstdlib>
#include"ConsoleUtil.h"
#include"AccountManager.h"

class MenuInterface
{
public:
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

