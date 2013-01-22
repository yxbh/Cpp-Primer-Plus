#define _CRT_SECURE_NO_WARNINGS
#include "Plorg.h"
#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

Plorg::Plorg(const char * name, int ci)
{
	strcpy(this->name, name);
	this->ci = ci;
}

void Plorg::change_ci(const int new_ci)
{
	ci = new_ci;
}

void Plorg::report(void) const
{
	cout << name << endl;
	cout << ci << endl;
}


Plorg::~Plorg(void)
{
}
