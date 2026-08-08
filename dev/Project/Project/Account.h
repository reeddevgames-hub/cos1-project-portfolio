#pragma once
#include<cstring>

class Account

// This will represent a single bank account record and will contain the account number, Account Holders name, 
// and the balance of the account in question.
{
private:
	
	int account_Number;               // Account Number, unique Identifier.
	char holder_Name[50];            // Account Holders name in a char array with a max of 50 characters for ease of use with binary writing to file.
	double total_Balance;              // The Account balances tied to that Account Holder. 

public:

	// Constructor
	Account( int accId, const char* name, double balance) : account_Number(accId), total_Balance(balance) 
	{
		strcpy_s(holder_Name, 50, name);
	}

	// Getters
	int GetAccountNumber() const
	{
		return account_Number;
	}

	const char* GetAccountHolderName() const
	{
		return holder_Name;
	}

	double GetAccountBalance() const
	{
		return total_Balance;
	}

	// Setters
	void SetAccountNumber(int acc_Number)
	{
		account_Number = acc_Number;
	}

	void SetAccountHolderName(const char* _name)
	{
		strcpy_s(holder_Name, 50, _name);
	}

	bool Deposit();

	bool Withdraw();

};

