#pragma once
#include<vector>
#include"Account.h"


// This will be where multiple accounts can be stored together in a vector after they are created.
class AccountManager
{
private:
	std::vector<Account*> master_registry;
	Account* current_user;

public:
	AccountManager();

	void AccountCreation(int id_number, const char* users_name, double initial_deposit, Account::AccountType account_type, double interest_rate, int security_pin);
	bool LoginVerification(int id_num, int secure_pin);
	void Logout();

	Account* PrivateAccountFinder(int id_number);
	bool TranferCoordinator(int destination_id, double sending_amount);

	void RunGlobalInterestSweep();

	// Getters.
	Account* GetCurrentUser() const;

	const std::vector<Account*>& GetMasterRegistry() const;

	// Destructor.
	~AccountManager();

	// Disables the Copy Constructor in order to stop code from initilizing a new manager as a direct copy of the existing manager.
	AccountManager(const AccountManager&) = delete;

	// Disables the Copy Assignment Operator in order to stop an existing manager from copying data from another manager.
	AccountManager& operator=(const AccountManager&) = delete;
};