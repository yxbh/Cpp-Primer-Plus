#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include "Cow.h"
#include <cstring>
#include <iostream>

Cow::Cow()
{
	name[0] = '\0';
	hobby = new char[1];
	hobby[0] = '\0';
	weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt)
{
	strncpy(name, nm, 20);
	hobby = new char[strlen(ho)+1];
	strcpy(hobby, ho);
	weight = wt;
}

Cow::Cow(const Cow & c)
{
	strncpy(name, c.name, 20);
	hobby = new char[strlen(c.hobby)+1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	if (this == &c) // self assignment?
		return *this;
	strncpy(name, c.name, 20);
	if (hobby != nullptr) // check if string ptr is null
		delete [] hobby;
	hobby = new char[strlen(c.hobby)+1];
	strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::ShowCow() const
{
	using std::cout;
	using std::endl;
	cout << "name: " << name << endl;
	cout << "hobby: " << hobby << endl;
	cout << "weight: " << weight << endl;
}

#endif