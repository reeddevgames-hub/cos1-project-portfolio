#include "MenuInterface.h"
#include <iostream>
#include "InputFilter.h"
#include<string>

// Constructor Definition
MenuInterface::MenuInterface(AccountManager& reference) : acc_reference(reference), is_running(true) { }

// Display Bank Main Menu and created account information.
void MenuInterface:: DisplayMainMenu()
{
	// Display User Account Info. 
	ConsoleUtil::WriteLine("========================================", Red);
	ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Your Current Account Information ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
	ConsoleUtil::Write("Account Holder: ", Cyan); ConsoleUtil::WriteLine(acc_reference.GetCurrentUser()->GetAccountHolderName(), Cyan);
	ConsoleUtil::Write("Current Balance: $", Cyan); ConsoleUtil::WriteLine(std::to_string(acc_reference.GetCurrentUser()->GetAccountBalance()), Green);
	ConsoleUtil::WriteLine("========================================", Red);
	ConsoleUtil::WriteLine();

	// Display Main Menu. 
	ConsoleUtil::WriteLine("========================================", Yellow);
	ConsoleUtil::Write("== ", Yellow); ConsoleUtil::Write(" Choose From a Menu Option Below. ", Magenta); ConsoleUtil::WriteLine(" ==", Yellow);
	ConsoleUtil::WriteLine("0. Deposit Funds", Magenta);
	ConsoleUtil::WriteLine("1. Withdraw Funds", Magenta);
	ConsoleUtil::WriteLine("2. Transfer Money", Magenta);
	ConsoleUtil::WriteLine("3. Open a New Sub-Account", Magenta);
	ConsoleUtil::WriteLine("4. Exit Banking App", Magenta);
}

