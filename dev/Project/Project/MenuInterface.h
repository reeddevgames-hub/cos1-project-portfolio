#pragma once
#include "Account.h"

class MenuInterface
{
public:
	enum MenuOption

		// This makes The options that will be in the menu an enum which can be easier to call later.
	{
		CreateAccount,
		Deposit,
		Withdraw,
		Transfer,
		Exit
	};

private:
	Account& acc_Reference;

	void DisplayMainMenu();

	void HandleSelection(MenuOption option);

public:

	MenuInterface(Account& _reference) : acc_Reference(_reference)
	{
	}

	void Run()
	{
		bool is_Running = true;

		while (is_Running == true)
		{

		}
	}
};

