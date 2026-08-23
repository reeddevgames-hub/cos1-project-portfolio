#include "Account.h"

// Constructor
Account::Account(int acc_id, const char* name, double balance, AccountType acc_type, double rate, int new_pin) : account_number(acc_id), total_balance(balance), type(acc_type), interest_rate(rate), pin(new_pin)
{
	strcpy_s(holder_name, sizeof(holder_name), name);
}

// Getters
int Account::GetAccountNumber() const
{
	return account_number;
}

const char* Account::GetAccountHolderName() const
{
	return holder_name;
}

double Account::GetAccountBalance() const
{
	return total_balance;
}

Account::AccountType Account::GetAccountType() const
{
	return type;
}

double Account::GetInterestRate() const
{
	return interest_rate;
}

int Account::GetPin() const
{
	return pin;
}

// Setters
void Account::SetAccountNumber(int acc_id)
{
	account_number = acc_id;
}

void Account::SetAccountHolderName(const char* name)
{
	strcpy_s(holder_name, sizeof(holder_name), name);
}

void Account::SetAccountType(AccountType acc_type)
{
	type = acc_type;
}

void Account::SetInterestRate(double rate)
{
	interest_rate = rate;
}

void Account::SetPin(int new_pin)
{
	pin = new_pin;
}

// Other Functions
bool Account::Deposit(double amount)
{
	// GUARD CLAUSE: Rejecting zero or negative transactions immediately.
	if (amount <= 0) { return false; }
	
	total_balance += amount;
	return true;
}

bool Account::Withdraw(double amount)
{
	// GUARD CLAUSE: Rejecting amounts of insufficient funds immediately.
	if (amount <= 0 || total_balance < amount) { return false; }
	
	total_balance -= amount;
	return true;
}

bool Account::Transfer(Account& destination_account, double amount)
{
	// GUARD CLAUSE: if the withdrawal from this account fails, exit immediately.
	if (!Withdraw(amount)) { return false; }

	destination_account.Deposit(amount);
	return true;
}

void Account::ApplyInterest()
{
	if (type == AccountType::Savings)
	{
		double interest_earned = total_balance * interest_rate;
		total_balance += interest_earned;
	}
}