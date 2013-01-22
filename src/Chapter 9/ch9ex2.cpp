/*
copied from static.cpp from book src
*/
#include <iostream>
#include <string>
// function prototype
void strcount(const std::string str);


void ch9ex2(void)
{
	using namespace std;
	string input;

	cout << "Enter a line:\n";
	getline(cin, input);
	while (cin && input != "")
	{
		strcount(input);
		cout << "Enter next line (empty line to quit):\n";
		getline(cin, input); 
	}
	cout << "Bye\n";

	// code to keep window open for MSVC++
	cin.clear();
	while (cin.get() != '\n')
		continue;
	cin.get();

}

void strcount(const std::string str)
{
	using namespace std;
	static int total = 0;        // static local variable

	cout << "\"" << str <<"\" contains ";
	total = str.size();
	cout << total << " characters total\n";
}
