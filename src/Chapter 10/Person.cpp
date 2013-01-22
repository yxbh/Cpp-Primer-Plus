#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Person.h"
#include <string>
#include <iostream>
#include <cstring>
using std::string;
using std::cout;
using std::endl;

Person::Person(const string & ln, const char * fn)
{
	lname = ln;
	strcpy(fname,fn);
}

void Person::Show() const
{
	cout << fname;
	cout << " ";
	cout << lname;
	cout << endl;
}

void Person::FormalShow() const
{
	cout << lname;
	cout << ", ";
	cout << fname;
	cout << endl;
}

#endif