#include <iostream>
#include <string>

using namespace std;

static long factorial(long);

void ch7ex5()
{
	std::cout << " - Chapter 7 Exercise 5 - " << std::endl << std::endl;

	long input;
	cout << "Enter a number <q to quit>: ";
	bool const_true = true;
	while (const_true) {
		while (cin >> input && input >= 0)
		{
			cout << "Result: " << factorial(input) << endl;
			cout << "Enter a number <q to quit>: ";
		}

		if (!cin) {
			cin.clear();
			string buf;
			cin >> buf;
			if (buf != "q") {}
		} else {
			cout << "Bye..." << endl;
			break;
		}

		cout << "Enter a number <q to quit>: ";
	}
}

static long factorial(long num)
{
	if (num > 1)
		return num*factorial(num-1);
	else
		return num;
}