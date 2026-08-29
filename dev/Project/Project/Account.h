#pragma once
#include<cstring>

class Account
{
public:
	enum AccountType {
		Checking,
		Savings
	};

private:
	
	int account_number;        
	char holder_name[50];         
	double total_balance;            
	AccountType type;           
	double interest_rate;            
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

	// Core Banking Operations
	bool Deposit(double amount);
	bool Withdraw(double amount);
	bool Transfer(Account& destination_account, double amount);
	
	void ApplyInterest();
};