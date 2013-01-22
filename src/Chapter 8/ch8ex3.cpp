#include <iostream>
#include <string>
#include <cctype>
using namespace std;

static void func(string &);

void ch8ex3(void)
{
	string input;
	cout << "Enter a string (q to quit); ";
	getline(cin, input);
	while ( input != "q")
	{
		func(input);
		cout << input << endl;
		cout << "Enter a string (q to quit); ";
		getline(cin, input);
	}

	if (cin)
		cout << "Bye." << endl;
	else
		cerr << "Err..." << endl;
}

static void func(string & str)
{
	int size = str.size();
	while (size)
	{
		str[size-1] = (char)toupper(str[size-1]);
		size--;
	}
}