#include "Complex.h"
#include <string>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

void ch11ex7()
{
	Complex a(3.0, 4.0);	// initialise to (3, 4i)
	Complex c;
	cout << "Enter a complex number (q to quit):\n";

	// put into a while loop
	while (cin >> c)
	{
		cout << "a is " << a << "\n";
		cout << "a + c is " << a + c << "\n";
		cout << "a - c is " << a - c << "\n";
		cout << "a * c is " << a * c << "\n";
		cout << "2 * c is " << 2 * c << "\n";
		cout << "Enter a complex number (q to quit):\n";
	}
	cout << "Done\n";
	
	if (!cin)
	{
		std::string str_buf;
		cin.clear();
		cin >> str_buf;
		if (str_buf == "q") {}
		else
			std::cerr << "Unknown input" << endl;
	}
	return;
}
