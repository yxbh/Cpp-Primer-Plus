#include "BankAccount.h"
#include <string>

BankAccount::BankAccount(const std::string & fullName, 
						 const std::string & account_number, 
						 const long balance)
{
	(*this).full_name = fullName;
	(*this).account_num = account_number;
	(*this).balance = balance;
}

void BankAccount::deposit(const long deposit_amount)
{
	balance += deposit_amount;
}

bool BankAccount::withdraw(const long withdraw_amount)
{
	if (balance > withdraw_amount) {
		balance -= withdraw_amount;
		return  true;
	}
	else
		return false;
}

const long BankAccount::get_balance(void) const
{
	return balance;
}

