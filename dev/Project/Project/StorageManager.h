#pragma once
#include <vector>
#include "Account.h"


struct AccountRecord
{
	char account_holder_name[50];
	int account_id;
	int security_pin;
	double account_balance;
	double account_interest_rate;
	int account_type_id;             // 1 for Checking, 2 for Savings.
};

class StorageManager
{
private:
	const char* filename =  "banking_database.dat";

public:
	bool SaveAccountInterface(const std::vector<Account*>& account_registry);

	std::vector<Account*> LoadAccountInterface();
};