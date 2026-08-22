#include "AccountManager.h"

AccountManager::AccountManager()
{
	currentUser = nullptr;
}

// Helps create multiple accounts and passes them inteor the master_registry vector for storage.
void AccountManager::AccountCreation(int IDNumber, const char* usersName, double initialDeposit, Account::AccountType acc_Type, double interestRate, int securityPin)
{
	Account newAccount(IDNumber, usersName, initialDeposit, acc_Type, interestRate, securityPin);
	master_Registry.push_back(newAccount);
}

// Makes you have to use your ID number and security pin to verify the account is yours.
bool AccountManager::LoginVerification(int IDNum, int securePin)
{
	for (Account& acc : master_Registry)
	{
		if (acc.GetAccountNumber() == IDNum)
		{
			if (acc.GetPin() == securePin)
			{
				currentUser = &acc;
				return true;
			}
		}
	}
	return false;
}

// Lets you log out of the account.
void AccountManager::Logout()
{
	currentUser = nullptr;
}

// This allows you to search for an account to see if it is there for when you want to transfer to a different account.
Account* AccountManager::PrivateAccountFinder(int IDNumber1)
{
	for (Account& acc : master_Registry)
	{
		if ( acc.GetAccountNumber() == IDNumber1)
		{
			return &acc;
		}
	}
	return nullptr;
}

// This runs your transfer function after finding the account then allows you to transfer to that account.
bool AccountManager::TranferCoordinator(int destination_IDNum, double sending_Amount)
{
	if (currentUser == nullptr)
	{
		return false;
	}
	Account* recieving_Account = PrivateAccountFinder(destination_IDNum);
	
	if (recieving_Account != nullptr)
	{
		return currentUser->Transfer(*recieving_Account, sending_Amount);
	}
	return false;
}

// This function works as a fast track to the "next month" when you use an account with interest and it will add said interest agains the amount in your current balance.
void AccountManager::RunGlobalInterestSweep()
{
	for (Account& acc : master_Registry)
	{
		acc.ApplyInterest();
	}
}

// Getters
Account* AccountManager::GetCurrentUser()const
{
	return currentUser;
}

const std::vector<Account>& AccountManager::GetMasterRegistry()const
{
	return master_Registry;
}