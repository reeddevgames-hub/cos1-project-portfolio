#pragma once
#include<cstring>

// This will represent a single bank account record and will contain the account number, Account Holders name, 
// and the balance of the account in question.
class Account
{
public:
	enum AccountType {
		Checking,
		Savings
	};

private:
	
	int account_Number;               // Account Number, unique Identifier.
	char holder_Name[50];            // Account Holders name in a char array with a max of 50 characters for ease of use with binary writing to file.
	double total_Balance;              // The Account balances tied to that Account Holder. 

	AccountType type;                 // Variable for account type enum.
	double interest_Rate;             // Variable for interest rate for savings account. 
	int pin;

public:

	// Constructor
	Account(int accId, const char* name, double balance, AccountType accType, double rate = 0.0, int new_Pin = 0000);
	
	// Getters
	int GetAccountNumber() const;

	const char* GetAccountHolderName() const;

	double GetAccountBalance() const;

	AccountType GetAccountType() const;

	double GetInterestRate() const;

	int GetPin() const;

	// Setters
	void SetAccountNumber(int accId);
	
	void SetAccountHolderName(const char* name);
	
	void SetAccountType(AccountType accType);

	void SetInterestRate(double rate);

	void SetPin(int new_Pin);

	// Other Functions
	bool Deposit(double _balance);

	bool Withdraw(double _balance);

	bool Transfer(Account& destination_Account, double amount);

	void ApplyInterest();
};

