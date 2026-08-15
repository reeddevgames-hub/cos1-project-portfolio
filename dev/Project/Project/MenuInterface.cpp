#include "MenuInterface.h"
#include <iostream>

// Constructor Definition
MenuInterface::MenuInterface(Account& _reference) : acc_Reference(_reference)
{

}

// Display Bank Main Menu and created account information.
void MenuInterface:: DisplayMainMenu()
{
	// Display User Account Info. 
	ConsoleUtil::WriteLine("========================================", Red);
	ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Your Current Account Information ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
	ConsoleUtil::Write("Account Holder: ", Cyan); ConsoleUtil::WriteLine(acc_Reference.GetAccountHolderName(), Cyan);
	ConsoleUtil::Write("Current Balance: $", Cyan); ConsoleUtil::WriteLine(std::to_string(acc_Reference.GetAccountBalance()), Green);
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
void MenuInterface::HandleSelection(MenuInterface::MenuOption option)
{
	switch (option)
	{
	case MenuInterface::Deposit:
		double deposit_Amount;
		ConsoleUtil::WriteLine();
		ConsoleUtil::Write("Please Enter a Positive Amount: $", Red);
		std::cin >> deposit_Amount;

		if (acc_Reference.Deposit(deposit_Amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Deposit was completed safely", Green);
		}
		system("pause");
		break;

	case MenuInterface::Withdraw:
		double withdraw_Amount;
		ConsoleUtil::WriteLine();
		ConsoleUtil::Write("Please Enter a Positive Amount: $", Red);
		std::cin >> withdraw_Amount;

		if (acc_Reference.Withdraw(withdraw_Amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Money was Withdrawn safely", Green);
		}
		system("pause");
		ConsoleUtil::WriteLine();
		break;

	case MenuInterface::Transfer:
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("Transfer System Coming Soon...", Red);
		system("pause");
		ConsoleUtil::WriteLine();
		break;

	case MenuInterface::Exit:
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("========================================", Red);
		ConsoleUtil::WriteLine(" Thank you for banking with Energy Bank ", Cyan);
		ConsoleUtil::WriteLine("        Have a fabulous day!!        ", Cyan);
		ConsoleUtil::WriteLine("========================================", Red);
		is_Running = false;
		break;
	}
}

void MenuInterface::Run()
{
	int userInput;
	std::string userName;
	double initial_Deposit;
	int userPin;
	int typeChoice;

	ConsoleUtil::WriteLine("===============================", Red);
	ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Welcome To Energy Bank! ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
	ConsoleUtil::WriteLine("===============================", Red);
	ConsoleUtil::WriteLine();
	ConsoleUtil::WriteLine("1. Please Enter '1' in Order to Create an Account", Cyan);
	ConsoleUtil::Write("Enter Here: ", Cyan);
	std::cin >> userInput;
	ConsoleUtil::WriteLine();

	// When user creates an account, run this.
	if (userInput == 1)
	{
		std::cin.ignore();

		// Enter Users Desired name. Then it is passed to the account reference and converted to char for Setting the Account Holder Name.
		ConsoleUtil::Write("Please Enter Your Desired Name: ", Cyan); std::getline(std::cin, userName);
		acc_Reference.SetAccountHolderName(userName.c_str());
		ConsoleUtil::WriteLine();

		// Select Account Type to create.
		ConsoleUtil::WriteLine("Select Account Type:", Cyan);
		ConsoleUtil::Write("1. Checking \n2. Savings", Cyan);
		ConsoleUtil::WriteLine("Enter Choice (1-2): ", Cyan);
		std::cin >> typeChoice;
		
		// If the user chooses 2, set the interest rate to 5% and create a savings account, else just create a checking account. 
		if (typeChoice == 2)
		{
			acc_Reference.SetAccountType(Account::Savings);
			acc_Reference.SetInterestRate(0.05);
		} 
		else 
		{
			acc_Reference.SetAccountType(Account::Checking);
		}
		ConsoleUtil::WriteLine();

		// Promp the user to create a pin for added security.
		ConsoleUtil::Write("Create a 4-Digit Security Pin: ", Cyan);
		std::cin >> userPin;
		acc_Reference.SetPin(userPin);
		ConsoleUtil::WriteLine();

		// Enter your initial Deposit amount.
		ConsoleUtil::Write("Please Enter Your Initial Deposit Amount: $", Cyan);
		std::cin >> initial_Deposit;
		acc_Reference.Deposit(initial_Deposit);
		ConsoleUtil::WriteLine();
	}
	while (is_Running == true)
	{
		ConsoleUtil::WriteLine("(*Dev Tip: Press '9' to execute monthly interest cycle*)", Yellow);

		DisplayMainMenu();
		ConsoleUtil::Write("Enter Option: ", Magenta);
		std::cin >> userInput;
		std::cin.ignore();


		if (userInput==9)
		{
			acc_Reference.ApplyInterest();
			ConsoleUtil::WriteLine("It is a new month! Check your new balance!", Green);
			system("pause");
		}
		else
		{
			HandleSelection((MenuInterface::MenuOption)userInput);
		}
	}
}