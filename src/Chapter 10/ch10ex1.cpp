#include "BankAccount.h"
#include <iostream>
using namespace std;

void ch10ex1(void)
{
	BankAccount acc1("Ben Huang", "123124", 140000);
	cout << "I have " << acc1.get_balance() << " dollars!" << endl;
	long int money = 999;
	cout << "I have deposited " << money << " dollars." << endl;
	acc1.deposit(money);
	cout << "Now I have " << acc1.get_balance() << " dollars in my account!" << endl;
}