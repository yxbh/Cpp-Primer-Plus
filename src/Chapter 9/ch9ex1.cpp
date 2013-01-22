#if defined(_WIN32) || defined(_WIN64)
#define _CRT_SECURE_NO_WARNINGS   // for strcpy()
#endif
#include "golf.h"
#include <iostream>
#include <cstring> // for strcpy()
#include <string>
using namespace std;

void ch9ex1(void)
{
	golf ann;
	setgolf(ann, "Ann Birdfree", 24);
	showgolf(ann);
	golf andy;
	setgolf(andy);
	showgolf(andy);

}

void setgolf(golf & g, const char * name, int hc)
{
	strcpy(g.fullname, name);
	g.handicap = hc;
}

int setgolf(golf & g)
{
	int return_val = 1;
	string name_buffer;
	cout << "Enter name: ";
	getline(cin, name_buffer); cin.get();
	if (name_buffer.size() == 0)
		return_val = 0;
	strcpy(g.fullname, name_buffer.c_str());
	cout << "Enter handicap value: ";
	cin >> g.handicap;
	while (!cin) {
		cin.clear();
		string flush;
		cin >> flush;
		cout << "Invalid input, enter again: ";
		cin >> g.handicap;
	}
	return return_val;
}

void handicap(golf & g, int hc)
{
	g.handicap = hc;
}

void showgolf(const golf & g)
{
	cout << g.fullname << "  " << g.handicap << endl;	
}