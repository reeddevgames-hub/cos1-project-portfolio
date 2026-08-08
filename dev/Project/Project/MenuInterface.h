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
		CreateAccount,
		Deposit,
		Withdraw,
		Transfer,
		Exit
	};

private:
	bool is_Running = true;
	Account& acc_Reference;

	void DisplayMainMenu()
	{
		system("CLS");
		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Welcome To Energy Bank! ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
	}

	void HandleSelection(MenuOption option)
	{

	}

public:

	MenuInterface(Account& _reference) : acc_Reference(_reference)
	{
	}

	void Run()
	{
		int userInput;
		std::string userName;
		double initial_Deposit;


		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Welcome To Energy Bank! ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("1. Please Enter '1' in Order to Create an Account", Cyan);
		ConsoleUtil::Write("Enter Here: ", Cyan);
		std::cin >> userInput;

		// When user creates an account, run this.
		if (userInput == 1)
		{
			system("CLS");

			std::cin.ignore();
			
			// Enter Users Desired name. Then it is passed to the account reference and converted to char for Setting the Account Holder Name.
			ConsoleUtil::Write("Please Enter Your Desired Name: ", Cyan); std::getline(std::cin, userName);
			acc_Reference.SetAccountHolderName(userName.c_str());
			
			// Enter your initial Deposit amount.
			ConsoleUtil::Write("Please Enter Your Initial Deposit Amount: $", Cyan);
			std::cin >> initial_Deposit;
			acc_Reference.Deposit(initial_Deposit);



		}

		while (is_Running == true)
		{

		}
	}
};

