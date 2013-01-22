#include <iostream>
#include <string>
using namespace std;

void iquote(const int);
void iquote(const double);
void iquote(const string);

void ch8re3(void)
{
	iquote(12);
	iquote(123.32);
	iquote("Hello World!");
}

void iquote(const int a)
{
	cout << "\"" << a << "\"" << endl;
}

void iquote(const double a)
{
	cout << "\"" << a << "\"" << endl;
}

void iquote(const string a)
{
	cout << "\"" << a << "\"" << endl;
}
