#include "StorageManager.h"
#include<fstream>
#include<cstring>

// Saving Information to Binary FIle.
bool StorageManager::SaveAccountInterface(const std::vector<Account*>& reference)
{
	// Attempts to open file.
	std::ofstream out_file(filename, std::ios::out | std::ios::binary | std::ios::trunc);
	
	// GUARD CLAUSE: If fails to open, return immediately.
	if (!out_file)
	{
		return false;
	}

	// Loop to translate to binary and map it to the Getters to get the required information.
	for (const auto& account_ptr : reference)
	{
		AccountRecord record;

		record.account_id = account_ptr->GetAccountNumber();
		record.security_pin = account_ptr->GetPin();
		record.account_balance = account_ptr->GetAccountBalance();
		record.account_interest_rate = account_ptr->GetInterestRate();
		record.account_type_id = (account_ptr->GetAccountType() == Account::Savings) ? 2 : 1;

		strcpy_s(record.account_holder_name, sizeof(record.account_holder_name), account_ptr->GetAccountHolderName());
		
		out_file.write(reinterpret_cast<const char*>(&record), sizeof(AccountRecord));
	}

	out_file.close();
	return true;
}

// Loading the Saved Information in the Binary File to be read.
std::vector<Account*> StorageManager::LoadAccountInterface()
{
	std::vector<Account*> loaded_accounts;

	// Attempts to open file.
	std::ifstream in_file(filename, std::ios::in | std::ios::binary);
	
	// GUARD CLAUSE: If file fails to open, return immediately.
	if (!in_file)
	{
		return loaded_accounts;
	}

	AccountRecord record;

	while (in_file.read(reinterpret_cast<char*>(&record), sizeof(AccountRecord)))
	{
		// map the recieved raw records of the iteger back into the account types.
		Account::AccountType type = (record.account_type_id == 2) ? Account::Savings : Account::Checking;

		Account* new_account = new Account(record.account_id, record.account_holder_name, record.account_balance, type, record.account_interest_rate, record.security_pin);
		loaded_accounts.push_back(new_account);
	}

	in_file.close();
	return loaded_accounts;
}