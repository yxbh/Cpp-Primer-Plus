#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void ch9re4(void)
{
	double x;
	cout << "Enter value: ";
	while (! (cin >> x) )
	{
		cout << "Bad input. Please enter a number: ";
		cin.clear();
		while (cin.get() != '\n')
			continue;
	}
	cout << "value = " << x << endl;
	return;
}