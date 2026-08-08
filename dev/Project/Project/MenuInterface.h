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

	void DisplayMainMenu()
	{
		system("CLS");

		// Display User Account Info. 
		ConsoleUtil::WriteLine("========================================", Red);
		ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Your Current Account Information ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
		ConsoleUtil::Write("Account Holder: ", Cyan); ConsoleUtil::WriteLine(acc_Reference.GetAccountHolderName(), Cyan);
		ConsoleUtil::Write("Current Balance: $", Cyan); ConsoleUtil::WriteLine(std::to_string( acc_Reference.GetAccountBalance()), Green);
		ConsoleUtil::WriteLine("========================================", Red);
		ConsoleUtil::WriteLine();

		// Display Main Menu. 
		ConsoleUtil::WriteLine("========================================", Yellow);
		ConsoleUtil::Write("== ", Yellow); ConsoleUtil::Write(" Choose From a Menu Option Below. ", Magenta); ConsoleUtil::WriteLine(" ==", Yellow);
		ConsoleUtil::WriteLine("0. Deposit Funds", Magenta);
		ConsoleUtil::WriteLine("1. Withdraw Funds", Magenta);
		ConsoleUtil::WriteLine("2. Transfer Money", Magenta);
		ConsoleUtil::WriteLine("3. Exit Banking App", Magenta);
	}

	// Using enum MenuOption, makes a switch statement for each choice if chosen.
	void HandleSelection(MenuOption option)
	{
		switch (option)
		{
		case MenuOption::Deposit:
			system("CLS");

			double deposit_Amount;
			ConsoleUtil::Write("Please Enter a Positive Amount: $", Red);
			std::cin >> deposit_Amount;

			if (acc_Reference.Deposit(deposit_Amount)== true)
			{
				ConsoleUtil::WriteLine("Congraulations! Your Deposit was completed safely", Green);
			}
			system("pause");
				break;

		case MenuOption::Withdraw:
			system("CLS");

			double withdraw_Amount;
			ConsoleUtil::Write("Please Enter a Positive Amount: $", Red);
			std::cin >> withdraw_Amount;

			if (acc_Reference.Withdraw(withdraw_Amount) == true)
			{
				ConsoleUtil::WriteLine("Congraulations! Your Money was Withdrawn safely", Green);
			}
			system("pause");
			break;

		case MenuOption::Transfer:
			ConsoleUtil::WriteLine("Transfer System Coming Soon...", Red);
			system("pause");
			break;

		case MenuOption::Exit:
			is_Running = false;
			break;
		}
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
			DisplayMainMenu();
			ConsoleUtil::Write("Enter Option: ", Magenta);
			std::cin >> userInput;
			std::cin.ignore();
			HandleSelection((MenuOption)userInput);
		}
	}
};

