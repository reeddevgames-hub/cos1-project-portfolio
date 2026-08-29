#include "MenuInterface.h"
#include <iostream>
#include "InputFilter.h"
#include<string>

// Constructor Definition
MenuInterface::MenuInterface(AccountManager& reference) : account_manager_reference(reference), is_running(true) { }

// Display Bank Main Menu and created account information.
void MenuInterface:: DisplayMainMenu()
{
	// Display User Account Info. 
	ConsoleUtil::WriteLine("========================================", Red);
	ConsoleUtil::Write("== ", Red); 
	ConsoleUtil::Write(" Your Current Account Information ", Cyan); 
	ConsoleUtil::WriteLine(" ==", Red);
	
	std::string profile_holder = account_manager_reference.GetCurrentUser()->GetAccountHolderName();
	ConsoleUtil::Write("== ", Red);
	ConsoleUtil::Write("Account Holder: ", Cyan);
	ConsoleUtil::Write(profile_holder, Cyan);
	ConsoleUtil::WriteLine(" == ", Red);
	ConsoleUtil::WriteLine("----------------------------------------", Red);

	for (Account* acc : account_manager_reference.GetMasterRegistry())
	{
		if (acc->GetAccountHolderName() == profile_holder)
		{
			std::string account_type_label = (acc->GetAccountType() == Account::Savings) ? "Savings" : "Checking";

			ConsoleUtil::Write("== ", Red);
			ConsoleUtil::Write("Account ID: " + std::to_string(acc->GetAccountNumber()) + " (" + account_type_label + ") | Balance: ", Cyan);
			ConsoleUtil::Write("$ ", Green);
			ConsoleUtil::WriteLine(std::to_string(acc->GetAccountBalance()), Green);
		}
	}
	ConsoleUtil::WriteLine("========================================", Red);
	ConsoleUtil::WriteLine();

	// Display Main Menu. 
	ConsoleUtil::WriteLine("========================================", Yellow);
	ConsoleUtil::Write("== ", Yellow); 
	ConsoleUtil::Write(" Choose From a Menu Option Below. ", Magenta); 
	ConsoleUtil::WriteLine(" ==", Yellow);
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

		ConsoleUtil::WriteLine("(*Tip: Enter '0' to cancel and go back to the main menu*)", Yellow);
		deposit_amount = InputFilter::SafePositiveDouble("Please Enter a Positive Amount: $", "Error: Invalid format! You must enter a positive decimal number.");

		// GUARD CLAUSE: Go back if user typed 0.
		if (deposit_amount == 0.0)
		{
			ConsoleUtil::WriteLine("Transaction canceled. Returning to main menu...", Yellow);
			InputFilter::pause_execution();
			break;
		}
		
		if (account_manager_reference.GetCurrentUser()->Deposit(deposit_amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Deposit was completed safely", Green);
		}
		InputFilter::pause_execution();
		break;
	}
	case MenuInterface::Withdraw:
	{
		double withdraw_amount;
		ConsoleUtil::WriteLine();

		ConsoleUtil::WriteLine("(*Tip: Enter '0' to cancel and go back to the main menu*)", Yellow);
		withdraw_amount = InputFilter::SafePositiveDouble("Please Enter a Positive Amount: $", "Error: Cash quantity must be a positive number.");

		// GUARD CLAUSE: Go back if user typed 0.
		if (withdraw_amount == 0.0)
		{
			ConsoleUtil::WriteLine("Transaction canceled. Returning to main menu...", Yellow);
			InputFilter::pause_execution();
			break;
		}

		if (account_manager_reference.GetCurrentUser()->Withdraw(withdraw_amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Money was Withdrawn safely", Green);
		}
		ConsoleUtil::WriteLine();
		InputFilter::pause_execution();
		break;
	}
	case MenuInterface::Transfer:
	{
		int destinationacc_id;
		double sent_amount;
		account_manager_reference.PrintTransferRegistry();
		ConsoleUtil::WriteLine();

		ConsoleUtil::WriteLine("(*Tip: Enter '0' to cancel and go back to the main menu*)", Yellow);
		destinationacc_id = InputFilter::SafeInteger("Please Enter the Recipient 4 - Digit Account ID Number : ", "Error: IDs must consist of only numeric digits.");

		// GUARD CLAUSE: Go back if user typed 0.
		if (destinationacc_id == 0.0)
		{
			ConsoleUtil::WriteLine("Transaction canceled. Returning to main menu...", Yellow);
			InputFilter::pause_execution();
			break;
		}

		ConsoleUtil::WriteLine();
		sent_amount = InputFilter::SafePositiveDouble("Please Enter a POSITIVE amount to transfer: ", "Error: You cannot send a negative amount or 0.0 dollars.");

		// GUARD CLAUSE: Go back if user typed 0.
		if (sent_amount == 0.0)
		{
			ConsoleUtil::WriteLine("Transaction canceled. Returning to main menu...", Yellow);
			InputFilter::pause_execution();
			break;
		}

		if (account_manager_reference.TransferCoordinator(destinationacc_id, sent_amount) == true)
		{
			ConsoleUtil::WriteLine("Transfer was Successfully Completed!", Green);
		}
		else
		{
			ConsoleUtil::WriteLine("TRANSFER FAILED: (*Invalid Account ID!  or Insuficient Funds!*)", Red);
		}
		ConsoleUtil::WriteLine();
		InputFilter::pause_execution();
		break;
	}
	case MenuInterface::CreateSubAccount:
	{
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("======= OPEN AN ADDITIONAL SUB-ACCOUNT =======", Cyan);
		ConsoleUtil::WriteLine("Select Account Type:", Cyan);
		ConsoleUtil::WriteLine("1. Checking \n2. Savings", Cyan);

		int sub_type_choice = InputFilter::SafeInteger("Enter # Choice (1, 2 or 0): ", "Error: Selection invalid! Please select 1, 2 or 0.");

		// GUARD CLAUSE: Go back if user typed 0.
		if (sub_type_choice == 0.0)
		{
			ConsoleUtil::WriteLine("Operation canceled. Returning to main menu...", Yellow);
			InputFilter::pause_execution();
			break;
		}

		Account::AccountType sub_chosen_type = (sub_type_choice == 2) ? Account::Savings : Account::Checking;
		double sub_interest_rate = (sub_type_choice == 2) ? 0.05 : 0.0;
		double sub_initial_deposit = InputFilter::SafePositiveDouble("Please Enter Your Opening Deposit Amount: $", "Error: Opening balances must be positive numbers.");

		account_manager_reference.CreateLinkedSubAccount(sub_chosen_type, sub_initial_deposit, sub_interest_rate);

		ConsoleUtil::WriteLine();
		InputFilter::pause_execution();
		break;
	}
	case MenuInterface::Exit:
	{
		// Save the account information before exiting the application.
		storage_manager.SaveAccountInterface(account_manager_reference.GetMasterRegistry());

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

	account_manager_reference.AccountCreation(new_account_id, user_name.c_str(), initial_deposit, chosen_type, interest_rate, user_pin);
	ConsoleUtil::WriteLine("Congradulations! Your account has successfully been created! Welcome To Energy Bank.", Green);
	InputFilter::pause_execution();

	account_manager_reference.LoginVerification(new_account_id, user_pin);
}

// Stand-alone function to handle login evaluation.
void MenuInterface::HandleLogin(bool& is_authenticated)
{
	int login_id = InputFilter::SafeInteger("Enter Your 4-Digit Account ID Number: ", "Error: Invalid Input! IDs must be numeric digits in order to access your account/s.");
	int login_pin = InputFilter::SafeInteger("Enter Your 4-Digit Security Pin: ", "Error: Invalid Entry! Please type your 4-Digit pin.");

	if (!account_manager_reference.LoginVerification(login_id, login_pin))
	{
		ConsoleUtil::WriteLine("ACCESS DENIED: Invalid ID or PIN Code! Please Create an Account if you do not have one yet.", Red);
		InputFilter::pause_execution();
	}
	else
	{
		ConsoleUtil::WriteLine("ACCESS GRANTED:  Loading Main Menu...", Green);
		InputFilter::pause_execution();
		is_authenticated = true;
	}
}

void MenuInterface::Run()
{
	// Load any saved data from the binary database file on bootup of the application.
	account_manager_reference.InitializeRegistry(storage_manager.LoadAccountInterface());

	bool is_authenticated = false;

	while (!is_authenticated)
	{
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("===============================================", Red);
		ConsoleUtil::Write("========== ", Red); ConsoleUtil::Write(" Welcome To Energy Bank! ", Cyan); ConsoleUtil::WriteLine(" ==========", Red);
		ConsoleUtil::WriteLine("===============================================", Red);
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("== IF THIS IS YOUR FIRST TIME HERE, PLEASE CREATE AN ACCOUNT ==", Yellow);
		ConsoleUtil::WriteLine("Please choose from the options below. ", Cyan); 
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

	if (account_manager_reference.GetCurrentUser() != nullptr)
	{
		while (is_running)
		{
			ConsoleUtil::WriteLine("(*Dev Tip: Press '9' to execute monthly interest cycle*)", Yellow);

			DisplayMainMenu();

			int menu_selection = InputFilter::SafeInteger("Enter Option: ", "Error: Selection option unrecognized.");
						
			if (menu_selection == 9)
			{
				account_manager_reference.RunGlobalInterestSweep();
				ConsoleUtil::WriteLine("It is a new month! Check your new balance!", Green);
				InputFilter::pause_execution();
			}
			else
			{
				HandleSelection((MenuInterface::MenuOption)menu_selection);
			}
		}
	}
}