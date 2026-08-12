#pragma once
#include<cstring>

// This will represent a single bank account record and will contain the account number, Account Holders name, 
// and the balance of the account in question.
class Account
{
private:
	
	int account_Number;               // Account Number, unique Identifier.
	char holder_Name[50];            // Account Holders name in a char array with a max of 50 characters for ease of use with binary writing to file.
	double total_Balance;              // The Account balances tied to that Account Holder. 

public:

	// Constructor
	Account(int accId, const char* name, double balance);
	
	// Getters
	int GetAccountNumber() const;

	const char* GetAccountHolderName() const;

	double GetAccountBalance() const;

	// Setters
	void SetAccountNumber(int acc_Number);
	
	void SetAccountHolderName(const char* _name);
	


	bool Deposit(double _balance);

	bool Withdraw(double _balance);
};

