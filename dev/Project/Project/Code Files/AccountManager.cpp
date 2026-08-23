#include "AccountManager.h"

AccountManager::AccountManager()
{
	current_user = nullptr;
}

// Helps create multiple accounts and passes them inteor the master_registry vector for storage.
void AccountManager::AccountCreation(int id_number, const char* users_name, double initial_deposit, Account::AccountType account_type, double interest_rate, int security_pin)
{
	Account* new_account = new Account(id_number, users_name, initial_deposit, account_type, interest_rate, security_pin);
	master_registry.push_back(new_account);
}

// Makes you have to use your ID number and security pin to verify the account is yours.
bool AccountManager::LoginVerification(int id_num, int secure_pin)
{
	for (Account* acc : master_registry)
	{
		current_user = (acc->GetAccountNumber() == id_num && acc->GetPin() == secure_pin) ? acc : current_user;

		if (current_user == acc)
		{
			return true;
		}
	}
	return false;
}

// Lets you log out of the account.
void AccountManager::Logout()
{
	current_user = nullptr;
}

// This allows you to search for an account to see if it is there for when you want to transfer to a different account.
Account* AccountManager::PrivateAccountFinder(int id_number)
{
	for (Account* acc : master_registry)
	{
		if ( acc->GetAccountNumber() == id_number)
		{
			return acc;
		}
	}
	return nullptr;
}

// This runs your transfer function after finding the account then allows you to transfer to that account.
bool AccountManager::TranferCoordinator(int destination_id, double sending_amount)
{
	if (current_user == nullptr)
	{
		return false;
	}
	Account* recieving_account = PrivateAccountFinder(destination_id);
	
	if (recieving_account != nullptr)
	{
		return current_user->Transfer(*recieving_account, sending_amount);
	}
	return false;
}

// This function works as a fast track to the "next month" when you use an account with interest and it will add said interest agains the amount in your current balance.
void AccountManager::RunGlobalInterestSweep()
{
	for (Account* acc : master_registry)
	{
		acc->ApplyInterest();
	}
}

// Getters
Account* AccountManager::GetCurrentUser()const
{
	return current_user;
}

const std::vector<Account*>& AccountManager::GetMasterRegistry()const
{
	return master_registry;
}

// Destructor
AccountManager::~AccountManager()
{
	for (Account* acc : master_registry)
	{
		delete acc;
	}
	master_registry.clear();
}