#include "MenuInterface.h"
#include <iostream>
#include "InputFilter.h"

// Constructor Definition
MenuInterface::MenuInterface(AccountManager& _reference) : acc_Reference(_reference)
{

}

// Display Bank Main Menu and created account information.
void MenuInterface:: DisplayMainMenu()
{
	// Display User Account Info. 
	ConsoleUtil::WriteLine("========================================", Red);
	ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Your Current Account Information ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
	ConsoleUtil::Write("Account Holder: ", Cyan); ConsoleUtil::WriteLine(acc_Reference.GetCurrentUser()->GetAccountHolderName(), Cyan);
	ConsoleUtil::Write("Current Balance: $", Cyan); ConsoleUtil::WriteLine(std::to_string(acc_Reference.GetCurrentUser()->GetAccountBalance()), Green);
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
		deposit_Amount = InputFilter::SafePositiveDouble("Please Enter a Positive Amount: $", "Error: Invalid format! You must enter a positive decimal number.");

		if (acc_Reference.GetCurrentUser()->Deposit(deposit_Amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Deposit was completed safely", Green);
		}
		system("pause");
		break;

	case MenuInterface::Withdraw:
		double withdraw_Amount;
		ConsoleUtil::WriteLine();
		withdraw_Amount = InputFilter::SafePositiveDouble("Please Enter a Positive Amount: $", "Error: Cash quantity must be a positive number.");

		if (acc_Reference.GetCurrentUser()->Withdraw(withdraw_Amount) == true)
		{
			ConsoleUtil::WriteLine();
			ConsoleUtil::WriteLine("Congraulations! Your Money was Withdrawn safely", Green);
		}
		system("pause");
		ConsoleUtil::WriteLine();
		break;

	case MenuInterface::Transfer:
		int destinationacc_ID;
		double sent_Amount;

		ConsoleUtil::WriteLine();
		destinationacc_ID = InputFilter::SafeInteger("Please Enter the Recipient 4 - Digit Account ID Number : ", "Error: IDs must consist of only numeric digits.");
		ConsoleUtil::WriteLine();
		sent_Amount = InputFilter::SafePositiveDouble("Please Enter a POSITIVE amount to transfer: ", "Error: You cannot send a negative amount or 0.0 dollars.");

		if (acc_Reference.TranferCoordinator(destinationacc_ID, sent_Amount) == true)
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
	int new_AccountID;
	bool is_Authenticated = false;

	while (is_Authenticated == false)
	{
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::Write("== ", Red); ConsoleUtil::Write(" Welcome To Energy Bank! ", Cyan); ConsoleUtil::WriteLine(" ==", Red);
		ConsoleUtil::WriteLine("===============================", Red);
		ConsoleUtil::WriteLine();
		ConsoleUtil::WriteLine("Please enter the number associated with the choices from below! ", Cyan);
		ConsoleUtil::WriteLine("1. Login to Your Account\n2. Open a New Bank Account", Cyan);
		userInput = InputFilter::SafeInteger("Enter Choice # Here: ", "Error: Choice not recognized! Please enter a valid number (1 or 2).");

		// When user creates an account, run this.
		if (userInput == 2)
		{
			// Enter Users Desired name. Then it is passed to the account reference and converted to char for Setting the Account Holder Name.
			userName = InputFilter::SafeString("Please Enter Your Desired Name: ", "Error: Name field cannot be left blank! Please type an account holder name.");

			// Select Account Type to create.
			ConsoleUtil::WriteLine("Select Account Type:", Cyan);
			ConsoleUtil::WriteLine("1. Checking \n2. Savings", Cyan);
			typeChoice = InputFilter::SafeInteger("Enter # Choice (1 or 2): ", "Error: Selection invalid! Please select from the available options (1 or 2).");

			Account::AccountType chosenType = Account::Checking;
			double interestRate = 0.0;

			// Account Creation Block
			if (typeChoice == 2)
			{
				chosenType = Account::Savings;
				interestRate = 0.05;
			}
			// Prompt user to create an account ID.
			new_AccountID = InputFilter::SafeInteger("Create a Unique 4-Digit Account ID Number: ", "Error: Invalid Input! System account IDs must be numbers.");

			// Prompt user to create a security pin.
			userPin = InputFilter::SafeInteger("Create a 4-Digit Security Pin: ", "Error: Pin code must be 4-digit numbers.");

			initial_Deposit = InputFilter::SafePositiveDouble("Please Enter Your Initial Deposit Amount: $", "Error: Opening balances must be valid positive decimal inputs.");

			acc_Reference.AccountCreation(new_AccountID, userName.c_str(), initial_Deposit, chosenType, interestRate, userPin);
			ConsoleUtil::WriteLine("Congradulations! Your account has successfully been created! Welcome To Energy Bank.", Green);
			system("pause");

			acc_Reference.LoginVerification(new_AccountID, userPin);
			is_Authenticated = true;
		}

		// Login Block
		else if (userInput == 1)
		{
			int loginID;
			int loginPin;

			loginID = InputFilter::SafeInteger("Enter Your 4-Digit Account ID Number: ", "Error: Invalid Input! IDs must be numeric digits in order to access your account/s.");

			loginPin = InputFilter::SafeInteger("Enter Your 4-Digit Security Pin: ", "Error: Invalid Entry! Please type your 4-Digit pin.");

			if (acc_Reference.LoginVerification(loginID, loginPin) == false)
			{
				ConsoleUtil::WriteLine("ACCESS DENIED: Invalid ID or PIN Code! Please Create an Account if you do not have one yet.", Red);
				system("pause");
			}

			else
			{
				ConsoleUtil::WriteLine("ACCESS GRANTED:  Loading Main Menu...", Green);
				system("pause");
				is_Authenticated = true;
			}
		}
	}

	if (acc_Reference.GetCurrentUser() != nullptr)
	{
		while (is_Running == true)
		{
			ConsoleUtil::WriteLine("(*Dev Tip: Press '9' to execute monthly interest cycle*)", Yellow);

			DisplayMainMenu();
			ConsoleUtil::Write("Enter Option: ", Magenta);
			std::cin >> userInput;
			std::cin.ignore();
			
			if (userInput == 9)
			{
				acc_Reference.RunGlobalInterestSweep();
				ConsoleUtil::WriteLine("It is a new month! Check your new balance!", Green);
				system("pause");
			}
			else
			{
				HandleSelection((MenuInterface::MenuOption)userInput);

				std::cin.ignore(1000, '\n');
			}
		}
	}
}