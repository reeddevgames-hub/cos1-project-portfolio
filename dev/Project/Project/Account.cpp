#include "Account.h"

// Constructor
Account::Account(int accId, const char* name, double balance) : account_Number(accId), total_Balance(balance)
{
	strcpy_s(holder_Name, 50, name);
}

// Getters
int Account::GetAccountNumber() const
{
	return account_Number;
}

const char* Account::GetAccountHolderName() const
{
	return holder_Name;
}

double Account::GetAccountBalance() const
{
	return total_Balance;
}

// Setters
void Account::SetAccountNumber(int acc_Number)
{
	account_Number = acc_Number;
}

void Account::SetAccountHolderName(const char* _name)
{
	strcpy_s(holder_Name, 50, _name);
}

// Other Functions for Account
bool Account::Deposit(double _balance)
{
	if (_balance > 0)
	{
		total_Balance += _balance;
		return true;
	}
	else
	{
		return false;
	}
}

bool Account::Withdraw(double _balance)
{
	if (_balance > 0 && total_Balance >= _balance)
	{
		total_Balance -= _balance;
		return true;
	}
	else
	{
		return false;
	}
}