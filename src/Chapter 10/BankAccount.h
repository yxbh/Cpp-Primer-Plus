// for ch10re5 and ch10re7

#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include <string>

class BankAccount 
{
private:
	std::string full_name;
	std::string account_num;
	long int balance;
public:
	BankAccount(const std::string & fname, 
		const std::string & acc_name, 
		const long balance);
	void deposit(const long);
	bool withdraw(const long); // true when success, false otherwise
	const long get_balance(void) const;
};

#endif