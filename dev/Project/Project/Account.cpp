#include "Account.h"

// Constructor
Account::Account(int accId, const char* name, double balance, AccountType accType, double rate, int new_Pin) : account_Number(accId), total_Balance(balance), type(accType), interest_Rate(rate), pin(new_Pin)
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

Account::AccountType Account::GetAccountType() const
{
	return type;
}

double Account::GetInterestRate() const
{
	return interest_Rate;
}

int Account::GetPin() const
{
	return pin;
}

// Setters
void Account::SetAccountNumber(int accId)
{
	account_Number = accId;
}

void Account::SetAccountHolderName(const char* name)
{
	strcpy_s(holder_Name, 50, name);
}

void Account::SetAccountType(AccountType accType)
{
	type = accType;
}

void Account::SetInterestRate(double rate)
{
	interest_Rate = rate;
}

void Account::SetPin(int new_Pin)
{
	pin = new_Pin;
}

// Other Functions
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

bool Account::Transfer(Account& destination_Account, double amount)
{
	// Will withdraw from the sender account
	if (this->Withdraw(amount) == true)
	{
		// Will deposit into the destination account
		destination_Account.Deposit(amount);
		return true;
	}
	return false;
}

void Account::ApplyInterest()
{
	if (type == AccountType::Savings)
	{
		double interestEarned = total_Balance * interest_Rate;
		total_Balance += interestEarned;
	}
}