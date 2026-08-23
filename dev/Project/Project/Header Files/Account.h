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
	
	int account_number;               // Account Number, unique Identifier.
	char holder_name[50];            // Account Holders name in a char array with a max of 50 characters for ease of use with binary writing to file.
	double total_balance;              // The Account balances tied to that Account Holder. 

	AccountType type;                 // Variable for account type enum.
	double interest_rate;             // Variable for interest rate for savings account. 
	int pin;

public:

	// Constructor
	Account(int acc_id, const char* name, double balance, AccountType acc_type, double rate, int new_pin);
	
	// Getters
	int GetAccountNumber() const;

	const char* GetAccountHolderName() const;

	double GetAccountBalance() const;

	AccountType GetAccountType() const;

	double GetInterestRate() const;

	int GetPin() const;

	// Setters
	void SetAccountNumber(int acc_id);
	
	void SetAccountHolderName(const char* name);
	
	void SetAccountType(AccountType acc_type);

	void SetInterestRate(double rate);

	void SetPin(int new_pin);

	// Other Functions
	bool Deposit(double amount);

	bool Withdraw(double amount);

	bool Transfer(Account& destination_account, double amount);

	void ApplyInterest();
};

