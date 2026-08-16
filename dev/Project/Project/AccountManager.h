#pragma once
#include<vector>
#include"Account.h"


// This will be where multiple accounts can be stored together in a vector after they are created.
class AccountManager
{
private:
	std::vector<Account> master_Registry;
	Account* currentUser;

public:
	AccountManager();

	void AccountCreation(int IDNumber, const char* usersName, double initialDeposit, Account::AccountType acc_Type, double interestRate, int securityPin);

	bool LoginVerification(int IDNum, int securePin);
	void Logout();

	Account* PrivateAccountFinder(int IDNumber1);
	bool TranferCoordinator(int destination_IDNum, double sending_Amount);

	void RunGlobalInterestSweep();

	// Getters
	Account* GetCurrentUser() const;

	const std::vector<Account>& GetMasterRegistry() const;
};