// Using enum MenuOption, makes a switch statement for each choice if chosen.
void MenuInterface::HandleSelection(MenuInterface::MenuOption option)
{
	switch (option)
	{
	case MenuInterface::Deposit:
	{
		double deposit_amount;
		ConsoleUtil::WriteLine();
		deposit_amount = InputFilter::SafePositiveDouble("Please Enter a Positive Amount: $", "Error: Invalid format! You must enter a positive decimal number.");

		if (acc_reference.GetCurrentUser()->Deposit(deposit_amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Deposit was completed safely", Green);
		}
		system("pause");
		break;
	}

	case MenuInterface::Withdraw:
	{
		double withdraw_amount;
		ConsoleUtil::WriteLine();
		withdraw_amount = InputFilter::SafePositiveDouble("Please Enter a Positive Amount: $", "Error: Cash quantity must be a positive number.");

		if (acc_reference.GetCurrentUser()->Withdraw(withdraw_amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Money was Withdrawn safely", Green);
		}
		system("pause");
		ConsoleUtil::WriteLine();
		break;
	}

	case MenuInterface::Transfer:
	{
		int destinationacc_id;
		double sent_amount;

		acc_reference.PrintTransferRegistry();
		ConsoleUtil::WriteLine();

		destinationacc_id = InputFilter::SafeInteger("Please Enter the Recipient 4 - Digit Account ID Number : ", "Error: IDs must consist of only numeric digits.");
		ConsoleUtil::WriteLine();
		sent_amount = InputFilter::SafePositiveDouble("Please Enter a POSITIVE amount to transfer: ", "Error: You cannot send a negative amount or 0.0 dollars.");

		if (acc_reference.TranferCoordinator(destinationacc_id, sent_amount) == true)
		{
			ConsoleUtil::WriteLine("Transfer was Successfully Completed!", Green);
		}
		else
		{
			ConsoleUtil::WriteLine("TRANSFER FAILED: (*Invalid Account ID!  or Insuficient Funds!*)", Red);
		}
		system("pause");
		ConsoleUtil::WriteLine();
		break;
	}

	case MenuInterface::CreateSubAccount:
	{
		ConsoleUtil::WriteLine();

		ConsoleUtil::WriteLine("Sub-account route varified!", Green);
		system("pause");
		ConsoleUtil::WriteLine();
		break;
	}

	case MenuInterface::Exit:
	{
		// Save the account information before exiting the application.
		storage_manager.SaveAccountInterface(acc_reference.GetMasterRegistry());

		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("========================================", Red);
		ConsoleUtil::WriteLine(" Thank you for banking with Energy Bank ", Cyan);
		ConsoleUtil::WriteLine("        Have a fabulous day!!        ", Cyan);
		ConsoleUtil::WriteLine("========================================", Red);
		is_running = false;
		break;
	}
	}
}

// Stand-alone function to handle account creation. 
void MenuInterface::HandleAccountCreation()
{
	std::string user_name = InputFilter::SafeString("Please Enter Your Desired Name: ", "Error: Name field cannot be left blank! Please type an account holder name.");

	ConsoleUtil::WriteLine("Select Account Type:", Cyan);
	ConsoleUtil::WriteLine("1. Checking \n2. Savings", Cyan);
	int type_choice = InputFilter::SafeInteger("Enter # Choice (1 or 2): ", "Error: Selection invalid! Please select from the available options (1 or 2).");

	Account::AccountType chosen_type = Account::Checking;
	double interest_rate = 0.0;

	if (type_choice == 2)
	{
		chosen_type = Account::Savings;
		interest_rate = 0.05;
	}
	
	int new_account_id = InputFilter::SafeInteger("Create a Unique 4-Digit Account ID Number: ", "Error: Invalid Input! System account IDs must be numbers.");
	int user_pin = InputFilter::SafeInteger("Create a 4-Digit Security Pin: ", "Error: Pin code must be 4-digit numbers.");
	double initial_deposit = InputFilter::SafePositiveDouble("Please Enter Your Initial Deposit Amount: $", "Error: Opening balances must be valid positive decimal inputs.");

	acc_reference.AccountCreation(new_account_id, user_name.c_str(), initial_deposit, chosen_type, interest_rate, user_pin);
	ConsoleUtil::WriteLine("Congradulations! Your account has successfully been created! Welcome To Energy Bank.", Green);
	system("pause");

	acc_reference.LoginVerification(new_account_id, user_pin);
}

// Stand-alone function to handle login evaluation.
void MenuInterface::HandleLogin(bool& is_authenticated)
{
	int login_id = InputFilter::SafeInteger("Enter Your 4-Digit Account ID Number: ", "Error: Invalid Input! IDs must be numeric digits in order to access your account/s.");
	int login_pin = InputFilter::SafeInteger("Enter Your 4-Digit Security Pin: ", "Error: Invalid Entry! Please type your 4-Digit pin.");

	if (!acc_reference.LoginVerification(login_id, login_pin))
	{
		ConsoleUtil::WriteLine("ACCESS DENIED: Invalid ID or PIN Code! Please Create an Account if you do not have one yet.", Red);
		system("pause");
	}
	else
	{
		ConsoleUtil::WriteLine("ACCESS GRANTED:  Loading Main Menu...", Green);
		system("pause");
		is_authenticated = true;
	}
}

void MenuInterface::Run()
{
	// Load any saved data from the binary database file on bootup of the application.
	acc_reference.InitializeRegistry(storage_manager.LoadAccountInterface());

	bool is_authenticated = false;

	while (!is_authenticated)
	{
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Welcome To Energy Bank! ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("Please enter the number associated with the choices from below! ", Cyan);
		ConsoleUtil::WriteLine("1. Login to Your Account\n2. Open a New Bank Account", Cyan);
		
		int user_input = InputFilter::SafeInteger("Enter Choice # Here: ", "Error: Choice not recognized! Please enter a valid number (1 or 2).");
	
		if (user_input == 2)
		{
			HandleAccountCreation();
			is_authenticated = true;
		}
		else if (user_input == 1)
		{
			HandleLogin(is_authenticated);
		}
	}

	if (acc_reference.GetCurrentUser() != nullptr)
	{
		while (is_running)
		{
			ConsoleUtil::WriteLine("(*Dev Tip: Press '9' to execute monthly interest cycle*)", Yellow);

			DisplayMainMenu();
			ConsoleUtil::Write("Enter Option: ", Magenta);

			int menu_selection;
			std::cin >> menu_selection;
			std::cin.ignore();
			
			if (menu_selection == 9)
			{
				acc_reference.RunGlobalInterestSweep();
				ConsoleUtil::WriteLine("It is a new month! Check your new balance!", Green);
				system("pause");
			}
			else
			{
				HandleSelection((MenuInterface::MenuOption)menu_selection);

				std::cin.ignore(1000, '\n');
			}
		}
	}
}