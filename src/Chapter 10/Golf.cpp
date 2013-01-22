#include "Golf.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;


Golf::Golf(const std::string fname, const int hc)
{
	fullname = fname;
	handicap = hc;
}

void Golf::showgolf(void) const
{
	cout << "Name: " << fullname << endl;
	cout << "Handicap val: " << handicap << endl;
}

const int Golf::setgolf(void)
{
	int return_val = 1;
	std::string name_buffer;
	cout << "Enter name: ";
	std::getline(cin, name_buffer); cin.get();
	if (name_buffer.size() == 0)
		return_val = 0;
	fullname = name_buffer;
	cout << "Enter handicap value: ";
	cin >> handicap;
	while (!cin) {
		cin.clear();
		std::string flush;
		cin >> flush;
		cout << "Invalid input, enter again: ";
		cin >> handicap;
	}
	return return_val;
}


Golf::~Golf()
{}