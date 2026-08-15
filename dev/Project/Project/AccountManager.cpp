#include "AccountManager.h"

AccountManager::AccountManager()
{
	currentUser = nullptr;
}

void AccountManager::AccountCreation(int IDNumber, const char* usersName, double initialDeposit, Account::AccountType acc_Type, double interestRate, int securityPin)
{
	Account newAccount(IDNumber, usersName, initialDeposit, acc_Type, interestRate, securityPin);
	master_Registry.push_back(newAccount);
}

bool AccountManager::LoginVerification(int IDNum, int securePin)
{
	for (Account& acc : master_Registry)
	{
		if (acc.GetAccountNumber() == IDNum);
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

void AccountManager::Logout()
{
	currentUser = nullptr;
}

Account* AccountManager::PrivateAccountFinder(int IDNumber1)
{

}

bool AccountManager::TranferCoordinator(int destination_IDNum, double sending_Amount)
{

}

void AccountManager::RunGlobalInterestSweep()
{

}

// Getters
Account* AccountManager::GetCurrentUser()const
{

}

const std::vector<Account>& AccountManager::GetMasterRegistry()const
{

}